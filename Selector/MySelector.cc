
#include "MySelector.h"
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TStyle.h>
#include "TMath.h"
#include "TFile.h"
#include <TLorentzVector.h>
#include <TVector3.h>

#include <complex>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cmath>
#include <typeinfo>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;


bool LorentzVectorSortPt(const TLorentzVector & l1,const TLorentzVector & l2){
 		 return (l1.Pt() > l2.Pt());
	 }

#ifdef __Data	 

bool MySelector::PassSignalTrigger() const
{
  unsigned nT(SignalNames.size());
  if(nT == 0) return true;

  for(unsigned int i = 0; i != nT; ++i){

    if(hltMap.pass(SignalNames[i])) return true;

	}
  return false;
}

bool MySelector::PassMETTrigger() const
{
  unsigned nT(METNames.size());
  if(nT == 0) return true;

  for(unsigned int i = 0; i != nT; ++i){

    if(hltMap.pass(METNames[i])) return true;

	}
  return false;
}


bool MySelector::PassIsoGammaTrigger() const
{
  unsigned nT(IsoGammaNames.size());
  if(nT == 0) return true;

  for(unsigned int i = 0; i != nT; ++i){

    if(hltMap.pass(IsoGammaNames[i])) return true;

	}
  return false;
}

bool MySelector::PassDisplacedTrigger() const
{
  unsigned nT(DisplacedNames.size());
  if(nT == 0) return true;

  for(unsigned int i = 0; i != nT; ++i){

    if(hltMap.pass(DisplacedNames[i])) return true;

	}
  return false;
}

bool MySelector::PassGamma135Trigger() const
{
  unsigned nT(Gamma135Names.size());
  if(nT == 0) return true;

  for(unsigned int i = 0; i != nT; ++i){

    if(hltMap.pass(Gamma135Names[i])) return true;

	}
  return false;
}

bool MySelector::PassGamma30Trigger() const
{
  unsigned nT(Gamma30Names.size());
  if(nT == 0) return true;

  for(unsigned int i = 0; i != nT; ++i){

    if(hltMap.pass(Gamma30Names[i])) return true;

	}
  return false;
}


bool MySelector::PassHLTPhysicsTrigger() const
{
  unsigned nT(HLTPhysicsNames.size());
  if(nT == 0) return true;

  for(unsigned int i = 0; i != nT; ++i){

    if(hltMap.pass(HLTPhysicsNames[i])) return true;

	}
  return false;
}
#endif

void MySelector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   

}


void MySelector::SlaveBegin(TTree * tree)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).
	 
  TH1::SetDefaultSumw2();
  TH2::SetDefaultSumw2();
  // First create a "cut flow" histogram that contains event counts for the
  // different stages of the analysis
	
   //initialize the Tree branch addresses
   Init(tree);
	// TH1::SetDefaultSumw2();

   //print the option specified in the Process function.
   TString option = GetOption();
   Info("SlaveBegin",
        "starting h1analysis with process option: %s (tree: %p)", option.Data(), tree);

   
   ///////own histos
	 float metbinning[] = {0,25,50,75,100,125,150,200,250,350,600};
	 float inversemetbinning[] = {0, 0.003,0.004,0.005,0.0055,0.006,0.0065,0.007,0.0075,0.008,0.0085,0.009,0.0095,0.01,0.02};
	 float metsignificancebinning[] = {0,4,6,8,10,12,16,20,25,30,70};
	 float scalebinning[] = {0,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,26,28,30,32,36,40,45,50,70};	 
	 float scalebinningPtOverMET[] = {0,0.4,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.2,3.4,3.6,3.8,4.0,4.2,4.6,5.0,5.4,5.8,6.2,6.6,7.0,7.5,8.0,10,12};		 
	 float HTbinning[] = {0,75,100,125,150,175,200,225,250,275,300,325,350,375,400,425,450,475,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1300,1400,1500,1750,2000,3000};
	 	 
		// No fill cut flow histo in command -> strange bug

	 CreateHisto("h_cutflow", "cutflow", 13, -0.5, 12.5);
   Fill("h_cutflow","all", 0);
   Fill("h_cutflow","PileupRew", 0);	 
	 Fill("h_cutflow","# #gamma>0", 0);
	 Fill("h_cutflow","Trigger", 0);	 
	 Fill("h_cutflow","#MET>100", 0);	 
	 Fill("h_cutflow","# loose #gamma>0", 0);	 
	 Fill("h_cutflow","# tight #gamma>0", 0);	  
	 Fill("h_cutflow","tight #gamma p_{T}>40", 0);
	 Fill("h_cutflow", "r9 > 0.9", 0);
	 Fill("h_cutflow","tight #gamma in barrel", 0);	
//	 Fill("h_c u tf low", "N_{Jets} > 1", 0);
	// Fill("h_cu tfl ow", "N_{loose Jets} > 2", 0);	 
	 Fill("h_cutflow", "cleaned", 0);	
	 Fill("h_cutflow","HT>100", 0);	 
	 Fill("h_cutflow","tight #gamma p_{T}>80", 0);	  	 	   
