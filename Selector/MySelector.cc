
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


		// No fill cut flow histo in command -> strange bug

	 CreateHisto("h_cutflow", "cutflow", 11, -0.5, 10.5);
   Fill("h_cutflow","all", 0);
   Fill("h_cutflow","PileupRew", 0);	 
	 Fill("h_cutflow","# #gamma>0", 0);
	 Fill("h_cutflow","#MET>40", 0);	 
	 Fill("h_cutflow","# loose #gamma>0", 0);	  
	 Fill("h_cutflow","loose #gamma p_{T}>50", 0);
	 Fill("h_cutflow", "r9 > 0.9", 0);
	 Fill("h_cutflow","loose #gamma in barrel", 0);	
	 Fill("h_cutflow", "N_{Jets} > 1", 0);
	 Fill("h_cutflow", "N_{loose Jets} > 2", 0);	 	   
	 Fill("h_cutflow","Ht>150", 0);
	 	
		
		
		CreateHisto("h_numerator_final_pt_leg_tight_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_tight_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_ID_leg_tight_1", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_ID_leg_tight_1", "photon pt [GeV]", 80, 0, 400); 		
		CreateHisto("h_numerator_final_met_leg_tight_1", "MET [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_tight_1", "MET [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_pt_leg_tight_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_tight_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_pt_leg_tight_woMETcut_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_tight_woMETcut_2", "photon pt [GeV]", 80, 0, 400); 
		CreateHisto("h_numerator_final_met_leg_tight_2", "MET [GeV]", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_tight_2", "MET [GeV]", 80, 0, 400); 		

	  
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
		
										
	 CreateHisto("h_truth_ht", "ht on GEN level for status 1 ", 200, 0, 1000);
	 CreateHisto("h_truth_photon_pt", "pt of photons (22) on GEN level for status 1 ", 32, 0, 400);	 
	 CreateHisto("h_trueNum", "true num interactions ", 60, 0, 60);	 
	 CreateHisto("h_trueNum2", "true num interactions ", 60, 0, 60);	
	 	 
	 CreateHisto("h_photon_HE","H Tower over E", 100, 0, 1);
	 CreateHisto("h_photon_iso"," photon iso", 200, 0, 100);	 
	 CreateHisto("h_photon_r9", "photon r9", 100, 0, 2);
	 CreateHisto("h_photon_ecalRecEt"," photons_photons_ecalRecHitSumEtConeDR04", 200, 0, 100);
	 
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
	 	 
	 CreateHisto("h_met_vor", "MET", 100, 0, 500);
	 CreateHisto("h_met_nach", "MET", 100, 0, 500);
	 CreateHisto("h_met", "MET", 100, 0, 500);
	 CreateHisto("h_met_cut", "MET", 100, 0, 500);	 
	 CreateHisto("h_inverse_MET", "1/MET", 60, 0, 0.025);
	 CreateHisto("h_inverse_MET_cut", "1/MET", 60, 0, 0.025);	 
	 	 
	 CreateHisto("h_n_photon", "# of photons", 10, -0.5, 9.5);	 
	 CreateHisto("h_n_photon_loose", " # of loose photons",10, -0.5, 9.5);
	 CreateHisto("h_n_photon_tight", " # of tight photons",10, -0.5, 9.5);	 
	 CreateHisto("h_n_photon_trigger", " # of trigger photons",10, -0.5, 9.5);
	 	 
	 CreateHisto("h_n_photon_loose_cut", " # of photons",10, -0.5, 9.5);	 
	 
   CreateHisto("h_n_photon_2", " # of loose photons",10, -0.5, 9.5);
	 CreateHisto("h_HT","HT of all jets [GeV]",300,0.,3000);	 
	 CreateHisto("h_HT_metcut","HT of all loose jets with MET > 50 GeV [GeV]",60,0.,1500);
	 	 
	 CreateHisto("h_reco_vert_n_vor", "# of vertices", 40, -0.5, 39.5); 
	 CreateHisto("h_reco_vert_n_nach", "# of vertices", 40, -0.5, 39.5);	 	 
	 CreateHisto("h_reco_vert_n", "# of vertices", 40, -0.5, 39.5);
	 
	 CreateHisto("h_n_jets", "# of jets", 10, -0.5, 9.5);
	 CreateHisto("h_n_jets_loose", "# of loose jets", 10, -0.5, 9.5);	 
	 CreateHisto("h_loose_jets_pt", "Pt of loose jets", 120, 0, 1200);	 
	 CreateHisto("h_loose_photons_pt", "Pt of loose photons", 32, 0, 400);	
	 CreateHisto("h_loose_photon_e5x5", "e5x5 of loose photons", 32, 0, 400);	 
	 CreateHisto("h_photon_eta", "Eta of photons", 40, -4, 4);	 
	 CreateHisto("h_loose_photon_eta_vor", "Eta of loose photons", 40, -4, 4);	 
	 CreateHisto("h_loose_photon_eta", "Eta of loose photons", 40, -4, 4);
	 	 
	 CreateHisto("h_loose_1photons_pt", "Pt of loose photons", 32, 0, 400);
	 CreateHisto("h_loose_1photons_pt_cut", "Pt of loose photons", 32, 0, 400);	 	  
	 CreateHisto("h_loose_jets_chargedHE", "charged hadron energy in loose jets", 32, 0, 400);	 
	 CreateHisto("h_loose_jets_chargedfrac", "charged hadron energy fraction in loose jets", 20, 0, 1);	 
	 CreateHisto("h_loose_jets_chargedM", "charged Multiplicity in loose jets", 20, -0.5, 19.5);	  
     
	 CreateHisto("h_AngleMJ", "Angle between Jets and MET", 32, 0, 3.2);
	 CreateHisto("h_Eta_Jet", "Eta of Jets", 40, -4, 4); 
	 
	 CreateHisto2D("h_corrMETJet", " correlation of Phi of MET and Jets", 32, -3.2, 3.2, 32, -3.2, 3.2);
	 CreateHisto2D("h_corrMET1Jet", " correlation of Phi of MET and first Jet", 32, -3.2, 3.2, 32, -3.2, 3.2);
	 CreateHisto2D("h2_corr_r9_pt_signal", "correlation of r9 and photon pt", 130, 0, 1.3, 150, 0, 300);	 
	 CreateHisto2D("h2_corr_r9_pt_iso", "correlation of r9 and photon pt", 130, 0, 1.3, 150, 0, 300);
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
			jet.SetChargedEmEnergy(pfJets_ak5_chargedEmEnergy[i]);
			jet.SetNeutralEmEnergy(pfJets_ak5_neutralEmEnergy[i]);
			jet.SetNConstituents(pfJets_ak5_nConstituents[i]);
			jet.SetChargedMultiplicity(pfJets_ak5_chargedMultiplicity[i]);
			
			Jets.push_back(jet);
			}
	 sort(Jets.begin(), Jets.end(), LorentzVectorSortPt);
			
	 PfParticles.clear();
	 for (int i = 0; i < pfParticles_; ++i) {
      MyPfParticle pfparticle(pfParticles_momentum_fP_fX[i], pfParticles_momentum_fP_fY[i],pfParticles_momentum_fP_fZ[i],pfParticles_momentum_fE[i]);
			double pfParticle_pt = pfparticle.Pt();
	 	  pfparticle.SetPfPt(pfParticle_pt);
			
			PfParticles.push_back(pfparticle);
			}
	
	 GenParticles.clear();
	 for (int i = 0; i < pfParticles_; ++i) {
      MyGenParticles genparticles(genParticles_momentum_fP_fX[i], genParticles_momentum_fP_fY[i],genParticles_momentum_fP_fZ[i],genParticles_momentum_fE[i]);
			double genparticles_pt = genparticles.Pt();
	 	  genparticles.SetPfPt(genparticles_pt);
			
			GenParticles.push_back(genparticles);
			}	
	
			
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

	 Eventweight *= getPileUpWeight();
	 

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
	
	 vector<int> cut_photons;
	 vector<int> cut_EB_photons;	 
	 vector<int> cut_r9_photons;	
	 															
	 vector<int> trigger_photons;		
	 														
																															
	 vector<int> loose_jets;    /* these "loose jets" are jets with loose ID */
	 
	 
	 
	 
 
	 ///////////////////* Start analysis  *////////////////////////
	 
	 
   for (unsigned int i = 0; i < Photons.size(); i++) {
			Fill("h_photon_eta", Photons[i].Eta());	 
	 		Fill("h_photon_HE", photons_photons_hadTowOverEm[i]);
	 		Fill("h_photon_iso", photons_photons_photonIso[i]);	 
	 		Fill("h_photon_r9", photons_photons_r9[i]);	 
	 		Fill("h_photon_ecalRecEt", photons_photons_ecalRecHitSumEtConeDR04[i]);	
			if ( Photons[i].IsLooseIsolated() ) {
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

	 for (unsigned int i = 0; i < Jets.size(); i++) {
	//	cout << "neutral energy fraction: " << Jets[i].neutralHadronEnergy << "  energy :" << Jets[i].JetE <<	endl;
	 	if ( Jets[i].IsLooseIsolated() ) {
				loose_jets.push_back(i);

		}
	 }	 
	 
	 Fill("h_met_vor", metMET.Pt());
	 
	 bool cut_n_photon  = (Photons.size() > 0);

	 
	 /* Require trigger selection taking turn-on into account */
	 	 
	 if (cut_n_photon == false) return kFALSE; // at least one photon	 
	 
	 Fill("h_cutflow", "# #gamma>0");
		 
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
		
		
/*************************** two ways discussed with Zeynep ****************************/


/* First way */


// For Minimum bias dataset -> get photon pt turn on and pt efficiency

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassHLTPhysicsTrigger() && MET.Pt() > 40 && Photons[tight_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_pt_leg_tight_1", Photons[tight_photons[0]].Pt());
	 		if ( PassGamma30Trigger() ) {
					Fill("h_numerator_final_pt_leg_tight_1", Photons[tight_photons[0]].Pt());
					}
	 	
	    }

// For Single Photon dataset -> get photon ID efficiency

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassGamma30Trigger() && MET.Pt() > 40 && Photons[tight_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_ID_leg_tight_1", Photons[tight_photons[0]].Pt());
	 		if ( PassIsoGammaTrigger() ) {
					Fill("h_numerator_final_ID_leg_tight_1", Photons[tight_photons[0]].Pt());
					}
	 	
	    }

// For Single Photon dataset -> get MET turn on and MET efficiency

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassIsoGammaTrigger() && Photons[tight_photons[0]].r9 > 0.9 && Photons[tight_photons[0]].Pt() > 40){
	 		Fill("h_denumerator_final_met_leg_tight_1", MET.Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_met_leg_tight_1", MET.Pt());
					}
	    }
			
			

/* Second way */


// For MET dataset -> get photon pt turn on and pt efficiency times ID efficiency

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() && MET.Pt() > 40 &&  MET.Pt() > 100 && Photons[tight_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_pt_leg_tight_2", Photons[tight_photons[0]].Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_pt_leg_tight_2", Photons[tight_photons[0]].Pt());
					}
	 	
	    }
				
