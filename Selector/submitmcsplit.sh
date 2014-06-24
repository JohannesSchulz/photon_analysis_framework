#!/bin/bash
# This script submits all jobs to naf, which are defined in dataset

datasets=(

# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_0_15_V07/

# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_15_30_V07/ 
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_30_50_V07/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_50_80_V07/

# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_80_120_V07/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_120_170_V07/
  
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_170_300_V07/
  
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_300_470_V07/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_470_800_V07/
  
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_800_1400_V07/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_1400_1800_V07/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/G_1800_V07/

# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WJets_V02/ 
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/ZGamma_V02/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WGamma_V02/ 

# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/WGamma_50_130_V02/ 
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/WGamma_130_inf_V02/ 

# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/ZGammaNuNu_V02/ 
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/TTJets_V02/

# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/TTGamma_V02/  #TTGamma is madgraph 8 TeV

# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/GJets_40_100_V06/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/GJets_100_200_V02/

# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/GJets_200_400_V02/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/GJets_400_inf_V02/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WW_incl_V06/ 

# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WZ_incl_V06/ 

# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/ZZ_incl_V06/ 
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/QCD_100-250_V06/ 
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/QCD_250-500_V02/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/QCD_500-1000_V02/
 
# srm://dcache-se-cms.desy.de:8443/srm/managerv2?SFN=/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/QCD_1000-inf_V02/ 

##/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WJets_V02/ 
 
/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/ZGamma_V02/

/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/ZGammaLL_V02/

/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/ZGammaNuNu_V02/ 
 
/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WGamma_V02/ 

/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WGamma_20_30_V07/ #

/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WGamma_30_50_V07/
#  
/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WGamma_50_130_V07/ 
 
/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WGamma_130_inf_V07/ 
 
##/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/TTJets_V02/

/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/TTGamma_V02/  #TTGamma is madgraph 8 TeV

/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/GJets_40_100_V06/
 
/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/GJets_100_200_V02/
 
/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/GJets_200_400_V02/

/pnfs/desy.de/cms/tier2/store/user/kiesel/nTuples/GJets_400_inf_V02/

/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WW_incl_V06/ 

/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/WZ_incl_V06/ 

/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/ZZ_incl_V06/ 
 
##/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/QCD_100-250_V06/   #no contribution!
 
##/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/QCD_250-500_V02/   #no contribution!

/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/QCD_500-1000_V02/
 
/pnfs/desy.de/cms/tier2/store/user/jschulz/nTuples/QCD_1000-inf_V02/  

)

# settings
version="1"
outputFolder=/nfs/dust/cms/user/jschulz/results
files_per_job=20

fetchScript=getOutputMC_${version}.sh
echo "#!/bin/bash -e" > $fetchScript
chmod +x $fetchScript

for dataset in "${datasets[@]}"; do

    # get folder name as best description for job
    job_name=$(echo $dataset|rev|cut -d'/' -f2|rev)		
#    job_name=$(echo $dataset|rev|cut -d'/' -f2|rev)
    # Since root can't handle -, it will be substituted to _
    job_name=$(echo $job_name|sed 's/-/_/g')
		
#		echo $job_name
    files=( $(dcls $dataset|grep root) )
#    files=( $(dcls $dataset|grep root|awk '{print $2 }') )
		
#		echo $files
		
    # Ugly hack to get more than 1000 files (up to 2000).
#    files+=( $(dcls -offset 1000 -count 1999 $dataset|grep root|awk '{print $2 }') )
#		echo $files
		echo ${#files[@]}
    number_of_jobs=$(expr \( ${#files[@]} + $files_per_job \) / $files_per_job )
		
		echo $number_of_jobs

#    files=( $(srmls -offset 0 -count 999 $dataset|grep root|awk '{print $2 }') )
    # Ugly hack to get more than 1000 files (up to 2000).
#    files+=( $(srmls -offset 1000 -count 1999 $dataset|grep root|awk '{print $2 }') )
#    number_of_jobs=$(expr \( ${#files[@]} + $files_per_job \) / $files_per_job )



    for (( job=1; job<=$number_of_jobs; job++ )); do

        jobPrefix=${job_name}.${version}__${job}

        files_to_submit=""
        for (( i=$(expr $job \* $files_per_job - $files_per_job ); i<$(expr $job \* $files_per_job ); i++ )); do
            if [[ "${files[$i]}" != "" ]]; then
               files_to_submit=$files_to_submit"dcap://dcache-cms-dcap.desy.de"${dataset}${files[$i]}" "
            fi
        done # files for one job
        outputFileName=$outputFolder/${jobPrefix}_sel.root


        script=$jobPrefix.sh
        echo export SCRAM_ARCH="slc5_amd64_gcc462" >> $script
        echo export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch >> $script
        echo source $VO_CMS_SW_DIR/cmsset_default.sh >> $script
        echo cd $HOME/CMSSW_5_3_8_patch3/src >> $script
        echo cmsenv >> $script
        echo cd $HOME/photon_analysis_framework/Selector >> $script

			#	echo $job_name $outputFileName $files_to_submit
        echo ./processMC $job_name $outputFileName $files_to_submit >> $script
        chmod +x $script
        qsub -P af-cms -b y -j y -l h_rt=24:00:00 -l os=sld5 `pwd`/$jobPrefix.sh
				
				# -b y
				# -l h_cpu=17:00:00      (the cpu time for this job)
				# -P $GROUP                Project name for resource settlement in Fair Share operation.
				# -j y                     Join: Standard error output is written to standard output.
        # i: merge stdout and stderr
        # o: log file
    done # all jobs
    echo "rm ${job_name}.${version}__*.sh" >> $fetchScript
    echo "rm ~/${job_name}.${version}__*.sh.o*" >> $fetchScript
    echo "hadd -f $outputFolder/${job_name}.${version}_sel.root $outputFolder/${job_name}.${version}__*.root" >> $fetchScript
    echo "rm $outputFolder/${job_name}.${version}__*.root" >> $fetchScript
done #dataset
