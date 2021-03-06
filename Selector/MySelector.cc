
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

bool MySelector::PassPhotonHadTrigger() const
{
  unsigned nT(PhotonHadNames.size());
  if(nT == 0) return true;

  for(unsigned int i = 0; i != nT; ++i){

    if(hltMap.pass(PhotonHadNames[i])) return true;

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
	 float metScalebinning[] = {0,105,110,115,120,125,130,135,140,145,150,155,160,165,170,175,180,185,190,195,200,210,220,230,240,250,275,300,350,600};	 
	 float inversemetbinning[] = {0, 0.003,0.004,0.005,0.0055,0.006,0.0065,0.007,0.0075,0.008,0.0085,0.009,0.0095,0.01,0.02};
	 float metsignificancebinning[] = {0,4,6,8,10,12,16,20,25,30,70};
	 float scalebinning36[] ={0,4,4.5,5,5.34,5.67,6,6.25,6.5,6.75,7,7.25,7.5,7.75,8,8.25,8.5,8.75,9,9.33,9.66,10,10.5,11,11.5,12,12.5,13,13.75,14.5,15.25,16,17,18,19,20,40};	 
   float scalebinning30[] = {0,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,26,28,30,32,36,40,45,50,70};		 
   float scalebinning24[] = {0,4,4.5,5,5.5,6,6.5,7,7.5,8,8.5,9,9.5,10,10.5,11,12,13,14,15,16,17,18,19,40}; 
   float scalebinning17[] = {0,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,40};
   float scalebinning12[] = {0,4,5,6,7,8,9,10,11,12,13,15,40};
   float scalebinning16[] = {0,4,5,6,7,8,9,10,11,12,13,15,17,19,22,30,40}; 	 	 
   float METsign39[] = {0,15,17.5,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,42,44,46,48,50,52.5,55,57.5,60,65,70,80,90,110,140,400};	 	
   float METsign23[] = {0,16,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,55,60,70,90,130,400};
   float METsign14[] = {0,15,22,26,30,34,40,46,60,80,100,140,180,230,350};
   float METsign32[] = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,110,120,130,140,150,160,170,180,190,200,230,500};	 
   float METsign10[] = {0,20,40,60,80,100,120,150,180,210,500}; 
   float METsign13[] = {0,20,40,60,80,100,120,140,170,200,230,300,400,500};	 
   float Sigma7[] = {0,160,320,480,640,800,1120,2000};  		 
	 float scalebinningPtOverMET[] = {0,0.4,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.0,2.1,2.2,2.3,2.4,2.5,2.6,2.7,2.8,2.9,3.0,3.2,3.4,3.6,3.8,4.0,4.2,4.6,5.0,5.4,5.8,6.2,6.6,7.0,7.5,8.0,10,12};		 
	 float HTbinning[] = {0,75,100,125,150,175,200,225,250,275,300,325,350,375,400,425,450,475,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1300,1400,1500,1750,2000,3000};		
   float HTbinning41[] = {0,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,320,340,360,380,400,425,450,475,500,525,550,575,600,625,650,700,750,850,950,1200,3000};	
	 float HTbinning29[] = {0,100,140,180,220,260,300,340,380,420,460,500,540,580,620,660,700,740,780,820,860,900,940,1020,1100,1180,1260,1400,1550,2000};
	 float InvMassBin27[] = {0,60,70,85,100,115,130,145,160,175,190,205,220,240,260,280,300,330,360,390,420,450,485,520,570,650,750,1000};
	 float PTbefore2[] = {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500,520,540,560,580,600,620,640,680,750}; 	 	 
	 float PTbefore36[] = {0,20,40,60,80,100,120,140,160,180,200,220,240,260,280,300,320,340,360,380,400,420,440,460,480,500,520,540,560,580,600,650,700,750,800,900,1000};   
  	 
		// No fill cut flow histo in command -> strange bug

	 CreateHisto("h_cutflow", "cutflow", 13, -0.5, 12.5);
   Fill("h_cutflow","all", 0); 
	 Fill("h_cutflow","pass #slash{E}_{T} filters", 0);
	 Fill("h_cutflow","trigger", 0);	 
	 Fill("h_cutflow","#slash{E}_{T} > 100 GeV", 0);	 
	 Fill("h_cutflow","# loose #gamma > 0", 0);	 
	 Fill("h_cutflow","# tight #gamma > 0", 0);	  
	 Fill("h_cutflow","tight #gamma p_{T} > 40 GeV", 0);
	 Fill("h_cutflow", "r9 > 0.9", 0);
	 Fill("h_cutflow","tight #gamma in barrel", 0);	
//	 Fill("h_c u tf low", "N_{Jets} > 1", 0);
	// Fill("h_cu tfl ow", "N_{loose Jets} > 2", 0);	 
	 Fill("h_cutflow", "#Delta(R)(1st #gamma, n. jet) > 0.5", 0);	
	 Fill("h_cutflow","H_{T} > 100 GeV", 0);	 
//	 Fi ll("h_cu tflow","tight #gamma p_{T}>100", 0);	  	 	   
	 Fill("h_cutflow","CR + SR", 0);
	 Fill("h_cutflow","SR", 0);

	pdfTree = new TTree("pdfTree", "pdf uncertainty calculation");
	pdfTree->Branch("x2", &pdf_x2, "x2/F");
	pdfTree->Branch("x1", &pdf_x1, "x1/F");
 	pdfTree->Branch("scale", &pdf_scale, "scale/F");
	pdfTree->Branch("id1", &pdf_id1, "id1/F");
	pdfTree->Branch("id2", &pdf_id2, "id2/F");
	pdfTree->Branch("weight", &pdf_weight, "weight/F");
	pdfTree->Branch("selected", &pdf_selected, "selected/F");

  #ifdef __Data
	
    CreateHisto("h_denumerator_bypass_tight_MET_2", "MET (GeV)", 80, 0, 400);				
    CreateHisto("h_numerator_bypass_tight_MET_2","MET (GeV)", 80, 0, 400);									
    CreateHisto("h_denumerator_bypass_tight_2", "MET (GeV)", 80, 0, 400);				
    CreateHisto("h_numerator_bypass_tight_2", "MET (GeV)", 80, 0, 400);									
    CreateHisto("h_denumerator_bypass_loose_MET_2", "MET (GeV)", 80, 0, 400);				
    CreateHisto("h_numerator_bypass_loose_MET_2","MET (GeV)", 80, 0, 400);									
    CreateHisto("h_denumerator_bypass_loose_2","MET (GeV)", 80, 0, 400);				
    CreateHisto("h_numerator_bypass_loose_2", "MET (GeV)", 80, 0, 400);									

		
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
		
		CreateHisto("h_numerator_final_pt_leg_tight_1", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_tight_1", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_numerator_final_ID_leg_tight_1", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_ID_leg_tight_1", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_numerator_final_ID_leg_tight_wo_1", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_ID_leg_tight_wo_1", "photon pt (GeV)", 80, 0, 400); 		
				
		CreateHisto("h_numerator_final_met_leg_tight_1", "MET (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_tight_1", "MET (GeV)", 80, 0, 400); 
		CreateHisto("h_numerator_final_pt_leg_tight_2", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_tight_2", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_numerator_final_pt_leg_tight_woMETcut_2", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_tight_woMETcut_2", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_numerator_final_met_leg_tight_2", "MET (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_tight_2", "MET (GeV)", 80, 0, 400); 	
		
		CreateHisto("h_numerator_final_pt_leg_loose_1", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_loose_1", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_numerator_final_ID_leg_loose_1", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_ID_leg_loose_1", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_numerator_final_ID_leg_loose_wo_1", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_ID_leg_loose_wo_1", "photon pt (GeV)", 80, 0, 400); 		
				
		CreateHisto("h_numerator_final_met_leg_loose_1", "MET (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_loose_1", "MET (GeV)", 80, 0, 400); 
		CreateHisto("h_numerator_final_pt_leg_loose_2", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_loose_2", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_numerator_final_pt_leg_loose_woMETcut_2", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_pt_leg_loose_woMETcut_2", "photon pt (GeV)", 80, 0, 400); 
		CreateHisto("h_numerator_final_met_leg_loose_2", "MET (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_loose_2", "MET (GeV)", 80, 0, 400);		
		
		CreateHisto("h_numerator_final_met_leg_loose_wo", "MET (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_final_met_leg_loose_wo", "MET (GeV)", 80, 0, 400);	
		
		CreateHisto("h_numerator_MET_calc", "MET (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_MET_calc", "MET (GeV)", 80, 0, 400);
		
		CreateHisto("h_numerator_MET_calc_selection", "MET (GeV)", 25, 0, 1000); 
		CreateHisto("h_denumerator_MET_calc_selection", "MET (GeV)", 25, 0, 1000);		
		CreateHisto("h_numerator_PT_calc_selection", "1st #gamma_{loose} p_{T} (GeV)", 25, 0, 1000); 
		CreateHisto("h_denumerator_PT_calc_selection", "1st #gamma_{loose} p_{T} (GeV)", 25, 0, 1000);	
		CreateHisto("h_numerator_PT_calc_MET40", "1st #gamma_{loose} p_{T} (GeV)", 25, 0, 1000); 
		CreateHisto("h_denumerator_PT_calc_MET40", "1st #gamma_{loose} p_{T} (GeV)", 25, 0, 1000);			
		CreateHisto("h_numerator_PT_calc_selection_40", "1st #gamma_{loose} p_{T} (GeV)", 25, 0, 1000); 
		CreateHisto("h_denumerator_PT_calc_selection_40", "1st #gamma_{loose} p_{T} (GeV)", 25, 0, 1000);								
		CreateHisto("h_numerator_PT_calc_selection_100", "1st #gamma_{loose} p_{T} (GeV)", 25, 0, 1000); 
		CreateHisto("h_denumerator_PT_calc_selection_100", "1st #gamma_{loose} p_{T} (GeV)", 25, 0, 1000);
	  
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
		
		
		CreateHisto("h_denumerator_selection_pt", "Photons[loose_photons[0]].Pt()", 80, 0, 400);
		CreateHisto("h_numerator_selection_pt", "Photons[loose_photons[0]].Pt()", 80, 0, 400);
		CreateHisto("h_numerator_selection_met", "MET (GeV)", 80, 0, 400); 
		CreateHisto("h_denumerator_selection_met", "MET (GeV)", 80, 0, 400); 	
	  CreateHisto("h_denumerator_vert", "# of vertices", 40, -0.5, 39.5);
	  CreateHisto("h_numerator_vert", "# of vertices", 40, -0.5, 39.5);		
	  CreateHisto("h_denumerator_vert_100", "# of vertices", 40, -0.5, 39.5);		
	  CreateHisto("h_numerator_vert_100", "# of vertices", 40, -0.5, 39.5);	


// Neue trigger studien

		CreateHisto("h_numerator_selection_pt_leg_met_sign","#slash{E}_{T} significance",80,0,600);			
		CreateHisto("h_denumerator_selection_pt_leg_met_sign","#slash{E}_{T} significance",80,0,600);				
			
		CreateHisto("h_denumerator_selection_met_sign","#slash{E}_{T} significance",80,0,600);
		CreateHisto("h_denumerator_selection_trans_mass","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",80,0,1000);
		CreateHisto("h_denumerator_selection_sigma","#Sigma (GeV)",80,0,1600);			 			 

		CreateHisto("h_denumerator_selection_met_sign_met_cut","#slash{E}_{T} significance",80,0,600);
		CreateHisto("h_denumerator_selection_trans_mass_met_cut","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",80,0,1000);
		CreateHisto("h_denumerator_selection_sigma_met_cut","#Sigma (GeV)",80,0,1600);						

		CreateHisto("h_numerator_selection_met_sign","#slash{E}_{T} significance",80,0,600);
		CreateHisto("h_numerator_selection_trans_mass","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",80,0,1000);
		CreateHisto("h_numerator_selection_sigma",	"#Sigma (GeV)",80,0,1600);				 					 					 

		CreateHisto("h_numerator_selection_met_sign_met_cut","#slash{E}_{T} significance",80,0,600);
		CreateHisto("h_numerator_selection_trans_mass_met_cut","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",80,0,1000);
		CreateHisto("h_numerator_selection_sigma_met_cut",	"#Sigma (GeV)",80,0,1600);	
					 
					 					
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
	
	 CreateHisto("h_upper_right_SR_ht_trigger_fired","H_{T} (GeV)",50,0,2000);		
	 CreateHisto("h_upper_left_SR_ht_trigger_fired","H_{T} (GeV)",50,0,2000);	
	 CreateHisto("h_lower_left_SR_ht_trigger_fired","H_{T} (GeV)",50,0,2000);
	 CreateHisto("h_lower_right_SR_ht_trigger_fired","H_{T} (GeV)",50,0,2000);	 
	 
	 CreateHisto("h_effitest", "Trigger efficiency", 13, -0.15, 1.15);
	 CreateHisto2D("h_2_effitest", "Trigger efficiency", 13, -0.15, 1.15, 2000, 0, 2000);
						
						
  #endif				
						
	 CreateHisto("h_photon_seedTime", "seed time of 1st tight photon ", 100, -100,100);	
	 CreateHisto("h_tight_photons_pt_cut_flow","1st #gamma_{tight} p_{T} (GeV)", 100, 0, 1000);
	 
   CreateHisto("h_photon_pt_for_control","1st #gamma_{tight} p_{T} (GeV)", 100, 0, 1000);	
   CreateHisto("h_ht_for_control","H_{T} (GeV)",100,0,2000);	 
	 CreateHisto("h_truth_ht", "ht on GEN level for status 1 ", 200, 0, 1000);
	 CreateHisto("h_truth_photon_pt", "pt of photons (22) on GEN level for status 1 ", 36, 0, 400);	
	 CreateHisto("h_truth_photons_pt_sel", "pt of photons (22) on GEN level for status 1 ", 36, 0, 500);	
	 CreateHisto("h_truth_electrons_pt_sel", "pt of electrons (+-11) on GEN level for status 1 ", 36, 0, 500);	 	  
	 CreateHisto("h_trueNum", "true num interactions ", 60, 0, 60);	 
	 CreateHisto("h_trueNum2", "true num interactions ", 60, 0, 60);	
	 CreateHisto("h_truth_fake_met_sel","MET.Pt()",50,50,600);
	 CreateHisto("h_truth_fake_met_significance_sel","#slash{E}_{T} significance",50,0,400);	
	 CreateHisto("h_truth_fake_inverse_met_sel","1./MET.Pt()", 50, 0, 0.02);
	 CreateHisto("h_truth_fake_tight_photon_pt_sel","Photons[tight_photons[0]].Pt()", 50, 0, 1000);
	 CreateHisto("h_met_datadriven","MET.Pt()",50,50,600);
	 CreateHisto("h_inverse_met_datadriven","1./MET.Pt()", 50, 0, 0.02);	
	 CreateHisto("h_tight_photon_pt_datadriven","Photons[tight_photons[0]].Pt()", 50, 0, 1000);	
	 CreateHisto("h_DR_gen_e_rec_gamma","#DeltaR(gen. e, 1st #gamma_{tight})",50,0,0.5);		
	 CreateHisto("h_total_number_reco_photons", "tight_photons.size()",5,-0.5,4.5 );
	 CreateHisto("h_gen_number_reco_photons", "tight_photons.size()",5,-0.5,4.5 );	 		
	 CreateHisto("h_real_number_reco_photons", "tight_photons.size()",5,-0.5,4.5 );		
	 
	 								 
	 CreateHisto("h_ht_before_preselection","H_{T} of all jets", 100, 0, 1000);
	 CreateHisto("h_ht_before_pre","H_{T} of all jets", 100, 0, 1000);	 
	 CreateHisto("h_met_before_preselection","#slash{E}_{T} (GeV)",100,0,600);		
		
									 				 
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
	 
	 
	 CreateHisto("h_met", "#slash{E}_{T} (GeV)", 50, 50, 600);
	 CreateHisto("h_TypeOneMet", "Type 1 corrected #slash{E}_{T} (GeV)", 50, 50, 600);	 
	 CreateHistoArray("h_met_orth", "#slash{E}_{T} (GeV)", 29, metScalebinning);
	 CreateHisto("h_pt_orth", "1st tight #gamma pt (GeV)", 40, 30, 110);	 	 
	 CreateHisto("h_met_nJetmax2", "#slash{E}_{T}", 50, 50, 600);	 
	 CreateHisto("h_met_nJetmin3", "#slash{E}_{T}", 50, 50, 600);	
	 CreateHisto("h_met_npixel0", "#slash{E}_{T}", 50, 50, 600);	 
	 CreateHisto("h_met_npixel1", "#slash{E}_{T}", 50, 50, 600);	 	 
	 CreateHistoArray("h_met_array", "#slash{E}_{T} (GeV)", 10, metbinning);	 
	 CreateHisto("h_met_cut", "#slash{E}_{T} (GeV)", 50, 50, 600);	 
	 CreateHisto("h_inverse_MET", "#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHistoArray("h_inverse_MET_array", "#slash{E}_{T}^{-1} (GeV^{-1})", 14, inversemetbinning);	 
	 CreateHisto("h_inverse_MET_sig", "#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);	
	 CreateHisto("h_inverse_MET_GJets", "#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);	  
	 CreateHisto("h_inverse_MET_cut", "#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 	 
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
	 CreateHisto("h_n_bJets", "# of b jets", 10, -0.5, 9.5);	 
	 CreateHisto("h_n_bJets2", "# of b jets", 10, -0.5, 9.5);	 	 
	 CreateHisto("h_n_electrons_medium", "# of medium electrons", 10, -0.5, 9.5);
	 CreateHisto("h_n_muons_loose", "# of loose muons", 10, -0.5, 9.5);	 
	 CreateHisto("h_n_muons_soft", "# of soft muons", 10, -0.5, 9.5);		 

	 CreateHisto("h_sum_pt_photons", "sum_photon_pt",50,0,1000);
	 CreateHisto("h_sum_pt", "sum_pt",60,0,3000);
	 CreateHisto("h_centrality", "centrality",22,0,1.1);
	 CreateHisto("h_centrality_photon", "centrality",22,0,1.1);	 
	 CreateHisto("h_sum_signal","S_{T}^{#gamma} (GeV)",50,0,2000);
	 CreateHisto("h_ST_TypeOne","corrected S_{T}^{#gamma} (GeV)",50,0,2000);	 	 
	 CreateHisto("h_sum_visible","S_{T}^{#gamma} (GeV)",50,0,2000);	 
	 CreateHistoArray("h_sum_signal_per_gev","S_{T}^{#gamma} (GeV)",7,Sigma7); 
		 
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
	 
	 
	 //control regions	 
	 CreateHisto("h_n_loose_photons_control2", " # of loose photons",10, -0.5, 9.5);	
   CreateHistoArray("h_HT_array_control2","H_{T} of all jets (GeV)", 38, HTbinning);
	 CreateHistoArray("h_1tightPhotonPtOverMET_control2","#gamma_{tight} p_{T} / #slash{E}_{T}", 43, scalebinningPtOverMET );	 
	 CreateHistoArray("h_METoverSqHT_control2","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",30,scalebinning30);	 
	 CreateHistoArray("h_met_control2","#slash{E}_{T} (GeV)", 29, metScalebinning);
	 CreateHisto("h_pt_control2","1st loose #gamma pt (GeV)", 50, 30, 1000);
	 CreateHisto("h_n_loose_photons_control3", " # of loose photons",10, -0.5, 9.5);					
	 CreateHistoArray("h_HT_array_control3","H_{T} of all jets (GeV)", 38, HTbinning);
	 CreateHistoArray("h_1tightPhotonPtOverMET_control3","#gamma_{tight} p_{T} / #slash{E}_{T}", 43, scalebinningPtOverMET );	 
	 CreateHistoArray("h_METoverSqHT_control3","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",30,scalebinning30);	 
	 CreateHistoArray("h_met_control3","#slash{E}_{T} (GeV)", 29, metScalebinning);
	 CreateHisto("h_pt_control3","1st loose #gamma pt (GeV)", 50, 30, 1000);				
	 CreateHisto("h_n_loose_photons_control4", " # of loose photons",10, -0.5, 9.5);
	 CreateHistoArray("h_HT_array_control4","H_{T} of all jets (GeV)", 38, HTbinning);
	 CreateHistoArray("h_1tightPhotonPtOverMET_control4","#gamma_{tight} p_{T} / #slash{E}_{T}", 43, scalebinningPtOverMET );	 
	 CreateHistoArray("h_METoverSqHT_control4","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",30,scalebinning30);	 
	 CreateHistoArray("h_met_control4","#slash{E}_{T} (GeV)", 29, metScalebinning);
	 CreateHisto("h_pt_control4","1st loose #gamma pt (GeV)", 50, 30, 1000);		
	 
	 //cross checks on pt dependence
	 CreateHisto("h_pt_dep_1","1st tight #gamma pt (GeV)", 100, 30, 1000); 
	 CreateHisto("h_pt_dep_2","1st tight #gamma pt (GeV)", 100, 30, 1000); 
	 CreateHisto("h_pt_dep_3","1st tight #gamma pt (GeV)", 100, 30, 1000); 
	 CreateHisto("h_pt_dep_4","1st tight #gamma pt (GeV)", 100, 30, 1000); 
	 
	 CreateHistoArray("h_METoverSqHT_double_control_150","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);	
	 CreateHistoArray("h_METoverSqHT_double_control_200","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);	
	 CreateHistoArray("h_METoverSqHT_double_control_250","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);	
	 
	 CreateHistoArray("h_METoverSqHT_double_control_10","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);	
	 CreateHistoArray("h_METoverSqHT_double_control_15","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);	
	 CreateHistoArray("h_METoverSqHT_double_control_20","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);
	 CreateHistoArray("h_METoverSqHT_double_control_30","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_20_2","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);	 
	 CreateHistoArray("h_METoverSqHT_double_control_20_3","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);
	 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_0_10_50","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_0_10_60","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_0_10_70","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_0_10_80","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_0_20_50","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_0_20_60","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 	 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_0_20_70","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_0_20_80","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_50_10_50","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_50_10_60","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_50_10_70","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_50_10_80","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_50_20_60","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_50_20_70","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_50_20_80","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 	 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_100_10_50","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_100_10_60","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_100_10_70","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_100_10_80","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_100_10_80_16","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",16,scalebinning16); 	 	 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_100_0_50","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_100_0_60","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_100_0_70","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_100_0_80","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 			
				 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_20","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_25","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_30","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_35","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_40","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_50","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_60","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_70","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_80","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);	 
	 
	 CreateHistoArray("h_METoverSqHT_double_control_3_regions_30_200","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);
	 CreateHistoArray("h_METoverSqHT_double_control_20_60","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);
	 CreateHistoArray("h_METoverSqHT_double_control_10_60","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);
	 CreateHistoArray("h_METoverSqHT_double_control_10_80","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);
		
	 CreateHisto("h_MET_significance_metsig_sideband","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1000); 
	 CreateHistoArray("h_METoverSqHT_double_control_100_300","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 
	 CreateHistoArray("h_MET_significance_MT_sideband"," #slash{E}_{T} significance",14,METsign14);	
	 CreateHisto("h_MET_significance_MT_sideband_2"," #slash{E}_{T} significance",50,0,500);
	 CreateHisto("h_trans_mass_pt_40","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1000); 
	 CreateHistoArray("h_METoverSqHT_trans_mass_control","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);
	 CreateHisto("h_photon_pt_trans_mass_control","1st tight #gamma pt (GeV)", 100, 30, 1000);
	 CreateHisto("h_photon_pt_trans_mass_signal","1st tight #gamma pt (GeV)", 100, 30, 1000); 
	 CreateHistoArray("h_METoverSqHT_met_sign_control","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12); 	
	 CreateHisto("h_photon_pt_met_sign_control","1st tight #gamma pt (GeV)", 100, 30, 1000); 		  
	 CreateHisto("h_photon_pt_met_sign_signal","1st tight #gamma pt (GeV)", 100, 30, 1000); 	

	 //variation of control region
	 
	 CreateHistoArray("h_HT_array_100_41","H_{T} of all jets (GeV)", 38, HTbinning41);
	 CreateHistoArray("h_MET_significance_100_39"," #slash{E}_{T} significance",39,METsign39);
	 CreateHistoArray("h_MET_significance_100_23"," #slash{E}_{T} significance",23,METsign23);	 
	 CreateHistoArray("h_METoverSqHT_100_36","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",36,scalebinning36);	
	 CreateHistoArray("h_METoverSqHT_100_30","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",30,scalebinning30);	 
	 CreateHistoArray("h_METoverSqHT_100_24","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",24,scalebinning24);	 
	 CreateHistoArray("h_METoverSqHT_100_17","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",17,scalebinning17);	 
	 CreateHistoArray("h_METoverSqHT_100_12","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);		 
	 CreateHistoArray("h_HT_array_80","H_{T} of all jets (GeV)", 38, HTbinning);
	 CreateHistoArray("h_HT_array_80_41","H_{T} of all jets (GeV)", 38, HTbinning41);
	 CreateHistoArray("h_MET_significance_80_39"," #slash{E}_{T} significance",39,METsign39);
	 CreateHistoArray("h_MET_significance_80_23"," #slash{E}_{T} significance",23,METsign23);	 	 
	 CreateHistoArray("h_METoverSqHT_80_36","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",36,scalebinning36);
	 CreateHistoArray("h_METoverSqHT_80_30","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",30,scalebinning30);	 
	 CreateHistoArray("h_METoverSqHT_80_24","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",24,scalebinning24);	 
	 CreateHistoArray("h_METoverSqHT_80_17","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",17,scalebinning17);	
	 CreateHistoArray("h_METoverSqHT_80_12","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);	  	 
	 CreateHistoArray("h_met_80","#slash{E}_{T} (GeV)", 29, metScalebinning);
	 CreateHisto("h_pt_80","1st loose #gamma pt (GeV)", 50, 30, 1000);
	 CreateHistoArray("h_HT_array_90","H_{T} of all jets (GeV)", 38, HTbinning);
	 CreateHistoArray("h_HT_array_90_41","H_{T} of all jets (GeV)", 38, HTbinning41);
	 CreateHistoArray("h_MET_significance_90_39"," #slash{E}_{T} significance",39,METsign39);
	 CreateHistoArray("h_MET_significance_90_23"," #slash{E}_{T} significance",23,METsign23);	 
	 CreateHistoArray("h_METoverSqHT_90_36","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",36,scalebinning36);	
	 CreateHistoArray("h_METoverSqHT_90_30","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",30,scalebinning30);	 
	 CreateHistoArray("h_METoverSqHT_90_24","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",24,scalebinning24);	 
	 CreateHistoArray("h_METoverSqHT_90_17","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",17,scalebinning17);
	 CreateHistoArray("h_METoverSqHT_90_12","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);	 	  
	 CreateHistoArray("h_met_90","#slash{E}_{T} (GeV)", 29, metScalebinning);
	 CreateHisto("h_pt_90","1st loose #gamma pt (GeV)", 50, 30, 1000);	 	 
	 CreateHistoArray("h_HT_array_110","H_{T} of all jets (GeV)", 38, HTbinning);
	 CreateHistoArray("h_HT_array_110_41","H_{T} of all jets (GeV)", 38, HTbinning41);
	 CreateHistoArray("h_MET_significance_110_39"," #slash{E}_{T} significance",39,METsign39);
	 CreateHistoArray("h_MET_significance_110_23"," #slash{E}_{T} significance",23,METsign23);	 
	 CreateHistoArray("h_METoverSqHT_110_36","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",36,scalebinning36);	
	 CreateHistoArray("h_METoverSqHT_110_30","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",30,scalebinning30);	 
	 CreateHistoArray("h_METoverSqHT_110_24","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",24,scalebinning24);	 
	 CreateHistoArray("h_METoverSqHT_110_17","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",17,scalebinning17);	
	 CreateHistoArray("h_METoverSqHT_110_12","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);	   
	 CreateHistoArray("h_met_110","#slash{E}_{T} (GeV)", 29, metScalebinning);
	 CreateHisto("h_pt_110","1st loose #gamma pt (GeV)", 50, 30, 1000);	 	
	 CreateHistoArray("h_HT_array_120","H_{T} of all jets (GeV)", 38, HTbinning);
	 CreateHistoArray("h_HT_array_120_41","H_{T} of all jets (GeV)", 38, HTbinning41);
	 CreateHistoArray("h_MET_significance_120_39"," #slash{E}_{T} significance",39,METsign39);
	 CreateHistoArray("h_MET_significance_120_23"," #slash{E}_{T} significance",23,METsign23);	 
	 CreateHistoArray("h_METoverSqHT_120_36","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",36,scalebinning36);	
	 CreateHistoArray("h_METoverSqHT_120_30","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",30,scalebinning30);	 
	 CreateHistoArray("h_METoverSqHT_120_24","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",24,scalebinning24);	 
	 CreateHistoArray("h_METoverSqHT_120_17","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",17,scalebinning17);	
	 CreateHistoArray("h_METoverSqHT_120_12","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",12,scalebinning12);	   
	 CreateHistoArray("h_met_120","#slash{E}_{T} (GeV)", 29, metScalebinning);
	 CreateHisto("h_pt_120","1st loose #gamma pt (GeV)", 50, 30, 1000);
	 CreateHisto("h_MET_over_PT_100", "#slash{E}_{T} / 1st #gamma_{tight} p_{T}", 75, 0, 15);
	 CreateHisto("h_Angle_MET_1jet_100","Angle between 1st Jet and MET", 64, 0, 3.2);			
	 CreateHistoArray("h_InvMass_2jets_100", "Invariant mass of the two leading jets (GeV)",27,InvMassBin27);		
	 CreateHisto("h_MET_over_PT_80", "#slash{E}_{T} / 1st #gamma_{tight} p_{T}", 75, 0, 15);
	 CreateHisto("h_Angle_MET_1jet_80","Angle between 1st Jet and MET", 64, 0, 3.2);			
	 CreateHistoArray("h_InvMass_2jets_80", "Invariant mass of the two leading jets (GeV)",27,InvMassBin27);			
	 CreateHisto("h_MET_over_PT_90", "#slash{E}_{T} / 1st #gamma_{tight} p_{T}", 75, 0, 15);
	 CreateHisto("h_Angle_MET_1jet_90","Angle between 1st Jet and MET", 64, 0, 3.2);			
	 CreateHistoArray("h_InvMass_2jets_90", "Invariant mass of the two leading jets (GeV)",27,InvMassBin27);		
	 CreateHisto("h_MET_over_PT_110", "#slash{E}_{T} / 1st #gamma_{tight} p_{T}", 75, 0, 15);
	 CreateHisto("h_Angle_MET_1jet_110","Angle between 1st Jet and MET", 64, 0, 3.2);			
	 CreateHistoArray("h_InvMass_2jets_110", "Invariant mass of the two leading jets (GeV)",27,InvMassBin27);			
	 CreateHisto("h_MET_over_PT_120", "#slash{E}_{T} / 1st #gamma_{tight} p_{T}", 75, 0, 15);
	 CreateHisto("h_Angle_MET_1jet_120","Angle between 1st Jet and MET", 64, 0, 3.2);			
	 CreateHistoArray("h_InvMass_2jets_120", "Invariant mass of the two leading jets (GeV)",27,InvMassBin27);			
			
				 									 
	 CreateHistoArray("h_HT_array", "H_{T} of all jets (GeV)", 38, HTbinning);
	 CreateHistoArray("h_HT_array_HT_cut", "H_{T} of all jets (GeV)", 38, HTbinning);	 
	 CreateHistoArray("h_HT_array_pt_cut", "H_{T} of all jets (GeV)", 38, HTbinning);	 	
	 CreateHistoArray("h_HT_array_datadriven", "H_{T} of all jets (GeV)", 38, HTbinning);	
	 CreateHisto("h_pt_raw","1st tight photon pt (GeV)",50,0.,1000);	  		 
	 CreateHisto("h_HT_raw","H_{T} of all jets (GeV)",100,0.,1000);	
	 CreateHisto("h_HT","H_{T} of all jets (GeV)",44,0.,2200);	
	 CreateHisto("h_HT2","H_{T} of all jets (GeV)",44,0.,2200);	 
	 CreateHisto("h_HT_sig","H_{T} of all jets (GeV)",44,0.,2200);
	 CreateHisto("h_HT_GJets","H_{T} of all jets (GeV)",44,0.,2200);	 	  
	 CreateHisto("h_HT_metcut","H_{T} of all loose jets with MET > 50 GeV (GeV)",60,0.,1500);
	 	 
	 CreateHisto("h_reco_vert_n_vor", "# of vertices", 40, -0.5, 39.5); 
	 CreateHisto("h_reco_vert_n_nach", "# of vertices", 40, -0.5, 39.5);	 	 
	 CreateHisto("h_reco_vert_n", "# of vertices", 40, -0.5, 39.5);
	 
	 	 	 
	 CreateHisto("h_loose_jets_pt", "Pt of loose jets", 60, 0, 1200);	
	 CreateHisto("h_cleaned_jets_pt", "Pt of cleaned jets", 60, 0, 1200);	  
	 CreateHisto("h_loose_photons_pt", "all #gamma_{loose} p_{T} (GeV)", 50, 0, 1000);	
	 CreateHisto("h_loose_photon_e5x5", "e5x5 of loose photons", 32, 0, 400);
	 CreateHisto("h_loose_1photons_pt", "1st #gamma_{loose} p_{T} (GeV)", 50, 0, 1000);
	 CreateHisto("h_tight_1photons_pt", "1st #gamma_{tight} p_{T} (GeV)", 200, 0, 1000);	 
	 CreateHisto("h_loose_1photons_pt_cut", "1st #gamma_{loose} p_{T} (GeV)", 32, 0, 400);		 
	 	 
	 CreateHisto("h_photon_eta", "#eta of photons", 40, -4, 4);	 
	 CreateHisto("h_loose_photon_eta_vor", "#eta of loose photons", 40, -4, 4);	 
	 CreateHisto("h_loose_photon_eta", "#eta of loose photons", 40, -4, 4);
	 CreateHisto("h_Eta_Jet", "#eta of Jets", 40, -4, 4);	 	 
		  	  
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
	  	 	 
	 CreateHisto("h_METoverHT","#slash{E}_{T} / H_{T}", 50, 0, 1);
	 CreateHisto("h_1tightPhotonPtOverHT", "1st #gamma_{tight} p_{T} / H_{T}", 50, 0, 2);
	 CreateHisto("h_METoverPhotonPt", "#slash{E}_{T} / 1st #gamma_{tight} p_{T}", 75, 0, 5);
	 CreateHisto("h_1tightPhotonPtOverMET", "1st #gamma_{tight} p_{T} / #slash{E}_{T}", 75, 0, 10);	 
	 CreateHistoArray("h_1tightPhotonPtOverMET_scale", "#gamma_{tight} p_{T} / #slash{E}_{T}", 43, scalebinningPtOverMET );
	 CreateHistoArray("h_1tightPhotonPtOverMET_scale_HT_cut", "#gamma_{tight} p_{T} / #slash{E}_{T}", 43, scalebinningPtOverMET );	 	 
	 CreateHistoArray("h_1tightPhotonPtOverMET_scale_pt_cut", "#gamma_{tight} p_{T} / #slash{E}_{T}", 43, scalebinningPtOverMET );	
	  	 
			 
	 CreateHisto("h_MET_significance"," #slash{E}_{T} significance",60,0,600);	
	 CreateHisto("h_MET_significance_corrected"," #slash{E}_{T} significance",60,0,600);
	 CreateHistoArray("h_MET_significance_array"," #slash{E}_{T} significance",10,METsign10);
	 CreateHistoArray("h_MET_significance_array_norm"," #slash{E}_{T} significance",10,METsign10);	 
	 CreateHistoArray("h_MET_significance_per_gev_10"," #slash{E}_{T} significance",10,METsign10);
	 CreateHistoArray("h_MET_significance_per_gev_14"," #slash{E}_{T} significance",14,METsign14);	 	 
	 CreateHistoArray("h_MET_significance_per_gev_23"," #slash{E}_{T} significance",23,METsign23);	 
	 CreateHistoArray("h_MET_significance_per_gev_32"," #slash{E}_{T} significance",32,METsign32);	
	 CreateHistoArray("h_MET_significance_per_gev_10_blind"," #slash{E}_{T} significance",10,METsign10);
	 CreateHistoArray("h_MET_significance_per_gev_14_blind"," #slash{E}_{T} significance",14,METsign14);	 	 
	 CreateHistoArray("h_MET_significance_per_gev_23_blind"," #slash{E}_{T} significance",23,METsign23);	 
	 CreateHistoArray("h_MET_significance_per_gev_32_blind"," #slash{E}_{T} significance",32,METsign32);	   	
	 CreateHisto("h_MET_significance_scale"," #slash{E}_{T} significance",60,0,600);
	 CreateHisto("h_MET_significance_80"," #slash{E}_{T} significance",60,0,600);	 		 	 
	 CreateHisto("h_MET_significance_90"," #slash{E}_{T} significance",60,0,600);				 
	 CreateHisto("h_MET_significance_110"," #slash{E}_{T} significance",60,0,600);				 
	 CreateHisto("h_MET_significance_120"," #slash{E}_{T} significance",60,0,600);	
	 CreateHisto("h_MET_significance_control2"," #slash{E}_{T} significance",60,0,600);				 
	 CreateHisto("h_MET_significance_control3"," #slash{E}_{T} significance",60,0,600);				 
	 CreateHisto("h_MET_significance_control4"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_met_significance_40"," #slash{E}_{T} significance",50,0,500);	 
	
	 CreateHisto("h_met_significance_before_preselection"," #slash{E}_{T} significance",50,0,500);
	 CreateHisto("h_met_significance_before_preselection2"," #slash{E}_{T} significance",50,0,500);	
	 CreateHisto("h_met_significance_before_preselection3"," #slash{E}_{T} significance",50,0,500);
	 CreateHisto("h_met_significance_before_preselection4"," #slash{E}_{T} significance",50,0,500);		  	 	 
	 CreateHisto("h_met_significance_before_preselection5"," #slash{E}_{T} significance",50,0,500);
	 
	 	 
	 CreateHisto("h_photon_pt_significance","1st #gamma_{tight} p_{T} / #sqrt{H_{T}} [#sqrt{GeV}]",40,0,50);
	 CreateHisto("h_photon_pt_met_significance","1st #gamma_{tight} p_{T} / #sqrt{#slash{E}_{T}} [#sqrt{GeV}]",40,0,60);	 
	 			 
	 CreateHisto("h_METoverSqHT"," #slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}]",50,0,100);
	 CreateHisto("h_METoverSqHT_blind"," #slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}]",50,0,100);	 
	 
	 CreateHistoArray("h_METoverSqHT_scale","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}]",30,scalebinning30);	
	 CreateHistoArray("h_METoverSqHT_scale_HT_cut","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}]",30,scalebinning30);	  
	 CreateHistoArray("h_METoverSqHT_scale_HT","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",30,scalebinning30);		 	 
	 CreateHistoArray("h_METoverSqHT_array","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",10,metsignificancebinning);	 
	 CreateHisto("h_HToverMET", "H_{T} / #slash{E}_{T}",60,0,20);
	 CreateHisto("h_InvMassJets","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEta","InvMassJetsEta",40,0,800); 
	 CreateHisto("h_InvMassJetsRel","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEtaRel","InvMassJetsEta",40,0,800);
	 CreateHisto("h_trans_mass_MET_Gamma","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1000);
	 CreateHisto("h_trans_mass_MET_Gamma_blind","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1000);	 
	 CreateHisto("h_trans_mass_MET_Gamma_100","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1000);	 
	 
	 
	 CreateHisto("h_METoverSqHT_low"," #slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}]",50,0,100);
	 CreateHisto("h_HToverMET_low", "H_{T} / #slash{E}_{T}",60,0,20);
	 CreateHisto("h_InvMassJets_low","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEta_low","InvMassJetsEta",40,0,800); 
	 CreateHisto("h_InvMassJetsRel_low","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEtaRel_low","InvMassJetsEta",40,0,800);
	 CreateHisto("h_trans_mass_MET_Gamma_low","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1100);
	 CreateHisto("h_n_loose_photons_low","Number of #gamma_{loose}",10,-0.5,9.5);
	 CreateHisto("h_inverse_met_low","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_tight_photon_pt_over_HT_low","1st #gamma_{tight} p_{T} / H_{T}", 50, 0, 2);
	 CreateHisto("h_cleaned_jets_pt_low","1st Jet p_{T} (GeV)", 60, 0, 1000);
	 CreateHisto("h_trans_mass_MET_Gamma_low_sig","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1100);
	 CreateHisto("h_cleaned_jets_pt_low_sig","1st Jet p_{T} (GeV)", 60, 0, 1000);	 
	 CreateHisto("h_inverse_met_low_sig", "#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_n_loose_photons_low_sig","Number of #gamma_{loose}",10,-0.5,9.5);	
		 
	 CreateHisto("h_Etrans_rel","Relative transversal energy",40,0,800);
	 CreateHisto("h_DeltaPhi_rel", "rel Delta Phi",32,0,3.2);		 		 
	 CreateHisto("h_trans_mass_MET_Rel","TransMassMETRel",40,0,800);
	 CreateHisto("h_trans_mass_MET_Rel_Z","TransMassMETRel",40,0,800);	 
 	
	 
	 	  	  	 
	 CreateHisto("h_METoverSqHT_high","#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}] ",50,0,80);
	 CreateHisto("h_HToverMET_high", "H_{T} / #slash{E}_{T}",60,0,20);
	 CreateHisto("h_InvMassJets_high","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEta_high","InvMassJetsEta",40,0,800); 
	 CreateHisto("h_InvMassJetsRel_high","InvMassJets",40,0,800);
	 CreateHisto("h_InvMassJetsEtaRel_high","InvMassJetsEta",40,0,800);	 
	 CreateHisto("h_n_cleaned_jets_high","Number of Jets",10,-0.5,9.5);	
	 CreateHisto("h_trans_mass_MET_Gamma_high","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1100);
	 CreateHisto("h_n_loose_photons_high","Number of #gamma_{loose}",10,-0.5,9.5);
	 CreateHisto("h_inverse_met_high","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_tight_photon_pt_over_HT_high","#gamma_{tight} p_{T}/H_{T}", 50, 0, 2);
	 CreateHisto("h_cleaned_jets_pt_high","1st Jet p_{T} (GeV)", 60, 0, 1200);
	 CreateHisto("h_trans_mass_MET_Gamma_high_sig","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1300);
	 CreateHisto("h_cleaned_jets_pt_high_sig","1st Jet p_{T} (GeV)", 60, 0, 1200);	 
	 CreateHisto("h_inverse_met_high_sig", "#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_n_loose_photons_high_sig","Number of #gamma_{loose}",10,-0.5,9.5);	
	 CreateHisto("h_trans_mass_MET_Gamma_high_ratio","M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1300);
	 CreateHisto("h_cleaned_jets_pt_high_ratio","1st Jet p_{T} (GeV)", 60, 0, 1200);	 
	 CreateHisto("h_inverse_met_high_ratio", "#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_n_loose_photons_high_ratio","Number of #gamma_{loose}",10,-0.5,9.5);	  
	 
	 CreateHisto("h_selection_low"," #slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);	 
	 CreateHisto("h_selection_high"," #slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);	 
	 CreateHisto("h_selection_high2","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_selection_high2_met_sign"," #slash{E}_{T} significance",60,0,600);	 	 	 
	
	// N-1 Plots
	 CreateHisto("h_N-1_mt_low", "M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1300);
	 CreateHisto("h_N-1_sum_pt_low", "#sum_{i} #gamma_{i}p_{T} + H_{T} (GeV)",60,0,2000);
	 CreateHisto("h_N-1_sum_signal_low", "#sum_{i} #gamma_{i}p_{T} + #slash{E}_{T}",60,0,2000);	 
	 CreateHisto("h_N-1_jet_pt_low", "1st Jet p_{T} (GeV)", 60, 0, 1000);
	 CreateHisto("h_inverse_met_selection_low", "#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	   
	 CreateHisto("h_N-1_METsig_high", "#slash{E}_{T} / #sqrt{H_{T}} [#sqrt{GeV}]",50,0,80);
	 CreateHisto("h_N-1_mt_high", "M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1300);
	 CreateHisto("h_N-1_sum_pt_high", "#sum_{i} #gamma_{i}p_{T} + H_{T} (GeV)",60,0,3000);
	 CreateHisto("h_N-1_sum_signal_high", "#sum_{i} #gamma_{i}p_{T} + #slash{E}_{T} (GeV)",60,0,3000);
	 CreateHisto("h_N-1_sum_ptOverHt_high", "#sum_{i} #gamma_{i}p_{T} / #sqrt{H_{T}} [#sqrt{GeV}]",50,0,100);	 	 
	 CreateHisto("h_N-1_n_jets_high", "Number of Jets",10,-0.5,9.5);
	 CreateHisto("h_inverse_met_selection_high", "#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 
	 CreateHisto("h_n_pixel_selection_low","Number of #gamma_{Pixel}",5,-0.5,4.5);
	 CreateHisto("h_n_photons_selection_low","Number of #gamma_{loose}",5,-0.5,4.5);	 
	 CreateHisto("h_n_jets_selection_low","Number of Jets",10,-0.5,9.5);	 
	 CreateHisto("h_inverse_met_selection_pixel_low","#slash{E}_{T}^{-1} (GeV^{-1}) ",50, 0, 0.02);
	 CreateHisto("h_inverse_met_selection_2gamma_low","#slash{E}_{T}^{-1} (GeV^{-1}) ",50, 0, 0.02);	 	 
	 CreateHisto("h_n_pixel_selection_high","Number of #gamma_{Pixel}",5,-0.5,4.5);
	 CreateHisto("h_n_photons_selection_high","Number of #gamma_{Pixel}",5,-0.5,4.5);	 
	 CreateHisto("h_inverse_met_selection_pixel_high","#slash{E}_{T}^{-1} (GeV^{-1}) ",50, 0, 0.02);
	 CreateHisto("h_inverse_met_selection_jets_high"," #slash{E}_{T}^{-1} (GeV^{-1})",50, 0, 0.02);
	 CreateHisto("h_inverse_met_selection_2gamma_high","#slash{E}_{T}^{-1} (GeV^{-1})",50, 0, 0.02);	 	 
 	 CreateHisto("h_number_selection_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})",50, 0, 0.02);
	 
	 // Check dependency of n Vertex  -> difference in trigger efficiency
	 
		CreateHisto("h_vert_20","# of vertices", 40, -0.5, 39.5);
		CreateHisto("h_vert_40","# of vertices", 40, -0.5, 39.5);		
		CreateHisto("h_vert_60","# of vertices", 40, -0.5, 39.5);		
		CreateHisto("h_vert_80","# of vertices", 40, -0.5, 39.5);		
		CreateHisto("h_vert_100","# of vertices", 40, -0.5, 39.5);		
		CreateHisto("h_vert_150","# of vertices", 40, -0.5, 39.5);		
		CreateHisto("h_vert_high","# of vertices", 40, -0.5, 39.5);		
		CreateHisto("h_vert_met_125","# of vertices", 40, -0.5, 39.5);
		CreateHisto("h_vert_met_150","# of vertices", 40, -0.5, 39.5);		
		CreateHisto("h_vert_met_200","# of vertices", 40, -0.5, 39.5);		
		CreateHisto("h_vert_met_250","# of vertices", 40, -0.5, 39.5);		
		CreateHisto("h_vert_met_350","# of vertices", 40, -0.5, 39.5);		
		CreateHisto("h_vert_met_high","# of vertices", 40, -0.5, 39.5);		
		
			
		// Photon properties
		
		
		CreateHisto("h_photon_charged_iso_40","#gamma_{tight} charged hadron isolation (GeV)", 50, 0, 0.7);		 
		CreateHisto("h_photon_neutral_iso_40","#gamma_{tight} neutral hadron isolation - 0.04*p_{T} (GeV)", 50, 0, 0.4);
		CreateHisto("h_photon_photon_iso_40","#gamma_{tight} photon isolation - 0.005*p_{T} (GeV)", 50, 0, 0.5);
		
		CreateHisto("h_photon_charged_iso_60","#gamma_{tight} charged hadron isolation (GeV)", 50, 0, 0.7);		 
		CreateHisto("h_photon_neutral_iso_60","#gamma_{tight} neutral hadron isolation - 0.04*p_{T} (GeV)", 50, 0, 0.4);
		CreateHisto("h_photon_photon_iso_60","#gamma_{tight} photon isolation - 0.005*p_{T} (GeV)", 50, 0, 0.5);	
		
		CreateHisto("h_photon_charged_iso_80","#gamma_{tight} charged hadron isolation (GeV)", 50, 0, 0.7);		 
		CreateHisto("h_photon_neutral_iso_80","#gamma_{tight} neutral hadron isolation - 0.04*p_{T} (GeV)", 50, 0, 0.4);
		CreateHisto("h_photon_photon_iso_80","#gamma_{tight} photon isolation - 0.005*p_{T} (GeV)", 50, 0, 0.5);
		
		CreateHisto("h_photon_charged_iso_100","#gamma_{tight} charged hadron isolation (GeV)", 50, 0, 0.7);		 
		CreateHisto("h_photon_neutral_iso_100","#gamma_{tight} neutral hadron isolation - 0.04*p_{T} (GeV)", 50, 0, 0.4);
		CreateHisto("h_photon_photon_iso_100","#gamma_{tight} photon isolation - 0.005*p_{T} (GeV)", 50, 0, 0.5);			
				
		CreateHisto("h_photon_charged_iso_150","#gamma_{tight} charged hadron isolation (GeV)", 50, 0, 0.7);		 
		CreateHisto("h_photon_neutral_iso_150","#gamma_{tight} neutral hadron isolation - 0.04*p_{T} (GeV)", 50, 0, 0.4);
		CreateHisto("h_photon_photon_iso_150","#gamma_{tight} photon isolation - 0.005*p_{T} (GeV)", 50, 0, 0.5);
		
		CreateHisto("h_photon_charged_iso_200","#gamma_{tight} charged hadron isolation (GeV)", 50, 0, 0.7);		 
		CreateHisto("h_photon_neutral_iso_200","#gamma_{tight} neutral hadron isolation - 0.04*p_{T} (GeV)", 50, 0, 0.4);
		CreateHisto("h_photon_photon_iso_200","#gamma_{tight} photon isolation - 0.005*p_{T} (GeV)", 50, 0, 0.5);	
						
		CreateHisto("h_photon_charged_iso_400","#gamma_{tight} charged hadron isolation (GeV)", 50, 0, 0.7);		 
		CreateHisto("h_photon_neutral_iso_400","#gamma_{tight} neutral hadron isolation - 0.04*p_{T} (GeV)", 50, 0, 0.4);
		CreateHisto("h_photon_photon_iso_400","#gamma_{tight} photon isolation - 0.005*p_{T} (GeV)", 50, 0, 0.5);
		
		CreateHisto("h_photon_charged_iso_inf","#gamma_{tight} charged hadron isolation (GeV)", 50, 0, 0.7);		 
		CreateHisto("h_photon_neutral_iso_inf","#gamma_{tight} neutral hadron isolation - 0.04*p_{T} (GeV)", 50, 0, 0.4);
		CreateHisto("h_photon_photon_iso_inf","#gamma_{tight} photon isolation - 0.005*p_{T} (GeV)", 50, 0, 0.5);					
		// Control and Signal Region
		
	 	CreateHisto("h_tight_photon_pt_before","1st #gamma_{tight} p_{T} (GeV)", 100, 0, 1000);	
		CreateHistoArray("h_tight_photon_pt_before_per_gev","1st #gamma_{tight} p_{T} (GeV)",36,PTbefore36);		
	  CreateHistoArray("h_MET_significance_array_norm_before"," #slash{E}_{T} significance",10,METsign10); 		
	  CreateHistoArray("h_MET_significance_per_gev_14_before"," #slash{E}_{T} significance",14,METsign14);	
		CreateHisto("h_trans_mass_pt_before", "M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1000);	
		CreateHistoArray("h_trans_mass_pt_before_per_gev", "M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",34,PTbefore2);		
		CreateHisto("h_met_significance_before", " #slash{E}_{T} significance",60,0,600);	
	  CreateHisto("h_sum_signal_over_sqrt_met_before","#sum [#sqrt{GeV}]",40,10,90);
	  CreateHisto("h_n_photon_loose_before","Number of #gamma_{loose}",10,-0.5,9.5);	
	  CreateHisto("h_n_photon_tight_before","Number of #gamma_{tight}",10,-0.5,9.5);			
	  CreateHisto("h_n_jets_cleaned_before","Number of jets",10,-0.5,9.5);
		CreateHisto("h_jet_pt_before","1st jet p_{T} (GeV)", 100, 0, 1000);
	  CreateHisto("h_HT_before","H_{T} (GeV)",50,0,2000);	  
		CreateHisto("h_hlt_HT_before","H_{T} (GeV)",50,0,2000);	 
	  CreateHistoArray("h_HT_before_per_gev","H_{T} (GeV)",29,HTbinning29);		
		CreateHisto("h_met_before","#slash{E}_{T} (GeV)", 50, 50, 600); 		
		CreateHisto("h_TypeOneMet_before","Type 1 corrected #slash{E}_{T} (GeV)", 50, 50, 600); 		
	  CreateHisto("h_ST_TypeOne_before","corrected S_{T}^{#gamma} (GeV)",50,0,2000);	
	  CreateHisto("h_ST_before","S_{T}^{#gamma} (GeV)",50,0,2000);	 
	 	 
	 	CreateHisto("h_tight_photon_pt_CR","1st #gamma_{tight} p_{T} (GeV)", 100, 0, 1000);	 
	  CreateHistoArray("h_MET_significance_array_norm_CR"," #slash{E}_{T} significance",10,METsign10);
	  CreateHistoArray("h_MET_significance_array_CR"," #slash{E}_{T} significance",10,METsign10);
	  CreateHistoArray("h_MET_significance_array_CR_13"," #slash{E}_{T} significance",10,METsign13);						
	  CreateHistoArray("h_MET_significance_per_gev_14_CR"," #slash{E}_{T} significance",14,METsign14);
		CreateHisto("h_trans_mass_pt_CR", "M_{T}(#slash{E}_{T}, 1st #gamma) (GeV)",50,0,1000);	
		CreateHisto("h_met_significance_CR"," #slash{E}_{T} significance",60,0,600);		
	  CreateHisto("h_sum_signal_over_sqrt_met_CR","#sum [#sqrt{GeV}]",40,10,90);
	  CreateHisto("h_n_photon_loose_CR","Number of #gamma_{loose}",10,-0.5,9.5);	
	  CreateHisto("h_n_photon_tight_CR","Number of #gamma_{tight}",10,-0.5,9.5);			
	  CreateHisto("h_n_jets_cleaned_CR","Number of jets",10,-0.5,9.5);
		CreateHisto("h_jet_pt_CR","1st jet p_{T} (GeV)", 100, 0, 1000);
	  CreateHisto("h_HT_CR","H_{T} (GeV)",50,0,2000);
		CreateHisto("h_met_CR","#slash{E}_{T} (GeV)", 50, 50, 600);
		CreateHisto("h_TypeOneMet_CR","Type 1 corrected #slash{E}_{T} (GeV)", 50, 50, 600); 		
		CreateHistoArray("h_InvMass_2jets_CR", "Invariant mass of the two leading jets (GeV)",27,InvMassBin27);		
		CreateHisto("h_Angle_MJ1_CR","Angle between 1st Jet and #slash{E}_{T}", 64, 0, 3.2);	
	  CreateHisto("h_ST_TypeOne_CR","corrected S_{T}^{#gamma} (GeV)",50,0,2000);	
	  CreateHisto("h_ST_CR","S_{T}^{#gamma} (GeV)",50,0,2000);		
		
		//FINAL
		
		CreateHisto("h_final_n_loose_photons_blind"," # of loose photons",10, -0.5, 9.5);
		CreateHisto("h_final_n_loose_photons_unblind"," # of loose photons",10, -0.5, 9.5);		
		CreateHistoArray("h_final_MET_significance_blind"," #slash{E}_{T} significance",14,METsign14);	
		CreateHistoArray("h_final_MET_significance_unblind"," #slash{E}_{T} significance",14,METsign14);			

		// 	Signal region bins  //

	CreateHisto("h_upper_right_SR_HT","H_{T} (GeV)",50,0,2000); 
	CreateHisto("h_upper_right_SR_n","Number of #gamma_{loose}",10,-0.5,9.5);	
	CreateHisto("h_upper_right_SR","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);
	
	CreateHisto("h_upper_left_SR_HT","H_{T} (GeV)",50,0,2000); 
	CreateHisto("h_upper_left_SR_n","Number of #gamma_{loose}",10,-0.5,9.5);	
	CreateHisto("h_upper_left_SR","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);
			
	CreateHisto("h_lower_left_SR_HT","H_{T} (GeV)",50,0,2000); 
	CreateHisto("h_lower_left_SR_n","Number of #gamma_{loose}",10,-0.5,9.5);	
	CreateHisto("h_lower_left_SR","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);
		
	CreateHisto("h_lower_right_SR_HT","H_{T} (GeV)",50,0,2000); 
	CreateHisto("h_lower_right_SR_n","Number of #gamma_{loose}",10,-0.5,9.5);	
	CreateHisto("h_lower_right_SR","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);			

	CreateHisto("h_upper_right_SR_sum_signal","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);		
	CreateHisto("h_upper_left_SR_sum_signal","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);	
	CreateHisto("h_lower_left_SR_sum_signal","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);
	CreateHisto("h_lower_right_SR_sum_signal","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);		
	
	CreateHisto("h_upper_right_SR_ht","H_{T} (GeV)",50,0,2000);		
	CreateHisto("h_upper_left_SR_ht","H_{T} (GeV)",50,0,2000);	
	CreateHisto("h_lower_left_SR_ht","H_{T} (GeV)",50,0,2000);
	CreateHisto("h_lower_right_SR_ht","H_{T} (GeV)",50,0,2000);	
	
	CreateHisto("h_upper_right_SR_ht_trigger","H_{T} (GeV)",50,0,2000);		
	CreateHisto("h_upper_left_SR_ht_trigger","H_{T} (GeV)",50,0,2000);	
	CreateHisto("h_lower_left_SR_ht_trigger","H_{T} (GeV)",50,0,2000);
	CreateHisto("h_lower_right_SR_ht_trigger","H_{T} (GeV)",50,0,2000);	
	
	CreateHisto("h_upper_right_SR_ht_trigger_had","H_{T} (GeV)",50,0,2000);		
	CreateHisto("h_upper_left_SR_ht_trigger_had","H_{T} (GeV)",50,0,2000);	
	CreateHisto("h_lower_left_SR_ht_trigger_had","H_{T} (GeV)",50,0,2000);
	CreateHisto("h_lower_right_SR_ht_trigger_had","H_{T} (GeV)",50,0,2000);	
	
	CreateHisto("h_upper_right_SR_ht_trigger_had_2","H_{T} (GeV)",50,0,2000);		
	CreateHisto("h_upper_left_SR_ht_trigger_had_2","H_{T} (GeV)",50,0,2000);	
	CreateHisto("h_lower_left_SR_ht_trigger_had_2","H_{T} (GeV)",50,0,2000);
	CreateHisto("h_lower_right_SR_ht_trigger_had_2","H_{T} (GeV)",50,0,2000);		
			
	
	CreateHisto("h_upper_right_SR_MT","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);		
	CreateHisto("h_upper_left_SR_MT","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);	
	CreateHisto("h_lower_left_SR_MT","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);
	CreateHisto("h_lower_right_SR_MT","1st #gamma_{tight} p_{T} (GeV)" ,1,0,5000);		
	 /*************** Selection analysis *****************/
	 
	 
	 CreateHisto("h_sum_signal_over_sqHT","( #sum_{i} #gamma_{i}p_{T} + #slash{E}_{T} )/ #sqrt{H_{T}} [#sqrt{GeV}]",40,0,100);
	 CreateHisto("h_sum_signal_over_sqMET"," #Sigma [#sqrt{GeV}]",45,10,100);	 
	 CreateHisto("h_sum_signal_over_MET","( #sum_{i} #gamma_{i}p_{T} + #slash{E}_{T} )/ #slash{E}_{T} [#sqrt{GeV}]",40,0,20);	 
	 CreateHisto("h_stage1_met_significance"," #slash{E}_{T} significance",60,0,600);
	 CreateHisto("h_stage1_met_over_pt", "#slash{E}_{T} / 1st #gamma_{tight} p_{T}", 50, 0, 10);
	 CreateHisto("h_stage1_pt_over_HT","1st #gamma_{tight} p_{T} / H_{T}", 60, 0, 3);
	 CreateHisto("h_stage1_angle_met_1jet","Angle between 1st Jet and MET", 42, 0, 4.2);
	 CreateHisto("h_stage1_sum_signal", "#sum_{i} #gamma_{i}p_{T} + #slash{E}_{T} (GeV)",50,0,2000);
	 CreateHisto("h_stage1_n_jets","# of cleaned jets", 10, -0.5, 9.5);
	 CreateHisto("h_stage1_angle_photon_met","Angle between tight photon and MET", 42, 0, 4.2);
	 CreateHisto("h_stage1_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02); 
	 CreateHisto("h_stage1_jet_pt", "1st jet p_{T} (GeV)",40,0,1000);  
	 CreateHisto("h_stage2_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_stage2_met_significance"," #slash{E}_{T} significance",60,0,600);  
	 CreateHisto("h_stage3_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_stage3_met_significance"," #slash{E}_{T} significance",60,0,600);        
	 CreateHisto("h_stage4_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_stage4_met_significance"," #slash{E}_{T} significance",60,0,600);      
	 CreateHisto("h_stage5_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_stage5_met_significance"," #slash{E}_{T} significance",60,0,600);      
	 CreateHisto("h_stage6_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_stage6_met_significance"," #slash{E}_{T} significance",60,0,600);  
	 CreateHisto("h_stage7_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_stage7_met_significance"," #slash{E}_{T} significance",60,0,600);      
	 CreateHisto("h_stage8_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_stage8_met_significance"," #slash{E}_{T} significance",60,0,600);  
	 CreateHisto("h_stage9_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_stage9_met_significance"," #slash{E}_{T} significance",60,0,600);    
	 CreateHisto("h_stage10_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_stage10_met_significance_25"," #slash{E}_{T} significance",60,0,600);
	 CreateHisto("h_stage10_met_significance_26"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_stage10_met_significance_27"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_stage10_met_significance_28"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_stage10_met_significance_29"," #slash{E}_{T} significance",60,0,600);
	 CreateHisto("h_stage10_met_significance"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_stage10_met_significance_31"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_stage10_met_significance_32"," #slash{E}_{T} significance",60,0,600);	
	 CreateHisto("h_stage10_met_significance_33"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_stage10_met_significance_34"," #slash{E}_{T} significance",60,0,600);		 
	 CreateHisto("h_stage10_met_significance_35"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_stage10_met_significance_36"," #slash{E}_{T} significance",60,0,600);		  	 	 
	 CreateHisto("h_stage10_met_significance_37"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_stage10_met_significance_38"," #slash{E}_{T} significance",60,0,600);	
	 CreateHisto("h_stage10_met_significance_39"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_stage10_met_significance_40"," #slash{E}_{T} significance",60,0,600);		 
	 	   
	 CreateHisto("h_stage11_inverse_met","#slash{E}_{T}^{-1} (GeV^{-1})", 50, 0, 0.02);
	 CreateHisto("h_stage11_met_significance_10"," #slash{E}_{T} significance",60,0,600);
	 CreateHisto("h_stage11_met_significance_11"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_stage11_met_significance"," #slash{E}_{T} significance",60,0,600);	 
	 CreateHisto("h_stage11_met_significance_13"," #slash{E}_{T} significance",60,0,600);	  			
	 CreateHisto("h_stage11_met_significance_8"," #slash{E}_{T} significance",60,0,600);
	 
	 CreateHisto("h_stage12_met_significance"," #slash{E}_{T} significance",60,0,600);  	 
	 CreateHisto("h_stage13_met_significance"," #slash{E}_{T} significance",60,0,600);  	 
	 CreateHisto("h_stage14_met_significance"," #slash{E}_{T} significance",60,0,600);  	 
	 CreateHisto("h_stage15_met_significance"," #slash{E}_{T} significance",60,0,600);  
	 CreateHisto("h_stage16_met_significance"," #slash{E}_{T} significance",60,0,600);	 	
	 CreateHisto("h_stage17_met_significance"," #slash{E}_{T} significance",60,0,600);
	 CreateHisto("h_stage18_met_significance"," #slash{E}_{T} significance",60,0,600);	 	
	 CreateHisto("h_stage19_met_significance"," #slash{E}_{T} significance",60,0,600);
	 CreateHisto("h_stage20_met_significance"," #slash{E}_{T} significance",60,0,600);	 	
	 CreateHisto("h_stage21_met_significance"," #slash{E}_{T} significance",60,0,600);	 
	 	 
	  
	 CreateHisto("h_stage4_N-1_pt_over_HT","1st #gamma_{tight} p_{T} / H_{T}", 60, 0, 3);						

	 CreateHisto("h_stage5_N-1_met_over_pt", "#slash{E}_{T} / 1st #gamma_{tight} p_{T}", 50, 0, 10);

	 CreateHisto("h_stage1_N-1_met_ratio_pt_ratio"," #slash{E}_{T} significance",60,0,600);
	 
	 CreateHisto2D("h2_met_sign_sigma","#slash{E}_{T} significance vs. #Sigma",60,0,600,60,0,1800);		  		
	 CreateHisto2D("h2_met_sign_sigma_SR","#slash{E}_{T} significance vs. #Sigma",60,0,600,60,0,1800);		
	 CreateHisto2D("h2_sigma_metsign","#Sigma vs. #slash{E}_{T} significance",50,0,100,60,0,600);		
	 CreateHisto2D("h2_sigma_met","#Sigma vs. #slash{E}_{T}",50,0,100,60,0,600);			
 			
	 CreateHisto2D("h2_met_sign_trans_mass"," #slash{E}_{T} significance vs. M_{T}(#slash{E}_{T}, 1st #gamma) ",60,0,600,50,0,1000);
	 CreateHisto2D("h2_trigger_effis_numerator","1st #gamma_{tight} p_{T} vs #slash{E}_{T}",40,0,400,40,0,400);				
	 CreateHisto2D("h2_trigger_effis_denumerator","1st #gamma_{tight} p_{T} vs #slash{E}_{T}",40,0,400,40,0,400);															
   CreateHisto2D("h2_sigmaIEIE_met","2D sigma i eta i eta and MET",40,0,0.04,40,0,600);			
   CreateHisto2D("h2_sigmaIEIE_met_1","2D sigma i eta i eta and MET",40,0,0.04,40,0,600);				
   CreateHisto2D("h2_n_photon_pixel_met","2D number of pixel photons and MET",3,-0.5,2.5,30,0,600);		 
   CreateHisto2D("h2_n_jets_met","2D number of cleaned jets and MET",10,-0.5,9.5,30,0,600);		 
   CreateHisto2D("h2_truth_photon_DeltaR_relPt_before","GenMatch for photons in DeltaR and relativ pt",300,0,1,300,-2.5,2.5);	
   CreateHisto2D("h2_truth_electron_DeltaR_relPt_before","#Delta R(gen. e, #gamma)",300,0,1,300,-2.5,2.5);	 	 
   CreateHisto2D("h2_truth_photon_DeltaR_relPt","GenMatch for photons in DeltaR and relativ pt",50,0,0.5,50,-2.5,2.5);	
   CreateHisto2D("h2_truth_electron_DeltaR_relPt","GenMatch for electrons in DeltaR and relativ pt",50,0,0.5,50,-2.5,2.5);	  
	 CreateHisto2D("h2_vert_met", "correlation of # vertices and MET", 60, -0.5, 59.5, 40, 0, 100);	 
	 CreateHisto2D("h2_vert_pt", "correlation of # vertices and tight photon pt",60, -0.5, 59.5, 40, 0, 100);	 	 
	 CreateHisto2D("h_corrMETJet", " correlation of Phi of MET and Jets", 32, -3.2, 3.2, 32, -3.2, 3.2);
	 CreateHisto2D("h_corrMET1Jet", " correlation of Phi of MET and first Jet", 32, -3.2, 3.2, 32, -3.2, 3.2);
	 CreateHisto2D("h2_corr_r9_pt_signal", "correlation of r9 and photon pt", 130, 0, 1.3, 150, 0, 300);	 
	 CreateHisto2D("h2_corr_r9_pt_iso", "correlation of r9 and photon pt", 130, 0, 1.3, 150, 0, 300);
	 CreateHisto2D("h2_Corr_DeltaR_relPt_Photon_Jet", "Correlation of Delta R and relPt of Photon and Jet",150,0,1,150,0,3);
	 CreateHisto2D("h2_Corr_DeltaR_relPt2_Photon_Jet", "Correlation of Delta R and relPt of Photon and Jet",150,0,1,150,0,3);	 
	 CreateHisto2D("h2_match_DeltaR_relPt_Photon_Jet", "Correlation of Delta R and relPt of Photon and Jet",150,0,1,150,-1.5,1.5);
	 CreateHisto2D("h2_match_DeltaR_relPt2_Photon_Jet", "Correlation of Delta R and relPt of Photon and Jet",150,0,1,150,0,3);		 
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
	 //Shifting jet momentum for correction and up and down for JEC uncertainty 
	 
    //  MyJet jet(pfJets_ak5_momentum_fP_fX[i]*(1-pfJets_ak5_jecUncertainty[i]),pfJets_ak5_momentum_fP_fY[i]*(1-pfJets_ak5_jecUncertainty[i]),pfJets_ak5_momentum_fP_fZ[i]*(1-pfJets_ak5_jecUncertainty[i]),pfJets_ak5_momentum_fE[i]*(1-pfJets_ak5_jecUncertainty[i]));
    //  MyJet jet(pfJets_ak5_momentum_fP_fX[i],pfJets_ak5_momentum_fP_fY[i],pfJets_ak5_momentum_fP_fZ[i],pfJets_ak5_momentum_fE[i]);
      MyJet jet(pfJets_ak5_momentum_fP_fX[i]*pfJets_ak5_JECScale[i],pfJets_ak5_momentum_fP_fY[i]*pfJets_ak5_JECScale[i],pfJets_ak5_momentum_fP_fZ[i]*pfJets_ak5_JECScale[i],pfJets_ak5_momentum_fE[i]*pfJets_ak5_JECScale[i]);			
   //   MyJet jet(pfJets_ak5_momentum_fP_fX[i]*(1+pfJets_ak5_jecUncertainty[i]),pfJets_ak5_momentum_fP_fY[i]*(1+pfJets_ak5_jecUncertainty[i]),pfJets_ak5_momentum_fP_fZ[i]*(1+pfJets_ak5_jecUncertainty[i]),pfJets_ak5_momentum_fE[i]*(1+pfJets_ak5_jecUncertainty[i]));
	
			double jet_pt = jet.Pt();
			double jet_eta = jet.Eta();
			double jet_E = jet.E();
	 	  jet.SetJetPt(jet_pt);
			jet.SetJetEta(jet_eta);
			jet.SetJetE(jet_E);
			jet.SetJecUncert(pfJets_ak5_jecUncertainty[i]);	
			jet.SetJecScale(pfJets_ak5_JECScale[i]);					
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
	 
	 
	 Vertices.clear();
	 for (int i = 0; i < vertices_; ++i) {
      MyVertices vertices(vertices_position_fX[i], vertices_position_fY[i],vertices_position_fZ[i],0);
			}	
			
	 Tracks.clear();
	 for (int i = 0; i < tracks_; ++i) {
      MyTracks tracks(tracks_momentum_fP_fX[i], tracks_momentum_fP_fY[i],tracks_momentum_fP_fZ[i],tracks_momentum_fE[i]);
			}			
			
			
	 Electrons.clear();
	 for (int i = 0; i < electrons_gsfElectrons_; ++i) {
      MyElectron electron(electrons_gsfElectrons_momentum_fP_fX[i], electrons_gsfElectrons_momentum_fP_fY[i],electrons_gsfElectrons_momentum_fP_fZ[i],electrons_gsfElectrons_momentum_fE[i]);
			double electron_pt = electron.Pt();
			double electron_eta = electron.Eta();
			TVector3 electron_vertex = TVector3(electrons_gsfElectrons_vertex_fX[i],electrons_gsfElectrons_vertex_fY[i],electrons_gsfElectrons_vertex_fZ[i]);

	 	  electron.SetElectronPt(electron_pt);
			electron.SetElectronEta(electron_eta);
			electron.SetSigmaIetaIeta(electrons_gsfElectrons_sigmaIetaIeta[i]);
			electron.SetDeltaEtaSuperCluster(electrons_gsfElectrons_deltaEtaSuperClusterTrackAtVtx[i]);
			electron.SetDeltaPhiSuperCluster(electrons_gsfElectrons_deltaPhiSuperClusterTrackAtVtx[i]);			
			electron.SetHoverE(electrons_gsfElectrons_hcalOverEcalBc[i]);
			electron.SetEoverP(electrons_gsfElectrons_eSuperClusterOverP[i]);
			electron.SetEcalEnergy(electrons_gsfElectrons_ecalEnergy[i]);
			electron.SetTrackIndex(electrons_gsfElectrons_gsfTrackIndex[i]);
			electron.SetnMissingHits(electrons_gsfElectrons_nMissingHits[i]);		
			electron.SetPassConversionVeto(electrons_gsfElectrons_passConversionVeto[i]);				
			electron.SetVertex(electron_vertex);					
			electron.SetVertexX(tracks_vertex_fX[electrons_gsfElectrons_gsfTrackIndex[i]]);
			electron.SetVertexY(tracks_vertex_fY[electrons_gsfElectrons_gsfTrackIndex[i]]);	
			electron.SetVertexZ(tracks_vertex_fZ[electrons_gsfElectrons_gsfTrackIndex[i]]);			
	//		electron.SetVertexX(vertices_position_fX[tracks_vertexIndex[electrons_gsfElectrons_gsfTrackIndex[i]]]);
	//		electron.SetVertexY(vertices_position_fY[tracks_vertexIndex[electrons_gsfElectrons_gsfTrackIndex[i]]]);	
	//		electron.SetVertexZ(vertices_position_fZ[tracks_vertexIndex[electrons_gsfElectrons_gsfTrackIndex[i]]]);
			electron.SetTrackPX(tracks_momentum_fP_fX[electrons_gsfElectrons_gsfTrackIndex[i]]);
			electron.SetTrackPY(tracks_momentum_fP_fY[electrons_gsfElectrons_gsfTrackIndex[i]]);	
			electron.SetTrackPZ(tracks_momentum_fP_fZ[electrons_gsfElectrons_gsfTrackIndex[i]]);			

			Electrons.push_back(electron);
			}
	 sort(Electrons.begin(), Electrons.end(), LorentzVectorSortPt);	
	 
		
	 Muons.clear();
	 for (int i = 0; i < muons_muons_; ++i) {
      MyMuon muon(muons_muons_momentum_fP_fX[i], muons_muons_momentum_fP_fY[i],muons_muons_momentum_fP_fZ[i],muons_muons_momentum_fE[i]);
			double muon_pt = muon.Pt();
			double muon_eta = muon.Eta();
	 	  muon.SetMuonPt(muon_pt);
			muon.SetMuonEta(muon_eta);
			muon.SetMuonType(muons_muons_type[i]);
			muon.SetMuonQualityFlag(muons_muons_qualityFlags[i]);			
			muon.SetVertexX(tracks_vertex_fX[muons_muons_trackIndex[i]]);
			muon.SetVertexY(tracks_vertex_fY[muons_muons_trackIndex[i]]);	
			muon.SetVertexZ(tracks_vertex_fZ[muons_muons_trackIndex[i]]);			

			muon.SetTrackPX(tracks_momentum_fP_fX[muons_muons_trackIndex[i]]);
			muon.SetTrackPY(tracks_momentum_fP_fY[muons_muons_trackIndex[i]]);	
			muon.SetTrackPZ(tracks_momentum_fP_fZ[muons_muons_trackIndex[i]]);	
			muon.SetChargedHadronPt(muons_muons_sumChargedHadronPt04[i]);
			muon.SetNeutralHadronEt(muons_muons_sumNeutralHadronEt04[i]);
			muon.SetPhotonEt(muons_muons_sumPhotonEt04[i]);
			muon.SetPUPt(muons_muons_sumPUPt04[i]);	
			muon.SetChi2(tracks_ndof[muons_muons_trackIndex[i]]);
			muon.SetNDF(tracks_chi2[muons_muons_trackIndex[i]]);
			muon.SetPixelLayers(muons_muons_nPixelLayersWithMeasurement[i]);
			muon.SetStripLayers(muons_muons_nStripLayersWithMeasurement[i]);			
			
			Muons.push_back(muon);
			}
	 sort(Muons.begin(), Muons.end(), LorentzVectorSortPt);			
		
			
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
	TypeOneMET.SetXYZM(met_pfType1CorrectedMet_mEt_fX, met_pfType1CorrectedMet_mEt_fY, 0, 0);	
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

void MySelector::Fill(const char * name, double value, double weight)
{
  TH1F * h = histo[name];
  if (h != 0)
    h->Fill(value,Eventweight*weight);
  else {
    std::cout << std::string("Histogram \"") + name + std::string("\" not existing. Did you misspell or forgot to create?") << std::endl;
  }
}


void MySelector::FillPerGev(const char * name, double value, double weight)
{
  TH1F * h = histo[name];
  if (h != 0)
    h->Fill(value,Eventweight*weight/(h->GetBinWidth(h->FindBin(value))));
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

void MySelector::FillMETsign(const char * name, double value, double weight)
{
  TH1F * h = histo[name];
  if (h != 0){
		if ( value < 120 ) {
    	h->Fill(value,Eventweight*weight);
			}
		if (value > 120 && value < 210) {
    	h->Fill(value,Eventweight*weight/1.5);
			}		
		if (value > 210) {
    	h->Fill(value,Eventweight*weight/(14.5));
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
 

	#ifdef __MC	
	 
	pdf_weight = 1*getPileUpWeight(); 	 

	 Fill("h_met_vor", metMET.Pt());
	
	  	
	 Eventweight *= getPileUpWeight();
	 
	 int lauf = 0;
	 int truenumb = -1;
   while(lauf < pu_ && truenumb < 0 ){

                if (pu_BX[lauf] == 0){
												Fill("h_trueNum2",pu_trueNumInteractions[lauf]);
                        truenumb = pu_trueNumInteractions[lauf];
										}		
								lauf++;
        }	
				 
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
	 
	 /* Photons */
	 
	 vector<int> loose_photons; /* these "loose photon" correspond to the twiki loose 
	 															different in Knuts analysis-> my loose = knuts tight */
																
	 vector<int> tight_photons; /* these "tight photon" correspond to the twiki tight 
	 															different in Knuts analysis */	
	 vector<int> pixel_photons;	
	 vector<int> cut_photons;
	 vector<int> cut_EB_photons;	 
	 vector<int> cut_r9_photons;	
	 															
	 vector<int> trigger_photons;	
	 	
	 /* Jets */	 														
																															
	 vector<int> loose_jets;    /* these "loose jets" are jets with loose ID */
	 vector<int> cleaned_jets;
	 vector<int> test_jets;	 
	 vector<int> cleaned_jets_control2;	 
	 vector<int> b_jets;
	 vector<int> b_jets2;	 
	 vector<int> photon_matched_jets;	
	  	 
	 /* Electrons */			 
			 
	 vector<int> medium_electrons;	 
	 
	 /* Muons */	 
	 
	 vector<int> loose_muons;	 
	 vector<int> soft_muons;	 
	 
   string ZGamma = "ZGamma_V09";
	 
   string ZGammaLL = "ZGammaLL_V09"; //
	 
   string ZGammaNuNu = "ZGammaNuNu_V09"; //
	 
	 string Pixel = "Pixel";
	 	 
	 string WGamma ="WGamma_V09";
	 
	 string WGamma_20_30 = "WGamma_20_30_V09";
	 
	 string WGamma_30_50 = "WGamma_30_50_V09";	 
	 
	 string WGamma_50_130 = "WGamma_50_130_V09";
	 
	 string WGamma_130_inf = "WGamma_130_inf_V09";
	 
	 string Signal_640_630 = "Signal_640_630";
	 	 
	 ///////////////////* Start analysis  *////////////////////////
	 	 

   if ( Pixel.compare(BGName) == 0 ) {	
	   for (unsigned int i = 0; i < Photons.size(); i++) {
	 		if (Photons[i].Pt() > 30 && Photons[i].IsTightIsolated() && Photons[i].HasPixelSeed() ) {
				pixel_photons.push_back(i);
				}	 
			if (Photons[i].Pt() > 30 && Photons[i].IsLooseIsolated() && Photons[i].HasPixelSeed() ) {
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
	 
	 
	 }
	 else{
	   for (unsigned int i = 0; i < Photons.size(); i++) {
	 		if (Photons[i].Pt() > 30 && Photons[i].HasPixelSeed() ) {
				pixel_photons.push_back(i);
				}	 
			if (Photons[i].Pt() > 30 && Photons[i].IsLooseIsolated() && !(Photons[i].HasPixelSeed())  ) {
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
	    
	 }
	
	 
	 for (unsigned int i = 0; i < Jets.size(); i++) {
	//	cout << "neutral energy fraction: " << Jets[i].neutralHadronEnergy << "  energy :" << Jets[i].JetE <<	endl;
	//		cout <<" JEts eta before:   " <<	Jets[i].JetEta << endl;	
	 	if ( Jets[i].IsLooseIsolated() ) {
			loose_jets.push_back(i);
	//		cout <<" JEts eta:   " <<	Jets[i].JetEta << endl;
//			cout <<" loose jets eta:   " <<	Jets[loose_jets[i]].JetEta << endl;			

		}
	 }
	 	 
	 	 
		 
	 // For ZGamma Cut
// ZGamma > 140 kFALSE, ZGammaNuNu < 140 kFALSE


/*   if ( ZGammaNuNu.compare(BGName) == 0 ) {	
		  for ( int i = 0; i < GenParticles.size() ; i++) {
//	 		  if (GenParticles[i].GenStatus == 1 && (GenParticles[i].GenPDGID == 17 || GenParticles[i].GenPDGID == -17  ) ) {
			  if ( GenParticles[i].GenStatus == 1 ){ // && fabs(GenParticles[i].GenPDGID) == 16 ) {	//fabs(GenParticles[i].GenPDGID == 12) || fabs(GenParticles[i].GenPDGID == 14) || fabs(GenParticles[i].GenPDGID == 16)  ) {
				cout << " Gen status:..."  << GenParticles[i].GenStatus <<endl;
				cout << " Gen ID:..."  << GenParticles[i].GenPDGID <<endl;			
			     }

				}

			}	
			*/
			
bool right_event = false;
				
   if ( ZGamma.compare(BGName) == 0 ) {	
	 		if (tight_photons.size() < 1) return kFALSE;
		//	cout << "------------------------------------------------" << endl;	
		  for ( unsigned int i = 0; i < GenParticles.size() ; i++) {	
			//	cout << "gen id....  " << 	GenParticles[i].GenPDGID	<< "      gen status.....  " <<  GenParticles[i].GenStatus << endl;		 
	 			if ( (fabs(GenParticles[i].GenPDGID) == 12 || fabs(GenParticles[i].GenPDGID) == 14 || fabs(GenParticles[i].GenPDGID) ==
				16) && (GenParticles[i].GenStatus == 1) ) {
					right_event = true;		
				//	cout << "neutrino" << endl;	
					}
				}
				if (right_event == true && Photons[tight_photons[0]].Pt() > 140) {
					return kFALSE;
					}
				if (right_event == false) {
					return kFALSE;
					}			 
			 
			}
			
	 else if ( ZGammaNuNu.compare(BGName) == 0 ) {	
			if (tight_photons.size() < 1) return kFALSE;		 
	 		if (Photons[tight_photons[0]].Pt() < 140) return kFALSE; 			
		  }
			
/*   if ( ZGammaLL.compare(BGName) == 0 ) {	
		  for ( int i = 0; i < GenParticles.size() ; i++) {
//	 		  if (GenParticles[i].GenStatus == 1 && (GenParticles[i].GenPDGID == 17 || GenParticles[i].GenPDGID == -17  ) ) {
			  if ( 	!((GenParticles[i].GenPDGID == 15 || GenParticles[i].GenPDGID == -15) &&  GenParticles[i].GenStatus == 2) ) {
				   return kFALSE;
			     }

				}

			}			

*/

/*   if ( WGamma.compare(BGName) == 0 ) {	
	 		if (tight_photons.size() < 1) return kFALSE;		 
	 		if (Photons[tight_photons[0]].Pt() > 135) return kFALSE; 			
			} 
	 else if ( WGamma_50_130.compare(BGName) == 0 ) {	
			if (tight_photons.size() < 1) return kFALSE;		 
	 		if (Photons[tight_photons[0]].Pt() < 135) return kFALSE; 			
		  }
	 else if ( WGamma_130_inf.compare(BGName) == 0 ) {	
			if (tight_photons.size() < 1) return kFALSE;		 
	 		if (Photons[tight_photons[0]].Pt() < 135) return kFALSE; 			
		  } 	*/
	 
	/***** Impact parameter calculation for cut based ID electrons ************/
	
	 
	 for (unsigned int i = 0; i < Electrons.size(); i++) {
	 	if ( Electrons[i].IsMediumIsolated() ) {
				medium_electrons.push_back(i);
				}
	 	}
		
	 for (unsigned int i = 0; i < Muons.size(); i++) {
	 	if ( Muons[i].IsPfMuon() && ( Muons[i].IsGlobalMuon() || Muons[i].IsTrackerMuon() ) && Muons[i].Pt() > 20 ) {
				loose_muons.push_back(i);
				}
	 	}
				
	 for (unsigned int i = 0; i < Muons.size(); i++) {
	 	if ( Muons[i].IsSoftMuon() ) {
				soft_muons.push_back(i);
				}
	 	}	 
	 		
 #ifdef __MC
 			 
	for( int i = 0; i < pu_; i++){
     if (pu_BX[i] == 0){
				Fill2("h2_vert_met",pu_trueNumInteractions[i],MET.Pt());
				if ( tight_photons.size() == 1 ) Fill2("h2_vert_pt",pu_trueNumInteractions[i],Photons[tight_photons[0]].Pt());							
				}		
     }
		 
  for ( unsigned int i = 0; i < GenParticles.size() ; i++) {
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
	 
//	if ( tight_photons.size() < 1 ) return kFA LSE; 
	
	 Fill("h_cutflow","all");

	pdf_id1 = gridParams_pdf_id1;
	pdf_id2 = gridParams_pdf_id2;
	pdf_scale = gridParams_pdf_scale;
	pdf_x1 = gridParams_pdf_x1;
	pdf_x2 = gridParams_pdf_x2;
	pdf_selected = 0;
	

	if ( !((metFilterBit & metFilterMask) == metFilterMask) ){
		pdfTree->Fill();
		return kFALSE;
	}		 
	// bool cut_n_photon  = (Photons.size() > 0);

	 
	 /* Require trigger selection taking turn-on into account */
	 	 
	// if (cu t_n_ph oton == f alse) return kFALSE; // at least one photon	 
	 
	Fill("h_cutflow", "pass #slash{E}_{T} filters");
	 
	double DeltaR1 = 0;	
	double DeltaR = 10;
	double DeltaR2 = 0;	
		 
	 #ifdef __Data   
	 		
	// Analysis code doubled to process datadriven and MC at the same time, realized with ifdef		
			
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
	 DeltaR = 10;

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() && MET.Pt() > 100 && Photons[tight_photons[0]].r9 < 1 && Photons[tight_photons[0]].r9 > 0.9 ){
	 		Fill("h_denumerator_final_pt_leg_tight_2", Photons[tight_photons[0]].Pt());
	  	if ( Photons[tight_photons[0]].Pt() > 40 ) {		
			AngleGJ = 10;
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
				DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
				if ( Jets[loose_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 ))){
					AngleGJ1 = fabs(DeltaPhi(Jets[loose_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ));
					if ( AngleGJ1 < AngleGJ ) {
					  AngleGJ = AngleGJ1;
				    }
			   	DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
	        if (DeltaR2 < DeltaR){
				 	 DeltaR = DeltaR2;
					 }
				 }
	    }
			Fill("h_denumerator_vert_100",vertices_n);	
			AngleGM2 = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));		
		  if (DeltaR > 0.5) {
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
		      	Fill("h_numerator_vert_100",vertices_n);													
						if (DeltaR > 0.5) {
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
			DeltaR = 10;
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
				DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
				if ( Jets[loose_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 ))){
					AngleGJ1 = fabs(DeltaPhi(Jets[loose_jets[i]].Phi(),Photons[tight_photons[0]].Phi() ));
					if ( AngleGJ1 < AngleGJ ) {
					  AngleGJ = AngleGJ1;
				    }
				  DeltaR2 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
	        if (DeltaR2 < DeltaR){
				 	 DeltaR = DeltaR2;
					 }
				 }

	    }
		 AngleGM2 = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));
	   if (DeltaR > 0.5 ) {
		   Fill("h_denumerator_DeltaRCut_2", Photons[tight_photons[0]].Pt());
		   }
				
	   if ( PassSignalTrigger() ) {
	  	 if (DeltaR > 0.5 ) {
			     Fill("h_numerator_DeltaRCut_2", Photons[tight_photons[0]].Pt());
			     }										
			 }
	 					
  }

//////////////
//selection//
/////////////

//PT efficiency -> use METParked dataset


	double HT_trigger = 0;
	DeltaR = 10;

	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() && MET.Pt() > 100 && Photons[tight_photons[0]].r9 > 0.9){
				
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
				DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]); 
				if ( Jets[loose_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 ))){
					HT_trigger += Jets[loose_jets[i]].Pt();
					DeltaR2 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]); 
	        if (DeltaR2 < DeltaR){
				 	 DeltaR = DeltaR2;
					 }
				 }

	    }
	   if (HT_trigger > 100) {
		 	 if (Photons[tight_photons[0]].Pt() > 40 ) {
		      Fill("h_denumerator_JET_corr_100_2",DeltaR);	
					}	    
			 if (DeltaR > 0.5 ) {
		   Fill("h_denumerator_selection_pt", Photons[tight_photons[0]].Pt());
			 if ( Photons[tight_photons[0]].Pt() > 40 ) {
				Fill("h_denumerator_PT_calc_selection",Photons[tight_photons[0]].Pt());
				Fill("h_denumerator_selection_pt_leg_met_sign",met_pfMet_significance);				
				 }
				}			 
		   }
				
	   if ( PassSignalTrigger() ) {
	  	 if (HT_trigger > 100) {
			 if (Photons[tight_photons[0]].Pt() > 40 ) {
			    Fill("h_numerator_JET_corr_100_2",DeltaR);
					}
			 if (DeltaR > 0.5 ){
			     Fill("h_numerator_selection_pt", Photons[tight_photons[0]].Pt());
					 if ( Photons[tight_photons[0]].Pt() > 40 ) {
						Fill("h_numerator_PT_calc_selection",Photons[tight_photons[0]].Pt());
						Fill("h_numerator_selection_pt_leg_met_sign",met_pfMet_significance);
						}	
						}					 
			     }										
			 }
	 					
  }
	
	double HT_trigger2 = 0;
	DeltaR = 10;


// MEt nur 40, aber Ht cut
	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassMETTrigger() && MET.Pt() > 40 && Photons[tight_photons[0]].r9 > 0.9){
				
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
				DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]); 
				if ( Jets[loose_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 ))){
					HT_trigger2 += Jets[loose_jets[i]].Pt();
					DeltaR2 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]); 
	        if (DeltaR2 < DeltaR){
				 	 DeltaR = DeltaR2;
					 }
				 }

	    }
	   if (HT_trigger2 > 100) {	    
			 if (DeltaR > 0.5 ) {
			 if ( Photons[tight_photons[0]].Pt() > 40 ) {
				Fill("h_denumerator_PT_calc_MET40",Photons[tight_photons[0]].Pt());
				 }
				}			 
		   }
				
	   if ( PassSignalTrigger() ) {
	  	 if (HT_trigger2 > 100) {
			 if (DeltaR > 0.5 ){
					 if ( Photons[tight_photons[0]].Pt() > 40 ) {
						Fill("h_numerator_PT_calc_MET40",Photons[tight_photons[0]].Pt());
						}	
						}					 
			     }										
			 }
	 					
  }	
	double TransMass_trigger = 0;	
	double sigma_trigger = 0;
	//MET efficiency 
	DeltaR = 10;
	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassIsoGammaTrigger() && Photons[tight_photons[0]].Pt() > 40 && Photons[tight_photons[0]].r9 > 0.9){
			TransMass_trigger = TMath::Sqrt(2*Photons[tight_photons[0]].Pt()*MET.Pt()*(1.- TMath::Cos(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi()))));		
			sigma_trigger = Photons[tight_photons[0]].Pt() + MET.Pt();  //hier nur ein photon verlangt deswegen [0]
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
				DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]); 
				if ( Jets[loose_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 ))){
					HT_trigger += Jets[loose_jets[i]].Pt();
					DeltaR2 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]); 
	        if (DeltaR2 < DeltaR){
				 	 DeltaR = DeltaR2;
					 }
				 }

	    }
	   if (DeltaR > 0.5 && HT_trigger > 100) {
		   Fill("h_denumerator_selection_met", MET.Pt());
			 Fill("h_denumerator_selection_met_sign",met_pfMet_significance);
			 Fill("h_denumerator_selection_trans_mass",TransMass_trigger);
			 Fill("h_denumerator_selection_sigma",sigma_trigger);			 			 
			 if ( MET.Pt() > 100 ) {
				Fill("h_denumerator_MET_calc_selection",MET.Pt());
			  Fill("h_denumerator_selection_met_sign_met_cut",met_pfMet_significance);
				Fill("h_denumerator_selection_trans_mass_met_cut",TransMass_trigger);
				Fill("h_denumerator_selection_sigma_met_cut",sigma_trigger);						
				}
		   }
				
	   if ( PassSignalTrigger() && HT_trigger > 100) {
	  	 if (DeltaR > 0.5) {
			     Fill("h_numerator_selection_met", MET.Pt());
			     Fill("h_numerator_selection_met_sign",met_pfMet_significance);
			     Fill("h_numerator_selection_trans_mass",TransMass_trigger);
			     Fill("h_numerator_selection_sigma",sigma_trigger);					 					 					 
					 if ( MET.Pt() > 100 ) {
					 	Fill("h_numerator_MET_calc_selection",MET.Pt());
			     Fill("h_numerator_selection_met_sign_met_cut",met_pfMet_significance);
				   Fill("h_numerator_selection_trans_mass_met_cut",TransMass_trigger);
				   Fill("h_numerator_selection_sigma_met_cut",sigma_trigger);					 				 							
						}					 
			     }										
			 }
	 					
  }
	
	
	//2 D efficiency plot of trigger effi
	DeltaR = 10;
	HT_trigger = 0;
	 if ( tight_photons.size() == 1 && fabs(Photons[tight_photons[0]].Eta()) < 1.4442 && PassIsoGammaTrigger() && Photons[tight_photons[0]].r9 > 0.9){
				
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
				DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]); 
				if ( Jets[loose_jets[i]].Pt()>30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 ))){
					HT_trigger += Jets[loose_jets[i]].Pt();
					DeltaR2 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]); 
	        if (DeltaR2 < DeltaR){
				 	 DeltaR = DeltaR2;
					 }
				 }

	    }
	   if (DeltaR > 0.5 && HT_trigger > 100) {
			 Fill2("h2_trigger_effis_denumerator",MET.Pt() ,Photons[tight_photons[0]].Pt());				
		   }
				
	   if ( PassSignalTrigger() && HT_trigger > 100 && DeltaR > 0.5) {
			 Fill2("h2_trigger_effis_numerator",MET.Pt() ,Photons[tight_photons[0]].Pt());										
			 }
	 					
  }	
	
	
	/*	
		------------------------> ///////////////////////////////////	<------------------------
 	 ------------------------> /// >> Ready for some magic? << /// <------------------------
	------------------------> /////////////////////////////////// <------------------------  */
		
	 DeltaR = 10;	
			
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
	   	Fill("h_denumerator_vert",vertices_n);			
			AngleGM2 = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));		
		  if (DeltaR > 0.5) {
				Fill("h_denumerator_DeltaRCut_PtCut_2", Photons[tight_photons[0]].Pt());
				if ( Photons[tight_photons[0]].Pt() < 100 ) {
					Fill("h_denumerator_PT_calc_selection_40",Photons[tight_photons[0]].Pt());
					}
				else {
					Fill("h_denumerator_PT_calc_selection_100",Photons[tight_photons[0]].Pt());					
					}
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
						Fill("h_numerator_vert",vertices_n);							
			      Fill("h_numerator_MET_corr_woDelta_2", AngleGM2);							
						if (DeltaR > 0.5) {
			       	Fill("h_numerator_DeltaRCut_PtCut_2", Photons[tight_photons[0]].Pt());						
							if ( Photons[tight_photons[0]].Pt() < 100 ) {
								Fill("h_numerator_PT_calc_selection_40",Photons[tight_photons[0]].Pt());
								}
							else {
								Fill("h_numerator_PT_calc_selection_100",Photons[tight_photons[0]].Pt());					
								}								
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
			if ( MET.Pt() > 100 ) {
				Fill("h_denumerator_MET_calc",MET.Pt());
				}
				
	 		if ( PassSignalTrigger() ) {
					Fill("h_numerator_final_met_leg_loose_wo", MET.Pt());
		    	if ( MET.Pt() > 100 ) {
			    	Fill("h_numerator_MET_calc",MET.Pt());
				    }					
					}
	 	
	    }				


/*****************************************************************************************************************************************************
************************************ end of trigger studies ******************************************************************************************
****************************************************************************************************************************************************/ 
	
	if ( tight_photons.size() > 0 ) {
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
			  double angle_jet_gamma = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);		
			 	Fill2("h2_match_DeltaR_relPt_Photon_Jet",angle_jet_gamma ,(Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/Photons[tight_photons[0]].Pt());
			 	Fill2("h2_match_DeltaR_relPt2_Photon_Jet",angle_jet_gamma ,Jets[loose_jets[i]].Pt()/Photons[tight_photons[0]].Pt());				
				}
			}	
		
	 if (!PassSignalTrigger() ) {
		pdfTree->Fill();
		return kFALSE;
	}
	 
	 Fill("h_cutflow", "trigger");	 
	 

	 /* At least one photon is needed for this cut definition */
	 
	 Fill("h_met_significance_before_preselection",met_pfMet_significance); 
	 
	 bool cut_met = (MET.Pt() > 100);
	  
	 if (!cut_met){
		pdfTree->Fill();
		return kFALSE;
	}
// met at least 40 GeV

//	cout << "test" << endl;
	 Fill("h_cutflow", "#slash{E}_{T} > 100 GeV");
	 	 
	 if ( loose_photons.size() == 0 ){
		pdfTree->Fill();
		return kFALSE;
	}
	// cout << "passed" << endl;
	 Fill("h_cutflow", "# loose #gamma > 0");	
	 
	 // Investigate further control regions -> no tight (but at least one loose) photon	 
	 double HT_before = 0;
	 double DeltaR1_before = 0;
	 if ( tight_photons.size() == 0 ) {
	 	 if (Photons[loose_photons[0]].Pt() > 40 && Photons[loose_photons[0]].r9 > 0.9 && fabs(Photons[loose_photons[0]].Eta()) < 1.4442 ) {
		 	 for (unsigned int i = 0; i < loose_jets.size(); i++) { 
	 			 DeltaR1_before = Photons[loose_photons[0]].DeltaR(Jets[loose_jets[i]]);
				 if (	Jets[loose_jets[i]].Pt() > 30 && (DeltaR1_before > 0.1 || (fabs((Photons[loose_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[loose_photons[0]].Pt()) >
					0.5 )) ) {
					 cleaned_jets_control2.push_back(i);			 
     	  	}
			 	}
			 for (unsigned int i = 0; i < cleaned_jets_control2.size(); i++) { 
    	 		HT_before += Jets[cleaned_jets_control2[i]].Pt(); 
			 		}
				if ( HT_before > 100 ) {	
				  Fill("h_n_loose_photons_control2",loose_photons.size());	
					Fill("h_HT_array_control2",HT_before);
					Fill("h_1tightPhotonPtOverMET_control2",Photons[loose_photons[0]].Pt()/MET.Pt());	 
					Fill("h_METoverSqHT_control2", MET.Pt()/(TMath::Sqrt(HT_before)));
					Fill("h_met_control2",MET.Pt());
					Fill("h_pt_control2",Photons[loose_photons[0]].Pt());								
					Fill("h_MET_significance_control2",met_pfMet_significance);
					if (Photons[loose_photons[0]].Pt() < 100) {
				    Fill("h_n_loose_photons_control3",loose_photons.size());					
						Fill("h_HT_array_control3",HT_before);
						Fill("h_1tightPhotonPtOverMET_control3",Photons[loose_photons[0]].Pt()/MET.Pt());	 
						Fill("h_METoverSqHT_control3", MET.Pt()/(TMath::Sqrt(HT_before)));
						Fill("h_met_control3",MET.Pt());
						Fill("h_pt_control3",Photons[loose_photons[0]].Pt());									
						Fill("h_MET_significance_control3",met_pfMet_significance);				
						}
					if (Photons[loose_photons[0]].Pt() > 100) {
					  Fill("h_n_loose_photons_control4",loose_photons.size());
						Fill("h_HT_array_control4",HT_before);
						Fill("h_1tightPhotonPtOverMET_control4",Photons[loose_photons[0]].Pt()/MET.Pt());	 
						Fill("h_METoverSqHT_control4", MET.Pt()/(TMath::Sqrt(HT_before)));
						Fill("h_met_control4",MET.Pt());
						Fill("h_pt_control4",Photons[loose_photons[0]].Pt());									
						Fill("h_MET_significance_control4",met_pfMet_significance);				
						}							

					}
				}	 
	   }
		 
		  
		 
	 if ( tight_photons.size() == 0 ){
		pdfTree->Fill();
		return kFALSE;
	}
	
	 Fill("h_cutflow", "# tight #gamma > 0");		 
	
	////* From here on: at least one tight isolated ID photon with P_t > 50 in Barrel, MET > 40 *//////// 
   for (unsigned int i = 0; i < tight_photons.size(); i++) {
		 if (Photons[tight_photons[i]].Pt() < 40) {
				Fill("h_photon_charged_iso_40",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_40", 0.);
						 } else {
						Fill("h_photon_neutral_iso_40",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_40", 0.);
						 } else {
						Fill("h_photon_photon_iso_40",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}													
				}
		 if (Photons[tight_photons[i]].Pt() > 40 && Photons[tight_photons[i]].Pt() < 60) {
				Fill("h_photon_charged_iso_60",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_60", 0.);
						 } else {
						Fill("h_photon_neutral_iso_60",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_60", 0.);
						 } else {
						Fill("h_photon_photon_iso_60",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}
					}
		 if (Photons[tight_photons[i]].Pt() > 60 && Photons[tight_photons[i]].Pt() < 80) {
				Fill("h_photon_charged_iso_80",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_80", 0.);
						 } else {
						Fill("h_photon_neutral_iso_80",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_80", 0.);
						 } else {
						Fill("h_photon_photon_iso_80",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}
				}						
						
		 if (Photons[tight_photons[i]].Pt() > 80 && Photons[tight_photons[i]].Pt() < 100) {
				Fill("h_photon_charged_iso_100",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_100", 0.);
						 } else {
						Fill("h_photon_neutral_iso_100",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_100", 0.);
						 } else {
						Fill("h_photon_photon_iso_100",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}	
				}					
												
		 if (Photons[tight_photons[i]].Pt() > 100 && Photons[tight_photons[i]].Pt() < 150) {
				Fill("h_photon_charged_iso_150",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_150", 0.);
						 } else {
						Fill("h_photon_neutral_iso_150",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_150", 0.);
						 } else {
						Fill("h_photon_photon_iso_150",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}
						
				}						
						
		 if (Photons[tight_photons[i]].Pt() > 150 && Photons[tight_photons[i]].Pt() < 200) {
				Fill("h_photon_charged_iso_200",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_200", 0.);
						 } else {
						Fill("h_photon_neutral_iso_200",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_200", 0.);
						 } else {
						Fill("h_photon_photon_iso_200",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}	
				}
										
		 if (Photons[tight_photons[i]].Pt() > 200 && Photons[tight_photons[i]].Pt() < 400) {
				Fill("h_photon_charged_iso_400",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_400", 0.);
						 } else {
						Fill("h_photon_neutral_iso_400",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_400", 0.);
						 } else {
						Fill("h_photon_photon_iso_400",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}		
			}					
		 if (Photons[tight_photons[i]].Pt() > 400) {
				Fill("h_photon_charged_iso_inf",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_inf", 0.);
						 } else {
						Fill("h_photon_neutral_iso_inf",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_inf", 0.);
						 } else {
						Fill("h_photon_photon_iso_inf",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}	
				}								
		 }			
   for (unsigned int i = 0; i < tight_photons.size(); i++) {
	 	Fill("h_tight_photons_pt_cut_flow", Photons[tight_photons[i]].Pt());
		 if (Photons[tight_photons[i]].Pt() > 40) {
		 		cut_photons.push_back(tight_photons[i]);
				}
		 }	
	 
	 if (cut_photons.size() == 0){
		pdfTree->Fill();
		return kFALSE;
	}
	 
	 Fill("h_cutflow", "tight #gamma p_{T} > 40 GeV");




	 
	 	 
   for (unsigned int i = 0; i < cut_photons.size(); i++) {
		 if (Photons[cut_photons[i]].r9 > 0.9) {
		 		cut_r9_photons.push_back(cut_photons[i]);
				}
		 }	 
	 
	 if (cut_r9_photons.size() == 0){
		pdfTree->Fill();
		return kFALSE;
	}
	 
	 Fill("h_cutflow", "r9 > 0.9");	 
	 
   for (unsigned int i = 0; i < cut_r9_photons.size(); i++) {
		 if (fabs(Photons[cut_r9_photons[i]].Eta()) < 1.4442) {
		 		cut_EB_photons.push_back(cut_r9_photons[i]);
				}
		 }
		 
	 if (cut_EB_photons.size() == 0){
		pdfTree->Fill();
		return kFALSE;
	}
	 
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
				
	if (DeltaR < 0.5 ){
		pdfTree->Fill();
		return kFALSE;
	}
	Fill("h_cutflow","#Delta(R)(1st #gamma, n. jet) > 0.5");
		
	
		
	 double HT = 0;  /* Defined as usually -> Must be modified if using corrected HT */		
	 double HT2 = 0;	
	 double HT3 = 0;
	 		
	 for (unsigned int i = 0; i < loose_jets.size(); i++) { 
	  if ( Jets[i].IsLooseIsolated() ) {
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
		 }
		 
		 		
		
	if ( tight_photons.size() > 1 ) {	 
	 for (unsigned int i = 0; i < loose_jets.size(); i++) { 
	 	 DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
		 if (	Jets[loose_jets[i]].Pt() > 30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 )) && (fabs(Jets[loose_jets[i]].Eta() ) < 2.5 ) ) {
       HT2 += Jets[loose_jets[i]].Pt(); 
       }	
		 }	
		Fill("h_HT2",HT2);
		}	
		
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) { 
     HT += Jets[cleaned_jets[i]].Pt(); 
		 }
		 
		Fill("h_HT_raw",HT);		
		Fill("h_pt_raw",Photons[tight_photons[0]].Pt());		
		
		
	if( HT < 100 ) {
		pdfTree->Fill();
		return kFALSE;
	}
	Fill("h_cutflow","H_{T} > 100 GeV");	
		
	  double TransMassCheck = TMath::Sqrt(2*Photons[tight_photons[0]].Pt()*MET.Pt()*(1.- TMath::Cos(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi()))));	
				
		Fill2("h2_met_sign_trans_mass",met_pfMet_significance,TransMassCheck);
				
	 double sum_photon_pt_before = 0;
	 for (unsigned int i = 0; i < loose_photons.size(); i++) {
			sum_photon_pt_before += Photons[loose_photons[i]].Pt();
			} 
	 double sum_signal_before = sum_photon_pt_before + MET.Pt();
	 double sum_signal_before_TypeOne = sum_photon_pt_before + TypeOneMET.Pt();	 
	 
		Fill2("h2_met_sign_sigma",met_pfMet_significance,sum_signal_before);	
			 		
		if (TransMassCheck < 250 && met_pfMet_significance > 20){
		  Fill("h_pt_dep_1", Photons[tight_photons[0]].Pt());
			Fill("h_METoverSqHT_double_control_250", MET.Pt()/(TMath::Sqrt(HT)));				
		  }
		if (TransMassCheck < 200 && met_pfMet_significance > 20){
			Fill("h_METoverSqHT_double_control_200", MET.Pt()/(TMath::Sqrt(HT)));	
		  }			
		if (TransMassCheck < 150 && met_pfMet_significance > 20){
			Fill("h_METoverSqHT_double_control_150", MET.Pt()/(TMath::Sqrt(HT)));	
		  }			
				
		if (TransMassCheck < 300 && met_pfMet_significance > 10){
		  Fill("h_pt_dep_2", Photons[tight_photons[0]].Pt());
			Fill("h_METoverSqHT_double_control_10", MET.Pt()/(TMath::Sqrt(HT)));			
		  }			
		if (TransMassCheck < 300 && met_pfMet_significance > 15){
		  Fill("h_pt_dep_3", Photons[tight_photons[0]].Pt());
			Fill("h_METoverSqHT_double_control_15", MET.Pt()/(TMath::Sqrt(HT)));			
		  }		
		if (TransMassCheck < 300 && met_pfMet_significance > 20){
		  Fill("h_pt_dep_4", Photons[tight_photons[0]].Pt());	
			Fill("h_METoverSqHT_double_control_20", MET.Pt()/(TMath::Sqrt(HT)));
		  }
			
		if (TransMassCheck < 300 && met_pfMet_significance < 20){
			Fill("h_METoverSqHT_double_control_20_2", MET.Pt()/(TMath::Sqrt(HT)));
		  }		
				
		if (TransMassCheck > 300 && met_pfMet_significance < 20){
			Fill("h_METoverSqHT_double_control_20_3", MET.Pt()/(TMath::Sqrt(HT)));
		  }				
		if (TransMassCheck < 300 && met_pfMet_significance > 30){
			Fill("h_METoverSqHT_double_control_30", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
			
		if ( (TransMassCheck < 300 && met_pfMet_significance > 20) || (TransMassCheck > 300 && met_pfMet_significance < 20) || (TransMassCheck < 300 && met_pfMet_significance < 20) ){
			Fill("h_METoverSqHT_double_control_3_regions_20", MET.Pt()/(TMath::Sqrt(HT)));
		  }				
		if ( (TransMassCheck < 300 && met_pfMet_significance > 25) || (TransMassCheck > 300 && met_pfMet_significance < 25) || (TransMassCheck < 300 &&
		met_pfMet_significance < 25) ){
			Fill("h_METoverSqHT_double_control_3_regions_25", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( (TransMassCheck < 300 && met_pfMet_significance > 30) || (TransMassCheck > 300 && met_pfMet_significance < 30) || (TransMassCheck < 300 &&
		met_pfMet_significance < 30) ){
			Fill("h_METoverSqHT_double_control_3_regions_30", MET.Pt()/(TMath::Sqrt(HT)));
		  }								
		if ( (TransMassCheck < 300 && met_pfMet_significance > 35) || (TransMassCheck > 300 && met_pfMet_significance < 35) || (TransMassCheck < 300 &&
		met_pfMet_significance < 35) ){
			Fill("h_METoverSqHT_double_control_3_regions_35", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( (TransMassCheck < 300 && met_pfMet_significance > 40) || (TransMassCheck > 300 && met_pfMet_significance < 40) || (TransMassCheck < 300 &&
		met_pfMet_significance < 40) ){
			Fill("h_METoverSqHT_double_control_3_regions_40", MET.Pt()/(TMath::Sqrt(HT)));
		  }				
		if ( (TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50) ){
			Fill("h_METoverSqHT_double_control_3_regions_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( (TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 && met_pfMet_significance < 60) || (TransMassCheck < 300 &&
		met_pfMet_significance < 60) ){
			Fill("h_METoverSqHT_double_control_3_regions_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
		if ( (TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 && met_pfMet_significance < 70) || (TransMassCheck < 300 &&
		met_pfMet_significance < 70) ){
			Fill("h_METoverSqHT_double_control_3_regions_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( (TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 && met_pfMet_significance < 80) || (TransMassCheck < 300 &&
		met_pfMet_significance < 80) ){
			Fill("h_METoverSqHT_double_control_3_regions_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
			
					
			
								 	
		if ( (TransMassCheck < 200 && met_pfMet_significance > 30) || (TransMassCheck > 200 && met_pfMet_significance < 30) || (TransMassCheck < 200 &&
		met_pfMet_significance < 30) ){
			Fill("h_METoverSqHT_double_control_3_regions_30_200", MET.Pt()/(TMath::Sqrt(HT)));
		  }	



		if ( met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_10_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 &&	met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_10_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
		if ( met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_10_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_10_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }
			
		if ( met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_20_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 &&	met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_20_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
		if ( met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_20_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_20_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }


		if ( TransMassCheck > 50 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_10_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( TransMassCheck > 50 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 &&	met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_10_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
		if ( TransMassCheck > 50 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_10_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( TransMassCheck > 50 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_10_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }
			
			
		if ( TransMassCheck > 50 && met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 &&	met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_20_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
		if ( TransMassCheck > 50 && met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_20_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( TransMassCheck > 50 && met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_20_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
						
			
			
			
		if ( TransMassCheck > 100 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_10_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( TransMassCheck > 100 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 && met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_10_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }
		if ( TransMassCheck > 100 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_10_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }
		if ( TransMassCheck > 100 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_10_80", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_double_control_3_regions_100_10_80_16", MET.Pt()/(TMath::Sqrt(HT)));			
		  }
			
		if ( TransMassCheck > 100 && ((TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_0_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( TransMassCheck > 100 && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 && met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_0_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }
		if ( TransMassCheck > 100 && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_0_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }
		if ( TransMassCheck > 100 && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_0_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }
				



			
		if ( (met_pfMet_significance > 20) &&  (met_pfMet_significance < 60) ){
			Fill("h_METoverSqHT_double_control_20_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
				
		if ( (met_pfMet_significance > 10) &&  (met_pfMet_significance < 60) ){
			Fill("h_METoverSqHT_double_control_10_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
							
		if ( (met_pfMet_significance > 10) &&  (met_pfMet_significance < 80) ){
			Fill("h_METoverSqHT_double_control_10_80", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_MET_significance_metsig_sideband",TransMassCheck);
		  }	
		if ( ( TransMassCheck > 100) &&  ( TransMassCheck < 300) ){
			Fill("h_METoverSqHT_double_control_100_300", MET.Pt()/(TMath::Sqrt(HT)));
			FillPerGev("h_MET_significance_MT_sideband",met_pfMet_significance);
			Fill("h_MET_significance_MT_sideband_2",met_pfMet_significance);			
		  }				
						
						
		if (TransMassCheck < 300){
		  Fill("h_METoverSqHT_trans_mass_control", MET.Pt()/(TMath::Sqrt(HT)));
		  Fill("h_photon_pt_trans_mass_control", Photons[tight_photons[0]].Pt());
		  }
		if (TransMassCheck > 300){
		  Fill("h_photon_pt_trans_mass_signal", Photons[tight_photons[0]].Pt());
		  }			
		if ( met_pfMet_significance < 60 ) {
		  Fill("h_METoverSqHT_met_sign_control", MET.Pt()/(TMath::Sqrt(HT)));	
		  Fill("h_photon_pt_met_sign_control", Photons[tight_photons[0]].Pt());		  
			}		
		if ( met_pfMet_significance > 60 ) {
		  Fill("h_photon_pt_met_sign_signal", Photons[tight_photons[0]].Pt());	
		  }	
			
			
		Fill("h_HT_array_HT_cut",HT);		
	  Fill("h_1tightPhotonPtOverMET_scale_HT_cut",Photons[tight_photons[0]].Pt()/MET.Pt());	
	  Fill("h_METoverSqHT_scale_HT_cut", MET.Pt()/(TMath::Sqrt(HT)));
		double AngleMJ1_scale = -1;
	  double InvMassJets_scale = -1;
		if ( cleaned_jets.size() > 0){			 
			 AngleMJ1_scale = DeltaPhi(MET.Phi(),Jets[cleaned_jets[0]].Phi() );
			 if (cleaned_jets.size() > 1){	
		   	TLorentzVector vJ_s = Jets[cleaned_jets[0]] + Jets[cleaned_jets[1]];
	     	InvMassJets_scale = vJ_s.M();
			 	}
			 }	 
			 				
	  if ( Photons[tight_photons[0]].Pt() < 100 ) {
			Fill("h_HT_array_pt_cut",HT);
			Fill("h_HT_array_100_41",HT);	
			Fill("h_MET_significance_100_39",met_pfMet_significance);
			Fill("h_MET_significance_100_23",met_pfMet_significance);								
			Fill("h_1tightPhotonPtOverMET_scale_pt_cut",Photons[tight_photons[0]].Pt()/MET.Pt());	 
			Fill("h_METoverSqHT_100_36", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_100_30", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_100_24", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_100_17", MET.Pt()/(TMath::Sqrt(HT)));	
			Fill("h_METoverSqHT_100_12", MET.Pt()/(TMath::Sqrt(HT)));						
			Fill("h_met_orth",MET.Pt());
			Fill("h_pt_orth",Photons[tight_photons[0]].Pt());
			Fill("h_MET_significance_scale",met_pfMet_significance);	
			Fill("h_MET_over_PT_100",MET.Pt()/Photons[tight_photons[0]].Pt());	
			Fill("h_Angle_MET_1jet_100",AngleMJ1_scale);				
			Fill("h_InvMass_2jets_100", InvMassJets_scale);									 
			}
		// Variation of control region
	  if ( Photons[tight_photons[0]].Pt() < 110 ) {
			Fill("h_HT_array_110",HT); 
			Fill("h_HT_array_110_41",HT);	
			Fill("h_MET_significance_110_39",met_pfMet_significance);
			Fill("h_MET_significance_110_23",met_pfMet_significance);			
			Fill("h_METoverSqHT_110_36", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_110_30", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_110_24", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_110_17", MET.Pt()/(TMath::Sqrt(HT)));		
			Fill("h_METoverSqHT_110_12", MET.Pt()/(TMath::Sqrt(HT)));					
			Fill("h_met_110",MET.Pt());
			Fill("h_pt_110",Photons[tight_photons[0]].Pt());				
			Fill("h_MET_significance_110",met_pfMet_significance);
			Fill("h_MET_over_PT_110",MET.Pt()/Photons[tight_photons[0]].Pt());	
			Fill("h_Angle_MET_1jet_110",AngleMJ1_scale);				
			Fill("h_InvMass_2jets_110", InvMassJets_scale);							 
			}			
	  if ( Photons[tight_photons[0]].Pt() < 90 ) {
			Fill("h_HT_array_90",HT); 
			Fill("h_HT_array_90_41",HT);	
			Fill("h_MET_significance_90_39",met_pfMet_significance);
			Fill("h_MET_significance_90_23",met_pfMet_significance);			
			Fill("h_METoverSqHT_90_36", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_90_30", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_90_24", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_90_17", MET.Pt()/(TMath::Sqrt(HT)));	
			Fill("h_METoverSqHT_90_12", MET.Pt()/(TMath::Sqrt(HT)));						
			Fill("h_met_90",MET.Pt());
			Fill("h_pt_90",Photons[tight_photons[0]].Pt());				
			Fill("h_MET_significance_90",met_pfMet_significance);	
			Fill("h_MET_over_PT_90",MET.Pt()/Photons[tight_photons[0]].Pt());	
			Fill("h_Angle_MET_1jet_90",AngleMJ1_scale);				
			Fill("h_InvMass_2jets_90", InvMassJets_scale);						 
			}			
	  if ( Photons[tight_photons[0]].Pt() < 120 ) {
			Fill("h_HT_array_120",HT); 
			Fill("h_HT_array_120_41",HT);	
			Fill("h_MET_significance_120_39",met_pfMet_significance);
			Fill("h_MET_significance_120_23",met_pfMet_significance);			
			Fill("h_METoverSqHT_120_36", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_120_30", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_120_24", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_120_17", MET.Pt()/(TMath::Sqrt(HT)));	
			Fill("h_METoverSqHT_120_12", MET.Pt()/(TMath::Sqrt(HT)));						
			Fill("h_met_120",MET.Pt());
			Fill("h_pt_120",Photons[tight_photons[0]].Pt());				
			Fill("h_MET_significance_120",met_pfMet_significance);
			Fill("h_MET_over_PT_120",MET.Pt()/Photons[tight_photons[0]].Pt());	
			Fill("h_Angle_MET_1jet_120",AngleMJ1_scale);				
			Fill("h_InvMass_2jets_120", InvMassJets_scale);							 
			}			
	  if ( Photons[tight_photons[0]].Pt() < 80 ) {
			Fill("h_HT_array_80",HT); 
			Fill("h_HT_array_80_41",HT);	
			Fill("h_MET_significance_80_39",met_pfMet_significance);
			Fill("h_MET_significance_80_23",met_pfMet_significance);			
			Fill("h_METoverSqHT_80_36", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_80_30", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_80_24", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_80_17", MET.Pt()/(TMath::Sqrt(HT)));	
			Fill("h_METoverSqHT_80_12", MET.Pt()/(TMath::Sqrt(HT)));						
			Fill("h_met_80",MET.Pt());
			Fill("h_pt_80",Photons[tight_photons[0]].Pt());				
			Fill("h_MET_significance_80",met_pfMet_significance);	
			Fill("h_MET_over_PT_80",MET.Pt()/Photons[tight_photons[0]].Pt());	
			Fill("h_Angle_MET_1jet_80",AngleMJ1_scale);				
			Fill("h_InvMass_2jets_80", InvMassJets_scale);						 
			}	
								
	 if (TransMassCheck < 100 || met_pfMet_significance < 10) {
		pdfTree->Fill();
		return kFALSE;
	}
	 
	 Fill("h_cutflow","CR + SR");	 
	 
	double HT_hlt_hadronic = 0;
	for (unsigned int i = 0; i < Jets.size(); i++) {
		if (Jets[i].Pt() > 40 && fabs(Jets[i].Eta()) < 3.0){
			 HT_hlt_hadronic += Jets[i].Pt();
//			cout << "jet pt:  " << Jets[i].Pt() << "  fabs jet eta:   " << fabs(Jets[i].Eta()) << endl;
			}
	 	}
	 
	 
	 	Fill("h_tight_photon_pt_before", Photons[tight_photons[0]].Pt());
	  FillMETsign("h_MET_significance_array_norm_before",met_pfMet_significance); 		
	  FillPerGev("h_MET_significance_per_gev_14_before",met_pfMet_significance);	
		Fill("h_trans_mass_pt_before", TransMassCheck);
		FillPerGev("h_trans_mass_pt_before_per_gev", TransMassCheck);		
		Fill("h_met_significance_before", met_pfMet_significance);		
	  Fill("h_sum_signal_over_sqrt_met_before",sum_signal_before/sqrt(MET.Pt()) );					
	  Fill("h_n_photon_loose_before",loose_photons.size());	
	  Fill("h_n_photon_tight_before",tight_photons.size());			
	  Fill("h_n_jets_cleaned_before",cleaned_jets.size());
		if ( cleaned_jets.size() > 0 ) { Fill("h_jet_pt_before", Jets[cleaned_jets[0]].Pt());}
	  Fill("h_HT_before",HT);
	  Fill("h_hlt_HT_before",HT_hlt_hadronic);		
	  FillPerGev("h_HT_before_per_gev",HT);		
	 	FillPerGev("h_tight_photon_pt_before_per_gev", Photons[tight_photons[0]].Pt());				
		Fill("h_met_before",MET.Pt()); 		
		
		Fill("h_TypeOneMet_before",TypeOneMET.Pt()); 		
	  Fill("h_ST_before",sum_signal_before);		  
		Fill("h_ST_TypeOne_before",sum_signal_before_TypeOne);	 
	 
	 
	 
	 
	 
	 if ( TransMassCheck > 100 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
	  Fill("h_tight_photon_pt_CR", Photons[tight_photons[0]].Pt());
	  FillMETsign("h_MET_significance_array_norm_CR",met_pfMet_significance);
	  Fill("h_MET_significance_array_CR",met_pfMet_significance);
	  Fill("h_MET_significance_array_CR_13",met_pfMet_significance);	
					 		
	  FillPerGev("h_MET_significance_per_gev_14_CR",met_pfMet_significance);	
  	  Fill("h_trans_mass_pt_CR", TransMassCheck);
	  Fill("h_met_significance_CR", met_pfMet_significance);		
	  Fill("h_sum_signal_over_sqrt_met_CR",sum_signal_before/sqrt(MET.Pt()) );				
	  Fill("h_n_photon_loose_CR",loose_photons.size());	
	  Fill("h_n_photon_tight_CR",tight_photons.size());			
	  Fill("h_n_jets_cleaned_CR",cleaned_jets.size());
		if ( cleaned_jets.size() > 0 ) { Fill("h_jet_pt_CR", Jets[cleaned_jets[0]].Pt());}
	  Fill("h_HT_CR",HT);
		Fill("h_met_CR",MET.Pt()); 	
		
		Fill("h_TypeOneMet_CR",TypeOneMET.Pt()); 		
	  Fill("h_ST_CR",sum_signal_before);
	  Fill("h_ST_TypeOne_CR",sum_signal_before_TypeOne);	
			 
		double AngleMJ1_CR = -1;
	  double InvMassJets_CR = -1;				
		if ( cleaned_jets.size() > 0){			 
			 AngleMJ1_CR = DeltaPhi(MET.Phi(),Jets[cleaned_jets[0]].Phi() );
			 if (cleaned_jets.size() > 1){	
		   	TLorentzVector vJ_CR = Jets[cleaned_jets[0]] + Jets[cleaned_jets[1]];
	     	InvMassJets_CR = vJ_CR.M();
			 	}
			 }
			 Fill("h_InvMass_2jets_CR", InvMassJets_CR);	
			 Fill("h_Angle_MJ1_CR", AngleMJ1_CR); 
	 	 }	 
	 	
	 

	 if (TransMassCheck < 300 || met_pfMet_significance < 80){
		pdfTree->Fill();
		return kFALSE;
	}
	 
	 Fill("h_cutflow","SR");
	 	
	
	
	Fill2("h2_met_sign_sigma_SR",met_pfMet_significance,sum_signal_before);	 
	 
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
	 Fill("h_n_muons_loose",loose_muons.size());
	 Fill("h_n_muons_soft",soft_muons.size());
	 	 		
	 Fill("h_Phi_MET", fabs(MET.Phi()));	 
	 Fill("h_METoverSqHT", MET.Pt()/(TMath::Sqrt(HT)));
   if ( Pixel.compare(BGName) == 0 ) {
	   Fill("h_METoverSqHT_blind", MET.Pt()/(TMath::Sqrt(HT)));
		}
	 else { 	 
	  if ( MET.Pt()/(TMath::Sqrt(HT)) < 12 ) {
	    Fill("h_METoverSqHT_blind", MET.Pt()/(TMath::Sqrt(HT)));
	 		}
		}	 
	 
	 Fill("h_METoverSqHT_scale", MET.Pt()/(TMath::Sqrt(HT)));	 
	 if (HT > 100) Fill("h_METoverSqHT_scale_HT", MET.Pt()/(TMath::Sqrt(HT)));	 
	 FillArraySignificance("h_METoverSqHT_array", MET.Pt()/(TMath::Sqrt(HT)));	 
	 Fill("h_HToverMET", HT/MET.Pt());
	 Fill("h_MET_significance",met_pfMet_significance);	 
	 Fill("h_MET_significance_corrected",met_pfType1CorrectedMet_significance);	
	 Fill("h_MET_significance_array",met_pfMet_significance);	 
	 FillMETsign("h_MET_significance_array_norm",met_pfMet_significance);	 
	 FillPerGev("h_MET_significance_per_gev_10",met_pfMet_significance);
	 FillPerGev("h_MET_significance_per_gev_14",met_pfMet_significance); 	
	 FillPerGev("h_MET_significance_per_gev_23",met_pfMet_significance);	 
	 FillPerGev("h_MET_significance_per_gev_32",met_pfMet_significance);
   if ( Pixel.compare(BGName) == 0 ) {
	 	FillPerGev("h_MET_significance_per_gev_10_blind",met_pfMet_significance);
	 	FillPerGev("h_MET_significance_per_gev_14_blind",met_pfMet_significance);			
	 	FillPerGev("h_MET_significance_per_gev_23_blind",met_pfMet_significance);	 
	 	FillPerGev("h_MET_significance_per_gev_32_blind",met_pfMet_significance);	
		}
	 else { 	 
	  if ( met_pfMet_significance < 60 ) {
	 		FillPerGev("h_MET_significance_per_gev_10_blind",met_pfMet_significance);
	 		FillPerGev("h_MET_significance_per_gev_14_blind",met_pfMet_significance);			
	 		FillPerGev("h_MET_significance_per_gev_23_blind",met_pfMet_significance);	 
	 		FillPerGev("h_MET_significance_per_gev_32_blind",met_pfMet_significance);	 
	 		}
		}	
	 
	  	 
		double AngleGM = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));
	  Fill("h_DeltaPhi_photon_MET",	AngleGM);	  
	 
	 double sum_pt = 0;
	 double sum_p = 0.000000001;
	 double sum_photon_pt = 0;
	 double sum_photon_p = 0.000000001;
	 	 
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
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
	 double sum_signal_TypeOne = sum_photon_pt + TypeOneMET.Pt(); 
	 Fill("h_sum_signal",sum_signal);
	 Fill("h_ST_TypeOne",sum_signal_TypeOne);	 
	 FillPerGev("h_sum_signal_per_gev",sum_signal);	 
	 
	 Fill2("h2_sigma_metsign",(sum_signal/(TMath::Sqrt(MET.Pt()))), met_pfMet_significance);	 
	 Fill2("h2_sigma_met",sum_signal/(TMath::Sqrt(MET.Pt())), MET.Pt());	 
	 
	 
	 for (unsigned int i = 0; i < tight_photons.size(); i++) { // Variablen MyPhoton �bergeben und dann abrufen -> Index-Zuordnung
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
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {	 
	   Fill("h_bTagDisc",Jets[cleaned_jets[i]].bTagDisc);
		 if (Jets[cleaned_jets[i]].bTagDisc > 0.5 ) {
		 		b_jets.push_back(i);
		    }	
	   Fill("h_bTagDisc",Jets[cleaned_jets[i]].bTagDisc);
		 if (Jets[cleaned_jets[i]].bTagDisc > -0.5 ) {
		 		b_jets2.push_back(i);
		    }						 
	   Fill("h_n_bJets",b_jets.size());
	   Fill("h_n_bJets2",b_jets2.size());		 
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
	 unsigned int indexi = 0;
	 unsigned int indexj = 0; 
	if ( cleaned_jets.size() > 1 ) {
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
	 	 EtaTest = fabs(Jets[cleaned_jets[i]].Eta());
		 if (EtaTest < EtaLow){
				EtaLow = EtaTest;
				indexi = i;
				}
	   }
	 for (unsigned int j = 0; j < cleaned_jets.size(); j++) {
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
	 
	 if (Photons[tight_photons[0]].Pt() > 100 ){
	   Fill("h_trans_mass_MET_Gamma_100",TransMassMETGamma);
	 	}
		
		
  if ( Pixel.compare(BGName) == 0 ) {
	 	Fill("h_trans_mass_MET_Gamma_blind",TransMassMETGamma);
		}
	 else { 	 
	  if ( TransMassMETGamma < 300 ) {
		 	Fill("h_trans_mass_MET_Gamma_blind",TransMassMETGamma);	 
	 		}
		}
		
		
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
	 Fill("h_tight_1photons_pt", Photons[tight_photons[0]].Pt() );	


 // For e->gamma fake rate estimated from data
 
 Fill("h_HT_array_datadriven",HT); 
 Fill("h_met_datadriven",MET.Pt());
 Fill("h_inverse_met_datadriven",1./MET.Pt()); 
 Fill("h_tight_photon_pt_datadriven",Photons[tight_photons[0]].Pt());   
 		
 
	 Fill2("h2_n_photon_pixel_met",pixel_photons.size(),MET.Pt());
	 Fill2("h2_n_jets_met",cleaned_jets.size(),MET.Pt()); 
	 
   for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
	 	
	 		Fill("h_cleaned_jets_pt", Jets[cleaned_jets[i]].Pt() );
			Fill("h_cleaned_jets_chargedHE", Jets[cleaned_jets[i]].chargedHadronEnergy );
			double frac = ( Jets[cleaned_jets[i]].chargedHadronEnergy / Jets[cleaned_jets[i]].JetE );
			Fill("h_cleaned_jets_chargedfrac", frac );
			Fill("h_cleaned_jets_chargedM", Jets[cleaned_jets[i]].chargedMultiplicity );

		}
	 for (unsigned int i = 0; i < photon_matched_jets.size(); i++) {	 	 
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
	 Fill("h_TypeOneMet",TypeOneMET.Pt());	 
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
	 	 
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) { 
			 double AngleMJ = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[i]].Phi() ));
       Fill("h_AngleMJ", AngleMJ);
			 Fill("h_Eta_Jet", Jets[loose_jets[i]].Eta()); 
			 Fill2("h_corrMETJet",MET.Phi() ,Jets[loose_jets[i]].Phi() );
		//	 cout << MET.Phi() << "............." << Jets[loose_jets[i]].Phi() << endl;
		   }
	
	 double AngleMJ1 = 0;
	 double AngleMJ2 = 0;
	 double AngleMJ3 = 0;			 
	 if ( cleaned_jets.size() > 0){			 
			 AngleMJ1 = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[0]].Phi() ));
       Fill("h_AngleMJ1", AngleMJ1);
			 }
	 if ( cleaned_jets.size() > 1){			 
			 AngleMJ2 = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[1]].Phi() ));
       Fill("h_AngleMJ2", AngleMJ2);
			 }			 
	 if ( cleaned_jets.size() > 2){			 
			 AngleMJ3 = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[2]].Phi() ));
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
	 Fill("h_METoverPhotonPt", MET.Pt()/Photons[tight_photons[0]].Pt());
	 Fill("h_1tightPhotonPtOverMET", Photons[tight_photons[0]].Pt()/MET.Pt());	 
	 Fill("h_1tightPhotonPtOverMET_scale",Photons[tight_photons[0]].Pt()/MET.Pt());
	 Fill("h_photon_seedTime", Photons[tight_photons[0]].photon_seedtime);
	 Fill("h_photon_pt_significance",Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)));
	 Fill("h_photon_pt_met_significance",Photons[tight_photons[0]].Pt()/(TMath::Sqrt(MET.Pt())));	 
	 Fill("h_sum_signal_over_sqHT",sum_signal/(TMath::Sqrt(HT)));	
	 Fill("h_sum_signal_over_sqMET",sum_signal/(TMath::Sqrt(MET.Pt())));
	 Fill("h_sum_signal_over_MET",sum_signal/MET.Pt());	 		 	 	 
	 if (HT > 100 ) {
		 Fill("h_met_cut",MET.Pt());	 
		 Fill("h_loose_1photons_pt_cut", Photons[loose_photons[0]].Pt() );	 
		 Fill("h_n_photon_loose_cut",loose_photons.size());	
		 Fill("h_inverse_MET_cut",1./MET.Pt()); 
	 }
	 	 

// Check dependency of n Vertex  -> difference in trigger efficiency
	 
	if (met_pfMet_significance < 20){
		Fill("h_vert_20",vertices_n);
		}
	else if (met_pfMet_significance < 40){
		Fill("h_vert_40",vertices_n);		
		}
	else if (met_pfMet_significance < 60){
		Fill("h_vert_60",vertices_n);		
		}		
	else if (met_pfMet_significance < 80){
		Fill("h_vert_80",vertices_n);		
		}	
	else if (met_pfMet_significance < 100){
		Fill("h_vert_100",vertices_n);		
		}			
	else if (met_pfMet_significance < 150){
		Fill("h_vert_150",vertices_n);		
		}		
	else {
		Fill("h_vert_high",vertices_n);		
		}	

	if (MET.Pt() < 125){
		Fill("h_vert_met_125",vertices_n);
		}
	else if (MET.Pt() < 150){
		Fill("h_vert_met_150",vertices_n);		
		}
	else if (MET.Pt() < 200){
		Fill("h_vert_met_200",vertices_n);		
		}		
	else if ( MET.Pt()< 250){
		Fill("h_vert_met_250",vertices_n);		
		}
	else if (MET.Pt() < 350){
		Fill("h_vert_met_350",vertices_n);		
		}				
	else {
		Fill("h_vert_met_high",vertices_n);		
		}			
		

/*

		4 bins in 2D MEt significance and Sigma region
		
		
																										*/
																										
double Sigma = sum_signal/(TMath::Sqrt(MET.Pt()));

if (met_pfMet_significance > 200 && Sigma > 30){
	Fill("h_upper_right_SR_HT", HT);
	Fill("h_upper_right_SR_n", loose_photons.size());
	Fill("h_upper_right_SR", Photons[tight_photons[0]].Pt() );	
  }
if (met_pfMet_significance < 200 && Sigma > 30){
	Fill("h_upper_left_SR_HT", HT);
	Fill("h_upper_left_SR_n", loose_photons.size());
	Fill("h_upper_left_SR", Photons[tight_photons[0]].Pt() );		
  }	
if (met_pfMet_significance > 200 && Sigma < 30){
	Fill("h_lower_right_SR_HT", HT);
	Fill("h_lower_right_SR_n", loose_photons.size());
	Fill("h_lower_right_SR", Photons[tight_photons[0]].Pt() );		
  }	
if (met_pfMet_significance < 200 && Sigma < 30){
	Fill("h_lower_left_SR_HT", HT);
	Fill("h_lower_left_SR_n", loose_photons.size());
	Fill("h_lower_left_SR", Photons[tight_photons[0]].Pt() );		
  }


double HT_hlt = 0;
double HT_photon_had = 0;

for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
	if (Jets[cleaned_jets[i]].Pt() > 30 && fabs(Jets[cleaned_jets[i]].Eta()) < 2.5){
		HT_photon_had += Jets[cleaned_jets[i]].Pt();		
		}
	}
for (unsigned int i = 0; i < loose_photons.size(); i++) {	
	if (Photons[loose_photons[i]].Pt() > 110 && fabs(Photons[loose_photons[i]].Eta()) < 1.4442){
		HT_photon_had += Photons[loose_photons[i]].Pt();		
		}
	}
	
 cout << "durchgekommen" << endl;	
	 
for (unsigned int i = 0; i < Jets.size(); i++) {
	if (Jets[i].Pt() > 40 && fabs(Jets[i].Eta()) < 3.0){
			HT_hlt += Jets[i].Pt();
//			cout << "jet pt:  " << Jets[i].Pt() << "  fabs jet eta:   " << fabs(Jets[i].Eta()) << endl;
			}
	 }	 
//cout << "HT_hlt:   " << HT_hlt << endl;
//cout << "HT:   " << HT << endl;


// Search bins with sum_signal
if (met_pfMet_significance > 200 && sum_signal > 600 ){
	pdf_selected = 1;
	Fill("h_upper_right_SR_sum_signal", Photons[tight_photons[0]].Pt() );
	Fill("h_upper_right_SR_ht", HT );	
	Fill("h_upper_right_SR_ht_trigger", HT_hlt );	
	Fill("h_upper_right_SR_ht_trigger_had", HT_photon_had );	
	if ( cleaned_jets.size() > 1 ) {
		Fill("h_upper_right_SR_ht_trigger_had_2", HT_photon_had );	
		}			
  if (PassPhotonHadTrigger() ) {
	Fill("h_upper_right_SR_ht_trigger_fired", HT_hlt );	
	}	
				
  }
if (met_pfMet_significance < 200 && sum_signal > 600 ){
	pdf_selected = 2;
	Fill("h_upper_left_SR_sum_signal", Photons[tight_photons[0]].Pt() );
	Fill("h_upper_left_SR_ht", HT );	
	Fill("h_upper_left_SR_ht_trigger", HT_hlt );
	Fill("h_upper_left_SR_ht_trigger_had", HT_photon_had );	
	if ( cleaned_jets.size() > 1 ) {
		Fill("h_upper_left_SR_ht_trigger_had_2", HT_photon_had );	
		}			
  if (PassPhotonHadTrigger() ) {
	Fill("h_upper_left_SR_ht_trigger_fired", HT_hlt );	
	}			
  }	
if (met_pfMet_significance > 200 && sum_signal < 600 ){
	pdf_selected = 4;		
	Fill("h_lower_right_SR_sum_signal", Photons[tight_photons[0]].Pt() );		
	Fill("h_lower_right_SR_ht", HT );	
	Fill("h_lower_right_SR_ht_trigger", HT_hlt );
	Fill("h_lower_right_SR_ht_trigger_had", HT_photon_had );	
	if ( cleaned_jets.size() > 1 ) {
		Fill("h_lower_right_SR_ht_trigger_had_2", HT_photon_had );	
		}			
  if (PassPhotonHadTrigger() ) {
	Fill("h_lower_right_SR_ht_trigger_fired", HT_hlt );	
	}			
  }	
if (met_pfMet_significance < 200 && sum_signal < 600 ){
	pdf_selected = 3;
	Fill("h_lower_left_SR_sum_signal", Photons[tight_photons[0]].Pt() );	
	Fill("h_lower_left_SR_ht", HT );
	Fill("h_lower_left_SR_ht_trigger", HT_hlt );
	Fill("h_lower_left_SR_ht_trigger_had", HT_photon_had );	
	if ( cleaned_jets.size() > 1 ) {
		Fill("h_lower_left_SR_ht_trigger_had_2", HT_photon_had );	
		}				
  if (PassPhotonHadTrigger() ) {
	Fill("h_lower_left_SR_ht_trigger_fired", HT_hlt );	
	}			
  }

	pdfTree->Fill();


// Search bins with MT
		
if (met_pfMet_significance > 200 && TransMassMETGamma > 500){
	Fill("h_upper_right_SR_MT", Photons[tight_photons[0]].Pt() );	
  }
if (met_pfMet_significance < 200 && TransMassMETGamma > 500){
	Fill("h_upper_left_SR_MT", Photons[tight_photons[0]].Pt() );		
  }	
if (met_pfMet_significance > 200 && TransMassMETGamma < 500){
	Fill("h_lower_right_SR_MT", Photons[tight_photons[0]].Pt() );		
  }	
if (met_pfMet_significance < 200 && TransMassMETGamma < 500){
	Fill("h_lower_left_SR_MT", Photons[tight_photons[0]].Pt() );		
  }				
	 
	/* Selection without HT splitting  */
	
	bool cut_trans_mass = (TransMassMETGamma > 350);  //if pt cut > 100, otherwise > 250
	
	bool cut_met_significance = (met_pfMet_significance > 150);
	
	bool cut_met_over_pt = ((MET.Pt()/Photons[tight_photons[0]].Pt()) > 1); //maybe reduces the right Vgamma
	
	bool cut_pt_over_HT = ((Photons[tight_photons[0]].Pt()/HT) > 0.6); //for several BGs
	
	bool cut_angle_met_1jet = (AngleMJ1 > 0.9); //especially for gammaJets if necessary
	
	bool cut_sum_signal = (sum_signal > 500); // maybe not useful after gamma pt > 100
	
	bool cut_n_jets = (cleaned_jets.size() < 3); 		// could work as undependent cut to pt & met-> looses signif. for higher
																									//mass splitting in signal
	
	bool cut_angle_photon_met = (AngleGM > 0.9);	//for several BGs

	bool cut_sum_signal_over_sq_met_25 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 25);	
	bool cut_sum_signal_over_sq_met_26 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 26);
	bool cut_sum_signal_over_sq_met_27 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 27); 	
	bool cut_sum_signal_over_sq_met_28 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 28);	
	bool cut_sum_signal_over_sq_met_29 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 29);
	bool cut_sum_signal_over_sq_met_30 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 30); 
	bool cut_sum_signal_over_sq_met_31 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 31);
	bool cut_sum_signal_over_sq_met_32 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 32);
	bool cut_sum_signal_over_sq_met_33 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 33);
	bool cut_sum_signal_over_sq_met_34 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 34); 
	bool cut_sum_signal_over_sq_met_35 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 35);
	bool cut_sum_signal_over_sq_met_36 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 36);
	bool cut_sum_signal_over_sq_met_37 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 37);
	bool cut_sum_signal_over_sq_met_38 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 38); 
	bool cut_sum_signal_over_sq_met_39 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 39);
	bool cut_sum_signal_over_sq_met_40 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 40);	
		
	
	bool cut_pt_over_sq_HT_10 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)) > 10);	
	bool cut_pt_over_sq_HT_11 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)) > 11);	
	bool cut_pt_over_sq_HT_12 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)) > 12);	
	bool cut_pt_over_sq_HT_13 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)) > 13);	
	bool cut_pt_over_sq_HT_8 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)) > 8);	
	
	bool cut_n_loose_photons = (loose_photons.size() > 1);
	
	bool cut_n_tight_photons = (tight_photons.size() > 1);
	
	bool cut_n_loose_muons = (loose_muons.size() < 1);
				
	bool cut_n_soft_muons = (soft_muons.size() < 1);
	
	bool cut_n_electrons = (medium_electrons.size() < 1);	
	
	bool cut_photon_pt_120 = (Photons[tight_photons[0]].Pt() > 120);
	bool cut_photon_pt_140 = (Photons[tight_photons[0]].Pt() > 140);	
	bool cut_photon_pt_180 = (Photons[tight_photons[0]].Pt() > 180);	
	
	bool cut_sum_signal_sq_met = (sum_signal/(TMath::Sqrt(MET.Pt())) > 30);
	
	bool cut_sum_signal_sq_ht = (sum_signal/(TMath::Sqrt(HT)) > 24);	
	
	
//	if (cut_photon_pt) {	
		 Fill("h_stage1_met_significance",met_pfMet_significance);
		 Fill("h_stage1_met_over_pt",(MET.Pt()/Photons[tight_photons[0]].Pt()));	
		 Fill("h_stage1_pt_over_HT",(Photons[tight_photons[0]].Pt()/HT));
		 Fill("h_stage1_angle_met_1jet",AngleMJ1);
		 Fill("h_stage1_sum_signal",sum_signal);
		 Fill("h_stage1_n_jets",cleaned_jets.size());
		 Fill("h_stage1_angle_photon_met", AngleGM);
		 Fill("h_stage1_inverse_met",(1./MET.Pt()));	
		 Fill("h_stage1_jet_pt", Jets[cleaned_jets[0]].Pt()	); 
		 if(cut_angle_photon_met){
		 	Fill("h_stage2_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage2_met_significance",met_pfMet_significance);			
			}
		 if(cut_angle_met_1jet){
		 	Fill("h_stage3_inverse_met",(1./MET.Pt()));	
		 	Fill("h_stage3_met_significance",met_pfMet_significance);				 	
			}	
	   if(cut_met_over_pt){
		 	Fill("h_stage4_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage4_met_significance",met_pfMet_significance);	
		 	Fill("h_stage4_N-1_pt_over_HT",(Photons[tight_photons[0]].Pt()/HT));						
			}
		 if(cut_pt_over_HT){
		 	Fill("h_stage5_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage5_met_significance",met_pfMet_significance);		
		 	Fill("h_stage5_N-1_met_over_pt",(MET.Pt()/Photons[tight_photons[0]].Pt()));					
			}	
		 if(cut_n_jets){
		 	Fill("h_stage6_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage6_met_significance",met_pfMet_significance);			
			}		
		 if(cut_sum_signal){
		 	Fill("h_stage7_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage7_met_significance",met_pfMet_significance);			
			}	
		 if(cut_met_significance){
		 	Fill("h_stage8_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage8_met_significance",met_pfMet_significance);			
			}
		 if(cut_trans_mass){
		 	Fill("h_stage9_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage9_met_significance",met_pfMet_significance);			
			}
		
		 if(cut_sum_signal_over_sq_met_25){
		 	Fill("h_stage10_met_significance_25",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_26){
		 	Fill("h_stage10_met_significance_26",met_pfMet_significance);			
			}
		 if(cut_sum_signal_over_sq_met_27){
		 	Fill("h_stage10_met_significance_27",met_pfMet_significance);			
			}				
		 if(cut_sum_signal_over_sq_met_28){
		 	Fill("h_stage10_met_significance_28",met_pfMet_significance);			
			}
		 if(cut_sum_signal_over_sq_met_29){
		 	Fill("h_stage10_met_significance_29",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_30){
		 	Fill("h_stage10_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage10_met_significance",met_pfMet_significance);			
			}						
		 if(cut_sum_signal_over_sq_met_31){
		 	Fill("h_stage10_met_significance_31",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_32){
		 	Fill("h_stage10_met_significance_32",met_pfMet_significance);
			FillPerGev("h_final_MET_significance_unblind",met_pfMet_significance);
		  Fill("h_final_n_loose_photons_unblind", loose_photons.size() );					
      if ( Pixel.compare(BGName) == 0 ) {
		    Fill("h_final_n_loose_photons_blind", loose_photons.size() );
				FillPerGev("h_final_MET_significance_blind",met_pfMet_significance);						
		    }
	    else { 	 
	    if ( loose_photons.size() < 2 ) {
		 	  Fill("h_final_n_loose_photons_blind",loose_photons.size());
				}	
	    if ( met_pfMet_significance < 60 ) {				
				FillPerGev("h_final_MET_significance_blind",met_pfMet_significance);
				}	
				
		   }
			}

		 if(cut_sum_signal_over_sq_met_33){
		 	Fill("h_stage10_met_significance_33",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_34){
		 	Fill("h_stage10_met_significance_34",met_pfMet_significance);			
			}				
		 if(cut_sum_signal_over_sq_met_35){
		 	Fill("h_stage10_met_significance_35",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_36){
		 	Fill("h_stage10_met_significance_36",met_pfMet_significance);			
			}	
		 if(cut_sum_signal_over_sq_met_37){
		 	Fill("h_stage10_met_significance_37",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_38){
		 	Fill("h_stage10_met_significance_38",met_pfMet_significance);			
			}				
		 if(cut_sum_signal_over_sq_met_39){
		 	Fill("h_stage10_met_significance_39",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_40){
		 	Fill("h_stage10_met_significance_40",met_pfMet_significance);			
			}							
					
			
		 if(cut_pt_over_sq_HT_10){
		 	Fill("h_stage11_met_significance_10",met_pfMet_significance);			
			}	
		 if(cut_pt_over_sq_HT_11){
		 	Fill("h_stage11_met_significance_11",met_pfMet_significance);			
			}			
		 if(cut_pt_over_sq_HT_12){
		 	Fill("h_stage11_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage11_met_significance",met_pfMet_significance);			
			}			
		 if(cut_pt_over_sq_HT_13){
		 	Fill("h_stage11_met_significance_13",met_pfMet_significance);			
			}						
		 if(cut_pt_over_sq_HT_8){
		 	Fill("h_stage11_met_significance_8",met_pfMet_significance);			
			}		
			
		 if(cut_n_loose_photons){
		 	Fill("h_stage12_met_significance",met_pfMet_significance);			
			}			
		 if(cut_n_tight_photons){
		 	Fill("h_stage13_met_significance",met_pfMet_significance);			
			}					
		 if(cut_n_loose_muons){
		 	Fill("h_stage14_met_significance",met_pfMet_significance);			
			}			
		 if(cut_n_soft_muons){
		 	Fill("h_stage15_met_significance",met_pfMet_significance);			
			}			
		 if(cut_n_electrons){
		 	Fill("h_stage16_met_significance",met_pfMet_significance);			
			}		
		 if(cut_photon_pt_180){
		 	Fill("h_stage17_met_significance",met_pfMet_significance);			
			}
		 if(cut_photon_pt_120){
		 	Fill("h_stage20_met_significance",met_pfMet_significance);			
			}			
		 if(cut_photon_pt_140){
		 	Fill("h_stage21_met_significance",met_pfMet_significance);			
			}	
					
		 if(cut_sum_signal_sq_met){
		 	Fill("h_stage18_met_significance",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_sq_ht){
		 	Fill("h_stage19_met_significance",met_pfMet_significance);			
			}		
					
		 if (cut_met_over_pt && cut_pt_over_HT){
		 	Fill("h_stage1_N-1_met_ratio_pt_ratio",met_pfMet_significance);			
			
		 	}	
		
	//	}
	
	
	
	 
 if (HT < 250) {
	
	 sum_pt = 0;
	 sum_p = 0.000000001;
	 sum_photon_pt = 0;
	 sum_photon_p = 0.000000001;
	 	 
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
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
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
	 	 EtaTest = fabs(Jets[cleaned_jets[i]].Eta());
		 if (EtaTest < EtaLow){
				EtaLow = EtaTest;
				indexi = i;
				}
	   }
	 for (unsigned int j = 0; j < cleaned_jets.size(); j++) {
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

	
	bool cut_jet_pt = true; //100; // (Jets[cleaned_jets[0]].Pt() > 100);
	bool cut_sum_pt = true; //(sum_pt > 350);
	bool cut_sum_signal = true; //(sum_signal > 450);	
	bool cut_m_t 		= (TransMassMETGamma > 300);
	
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
	 	 
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
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
			Fill("h_selection_high2_met_sign", met_pfMet_significance); 
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
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
	 	 EtaTest = fabs(Jets[cleaned_jets[i]].Eta());
		 if (EtaTest < EtaLow){
				EtaLow = EtaTest;
				indexi = i;
				}
	   }
	 for (unsigned int j = 0; j < cleaned_jets.size(); j++) {
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
	bool cut_ptOverHt		= true; //(sum_photon_pt/TMath::Sqrt(HT) > 0.5);
	// bool cut_HT_over_MET = (HT/MET.Pt() < 2);
	bool cut_MET_sig 		 = (MET.Pt()/(TMath::Sqrt(HT)) > 12);	
		
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
		Fill("h_N-1_sum_ptOverHt_high", sum_photon_pt/TMath::Sqrt(HT) );
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
 	 

/******************************* Data triggered by Signal trigger **************************/

	 #endif 
	 
/***************************************************************************************************************************/
/***************************************************************************************************************************/
/***************************************************************************************************************************/
/**********************************************--- MC ANALYSIS ---**********************************************************/
/***************************************************************************************************************************/	 
/***************************************************************************************************************************/	 
/***************************************************************************************************************************/	

#ifdef __MC	

	double HT_control = 0;
	if ( tight_photons.size() > 0 ) {
		  Fill("h_photon_pt_for_control", Photons[tight_photons[0]].Pt());	
	    for (unsigned int i = 0; i < loose_jets.size(); i++) { 
	 	    DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
		    if (	Jets[loose_jets[i]].Pt() > 30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 )) ) {
         HT_control += Jets[loose_jets[i]].Pt(); 		 
        }		
			} 
		  Fill("h_ht_for_control", HT_control);		
	}

	if ( tight_photons.size() > 0 ) {
			for (unsigned int i = 0; i < loose_jets.size(); i++) {
			  double angle_jet_gamma = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);		
			 	Fill2("h2_match_DeltaR_relPt_Photon_Jet",angle_jet_gamma ,(Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt());
			 	Fill2("h2_match_DeltaR_relPt2_Photon_Jet",angle_jet_gamma ,Jets[loose_jets[i]].Pt()/Photons[tight_photons[0]].Pt());				
				}
			}
	 
	 bool cut_met			  = (MET.Pt() > 100);
	  
	 if (cut_met && tight_photons.size() > 0 ){
   for (unsigned int i = 0; i < tight_photons.size(); i++) {
	   Fill("h_tight_photons_pt_cut_flow", Photons[tight_photons[i]].Pt());
		 if (Photons[tight_photons[i]].Pt() > 40) {
		 		cut_photons.push_back(tight_photons[i]);
				}
		 }		 
	 if (cut_photons.size() > 0) {
	 	 
   for (unsigned int i = 0; i < cut_photons.size(); i++) {
		 if (Photons[cut_photons[i]].r9 > 0.9) {
		 		cut_r9_photons.push_back(cut_photons[i]);
				}
		 }	 
	 
	 if (cut_r9_photons.size() > 0){ 
	 
   for (unsigned int i = 0; i < cut_r9_photons.size(); i++) {
		 if (fabs(Photons[cut_r9_photons[i]].Eta()) < 1.4442) {
		 		cut_EB_photons.push_back(cut_r9_photons[i]);
				}
		 }
		 
	 if (cut_EB_photons.size() > 0){ 
 
	 DeltaR1 = 0;	
	 DeltaR = 10;
	 DeltaR2 = 0;

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
	  if (DeltaR > 0.5 ){

	 double HT = 0;  /* Defined as usually -> Must be modified if using corrected HT */		
	 double HT3 = 0;
	 
//	 for (unsigned int i = 0; i < loose_jets.size(); i++) {	 
//	 cout << "jet eta before cleaned:    "  << Jets[loose_jets[i]].JetEta << endl;	 
//	 }
	 		
	 for (unsigned int i = 0; i < loose_jets.size(); i++) { 
	  if ( Jets[i].IsLooseIsolated() ) {
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
		}
		
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) { 
     HT += Jets[cleaned_jets[i]].Pt(); 
		 }
		 
//	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {	 
//	 cout << "jet eta after cleaned:    "  << Jets[cleaned_jets[i]].JetEta << endl;	 
//	 }	
	
		
 if( HT > 100 ){ 
	
 if (Photons[tight_photons[0]].Pt() > 40){ 

	for ( unsigned int i = 0; i < GenParticles.size() ; i++) {
	 		if (GenParticles[i].GenStatus == 1) {
					if (GenParticles[i].GenPDGID == 22 ) {
					Fill2("h2_truth_photon_DeltaR_relPt",GenParticles[i].DeltaR(Photons[tight_photons[0]]),((GenParticles[i].Pt()-Photons[tight_photons[0]].Pt())/GenParticles[i].Pt()));
							if ( GenParticles[i].DeltaR(Photons[tight_photons[0]]) < 0.1) {
							  Fill("h_truth_photons_pt_sel", GenParticles[i].Pt());
							  }
							}
					if ((GenParticles[i].GenPDGID == 11 || GenParticles[i].GenPDGID == -11)) {
							Fill("h_DR_gen_e_rec_gamma",GenParticles[i].DeltaR(Photons[tight_photons[0]]));
							Fill2("h2_truth_electron_DeltaR_relPt",GenParticles[i].DeltaR(Photons[tight_photons[0]]),((GenParticles[i].Pt()-Photons[tight_photons[0]].Pt())/GenParticles[i].Pt()));
							if(GenParticles[i].DeltaR(Photons[tight_photons[0]]) < 0.1 ) {
							  Fill("h_truth_electrons_pt_sel", GenParticles[i].Pt());
								Fill("h_truth_fake_met_sel",MET.Pt());
								Fill("h_truth_fake_met_significance_sel",met_pfMet_significance);								
							  Fill("h_truth_fake_inverse_met_sel",1./MET.Pt());
								Fill("h_truth_fake_tight_photon_pt_sel",Photons[tight_photons[0]].Pt());
								}		
							}
											
					}
		
			}
	
		}
		}		
		}
	}
	}		
	}		
	}

 
	// necessary to validate the e->gamma fake rate -> simulate the same cut stage
				
	
	 Fill("h_cutflow", "trigger");
	 
	 //check if QCd and GJets in analyzed phase space nearly equal
	 double HT_for_QCD = 0;
	 
	 if ( tight_photons.size() > 0 ) {
	 for (unsigned int i = 0; i < loose_jets.size(); i++) { 
	 	 DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
		 if (	Jets[loose_jets[i]].Pt() > 30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 )) ) {
       HT_for_QCD += Jets[loose_jets[i]].Pt();  
       }	
		 }
		}
		 
		Fill("h_ht_before_preselection",HT_for_QCD);
		Fill("h_met_before_preselection",MET.Pt());		
		 
	 if ( HT_for_QCD > 100 && tight_photons.size() > 0) {
	 	Fill("h_met_significance_before_preselection2",met_pfMet_significance);		
	 	}	
		
	 if ( HT_for_QCD > 200 && tight_photons.size() > 0) {
	 	Fill("h_met_significance_before_preselection3",met_pfMet_significance);		
	 	}	
		
	 if ( HT_for_QCD > 200 ) {
	 	Fill("h_met_significance_before_preselection4",met_pfMet_significance);		
	 	}			
						 
	 if ( HT_for_QCD > 100 ) {
	 	Fill("h_met_significance_before_preselection5",met_pfMet_significance);		
	 	}	
					 
	 if ( MET.Pt() > 50 && tight_photons.size() > 0 && Photons[tight_photons[0]].Pt() > 40) {
	 	Fill("h_met_significance_before_preselection",met_pfMet_significance);		
	 	}
		
		if ( HT_for_QCD > 100 ){
			Fill("h_ht_before_pre",HT_for_QCD);	
			}
		
		
	 
	 /* At least one photon is needed for this cut definition */
	  
	 if (!cut_met){
		pdfTree->Fill();
		return kFALSE;
	}
// met at least 100 GeV


	 Fill("h_cutflow", "#slash{E}_{T} > 100 GeV");
	 	 
	 if ( loose_photons.size() == 0 ){
		pdfTree->Fill();
		return kFALSE;
	}
	 
	 Fill("h_cutflow", "# loose #gamma > 0");	
	 
	 
	 // Investigate further control regions -> no tight (but at least one loose) photon
	 double HT_before = 0;
	 double DeltaR1_before = 0;
	 bool e_fake_control2 = false;
	 if ( tight_photons.size() == 0 ) { // be orthogonal
	 	 if (Photons[loose_photons[0]].Pt() > 40 && Photons[loose_photons[0]].r9 > 0.9 && fabs(Photons[loose_photons[0]].Eta()) < 1.4442 ) {
		 	 for (unsigned int i = 0; i < loose_jets.size(); i++) { 
	 			 DeltaR1_before = Photons[loose_photons[0]].DeltaR(Jets[loose_jets[i]]);
				 if (	Jets[loose_jets[i]].Pt() > 30 && (DeltaR1_before > 0.1 || (fabs((Photons[loose_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[loose_photons[0]].Pt()) >
					0.5 )) ) {
					 cleaned_jets_control2.push_back(i);			 
     	  	}
			 	}
			 for (unsigned int i = 0; i < cleaned_jets_control2.size(); i++) { 
    	 		HT_before += Jets[cleaned_jets_control2[i]].Pt(); 
			 		}
				if ( HT_before > 100 ) {
				
					for (unsigned int i = 0; i < GenParticles.size() ; i++) {
	 				if (GenParticles[i].GenStatus == 1) {
							if ((GenParticles[i].GenPDGID == 11 || GenParticles[i].GenPDGID == -11)) {
									if(GenParticles[i].DeltaR(Photons[loose_photons[0]]) < 0.1 ) {
										e_fake_control2 = true;
										}		
									}											
							}
					}
					if ( !e_fake_control2 ) {			
						Fill("h_HT_array_control2",HT_before);
						Fill("h_1tightPhotonPtOverMET_control2",Photons[loose_photons[0]].Pt()/MET.Pt());	 
						Fill("h_METoverSqHT_control2", MET.Pt()/(TMath::Sqrt(HT_before)));
						Fill("h_met_control2",MET.Pt());
						Fill("h_pt_control2",Photons[loose_photons[0]].Pt());				
						Fill("h_MET_significance_control2",met_pfMet_significance);
						if (Photons[loose_photons[0]].Pt() < 100) {
							Fill("h_HT_array_control3",HT_before);
							Fill("h_1tightPhotonPtOverMET_control3",Photons[loose_photons[0]].Pt()/MET.Pt());	 
							Fill("h_METoverSqHT_control3", MET.Pt()/(TMath::Sqrt(HT_before)));
							Fill("h_met_control3",MET.Pt());
							Fill("h_pt_control3",Photons[loose_photons[0]].Pt());				
							Fill("h_MET_significance_control3",met_pfMet_significance);					
							}
						if (Photons[loose_photons[0]].Pt() > 100) {
							Fill("h_HT_array_control4",HT_before);
							Fill("h_1tightPhotonPtOverMET_control4",Photons[loose_photons[0]].Pt()/MET.Pt());	 
							Fill("h_METoverSqHT_control4", MET.Pt()/(TMath::Sqrt(HT_before)));
							Fill("h_met_control4",MET.Pt());
							Fill("h_pt_control4",Photons[loose_photons[0]].Pt());				
							Fill("h_MET_significance_control4",met_pfMet_significance);					
							}							
						
						
						}
					}
				}
	 
	   }
	 
	 
	  
	 if ( tight_photons.size() == 0 ){
  	pdfTree->Fill();
		return kFALSE;
	}
	 
	 Fill("h_cutflow", "# tight #gamma > 0");	
	
   for (unsigned int i = 0; i < tight_photons.size(); i++) {
		 if (Photons[tight_photons[i]].Pt() < 40) {
				Fill("h_photon_charged_iso_40",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_40", 0.);
						 } else {
						Fill("h_photon_neutral_iso_40",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_40", 0.);
						 } else {
						Fill("h_photon_photon_iso_40",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}													
				}
				
		 if (Photons[tight_photons[i]].Pt() > 40 && Photons[tight_photons[i]].Pt() < 60) {
				Fill("h_photon_charged_iso_60",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_60", 0.);
						 } else {
						Fill("h_photon_neutral_iso_60",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_60", 0.);
						 } else {
						Fill("h_photon_photon_iso_60",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}
				}
				
		 if (Photons[tight_photons[i]].Pt() > 60 && Photons[tight_photons[i]].Pt() < 80) {
				Fill("h_photon_charged_iso_80",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_80", 0.);
						 } else {
						Fill("h_photon_neutral_iso_80",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_80", 0.);
						 } else {
						Fill("h_photon_photon_iso_80",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}		
				}				
						
		 if (Photons[tight_photons[i]].Pt() > 80 && Photons[tight_photons[i]].Pt() < 100) {
				Fill("h_photon_charged_iso_100",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_100", 0.);
						 } else {
						Fill("h_photon_neutral_iso_100",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_100", 0.);
						 } else {
						Fill("h_photon_photon_iso_100",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}	
				}					
												
		 if (Photons[tight_photons[i]].Pt() > 100 && Photons[tight_photons[i]].Pt() < 150) {
				Fill("h_photon_charged_iso_150",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_150", 0.);
						 } else {
						Fill("h_photon_neutral_iso_150",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_150", 0.);
						 } else {
						Fill("h_photon_photon_iso_150",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}	
						
			}					
						
		 if (Photons[tight_photons[i]].Pt() > 150 && Photons[tight_photons[i]].Pt() < 200) {
				Fill("h_photon_charged_iso_200",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_200", 0.);
						 } else {
						Fill("h_photon_neutral_iso_200",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_200", 0.);
						 } else {
						Fill("h_photon_photon_iso_200",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}	
				}
										
		 if (Photons[tight_photons[i]].Pt() > 200 && Photons[tight_photons[i]].Pt() < 400) {
				Fill("h_photon_charged_iso_400",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_400", 0.);
						 } else {
						Fill("h_photon_neutral_iso_400",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_400", 0.);
						 } else {
						Fill("h_photon_photon_iso_400",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}	
				}
										
		 if (Photons[tight_photons[i]].Pt() > 400) {
				Fill("h_photon_charged_iso_inf",Photons[tight_photons[i]].ChargedHadronIso_corrected());
				if ( Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_neutral_iso_inf", 0.);
						 } else {
						Fill("h_photon_neutral_iso_inf",Photons[tight_photons[i]].NeutralHadronIso_corrected() - 0.04*Photons[tight_photons[i]].Pt());
						}	
				if ( Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt() < 0 ) { 
						 Fill("h_photon_photon_iso_inf", 0.);
						 } else {
						Fill("h_photon_photon_iso_inf",Photons[tight_photons[i]].PhotonIso_corrected() - 0.005*Photons[tight_photons[i]].Pt());					
						}	
				}								
		 }	
		 		
	// Check here if e fake, before not possible because we need at least one tight photon 
  bool e_fake = false;
	for (unsigned int i = 0; i < GenParticles.size() ; i++) {
	 		if (GenParticles[i].GenStatus == 1) {
					if ((GenParticles[i].GenPDGID == 11 || GenParticles[i].GenPDGID == -11)) {
							if(GenParticles[i].DeltaR(Photons[tight_photons[0]]) < 0.1 ) {
								e_fake = true;
								}		
							}
											
					}
			}
			
	if ( Signal_640_630.compare(BGName) == 0 ) {
		e_fake = false;
		}
	
			
	if ( !e_fake ) {	 	 
//	if ( true ) {	
/*	for ( unsigned int i = 0; i < tight_photons.size(); i++) {
	cout << "=============================================" << endl;
	cout << "photon size:    " << tight_photons.size() << endl;	
	cout << "photon pt:    " << Photons[tight_photons[i]].Pt() << endl;
	cout << "photon eta:    " << Photons[tight_photons[i]].Eta() << endl;	
	cout << "photon r9:    " << Photons[tight_photons[i]].r9 << endl;	
	
	}
*/
	 if (cut_photons.size() == 0){
		pdfTree->Fill();
		return kFALSE;
	}
//	 cout << "da     " << endl;
	 
	 Fill("h_cutflow", "tight #gamma p_{T} > 40 GeV");
	 

	 if (cut_r9_photons.size() == 0){
		pdfTree->Fill();
		return kFALSE;
	}
//	 cout << "da     " << endl;	 
	 Fill("h_cutflow", "r9 > 0.9");	 

	 if (cut_EB_photons.size() == 0){
		pdfTree->Fill();
		return kFALSE;
	}
/*	 cout << "da     " << endl;	
	for ( unsigned int i = 0; i < tight_photons.size(); i++) {
	cout << "=============================================" << endl;
	cout << "photon size:    " << tight_photons.size() << endl;	
	cout << "photon pt:    " << Photons[tight_photons[i]].Pt() << endl;
	cout << "photon eta:    " << Photons[tight_photons[i]].Eta() << endl;	
	cout << "photon r9:    " << Photons[tight_photons[i]].r9 << endl;	
	
	}
*/
	 
	 Fill("h_cutflow", "tight #gamma in barrel");	 
	 
	////* From here on: at least one tight isolated ID photon with P_t > 40 in Barrel, MET > 100 *//////// 	 
	 
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
	  if (DeltaR < 0.5 ){
		pdfTree->Fill();
		return kFALSE;
	}

		
		Fill("h_cutflow","#Delta(R)(1st #gamma, n. jet) > 0.5");
		
	
		
	 double HT = 0;  /* Defined as usually -> Must be modified if using corrected HT */		
	 double HT2 = 0;	
	 double HT3 = 0;
	 		
	 for (unsigned int i = 0; i < loose_jets.size(); i++) { 
	 	 DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
		 if (	Jets[loose_jets[i]].Pt() > 30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 )) ) {
       HT3 += Jets[loose_jets[i]].Pt(); 			 
       }
		 if (	Jets[loose_jets[i]].Pt() > 30 && DeltaR1 < 0.1 && (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) <
				0.5 ) ) {		 
       }			 	
		 }
		
	if ( tight_photons.size() > 1 ) {	 
	 for (unsigned int i = 0; i < loose_jets.size(); i++) { 
	 	 DeltaR1 = Photons[tight_photons[0]].DeltaR(Jets[loose_jets[i]]);
		 if (	Jets[loose_jets[i]].Pt() > 30 && (DeltaR1 > 0.1 || (fabs((Photons[tight_photons[0]].Pt() - Jets[loose_jets[i]].Pt())/ Photons[tight_photons[0]].Pt()) >
				0.5 )) && (fabs(Jets[loose_jets[i]].Eta() ) < 2.5 ) ) {
       HT2 += Jets[loose_jets[i]].Pt(); 
       }	
		 }	
		Fill("h_HT2",HT2);
		}	
		
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) { 
     HT += Jets[cleaned_jets[i]].Pt(); 
		 }
		 
		Fill("h_HT_raw",HT);		
		Fill("h_pt_raw",Photons[tight_photons[0]].Pt());		
		
		
	if( HT < 100 ){
		pdfTree->Fill();
		return kFALSE;
	}
		
		
		Fill("h_cutflow","H_{T} > 100 GeV");	
		
		
/*   if ( ZGamma.compare(BGName) == 0 ) {	
	 		if (tight_photons.size() < 1) return kFALSE;
			cout << "------------------------------------------------" << endl;	
		  for ( int i = 0; i < GenParticles.size() ; i++) {	
				cout << " gen number:.....   "  << i << "    gen id....  " << 	GenParticles[i].GenPDGID	<< "      gen status.....  " <<  GenParticles[i].GenStatus << endl;		 
	 			if ( (fabs(GenParticles[i].GenPDGID) == 12 || fabs(GenParticles[i].GenPDGID) == 14 || fabs(GenParticles[i].GenPDGID) ==
				16) && (GenParticles[i].GenStatus == 1) ) {
					right_event = true;		
					cout << "neutrino" << endl;	
					}
				}
				if (right_event == true && Photons[tight_photons[0]].Pt() > 140) {
				//	return kFALSE;
					}
				if (right_event == false) {
			//		return kFALSE;
					}			 
			 	
			}*/
			
	 double TransMassCheck = TMath::Sqrt(2*Photons[tight_photons[0]].Pt()*MET.Pt()*(1.- TMath::Cos(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi()))));
			
	 double sum_photon_pt_before = 0;
	 for (unsigned int i = 0; i < loose_photons.size(); i++) {
			sum_photon_pt_before += Photons[loose_photons[i]].Pt();
			} 
	 double sum_signal_before = sum_photon_pt_before + MET.Pt();
	 double sum_signal_before_TypeOne = sum_photon_pt_before + TypeOneMET.Pt();	 
	 
		Fill2("h2_met_sign_trans_mass",met_pfMet_significance,TransMassCheck);
		Fill2("h2_met_sign_sigma",met_pfMet_significance,sum_signal_before);			 			

		if (TransMassCheck < 250 && met_pfMet_significance > 20){
		  Fill("h_pt_dep_1", Photons[tight_photons[0]].Pt());
			Fill("h_METoverSqHT_double_control_250", MET.Pt()/(TMath::Sqrt(HT)));				
		  }
		if (TransMassCheck < 200 && met_pfMet_significance > 20){
			Fill("h_METoverSqHT_double_control_200", MET.Pt()/(TMath::Sqrt(HT)));	
		  }			
		if (TransMassCheck < 150 && met_pfMet_significance > 20){
			Fill("h_METoverSqHT_double_control_150", MET.Pt()/(TMath::Sqrt(HT)));	
		  }	
		if (TransMassCheck < 300 && met_pfMet_significance > 10){
		  Fill("h_pt_dep_2", Photons[tight_photons[0]].Pt());
			Fill("h_METoverSqHT_double_control_10", MET.Pt()/(TMath::Sqrt(HT)));			
		  }			
		if (TransMassCheck < 300 && met_pfMet_significance > 15){
		  Fill("h_pt_dep_3", Photons[tight_photons[0]].Pt());
			Fill("h_METoverSqHT_double_control_15", MET.Pt()/(TMath::Sqrt(HT)));			
		  }		
		if (TransMassCheck < 300 && met_pfMet_significance > 20){
		  Fill("h_pt_dep_4", Photons[tight_photons[0]].Pt());	
			Fill("h_METoverSqHT_double_control_20", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if (TransMassCheck < 300 && met_pfMet_significance > 30){
			Fill("h_METoverSqHT_double_control_30", MET.Pt()/(TMath::Sqrt(HT)));
		  }				
		if (TransMassCheck < 300 && met_pfMet_significance < 20){
			Fill("h_METoverSqHT_double_control_20_2", MET.Pt()/(TMath::Sqrt(HT)));
		  }		
				
		if (TransMassCheck > 300 && met_pfMet_significance < 20){
			Fill("h_METoverSqHT_double_control_20_3", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
//	cout << "Eventweight vorher:   " << Eventweight << endl;
//	 string Signal = "Signal_640_630";
	 
 //  if ( ZGamma.compare(BGName) == 0 || ZGammaNuNu.compare(BGName) == 0 ||WGamma.compare(BGName) == 0 ||WGamma_20_30.compare(BGName) == 0 ||WGamma_30_50.compare(BGName) == 0 ||WGamma_50_130.compare(BGName) == 0 ||WGamma_130_inf.compare(BGName) == 0 ) {	
	 //normal
	//     Eventweight*= 0.932 - 0.000968*Photons[tight_photons[0]].Pt();
	// uncertainty both up:	
	  //   Eventweight*= 1.064 + 0.000872*Photons[tight_photons[0]].Pt(); 	
	//		 }		
	// uncertainty up with correlation:	
	//     Eventweight*=  ( 0.932 - 0.000968*Photons[tight_photons[0]].Pt()) + sqrt (fabs(0.017524 +
	//		 (0.0000033987*Photons[tight_photons[0]].Pt()*Photons[tight_photons[0]].Pt() - 2*Photons[tight_photons[0]].Pt()*0.00022109)));	
			// cout << "eventweight:   " << Eventweight << endl;	
		//	 }	
			 			
//	cout << "Eventweight nachher:   " << Eventweight << endl;	
						 
		if ( (TransMassCheck < 300 && met_pfMet_significance > 20) || (TransMassCheck > 300 && met_pfMet_significance < 20) || (TransMassCheck < 300 && met_pfMet_significance < 20) ){
			Fill("h_METoverSqHT_double_control_3_regions_20", MET.Pt()/(TMath::Sqrt(HT)));
		  }				
		if ( (TransMassCheck < 300 && met_pfMet_significance > 25) || (TransMassCheck > 300 && met_pfMet_significance < 25) || (TransMassCheck < 300 &&
		met_pfMet_significance < 25) ){
			Fill("h_METoverSqHT_double_control_3_regions_25", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( (TransMassCheck < 300 && met_pfMet_significance > 30) || (TransMassCheck > 300 && met_pfMet_significance < 30) || (TransMassCheck < 300 &&
		met_pfMet_significance < 30) ){
			Fill("h_METoverSqHT_double_control_3_regions_30", MET.Pt()/(TMath::Sqrt(HT)));
		  }								
		if ( (TransMassCheck < 300 && met_pfMet_significance > 35) || (TransMassCheck > 300 && met_pfMet_significance < 35) || (TransMassCheck < 300 &&
		met_pfMet_significance < 35) ){
			Fill("h_METoverSqHT_double_control_3_regions_35", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( (TransMassCheck < 300 && met_pfMet_significance > 40) || (TransMassCheck > 300 && met_pfMet_significance < 40) || (TransMassCheck < 300 &&
		met_pfMet_significance < 40) ){
			Fill("h_METoverSqHT_double_control_3_regions_40", MET.Pt()/(TMath::Sqrt(HT)));
		  }				
		if ( (TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50) ){
			Fill("h_METoverSqHT_double_control_3_regions_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( (TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 && met_pfMet_significance < 60) || (TransMassCheck < 300 &&
		met_pfMet_significance < 60) ){
			Fill("h_METoverSqHT_double_control_3_regions_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
		if ( (TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 && met_pfMet_significance < 70) || (TransMassCheck < 300 &&
		met_pfMet_significance < 70) ){
			Fill("h_METoverSqHT_double_control_3_regions_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( (TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 && met_pfMet_significance < 80) || (TransMassCheck < 300 &&
		met_pfMet_significance < 80) ){
			Fill("h_METoverSqHT_double_control_3_regions_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
			
										 	
		if ( (TransMassCheck < 200 && met_pfMet_significance > 30) || (TransMassCheck > 200 && met_pfMet_significance < 30) || (TransMassCheck < 200 &&
		met_pfMet_significance < 30) ){
			Fill("h_METoverSqHT_double_control_3_regions_30_200", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
			
			
		if ( met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_10_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 &&	met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_10_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
		if ( met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_10_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_10_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }
			
		if ( met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_20_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 &&	met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_20_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
		if ( met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_20_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_0_20_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }


		if ( TransMassCheck > 50 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_10_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( TransMassCheck > 50 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 &&	met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_10_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
		if ( TransMassCheck > 50 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_10_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( TransMassCheck > 50 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_10_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }
			
			
		if ( TransMassCheck > 50 && met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 &&	met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_20_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
		if ( TransMassCheck > 50 && met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_20_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }						
		if ( TransMassCheck > 50 && met_pfMet_significance > 20  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_50_20_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }			
						
			
			
			
		if ( TransMassCheck > 100 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_10_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( TransMassCheck > 100 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 && met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_10_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }
		if ( TransMassCheck > 100 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_10_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }
		if ( TransMassCheck > 100 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_10_80", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_double_control_3_regions_100_10_80_16", MET.Pt()/(TMath::Sqrt(HT)));	
		  }
		if ( TransMassCheck > 100 && ((TransMassCheck < 300 && met_pfMet_significance > 50) || (TransMassCheck > 300 && met_pfMet_significance < 50) || (TransMassCheck < 300 &&
		met_pfMet_significance < 50)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_0_50", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
		if ( TransMassCheck > 100 && ((TransMassCheck < 300 && met_pfMet_significance > 60) || (TransMassCheck > 300 &&
		met_pfMet_significance < 60) || (TransMassCheck < 300 && met_pfMet_significance < 60)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_0_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }
		if ( TransMassCheck > 100 && ((TransMassCheck < 300 && met_pfMet_significance > 70) || (TransMassCheck > 300 &&
		met_pfMet_significance < 70) || (TransMassCheck < 300 && met_pfMet_significance < 70)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_0_70", MET.Pt()/(TMath::Sqrt(HT)));
		  }
		if ( TransMassCheck > 100 && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
			Fill("h_METoverSqHT_double_control_3_regions_100_0_80", MET.Pt()/(TMath::Sqrt(HT)));
		  }
			
			
		if ( (met_pfMet_significance > 20) &&  (met_pfMet_significance < 60) ){
			Fill("h_METoverSqHT_double_control_20_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
				
		if ( (met_pfMet_significance > 10) &&  (met_pfMet_significance < 60) ){
			Fill("h_METoverSqHT_double_control_10_60", MET.Pt()/(TMath::Sqrt(HT)));
		  }	
							
		if ( (met_pfMet_significance > 10) &&  (met_pfMet_significance < 80) ){
			Fill("h_METoverSqHT_double_control_10_80", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_MET_significance_metsig_sideband",TransMassCheck);
		  }	
		if ( ( TransMassCheck > 100) &&  ( TransMassCheck < 300) ){
			Fill("h_METoverSqHT_double_control_100_300", MET.Pt()/(TMath::Sqrt(HT)));
			FillPerGev("h_MET_significance_MT_sideband",met_pfMet_significance);
			Fill("h_MET_significance_MT_sideband_2",met_pfMet_significance);			
		  }				
							 
		if (TransMassCheck < 300){
		  Fill("h_METoverSqHT_trans_mass_control", MET.Pt()/(TMath::Sqrt(HT)));
		  Fill("h_photon_pt_trans_mass_control", Photons[tight_photons[0]].Pt());
		  }
		if (TransMassCheck > 300){
		  Fill("h_photon_pt_trans_mass_signal", Photons[tight_photons[0]].Pt());
		  }			
		if ( met_pfMet_significance < 60 ) {
		  Fill("h_METoverSqHT_met_sign_control", MET.Pt()/(TMath::Sqrt(HT)));	
		  Fill("h_photon_pt_met_sign_control", Photons[tight_photons[0]].Pt());		  
			}		
		if ( met_pfMet_significance > 60 ) {
		  Fill("h_photon_pt_met_sign_signal", Photons[tight_photons[0]].Pt());	
		  }	
					
					
		Fill("h_HT_array_HT_cut",HT);		
	  Fill("h_1tightPhotonPtOverMET_scale_HT_cut",Photons[tight_photons[0]].Pt()/MET.Pt());	
	  Fill("h_METoverSqHT_scale_HT_cut", MET.Pt()/(TMath::Sqrt(HT)));
		double AngleMJ1_scale = -1;
	  double InvMassJets_scale = -1;				
		if ( cleaned_jets.size() > 0){			 
			 AngleMJ1_scale = DeltaPhi(MET.Phi(),Jets[cleaned_jets[0]].Phi() );
			 if (cleaned_jets.size() > 1){	
		   	TLorentzVector vJ_s = Jets[cleaned_jets[0]] + Jets[cleaned_jets[1]];
	     	InvMassJets_scale = vJ_s.M();
			 	}
			 }	 	 				
	  if ( Photons[tight_photons[0]].Pt() < 100 ) {
			Fill("h_HT_array_pt_cut",HT);
			Fill("h_HT_array_100_41",HT);	
			Fill("h_MET_significance_100_39",met_pfMet_significance);
			Fill("h_MET_significance_100_23",met_pfMet_significance);								
			Fill("h_1tightPhotonPtOverMET_scale_pt_cut",Photons[tight_photons[0]].Pt()/MET.Pt());	 
			Fill("h_METoverSqHT_100_36", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_100_30", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_100_24", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_100_17", MET.Pt()/(TMath::Sqrt(HT)));	
			Fill("h_METoverSqHT_100_12", MET.Pt()/(TMath::Sqrt(HT)));						
			Fill("h_met_orth",MET.Pt());
			Fill("h_pt_orth",Photons[tight_photons[0]].Pt());
			Fill("h_MET_significance_scale",met_pfMet_significance);	
			Fill("h_MET_over_PT_100",MET.Pt()/Photons[tight_photons[0]].Pt());	
			Fill("h_Angle_MET_1jet_100",AngleMJ1_scale);				
			Fill("h_InvMass_2jets_100", InvMassJets_scale);
			
			for (unsigned int i = 0; i < GenParticles.size() ; i++) {
	 		  if (GenParticles[i].GenStatus == 1 && tight_photons.size() > 0 && GenParticles[i].DeltaR(Photons[tight_photons[0]]) < 0.1 ) {
				  Fill("h_total_number_reco_photons", tight_photons.size() );
					
					if ( GenParticles[i].GenPDGID == 22 ) {
					  Fill("h_gen_number_reco_photons", tight_photons.size() );					 
											
						if ( ( (GenParticles[i].Pt() - Photons[tight_photons[0]].Pt())/Photons[tight_photons[0]].Pt() < 0.5) ) {
					   	Fill("h_real_number_reco_photons", tight_photons.size() );					 
						 	}
						}
											
					}
			  }									 
			}
		// Variation of control region
	  if ( Photons[tight_photons[0]].Pt() < 110 ) {
			Fill("h_HT_array_110",HT); 
			Fill("h_HT_array_110_41",HT);	
			Fill("h_MET_significance_110_39",met_pfMet_significance);
			Fill("h_MET_significance_110_23",met_pfMet_significance);			
			Fill("h_METoverSqHT_110_36", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_110_30", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_110_24", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_110_17", MET.Pt()/(TMath::Sqrt(HT)));	
			Fill("h_METoverSqHT_110_12", MET.Pt()/(TMath::Sqrt(HT)));						
			Fill("h_met_110",MET.Pt());
			Fill("h_pt_110",Photons[tight_photons[0]].Pt());				
			Fill("h_MET_significance_110",met_pfMet_significance);
			Fill("h_MET_over_PT_110",MET.Pt()/Photons[tight_photons[0]].Pt());	
			Fill("h_Angle_MET_1jet_110",AngleMJ1_scale);				
			Fill("h_InvMass_2jets_110", InvMassJets_scale);							 
			}			
	  if ( Photons[tight_photons[0]].Pt() < 90 ) {
			Fill("h_HT_array_90",HT); 
			Fill("h_HT_array_90_41",HT);	
			Fill("h_MET_significance_90_39",met_pfMet_significance);
			Fill("h_MET_significance_90_23",met_pfMet_significance);			
			Fill("h_METoverSqHT_90_36", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_90_30", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_90_24", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_90_17", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_90_12", MET.Pt()/(TMath::Sqrt(HT)));							
			Fill("h_met_90",MET.Pt());
			Fill("h_pt_90",Photons[tight_photons[0]].Pt());				
			Fill("h_MET_significance_90",met_pfMet_significance);	
			Fill("h_MET_over_PT_90",MET.Pt()/Photons[tight_photons[0]].Pt());	
			Fill("h_Angle_MET_1jet_90",AngleMJ1_scale);				
			Fill("h_InvMass_2jets_90", InvMassJets_scale);						 
			}			
	  if ( Photons[tight_photons[0]].Pt() < 120 ) {
			Fill("h_HT_array_120",HT); 
			Fill("h_HT_array_120_41",HT);	
			Fill("h_MET_significance_120_39",met_pfMet_significance);
			Fill("h_MET_significance_120_23",met_pfMet_significance);			
			Fill("h_METoverSqHT_120_36", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_120_30", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_120_24", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_120_17", MET.Pt()/(TMath::Sqrt(HT)));	
			Fill("h_METoverSqHT_120_12", MET.Pt()/(TMath::Sqrt(HT)));						
			Fill("h_met_120",MET.Pt());
			Fill("h_pt_120",Photons[tight_photons[0]].Pt());				
			Fill("h_MET_significance_120",met_pfMet_significance);
			Fill("h_MET_over_PT_120",MET.Pt()/Photons[tight_photons[0]].Pt());	
			Fill("h_Angle_MET_1jet_120",AngleMJ1_scale);				
			Fill("h_InvMass_2jets_120", InvMassJets_scale);							 
			}			
	  if ( Photons[tight_photons[0]].Pt() < 80 ) {
			Fill("h_HT_array_80",HT); 
			Fill("h_HT_array_80_41",HT);	
			Fill("h_MET_significance_80_39",met_pfMet_significance);
			Fill("h_MET_significance_80_23",met_pfMet_significance);			
			Fill("h_METoverSqHT_80_36", MET.Pt()/(TMath::Sqrt(HT)));
			Fill("h_METoverSqHT_80_30", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_80_24", MET.Pt()/(TMath::Sqrt(HT)));			
			Fill("h_METoverSqHT_80_17", MET.Pt()/(TMath::Sqrt(HT)));	
			Fill("h_METoverSqHT_80_12", MET.Pt()/(TMath::Sqrt(HT)));						
			Fill("h_met_80",MET.Pt());
			Fill("h_pt_80",Photons[tight_photons[0]].Pt());				
			Fill("h_MET_significance_80",met_pfMet_significance);	
			Fill("h_MET_over_PT_80",MET.Pt()/Photons[tight_photons[0]].Pt());	
			Fill("h_Angle_MET_1jet_80",AngleMJ1_scale);				
			Fill("h_InvMass_2jets_80", InvMassJets_scale);						 
			}
					
												
	 if (TransMassCheck < 100 || met_pfMet_significance < 10){
		pdfTree->Fill();
		return kFALSE;
	}
	
  Fill("h_cutflow","CR + SR");	
		 
	double HT_hlt_hadronic = 0;
	for (unsigned int i = 0; i < Jets.size(); i++) {
		if (Jets[i].Pt() > 40 && fabs(Jets[i].Eta()) < 3.0){
			 HT_hlt_hadronic += Jets[i].Pt();
//			cout << "jet pt:  " << Jets[i].Pt() << "  fabs jet eta:   " << fabs(Jets[i].Eta()) << endl;
			}
	 	}	 
			
	 	Fill("h_tight_photon_pt_before", Photons[tight_photons[0]].Pt());
	  FillMETsign("h_MET_significance_array_norm_before",met_pfMet_significance); 		
	  FillPerGev("h_MET_significance_per_gev_14_before",met_pfMet_significance);	
		Fill("h_trans_mass_pt_before", TransMassCheck);	
		FillPerGev("h_trans_mass_pt_before_per_gev", TransMassCheck);	
		Fill("h_met_significance_before", met_pfMet_significance);		
	  Fill("h_sum_signal_over_sqrt_met_before",sum_signal_before/sqrt(MET.Pt()) );	
	  Fill("h_n_photon_loose_before",loose_photons.size());	
	  Fill("h_n_photon_tight_before",tight_photons.size());			
	  Fill("h_n_jets_cleaned_before",cleaned_jets.size());
		if ( cleaned_jets.size() > 0 ) { Fill("h_jet_pt_before", Jets[cleaned_jets[0]].Pt());}
	  Fill("h_HT_before",HT);
	  Fill("h_hlt_HT_before",HT_hlt_hadronic);		
		Fill("h_met_before",MET.Pt()); 	
	  FillPerGev("h_HT_before_per_gev",HT);		
	 	FillPerGev("h_tight_photon_pt_before_per_gev", Photons[tight_photons[0]].Pt());	
		
				
		Fill("h_TypeOneMet_before",TypeOneMET.Pt()); 		
	  Fill("h_ST_before",sum_signal_before);		  
		Fill("h_ST_TypeOne_before",sum_signal_before_TypeOne);			
	

	 
	 
    if ( TransMassCheck > 100 && met_pfMet_significance > 10  && ((TransMassCheck < 300 && met_pfMet_significance > 80) || (TransMassCheck > 300 &&
		met_pfMet_significance < 80) || (TransMassCheck < 300 && met_pfMet_significance < 80)) ){
		
	 	Fill("h_tight_photon_pt_CR", Photons[tight_photons[0]].Pt());
	  FillMETsign("h_MET_significance_array_norm_CR",met_pfMet_significance); 	  
		Fill("h_MET_significance_array_CR",met_pfMet_significance);
	  Fill("h_MET_significance_array_CR_13",met_pfMet_significance);			
	  FillPerGev("h_MET_significance_per_gev_14_CR",met_pfMet_significance);	
		Fill("h_trans_mass_pt_CR", TransMassCheck);
		Fill("h_met_significance_CR", met_pfMet_significance);		
	  Fill("h_sum_signal_over_sqrt_met_CR",sum_signal_before/sqrt(MET.Pt()) );	
	  Fill("h_n_photon_loose_CR",loose_photons.size());	
	  Fill("h_n_photon_tight_CR",tight_photons.size());			
	  Fill("h_n_jets_cleaned_CR",cleaned_jets.size());
		if ( cleaned_jets.size() > 0 ) { Fill("h_jet_pt_CR", Jets[cleaned_jets[0]].Pt());}
	  Fill("h_HT_CR",HT);
		Fill("h_met_CR",MET.Pt()); 	
		
		Fill("h_TypeOneMet_CR",TypeOneMET.Pt()); 		
	  Fill("h_ST_CR",sum_signal_before);		  
		Fill("h_ST_TypeOne_CR",sum_signal_before_TypeOne);	
			 
		double AngleMJ1_CR = -1;
	  double InvMassJets_CR = -1;				
		if ( cleaned_jets.size() > 0){			 
			 AngleMJ1_CR = DeltaPhi(MET.Phi(),Jets[cleaned_jets[0]].Phi() );
			 if (cleaned_jets.size() > 1){	
		   	TLorentzVector vJ_CR = Jets[cleaned_jets[0]] + Jets[cleaned_jets[1]];
	     	InvMassJets_CR = vJ_CR.M();
			 	}
			 }
			 Fill("h_InvMass_2jets_CR", InvMassJets_CR);	
			 Fill("h_Angle_MJ1_CR", AngleMJ1_CR); 
	 	}
		

	 
//	cout << "test" << endl;

	 if (TransMassCheck < 300 || met_pfMet_significance < 80){
		pdfTree->Fill();
		return kFALSE;
	}

//	cout << "passed" << endl;

/*  for (int i = 0; i < cleaned_jets.size(); ++i) { 
		cout << "=======================================================" << endl;
		cout << "jet scale:   "	<<  Jets[cleaned_jets[i]].jecScale << endl;
		cout << "jet pt:   "	<< Jets[cleaned_jets[i]].Pt() << endl;		
		cout << "jet p:   "	<< Jets[cleaned_jets[i]].P() << endl;		
		cout << "jet E 2:   "	<< Jets[cleaned_jets[i]].JetE << endl;
		cout << "JET Eta:   "	<< Jets[i].JetEta << endl;			
		cout << "jet Eta:   "	<< Jets[cleaned_jets[i]].JetEta << endl;
		cout << "jet nC:   "	<< Jets[cleaned_jets[i]].nConstituents	<< endl;				
		cout << "neutral hadron fraction:    " << Jets[cleaned_jets[i]].neutralHadronEnergy/Jets[cleaned_jets[i]].JetE << endl;
		cout << "neutral em fraction:    " << Jets[cleaned_jets[i]].neutralEmEnergy/Jets[cleaned_jets[i]].JetE << endl;			
	}
*/ 
	 
	 Fill("h_cutflow","SR");
	 
	Fill2("h2_met_sign_sigma_SR",met_pfMet_significance,sum_signal_before);	 	 

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
	 Fill("h_n_muons_loose",loose_muons.size());	
	 Fill("h_n_muons_soft",soft_muons.size());	 
	 
	/* for (unsigned int i = 0; i < medium_electrons.size(); i++) {	
	 		cout << "-->> electron dz:  " << Electrons[medium_electrons[i]].electron_dz(Electrons[medium_electrons[i]].electron_vertex) << endl;
	 		cout << "-->> electron d0:  " << Electrons[medium_electrons[i]].electron_d0(Electrons[medium_electrons[i]].electron_vertex) << endl;
   		cout << "-->> electron vertexX:  " << Electrons[medium_electrons[i]].electron_vertex_x<< endl;
	 		cout << "-->> electron vertexY:  " << Electrons[medium_electrons[i]].electron_vertex_y<< endl;
	 		cout << "-->> electron vertexZ:  " << Electrons[medium_electrons[i]].electron_vertex_z<< endl;
	 		cout << "-->> electron trackPx:  " << Electrons[medium_electrons[i]].electron_track_px<< endl;
	 		cout << "-->> electron trackPy:  " << Electrons[medium_electrons[i]].electron_track_py<< endl;
	 		cout << "-->> electron trackPz:  " << Electrons[medium_electrons[i]].electron_track_pz<< endl; 
	 		cout << "-->> pass conversion veto:  " << Electrons[medium_electrons[i]].electron_pass_conversion_veto << endl; 
	 		cout << "-->> Missing hits:  " << Electrons[medium_electrons[i]].electron_n_missing_hits << endl;						
			if (Electrons[medium_electrons[i]].electron_dz(Electrons[medium_electrons[i]].electron_vertex) > 0.2) cout <<
			Electrons[medium_electrons[i]].electron_dz(Electrons[medium_electrons[i]].electron_vertex) << endl;
			if (Electrons[medium_electrons[i]].electron_d0(Electrons[medium_electrons[i]].electron_vertex) > 0.02) cout <<
			Electrons[medium_electrons[i]].electron_d0(Electrons[medium_electrons[i]].electron_vertex) << endl;			
	 		} */
/*	 for (unsigned int i = 0; i < loose_muons.size(); i++) {		
//	 	 	if (Muons[loose_muons[i]].muon_dz() > 30 ) cout << "-->> muon dz:  " << Muons[loose_muons[i]].muon_dz() << endl;
//	 		if (Muons[loose_muons[i]].muon_dxy() > 3 ) cout << "-->> muon dxy:  " << Muons[loose_muons[i]].muon_dxy() << endl;
	 cout << "-->> muon pt:  " <<Muons[loose_muons[i]].muon_pt << endl;
	 cout << "-->> muon eta:  " <<Muons[loose_muons[i]].muon_eta << endl;

	 cout << "-->> muon chargedhadron:  " <<Muons[loose_muons[i]].muon_chargedHadronPt04 << endl;
	 cout << "-->> muon neutralhadron:  " <<Muons[loose_muons[i]].muon_neutralHadronEt04 << endl;
	 cout << "-->> muon photon:  " <<Muons[loose_muons[i]].muon_photonEt04 << endl;
	 cout << "-->> muon pu:  " <<Muons[loose_muons[i]].muon_PUPt04 << endl;
	 cout << "-->> muon chi2:  " <<Muons[loose_muons[i]].muon_Chi2 << endl;
	 cout << "-->> muon ndf:  " <<Muons[loose_muons[i]].muon_NDF << endl;
	 cout << "-->> muon pixel:  " <<Muons[loose_muons[i]].muon_PixelLayers << endl;
	 cout << "-->> muon strips:  " <<Muons[loose_muons[i]].muon_StripLayers << endl;	
	 cout << "-->> muon pf:  " <<Muons[loose_muons[i]].IsPfMuon() << endl;
	 cout << "-->> muon global:  " <<Muons[loose_muons[i]].IsGlobalMuon() << endl;	 
	 cout << "-->> muon deltaB_iso/pt:  " <<Muons[loose_muons[i]].muon_deltaB_iso()/Muons[loose_muons[i]].muon_pt << endl;
	 	 	}	*/
			
//	cout << "para:  " << gridParams_pdf_scale << endl; 
//	pdf_id1 = gridParams_pdf_id1;
//	pdf_id2 = gridParams_pdf_id2;
//	pdf_scale = gridParams_pdf_scale;
//	pdf_x1 = gridParams_pdf_x1;
//	pdf_x2 = gridParams_pdf_x2;
//	pdf_selected = 0;
	
		  
	 Fill("h_Phi_MET", fabs(MET.Phi()));	 
	 Fill("h_METoverSqHT", MET.Pt()/(TMath::Sqrt(HT)));	    
	 Fill("h_METoverSqHT_blind", MET.Pt()/(TMath::Sqrt(HT)));
	 Fill("h_METoverSqHT_scale", MET.Pt()/(TMath::Sqrt(HT)));	 
	 Fill("h_METoverSqHT_scale_HT", MET.Pt()/(TMath::Sqrt(HT)));	 
	 FillArraySignificance("h_METoverSqHT_array", MET.Pt()/(TMath::Sqrt(HT)));	 
	 Fill("h_HToverMET", HT/MET.Pt());
	 Fill("h_MET_significance",met_pfMet_significance);
	 Fill("h_MET_significance_corrected",met_pfType01CorrectedMet_significance);	  
	 Fill("h_MET_significance_array",met_pfMet_significance);	 
	 FillMETsign("h_MET_significance_array_norm",met_pfMet_significance); 		
	 FillPerGev("h_MET_significance_per_gev_10",met_pfMet_significance);
	 FillPerGev("h_MET_significance_per_gev_14",met_pfMet_significance);	 	
	 FillPerGev("h_MET_significance_per_gev_23",met_pfMet_significance);	 
	 FillPerGev("h_MET_significance_per_gev_32",met_pfMet_significance);
	 FillPerGev("h_MET_significance_per_gev_10_blind",met_pfMet_significance);	
	 FillPerGev("h_MET_significance_per_gev_14_blind",met_pfMet_significance);	 
	 FillPerGev("h_MET_significance_per_gev_23_blind",met_pfMet_significance);	 
	 FillPerGev("h_MET_significance_per_gev_32_blind",met_pfMet_significance);	 
	 
	 		 		
		double AngleGM = fabs(DeltaPhi(MET.Phi(),Photons[tight_photons[0]].Phi() ));
	  Fill("h_DeltaPhi_photon_MET",	AngleGM);
		
	 double sum_pt = 0;
	 double sum_p = 0.000000001;
	 double sum_photon_pt = 0;
	 double sum_photon_p = 0.000000001;
	 	 
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
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
	 double sum_signal_TypeOne = sum_photon_pt + TypeOneMET.Pt();	 
	 Fill("h_sum_signal",sum_signal);
	 Fill("h_ST_TypeOne",sum_signal_TypeOne);	 
	 FillPerGev("h_sum_signal_per_gev",sum_signal);	 
	 
	 Fill2("h2_sigma_metsign",(sum_signal/(TMath::Sqrt(MET.Pt()))), met_pfMet_significance);	 
	 Fill2("h2_sigma_met",sum_signal/(TMath::Sqrt(MET.Pt())), MET.Pt());
	 
	 	 
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
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {	 
	   Fill("h_bTagDisc",Jets[cleaned_jets[i]].bTagDisc);
		 if (Jets[cleaned_jets[i]].bTagDisc > 0.5 ) {
		 		b_jets.push_back(i);
		    }		 
	   Fill("h_bTagDisc",Jets[cleaned_jets[i]].bTagDisc);
		 if (Jets[cleaned_jets[i]].bTagDisc > -0.5 ) {
		 		b_jets2.push_back(i);
		    }						 
	   Fill("h_n_bJets",b_jets.size());
	   Fill("h_n_bJets2",b_jets2.size());		 
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
	 unsigned int indexi = 0;
	 unsigned int indexj = 0; 
	if ( cleaned_jets.size() > 1 ) {
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
	 	 EtaTest = fabs(Jets[cleaned_jets[i]].Eta());
		 if (EtaTest < EtaLow){
				EtaLow = EtaTest;
				indexi = i;
				}
	   }
	 for (unsigned int j = 0; j < cleaned_jets.size(); j++) {
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
	 Fill("h_trans_mass_MET_Gamma_blind",TransMassMETGamma);
	 if (Photons[tight_photons[0]].Pt() > 100 ){
	   Fill("h_trans_mass_MET_Gamma_100",TransMassMETGamma);
	 	}
	 
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
		
 
 // FakeRate durch Elektronen ->  Vergleiche GammaPixel-Verteilung * FakeRate pro BG mit pdgID == +-11 die als Gamma rek. wurden
 // Die BG, wo Anteil von pdgID = +-11 gro� gg pdgID = 22 ist k�nnen durch FakeRate abgesch�tzt werden

		Fill("h_met_datadriven",MET.Pt());
		Fill("h_HT_array_datadriven",HT);		
		Fill("h_inverse_met_datadriven",1./MET.Pt());	
		Fill("h_tight_photon_pt_datadriven",Photons[tight_photons[0]].Pt());												
	
 
	 Fill2("h2_n_photon_pixel_met",pixel_photons.size(),MET.Pt());
	 Fill2("h2_n_jets_met",cleaned_jets.size(),MET.Pt()); 
	 
   for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
	 	
	 		Fill("h_cleaned_jets_pt", Jets[cleaned_jets[i]].Pt() );
			Fill("h_cleaned_jets_chargedHE", Jets[cleaned_jets[i]].chargedHadronEnergy );
			double frac = ( Jets[cleaned_jets[i]].chargedHadronEnergy / Jets[cleaned_jets[i]].JetE );
			Fill("h_cleaned_jets_chargedfrac", frac );
			Fill("h_cleaned_jets_chargedM", Jets[cleaned_jets[i]].chargedMultiplicity );
			//cout << "jec uncertainty:  " << Jets[cleaned_jets[i]].jecUncert << endl;
		  }
			
	 for (unsigned int i = 0; i < photon_matched_jets.size(); i++) {	 	 
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
	 Fill("h_TypeOneMet",TypeOneMET.Pt());	 
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
	 	 
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) { 
			 double AngleMJ = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[i]].Phi() ));
       Fill("h_AngleMJ", AngleMJ);
			 Fill("h_Eta_Jet", Jets[loose_jets[i]].Eta()); 
			 Fill2("h_corrMETJet",MET.Phi() ,Jets[loose_jets[i]].Phi() );
		//	 cout << MET.Phi() << "............." << Jets[loose_jets[i]].Phi() << endl;
		   }
		
			 
	double AngleMJ1 = 0;		
	double AngleMJ2 = 0;	
	double AngleMJ3 = 0;		 
	 if ( cleaned_jets.size() > 0){			 
			 AngleMJ1 = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[0]].Phi() ));
       Fill("h_AngleMJ1", AngleMJ1);
			 }
	 if ( cleaned_jets.size() > 1){			 
			 AngleMJ2 = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[1]].Phi() ));
       Fill("h_AngleMJ2", AngleMJ2);
			 }			 
	 if ( cleaned_jets.size() > 2){			 
			 AngleMJ3 = fabs(DeltaPhi(MET.Phi(),Jets[cleaned_jets[2]].Phi() ));
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
	 Fill("h_METoverPhotonPt", MET.Pt()/Photons[tight_photons[0]].Pt());
	 Fill("h_1tightPhotonPtOverMET_scale",Photons[tight_photons[0]].Pt()/MET.Pt());
	 Fill("h_photon_seedTime", Photons[tight_photons[0]].photon_seedtime);
	 Fill("h_photon_pt_significance",Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)));		 
	 Fill("h_photon_pt_met_significance",Photons[tight_photons[0]].Pt()/(TMath::Sqrt(MET.Pt())));
	 Fill("h_sum_signal_over_sqHT",sum_signal/(TMath::Sqrt(HT)));
	 Fill("h_sum_signal_over_sqMET",sum_signal/(TMath::Sqrt(MET.Pt()))); 
	 Fill("h_sum_signal_over_MET",sum_signal/MET.Pt());	 
	 if (HT > 100 ) {
		 Fill("h_met_cut",MET.Pt());	 
		 Fill("h_loose_1photons_pt_cut", Photons[loose_photons[0]].Pt() );	 
		 Fill("h_n_photon_loose_cut",loose_photons.size());	
		 Fill("h_inverse_MET_cut",1./MET.Pt()); 
	 }
	 
// Check dependency of n Vertex  -> difference in trigger efficiency
	 
	if (met_pfMet_significance < 20){
		Fill("h_vert_20",vertices_n);
		}
	else if (met_pfMet_significance < 40){
		Fill("h_vert_40",vertices_n);		
		}
	else if (met_pfMet_significance < 60){
		Fill("h_vert_60",vertices_n);		
		}		
	else if (met_pfMet_significance < 80){
		Fill("h_vert_80",vertices_n);		
		}	
	else if (met_pfMet_significance < 100){
		Fill("h_vert_100",vertices_n);		
		}			
	else if (met_pfMet_significance < 150){
		Fill("h_vert_150",vertices_n);		
		}		
	else {
		Fill("h_vert_high",vertices_n);		
		}	

	if (MET.Pt() < 125){
		Fill("h_vert_met_125",vertices_n);
		}
	else if (MET.Pt() < 150){
		Fill("h_vert_met_150",vertices_n);		
		}
	else if (MET.Pt() < 200){
		Fill("h_vert_met_200",vertices_n);		
		}		
	else if ( MET.Pt()< 250){
		Fill("h_vert_met_250",vertices_n);		
		}
	else if (MET.Pt() < 350){
		Fill("h_vert_met_350",vertices_n);		
		}				
	else {
		Fill("h_vert_met_high",vertices_n);		
		}	


/*

		4 bins in 2D MEt significance and Sigma region
		
		
																										*/
																										
double Sigma = sum_signal/(TMath::Sqrt(MET.Pt()));

if (met_pfMet_significance > 200 && Sigma > 30){
	Fill("h_upper_right_SR_HT", HT);
	Fill("h_upper_right_SR_n", loose_photons.size());
	Fill("h_upper_right_SR", Photons[tight_photons[0]].Pt() );	
  }
if (met_pfMet_significance < 200 && Sigma > 30){
	Fill("h_upper_left_SR_HT", HT);
	Fill("h_upper_left_SR_n", loose_photons.size());
	Fill("h_upper_left_SR", Photons[tight_photons[0]].Pt() );		
  }	
if (met_pfMet_significance > 200 && Sigma < 30){
	Fill("h_lower_right_SR_HT", HT);
	Fill("h_lower_right_SR_n", loose_photons.size());
	Fill("h_lower_right_SR", Photons[tight_photons[0]].Pt() );		
  }	
if (met_pfMet_significance < 200 && Sigma < 30){
	Fill("h_lower_left_SR_HT", HT);
	Fill("h_lower_left_SR_n", loose_photons.size());
	Fill("h_lower_left_SR", Photons[tight_photons[0]].Pt() );		
  }	
	
double HT_hlt = 0;
double HT_photon_had = 0;

for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
	if (Jets[cleaned_jets[i]].Pt() > 30 && fabs(Jets[cleaned_jets[i]].Eta()) < 2.5){
		HT_photon_had += Jets[cleaned_jets[i]].Pt();		
		}
	}
for (unsigned int i = 0; i < loose_photons.size(); i++) {	
	if (Photons[loose_photons[i]].Pt() > 110 && fabs(Photons[loose_photons[i]].Eta()) < 1.4442){
		HT_photon_had += Photons[loose_photons[i]].Pt();		
		}
	}
	
	
	 
for (unsigned int i = 0; i < Jets.size(); i++) {
	if (Jets[i].Pt() > 40 && fabs(Jets[i].Eta()) < 3.0){
			HT_hlt += Jets[i].Pt();
//			cout << "jet pt:  " << Jets[i].Pt() << "  fabs jet eta:   " << fabs(Jets[i].Eta()) << endl;
			}
	 }	 
/*
cout << "HT_hlt:   " << HT_hlt << endl;
cout << "HT:   " << HT << endl;
cout << "HT photon had:   " << HT_photon_had << endl;
cout << "number of jets   " << cleaned_jets.size() << endl;
*/

// Search bins with sum_signal
if (met_pfMet_significance > 200 && sum_signal > 600 ){
	pdf_selected = 1;
	Fill("h_upper_right_SR_sum_signal", Photons[tight_photons[0]].Pt() );
	Fill("h_upper_right_SR_ht", HT );	
	Fill("h_upper_right_SR_ht_trigger", HT_hlt );	
	Fill("h_upper_right_SR_ht_trigger_had", HT_photon_had );
	if ( cleaned_jets.size() > 1 ) {
		Fill("h_upper_right_SR_ht_trigger_had_2", HT_photon_had );	
		}					
  }
if (met_pfMet_significance < 200 && sum_signal > 600 ){
	pdf_selected = 2;
	Fill("h_upper_left_SR_sum_signal", Photons[tight_photons[0]].Pt() );
	Fill("h_upper_left_SR_ht", HT );	
	Fill("h_upper_left_SR_ht_trigger", HT_hlt );
	Fill("h_upper_left_SR_ht_trigger_had", HT_photon_had );
	if ( cleaned_jets.size() > 1 ) {
		Fill("h_upper_left_SR_ht_trigger_had_2", HT_photon_had );	
		}											
  }	
if (met_pfMet_significance > 200 && sum_signal < 600 ){
	pdf_selected = 4;		
	Fill("h_lower_right_SR_sum_signal", Photons[tight_photons[0]].Pt() );		
	Fill("h_lower_right_SR_ht", HT );	
	Fill("h_lower_right_SR_ht_trigger", HT_hlt );
	Fill("h_lower_right_SR_ht_trigger_had", HT_photon_had );	
	if ( cleaned_jets.size() > 1 ) {
		Fill("h_lower_right_SR_ht_trigger_had_2", HT_photon_had );	
		}									
  }	
if (met_pfMet_significance < 200 && sum_signal < 600 ){
	pdf_selected = 3;
	Fill("h_lower_left_SR_sum_signal", Photons[tight_photons[0]].Pt() );	
	Fill("h_lower_left_SR_ht", HT );
	Fill("h_lower_left_SR_ht_trigger", HT_hlt );
	Fill("h_lower_left_SR_ht_trigger_had", HT_photon_had );	
	if ( cleaned_jets.size() > 1 ) {
		Fill("h_lower_left_SR_ht_trigger_had_2", HT_photon_had );	
		}										
  }


	pdfTree->Fill();


// Search bins with MT
		
if (met_pfMet_significance > 200 && TransMassMETGamma > 500){
	Fill("h_upper_right_SR_MT", Photons[tight_photons[0]].Pt() );	
  }
if (met_pfMet_significance < 200 && TransMassMETGamma > 500){
	Fill("h_upper_left_SR_MT", Photons[tight_photons[0]].Pt() );		
  }	
if (met_pfMet_significance > 200 && TransMassMETGamma < 500){
	Fill("h_lower_right_SR_MT", Photons[tight_photons[0]].Pt() );		
  }	
if (met_pfMet_significance < 200 && TransMassMETGamma < 500){
	Fill("h_lower_left_SR_MT", Photons[tight_photons[0]].Pt() );		
  }	


/* Selection without HT cut */

	bool cut_trans_mass = (TransMassMETGamma > 350);  //if pt cut > 100, otherwise > 250
	
	bool cut_met_significance = (met_pfMet_significance > 150);
	
	bool cut_met_over_pt = ((MET.Pt()/Photons[tight_photons[0]].Pt()) > 1); //maybe reduces the right Vgamma
	
	bool cut_pt_over_HT = ((Photons[tight_photons[0]].Pt()/HT) > 0.6); //for several BGs
	
	bool cut_angle_met_1jet = (AngleMJ1 > 0.9); //especially for gammaJets if necessary
	
	bool cut_sum_signal = (sum_signal > 500); // maybe not useful after gamma pt > 100
	
	bool cut_n_jets = (cleaned_jets.size() < 3); 		// could work as undependent cut to pt & met-> looses signif. for higher
																									//mass splitting in signal
	
	bool cut_angle_photon_met = (AngleGM > 0.9);	//for several BGs
		
/*	bool cut_pt_over_sq_met_10 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(MET.Pt())) > 10);	
	bool cut_pt_over_sq_met_11 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(MET.Pt())) > 11);
	bool cut_pt_over_sq_met_12 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(MET.Pt())) > 12);	 
	bool cut_pt_over_sq_met_13 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(MET.Pt())) > 13);	
	bool cut_pt_over_sq_met_14 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(MET.Pt())) > 14);	*/
	
		
	bool cut_sum_signal_over_sq_met_25 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 25);	
	bool cut_sum_signal_over_sq_met_26 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 26);
	bool cut_sum_signal_over_sq_met_27 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 27); 	
	bool cut_sum_signal_over_sq_met_28 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 28);	
	bool cut_sum_signal_over_sq_met_29 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 29);
	bool cut_sum_signal_over_sq_met_30 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 30); 
	bool cut_sum_signal_over_sq_met_31 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 31);
	bool cut_sum_signal_over_sq_met_32 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 32);
	bool cut_sum_signal_over_sq_met_33 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 33); 
	bool cut_sum_signal_over_sq_met_34 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 34);
	bool cut_sum_signal_over_sq_met_35 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 35);	
	bool cut_sum_signal_over_sq_met_36 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 36); 
	bool cut_sum_signal_over_sq_met_37 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 37);
	bool cut_sum_signal_over_sq_met_38 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 38);	
	bool cut_sum_signal_over_sq_met_39 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 39); 
	bool cut_sum_signal_over_sq_met_40 = ( sum_signal/(TMath::Sqrt(MET.Pt())) > 40);

		
	bool cut_pt_over_sq_HT_10 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)) > 10);	
	bool cut_pt_over_sq_HT_11 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)) > 11);	
	bool cut_pt_over_sq_HT_12 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)) > 12);	
	bool cut_pt_over_sq_HT_13 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)) > 13);	
	bool cut_pt_over_sq_HT_8 = ( Photons[tight_photons[0]].Pt()/(TMath::Sqrt(HT)) > 8);
	
	bool cut_n_loose_photons = (loose_photons.size() > 1);
	
	bool cut_n_tight_photons = (tight_photons.size() > 1);
	
	bool cut_n_loose_muons = (loose_muons.size() < 1);
				
	bool cut_n_soft_muons = (soft_muons.size() < 1);
	
	bool cut_n_electrons = (medium_electrons.size() < 1);	
	
	bool cut_photon_pt_120 = ( Photons[tight_photons[0]].Pt() > 120);		
	bool cut_photon_pt_140 = ( Photons[tight_photons[0]].Pt() > 140);	
	bool cut_photon_pt_180 = ( Photons[tight_photons[0]].Pt() > 180);	
	
	bool cut_sum_signal_sq_met = (sum_signal/(TMath::Sqrt(MET.Pt())) > 30);
	
	bool cut_sum_signal_sq_ht = (sum_signal/(TMath::Sqrt(HT)) > 24);
	
				 			
//	if (cut_photon_pt) {	
		 Fill("h_stage1_met_significance",met_pfMet_significance);
		 Fill("h_stage1_met_over_pt",(MET.Pt()/Photons[tight_photons[0]].Pt()));	
		 Fill("h_stage1_pt_over_HT",(Photons[tight_photons[0]].Pt()/HT));
		 Fill("h_stage1_angle_met_1jet",AngleMJ1);
		 Fill("h_stage1_sum_signal",sum_signal);
		 Fill("h_stage1_n_jets",cleaned_jets.size());
		 Fill("h_stage1_angle_photon_met", AngleGM);
		 Fill("h_stage1_inverse_met",(1./MET.Pt()));		 
		 Fill("h_stage1_jet_pt", Jets[cleaned_jets[0]].Pt()	);
		 if(cut_angle_photon_met){
		 	Fill("h_stage2_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage2_met_significance",met_pfMet_significance);			
			}
		 if(cut_angle_met_1jet){
		 	Fill("h_stage3_inverse_met",(1./MET.Pt()));	
		 	Fill("h_stage3_met_significance",met_pfMet_significance);				 	
			}
		 if(cut_met_over_pt){
		 	Fill("h_stage4_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage4_met_significance",met_pfMet_significance);	
		 	Fill("h_stage4_N-1_pt_over_HT",(Photons[tight_photons[0]].Pt()/HT));						
			}
		 if(cut_pt_over_HT){
		 	Fill("h_stage5_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage5_met_significance",met_pfMet_significance);		
		 	Fill("h_stage5_N-1_met_over_pt",(MET.Pt()/Photons[tight_photons[0]].Pt()));					
			}	
		 if(cut_n_jets){
		 	Fill("h_stage6_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage6_met_significance",met_pfMet_significance);			
			}		
		 if(cut_sum_signal){
		 	Fill("h_stage7_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage7_met_significance",met_pfMet_significance);			
			}	
		 if(cut_met_significance){
		 	Fill("h_stage8_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage8_met_significance",met_pfMet_significance);			
			}
		 if(cut_trans_mass){
		 	Fill("h_stage9_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage9_met_significance",met_pfMet_significance);			
			}	

		
		 if(cut_sum_signal_over_sq_met_25){
		 	Fill("h_stage10_met_significance_25",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_26){
		 	Fill("h_stage10_met_significance_26",met_pfMet_significance);			
			}
		 if(cut_sum_signal_over_sq_met_27){
		 	Fill("h_stage10_met_significance_27",met_pfMet_significance);			
			}				
		 if(cut_sum_signal_over_sq_met_28){
		 	Fill("h_stage10_met_significance_28",met_pfMet_significance);			
			}
		 if(cut_sum_signal_over_sq_met_29){
		 	Fill("h_stage10_met_significance_29",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_30){
		 	Fill("h_stage10_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage10_met_significance",met_pfMet_significance);			
			}						
		 if(cut_sum_signal_over_sq_met_31){
		 	Fill("h_stage10_met_significance_31",met_pfMet_significance);			
			}	
			
		 if(cut_sum_signal_over_sq_met_32){
		 	Fill("h_stage10_met_significance_32",met_pfMet_significance);		
      Fill("h_final_n_loose_photons_blind", loose_photons.size() );		  
			Fill("h_final_n_loose_photons_unblind", loose_photons.size() );	
			FillPerGev("h_final_MET_significance_blind",met_pfMet_significance);
			FillPerGev("h_final_MET_significance_unblind",met_pfMet_significance);	
			}
				
		 if(cut_sum_signal_over_sq_met_33){
		 	Fill("h_stage10_met_significance_33",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_34){
		 	Fill("h_stage10_met_significance_34",met_pfMet_significance);			
			}				
		 if(cut_sum_signal_over_sq_met_35){
		 	Fill("h_stage10_met_significance_35",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_36){
		 	Fill("h_stage10_met_significance_36",met_pfMet_significance);			
			}	
		 if(cut_sum_signal_over_sq_met_37){
		 	Fill("h_stage10_met_significance_37",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_38){
		 	Fill("h_stage10_met_significance_38",met_pfMet_significance);			
			}				
		 if(cut_sum_signal_over_sq_met_39){
		 	Fill("h_stage10_met_significance_39",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_over_sq_met_40){
		 	Fill("h_stage10_met_significance_40",met_pfMet_significance);			
			}						
			
			
		 if(cut_pt_over_sq_HT_10){
		 	Fill("h_stage11_met_significance_10",met_pfMet_significance);			
			}	
		 if(cut_pt_over_sq_HT_11){
		 	Fill("h_stage11_met_significance_11",met_pfMet_significance);			
			}			
		 if(cut_pt_over_sq_HT_12){
		 	Fill("h_stage11_inverse_met",(1./MET.Pt()));
		 	Fill("h_stage11_met_significance",met_pfMet_significance);			
			}			
		 if(cut_pt_over_sq_HT_13){
		 	Fill("h_stage11_met_significance_13",met_pfMet_significance);			
			}						
		 if(cut_pt_over_sq_HT_8){
		 	Fill("h_stage11_met_significance_8",met_pfMet_significance);			
			}	
			
		 if(cut_n_loose_photons){
		 	Fill("h_stage12_met_significance",met_pfMet_significance);			
			}			
		 if(cut_n_tight_photons){
		 	Fill("h_stage13_met_significance",met_pfMet_significance);			
			}					
		 if(cut_n_loose_muons){
		 	Fill("h_stage14_met_significance",met_pfMet_significance);			
			}			
		 if(cut_n_soft_muons){
		 	Fill("h_stage15_met_significance",met_pfMet_significance);			
			}			
		 if(cut_n_electrons){
		 	Fill("h_stage16_met_significance",met_pfMet_significance);			
			}					
		 if(cut_photon_pt_180){
		 	Fill("h_stage17_met_significance",met_pfMet_significance);			
			}	
		 if(cut_photon_pt_120){
		 	Fill("h_stage20_met_significance",met_pfMet_significance);			
			}			
		 if(cut_photon_pt_140){
		 	Fill("h_stage21_met_significance",met_pfMet_significance);			
			}	
							
		 if(cut_sum_signal_sq_met){
		 	Fill("h_stage18_met_significance",met_pfMet_significance);			
			}			
		 if(cut_sum_signal_sq_ht){
		 	Fill("h_stage19_met_significance",met_pfMet_significance);			
			}			
					
		 if (cut_met_over_pt && cut_pt_over_HT){
		 	Fill("h_stage1_N-1_met_ratio_pt_ratio",met_pfMet_significance);			
			
		 	}												
		
	//	}
		
		
	 
 if (HT < 250) {
	
	 sum_pt = 0;
	 sum_p = 0.000000001;
	 sum_photon_pt = 0;
	 sum_photon_p = 0.000000001;
	 	 
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
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
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
	 	 EtaTest = fabs(Jets[cleaned_jets[i]].Eta());
		 if (EtaTest < EtaLow){
				EtaLow = EtaTest;
				indexi = i;
				}
	   }
	 for (unsigned int j = 0; j < cleaned_jets.size(); j++) {
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

	
	bool cut_jet_pt = true; //100; // (Jets[cleaned_jets[0]].Pt() > 100);
	bool cut_sum_pt = true; //(sum_pt > 350);
	bool cut_sum_signal = true; //(sum_signal > 450);	
	bool cut_m_t 		= (TransMassMETGamma > 300);
	
/* Meeting 24.02. fuer significance 
	
	bool cut_jet_pt = true; // (Jets[cleaned_jets[0]].Pt() > 100);
	bool cut_sum_pt = (sum_pt > 350);
	bool cut_m_t 		= (TransMassMETGamma > 400);	*/

  bool e_fake = false;
	for (unsigned int i = 0; i < GenParticles.size() ; i++) {
	 		if (GenParticles[i].GenStatus == 1) {
					if ((GenParticles[i].GenPDGID == 11 || GenParticles[i].GenPDGID == -11)) {
							if(GenParticles[i].DeltaR(Photons[tight_photons[0]]) < 0.1 ) {
								e_fake = true;
								}		
							}
											
					}
			}
	if ( !e_fake ) {	
	
	
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
	}
		
 }else{
 
	 sum_pt = 0;
	 sum_p = 0.000000001;
	 sum_photon_pt = 0;
	 sum_photon_p = 0.000000001;
	 	 
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
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
			Fill("h_selection_high2_met_sign", met_pfMet_significance); 
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
	 for (unsigned int i = 0; i < cleaned_jets.size(); i++) {
	 	 EtaTest = fabs(Jets[cleaned_jets[i]].Eta());
		 if (EtaTest < EtaLow){
				EtaLow = EtaTest;
				indexi = i;
				}
	   }
	 for (unsigned int j = 0; j < cleaned_jets.size(); j++) {
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
	bool cut_ptOverHt		= true; //(sum_photon_pt/(TMath::Sqrt(HT)) > 0.5);
	// bool cut_HT_over_MET = (HT/MET.Pt() < 2);
	bool cut_MET_sig 		 = (MET.Pt()/(TMath::Sqrt(HT)) > 12);	
	
	
  bool e_fake = false;
	for (unsigned int i = 0; i < GenParticles.size() ; i++) {
	 		if (GenParticles[i].GenStatus == 1) {
					if ((GenParticles[i].GenPDGID == 11 || GenParticles[i].GenPDGID == -11)) {
							if(GenParticles[i].DeltaR(Photons[tight_photons[0]]) < 0.1 ) {
								e_fake = true;
								}		
							}
											
					}
			}
	if ( !e_fake ) {	
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
		Fill("h_N-1_sum_ptOverHt_high", sum_photon_pt/(TMath::Sqrt(HT)) );
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

 }	
 
 }
 
 #endif

	 
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
