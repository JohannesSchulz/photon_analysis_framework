//own
#include "process.h"
#include "MySelector.h"

//system
#include <iostream>
#include <string>

//root includes
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1F.h"
#include "TCanvas.h"



int main(int argc, char** argv)
{

/* cross section in pb */

double xs = 1;
double Ngen = 1;
double lumi =  7369.;
double lumiPart = 1.; //(2665629./96848304.);
double Eventweight = 1;

	#ifdef __MC 

	std::cout << ">> MC flag <<" << std::endl; 

	MySelector *evt = new MySelector;
	evt->SetPileUpWeightFile("puWeights.root");	

string GJets40 = "GJets_40_100_V06";
string GJets100 = "GJets_100_200_V02";
string GJets200 = "GJets_200_400_V02";
string GJets400 = "GJets_400_inf_V02";
string GJets = "GJets_V02";
string QCD100 = "QCD_100_250_V06";
string QCD250 = "QCD_250_500_V02";
string QCD500 = "QCD_500_1000_V02";
string QCD1000 = "QCD_1000_inf_V02";
string TTJets = "TTJets_V02";
string ZGamma = "ZGamma_V02";
string WJets = "WJets_V02";
string ZGammaNuNu = "ZGammaNuNu_V02";
string WW_incl = "WW_incl_V06";
string WZ_incl = "WZ_incl_V06";
string ZZ_incl = "ZZ_incl_V06";
string Signal_540_280 = "Signal_540_280";
string Signal_340_130 = "Signal_340_130";
string Signal_340_180 = "Signal_340_180";
string WGamma ="WGamma_V02";
/* total Ngen after Ntuplizer

 GJets100 = Ngen = 9662703;
 GJets200 = Ngen = 58927146;
 GJets400 = Ngen = 42441678;
 QCD250 = Ngen 	 = 27062078;
 QCD500 = Ngen	 = 30649292;
 QCD1000 = Ngen	 = 13843863;
 TTJets = Ngen	 = 6923652;
 ZGamma = Ngen	 = 6321549;
 WJets = Ngen		 = 57659905;

*/ 

if ( GJets100.compare(argv[1]) == 0 ) {
	xs = 5212.0;
	Ngen = 9662703;//473815; 9612703 
	} else if ( GJets200.compare(argv[1]) == 0 ) {
		xs = 960.5;
		Ngen = 58927146;//456205;
		}
		else if ( GJets40.compare(argv[1]) == 0 ) {
		xs = 20930;
		Ngen = 19957930;
		}
		else if ( GJets400.compare(argv[1]) == 0 ) {
		xs = 107.5;
		Ngen = 42441678;//204239;
		}	
		else if ( GJets.compare(argv[1]) == 0 ) {
		xs = 107.5;
		Ngen = 9539562;//204239;
		}				
		else if ( QCD100.compare(argv[1]) == 0 ) {
		xs = 10360000;
		Ngen = 50229518;//500000;
		}						
		else if ( QCD250.compare(argv[1]) == 0 ) {
		xs = 276000;
		Ngen = 27062078;//500000;
		}
		else if ( QCD500.compare(argv[1]) == 0 ) {
		xs = 8426;
		Ngen = 30649292;//413547;
		}
		else if ( QCD1000.compare(argv[1]) == 0 ) {
		xs = 204;
		Ngen = 13843863;//405506;
		}
		else if ( TTJets.compare(argv[1]) == 0 ) {
		xs = 245.8; //NNLO
		Ngen = 6923652;//423652;
		}
		else if ( ZGamma.compare(argv[1]) == 0 ) {
		xs = 123.9;
		Ngen = 6321549;//456458;
		}		
		else if ( WJets.compare(argv[1]) == 0 ) {
		xs = 30400; //12503;
		Ngen = 57659905;//500000;
		}	
		else if ( ZGammaNuNu.compare(argv[1]) == 0 ) {
		xs = 0.0283;
		Ngen = 489474;//500000;
		}		
		else if ( WW_incl.compare(argv[1]) == 0 ) {
		xs = 54.838; //NLO
		Ngen = 10000431;//500000;
		}		
		else if ( WZ_incl.compare(argv[1]) == 0 ) {
		xs = 12.63; //LO
		Ngen = 10000283;//500000;
		}		
		else if ( ZZ_incl.compare(argv[1]) == 0 ) {
		xs = 5.196; //LO
		Ngen = 9799908;//500000;
		}		
		else if ( Signal_540_280.compare(argv[1]) == 0 ) {
		xs = 0.009425;
		Ngen = 7992;//500000;
		}		
		else if ( Signal_340_130.compare(argv[1]) == 0 ) {
		xs = 0.0983;
		Ngen = 499;//500000;
		}		
		else if ( Signal_340_180.compare(argv[1]) == 0 ) {
		xs = 0.09724;
		Ngen = 5734;//500000;
		}		
		
		else if ( WGamma.compare(argv[1]) == 0 ) {
		xs = 461.6;
		Ngen = 5000000;//500000;
		}	
		
	Eventweight = ( xs / Ngen ) * lumi * lumiPart;

	#endif 



	#ifdef __Data
	
  std::cout << ">> Data flag <<" << std::endl;  
  MySelector *evt = new MySelector;
	
	#endif

	std::cout << "Cross-section of " << argv[1] << " is: " << xs << " pb and the event weight: " << Eventweight << std::endl;
	if( argc < 3 ) {
		std::cout << "usage: ./process job_name output.root input1.root input2.root ..." << std::endl;
		return 1;
		}
		
	TChain * tchain = new TChain( "susyTree" );

 	for(int i=3; i<argc; ++i){
	  tchain->Add( argv[i] );
		}

  evt->AddSignalTrigger("HLT_Photon30_R9Id90_CaloId_HE10_Iso40_EBOnly_Met25_HBHENoiseCleaned");
  evt->AddMETTrigger("HLT_MET100_HBHENoiseCleaned");
  evt->AddIsoGammaTrigger("HLT_Photon30_R9Id90_CaloId_HE10_Iso40_EBOnly");   
  evt->AddDisplacedTrigger("HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30");
  evt->AddDisplacedTrigger("HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25"); 
  evt->AddGamma135Trigger("HLT_Photon135");
  evt->AddGamma30Trigger("HLT_Photon30");
  evt->AddHLTPhysicsTrigger("HLT_Physics");           
		 
  evt->Init( tchain );
	
  Long64_t nentries = evt->fChain->GetEntries();

  evt->Begin( tchain );

  evt->SlaveBegin( tchain );

	
	std::cout<<"-----------------------------------------------"<<std::endl;
	std::cout<<"   "<<argv[1]<<" has total number of Events: "<<nentries<<std::endl;
	std::cout<<"-----------------------------------------------"<<std::endl;
  for (Long64_t i = 0; i < nentries; i++){
     evt->SetLumiWeight(Eventweight);
	   evt->GetEntry(i);
     evt->Process(i);
	   }
  evt->SlaveTerminate();
  evt->Terminate();

	evt->histo.Write(argv[2]);
	evt->histo2.Update(argv[2]);
	
	//evt->histo2.Write(argv[2]);	
	return 0;
}
