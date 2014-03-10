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
string G0 = "G_0_15_V07";
string G15 = "G_15_30_V07";
string G30 = "G_30_50_V07";
string G50 = "G_50_80_V07";
string G80 = "G_80_120_V07";
string G120 = "G_120_170_V07";
string G170 = "G_170_300_V07";
string G300 = "G_300_470_V07";
string G470 = "G_470_800_V07";
string G800 = "G_800_1400_V07";
string G1400 = "G_1400_1800_V07";
string G1800 = "G_1800_V07";
string QCD100 = "QCD_100_250_V06";
string QCD250 = "QCD_250_500_V02";
string QCD500 = "QCD_500_1000_V02";
string QCD1000 = "QCD_1000_inf_V02";
string TTJets = "TTJets_V02";
string ZGamma = "ZGamma_V02";
string WJets = "WJets_V02";
string WGamma = "WGamma_V02";
string ZGammaNuNu = "ZGammaNuNu_V02";
string WW_incl = "WW_incl_V06";
string WZ_incl = "WZ_incl_V06";
string ZZ_incl = "ZZ_incl_V06";
string Signal_540_280 = "Signal_540_280";
string Signal_340_130 = "Signal_340_130";
string Signal_340_180 = "Signal_340_180";
string Signal_440_430 = "Signal_440_430";
string Signal_490_480 = "Signal_490_480";
string Signal_540_530 = "Signal_540_530";
string Signal_540_480 = "Signal_540_480";
string Signal_590_580 = "Signal_590_580";
string Signal_640_630 = "Signal_640_630";
string Signal_690_680 = "Signal_690_680";
string Signal_740_730 = "Signal_740_730";
string Signal_500_500_500 = "Signal_500_500_500";
string Signal_2000_530_540 = "Signal_2000_530_540";
string Signal_mu_250_m1_300_m2_600 = "Signal_mu_250_m1_300_m2_600";
string Signal_mu_350_m1_350_m2_600 = "Signal_mu_350_m1_350_m2_600";

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
		else if ( G0.compare(argv[1]) == 0 ) {
		xs = 90601456;
		Ngen = 2000000;//204239;
		}			
		else if ( G15.compare(argv[1]) == 0 ) {
		xs = 200061.7;
		Ngen = 2000000;//204239;
		}				
		else if ( G30.compare(argv[1]) == 0 ) {
		xs = 19931.62;
		Ngen = 2000000;//204239;
		}			
		else if ( G50.compare(argv[1]) == 0 ) {
		xs = 3322.309;
		Ngen = 2000000;//204239;
		}		
		else if ( G80.compare(argv[1]) == 0 ) {
		xs = 558.2865;
		Ngen = 2000000;//204239;
		}		
		else if ( G120.compare(argv[1]) == 0 ) {
		xs = 108.0068;
		Ngen = 2000000;//204239;
		}		
		else if ( G170.compare(argv[1]) == 0 ) {
		xs = 30.12207;
		Ngen = 2000000;//204239;
		}		
		else if ( G300.compare(argv[1]) == 0 ) {
		xs = 2.138632;
		Ngen = 2000000;//204239;
		}		
		else if ( G470.compare(argv[1]) == 0 ) {
		xs = 0.2119244;
		Ngen = 2000000;//204239;
		}		
		else if ( G800.compare(argv[1]) == 0 ) {
		xs = 0.007077847;
		Ngen = 2000000;//204239;
		}		
		else if ( G1400.compare(argv[1]) == 0 ) {
		xs = 0.00004510327;
		Ngen = 2000000;//204239;
		}		
		else if ( G1800.compare(argv[1]) == 0 ) {
		xs = 0.000001867141;
		Ngen = 2000000;//204239;
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
		xs = 0.074;
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
		Ngen = 7992;
		}	
		else if ( Signal_540_530.compare(argv[1]) == 0 ) {
		xs = 0.009501;
		Ngen = 10000;
		}			
		else if ( Signal_340_130.compare(argv[1]) == 0 ) {
		xs = 0.0983;
		Ngen = 499;
		}		
		else if ( Signal_340_180.compare(argv[1]) == 0 ) {
		xs = 0.09724;
		Ngen = 5734;
		}	
		else if ( Signal_440_430.compare(argv[1]) == 0 ) {
		xs = 0.0983;
		Ngen = 499;
		}		
		else if ( Signal_490_480.compare(argv[1]) == 0 ) {
		xs = 0.01634;
		Ngen = 5734;
		}			
		else if ( Signal_590_580.compare(argv[1]) == 0 ) {
		xs = 0.005774;
		Ngen = 10000;
		}		
		else if ( Signal_640_630.compare(argv[1]) == 0 ) {
		xs = 0.00352;
		Ngen = 10000;
		}		
		else if ( Signal_690_680.compare(argv[1]) == 0 ) {
		xs = 0.002181;
		Ngen = 10000;
		}			
		else if ( Signal_540_480.compare(argv[1]) == 0 ) {
		xs = 0.009638;
		Ngen = 10000;
		}		
		else if ( Signal_740_730.compare(argv[1]) == 0 ) {
		xs = 0.001378;
		Ngen = 10000;
		}			
		else if ( Signal_500_500_500.compare(argv[1]) == 0 ) {
		xs = 0.02674;
		Ngen = 10000;
		}		
		else if ( Signal_2000_530_540.compare(argv[1]) == 0 ) {
		xs = 0.005434;
		Ngen = 10000;
		}				
		else if ( Signal_mu_250_m1_300_m2_600.compare(argv[1]) == 0 ) {
		xs = 0.223;
		Ngen = 1000;
		}
		else if ( Signal_mu_350_m1_350_m2_600.compare(argv[1]) == 0 ) {
		xs = 0.007;
		Ngen = 1000;
		}				
		else if ( WGamma.compare(argv[1]) == 0 ) {
		xs = 461.6;
		Ngen = 4802358;//500000;
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
	evt->BGInfo( argv[1] );
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