//	 Fill("h_ cutfl ow", "Ht>150", 0);

  #ifdef __Data
	
    CreateHisto("h_denumerator_bypass_tight_MET_2", "MET [GeV]", 80, 0, 400);				
    CreateHisto("h_numerator_bypass_tight_MET_2","MET [GeV]", 80, 0, 400);									
    CreateHisto("h_denumerator_bypass_tight_2", "MET [GeV]", 80, 0, 400);				
    CreateHisto("h_numerator_bypass_tight_2", "MET [GeV]", 80, 0, 400);									
    CreateHisto("h_denumerator_bypass_loose_MET_2", "MET [GeV]", 80, 0, 400);				
    CreateHisto("h_numerator_bypass_loose_MET_2","MET [GeV]", 80, 0, 400);									
    CreateHisto("h_denumerator_bypass_loose_2","MET [GeV]", 80, 0, 400);				
    CreateHisto("h_numerator_bypass_loose_2", "MET [GeV]", 80, 0, 400);									

		
    CreateHisto("h_denumerator_r9_2", "tight photon r9[0]",130, 0, 1.3 );
    CreateHisto("h_numerator_r9_2", "tight photon r9[0]",130, 0, 1.3 );	 	
		
		CreateHisto("h_denumerator_MET_corr_wo_1", "Delta Phi of MET and Photon",64, 0, 3.2);
		CreateHisto("h_denumerator_MET_corr_1", "Delta Phi of MET and Photon",64, 0, 3.2);		
		CreateHisto("h_denumerator_MET_corr_2", "Delta Phi of MET and Photon",64, 0, 3.2);
		CreateHisto("h_denumerator_MET_corr_100_2", "Delta Phi of MET and Photon",64, 0, 3.2);		
		
		CreateHisto("h_numerator_MET_corr_wo_1", "Delta Phi of MET and Photon",64, 0, 3.2);
		CreateHisto("h_numerator_MET_corr_1", "Delta Phi of MET and Photon",64, 0, 3.2);		
		CreateHisto("h_numerator_MET_corr_2", "Delta Phi of MET and Photon",64, 0, 3.2);
		CreateHisto("h_numerator_MET_corr_100_2", "Delta Phi of MET and Photon",64, 0, 3.2);		
		
		CreateHisto("h_denumerator_MET_corr_woDelta_2", "Delta Phi of MET and Photon",64, 0, 3.2);		
		CreateHisto("h_numerator_MET_corr_woDelta_2", "Delta Phi of MET and Photon",64, 0, 3.2);		
		
		CreateHisto("h_denumerator_JET_corr_wo_1", "Delta Phi of Photon and JET",64, 0, 3.2);
		CreateHisto("h_denumerator_JET_corr_1", "Delta Phi of Photon and JET",64, 0, 3.2);		
		CreateHisto("h_denumerator_JET_corr_2", "Delta R of Photon and nearest JET",128, 0, 6.4);
		CreateHisto("h_denumerator_JET_corr_100_2", "Delta R of Photon and nearest JET",128, 0, 6.4);		
		
		CreateHisto("h_numerator_JET_corr_wo_1", "Delta Phi of Photon and JET",64, 0, 3.2);
		CreateHisto("h_numerator_JET_corr_1", "Delta Phi of Photon and nearest JET",64, 0, 3.2);		
		CreateHisto("h_numerator_JET_corr_2", "Delta R of Photon and nearest JET",128, 0, 6.4);		
		CreateHisto("h_numerator_JET_corr_100_2", "Delta R of Photon and nearest JET",128, 0, 6.4);		
		
		CreateHisto("h_denumerator_DeltaRCut2_DeltaPhiCut_PtCut_2", "Photons[tight_photons[0]].Pt()",80,0,400);
		CreateHisto("h_numerator_DeltaRCut2_DeltaPhiCut_PtCut_2", "Photons[tight_photons[0]].Pt()",80,0,400);		
		
		CreateHisto("h_denumerator_DeltaRCut_DeltaPhiCut_PtCut_2", "Photons[tight_photons[0]].Pt()",80,0,400);
		CreateHisto("h_numerator_DeltaRCut_DeltaPhiCut_PtCut_2", "Photons[tight_photons[0]].Pt()",80,0,400);				
		CreateHisto("h_denumerator_DeltaRCut_PtCut_2", "Photons[tight_photons[0]].Pt()",80,0,400);
		CreateHisto("h_numerator_DeltaRCut_PtCut_2", "Photons[tight_photons[0]].Pt()",80,0,400);	
		CreateHisto("h_denumerator_DeltaRCut_DeltaPhiCut_PtCut_100_2", "Photons[tight_photons[0]].Pt()",80,0,400);
		CreateHisto("h_numerator_DeltaRCut_DeltaPhiCut_PtCut_100_2", "Photons[tight_photons[0]].Pt()",80,0,400);				
		CreateHisto("h_denumerator_DeltaRCut_PtCut_100_2", "Photons[tight_photons[0]].Pt()",80,0,400);
		CreateHisto("h_numerator_DeltaRCut_PtCut_100_2", "Photons[tight_photons[0]].Pt()",80,0,400);		
		
			
		CreateHisto("h_denumerator_DeltaRCut_2", "Photons[tight_photons[0]].Pt()",80,0,400);		
		CreateHisto("h_numerator_DeltaRCut_2", "Photons[tight_photons[0]].Pt()",80,0,400);
		
							
		CreateHisto("h_numerator_final_pt_leg_tight_40_2", "Photons[tight_photons[0]].Pt()",80,0,400);	
		CreateHisto("h_denumerator_final_pt_leg_tight_40_2", "Photons[tight_photons[0]].Pt()",80,0,400);		
		
		CreateHisto("h_numerator_final_pt_leg_tight_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_tight_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_ID_leg_tight_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_ID_leg_tight_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_ID_leg_tight_wo_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_ID_leg_tight_wo_1", "photon pt [GeV]", 80, 0, 400); 		
				
		CreateHisto("h_numerator_final_met_leg_tight_1", "MET [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_tight_1", "MET [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_pt_leg_tight_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_tight_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_pt_leg_tight_woMETcut_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_tight_woMETcut_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_met_leg_tight_2", "MET [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_tight_2", "MET [GeV]", 80, 0, 400); 	
		
		CreateHisto("h_numerator_final_pt_leg_loose_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_loose_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_ID_leg_loose_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_ID_leg_loose_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_ID_leg_loose_wo_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_ID_leg_loose_wo_1", "photon pt [GeV]", 80, 0, 400); 		
				
		CreateHisto("h_numerator_final_met_leg_loose_1", "MET [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_loose_1", "MET [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_pt_leg_loose_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_loose_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_pt_leg_loose_woMETcut_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_loose_woMETcut_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_met_leg_loose_2", "MET [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_loose_2", "MET [GeV]", 80, 0, 400);		
		
		CreateHisto("h_numerator_final_met_leg_loose_wo", "MET [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_loose_wo", "MET [GeV]", 80, 0, 400);	
		
		CreateHisto("h_numerator_MET_calc", "MET [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_MET_calc", "MET [GeV]", 80, 0, 400);					

	  
		CreateHisto("h_signal_pt", "Photons[0].Pt()",150, 0, 300);		
    CreateHisto("h_signal_r9", "photons_photons_r9[0]",130, 0, 1.3 );
		CreateHisto("h_signal_eVeto", "photons_photons_passelectronveto[0]",3, -0.5, 2.5);
		CreateHisto("h_signal_nPixelSeeds", "photons_photons_nPixelSeeds[0]",20, -0.5, 19.5);
		CreateHisto("h_signal_fidBit", "photons_photons_fidBit[0]", 110, -10.5, 99.5);
		CreateHisto("h_signal_e5x5", "e5x5[0].Pt()",150, 0, 300);			
    CreateHisto("h_signal_HE", "photons_photons_hadronicOverEm[0]",110, 0, 1.1);
    CreateHisto("h_signal_sigmaEE", "photons_photons_sigmaEtaEta[0]",100, 0, 0.05);     
    CreateHisto("h_signal_sigmaIEIE", "photons_photons_sigmaIetaIeta[0]",100, 0, 0.05);                
    CreateHisto("h_signal_ecalSumEt04", "photons_photons_ecalRecHitSumEtConeDR04[0]",100, 0, 10);
    CreateHisto("h_signal_ecalSumEt03", "photons_photons_ecalRecHitSumEtConeDR03[0]",100, 0, 10);
    CreateHisto("h_signal_ecalSumEt03_cal", "photons_photons_ecalRecHitSumEtConeDR03[0]-(Photons[0].Et()*0.012)",100, 0, 10);        
    CreateHisto("h_signal_hcalIsoDepth1", "photons_photons_hcalDepth1TowerSumEtConeDR03[0]",100, 0, 10);
    CreateHisto("h_signal_hcalIsoDepth2", "photons_photons_hcalDepth2TowerSumEtConeDR03[0]",100, 0, 10);    
    CreateHisto("h_signal_hcalIsoDepth12", "photons_photons_hcalDepth1TowerSumEtConeDR03[0]+photons_photons_hcalDepth2TowerSumEtConeDR03[0]",100, 0, 10);        
	  CreateHisto("h_signal_trkSumHollow", "photons_photons_trkSumPtHollowConeDR03[0]",100, 0, 10);
		CreateHisto("h_signal_eta", "Photons[0].Eta()", 100, -5, 5);
		
		CreateHisto2D("h_corr_pt", "Photons[0].Pt()",80, 0, 400, 80, 0, 400);		
    CreateHisto2D("h_corr_r9", "photons_photons_r9[0]",65, 0, 1.3, 80, 0, 400 );
		CreateHisto2D("h_corr_eVeto", "photons_photons_passelectronveto[0]",3, -0.5, 2.5, 80, 0, 400);
		CreateHisto2D("h_corr_nPixelSeeds", "photons_photons_nPixelSeeds[0]",20, -0.5, 19.5, 80, 0, 400);
		CreateHisto2D("h_corr_fidBit", "photons_photons_fidBit[0]", 110, -10.5, 99.5, 80, 0, 400);
		CreateHisto2D("h_corr_e5x5", "e5x5[0].Pt()",80, 0, 400, 80, 0, 400);			
    CreateHisto2D("h_corr_HE", "photons_photons_hadronicOverEm[0]",110, 0, 1.1, 80, 0, 400);
    CreateHisto2D("h_corr_HTowE", "photons_photons_hadTowOverEm[0]",110, 0, 1.1, 80, 0, 400);		
    CreateHisto2D("h_corr_sigmaEE", "photons_photons_sigmaEtaEta[0]",100, 0, 0.05, 80, 0, 400);     
    CreateHisto2D("h_corr_sigmaIEIE", "photons_photons_sigmaIetaIeta[0]",100, 0, 0.05, 80, 0, 400);                
    CreateHisto2D("h_corr_ecalSumEt04", "photons_photons_ecalRecHitSumEtConeDR04[0]",100, 0, 10, 80, 0, 400);
    CreateHisto2D("h_corr_ecalSumEt03", "photons_photons_ecalRecHitSumEtConeDR03[0]",100, 0, 10, 80, 0, 400);
    CreateHisto2D("h_corr_ecalSumEt03_cal", "photons_photons_ecalRecHitSumEtConeDR03[0]-(Photons[0].Et()*0.012)",100, 0, 10, 80, 0, 400);        
    CreateHisto2D("h_corr_hcalIsoDepth1", "photons_photons_hcalDepth1TowerSumEtConeDR03[0]",100, 0, 10, 80, 0, 400);
    CreateHisto2D("h_corr_hcalIsoDepth2", "photons_photons_hcalDepth2TowerSumEtConeDR03[0]",100, 0, 10, 80, 0, 400);    
    CreateHisto2D("h_corr_hcalIsoDepth12", "photons_photons_hcalDepth1TowerSumEtConeDR03[0]+photons_photons_hcalDepth2TowerSumEtConeDR03[0]",100, 0, 10, 80, 0, 400);        
	  CreateHisto2D("h_corr_trkSumHollow", "photons_photons_trkSumPtHollowConeDR03[0]",100, 0, 10, 80, 0, 400);
		CreateHisto2D("h_corr_eta", "Photons[0].Eta()", 100, -5, 5, 80, 0, 400);		
		
				 	 
		CreateHisto("h_pt_iso", "Photons[0].Pt()",150, 0, 300);
    CreateHisto("h_r9_iso", "photons_photons_r9[0]",130, 0, 1.3 );
		CreateHisto("h_eVeto_iso", "photons_photons_passelectronveto[0]",3, -0.5, 2.5);
		CreateHisto("h_nPixelSeeds_iso", "photons_photons_nPixelSeeds[0]",20, -0.5, 19.5);
		CreateHisto("h_fidBit_iso", "photons_photons_fidBit[0]", 110, -10.5, 99.5);
		CreateHisto("h_e5x5_iso", "e5x5[0].Pt()",150, 0, 300);		
    CreateHisto("h_HE_iso", "photons_photons_hadronicOverEm[0]",110, 0, 1.1);
    CreateHisto("h_sigmaEE_iso", "photons_photons_sigmaEtaEta[0]",100, 0, 0.05);     
    CreateHisto("h_sigmaIEIE_iso", "photons_photons_sigmaIetaIeta[0]",100, 0, 0.05);                
    CreateHisto("h_ecalSumEt04_iso", "photons_photons_ecalRecHitSumEtConeDR04[0]",100, 0, 10);
    CreateHisto("h_ecalSumEt03_iso", "photons_photons_ecalRecHitSumEtConeDR03[0]",100, 0, 10);
    CreateHisto("h_ecalSumEt03_iso_cal", "photons_photons_ecalRecHitSumEtConeDR03[0]-(Photons[0].Et()*0.012)",100, 0, 10);        
    CreateHisto("h_hcalIsoDepth1_iso", "photons_photons_hcalDepth1TowerSumEtConeDR03[0]",100, 0, 10);
    CreateHisto("h_hcalIsoDepth2_iso", "photons_photons_hcalDepth2TowerSumEtConeDR03[0]",100, 0, 10);    
    CreateHisto("h_hcalIsoDepth12_iso", "photons_photons_hcalDepth1TowerSumEtConeDR03[0]+photons_photons_hcalDepth2TowerSumEtConeDR03[0]",100, 0, 10);        
	  CreateHisto("h_trkSumHollow_iso", "photons_photons_trkSumPtHollowConeDR03[0]",100, 0, 10);
		CreateHisto("h_eta_iso", "Photons[0].Eta()", 100, -5, 5);		
		CreateHisto("h_denumerator", "Photons[0].Pt()",250, 0, 500);
		CreateHisto("h_numerator", "Photons[0].Pt()",250, 0, 500);
		
		CreateHisto("h_denumerator_loose_eta", "Photons[loose_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_denumerator_loose_eta_r9", "Photons[loose_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_numerator_loose_eta", "Photons[loose_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_numerator_loose_eta_r9", "Photons[loose_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_denumerator_tight_eta"," Photons[tight_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_denumerator_tight_eta_r9", "Photons[tight_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_numerator_tight_eta", "Photons[tight_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_numerator_tight_eta_r9", "Photons[tight_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_numerator_tight_eta_r9_turnon", "Photons[tight_photons[0]].r9", 250, 0, 500);		
		CreateHisto("h_denumerator_tight_eta_r9_turnon", "Photons[tight_photons[0]].r9", 250, 0, 500);	
		CreateHisto("h_denumerator_eta_hadronic_turnon", "Photons[tight_photons[0]].hadronic", 250, 0, 500);	
		CreateHisto("h_denumerator_tight_eta_hadronic_turnon", "Photons[tight_photons[0]].hadronic", 250, 0, 500);	
		CreateHisto("h_denumerator_eta_hdepth_turnon", "Photons[tight_photons[0]].hdepth", 250, 0, 500);	
		CreateHisto("h_denumerator_tight_eta_hdepth_turnon", "Photons[tight_photons[0]].hdepth", 250, 0, 500);	
		CreateHisto("h_denumerator_eta_tracksum_turnon", "Photons[tight_photons[0]].tracksum", 250, 0, 500);	
		CreateHisto("h_denumerator_tight_eta_tracksum_turnon", "Photons[tight_photons[0]].tracksum", 250, 0, 500);	
		CreateHisto("h_numerator_eta_hadronic_turnon", "Photons[tight_photons[0]].hadronic", 250, 0, 500);	
		CreateHisto("h_numerator_tight_eta_hadronic_turnon", "Photons[tight_photons[0]].hadronic", 250, 0, 500);	
		CreateHisto("h_numerator_eta_hdepth_turnon", "Photons[tight_photons[0]].hdepth", 250, 0, 500);	
		CreateHisto("h_numerator_tight_eta_hdepth_turnon", "Photons[tight_photons[0]].hdepth", 250, 0, 500);	
		CreateHisto("h_numerator_eta_tracksum_turnon", "Photons[tight_photons[0]].tracksum", 250, 0, 500);	
		CreateHisto("h_numerator_tight_eta_tracksum_turnon", "Photons[tight_photons[0]].tracksum", 250, 0, 500);		
		
	
		CreateHisto("h_denumerator_all_loose_eta"," Photons[loose_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_denumerator_all_loose_eta_r9"," Photons[loose_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_numerator_all_loose_eta", "Photons[loose_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_numerator_all_loose_eta_r9", "Photons[loose_photons[0]].Pt()", 250, 0, 500);	
		CreateHisto("h_denumerator_all_loose_eta_r9_e5x5"," Photons[loose_photons[0]].e5", 250, 0, 500);
		CreateHisto("h_numerator_all_loose_eta_r9_e5x5", "Photons[loose_photons[0]].e5", 250, 0, 500);					
		
		CreateHisto("h_denumerator_trigger"," Photons[loose_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_denumerator_all_trigger"," Photons[loose_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_numerator_trigger", "Photons[loose_photons[0]].Pt()", 250, 0, 500);
		CreateHisto("h_numerator_all_trigger", "Photons[loose_photons[0]].Pt()", 250, 0, 500);		
 
	  CreateHisto("h_check_signal_r9", "photons_photons_r9", 100, 0, 2);
		CreateHisto("h_check_signal_HE", "photons_photons_hadTowOverEm", 110, 0, 1.1);
		CreateHisto("h_check_signal_ecalSumEt04", "photons_photons_ecalRecHitSumEtConeDR04", 100, 0, 100);
		CreateHisto("h_check_signal_ecalSumEt03", "photons_photons_ecalRecHitSumEtConeDR03", 100, 0, 100);
		CreateHisto("h_check_signal_hcalIsoCone", "photons_photons_hcalIsoConeDR04_2012", 100, 0, 100);
		CreateHisto("h_check_signal_hcalDepth03", "photons_photons_hcalDepth1TowerSumEtConeDR03", 100, 0, 100);
		CreateHisto("h_check_signal_eta", "Photons[loose_photons[0]].Eta()", 50, -5, 5);
	 
	  CreateHisto("h_check_met_r9", "photons_photons_r9", 100, 0, 2);
		CreateHisto("h_check_met_HE", "photons_photons_hadTowOverEm", 110, 0, 1.1);
		CreateHisto("h_check_met_ecalSumEt04", "photons_photons_ecalRecHitSumEtConeDR04", 100, 0, 100);
		CreateHisto("h_check_met_ecalSumEt03", "photons_photons_ecalRecHitSumEtConeDR03", 100, 0, 100);
		CreateHisto("h_check_met_hcalIsoCone", "photons_photons_hcalIsoConeDR04_2012", 100, 0, 100);
		CreateHisto("h_check_met_hcalDepth03", "photons_photons_hcalDepth1TowerSumEtConeDR03", 100, 0, 100);
		CreateHisto("h_check_met_eta", "Photons[loose_photons[0]].Eta()", 50, -5, 5);	
		 
	  CreateHisto("h_check_signal_r9_iso", "photons_photons_r9", 100, 0, 2);
		CreateHisto("h_check_signal_HE_iso", "photons_photons_hadTowOverEm", 110, 0, 1.1);
		CreateHisto("h_check_signal_ecalSumEt04_iso", "photons_photons_ecalRecHitSumEtConeDR04", 100, 0, 100);
		CreateHisto("h_check_signal_ecalSumEt03_iso", "photons_photons_ecalRecHitSumEtConeDR03", 100, 0, 100);
		CreateHisto("h_check_signal_hcalIsoCone_iso", "photons_photons_hcalIsoConeDR04_2012", 100, 0, 100);
		CreateHisto("h_check_signal_hcalDepth03_iso", "photons_photons_hcalDepth1TowerSumEtConeDR03", 100, 0, 100);
		CreateHisto("h_check_signal_eta_iso", "Photons[loose_photons[0]].Eta()", 50, -5, 5);
	 
	  CreateHisto("h_check_met_r9_iso", "photons_photons_r9", 100, 0, 2);
		CreateHisto("h_check_met_HE_iso", "photons_photons_hadTowOverEm", 110, 0, 1.1);
		CreateHisto("h_check_met_ecalSumEt04_iso", "photons_photons_ecalRecHitSumEtConeDR04", 100, 0, 100);
		CreateHisto("h_check_met_ecalSumEt03_iso", "photons_photons_ecalRecHitSumEtConeDR03", 100, 0, 100);
		CreateHisto("h_check_met_hcalIsoCone_iso", "photons_photons_hcalIsoConeDR04_2012", 100, 0, 100);
		CreateHisto("h_check_met_hcalDepth03_iso", "photons_photons_hcalDepth1TowerSumEtConeDR03", 100, 0, 100);
		CreateHisto("h_check_met_eta_iso", "Photons[loose_photons[0]].Eta()", 50, -5, 5);		 
		
   CreateHisto("h_efficiency_met_my", "trigger efficiency met", 1, 0, 4000);	 
   CreateHisto("h_efficiency_met_cross", "trigger efficiency met", 1, 0, 4000);	 
   CreateHisto("h_efficiency_photon_my", "trigger efficiency photon pt", 1, 0, 4000);	 
   CreateHisto("h_efficiency_photon_cross", "trigger efficiency photon pt", 1, 0, 4000);
	 
	 CreateHisto("h_triggereff__mytrigger_instLumi", "inst. lumi signal trigger", 140, 100, 800);
	 CreateHisto("h_triggereff__mytrigger_runNumber", "run number signal trigger", 18240, 190456, 208696);
	 CreateHisto("h_triggereff__mytrigger_lumiBlock", "lumi block signal trigger", 2000, 0, 2000);
	 CreateHisto("h_triggereff__crosstrigger_instLumi", "inst. lumi cross trigger",140, 100, 800 );
	 CreateHisto("h_triggereff__crosstrigger_runNumber", "run number cross trigger", 18240, 190456, 208696);
	 CreateHisto("h_triggereff__crosstrigger_lumiBlock", "lumi block cross trigger", 2000, 0, 2000);	 
	 
	 CreateHisto("h_triggereff_metcross_mytrigger", "1st Photon pt, pass trigger", 250, 0, 500); 
	 CreateHisto("h_triggereff_metcross_crosstrigger", "1st Photon pt, pass MET > 100 crosstrigger", 250, 0, 500);
	 
	 CreateHisto("h_triggereff_metcross_mytrigger2", "1st Photon pt, pass trigger", 250, 0, 500); 
	 CreateHisto("h_triggereff_metcross_crosstrigger2", "1st Photon pt, pass MET > 100 crosstrigger", 250, 0, 500);	 
	 CreateHisto("h_triggereff_metcross_mytrigger3", "MET", 250, 0, 500); 
	 CreateHisto("h_triggereff_metcross_crosstrigger3", "MET", 250, 0, 500);		
	  
	 CreateHisto("h_triggereff_photonptcross_mytrigger_vor", "MET, pass trigger", 250, 0, 500); 
	 CreateHisto("h_triggereff_photonptcross_crosstrigger_vor", "MET, pass iso photon pt > 30 crosstrigger", 250, 0, 500);	
	 CreateHisto("h_triggereff_photonptcross_mytrigger_vor2", "MET, pass trigger", 150, 0, 300); 
	 CreateHisto("h_triggereff_photonptcross_crosstrigger_vor2", "MET, pass iso photon pt > 30 crosstrigger", 150, 0, 300);		 
	 CreateHisto("h_triggereff_photonptcross_mytrigger_nach", "MET, pass trigger", 150, 0, 300); 
	 CreateHisto("h_triggereff_photonptcross_crosstrigger_nach", "MET, pass iso photon pt > 30 crosstrigger", 150, 0, 300);	 
	  
	 CreateHisto("h_triggereff_photonptcross_mytrigger_2", "MET, pass trigger", 60, 0, 120); 
	 CreateHisto("h_triggereff_photonptcross_crosstrigger_2", "MET, pass iso photon pt > 30 crosstrigger", 60, 0, 120);
 
	 
	 CreateHisto("h_effitest", "Trigger efficiency", 13, -0.15, 1.15);
	 CreateHisto2D("h_2_effitest", "Trigger efficiency", 13, -0.15, 1.15, 2000, 0, 2000);
						
						
  #endif				
						
	 CreateHisto("h_photon_seedTime", "seed time of 1st tight photon ", 100, -100,100);	
	 									
	 CreateHisto("h_truth_ht", "ht on GEN level for status 1 ", 200, 0, 1000);
	 CreateHisto("h_truth_photon_pt", "pt of photons (22) on GEN level for status 1 ", 36, 0, 400);	
	 CreateHisto("h_truth_photons_pt_sel", "pt of photons (22) on GEN level for status 1 ", 36, 0, 500);	
	 CreateHisto("h_truth_electrons_pt_sel", "pt of electrons (+-11) on GEN level for status 1 ", 36, 0, 500);	 	  
	 CreateHisto("h_trueNum", "true num interactions ", 60, 0, 60);	 
	 CreateHisto("h_trueNum2", "true num interactions ", 60, 0, 60);	
	 CreateHisto("h_truth_fake_met_sel","MET.Pt()",50,50,600);
	 CreateHisto("h_truth_fake_inverse_met_sel","1./MET.Pt()", 60, 0, 0.025);
	 CreateHisto("h_truth_fake_tight_photon_pt_sel","Photons[tight_photons[0]].Pt()", 50, 0, 1000);
	 CreateHisto("h_met_datadriven","MET.Pt()",50,50,600);
	 CreateHisto("h_inverse_met_datadriven","1./MET.Pt()", 60, 0, 0.025);	
	 CreateHisto("h_tight_photon_pt_datadriven","Photons[tight_photons[0]].Pt()", 50, 0, 1000);	
						
						 
	 CreateHisto("h_photon_HE","H Tower over E", 100, 0, 1);
	 CreateHisto("h_photon_iso"," photon iso", 200, 0, 100);	 
	 CreateHisto("h_photon_r9", "photon r9", 100, 0.5, 1.5);
	 CreateHisto("h_photon_ecalRecEt"," photons_photons_ecalRecHitSumEtConeDR04", 200, 0, 100);	 
	 CreateHisto("h_SigmaIetaIeta", "sigma IetaIeta of tight photons", 40, 0, 0.04);
	 CreateHisto("h_met_SigmaIetaIeta_low", "MET.Pt()", 50, 50, 600);
		CreateHisto("h_met_SigmaIetaIeta_high", "MET.Pt()", 50, 50, 600);
		CreateHisto("h_met_SigmaIetaIeta_low_1", "MET.Pt()", 50, 50, 600);
		CreateHisto("h_met_SigmaIetaIeta_high_1", "MET.Pt()", 50, 50, 600);	 
	 CreateHisto("h_met_vor", "MET", 50, 50, 600);
	 CreateHisto("h_met_nach", "MET", 50, 50, 600);
	 
	 CreateHisto("h_met", "MET", 50, 50, 600);
	 CreateHisto("h_met_nJetmax2", "MET", 50, 50, 600);	 
	 CreateHisto("h_met_nJetmin3", "MET", 50, 50, 600);	
	 CreateHisto("h_met_npixel0", "MET", 50, 50, 600);	 
	 CreateHisto("h_met_npixel1", "MET", 50, 50, 600);		 
	 CreateHistoArray("h_met_array", "MET", 10, metbinning);	 
	 CreateHisto("h_met_cut", "MET", 50, 50, 600);	 
	 CreateHisto("h_inverse_MET", "1/MET", 60, 0, 0.025);
	 CreateHistoArray("h_inverse_MET_array", "1/MET", 14, inversemetbinning);	 
	 CreateHisto("h_inverse_MET_sig", "1/MET", 60, 0, 0.025);	
	 CreateHisto("h_inverse_MET_GJets", "1/MET", 60, 0, 0.025);	  
	 CreateHisto("h_inverse_MET_cut", "1/MET", 60, 0, 0.025);
	 	 
   CreateHisto("h_n_photon_2", " # of loose photons",10, -0.5, 9.5);	 	 
	 CreateHisto("h_n_photon", "# of photons", 10, -0.5, 9.5);	 
	 CreateHisto("h_n_photon_loose", " # of loose photons",10, -0.5, 9.5);
	 CreateHisto("h_n_photon_tight", " # of tight photons",10, -0.5, 9.5);
	 CreateHisto("h_n_photon_pixel", " # of pixel photons",10, -0.5, 9.5);	 	 
	 CreateHisto("h_n_photon_trigger", " # of trigger photons",10, -0.5, 9.5);
	 CreateHisto("h_n_photon_loose_cut", " # of photons",10, -0.5, 9.5);	
	 CreateHisto("h_n_jets", "# of jets", 10, -0.5, 9.5);
	 CreateHisto("h_n_jets_loose", "# of loose jets", 10, -0.5, 9.5);
	 CreateHisto("h_n_jets_cleaned", "# of cleaned jets", 10, -0.5, 9.5);
	 CreateHisto("h_n_jets_photon_matched", "# of photon matched jets", 10, -0.5, 9.5);	 
	 CreateHisto("h_n_cleaned_jets_low", "# of cleaned jets", 10, -0.5, 9.5);	 
	 CreateHisto("h_n_bJets", "# of b jets", 10, -0.5, 9.5);	 	 
	 CreateHisto("h_n_electrons_medium", "# of medium electrons", 10, -0.5, 9.5);
	 

	 CreateHisto("h_sum_pt_photons", "sum_photon_pt",50,0,1000);
	 CreateHisto("h_sum_pt", "sum_pt",60,0,3000);
	 CreateHisto("h_centrality", "centrality",22,0,1.1);
	 CreateHisto("h_centrality_photon", "centrality",22,0,1.1);	 
	 CreateHisto("h_sum_signal","sum_signal",50,0,2000);	 
	 CreateHisto("h_sum_visible","sum_signal",50,0,2000);	 
	 
	 CreateHisto("h_sum_pt_photons_low", "sum_photon_pt",50,0,1000);
	 CreateHisto("h_sum_pt_low", "sum_pt",60,0,2000);
	 CreateHisto("h_centrality_low", "centrality",22,0,1.1);
	 CreateHisto("h_centrality_photon_low", "centrality",22,0,1.1);	 
	 CreateHisto("h_sum_signal_low","sum_signal",50,0,2000);	 
	 CreateHisto("h_sum_visible_low","sum_signal",50,0,2000);		 	
	 CreateHisto("h_tight_1photon_pt_low","Photons[tight_photons[0]].Pt()",40,0,1000);		 
	 CreateHisto("h_sum_pt_photons_high", "sum_photon_pt",50,0,1000);
	 CreateHisto("h_sum_pt_high", "sum_pt",60,0,3000);
	 CreateHisto("h_centrality_high", "centrality",22,0,1.1);
	 CreateHisto("h_centrality_photon_high", "centrality",22,0,1.1);	 
	 CreateHisto("h_sum_signal_high","sum_signal",50,0,2000);	 
	 CreateHisto("h_sum_visible_high","sum_signal",50,0,2000);		 	
	 CreateHisto("h_tight_1photon_pt_high","Photons[tight_photons[0]].Pt()",40,0,1000);
	 		 
	 CreateHistoArray("h_HT_array", "HT of all jets [GeV]", 38, HTbinning);
	 CreateHistoArray("h_HT_array_HT_cut", "HT of all jets [GeV]", 38, HTbinning);	 
	 CreateHistoArray("h_HT_array_pt_cut", "HT of all jets [GeV]", 38, HTbinning);	 	
	 CreateHistoArray("h_HT_array_datadriven", "HT of all jets [GeV]", 38, HTbinning);	 		 
	 CreateHisto("h_HT_raw","HT of all jets [GeV]",50,0.,3000);	
	 CreateHisto("h_HT","HT of all jets [GeV]",50,0.,3000);	
	 CreateHisto("h_HT2","HT of all jets [GeV]",50,0.,3000);	 
	 CreateHisto("h_HT_sig","HT of all jets [GeV]",50,0.,3000);
	 CreateHisto("h_HT_GJets","HT of all jets [GeV]",50,0.,3000);	 	  
	 CreateHisto("h_HT_metcut","HT of all loose jets with MET > 50 GeV [GeV]",60,0.,1500);
	 	 
	 CreateHisto("h_reco_vert_n_vor", "# of vertices", 40, -0.5, 39.5); 
	 CreateHisto("h_reco_vert_n_nach", "# of vertices", 40, -0.5, 39.5);	 	 
	 CreateHisto("h_reco_vert_n", "# of vertices", 40, -0.5, 39.5);
	 	 	 
	 CreateHisto("h_loose_jets_pt", "Pt of loose jets", 60, 0, 1200);	
	 CreateHisto("h_cleaned_jets_pt", "Pt of cleaned jets", 60, 0, 1200);	  
	 CreateHisto("h_loose_photons_pt", "Pt of loose photons", 50, 0, 1000);	
	 CreateHisto("h_loose_photon_e5x5", "e5x5 of loose photons", 32, 0, 400);
	 CreateHisto("h_loose_1photons_pt", "Pt of 1st loose photon", 50, 0, 1000);
	 CreateHisto("h_tight_1photons_pt", "Pt of 1st tight photon", 50, 0, 1000);	 
	 CreateHisto("h_loose_1photons_pt_cut", "Pt of loose photons", 32, 0, 400);		 
	 	 
	 CreateHisto("h_photon_eta", "Eta of photons", 40, -4, 4);	 
	 CreateHisto("h_loose_photon_eta_vor", "Eta of loose photons", 40, -4, 4);	 
	 CreateHisto("h_loose_photon_eta", "Eta of loose photons", 40, -4, 4);
	 CreateHisto("h_Eta_Jet", "Eta of Jets", 40, -4, 4);	 	 
		  	  
	 CreateHisto("h_cleaned_jets_chargedHE", "charged hadron energy in loose jets", 32, 0, 400);	 
	 CreateHisto("h_cleaned_jets_chargedfrac", "charged hadron energy fraction in loose jets", 20, 0, 1);	 
	 CreateHisto("h_cleaned_jets_chargedM", "charged Multiplicity in loose jets", 30, -0.5, 29.5);	  
   
	 
	 CreateHisto("h_matched_jet_chargedHadronEnergy","Jets[photon_matched_jets[i]].chargedHadronEnergy",40, 0, 500 );
	 CreateHisto("h_matched_jet_neutralHadronEnergy","Jets[photon_matched_jets[i]].neutralHadronEnergy",40, 0, 320 );		 
	 CreateHisto("h_matched_jet_photonEnergy","Jets[photon_matched_jets[i]].photonEnergy",40, 0, 600 );		 
	 CreateHisto("h_matched_jet_nConstituents","Jets[photon_matched_jets[i]].nConstituents", 40, -0.5, 39.5);
	 CreateHisto("h_matched_jet_chargedHadronMultiplicity","Jets[photon_matched_jets[i]].chargedHadronMultiplicity", 30, -0.5, 29.5);
	 CreateHisto("h_matched_jet_neutralHadronMultiplicity","Jets[photon_matched_jets[i]].neutralHadronMultiplicity", 30, -0.5, 29.5);		 
	 CreateHisto("h_matched_jet_chargedMultiplicity","Jets[photon_matched_jets[i]].chargedMultiplicity", 30, -0.5, 29.5);
	 CreateHisto("h_matched_jet_neutralMultiplicity","Jets[photon_matched_jets[i]].neutralMultiplicity", 30, -0.5, 29.5);
	 CreateHisto("h_matched_jet_photonMultiplicity","Jets[photon_matched_jets[i]].photonMultiplicity", 30, -0.5, 29.5);  
		 
		 
	 CreateHisto("h_AngleMJ", "Angle between Jets and MET", 42, 0, 4.2);
	 CreateHisto("h_AngleMJ1", "Angle between 1st Jet and MET", 42, 0, 4.2);	 
	 CreateHisto("h_AngleMJ2", "Angle between 2nd Jet and MET", 42, 0, 4.2);	 
	 CreateHisto("h_AngleMJ3", "Angle between 3rd Jet and MET", 42, 0, 4.2);	 
	 CreateHisto("h_AngleGM_all", "Angle between tight photon and MET", 42, 0, 4.2);	
	 CreateHisto("h_AngleGM_test", "Angle between tight photon and MET", 42, 0, 4.2);	   	 
	 CreateHisto("h_DeltaR_photon_jet", "Delta R of tight photon and nearest jet", 32,0,6.2);	 
	 CreateHisto("h_DeltaPhi_photon_jet", "Delta Phi of tight photon and nearest jet", 42,0,4.2);
	 CreateHisto("h_DeltaPhi_photon_jet_before", "Delta Phi of tight photon and nearest jet", 42,0,4.2);	 
	 CreateHisto("h_DeltaPhi_photon_jet_after", "Delta Phi of tight photon and nearest jet", 42,0,4.2);	 	
	 CreateHisto("h_DeltaPhi_photon_MET", "Delta Phi of tight photon and MET", 42,0,4.2);	  
	 CreateHisto("h_DeltaPhi_JJ", "Delta Phi of two highest energetic jets", 42,0,4.2);	
	 CreateHisto("h_DeltaPhi_JMother", "Delta Phi of two highest energetic jets and MET", 42,0,4.2);
	 CreateHisto("h_DeltaPhi_JMotherRel", "Delta Phi of two highest energetic jets and MET", 42,0,4.2);	
	 CreateHisto("h_DR_self","Delta R of all Jets and tight Photon", 64, 0, 6.4);
	 CreateHisto("h_DR_test","Delta R of all Jets and tight Photon", 64, 0, 6.4);	
	 
	 CreateHisto("h_Phi_MET", "MET.Phi()",42,0,4.2);	 
	  	
	 CreateHisto("h_bTagDisc", "b tag discriminator",60,-3,3);	
	  	 	 
	 CreateHisto("h_METoverHT","MET.Pt()/HT", 50, 0, 1);
	 CreateHisto("h_1tightPhotonPtOverHT", "Photons[tight_photons[0]].Pt()/HT", 50, 0, 2);
	 CreateHisto("h_1tightPhotonPtOverMET", "Photons[tight_photons[0]].Pt()/MET.Pt()", 75, 0, 15);
	 CreateHistoArray("h_1tightPhotonPtOverMET_scale", "Photons[tight_photons[0]].Pt()/MET.Pt()", 43, scalebinningPtOverMET );
	 CreateHistoArray("h_1tightPhotonPtOverMET_scale_HT_cut", "Photons[tight_photons[0]].Pt()/MET.Pt()", 43, scalebinningPtOverMET );	 	 
	 CreateHistoArray("h_1tightPhotonPtOverMET_scale_pt_cut", "Photons[tight_photons[0]].Pt()/MET.Pt()", 43, scalebinningPtOverMET );	
	  	 
	 CreateHisto("h_METoverSqHT"," MET.Pt()/(TMath::Sqrt(HT))",50,0,100);
	 CreateHistoArray("h_METoverSqHT_scale"," MET.Pt()/(TMath::Sqrt(HT))",30,scalebinning);	
	 CreateHistoArray("h_METoverSqHT_scale_HT_cut"," MET.Pt()/(TMath::Sqrt(HT))",30,scalebinning);	 
	 CreateHistoArray("h_METoverSqHT_scale_pt_cut"," MET.Pt()/(TMath::Sqrt(HT))",30,scalebinning);	 
	 CreateHistoArray("h_METoverSqHT_scale_HT"," MET.Pt()/(TMath::Sqrt(HT))",30,scalebinning);		 	 
	 CreateHistoArray("h_METoverSqHT_array"," MET.Pt()/(TMath::Sqrt(HT))",10,metsignificancebinning);	 
	 CreateHisto("h_HToverMET", "HT/MET.Pt()",60,0,20);
	 CreateHisto("h_InvMassJets","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEta","InvMassJetsEta",40,0,800); 
	 CreateHisto("h_InvMassJetsRel","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEtaRel","InvMassJetsEta",40,0,800);
	 CreateHisto("h_trans_mass_MET_Gamma","transverse mass of MET and Photon",40,0,800);
	 
	 
	 CreateHisto("h_METoverSqHT_low"," MET.Pt()/(TMath::Sqrt(HT))",50,0,100);
	 CreateHisto("h_HToverMET_low", "HT/MET.Pt()",60,0,20);
	 CreateHisto("h_InvMassJets_low","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEta_low","InvMassJetsEta",40,0,800); 
	 CreateHisto("h_InvMassJetsRel_low","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEtaRel_low","InvMassJetsEta",40,0,800);
	 CreateHisto("h_n_cleaned_jets_low","cleaned_jets.size()",10,-0.5,9.5);	
	 CreateHisto("h_trans_mass_MET_Gamma_low","TransMassMETGamma",50,0,1100);
	 CreateHisto("h_n_loose_photons_low","loose_photons.size()",10,-0.5,9.5);
	 CreateHisto("h_inverse_met_low"," 1./MET.Pt()", 60, 0, 0.025);
	 CreateHisto("h_tight_photon_pt_over_HT_low","Photons[tight_photons[0]].Pt()/HT", 50, 0, 2);
	 CreateHisto("h_cleaned_jets_pt_low","Jets[cleaned_jets[0]].Pt()", 60, 0, 1000);
	 CreateHisto("h_trans_mass_MET_Gamma_low_sig","TransMassMETGamma",50,0,1100);
	 CreateHisto("h_cleaned_jets_pt_low_sig","Jets[cleaned_jets[0]].Pt()", 60, 0, 1000);	 
	 CreateHisto("h_inverse_met_low_sig", "1./MET.Pt()", 60, 0, 0.025);
	 CreateHisto("h_n_loose_photons_low_sig","loose_photons.size()",10,-0.5,9.5);	
		 
	 CreateHisto("h_Etrans_rel","Relative transversal energy",40,0,800);
	 CreateHisto("h_DeltaPhi_rel", "rel Delta Phi",32,0,3.2);		 		 
	 CreateHisto("h_trans_mass_MET_Rel","TransMassMETRel",40,0,800);
	 CreateHisto("h_trans_mass_MET_Rel_Z","TransMassMETRel",40,0,800);	 
 	
	 
	 	  	  	 
	 CreateHisto("h_METoverSqHT_high"," MET.Pt()/(TMath::Sqrt(HT))",50,0,100);
	 CreateHisto("h_HToverMET_high", "HT/MET.Pt()",60,0,20);
	 CreateHisto("h_InvMassJets_high","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEta_high","InvMassJetsEta",40,0,800); 
	 CreateHisto("h_InvMassJetsRel_high","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEtaRel_high","InvMassJetsEta",40,0,800);	 
	 CreateHisto("h_n_cleaned_jets_high","cleaned_jets.size()",10,-0.5,9.5);	
	 CreateHisto("h_trans_mass_MET_Gamma_high","TransMassMETGamma",50,0,1100);
	 CreateHisto("h_n_loose_photons_high","loose_photons.size()",10,-0.5,9.5);
	 CreateHisto("h_inverse_met_high"," 1./MET.Pt()", 60, 0, 0.025);
	 CreateHisto("h_tight_photon_pt_over_HT_high","Photons[tight_photons[0]].Pt()/HT", 50, 0, 2);
	 CreateHisto("h_cleaned_jets_pt_high","Jets[cleaned_jets[0]].Pt()", 60, 0, 1200);
	 CreateHisto("h_trans_mass_MET_Gamma_high_sig","TransMassMETGamma",50,0,1100);
	 CreateHisto("h_cleaned_jets_pt_high_sig","Jets[cleaned_jets[0]].Pt()", 60, 0, 1200);	 
	 CreateHisto("h_inverse_met_high_sig", "1./MET.Pt()", 60, 0, 0.025);
	 CreateHisto("h_n_loose_photons_high_sig","loose_photons.size()",10,-0.5,9.5);	
	 CreateHisto("h_trans_mass_MET_Gamma_high_ratio","TransMassMETGamma",50,0,1100);
	 CreateHisto("h_cleaned_jets_pt_high_ratio","Jets[cleaned_jets[0]].Pt()", 60, 0, 1200);	 
	 CreateHisto("h_inverse_met_high_ratio", "1./MET.Pt()", 60, 0, 0.025);
	 CreateHisto("h_n_loose_photons_high_ratio","loose_photons.size()",10,-0.5,9.5);	  
	 
	 CreateHisto("h_selection_low"," 1./MET.Pt()", 60, 0, 0.025);	 
	 CreateHisto("h_selection_high"," 1./MET.Pt()", 60, 0, 0.025);	 
	 CreateHisto("h_selection_high2"," 1./MET.Pt()", 60, 0, 0.025);	 
	
	// N-1 Plots
	 CreateHisto("h_N-1_mt_low", "TransMassMETGamma",50,0,1100);
	 CreateHisto("h_N-1_sum_pt_low", "sum_pt",60,0,2000);
	 CreateHisto("h_N-1_sum_signal_low", "sum_pt",60,0,2000);	 
	 CreateHisto("h_N-1_jet_pt_low", "Jets[cleaned_jets[0]].Pt()", 60, 0, 1000);
	 CreateHisto("h_inverse_met_selection_low", "1./MET.Pt()", 60, 0, 0.025);
	   
	 CreateHisto("h_N-1_METsig_high", "MET.Pt()/(TMath::Sqrt(HT)",50,0,100);
	 CreateHisto("h_N-1_mt_high", "TransMassMETGamma",50,0,1100);
	 CreateHisto("h_N-1_sum_pt_high", "sum_pt",60,0,3000);
	 CreateHisto("h_N-1_sum_signal_high", "sum_pt",60,0,3000);
	 CreateHisto("h_N-1_sum_ptOverHt_high", "sum pt of photons over Ht",50,0,2.5);	 	 
	 CreateHisto("h_N-1_n_jets_high", "cleaned_jets.size()",10,-0.5,9.5);
	 CreateHisto("h_inverse_met_selection_high", "1./MET.Pt()", 60, 0, 0.025);
	 
	 CreateHisto("h_n_pixel_selection_low","pixel_photons.size()",5,-0.5,4.5);
	 CreateHisto("h_n_photons_selection_low","loose_photons.size()",5,-0.5,4.5);	 
	 CreateHisto("h_n_jets_selection_low","pixel_photons.size()",10,-0.5,9.5);	 
	 CreateHisto("h_inverse_met_selection_pixel_low"," 1./MET.Pt()",60, 0, 0.025);
	 CreateHisto("h_inverse_met_selection_2gamma_low"," 1./MET.Pt()",60, 0, 0.025);	 	 
	 CreateHisto("h_n_pixel_selection_high","pixel_photons.size()",5,-0.5,4.5);
	 CreateHisto("h_n_photons_selection_high","pixel_photons.size()",5,-0.5,4.5);	 
	 CreateHisto("h_inverse_met_selection_pixel_high"," 1./MET.Pt()",60, 0, 0.025);
	 CreateHisto("h_inverse_met_selection_jets_high"," 1./MET.Pt()",60, 0, 0.025);
	 CreateHisto("h_inverse_met_selection_2gamma_high"," 1./MET.Pt()",60, 0, 0.025);	 	 
 	 CreateHisto("h_number_selection_inverse_met","1./MET.Pt()",60, 0, 0.025);
					
   CreateHisto2D("h2_sigmaIEIE_met","2D sigma i eta i eta and MET",40,0,0.04,40,0,600);			
   CreateHisto2D("h2_sigmaIEIE_met_1","2D sigma i eta i eta and MET",40,0,0.04,40,0,600);				
   CreateHisto2D("h2_n_photon_pixel_met","2D number of pixel photons and MET",3,-0.5,2.5,30,0,600);		 
   CreateHisto2D("h2_n_jets_met","2D number of cleaned jets and MET",10,-0.5,9.5,30,0,600);		 
   CreateHisto2D("h2_truth_photon_DeltaR_relPt_before","GenMatch for photons in DeltaR and relativ pt",50,0,0.5,50,-2.5,2.5);	
   CreateHisto2D("h2_truth_electron_DeltaR_relPt_before","GenMatch for electrons in DeltaR and relativ pt",50,0,0.5,50,-2.5,2.5);	 	 
   CreateHisto2D("h2_truth_photon_DeltaR_relPt","GenMatch for photons in DeltaR and relativ pt",50,0,0.5,50,-2.5,2.5);	
   CreateHisto2D("h2_truth_electron_DeltaR_relPt","GenMatch for electrons in DeltaR and relativ pt",50,0,0.5,50,-2.5,2.5);	  
	 CreateHisto2D("h2_vert_met", "correlation of # vertices and MET", 60, -0.5, 59.5, 40, 0, 100);	 
	 CreateHisto2D("h2_vert_pt", "correlation of # vertices and tight photon pt",60, -0.5, 59.5, 40, 0, 100);	 	 
	 CreateHisto2D("h_corrMETJet", " correlation of Phi of MET and Jets", 32, -3.2, 3.2, 32, -3.2, 3.2);
	 CreateHisto2D("h_corrMET1Jet", " correlation of Phi of MET and first Jet", 32, -3.2, 3.2, 32, -3.2, 3.2);
	 CreateHisto2D("h2_corr_r9_pt_signal", "correlation of r9 and photon pt", 130, 0, 1.3, 150, 0, 300);	 
	 CreateHisto2D("h2_corr_r9_pt_iso", "correlation of r9 and photon pt", 130, 0, 1.3, 150, 0, 300);
	 CreateHisto2D("h2_Corr_DeltaR_relPt_Photon_Jet", "Correlation of Delta R and relPt of Photon and Jet",40,0,1,40,0,4);
	 CreateHisto2D("h2_Corr_DeltaR_relPt2_Photon_Jet", "Correlation of Delta R and relPt of Photon and Jet",40,0,1,40,0,4);	 
}


