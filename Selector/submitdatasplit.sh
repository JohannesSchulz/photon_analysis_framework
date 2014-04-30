#!/bin/bash
# This script submitts all jobs to naf, which are defined in dataset

datasets=(

/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/PhotonParkedD_V06/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/PhotonParkedD_V06/
)

# settings
version="1"
outputFolder=/nfs/dust/cms/user/jschulz/results
files_per_job=20

fetchScript=getOutputData_${version}.sh
echo "#!/bin/bash -e" > $fetchScript
chmod +x $fetchScript

for dataset in "${datasets[@]}"; do

    # get folder name as best description for job
    job_name=$(echo $dataset|rev|cut -d'/' -f2|rev)
    # Since root can't handle -, it will be substituted to _
    job_name=$(echo $job_name|sed 's/-/_/g')

    files=( $(dcls $dataset|grep root) )
#    files=( $(dcls $dataset|grep root|awk '{print $2 }') )
		
#		echo $files
		
    # Ugly hack to get more than 1000 files (up to 2000).
#    files+=( $(dcls -offset 1000 -count 1999 $dataset|grep root|awk '{print $2 }') )
#		echo $files
		echo ${#files[@]}
    number_of_jobs=$(expr \( ${#files[@]} + $files_per_job \) / $files_per_job )
		
		echo $number_of_jobs



    for (( job=1; job<=$number_of_jobs; job++ )); do

        jobPrefix=${job_name}.${version}__${job}

        files_to_submit=""
        for (( i=$(expr $job \* $files_per_job - $files_per_job ); i<$(expr $job \* $files_per_job ); i++ )); do
            if [[ "${files[$i]}" != "" ]]; then
              files_to_submit=$files_to_submit"dcap://dcache-cms-dcap.desy.de"${dataset}${files[$i]}" "
            fi
        done # files for one job
        outputFileName=$outputFolder/${jobPrefix}_sel.root

        # now that we have all information, get data
        script=$jobPrefix.sh
        echo export SCRAM_ARCH="slc5_amd64_gcc462" >> $script
        echo export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch >> $script
        echo source $VO_CMS_SW_DIR/cmsset_default.sh >> $script
        echo cd $HOME/CMSSW_5_3_8_patch3/src >> $script
        echo cmsenv >> $script
        echo cd $HOME/photon_analysis_framework/Selector >> $script
        # echo make >> $script
				
	#			echo $job_name $outputFileName $files_to_submit
        echo ./processData $job_name $outputFileName $files_to_submit >> $script
        chmod +x $script
        qsub -P af-cms -b y -j y -l h_rt=24:00:00 -l os=sld5 `pwd`/$jobPrefix.sh
        # i: merge stdout and stderr
        # o: log file
    done # all jobs
    echo "rm ${job_name}.${version}__*.sh" >> $fetchScript
    echo "rm ~/${job_name}.${version}__*.sh.o*" >> $fetchScript
    echo "hadd -f $outputFolder/${job_name}.${version}_sel.root $outputFolder/${job_name}.${version}__*.root" >> $fetchScript
    echo "rm $outputFolder/${job_name}.${version}__*.root" >> $fetchScript
done #dataset