// same without MET offline cut				
	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() && Photons[tight_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_pt_leg_tight_woMETcut_2", Photons[tight_photons[0]].Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_pt_leg_tight_woMETcut_2", Photons[tight_photons[0]].Pt());
					}
	 	
	    }		
			
// For Single Photon dataset -> get  MET turn on and MET efficiency	

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassIsoGammaTrigger() && Photons[tight_photons[0]].r9 > 0.9 &&
	 Photons[tight_photons[0]].Pt() > 40){
	 		Fill("h_denumerator_final_met_leg_tight_2", MET.Pt());
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_met_leg_tight_2", MET.Pt());
					}
	 	
	    }		
		
		
			


/*****************************************************************************************************************************************************
************************************ end of trigger studies ******************************************************************************************
****************************************************************************************************************************************************/ 

	 #endif

  	 Fill("h_met_nach", metMET.Pt());

	 /* At least one photon is needed for this cut definition */
	 
	 bool cut_met			  = (MET.Pt() > 40);
	  
	 if (!cut_met) return kFALSE; // met at least 40 GeV


	 Fill("h_cutflow", "#MET>40");
	 	 
	 if ( loose_photons.size() == 0 ) return kFALSE;
	 
	 Fill("h_cutflow", "# loose #gamma>0");	 
	 
	
	////* From here on: at least one loose isolated ID photon with P_t > 50 in Barrel, MET > 40 *//////// 
	
   for (unsigned int i = 0; i < loose_photons.size(); i++) {
		 if (Photons[loose_photons[i]].Pt() > 50) {
		 		cut_photons.push_back(i);
				}
		 }	
	 
	 if (cut_photons.size() == 0) return kFALSE;
	 
	 Fill("h_cutflow", "loose #gamma p_{T}>50");
	 
	 	 
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
	 
	 Fill("h_cutflow", "loose #gamma in barrel");	 	
	 
	 if (Jets.size() < 2) return kFALSE;
	 
	 Fill("h_cutflow", "N_{Jets} > 1");	 
	 
	 if (loose_jets.size() < 3) return kFALSE;	
	  
	 Fill("h_cutflow","N_{loose Jets} > 2");
	  
	 
	////* From here on: at least one loose isolated ID photon with P_t > 50 in Barrel, MET > 40 and at least 2 jet candidates *//////// 	 
		 	
	
	 Fill("h_n_photon",photons_photons_);
	 Fill("h_n_photon_2",Photons.size());
	 Fill("h_n_photon_loose",loose_photons.size());	
	 Fill("h_n_photon_tight",tight_photons.size());	
	 Fill("h_n_photon_trigger",trigger_photons.size());
	 		 
	 Fill("h_n_jets",Jets.size());	 
	 Fill("h_n_jets_loose",loose_jets.size());	 
	 
	