float DeltaPhi(float a, float b) {
  float temp = std::abs(a-b);
  if (temp <= TMath::Pi())
    return temp;
  else
    return  2.*TMath::Pi() - temp;
} 


/* Create all interesting objects as photons, MET etc. 
	 Use own MyPhoton etc. classes and the variables given
	 in NtupleSelector.h */

void MySelector::BuildObjects() {

   Photons.clear();
   for (int i = 0; i < photons_photons_; ++i) {
      MyPhoton photon(photons_photons_momentum_fP_fX[i], photons_photons_momentum_fP_fY[i],photons_photons_momentum_fP_fZ[i],photons_photons_momentum_fE[i]);
			double photon_pt = photon.Pt();
			double photon_eta = photon.Eta();
			TVector3 caloPos(photons_photons_caloPosition_fX[i], photons_photons_caloPosition_fY[i], photons_photons_caloPosition_fZ[i]); 
			double calo_Eta = caloPos.Eta();
			photon.SetPhotonPt(photon_pt);
			photon.SetPhotonSeedTime(photons_photons_seedTime[i]);			
			photon.SetPhotonEta(photon_eta);			
			photon.SetCaloEta(calo_Eta);
			photon.SetRho(rho);
			photon.SetE5x5(photons_photons_e5x5[i]);
			photon.SetChargedHadronIso(photons_photons_chargedHadronIso[i]);
			photon.SetNeutralHadronIso(photons_photons_neutralHadronIso[i]);
			photon.SetPhotonIso(photons_photons_photonIso[i]);
			photon.Setr9(photons_photons_r9[i]);
			photon.SetHadronicOverEm(photons_photons_hadronicOverEm[i]);
			photon.SetHcalDepth1(photons_photons_hcalDepth1TowerSumEtConeDR03[i]);
			photon.SetTrackSumHollow(photons_photons_trkSumPtHollowConeDR03[i]);					
	/*		double neutralhadiso_corr = photon.ChargedHadronIso_corrected();
			double chargedhadiso_corr = photon.NeutralHadronIso_corrected();			
			double photoniso_corr = photon.PhotonIso_corrected();	
			photon.SetChargedHadronIso(chargedhadiso_corr);
			photon.SetNeutralHadronIso(neutralhadiso_corr);
			photon.SetPhotonIso(photoniso_corr);		*/			
			photon.SetSigmaIetaIeta(photons_photons_sigmaIetaIeta[i]);
			photon.SetSigmaIphiIphi(photons_photons_sigmaIphiIphi[i]);
			photon.SetNPixelSeeds(photons_photons_nPixelSeeds[i]);
			photon.SetHadTowOverEm(photons_photons_hadTowOverEm[i]);
			
      Photons.push_back(photon);
  	 }
		 
	 sort(Photons.begin(), Photons.end(), LorentzVectorSortPt);
	 
	 
	 Jets.clear();
	 for (int i = 0; i < pfJets_ak5_; ++i) {
      MyJet jet(pfJets_ak5_momentum_fP_fX[i], pfJets_ak5_momentum_fP_fY[i],pfJets_ak5_momentum_fP_fZ[i],pfJets_ak5_momentum_fE[i]);
			double jet_pt = jet.Pt();
			double jet_eta = jet.Eta();
			double jet_E = jet.E();
	 	  jet.SetJetPt(jet_pt);
			jet.SetJetEta(jet_eta);
			jet.SetJetE(jet_E);
			
			jet.SetChargedHadronEnergy(pfJets_ak5_chargedHadronEnergy[i]);
			jet.SetNeutralHadronEnergy(pfJets_ak5_neutralHadronEnergy[i]);
			jet.SetPhotonEnergy(pfJets_ak5_photonEnergy[i]);			
			jet.SetChargedEmEnergy(pfJets_ak5_chargedEmEnergy[i]);
			jet.SetNeutralEmEnergy(pfJets_ak5_neutralEmEnergy[i]);
			jet.SetNConstituents(pfJets_ak5_nConstituents[i]);
			jet.SetChargedHadronMultiplicity(pfJets_ak5_chargedHadronMultiplicity[i]);
			jet.SetNeutralHadronMultiplicity(pfJets_ak5_neutralHadronMultiplicity[i]);			
			jet.SetChargedMultiplicity(pfJets_ak5_chargedMultiplicity[i]);
			jet.SetNeutralMultiplicity(pfJets_ak5_neutralMultiplicity[i]);						
			jet.SetPhotonMultiplicity(pfJets_ak5_photonMultiplicity[i]);			
			jet.SetbTagDiscriminator(pfJets_ak5_bTagDiscriminators[i][5]);
			Jets.push_back(jet);
			}
	 sort(Jets.begin(), Jets.end(), LorentzVectorSortPt);
		
	 Electrons.clear();
	 for (int i = 0; i < electrons_gsfElectrons_; ++i) {
      MyElectron electron(electrons_gsfElectrons_momentum_fP_fX[i], electrons_gsfElectrons_momentum_fP_fY[i],electrons_gsfElectrons_momentum_fP_fZ[i],electrons_gsfElectrons_momentum_fE[i]);
			double electron_pt = electron.Pt();
			double electron_eta = electron.Eta();

	 	  electron.SetElectronPt(electron_pt);
			electron.SetElectronEta(electron_eta);
			electron.SetSigmaIetaIeta(electrons_gsfElectrons_sigmaIetaIeta[i]);
			electron.SetDeltaEtaSuperCluster(electrons_gsfElectrons_deltaEtaSuperClusterTrackAtVtx[i]);
			electron.SetDeltaPhiSuperCluster(electrons_gsfElectrons_deltaPhiSuperClusterTrackAtVtx[i]);			
			electron.SetHoverE(electrons_gsfElectrons_hcalOverEcalBc[i]);
			electron.SetEoverP(electrons_gsfElectrons_eSuperClusterOverP[i]);
			electron.SetEcalEnergy(electrons_gsfElectrons_ecalEnergy[i]);
			
			
			
			Electrons.push_back(electron);
			}
	 sort(Electrons.begin(), Electrons.end(), LorentzVectorSortPt);		
		
		
		
		
			
	 PfParticles.clear();
	 for (int i = 0; i < pfParticles_; ++i) {
      MyPfParticle pfparticle(pfParticles_momentum_fP_fX[i], pfParticles_momentum_fP_fY[i],pfParticles_momentum_fP_fZ[i],pfParticles_momentum_fE[i]);
			double pfParticle_pt = pfparticle.Pt();
	 	  pfparticle.SetPfPt(pfParticle_pt);
			
			PfParticles.push_back(pfparticle);
			}
			
	
	 GenParticles.clear();
	 for (int i = 0; i < genParticles_; ++i) {
      MyGenParticles genparticles(genParticles_momentum_fP_fX[i], genParticles_momentum_fP_fY[i],genParticles_momentum_fP_fZ[i],genParticles_momentum_fE[i]);
			double genparticles_pt = genparticles.Pt();
	 	  genparticles.SetGenPt(genparticles_pt);
			genparticles.SetPDGID(genParticles_pdgId[i]);
			genparticles.SetStatus(genParticles_status[i]);			
			GenParticles.push_back(genparticles);
			}	
			
	 sort(GenParticles.begin(), GenParticles.end(), LorentzVectorSortPt);	
	
			
	MET.SetXYZM(met_pfMet_mEt_fX, met_pfMet_mEt_fY, 0, 0);
	CaloMET.SetXYZM(met_caloType1CorrectedMet_mEt_fX, met_caloType1CorrectedMet_mEt_fY, 0, 0);
	metMET.SetXYZM(met_met_mEt_fX, met_met_mEt_fY, 0, 0);
	
	vertices_n = vertices_; 
	
}

