#!/bin/bash
# This script submits all jobs to naf, which are defined in dataset

datasets=(

/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/GGM_Wino_V04/


)

# settings
version="1"
outputFolder=/nfs/dust/cms/user/jschulz/results
files_per_job=1

fetchScript=getOutputGGM_WinoSignal_${version}.sh
echo "#!/bin/bash -e" > $fetchScript
chmod +x $fetchScript

for dataset in "${datasets[@]}"; do

    # get folder name as best description for job
   # folder_name=$(echo $dataset|rev|cut -d'/' -f2|rev)		
    job_name=$(echo $dataset|rev|cut -d'/' -f2|rev)
    # Since root can't handle -, it will be substituted to _
    job_name=$(echo $job_name|sed 's/-/_/g')

#    signal_name=$(ls $dataset|grep root|rev|cut -d'.' -f2|rev )

		
#		echo $job_name
    files=( $(ls $dataset|grep root ) )
#    files=( $(dcls $dataset|grep root|awk '{print $2 }') )
		
    echo $files
		
    # Ugly hack to get more than 1000 files (up to 2000).
#    files+=( $(dcls -offset 1000 -count 1999 $dataset|grep root|awk '{print $2 }') )
#		echo $files
	
 #   number_of_jobs=$(expr \( ${#files[@]} + $files_per_job \) / $files_per_job )
    number_of_jobs=${#files[@]} 	
    echo $number_of_jobs

#    files=( $(srmls -offset 0 -count 999 $dataset|grep root|awk '{print $2 }') )
    # Ugly hack to get more than 1000 files (up to 2000).
#    files+=( $(srmls -offset 1000 -count 1999 $dataset|grep root|awk '{print $2 }') )
#    number_of_jobs=$(expr \( ${#files[@]} + $files_per_job \) / $files_per_job )



    for (( job=1; job<=$number_of_jobs; job++ )); do

        files_to_submit=""
        for (( i=$(expr $job \* $files_per_job - $files_per_job ); i<$(expr $job \* $files_per_job ); i++ )); do
            if [[ "${files[$i]}" != "" ]]; then
               files_to_submit=$files_to_submit${dataset}${files[$i]}" "
            fi
        done # files for one job
	signal_name=($(ls $files_to_submit|grep root|rev|cut -d'/' -f1|rev ))
#	echo $signal_name
	signal_name=($(echo $signal_name|grep root|rev|cut -d'.' -f2|rev ))
	echo $signal_name

        jobPrefix=${signal_name}.${version}__${job}

        outputFileName=$outputFolder/${signal_name}.root


        script=${signal_name}.sh
      #  echo export SCRAM_ARCH="slc5_amd64_gcc462" >> $script
      #  echo export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch >> $script
      #  echo source /cvmfs/cms.cern.ch/cmsset_default.sh >> $script
      #  echo cd $HOME/CMSSW_5_3_8_patch3/src >> $script
      #  echo cmsenv >> $script
	echo export LD_LIBRARY_PATH=/opt/d-cache/dcap/lib64:/afs/desy.de/products/root/amd64_rhel60/5.34.00/lib:/usr/lib64/perl5/5.10.0/x86_64-linux-thread-multi/CORE:/afs/desy.de/user/j/jschulz/photon_analysis_framework/Selector >> $script
	echo export PATH=$PATH:/afs/desy.de/products/root/amd64_rhel60/5.34.00/bin/ >> $script
        echo cd $HOME/photon_analysis_framework/Selector >> $script

			#	echo $job_name $outputFileName $files_to_submit
        echo ./processMC $signal_name $outputFileName "dcap://dcache-cms-dcap.desy.de"$files_to_submit >> $script

 	echo $signal_name $outputFileName $files_to_submit
        chmod +x $script
	
        qsub -P af-cms -b y -j y -l h_rt=23:00:00 -l os=sld6 `pwd`/${signal_name}.sh
	
        
   #     echo "hadd -f $outputFolder/${signal_name}.${version}_sel.root $outputFolder/${signal_name}.${version}__*.root" >> $fetchScript
     #   echo "rm $outputFolder/${signal_name}.${version}__*.root" >> $fetchScript
			
				# -b y
				# -l h_cpu=17:00:00      (the cpu time for this job)
				# -P $GROUP                Project name for resource settlement in Fair Share operation.
				# -j y                     Join: Standard error output is written to standard output.
        # i: merge stdout and stderr
        # o: log file
    done # all jobs
    echo "rm "GGM_Wino"*.sh" >> $fetchScript
    echo "rm ~/"GGM_Wino"*.sh.o*" >> $fetchScript
 
done #dataset