/* Analyse the objects that satisfy the IDs */

   for (unsigned int i = 0; i < loose_photons.size(); i++) {
	 		Fill("h_loose_photons_pt", Photons[loose_photons[i]].Pt() );
	 		Fill("h_loose_photon_eta", Photons[loose_photons[i]].Eta() );	
	 		Fill("h_loose_photon_e5x5", Photons[loose_photons[i]].e5x5 );					
			
		 }
	 Fill("h_loose_1photons_pt", Photons[loose_photons[0]].Pt() );
	
	
   for (unsigned int i = 0; i < loose_jets.size(); i++) {
	 	if ( Jets[loose_jets[i]].Pt()>30 ) {
	 	
	 		Fill("h_loose_jets_pt", Jets[loose_jets[i]].Pt() );
			Fill("h_loose_jets_chargedHE", Jets[loose_jets[i]].chargedHadronEnergy );
			double frac = ( Jets[loose_jets[i]].chargedHadronEnergy / Jets[loose_jets[i]].JetE );
			Fill("h_loose_jets_chargedfrac", frac );
			Fill("h_loose_jets_chargedM", Jets[loose_jets[i]].chargedMultiplicity );
			
		 }
		}
	 
	/////////Fill met for all events
	 Fill("h_met",MET.Pt());
	

	 double HT = 0;  /* Defined as usually -> Must be modified if using knuts HT */



	 for (int i = 0; i < loose_jets.size(); i++) { 
			 double AngleMJ = fabs(DeltaPhi(MET.Phi(),Jets[loose_jets[i]].Phi() ));
       Fill("h_AngleMJ", AngleMJ);
			 Fill("h_Eta_Jet", Jets[loose_jets[i]].Eta()); 
			 Fill2("h_corrMETJet",MET.Phi() ,Jets[loose_jets[i]].Phi() );
		//	 cout << MET.Phi() << "............." << Jets[loose_jets[i]].Phi() << endl;
		   }
		 
	 if ( loose_jets.size() > 0) Fill2("h_corrMET1Jet",MET.Phi() ,Jets[loose_jets[0]].Phi() );
	 
	 for (int i = 0; i < loose_jets.size(); i++) { 
	 	 if (	Jets[loose_jets[i]].Pt() > 30 && (fabs(Jets[loose_jets[i]].Eta() ) < 2.4 ) ) {
       HT += Jets[loose_jets[i]].Pt(); 
       }	
		 }		
	 Fill("h_HT",HT);
	 Fill("h_reco_vert_n", vertices_n); 
	 Fill("h_inverse_MET",1./MET.Pt());
	 
	 if (HT > 150 ) {
		 Fill("h_met_cut",MET.Pt());	 
		 Fill("h_loose_1photons_pt_cut", Photons[loose_photons[0]].Pt() );	 
		 Fill("h_n_photon_loose_cut",loose_photons.size());	
	 	 Fill("h_cutflow", "Ht>150");
		 Fill("h_inverse_MET_cut",1./MET.Pt());
	 }
	 if ( MET.Pt() > 50 ) {
	 		Fill("h_HT_metcut",HT);
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