/*simplify the creation of histograms */

void MySelector::CreateHisto(const char * name, const char * title,
			     int nBins, double xlow, double xup)
{
  TH1F * h = new TH1F(name, title, nBins, xlow, xup);
  h->SetXTitle(title);
  h->SetTitle(name);
  histo.Add(name, h);
}

void MySelector::CreateHistoArray(const char * name, const char * title,
			     int nBins, const float * bins )
{
  TH1F * h = new TH1F(name, title, nBins, bins);
  h->SetXTitle(title);
  h->SetTitle(name);
  histo.Add(name, h);
}


void MySelector::CreateHisto2D(const char * name, const char * title, int nbinsx, double xlow, double xup, int nbinsy, double ylow, double yup)
{
  TH2F * h = new TH2F(name, title, nbinsx, xlow, xup, nbinsy, ylow, yup);
  h->SetXTitle(title);
  h->SetTitle(name);
	histo2.Add(name, h);
}
/*void MySelector::Fill(const char * name, double value)
{
  TH1F * h = histo[name];
  if (h != 0)
    h->Fill(value, Eventweight);
  else {
    std::cout << std::string("Histogram \"") + name + std::string("\" not existing. Did you misspell or forgot to create?") << std::endl;
  }
}*/

void MySelector::Fill(const char * name, double value, double weight)
{
  TH1F * h = histo[name];
  if (h != 0)
    h->Fill(value,Eventweight*weight);
  else {
    std::cout << std::string("Histogram \"") + name + std::string("\" not existing. Did you misspell or forgot to create?") << std::endl;
  }
}


void MySelector::FillArray(const char * name, double value, double weight)
{
  TH1F * h = histo[name];
  if (h != 0){
		if (value < 150 ) {
    	h->Fill(value,Eventweight*weight);
			}	
		if (value > 150 && value < 250 ) {
    	h->Fill(value,Eventweight*weight/2);
			}
		if (value > 250 && value < 350 ) {
    	h->Fill(value,Eventweight*weight/4);
			}			
		if (value > 350 && value < 600 ) {
    	h->Fill(value,Eventweight*weight/10);
			}			
			
		}
  else {
    std::cout << std::string("Histogram \"") + name + std::string("\" not existing. Did you misspell or forgot to create?") << std::endl;
  }
}

void MySelector::FillArrayInverse(const char * name, double value, double weight)
{
  TH1F * h = histo[name];
  if (h != 0){
		if (value > -0.1 && value < 0.003 ) {
    	h->Fill(value,Eventweight*weight/6);
			}
		if (value > 0.003 && value < 0.005 ) {
    	h->Fill(value,Eventweight*weight/2);
			}
		if (value > 0.005) {
    	h->Fill(value,Eventweight*weight);
			}								
			
		}
  else {
    std::cout << std::string("Histogram \"") + name + std::string("\" not existing. Did you misspell or forgot to create?") << std::endl;
  }
}
	 
	 
void MySelector::FillArraySignificance(const char * name, double value, double weight)
{
  TH1F * h = histo[name];
  if (h != 0){
		if (value > -0.1 && value < 4 ) {
    	h->Fill(value,Eventweight*weight/2);
			}
		if (value > 4 && value < 12 ) {
    	h->Fill(value,Eventweight*weight);
			}
		if (value > 12 && value < 20) {
    	h->Fill(value,Eventweight*weight/2);
			}
		if (value > 20 && value < 30) {
    	h->Fill(value,Eventweight*weight/(2.5));
			}			
		if (value > 30 && value < 70) {
    	h->Fill(value,Eventweight*weight/(20));
			}											
			
		}
  else {
    std::cout << std::string("Histogram \"") + name + std::string("\" not existing. Did you misspell or forgot to create?") << std::endl;
  }
}	 

void MySelector::Fill(const char * name, const char * text, double weight)
{
  TH1F * h = histo[name];
  if (h != 0)
    h->Fill(text, Eventweight*weight);
  else {
    std::cout << std::string("Histogram \"") + name + std::string("\" not existing. Did you misspell or forgot to create?") << std::endl;
  }
}

void MySelector::Fill2(const char * name, double x, double y)
{
  TH2F * h = histo2[name];
  if (h != 0)
    h->Fill(x, y, Eventweight);
  else {
    std::cout << std::string("Histogram \"") + name + std::string("\" not existing. Did you misspell or forgot to create?") << std::endl;
  }
}

void MySelector::SetLumiWeight(double weight){

	Eventweight = weight;
	
	}
	
void MySelector::BGInfo(std::string const & BG){

	BGName = BG;
	
	}	
	
	
void MySelector::SetPileUpWeightFile( std::string const & filename ) {
        /** Reads the pileup histogram from a given file  **/

        TFile *puFile = new TFile( filename.c_str() );
			
        if( puFile->IsZombie() )
                std::cerr << "ERROR: Could not read pileup weight file " << filename << std::endl;

        std::string histogramName = "pileup";
        if( puFile->GetListOfKeys()->Contains( histogramName.c_str() ) )	{

                pileupHisto = ((TH1F*) puFile->Get( histogramName.c_str() ));
						
								}
								
}

float MySelector::getPileUpWeight(){
        /**
         * If a pileup weight histogram has been added, the pile-up weight for the
         * current event is computed.
         */

        float trueNumInteractions = -1;
				int i = 0;
        while( i < pu_ && trueNumInteractions < 0 ){

                if (pu_BX[i] == 0){
												Fill("h_trueNum",pu_trueNumInteractions[i]);
                        trueNumInteractions = pu_trueNumInteractions[i];
										}		
								i++;
        }
				float PileupWeight = 1;
        PileupWeight = pileupHisto->GetBinContent( pileupHisto->FindBin( trueNumInteractions ) );

        return PileupWeight;
}

Bool_t MySelector::Process(Long64_t entry)
{


	  if (entry % 5000 == 0)
    cout << "Analysing Process:  " << entry << endl;


   //std::cout << "Process( "<< entry <<" )" <<std::endl;
	 // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either MySelector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.


   //read full event:
 //  fChain->GetTree()->GetEntry(entry);
	 
	// cout << " Tree number: " << fChain->GetTreeNumber() << endl;
	 //Get background file
	// int p = fChain->GetTreeNumber();
	// std::cout << "file: " << p << std::endl;
	 
   //std::cout << "file location: " << s << std::endl;
	 //cout << "Starting Process for event: " << entry << endl;
 
   //read only specific branches: 
	 //(may be faster if a lot are unused and selection is nearly final)
	 
/*   b_rho25->GetEntry(entry);
	 
   b_met_caloType1CorrectedMet_mEt_fX->GetEntry(entry);
   b_met_caloType1CorrectedMet_mEt_fY->GetEntry(entry);	
	  
   b_met_met_mEt_fX->GetEntry(entry);
   b_met_met_mEt_fY->GetEntry(entry);	 	 
		 
		 
   b_met_pfMet_mEt_fX->GetEntry(entry);
   b_met_pfMet_mEt_fY->GetEntry(entry); 
	   
   b_photons_photons_->GetEntry(entry);
   b_photons_photons_nPixelSeeds->GetEntry(entry);
   b_photons_photons_hadTowOverEm->GetEntry(entry);
   b_photons_photons_sigmaEtaEta->GetEntry(entry);
   b_photons_photons_sigmaIetaIeta->GetEntry(entry);
   b_photons_photons_sigmaIphiIphi->GetEntry(entry);
   b_photons_photons_chargedHadronIso->GetEntry(entry);
	 b_photons_photons_neutralHadronIso->GetEntry(entry);
	 b_photons_photons_photonIso->GetEntry(entry);
 	 b_photons_photons_caloPosition_fX->GetEntry(entry);
	 b_photons_photons_caloPosition_fY->GetEntry(entry);
 	 b_photons_photons_caloPosition_fZ->GetEntry(entry);
	 b_photons_photons_momentum_fP_fX->GetEntry(entry);
	 b_photons_photons_momentum_fP_fY->GetEntry(entry);
 	 b_photons_photons_momentum_fP_fZ->GetEntry(entry);
	 b_photons_photons_momentum_fE->GetEntry(entry);
	 b_photons_photons_r9->GetEntry(entry);   
   b_photons_photons_ecalRecHitSumEtConeDR04->GetEntry(entry);
	 
	 b_pfJets_ak5_->GetEntry(entry);
	 b_pfJets_ak5_momentum_fP_fX->GetEntry(entry);
 	 b_pfJets_ak5_momentum_fP_fY->GetEntry(entry);
	 b_pfJets_ak5_momentum_fP_fZ->GetEntry(entry);
	 b_pfJets_ak5_momentum_fE->GetEntry(entry);
	 b_pfJets_ak5_nConstituents->GetEntry(entry);	 
	 b_pfJets_ak5_chargedHadronEnergy->GetEntry(entry);	 
	 b_pfJets_ak5_neutralHadronEnergy->GetEntry(entry);
	 b_pfJets_ak5_chargedEmEnergy->GetEntry(entry);	 
	 b_pfJets_ak5_neutralEmEnergy->GetEntry(entry);	 
	 b_pfJets_ak5_chargedMultiplicity->GetEntry(entry);	 
	  
	 b_pfParticles_momentum_fP_fX->GetEntry(entry);
 	 b_pfParticles_momentum_fP_fY->GetEntry(entry);
	 b_pfParticles_momentum_fP_fZ->GetEntry(entry);
	 b_pfParticles_momentum_fE->GetEntry(entry);	
	 
	 b_genParticles_momentum_fP_fX->GetEntry(entry);
 	 b_genParticles_momentum_fP_fY->GetEntry(entry);
	 b_genParticles_momentum_fP_fZ->GetEntry(entry);
	 b_genParticles_momentum_fE->GetEntry(entry);	  
	  
	 b_vertices_->GetEntry(entry); */
// 	 ->GetEntry(entry);
	 
	 BuildObjects();
	 
	// TString trigger = "hlt_trigger";
	// TString hlt = "hlt_trigger";
	 
	 
	 
	 Fill("h_reco_vert_n_vor", vertices_n); 
	 Fill("h_cutflow","all");
	 
	 #ifdef __MC	

	 Fill("h_met_vor", metMET.Pt());

	  	
	 Eventweight *= getPileUpWeight();
	 
	 Fill("h_met_nach", metMET.Pt());	 

	 double truth_ht = 0;
	 for ( int i = 0; i < genParticles_ ; i++) {
	 		if (genParticles_status[i] == 1) {
					truth_ht += GenParticles[i].Et();
					if (genParticles_pdgId[i] == 22) {
							Fill("h_truth_photon_pt", GenParticles[i].Pt());
							}
					}
			}
	 Fill("h_truth_ht", truth_ht);
		
	 
	 #endif	 
	 
	 Fill("h_reco_vert_n_nach", vertices_n);	 
	 Fill("h_cutflow","PileupRew");	 
	 
	 double Ngen_Data = 0;
	 
	 vector<int> loose_photons; /* these "loose photon" correspond to the twiki loose 
	 															different in Knuts analysis-> my loose = knuts tight */
																
	 vector<int> tight_photons; /* these "tight photon" correspond to the twiki tight 
	 															different in Knuts analysis */	
	 vector<int> pixel_photons;	
	 vector<int> cut_photons;
	 vector<int> cut_EB_photons;	 
	 vector<int> cut_r9_photons;	
	 															
	 vector<int> trigger_photons;		
	 														
																															
	 vector<int> loose_jets;    /* these "loose jets" are jets with loose ID */
	 vector<int> cleaned_jets;
	 vector<int> b_jets;
	 vector<int> photon_matched_jets;	
	  	 
	 vector<int> medium_electrons;	 
	 
	 
   string ZGamma = "ZGamma_V02";

   string ZGammaNuNu = "ZGammaNuNu_V02";
	 
	 ///////////////////* Start analysis  *////////////////////////
	 
	 
   for (unsigned int i = 0; i < Photons.size(); i++) {
	 		if (Photons[i].Pt() > 30 && Photons[i].HasPixelSeed() ) {
				pixel_photons.push_back(i);
				}	 
			if (Photons[i].Pt() > 30 && Photons[i].IsLooseIsolated() ) {
				loose_photons.push_back(i);
				Fill("h_loose_photon_eta_vor", Photons[i].Eta());				
				if ( Photons[i].IsTightIsolated() ) {
						tight_photons.push_back(i);	
						}
			}
			if (Photons[i].PassTriggerIsolation() ){
				trigger_photons.push_back(i);
				}
	 }	 


// For ZGamma Cut
// ZGamma > 140 kFALSE, ZGammaNuNu < 140 kFALSE

   if ( ZGamma.compare(BGName) == 0 ) {	
	 		if (tight_photons.size() < 1) return kFALSE;		 
	 		if (Photons[tight_photons[0]].Pt() > 140) return kFALSE; 			
			} 
	 else if ( ZGammaNuNu.compare(BGName) == 0 ) {	
			if (tight_photons.size() < 1) return kFALSE;		 
	 		if (Photons[tight_photons[0]].Pt() < 140) return kFALSE; 			
		  }
		
	 
	 for (unsigned int i = 0; i < Jets.size(); i++) {
	//	cout << "neutral energy fraction: " << Jets[i].neutralHadronEnergy << "  energy :" << Jets[i].JetE <<	endl;
	 	if ( Jets[i].IsLooseIsolated() ) {
				loose_jets.push_back(i);

		}
	 }
	 
	/***** Impact parameter calculation for cut based ID electrons ************/
	
	 
	 for (unsigned int i = 0; i < Electrons.size(); i++) {
	 	if ( Electrons[i].IsMediumIsolated() ) {
				medium_electrons.push_back(i);

		}

	 }
	 
	 		
 #ifdef __MC
 			 
	for( unsigned i = 0; i < pu_; i++){
     if (pu_BX[i] == 0){
				Fill2("h2_vert_met",pu_trueNumInteractions[i],MET.Pt());
				if ( tight_photons.size() == 1 ) Fill2("h2_vert_pt",pu_trueNumInteractions[i],Photons[tight_photons[0]].Pt());							
				}		
     }
		 
  for ( int i = 0; i < GenParticles.size() ; i++) {
	 		if (GenParticles[i].GenStatus == 1 && tight_photons.size() > 0) {
					if (GenParticles[i].GenPDGID == 22 ) {
					   Fill2("h2_truth_photon_DeltaR_relPt_before",GenParticles[i].DeltaR(Photons[tight_photons[0]]),((GenParticles[i].Pt()-Photons[tight_photons[0]].Pt())/GenParticles[i].Pt()));
						 }
					if ((GenParticles[i].GenPDGID == 11 || GenParticles[i].GenPDGID == -11)) {
						 Fill2("h2_truth_electron_DeltaR_relPt_before",GenParticles[i].DeltaR(Photons[tight_photons[0]]),((GenParticles[i].Pt()-Photons[tight_photons[0]].Pt())/GenParticles[i].Pt()));	
						 }
											
					}
			}				
	 
 #endif	
	 
	 
	 Fill("h_met_vor", metMET.Pt());
	 
	 
	 #ifdef __Data	 
	 
	 
		if ( tight_photons.size() == 0 && PassMETTrigger()){
	 		Fill("h_denumerator_bypass_tight_MET_2", MET.Pt());				
	    if ( PassSignalTrigger() ) {
					Fill("h_numerator_bypass_tight_MET_2", MET.Pt());									
					}	 	
	  } 
	 
		if ( tight_photons.size() == 0 && PassGamma30Trigger()){
	 		Fill("h_denumerator_bypass_tight_2", MET.Pt());				
	    if ( PassSignalTrigger() ) {
					Fill("h_numerator_bypass_tight_2", MET.Pt());									
					}	 	
	  } 	
		
		if ( loose_photons.size() == 0 && PassMETTrigger()){
	 		Fill("h_denumerator_bypass_loose_MET_2", MET.Pt());				
	    if ( PassSignalTrigger() ) {
					Fill("h_numerator_bypass_loose_MET_2", MET.Pt());									
					}	 	
	  } 
	 
		if ( loose_photons.size() == 0 && PassGamma30Trigger()){
	 		Fill("h_denumerator_bypass_loose_2", MET.Pt());				
	    if ( PassSignalTrigger() ) {
					Fill("h_numerator_bypass_loose_2", MET.Pt());									
					}	 	
	  }		
		 
	 
	 #endif	 
	 
	 bool cut_n_photon  = (Photons.size() > 0);

	 
	 /* Require trigger selection taking turn-on into account */
	 	 
	 if (cut_n_photon == false) return kFALSE; // at least one photon	 
	 
	 Fill("h_cutflow", "# #gamma>0");
	 
	double DeltaR1 = 0;	
	double DeltaR = 10;
	double DeltaR2 = 0;	
		 
	 #ifdef __Data

/*	 cout << hltMap.size() << endl;
	 for( TriggerMap::const_iterator tm = hltMap.begin();
            tm != hltMap.end(); ++tm ) {
                        //cout << tm->first << endl;
                        } */

/*****************************************************************************************************************************************************
************************************ begin of trigger studies ****************************************************************************************
*****************************************************************************************************************************************************/ 

	if (Photons.size() == 1){
		if ( PassSignalTrigger() ) {
		 Fill("h_signal_pt", Photons[0].Pt());		
		 Fill("h_signal_r9", photons_photons_r9[0]);
		 Fill("h_signal_eVeto", photons_photons_passelectronveto[0]);
		 Fill("h_signal_nPixelSeeds", photons_photons_nPixelSeeds[0]);
		 Fill("h_signal_fidBit", photons_photons_fidBit[0]);
		 Fill("h_signal_e5x5", photons_photons_e5x5[0]);	 
	   Fill("h_signal_HE", photons_photons_hadronicOverEm[0]);
	   Fill("h_signal_sigmaEE", photons_photons_sigmaEtaEta[0]);		 
	   Fill("h_signal_sigmaIEIE", photons_photons_sigmaIetaIeta[0]);		 
	   Fill("h_signal_ecalSumEt04", photons_photons_ecalRecHitSumEtConeDR04[0]);
	   Fill("h_signal_ecalSumEt03", photons_photons_ecalRecHitSumEtConeDR03[0]);
	   Fill("h_signal_ecalSumEt03_cal", (photons_photons_ecalRecHitSumEtConeDR03[0]-(Photons[0].E()*0.012)));		 
	   Fill("h_signal_hcalIsoDepth1", photons_photons_hcalDepth1TowerSumEtConeDR03[0]);
	   Fill("h_signal_hcalIsoDepth2", photons_photons_hcalDepth2TowerSumEtConeDR03[0]);		 
	   Fill("h_signal_hcalIsoDepth12", photons_photons_hcalDepth1TowerSumEtConeDR03[0]+photons_photons_hcalDepth2TowerSumEtConeDR03[0]);		 
	   Fill("h_signal_trkSumHollow", photons_photons_trkSumPtHollowConeDR03[0]);
	   Fill("h_signal_eta", Photons[0].Eta());
		 Fill2("h2_corr_r9_pt_signal", photons_photons_r9[0] , Photons[0].Pt());
	   }
	  if (Photons[0].IsLooseIsolated() ) {
		 Fill("h_pt_iso", Photons[0].Pt());		
     Fill("h_r9_iso", photons_photons_r9[0]);
		 Fill("h_eVeto_iso", photons_photons_passelectronveto[0]);
		 Fill("h_nPixelSeeds_iso", photons_photons_nPixelSeeds[0]);
		 Fill("h_fidBit_iso", photons_photons_fidBit[0]);	
		 Fill("h_e5x5_iso", photons_photons_e5x5[0]);		 	 
     Fill("h_HE_iso", photons_photons_hadronicOverEm[0]);
     Fill("h_sigmaEE_iso", photons_photons_sigmaEtaEta[0]);     
     Fill("h_sigmaIEIE_iso", photons_photons_sigmaIetaIeta[0]);                
     Fill("h_ecalSumEt04_iso", photons_photons_ecalRecHitSumEtConeDR04[0]);
     Fill("h_ecalSumEt03_iso", photons_photons_ecalRecHitSumEtConeDR03[0]);
     Fill("h_ecalSumEt03_iso_cal", (photons_photons_ecalRecHitSumEtConeDR03[0]-(Photons[0].E()*0.012)));        
     Fill("h_hcalIsoDepth1_iso", photons_photons_hcalDepth1TowerSumEtConeDR03[0]);
     Fill("h_hcalIsoDepth2_iso", photons_photons_hcalDepth2TowerSumEtConeDR03[0]);    
     Fill("h_hcalIsoDepth12_iso", photons_photons_hcalDepth1TowerSumEtConeDR03[0]+photons_photons_hcalDepth2TowerSumEtConeDR03[0]);        
	   Fill("h_trkSumHollow_iso", photons_photons_trkSumPtHollowConeDR03[0]);
     Fill("h_eta_iso", Photons[0].Eta());
		 Fill2("h2_corr_r9_pt_iso", photons_photons_r9[0] , Photons[0].Pt());
		 if (fabs(Photons[0].Eta()) < 1.4442 && photons_photons_r9[0] > 0.9 && PassMETTrigger() ){
		 		Fill("h_denumerator", Photons[0].Pt() );
				if ( PassSignalTrigger() ) {
		 	  	Fill("h_numerator", Photons[0].Pt() );					
					}
				}		 
		 }
		}	


 for (unsigned int i = 0; i < Photons.size(); i++) {
	if ( PassSignalTrigger() ) {
		Fill("h_check_signal_r9", photons_photons_r9[i]);
		Fill("h_check_signal_HE", photons_photons_hadTowOverEm[i]);
		Fill("h_check_signal_ecalSumEt04", photons_photons_ecalRecHitSumEtConeDR04[i]);
		Fill("h_check_signal_ecalSumEt03", photons_photons_ecalRecHitSumEtConeDR03[i]);
		Fill("h_check_signal_hcalIsoCone", photons_photons_hcalIsoConeDR04_2012[i]);
		Fill("h_check_signal_hcalDepth03", photons_photons_hcalDepth1TowerSumEtConeDR03[i]);
		Fill("h_check_signal_eta", Photons[i].Eta());
		if (Photons[i].IsLooseIsolated() ) {
				Fill("h_check_signal_r9_iso", photons_photons_r9[i]);
				Fill("h_check_signal_HE_iso", photons_photons_hadTowOverEm[i]);
				Fill("h_check_signal_ecalSumEt04_iso", photons_photons_ecalRecHitSumEtConeDR04[i]);
				Fill("h_check_signal_ecalSumEt03_iso", photons_photons_ecalRecHitSumEtConeDR03[i]);
				Fill("h_check_signal_hcalIsoCone_iso", photons_photons_hcalIsoConeDR04_2012[i]);
				Fill("h_check_signal_hcalDepth03_iso", photons_photons_hcalDepth1TowerSumEtConeDR03[i]);
				Fill("h_check_signal_eta_iso", Photons[i].Eta());
			}
		}
		
	if ( PassMETTrigger() ) {
		Fill("h_check_met_r9", photons_photons_r9[i]);
		Fill("h_check_met_HE", photons_photons_hadTowOverEm[i]);
		Fill("h_check_met_ecalSumEt04", photons_photons_ecalRecHitSumEtConeDR04[i]);
		Fill("h_check_met_ecalSumEt03", photons_photons_ecalRecHitSumEtConeDR03[i]);
		Fill("h_check_met_hcalIsoCone", photons_photons_hcalIsoConeDR04_2012[i]);
		Fill("h_check_met_hcalDepth03", photons_photons_hcalDepth1TowerSumEtConeDR03[i]);
		Fill("h_check_met_eta", Photons[i].Eta());
		if (Photons[i].IsLooseIsolated() ) {
	      Fill("h_check_met_r9_iso", photons_photons_r9[i]);
	      Fill("h_check_met_HE_iso", photons_photons_hadTowOverEm[i]);
	      Fill("h_check_met_ecalSumEt04_iso", photons_photons_ecalRecHitSumEtConeDR04[i]);
	      Fill("h_check_met_ecalSumEt03_iso", photons_photons_ecalRecHitSumEtConeDR03[i]);
	      Fill("h_check_met_hcalIsoCone_iso", photons_photons_hcalIsoConeDR04_2012[i]);
	      Fill("h_check_met_hcalDepth03_iso", photons_photons_hcalDepth1TowerSumEtConeDR03[i]);
	      Fill("h_check_met_eta_iso", Photons[i].Eta());        
				}
		}		
	}
	
	
	for (unsigned int i = 0; i < Photons.size(); i++) {
    if ( PassGamma30Trigger() ) {
     Fill2("h_corr_pt", Photons[i].Pt(), MET.Pt());		
		 Fill2("h_corr_r9", photons_photons_r9[i], MET.Pt());
		 Fill2("h_corr_eVeto", photons_photons_passelectronveto[i], MET.Pt());
		 Fill2("h_corr_nPixelSeeds", photons_photons_nPixelSeeds[i], MET.Pt());
		 Fill2("h_corr_fidBit", photons_photons_fidBit[i], MET.Pt());
		 Fill2("h_corr_e5x5", photons_photons_e5x5[i], MET.Pt());	 
	   Fill2("h_corr_HE", photons_photons_hadronicOverEm[i], MET.Pt());
	   Fill2("h_corr_HTowE", photons_photons_hadTowOverEm[i], MET.Pt());		 
	   Fill2("h_corr_sigmaEE", photons_photons_sigmaEtaEta[i], MET.Pt());		 
	   Fill2("h_corr_sigmaIEIE", photons_photons_sigmaIetaIeta[i], MET.Pt());		 
	   Fill2("h_corr_ecalSumEt04", photons_photons_ecalRecHitSumEtConeDR04[i], MET.Pt());
	   Fill2("h_corr_ecalSumEt03", photons_photons_ecalRecHitSumEtConeDR03[i], MET.Pt());
	   Fill2("h_corr_ecalSumEt03_cal", (photons_photons_ecalRecHitSumEtConeDR03[i]-(Photons[i].E()*0.012)), MET.Pt());		 
	   Fill2("h_corr_hcalIsoDepth1", photons_photons_hcalDepth1TowerSumEtConeDR03[i], MET.Pt());
	   Fill2("h_corr_hcalIsoDepth2", photons_photons_hcalDepth2TowerSumEtConeDR03[i], MET.Pt());		 
	   Fill2("h_corr_hcalIsoDepth12", photons_photons_hcalDepth1TowerSumEtConeDR03[i]+photons_photons_hcalDepth2TowerSumEtConeDR03[i], MET.Pt());		 
	   Fill2("h_corr_trkSumHollow", photons_photons_trkSumPtHollowConeDR03[i], MET.Pt());
	   Fill2("h_corr_eta", Photons[i].Eta(), MET.Pt());	
		}
	
	}	 
		


	if ( loose_photons.size() > 0 ) {
			if ( PassSignalTrigger() && PassIsoGammaTrigger() ) {
					Fill( "h_triggereff_photonptcross_mytrigger_vor", metMET.Pt() );
					if ( metMET.Pt() > 40 ) {
							Fill("h_efficiency_met_my",metMET.Pt());
							}
					}
			if ( PassIsoGammaTrigger() ) {
					Fill( "h_triggereff_photonptcross_crosstrigger_vor", metMET.Pt() );
					if ( metMET.Pt() > 40 ) {
							Fill("h_efficiency_met_cross",metMET.Pt());
							}
					}					
			} 
			

 if ( PassSignalTrigger() && PassIsoGammaTrigger() ) {
			Fill( "h_triggereff_photonptcross_mytrigger_vor2", metMET.Pt() );
					}
			if ( PassIsoGammaTrigger() ) {
					Fill( "h_triggereff_photonptcross_crosstrigger_vor2", metMET.Pt() );
			}					
			
			

	if ( photons_photons_hadTowOverEm[0] < 0.1 && photons_photons_r9[0] > 0.9 && fabs(Photons[0].Eta()) <
	1.4442) {
		if ( PassSignalTrigger() && PassMETTrigger() ) {
			 	Fill( "h_triggereff_metcross_mytrigger", Photons[0].Pt() );
				if ( Photons[0].Pt() > 50 ) {
							Fill("h_efficiency_photon_my",Photons[0].Pt());
							}
				}
				
	  if ( PassMETTrigger() ) {
			 	Fill( "h_triggereff_metcross_crosstrigger", Photons[0].Pt() );
				if ( Photons[0].Pt() > 50 ) {
							Fill("h_efficiency_photon_cross",Photons[0].Pt());
							}				
				}
			} 
			 
			
	if ( loose_photons.size() > 0 && fabs(Photons[loose_photons[0]].Eta() < 1.4442 )) {
		if ( PassSignalTrigger() && PassMETTrigger() ) {
			 	Fill("h_triggereff_metcross_mytrigger2",Photons[loose_photons[0]].Pt() );
				Fill("h_triggereff__mytrigger_instLumi", avgInsRecLumi);
				Fill("h_triggereff__mytrigger_runNumber", runNumber);
				Fill("h_triggereff__mytrigger_lumiBlock", luminosityBlockNumber);
				}
				
	  if ( PassMETTrigger() ) {
			 	Fill("h_triggereff_metcross_crosstrigger2", Photons[loose_photons[0]].Pt() );
				Fill("h_triggereff__crosstrigger_instLumi", avgInsRecLumi);
				Fill("h_triggereff__crosstrigger_runNumber", runNumber);
				Fill("h_triggereff__crosstrigger_lumiBlock", luminosityBlockNumber);				
				}
			}	
			
			
	if ( loose_photons.size() > 0 ) {
		if ( PassSignalTrigger() && PassMETTrigger() ) {
			 	Fill( "h_triggereff_metcross_mytrigger3", metMET.Pt() );
				}
				
	  if ( PassSignalTrigger() ) {
			 	Fill( "h_triggereff_metcross_crosstrigger3", metMET.Pt() );
				}
			}				
	 
	 
	 if ( loose_photons.size() == 1 && fabs(Photons[loose_photons[0]].Eta()) < 1.4442 && PassMETTrigger() ){
	 		Fill("h_denumerator_loose_eta", Photons[loose_photons[0]].Pt());
			if ( Photons[loose_photons[0]].r9 > 0.9 ) {
					Fill("h_denumerator_loose_eta_r9", Photons[loose_photons[0]].Pt());
					}
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_loose_eta", Photons[loose_photons[0]].Pt());
					if ( Photons[loose_photons[0]].r9 > 0.9 ) {
							Fill("h_numerator_loose_eta_r9", Photons[loose_photons[0]].Pt());
							}			
					
					}
	 	
	    }
	 
	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() ){
	 		Fill("h_denumerator_tight_eta", Photons[tight_photons[0]].Pt());
			if ( Photons[tight_photons[0]].r9 > 0.9 ) {
					Fill("h_denumerator_tight_eta_r9", Photons[tight_photons[0]].Pt());
					}
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_tight_eta", Photons[tight_photons[0]].Pt());
					if ( Photons[tight_photons[0]].r9 > 0.9 ) {
							Fill("h_numerator_tight_eta_r9", Photons[tight_photons[0]].Pt());
							}			
					
					}
						 	
	    }	
			
	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() ){
			Fill("h_denumerator_tight_eta_r9_turnon", Photons[tight_photons[0]].r9 );
	 		if ( PassSignalTrigger() ) {
							Fill("h_numerator_tight_eta_r9_turnon", Photons[tight_photons[0]].r9);
							}			
					
			}
	
	 if ( Photons.size() > 0 && fabs(Photons[0].Eta()) < 1.4442 && PassMETTrigger() &&  Photons[0].r9 > 0.9 && Photons[0].hcalDepth1 < 4  && Photons[0].trackSumHollow < 4){
			Fill("h_denumerator_eta_hadronic_turnon", Photons[0].hadronicOverEm );
	 		if ( PassSignalTrigger() ) {
							Fill("h_numerator_eta_hadronic_turnon", Photons[0].hadronicOverEm );
							}			
					
			}	
			
	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() &&  Photons[tight_photons[0]].r9 > 0.9){
			Fill("h_denumerator_tight_eta_hadronic_turnon", Photons[tight_photons[0]].hadronicOverEm );
	 		if ( PassSignalTrigger() ) {
							Fill("h_numerator_tight_eta_hadronic_turnon", Photons[tight_photons[0]].hadronicOverEm );
							}			
					
			}	
			
	 if ( Photons.size() > 0 && fabs(Photons[0].Eta()) < 1.4442 && PassMETTrigger() &&  Photons[0].r9 > 0.9 &&
	 Photons[0].hadronicOverEm < 0.1 && Photons[0].trackSumHollow < 4){
			Fill("h_denumerator_eta_hdepth_turnon", Photons[0].hcalDepth1);
	 		if ( PassSignalTrigger() ) {
							Fill("h_numerator_eta_hdepth_turnon", Photons[0].hcalDepth1 );
							}			
					
			}	
			
	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() &&  Photons[tight_photons[0]].r9 > 0.9 &&
	 Photons[tight_photons[0]].hadronicOverEm < 0.1 && Photons[tight_photons[0]].trackSumHollow < 4){
			Fill("h_denumerator_tight_eta_hdepth_turnon", Photons[tight_photons[0]].hcalDepth1 );
	 		if ( PassSignalTrigger() ) {
							Fill("h_numerator_tight_eta_hdepth_turnon", Photons[tight_photons[0]].hcalDepth1 );
							}			
					
			}		
			
			
	 if ( Photons.size() > 0 && fabs(Photons[0].Eta()) < 1.4442 && PassMETTrigger() &&  Photons[0].r9 > 0.9 &&
	 Photons[0].hadronicOverEm < 0.1 && Photons[0].hcalDepth1 < 4){
			Fill("h_denumerator_eta_tracksum_turnon", Photons[0].trackSumHollow);
	 		if ( PassSignalTrigger() ) {
							Fill("h_numerator_eta_tracksum_turnon", Photons[0].trackSumHollow );
							}			
					
			}	
			
	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() &&  Photons[tight_photons[0]].r9 > 0.9 &&
	 Photons[tight_photons[0]].hadronicOverEm < 0.1 && Photons[tight_photons[0]].hcalDepth1 < 4){
			Fill("h_denumerator_tight_eta_tracksum_turnon", Photons[tight_photons[0]].trackSumHollow );
	 		if ( PassSignalTrigger() ) {
							Fill("h_numerator_tight_eta_tracksum_turnon", Photons[tight_photons[0]].trackSumHollow );
							}			
					
			}			
				
			
 if (loose_photons.size() > 0 ) {
	 if ( fabs(Photons[loose_photons[0]].Eta()) < 1.4442 && PassMETTrigger() ){
	 		Fill("h_denumerator_all_loose_eta", Photons[loose_photons[0]].Pt());
			if ( Photons[loose_photons[0]].r9 > 0.9 ) {
					Fill("h_denumerator_all_loose_eta_r9", Photons[loose_photons[0]].Pt());
					Fill("h_denumerator_all_loose_eta_r9_e5x5",Photons[loose_photons[0]].e5x5);				
					}
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_all_loose_eta", Photons[loose_photons[0]].Pt());
					if ( Photons[loose_photons[0]].r9 > 0.9 ) {
							Fill("h_numerator_all_loose_eta_r9", Photons[loose_photons[0]].Pt());
							Fill("h_numerator_all_loose_eta_r9_e5x5",Photons[loose_photons[0]].e5x5);							
							}			
					
					}
	 	
	    }
		}			
			 

	 if (trigger_photons.size() == 1 && PassMETTrigger() ){
	 		Fill("h_denumerator_trigger", Photons[trigger_photons[0]].Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_trigger", Photons[trigger_photons[0]].Pt());					
					}
	 	
	    }	
			
 if (trigger_photons.size() > 0 ) {			 
	 if ( PassMETTrigger() ){
	 		Fill("h_denumerator_all_trigger", Photons[trigger_photons[0]].Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_all_trigger", Photons[trigger_photons[0]].Pt());					
					}
	 	
	    }
		}		
		
double AngleGM1 = 0;
double AngleGM2 = 0;		
double AngleGJ1 = 0;
double AngleGJ = 10;
/*************************** two ways discussed with Zeynep ****************************/


/* First way - tight */


// For Minimum bias dataset -> get photon pt turn on and pt efficiency

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassHLTPhysicsTrigger() && MET.Pt() > 40&& Photons[tight_photons[0]].r9 < 1 && Photons[tight_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_pt_leg_tight_1", Photons[tight_photons[0]].Pt());
	 		if ( PassGamma30Trigger() ) {
					Fill("h_numerator_final_pt_leg_tight_1", Photons[tight_photons[0]].Pt());
					}
	 	
	    }

// For Single Photon dataset -> get photon ID efficiency with MET cut 40

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassGamma30Trigger() && MET.Pt() > 40 && Photons[tight_photons[0]].r9 < 1&& Photons[tight_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_ID_leg_tight_1", Photons[tight_photons[0]].Pt());
	 	  if ( Photons[tight_photons[0]].Pt() > 40 ) {
			  AngleGJ = 10;
			  for (unsigned int i = 0; i < loose_jets.size(); i++) {
	 					if ( Jets[loose_jets[i]].Pt()>30 && fabs(DeltaPhi(Jets[loose_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ) ) > 0.1) {
							AngleGJ1 = fabs(DeltaPhi(Jets[loose_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ));
							if ( AngleGJ1 < AngleGJ ) {
							 AngleGJ = AngleGJ1;
							 }
						 }
				}
				Fill("h_denumerator_JET_corr_1",AngleGJ);
		     AngleGM1 = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));
			   Fill("h_denumerator_MET_corr_1", AngleGM1);	
			  }		
	 		if ( PassIsoGammaTrigger() ) {
					Fill("h_numerator_final_ID_leg_tight_1", Photons[tight_photons[0]].Pt());
				  if ( Photons[tight_photons[0]].Pt() > 40 ) {
			       Fill("h_numerator_MET_corr_1", AngleGM1);	
						 Fill("h_numerator_JET_corr_1",AngleGJ);	
					   }			
					}
	 	
	    }
			
// For Single Photon dataset -> get photon ID efficiency without MET cut

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassGamma30Trigger()&& Photons[tight_photons[0]].r9 < 1 && Photons[tight_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_ID_leg_tight_wo_1", Photons[tight_photons[0]].Pt());
	 	 if ( Photons[tight_photons[0]].Pt() > 40 ) {		
		 		AngleGJ = 10;
			  for (unsigned int i = 0; i < loose_jets.size(); i++) {
	 					if ( Jets[loose_jets[i]].Pt()>30 && fabs(DeltaPhi(Jets[loose_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ) ) > 0.1) {
							AngleGJ1 = fabs(DeltaPhi(Jets[loose_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ));
							if ( AngleGJ1 < AngleGJ ) {
							 AngleGJ = AngleGJ1;
							 }
						 }
				}
			Fill("h_denumerator_JET_corr_wo_1",AngleGJ);		 	
	 	  AngleGM1 = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));
			Fill("h_denumerator_MET_corr_wo_1", AngleGM1);
			}
			if ( PassIsoGammaTrigger() ) {
					Fill("h_numerator_final_ID_leg_tight_wo_1", Photons[tight_photons[0]].Pt());
				  if ( Photons[tight_photons[0]].Pt() > 40 ) {					
			       Fill("h_numerator_MET_corr_wo_1", AngleGM1);
						Fill("h_numerator_JET_corr_wo_1",AngleGJ);
					    }					
					}
	 	
	    }			
			

// For Single Photon dataset -> get MET turn on and MET efficiency

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassIsoGammaTrigger() && Photons[tight_photons[0]].r9 < 1&& Photons[tight_photons[0]].r9 > 0.9 && Photons[tight_photons[0]].Pt() > 40){
	 		Fill("h_denumerator_final_met_leg_tight_1", MET.Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_met_leg_tight_1", MET.Pt());
					}
	    }
			
			

/* Second way - tight */


// For MET dataset -> get photon pt turn on and pt efficiency times ID efficiency

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() && MET.Pt() > 95 && Photons[tight_photons[0]].r9 < 1&& Photons[tight_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_pt_leg_tight_2", Photons[tight_photons[0]].Pt());
	  	if ( Photons[tight_photons[0]].Pt() > 40 ) {		
			AngleGJ = 10;
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
				DeltaR1 = sqrt((Jets[loose_jets[i]].Eta() - Photons[tight_photons[0]].Eta())*(Jets[loose_jets[i]].Eta() -
				Photons[tight_photons[0]].Eta()) + (Jets[loose_jets[i]].Phi() - Photons[tight_photons[0]].Phi())*(Jets[loose_jets[i]].Phi() - Photons[tight_photons[0]].Phi()));				
				if ( Jets[loose_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 ))){
					AngleGJ1 = fabs(DeltaPhi(Jets[loose_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ));
					if ( AngleGJ1 < AngleGJ ) {
					  AngleGJ = AngleGJ1;
				    }
					DeltaR2 =sqrt((Jets[loose_jets[i]].Eta() - Photons[tight_photons[0]].Eta())*(Jets[loose_jets[i]].Eta() -
				  Photons[tight_photons[0]].Eta()) + (Jets[loose_jets[i]].Phi() - Photons[tight_photons[0]].Phi())*(Jets[loose_jets[i]].Phi() - Photons[tight_photons[0]].Phi())); 
	        if (DeltaR2 < DeltaR){
				 	 DeltaR = DeltaR2;
					 }
				 }
	    }
	   	Fill("h_denumerator_JET_corr_100_2",DeltaR);
			AngleGM2 = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));		
		  if (DeltaR > 0.4) {
				Fill("h_denumerator_DeltaRCut_PtCut_100_2", Photons[tight_photons[0]].Pt());
	      Fill("h_denumerator_MET_corr_100_2", AngleGM2);
				if ( AngleGM2 > 0.4 ) {
					Fill("h_denumerator_DeltaRCut_DeltaPhiCut_PtCut_100_2", Photons[tight_photons[0]].Pt());
					}
				}
		 }			
			
			
			
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_pt_leg_tight_2", Photons[tight_photons[0]].Pt());
					if ( Photons[tight_photons[0]].Pt() > 40 ) {	
						Fill("h_numerator_JET_corr_100_2",DeltaR);							
						if (DeltaR > 0.4) {
			       	Fill("h_numerator_DeltaRCut_PtCut_100_2", Photons[tight_photons[0]].Pt());
			        Fill("h_numerator_MET_corr_100_2", AngleGM2);	
							if ( AngleGM2 > 0.4 ) {
								Fill("h_numerator_DeltaRCut_DeltaPhiCut_PtCut_100_2", Photons[tight_photons[0]].Pt());
								}							
						 	}			
						}	
					
					}
	 	
	    }
			

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() && MET.Pt() > 40 && Photons[tight_photons[0]].Pt() > 40){
	 		Fill("h_denumerator_r9_2", Photons[tight_photons[0]].r9);
		
	 	
  	 if ( PassSignalTrigger() ) {
	 		Fill("h_numerator_r9_2", Photons[tight_photons[0]].r9);
			}
		}


	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() && MET.Pt() > 40 && Photons[tight_photons[0]].r9 > 0.9){
				
			AngleGJ = 10;
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
				DeltaR1 = sqrt((Jets[loose_jets[i]].Eta() - Photons[tight_photons[0]].Eta())*(Jets[loose_jets[i]].Eta() -
				Photons[tight_photons[0]].Eta()) + (Jets[loose_jets[i]].Phi() - Photons[tight_photons[0]].Phi())*(Jets[loose_jets[i]].Phi() - Photons[tight_photons[0]].Phi()));

				if ( Jets[loose_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 ))){
					AngleGJ1 = fabs(DeltaPhi(Jets[loose_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ));
					if ( AngleGJ1 < AngleGJ ) {
					  AngleGJ = AngleGJ1;
				    }
					DeltaR2 =sqrt((Jets[loose_jets[i]].Eta() - Photons[tight_photons[0]].Eta())*(Jets[loose_jets[i]].Eta() -
				  Photons[tight_photons[0]].Eta()) + (Jets[loose_jets[i]].Phi() - Photons[tight_photons[0]].Phi())*(Jets[loose_jets[i]].Phi() - Photons[tight_photons[0]].Phi())); 
	        if (DeltaR2 < DeltaR){
				 	 DeltaR = DeltaR2;
					 }
				 }

	    }
		 AngleGM2 = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));
	   if (DeltaR > 0.4 && AngleGM2 > 0.4) {
		   Fill("h_denumerator_DeltaRCut_2", Photons[tight_photons[0]].Pt());
		   }
				
	   if ( PassSignalTrigger() ) {
	  	 if (DeltaR > 0.4 && AngleGM2 > 0.4) {
			     Fill("h_numerator_DeltaRCut_2", Photons[tight_photons[0]].Pt());
			     }										
			 }
	 					
  }






/*	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() && MET.Pt() > 40 && Photons[tight_photons[0]].r9 > 0.9 && Photons[tight_photons[0]].Pt() > 40){
			DeltaR = 10;		
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
				DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
				if ( Jets[loose_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Jets[loose_jets[i]].Pt()/Photons[tight_photons[0]].Pt()) - 1)  > 0.5 ))){
					AngleGJ1 = fabs(DeltaPhi(Jets[loose_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ));
					DeltaR2 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]); 
	        if (DeltaR2 < DeltaR){
				 	 DeltaR = DeltaR2;
					 }
				 }

	    }
			AngleGM2 = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));		
		  if (DeltaR > 0.4 && AngleGM2 > 0.4) {
					Fill("h_denumerator_DeltaRCut2_DeltaPhiCut_PtCut_2", Photons[tight_photons[0]].Pt());
				  if ( PassSignalTrigger() ) {
						Fill("h_numerator_DeltaRCut2_DeltaPhiCut_PtCut_2", Photons[tight_photons[0]].Pt());
						}							
			}			
	 	
	 }		*/		



	/*	
		------------------------> ///////////////////////////////////	<------------------------
 	 ------------------------> /// >> Ready for some magic? << /// <------------------------
	------------------------> /////////////////////////////////// <------------------------  */
		
			
	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() && MET.Pt() > 40 && Photons[tight_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_pt_leg_tight_40_2", Photons[tight_photons[0]].Pt());
	  	if ( Photons[tight_photons[0]].Pt() > 40 ) {		
			DeltaR = 10;
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
				DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
				if ( Jets[loose_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 ))){
					DeltaR2 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]); 
	        if (DeltaR2 < DeltaR){
				 	 DeltaR = DeltaR2;
					 }
				 }

	    }
			
	   	Fill("h_denumerator_JET_corr_2",DeltaR);
			AngleGM2 = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));		
		  if (DeltaR > 0.4) {
				Fill("h_denumerator_DeltaRCut_PtCut_2", Photons[tight_photons[0]].Pt());
	      Fill("h_denumerator_MET_corr_2", AngleGM2);
				if ( AngleGM2 > 0.4 ) {
					Fill("h_denumerator_DeltaRCut_DeltaPhiCut_PtCut_2", Photons[tight_photons[0]].Pt());
					}
				}
	      Fill("h_denumerator_MET_corr_woDelta_2", AngleGM2);
		 }
				
	 if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_pt_leg_tight_40_2", Photons[tight_photons[0]].Pt());
					if ( Photons[tight_photons[0]].Pt() > 40 ) {	
						Fill("h_numerator_JET_corr_2",DeltaR);	
			      Fill("h_numerator_MET_corr_woDelta_2", AngleGM2);							
						if (DeltaR > 0.4) {
			       	Fill("h_numerator_DeltaRCut_PtCut_2", Photons[tight_photons[0]].Pt());
			        Fill("h_numerator_MET_corr_2", AngleGM2);	
							if ( AngleGM2 > 0.4 ) {
								Fill("h_numerator_DeltaRCut_DeltaPhiCut_PtCut_2", Photons[tight_photons[0]].Pt());
								}							
						 	}			
						}										
					}
	 	
	  }				
		
// same without MET offline cut				
	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() && Photons[tight_photons[0]].r9 < 1&& Photons[tight_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_pt_leg_tight_woMETcut_2", Photons[tight_photons[0]].Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_pt_leg_tight_woMETcut_2", Photons[tight_photons[0]].Pt());
					}
	 	
	    }		
			
// For Single Photon dataset -> get  MET turn on and MET efficiency	

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassIsoGammaTrigger()&& Photons[tight_photons[0]].r9 < 1 && Photons[tight_photons[0]].r9 > 0.9 &&
	 Photons[tight_photons[0]].Pt() > 40){
	 		Fill("h_denumerator_final_met_leg_tight_2", MET.Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_met_leg_tight_2", MET.Pt());
					}
	 	
	    }		

////
/* First way - loose*/

// For Minimum bias dataset -> get photon pt turn on and pt efficiency

	 if ( loose_photons.size() == 1 && fabs(Photons[loose_photons[0]].Eta()) < 1.4442 && PassHLTPhysicsTrigger()&& Photons[loose_photons[0]].r9 < 1 && Photons[loose_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_pt_leg_loose_1", Photons[loose_photons[0]].Pt());
	 		if ( PassGamma30Trigger() ) {
					Fill("h_numerator_final_pt_leg_loose_1", Photons[loose_photons[0]].Pt());
					}
	 	
	    }
// For Single Photon dataset -> get photon ID efficiency with MET cut

	 if ( loose_photons.size() == 1 && fabs(Photons[loose_photons[0]].Eta()) < 1.4442 && MET.Pt() > 100 && PassGamma30Trigger()&& Photons[loose_photons[0]].r9 < 1 && Photons[loose_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_ID_leg_loose_1", Photons[loose_photons[0]].Pt());
	 		if ( PassIsoGammaTrigger() ) {
					Fill("h_numerator_final_ID_leg_loose_1", Photons[loose_photons[0]].Pt());
					}
	 	
	    }
			
			
// For Single Photon dataset -> get photon ID efficiency without MET cut

	 if ( loose_photons.size() == 1 && fabs(Photons[loose_photons[0]].Eta()) < 1.4442 && PassGamma30Trigger()&& Photons[loose_photons[0]].r9 < 1 && Photons[loose_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_ID_leg_loose_wo_1", Photons[loose_photons[0]].Pt());
	 		if ( PassIsoGammaTrigger() ) {
					Fill("h_numerator_final_ID_leg_loose_wo_1", Photons[loose_photons[0]].Pt());
					}
	 	
	    }
			
			
			

// For Single Photon dataset -> get MET turn on and MET efficiency

	 if ( loose_photons.size() == 1 && fabs(Photons[loose_photons[0]].Eta()) < 1.4442 && PassIsoGammaTrigger()&& Photons[loose_photons[0]].r9 < 1 && Photons[loose_photons[0]].r9 > 0.9){
	 		Fill("h_denumerator_final_met_leg_loose_1", MET.Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_met_leg_loose_1", MET.Pt());
					}
	    }
			
			

/* Second way - loose*/


// For MET dataset -> get photon pt turn on and pt efficiency times ID efficiency

	 if ( loose_photons.size() == 1 && fabs(Photons[loose_photons[0]].Eta()) < 1.4442 && PassMETTrigger() &&  MET.Pt() > 100 && Photons[loose_photons[0]].r9 < 1 && Photons[loose_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_pt_leg_loose_2", Photons[loose_photons[0]].Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_pt_leg_loose_2", Photons[loose_photons[0]].Pt());
					}
	 	
	    }
				
// same without MET offline cut				
	 if ( loose_photons.size() == 1 && fabs(Photons[loose_photons[0]].Eta()) < 1.4442 && PassMETTrigger()&& Photons[loose_photons[0]].r9 < 1 && Photons[loose_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_pt_leg_loose_woMETcut_2", Photons[loose_photons[0]].Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_pt_leg_loose_woMETcut_2", Photons[loose_photons[0]].Pt());
					}
	 	
	    }		
			
// For Single Photon dataset -> get  MET turn on and MET efficiency	

	 if ( loose_photons.size() == 1 && fabs(Photons[loose_photons[0]].Eta()) < 1.4442 && PassIsoGammaTrigger()&& Photons[loose_photons[0]].r9 < 1 && Photons[loose_photons[0]].r9 >
	 0.9 ){
	 		Fill("h_denumerator_final_met_leg_loose_2", MET.Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_met_leg_loose_2", MET.Pt());
					}
	 	
	    }			
		
// For Single Photon dataset -> get  MET turn on and MET efficiency	WITHOUT requirements


	 if ( PassIsoGammaTrigger()){
	 		Fill("h_denumerator_final_met_leg_loose_wo", MET.Pt());
			if ( MET.Pt() > 95 ) {
				Fill("h_denumerator_MET_calc",MET.Pt());
				}
				
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_met_leg_loose_wo", MET.Pt());
		    	if ( MET.Pt() > 95 ) {
			    	Fill("h_numerator_MET_calc",MET.Pt());
				    }					
					}
	 	
	    }				


/*****************************************************************************************************************************************************
************************************ end of trigger studies ******************************************************************************************
****************************************************************************************************************************************************/ 

	 if (!PassSignalTrigger() ) return kFALSE;


/******************************* Data triggered by Signal trigger **************************/
	 #endif
	 Fill("h_cutflow", "Trigger");

	 /* At least one photon is needed for this cut definition */
	 
	 bool cut_met			  = (MET.Pt() > 100);
	  
	 if (!cut_met) return kFALSE; // met at least 40 GeV


	 Fill("h_cutflow", "#MET>100");
	 	 
	 if ( loose_photons.size() == 0 ) return kFALSE;
	 
	 Fill("h_cutflow", "# loose #gamma>0");	
	  
	 if ( tight_photons.size() == 0 ) return kFALSE;
	 
	 Fill("h_cutflow", "# tight #gamma>0");		 
	
	////* From here on: at least one tight isolated ID photon with P_t > 50 in Barrel, MET > 40 *//////// 
	
   for (unsigned int i = 0; i < tight_photons.size(); i++) {
		 if (Photons[tight_photons[i]].Pt() > 40) {
		 		cut_photons.push_back(i);
				}
		 }	
	 
	 if (cut_photons.size() == 0) return kFALSE;
	 
	 Fill("h_cutflow", "tight #gamma p_{T}>40");
	 
	 	 
   for (unsigned int i = 0; i < cut_photons.size(); i++) {
		 if (Photons[cut_photons[i]].r9 > 0.9) {
		 		cut_r9_photons.push_back(i);
				}
		 }	 
	 
	 if (cut_r9_photons.size() == 0) return kFALSE;
	 
	 Fill("h_cutflow", "r9 > 0.9");	 
	 
   for (unsigned int i = 0; i < cut_r9_photons.size(); i++) {
		 if (fabs(Photons[cut_r9_photons[i]].Eta()) < 1.4442) {
		 		cut_EB_photons.push_back(i);
				}
		 }
		 
	 if (cut_EB_photons.size() == 0) return kFALSE;	
	 
	 Fill("h_cutflow", "tight #gamma in barrel");	 
	 
 	double AngleGJ_ana = 10;
 	double AngleGJ1_ana = 0;	 	
	
	 for (unsigned int i = 0; i < loose_jets.size(); i++) {
	      if ( Jets[loose_jets[i]].Pt()>20 && fabs(DeltaPhi(Jets[loose_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ) ) > 0.1 ){ // &&
				//(fabs((Photons[tight_photons[j]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[j]].Pt()) > 0.3 ) ) {
	        AngleGJ1_ana = fabs(DeltaPhi(Jets[loose_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ));
	        if ( AngleGJ1_ana < AngleGJ_ana ) {
	         AngleGJ_ana = AngleGJ1_ana;
	         }
	       }
	  }	 
	 Fill("h_DeltaPhi_photon_jet_before", AngleGJ_ana);		
		
//	 if (Jets.size() < 2) return kFALSE;
	 
//	 Fill("h_ cut fl ow", "N_{Jets} > 1");
	 	 
//	 if (loose_jets.size() < 3) return kFALSE;	
	  
	// Fill("h_c ut flow","N_{loose Jets} > 2");
	 
	for (unsigned int i = 0; i < loose_jets.size(); i++) {	 
	  double DRself = sqrt(((Jets[loose_jets[i]].Eta() - Photons[tight_photons[0]].Eta())*(Jets[loose_jets[i]].Eta() -
				Photons[tight_photons[0]].Eta())) + ((Jets[loose_jets[i]].Phi() - Photons[tight_photons[0]].Phi())*(Jets[loose_jets[i]].Phi() - Photons[tight_photons[0]].Phi())));
		double DRtest = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
		Fill("h_DR_self",DRself);
		Fill("h_DR_test",DRtest);
	 
	 }
	 
	////* From here on: at least one loose isolated ID photon with P_t > 50 in Barrel, MET > 40 and at least 2 jet candidates *//////// 	 
	 DeltaR1 = 0;	
	 DeltaR = 10;
	 DeltaR2 = 0;
	 
 // for (unsigned int j = 0; j < tight_photons.size(); j++) {	
  // 	AngleGJ_ana = 10;
 	//  AngleGJ1_ana = 0;
			
		double AngleGM = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));
	  Fill("h_DeltaPhi_photon_MET",	AngleGM);
		
		for (unsigned int i = 0; i < loose_jets.size(); i++) {
				DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
				if ( Jets[loose_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 ))){
					DeltaR2 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]); 
	        if (DeltaR2 < DeltaR){
				 	 DeltaR = DeltaR2;
					 }
				 }

	    }
	  if (DeltaR < 0.4 ) return kFALSE; 
		
		Fill("h_cutflow","cleaned");
		
	
		
	 double HT = 0;  /* Defined as usually -> Must be modified if using corrected HT */		
	 double HT2 = 0;	
	 double HT3 = 0;
	 		
	 for (int i = 0; i < loose_jets.size(); i++) { 
	 	 DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
		 if (	Jets[loose_jets[i]].Pt() > 30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 )) ) {
       HT3 += Jets[loose_jets[i]].Pt(); 
			 cleaned_jets.push_back(i);			 
       }
		 if (	Jets[loose_jets[i]].Pt() > 30 && DeltaR1 < 0.1 && (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) <
				0.5 ) ) {
			 photon_matched_jets.push_back(i);			 
       }			 	
		 }
		
	if ( tight_photons.size() > 1 ) {	 
	 for (int i = 0; i < loose_jets.size(); i++) { 
	 	 DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
		 if (	Jets[loose_jets[i]].Pt() > 30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 )) && (fabs(Jets[loose_jets[i]].Eta() ) < 2.5 ) ) {
       HT2 += Jets[loose_jets[i]].Pt(); 
       }	
		 }	
		Fill("h_HT2",HT2);
		}	
		
	 for (int i = 0; i < cleaned_jets.size(); i++) { 
     HT += Jets[cleaned_jets[i]].Pt(); 
		 }
		 
		Fill("h_HT_raw",HT);		
		
		
		
		if( HT < 100 ) return kFALSE;
		
		
		Fill("h_cutflow","HT>100");	
		
		Fill("h_HT_array_HT_cut",HT);		
	  Fill("h_1tightPhotonPtOverMET_scale_HT_cut",Photons[tight_photons[0]].Pt()/MET.Pt());	
	  Fill("h_METoverSqHT_scale_HT_cut", MET.Pt()/(TMath::Sqrt(HT)));
			 				
	  if ( Photons[tight_photons[0]].Pt() < 80 ) {
			Fill("h_HT_array_pt_cut",HT);
			Fill("h_1tightPhotonPtOverMET_scale_pt_cut",Photons[tight_photons[0]].Pt()/MET.Pt());	 
			Fill("h_METoverSqHT_scale_pt_cut", MET.Pt()/(TMath::Sqrt(HT)));	 
			}
		
					
		
		if (Photons[tight_photons[0]].Pt() < 80) return kFALSE;
		
		Fill("h_cutflow","tight #gamma p_{T}>80");


	 AngleGJ_ana = 10;		 		 
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
				DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[cleaned_jets[i]]);
	      if ( Jets[cleaned_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[cleaned_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 ))){
	        AngleGJ1_ana = fabs(DeltaPhi(Jets[cleaned_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ));
	        if ( AngleGJ1_ana < AngleGJ_ana ) {
	          AngleGJ_ana = AngleGJ1_ana;
	          }
					DeltaR2 = Photons[tight_photons[0]].DeltaR(Jets[cleaned_jets[i]]); 
	        if (DeltaR2 < DeltaR){
				 	  DeltaR = DeltaR2;
					  }
				  }
	     }
	  Fill("h_DeltaPhi_photon_jet", AngleGJ_ana);
		Fill("h_DeltaR_photon_jet", DeltaR);
		
		
		if (cleaned_jets.size() > 1){	
	// if ((fabs((Jets[loose_jets[0]].Pt() - Jets[loose_jets[1]].Pt())/ Jets[loose_jets[0]].Pt()) < 0.5 ) ) {
       double DeltaPhiJJ = fabs(DeltaPhi(Jets[cleaned_jets[1]].Phi(),Jets[cleaned_jets[0]].Phi()));
			 Fill("h_DeltaPhi_JJ",DeltaPhiJJ);
			 TLorentzVector v = Jets[cleaned_jets[0]] + Jets[cleaned_jets[1]];
			 double DeltaPhiJMother = fabs(DeltaPhi(MET.Phi(),v.Phi()));
			 Fill("h_DeltaPhi_JMother",DeltaPhiJMother);
	     if ((fabs((Jets[cleaned_jets[0]].Pt() - Jets[cleaned_jets[1]].Pt())/ Jets[cleaned_jets[0]].Pt()) < 0.5 ) ) {	
			 		TLorentzVector vRel = Jets[cleaned_jets[0]] + Jets[cleaned_jets[1]];
			 		double DeltaPhiJMotherRel = fabs(DeltaPhi(MET.Phi(),vRel.Phi()));
			 		Fill("h_DeltaPhi_JMotherRel",DeltaPhiJMotherRel);
			    		 			 
         }	
			}
			
	if ( tight_photons.size() == 1 ) {
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
			  DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);		
			 	Fill2("h2_Corr_DeltaR_relPt_Photon_Jet", DeltaR1,(Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt());
			 	Fill2("h2_Corr_DeltaR_relPt2_Photon_Jet", DeltaR1,Jets[loose_jets[i]].Pt()/Photons[tight_photons[0]].Pt());				
				}
			}	 	
	 Fill("h_n_photon",photons_photons_);
	 Fill("h_n_photon_2",Photons.size());
	 Fill("h_n_photon_loose",loose_photons.size());	
	 Fill("h_n_photon_tight",tight_photons.size());	
	 Fill("h_n_photon_pixel",pixel_photons.size());
	 Fill("h_n_photon_trigger",trigger_photons.size());
	 Fill("h_n_jets_cleaned",cleaned_jets.size());
	 Fill("h_n_jets_photon_matched",photon_matched_jets.size());	 		 
	 Fill("h_n_jets",Jets.size());	 
	 Fill("h_n_jets_loose",loose_jets.size());	 
	 Fill("h_n_electrons_medium",medium_electrons.size());
	 
	 Fill("h_Phi_MET", fabs(MET.Phi()));	 
	 Fill("h_METoverSqHT", MET.Pt()/(TMath::Sqrt(HT)));
	 Fill("h_METoverSqHT_scale", MET.Pt()/(TMath::Sqrt(HT)));	 
	 if (HT > 100) Fill("h_METoverSqHT_scale_HT", MET.Pt()/(TMath::Sqrt(HT)));	 
	 FillArraySignificance("h_METoverSqHT_array", MET.Pt()/(TMath::Sqrt(HT)));	 
	 Fill("h_HToverMET", HT/MET.Pt());

	 double sum_pt = 0;
	 double sum_p = 0.000000001;
	 double sum_photon_pt = 0;
	 double sum_photon_p = 0.000000001;
	 	 
	 for (int i = 0; i < cleaned_jets.size(); i++) {
		 sum_pt += Jets[cleaned_jets[i]].Pt();
	 	 sum_p += Jets[cleaned_jets[i]].P();	 
	   }	 
 	 
	 for (unsigned int i = 0; i < loose_photons.size(); i++) {
	 		sum_pt += Photons[loose_photons[i]].Pt();
			sum_photon_pt += Photons[loose_photons[i]].Pt();
			sum_p += Photons[loose_photons[i]].P();
			sum_photon_p += Photons[loose_photons[i]].P();
			}
	 Fill("h_sum_pt_photons", sum_photon_pt);
	 Fill("h_sum_pt", sum_pt);
	 double centrality = sum_pt/sum_p;
	 double centrality_photon = sum_photon_pt/sum_photon_p;
	 Fill("h_centrality", centrality);
	 Fill("h_centrality_photon", centrality_photon);	 
	 double sum_signal = sum_photon_pt + MET.Pt();
	 Fill("h_sum_signal",sum_signal);
	 
	 for (unsigned int i = 0; i < tight_photons.size(); i++) {
			Fill("h_photon_eta", Photons[tight_photons[i]].Eta());	 
	 		Fill("h_photon_HE", photons_photons_hadTowOverEm[tight_photons[i]]);
	 		Fill("h_photon_iso", photons_photons_photonIso[tight_photons[i]]);	 
	 		Fill("h_photon_r9", photons_photons_r9[tight_photons[i]]);	 
	 		Fill("h_photon_ecalRecEt", photons_photons_ecalRecHitSumEtConeDR04[tight_photons[i]]);
	    Fill("h_SigmaIetaIeta",Photons[tight_photons[i]].sigmaIetaIeta);
		  Fill2("h2_sigmaIEIE_met", Photons[tight_photons[i]].sigmaIetaIeta, MET.Pt());		
			if ( Photons[tight_photons[i]].sigmaIetaIeta < 0.006){
				Fill("h_met_SigmaIetaIeta_low", MET.Pt());
				}
			if ( Photons[tight_photons[i]].sigmaIetaIeta > 0.006){
				Fill("h_met_SigmaIetaIeta_high", MET.Pt());
				}			
			}	
		if ( Photons[tight_photons[0]].sigmaIetaIeta < 0.006){
				Fill("h_met_SigmaIetaIeta_low_1", MET.Pt());
				}
		if ( Photons[tight_photons[0]].sigmaIetaIeta > 0.006){
				Fill("h_met_SigmaIetaIeta_high_1", MET.Pt());
				}
						  
	 Fill2("h2_sigmaIEIE_met_1", Photons[tight_photons[0]].sigmaIetaIeta, MET.Pt());
	 for (int i = 0; i < cleaned_jets.size(); i++) {	 
	   Fill("h_bTagDisc",Jets[cleaned_jets[i]].bTagDisc);
		 if (Jets[cleaned_jets[i]].bTagDisc < -0.5 ) {
		 		b_jets.push_back(i);
		    }		 
	   Fill("h_n_bJets",b_jets.size());
	   }
		 		 
	 
	 if (cleaned_jets.size() > 1){	
	 	TLorentzVector vJ = Jets[cleaned_jets[0]] + Jets[cleaned_jets[1]];
	  double InvMassJets = vJ.M();
	  Fill("h_InvMassJets",InvMassJets);
		if ((fabs((Jets[cleaned_jets[0]].Pt() - Jets[cleaned_jets[1]].Pt())/ Jets[cleaned_jets[0]].Pt()) < 0.5 ) ) {
	    Fill("h_InvMassJetsRel",InvMassJets);		
			double sum_visible = vJ.Pt() + Photons[tight_photons[0]].Pt();
			Fill("h_sum_visible",sum_visible);
			}	
	 	}

	 
	 double EtaLow = 10;
	 double EtaTest = 10;
	 double EtaLow2 = 10;	
	 int indexi = 0;
	 int indexj = 0; 
	if ( cleaned_jets.size() > 1 ) {
	 for (int i = 0; i < cleaned_jets.size(); i++) {
	 	 EtaTest = fabs(Jets[cleaned_jets[i]].Eta());
		 if (EtaTest < EtaLow){
				EtaLow = EtaTest;
				indexi = i;
				}
	   }
	 for (int j = 0; j < cleaned_jets.size(); j++) {
	   if ( j != indexi ){
		 		EtaTest = fabs(Jets[cleaned_jets[j]].Eta());
				if (EtaTest < EtaLow2){
					EtaLow2 = EtaTest;
					indexj = j;
					}
				}
		 }
	 TLorentzVector vJEta =  Jets[cleaned_jets[indexi]] + Jets[cleaned_jets[indexj]];
	 double InvMassJetsEta = vJEta.M();
	 Fill("h_InvMassJetsEta",InvMassJetsEta);
	 if ((fabs((Jets[loose_jets[indexi]].Pt() - Jets[loose_jets[indexj]].Pt())/ Jets[loose_jets[indexi]].Pt()) < 0.5 ) ) {
	  Fill("h_InvMassJetsEtaRel",InvMassJetsEta);	 	
		}
	}	 
	 
	 //HT cut
	 double TransMassMETGamma =
	 TMath::Sqrt(2*Photons[tight_photons[0]].Pt()*MET.Pt()*(1.- TMath::Cos(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi()))));
	 Fill("h_trans_mass_MET_Gamma",TransMassMETGamma);
	 
	 if (cleaned_jets.size() > 1){	
		if ((fabs((Jets[cleaned_jets[0]].Pt() - Jets[cleaned_jets[1]].Pt())/ Jets[cleaned_jets[0]].Pt()) < 1 ) ) {
	 		TLorentzVector vZ = Jets[cleaned_jets[0]] + Jets[cleaned_jets[1]];
			TLorentzVector vRel = (Photons[tight_photons[0]] + vZ);
			TLorentzVector vSum = vRel + MET; 
			double Etrans = vSum.Et();		
	    Fill("h_Etrans_rel",Etrans);
			double DeltaPhiRel = fabs (DeltaPhi(MET.Phi(),vRel.Phi())); 
			Fill("h_DeltaPhi_rel",DeltaPhiRel);
			vRel = -1*vRel;
		  double TransMassMETRel = TMath::Sqrt(2*vRel.Pt()*MET.Pt()*(1.- TMath::Cos(DeltaPhi(MET.Phi(),vRel.Phi()))));
	 		Fill("h_trans_mass_MET_Rel",TransMassMETRel);		
			if ( fabs(vZ.M() - 91) < 20 )	{
				Fill("h_trans_mass_MET_Rel_Z",TransMassMETRel);
				}			
			}	
	 	}
	 
	 
 if (HT < 250) {
	
	 sum_pt = 0;
	 sum_p = 0.000000001;
	 sum_photon_pt = 0;
	 sum_photon_p = 0.000000001;
	 	 
	 for (int i = 0; i < cleaned_jets.size(); i++) {
		 sum_pt += Jets[cleaned_jets[i]].Pt();
	 	 sum_p += Jets[cleaned_jets[i]].P();	 
	   }	 
 	 
	 for (unsigned int i = 0; i < loose_photons.size(); i++) {
	 		sum_pt += Photons[loose_photons[i]].Pt();
			sum_photon_pt += Photons[loose_photons[i]].Pt();
			sum_p += Photons[loose_photons[i]].P();
			sum_photon_p += Photons[loose_photons[i]].P();
			}
	 Fill("h_sum_pt_photons_low", sum_photon_pt);
	 Fill("h_sum_pt_low", sum_pt);
	 centrality = sum_pt/sum_p;
	 centrality_photon = sum_photon_pt/sum_photon_p;
	 Fill("h_centrality_low", centrality);
	 Fill("h_centrality_photon_low", centrality_photon);	 
	 sum_signal = sum_photon_pt + MET.Pt();
	 Fill("h_sum_signal_low",sum_signal);	
	 Fill("h_tight_1photon_pt_low",Photons[tight_photons[0]].Pt());
	  
	 Fill("h_METoverSqHT_low", MET.Pt()/(TMath::Sqrt(HT)));
	 Fill("h_HToverMET_low", HT/MET.Pt());
	 if (cleaned_jets.size() > 1){	
	 	TLorentzVector vJ = Jets[cleaned_jets[0]] + Jets[cleaned_jets[1]];
	  double InvMassJets = vJ.M();
	  Fill("h_InvMassJets_low",InvMassJets);
		if ((fabs((Jets[cleaned_jets[0]].Pt() - Jets[cleaned_jets[1]].Pt())/ Jets[cleaned_jets[0]].Pt()) < 0.5 ) ) {
	    Fill("h_InvMassJetsRel_low",InvMassJets);			
			}	
	 	}
	 Fill("h_n_cleaned_jets_low",cleaned_jets.size());	
	 Fill("h_trans_mass_MET_Gamma_low",TransMassMETGamma);
	 Fill("h_n_loose_photons_low",loose_photons.size());
	 Fill("h_inverse_met_low", 1./MET.Pt());
	 Fill("h_tight_photon_pt_over_HT_low",Photons[tight_photons[0]].Pt()/HT);
	 if (cleaned_jets.size() > 0) Fill("h_cleaned_jets_pt_low",Jets[cleaned_jets[0]].Pt());
	 
	 if (MET.Pt()/(TMath::Sqrt(HT)) > 14 ){
	 	 Fill("h_trans_mass_MET_Gamma_low_sig",TransMassMETGamma);
	   if (cleaned_jets.size() > 0) Fill("h_cleaned_jets_pt_low_sig",Jets[cleaned_jets[0]].Pt());	 
	   Fill("h_inverse_met_low_sig", 1./MET.Pt());
	   Fill("h_n_loose_photons_low_sig",loose_photons.size());	
		 if ( TransMassMETGamma > 300 ) {		 
		 		Fill("h_selection_low", 1./MET.Pt());
				}
		 }	 	 
	 
	 EtaLow = 10;
	 EtaTest = 10;
	 EtaLow2 = 10;	
	 indexi = 0;
	 indexj = 0; 
	if ( cleaned_jets.size() > 1 ) {
	 for (int i = 0; i < cleaned_jets.size(); i++) {
	 	 EtaTest = fabs(Jets[cleaned_jets[i]].Eta());
		 if (EtaTest < EtaLow){
				EtaLow = EtaTest;
				indexi = i;
				}
	   }
	 for (int j = 0; j < cleaned_jets.size(); j++) {
	   if ( j != indexi ){
		 		EtaTest = fabs(Jets[cleaned_jets[j]].Eta());
				if (EtaTest < EtaLow2){
					EtaLow2 = EtaTest;
					indexj = j;
					}
				}
		 }
	 TLorentzVector vJEta =  Jets[cleaned_jets[indexi]] + Jets[cleaned_jets[indexj]];
	 double InvMassJetsEta = vJEta.M();
	 Fill("h_InvMassJetsEta_low",InvMassJetsEta);
	 if ((fabs((Jets[cleaned_jets[indexi]].Pt() - Jets[cleaned_jets[indexj]].Pt())/ Jets[cleaned_jets[indexi]].Pt()) < 0.5 ) ) {
	  Fill("h_InvMassJetsEtaRel_low",InvMassJetsEta);	 	
		}
	}	 
	
	// N-1 Plots

	
	bool cut_jet_pt = true; // (Jets[cleaned_jets[0]].Pt() > 100);
	bool cut_sum_pt = (sum_pt > 400);
	bool cut_sum_signal = true; //(sum_signal > 450);	
	bool cut_m_t 		= (TransMassMETGamma > 350);
	
/* Meeting 24.02. fuer significance 
	
	bool cut_jet_pt = true; // (Jets[cleaned_jets[0]].Pt() > 100);
	bool cut_sum_pt = (sum_pt > 350);
	bool cut_m_t 		= (TransMassMETGamma > 400);	*/
	
	
	if ( cut_jet_pt && cut_sum_pt && cut_sum_signal) {
		Fill("h_N-1_mt_low", TransMassMETGamma);
		}
	if ( cut_jet_pt && cut_m_t && cut_sum_signal) {
		Fill("h_N-1_sum_pt_low", sum_pt);
		}	
	if ( cut_m_t && cut_sum_pt && cut_sum_signal) {
		if ( cleaned_jets.size() > 0) Fill("h_N-1_jet_pt_low", Jets[cleaned_jets[0]].Pt());
		}
	if ( cut_m_t && cut_sum_pt) {
		Fill("h_N-1_sum_signal_low", sum_signal);
		}		
		
	if ( cut_jet_pt && cut_sum_pt && cut_m_t && cut_sum_signal) {
		Fill("h_inverse_met_selection_low", 1./MET.Pt());
		Fill("h_n_pixel_selection_low",pixel_photons.size());
		Fill("h_n_photons_selection_low",loose_photons.size());
		Fill("h_n_jets_selection_low",cleaned_jets.size());				
		if ( pixel_photons.size() == 0 ) {
			  Fill("h_inverse_met_selection_pixel_low", 1./MET.Pt());
				}
		if ( loose_photons.size() > 1 ) {
			  Fill("h_inverse_met_selection_2gamma_low", 1./MET.Pt());
				}				
		} 
	
	
	
		
 }else{
 
	 sum_pt = 0;
	 sum_p = 0.000000001;
	 sum_photon_pt = 0;
	 sum_photon_p = 0.000000001;
	 	 
	 for (int i = 0; i < cleaned_jets.size(); i++) {
		 sum_pt += Jets[cleaned_jets[i]].Pt();
	 	 sum_p += Jets[cleaned_jets[i]].P();	 
	   }	 
 	 
	 for (unsigned int i = 0; i < loose_photons.size(); i++) {
	 		sum_pt += Photons[loose_photons[i]].Pt();
			sum_photon_pt += Photons[loose_photons[i]].Pt();
			sum_p += Photons[loose_photons[i]].P();
			sum_photon_p += Photons[loose_photons[i]].P();
			}
	 Fill("h_sum_pt_photons_high", sum_photon_pt);
	 Fill("h_sum_pt_high", sum_pt);
	 centrality = sum_pt/sum_p;
	 centrality_photon = sum_photon_pt/sum_photon_p;
	 Fill("h_centrality_high", centrality);
	 Fill("h_centrality_photon_high", centrality_photon);	 
	 sum_signal = sum_photon_pt + MET.Pt();
	 Fill("h_sum_signal_high",sum_signal);	
	 Fill("h_tight_1photon_pt_high",Photons[tight_photons[0]].Pt());
	 
	 Fill("h_METoverSqHT_high", MET.Pt()/(TMath::Sqrt(HT)));
	 Fill("h_HToverMET_high", HT/MET.Pt());
	 if (cleaned_jets.size() > 1){	
	 	TLorentzVector vJ = Jets[cleaned_jets[0]] + Jets[cleaned_jets[1]];
	  double InvMassJets = vJ.M();
	  Fill("h_InvMassJets_high",InvMassJets);
		if ((fabs((Jets[cleaned_jets[0]].Pt() - Jets[cleaned_jets[1]].Pt())/ Jets[cleaned_jets[0]].Pt()) < 0.5 ) ) {
	    Fill("h_InvMassJetsRel_high",InvMassJets);			
			}	
	 	}
	 Fill("h_n_cleaned_jets_high",cleaned_jets.size());	
	 Fill("h_trans_mass_MET_Gamma_high",TransMassMETGamma);
	 Fill("h_n_loose_photons_high",loose_photons.size());
	 Fill("h_inverse_met_high", 1./MET.Pt());
	 Fill("h_tight_photon_pt_over_HT_high",Photons[tight_photons[0]].Pt()/HT);
	 if (cleaned_jets.size() > 0) Fill("h_cleaned_jets_pt_high",Jets[cleaned_jets[0]].Pt());
	 
	 if (MET.Pt()/(TMath::Sqrt(HT)) > 8 ){
	 	 Fill("h_trans_mass_MET_Gamma_high_sig",TransMassMETGamma);
	   if (cleaned_jets.size() > 0)   Fill("h_cleaned_jets_pt_high_sig",Jets[cleaned_jets[0]].Pt());	 
	   Fill("h_inverse_met_high_sig", 1./MET.Pt());
	   Fill("h_n_loose_photons_high_sig",loose_photons.size());
		 if ( TransMassMETGamma > 300 ) {		 
		 		Fill("h_selection_high", 1./MET.Pt());
		    }	
		 }
	 if (TransMassMETGamma > 300 && (Photons[tight_photons[0]].Pt()/HT) > 0.4 ) {
		 	Fill("h_selection_high2", 1./MET.Pt());	 
			}		
	
	 if ( (Photons[tight_photons[0]].Pt()/HT) > 0.4 ) {
	 	 Fill("h_trans_mass_MET_Gamma_high_ratio",TransMassMETGamma);
	 if (cleaned_jets.size() > 0)   Fill("h_cleaned_jets_pt_high_ratio",Jets[cleaned_jets[0]].Pt());	 
	   Fill("h_inverse_met_high_ratio", 1./MET.Pt());
	   Fill("h_n_loose_photons_high_ratio",loose_photons.size());	 
	   }
	 
	 
	 EtaLow = 10;
	 EtaTest = 10;
	 EtaLow2 = 10;	
	 indexi = 0;
	 indexj = 0; 
	if ( cleaned_jets.size() > 1 ) {
	 for (int i = 0; i < cleaned_jets.size(); i++) {
	 	 EtaTest = fabs(Jets[cleaned_jets[i]].Eta());
		 if (EtaTest < EtaLow){
				EtaLow = EtaTest;
				indexi = i;
				}
	   }
	 for (int j = 0; j < cleaned_jets.size(); j++) {
	   if ( j != indexi ){
		 		EtaTest = fabs(Jets[cleaned_jets[j]].Eta());
				if (EtaTest < EtaLow2){
					EtaLow2 = EtaTest;
					indexj = j;
					}
				}
		 }
	 TLorentzVector vJEta =  Jets[cleaned_jets[indexi]] + Jets[cleaned_jets[indexj]];
	 double InvMassJetsEta = vJEta.M();
	 Fill("h_InvMassJetsEta_high",InvMassJetsEta);
	 if ((fabs((Jets[cleaned_jets[indexi]].Pt() - Jets[cleaned_jets[indexj]].Pt())/ Jets[cleaned_jets[indexi]].Pt()) < 0.5 ) ) {
	  Fill("h_InvMassJetsEtaRel_high",InvMassJetsEta);	 	
		}
	}
	
	// N-1 Plots
/*	Meeting 24.02. fuer significance	
	bool cut_n_jet 			 = true; //(cleaned_jets.size() < 3);
	bool cut_sum_pt			 = (sum_pt > 600);
	bool cut_m_t 				 = (TransMassMETGamma > 300);
	// bool cut_HT_over_MET = (HT/MET.Pt() < 2);
	bool cut_MET_sig 		 = (MET.Pt()/(TMath::Sqrt(HT)) > 12); */
	
	bool cut_n_jet 			 = true; //(cleaned_jets.size() < 3);
	bool cut_sum_signal		= true; //sum_signal > 400;
	bool cut_sum_pt			 = true; //(sum_pt > 600);
	bool cut_m_t 				 = (TransMassMETGamma > 350);
	bool cut_ptOverHt		= (sum_photon_pt/HT > 0.5);
	// bool cut_HT_over_MET = (HT/MET.Pt() < 2);
	bool cut_MET_sig 		 = true; //(MET.Pt()/(TMath::Sqrt(HT)) > 12);	
	
	
	if ( loose_photons.size() > 1 && pixel_photons.size() == 0){
			Fill("h_number_selection_inverse_met",1./MET.Pt());
			}
	
	if ( cut_n_jet && cut_sum_pt && cut_m_t && cut_sum_signal && cut_ptOverHt) {
		Fill("h_N-1_METsig_high", MET.Pt()/(TMath::Sqrt(HT)));
		}
	if ( cut_n_jet && cut_sum_pt && cut_MET_sig && cut_sum_signal && cut_ptOverHt) {
		Fill("h_N-1_mt_high", TransMassMETGamma);
		}	
	if ( cut_n_jet && cut_MET_sig && cut_m_t && cut_sum_signal && cut_ptOverHt) {
		Fill("h_N-1_sum_pt_high", sum_pt);
		}
	if ( cut_sum_pt && cut_MET_sig && cut_m_t && cut_sum_signal && cut_ptOverHt) {
		Fill("h_N-1_n_jets_high", cleaned_jets.size());
		}	
	if ( cut_sum_pt && cut_MET_sig && cut_m_t && cut_ptOverHt) {
		Fill("h_N-1_sum_signal_high", sum_signal);
		}
	if ( cut_sum_pt && cut_MET_sig && cut_m_t) {
		Fill("h_N-1_sum_ptOverHt_high", sum_photon_pt/HT );
		}						
		
	if ( cut_n_jet && cut_sum_pt && cut_m_t && cut_MET_sig && cut_sum_signal && cut_ptOverHt) {
		Fill("h_inverse_met_selection_high", 1./MET.Pt());
		Fill("h_n_pixel_selection_high",pixel_photons.size());
		Fill("h_n_photons_selection_high",loose_photons.size());		
		if ( pixel_photons.size() == 0 ) {
			  Fill("h_inverse_met_selection_pixel_high", 1./MET.Pt());
				}
		if ( cleaned_jets.size() < 5 ) {
			  Fill("h_inverse_met_selection_jets_high", 1./MET.Pt());
				}	
		if ( loose_photons.size() > 1 ) {
			  Fill("h_inverse_met_selection_2gamma_high", 1./MET.Pt());
				}					
		} 
	
 }	
 
  	
 if ( (MET.Pt()/(TMath::Sqrt(HT))) > 18 ) {	
	Fill("h_inverse_MET_sig",1./MET.Pt());
	Fill("h_HT_sig",HT); 
 	}
	
 if ( (MET.Pt()/(TMath::Sqrt(HT))) < 10 && ( Photons[tight_photons[0]].Pt()/MET.Pt() > 1.5 ) ) {	
	Fill("h_inverse_MET_GJets",1./MET.Pt());
	Fill("h_HT_GJets",HT); 
 	}	
	
	////
/* Analyse the objects that satisfy the IDs */

   for (unsigned int i = 0; i < loose_photons.size(); i++) {
	 		Fill("h_loose_photons_pt", Photons[loose_photons[i]].Pt() );
	 		Fill("h_loose_photon_eta", Photons[loose_photons[i]].Eta() );	
	 		Fill("h_loose_photon_e5x5", Photons[loose_photons[i]].e5x5 );					
			
		 }
	 Fill("h_loose_1photons_pt", Photons[loose_photons[0]].Pt() );
	 if( tight_photons.size() > 0){
	 	Fill("h_tight_1photons_pt", Photons[tight_photons[0]].Pt() );	
		}	
		
		
		
 #ifdef __Data
 
 // For e->gamma fake rate estimated from data
 
 Fill("h_HT_array_datadriven",HT); 
 Fill("h_met_datadriven",MET.Pt());
 Fill("h_inverse_met_datadriven",1./MET.Pt()); 
 Fill("h_tight_photon_pt_datadriven",Photons[tight_photons[0]].Pt());   
 
 #endif	 		
				
 #ifdef __MC	
 
 // FakeRate durch Elektronen ->  Vergleiche GammaPixel-Verteilung * FakeRate pro BG mit pdgID == +-11 die als Gamma rek. wurden
 // Die BG, wo Anteil von pdgID = +-11 groß gg pdgID = 22 ist können durch FakeRate abgeschätzt werden
 
 bool e_fake = false;
	 for ( int i = 0; i < GenParticles.size() ; i++) {
	 		if (GenParticles[i].GenStatus == 1) {
					if (GenParticles[i].GenPDGID == 22 ) {
					Fill2("h2_truth_photon_DeltaR_relPt",GenParticles[i].DeltaR(Photons[tight_photons[0]]),((GenParticles[i].Pt()-Photons[tight_photons[0]].Pt())/GenParticles[i].Pt()));
							if ( GenParticles[i].DeltaR(Photons[tight_photons[0]]) < 0.1) {
							  Fill("h_truth_photons_pt_sel", GenParticles[i].Pt());
							  }
							}
					if ((GenParticles[i].GenPDGID == 11 || GenParticles[i].GenPDGID == -11)) {
							Fill2("h2_truth_electron_DeltaR_relPt",GenParticles[i].DeltaR(Photons[tight_photons[0]]),((GenParticles[i].Pt()-Photons[tight_photons[0]].Pt())/GenParticles[i].Pt()));
							if(GenParticles[i].DeltaR(Photons[tight_photons[0]]) < 0.1 ) {
							  Fill("h_truth_electrons_pt_sel", GenParticles[i].Pt());
								Fill("h_truth_fake_met_sel",MET.Pt());
							  Fill("h_truth_fake_inverse_met_sel",1./MET.Pt());
								Fill("h_truth_fake_tight_photon_pt_sel",Photons[tight_photons[0]].Pt());
								e_fake = true;
								}		
							}
											
					}
			} 
			
	if ( !e_fake ) {	
		Fill("h_met_datadriven",MET.Pt());
		Fill("h_HT_array_datadriven",HT);		
		Fill("h_inverse_met_datadriven",1./MET.Pt());	
		Fill("h_tight_photon_pt_datadriven",Photons[tight_photons[0]].Pt());												
		}	
	 
 #endif	
 
	 Fill2("h2_n_photon_pixel_met",pixel_photons.size(),MET.Pt());
	 Fill2("h2_n_jets_met",cleaned_jets.size(),MET.Pt()); 
	 
   for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
	 	
	 		Fill("h_cleaned_jets_pt", Jets[cleaned_jets[i]].Pt() );
			Fill("h_cleaned_jets_chargedHE", Jets[cleaned_jets[i]].chargedHadronEnergy );
			double frac = ( Jets[cleaned_jets[i]].chargedHadronEnergy / Jets[cleaned_jets[i]].JetE );
			Fill("h_cleaned_jets_chargedfrac", frac );
			Fill("h_cleaned_jets_chargedM", Jets[cleaned_jets[i]].chargedMultiplicity );

		}
	 for (int i = 0; i < photon_matched_jets.size(); i++) {	 	 
	   Fill("h_matched_jet_chargedHadronEnergy",Jets[photon_matched_jets[i]].chargedHadronEnergy );
	   Fill("h_matched_jet_neutralHadronEnergy",Jets[photon_matched_jets[i]].neutralHadronEnergy );		 
	   Fill("h_matched_jet_photonEnergy",Jets[photon_matched_jets[i]].photonEnergy );		 
	   Fill("h_matched_jet_nConstituents",Jets[photon_matched_jets[i]].nConstituents);
		 Fill("h_matched_jet_chargedHadronMultiplicity",Jets[photon_matched_jets[i]].chargedHadronMultiplicity);
		 Fill("h_matched_jet_neutralHadronMultiplicity",Jets[photon_matched_jets[i]].neutralHadronMultiplicity);		 
		 Fill("h_matched_jet_chargedMultiplicity",Jets[photon_matched_jets[i]].chargedMultiplicity);
		 Fill("h_matched_jet_neutralMultiplicity",Jets[photon_matched_jets[i]].neutralMultiplicity);
		 Fill("h_matched_jet_photonMultiplicity",Jets[photon_matched_jets[i]].photonMultiplicity);		 		 	 
	   }
	 
	/////////Fill met for all events
	 Fill("h_met",MET.Pt());
	 if (cleaned_jets.size() < 3 ){
	 		Fill("h_met_nJetmax2",MET.Pt());
			}
	 if (cleaned_jets.size() > 2 ){
	 		Fill("h_met_nJetmin3",MET.Pt());
			}	
	 if (pixel_photons.size() < 1 ){
	 		Fill("h_met_npixel0",MET.Pt());
			}
	 if (pixel_photons.size() > 0 ){
	 		Fill("h_met_npixel1",MET.Pt());
			}				
					
	 FillArray("h_met_array",MET.Pt());

	 double AngleGMall = fabs( DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi()) );
	 double AngleGMtest = fabs(Photons[tight_photons[0]].DeltaPhi(MET));
	 Fill("h_AngleGM_all",AngleGMall);
	 Fill("h_AngleGM_test",AngleGMtest);
	 	 
	 for (int i = 0; i < cleaned_jets.size(); i++) { 
			 double AngleMJ = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[i]].Phi() ));
       Fill("h_AngleMJ", AngleMJ);
			 Fill("h_Eta_Jet", Jets[loose_jets[i]].Eta()); 
			 Fill2("h_corrMETJet",MET.Phi() ,Jets[loose_jets[i]].Phi() );
		//	 cout << MET.Phi() << "............." << Jets[loose_jets[i]].Phi() << endl;
		   }
			 
	 if ( cleaned_jets.size() > 0){			 
			 double AngleMJ1 = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[0]].Phi() ));
       Fill("h_AngleMJ1", AngleMJ1);
			 }
	 if ( cleaned_jets.size() > 1){			 
			 double AngleMJ2 = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[1]].Phi() ));
       Fill("h_AngleMJ2", AngleMJ2);
			 }			 
	 if ( cleaned_jets.size() > 2){			 
			 double AngleMJ3 = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[2]].Phi() ));
       Fill("h_AngleMJ3", AngleMJ3);
			 }
			 			 
		 
	 if ( cleaned_jets.size() > 0) Fill2("h_corrMET1Jet",MET.Phi() ,Jets[cleaned_jets[0]].Phi() );
	 		
	 Fill("h_HT",HT);
	 Fill("h_HT_array",HT);	 
	 Fill("h_reco_vert_n", vertices_n); 
	 Fill("h_inverse_MET",1./MET.Pt());
	 FillArrayInverse("h_inverse_MET_array",1./MET.Pt());	 
	 Fill("h_METoverHT",MET.Pt()/HT);
	 Fill("h_1tightPhotonPtOverHT", Photons[tight_photons[0]].Pt()/HT);
	 Fill("h_1tightPhotonPtOverMET", Photons[tight_photons[0]].Pt()/MET.Pt());
	 Fill("h_1tightPhotonPtOverMET_scale",Photons[tight_photons[0]].Pt()/MET.Pt());
	 Fill("h_photon_seedTime", Photons[tight_photons[0]].photon_seedtime);	 
	 if (HT > 100 ) {
		 Fill("h_met_cut",MET.Pt());	 
		 Fill("h_loose_1photons_pt_cut", Photons[loose_photons[0]].Pt() );	 
		 Fill("h_n_photon_loose_cut",loose_photons.size());	
		 Fill("h_inverse_MET_cut",1./MET.Pt()); 

	 }

	 
 return kTRUE;
} // End Process

void MySelector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.
  
   //TCanvas *c2 = new TCanvas("c2", "c2",3,3,600,600);
   //h->Draw("h");
   //c2->Update();
}

void MySelector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   
 //  h_corrMET1Jet = dynamic_cast<TH2F *>(fOutput->FindObject("h_corrMET1Jet"));
   std::cout << "End of terminate()" <<std::endl;
}
