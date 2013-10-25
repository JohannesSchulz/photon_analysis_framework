
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

using namespace std;

void MySelector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   

}


/*void MySelector::CreateHisto(const char * name, const char * title, Int_t nbinsx, Double_t xlow, Double_t xup)
{
	//TH1F* h;
  //histo[name]
	histo[name] = new TH1F(name, title, nbinsx, xlow, xup);
	//fOutput->Add(histo[name]); 
} 

void MySelector::CreateHistoArray(const char * name, const char * title, Int_t nbinsx, const Float_t* xbins)
{
	//TH1F* h;
  //Form(name,h)
	histo[name] = new TH1F(name, title, nbinsx, xbins);
//	fOutput->Add(histo[name]);
}
*/


void MySelector::SlaveBegin(TTree * tree)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   //initialize the Tree branch addresses
   Init(tree);
	// TH1::SetDefaultSumw2();

   //print the option specified in the Process function.
   TString option = GetOption();
   Info("SlaveBegin",
        "starting h1analysis with process option: %s (tree: %p)", option.Data(), tree);


	 int nbins = 17;
   float binning[] = {0, 70, 80, 90, 100, 120, 140, 160, 180, 200, 250, 300, 350, 400, 500, 600, 700, 800};
	 

   h_weight_photonpt = new TH1F("h_weight_photonpt",";photon pT [GeV];entries",nbins,binning);
   h_weight_fakept = new TH1F("h_weight_fakept",";fake-photon pT [GeV];entries",nbins,binning);
   
   ///////own histos
	 //h_cutflow = new TH1F("cutflow", "cutflow", 7, 0, 7);
	 
	 
	/* h_cutflow->Fill("all", 0);
	 h_cutflow->Fill("# #gamma>0", 0);
	 h_cutflow->Fill("#gamma p_{T}>35", 0);
	 h_cutflow->Fill("#MET>30", 0);*/
	 


	 CreateHisto("h_met", "MET", 32, 0, 800);	 
  // h_met 										= new TH1F("h_met","met distribution",32,0,800);
	 h_DPhi_met_highjet 			= new TH1F("h_DPhi_met_highjet", "#Delta #Phi(met,jet)",20,0,3.2);
	 h_Phi_jet 								= new TH1F("h_Phi_jet", "#Phi(jet)",20,0,3.2);
	 h_Phi_jet2 							= new TH1F("h_Phi_jet2", "#Phi(jet)",20,0,3.2);
	 h_Phi_jet3 							= new TH1F("h_Phi_jet3", "#Phi(jet)",20,0,3.2);
	 h_Phi_met 								= new TH1F("h_Phi_met", "#Phi(met)",20,0,3.2); 
	 h_n_photon 							= new TH1F("h_n_photon", " # of photons",10, -0.5, 9.5);
   h_n_photon_2 						= new TH1F("h_n_photon_2", " # of photons",10, -0.5, 9.5);
   h_n_photon_loose					= new TH1F("h_n_photon_loose", " # of photons",10, -0.5, 9.5);
   h_loose_n 								= new TH1F("h_loose_n", " # of loose photons",10, -0.5, 9.5);
	 h_tight_n 								= new TH1F("h_tight_n", " # of tight photons",10, -0.5, 9.5);
	 h_photon_tight_DeltaPhi  = new TH1F("h_photon_tight_DeltaPhi", "#Delta #Phi(met,tight_photon)",20,0,3.2);
	 h_HT 										= new TH1F("h_HT",";HT of all jets [GeV];entries",24,0.,1200);
	 h_n_jet		 							= new TH1F("h_n_jet", " # of jets",10, -0.5, 9.5);
	 h_n_jet2 								= new TH1F("h_n_jet2", " # of jets",10, -0.5, 9.5);
	 

	 ///////
	 
	 
	/* CreateHistoArray("h_weight_photonpt",";photon pT [GeV];entries",nbins,binning);
	 CreateHistoArray("h_weight_fakept",";fake-photon pT [GeV];entries",nbins,binning);
	 CreateHistoArray("h_met","met distribution",nbins,binning); 
	 CreateHisto("h_DPhi_met_highjet", "#Delta #Phi(met,jet)",20,0,3.2); */
//	 CreateHisto("Phi_jet", "#Phi(jet)",20,0,3.2);
//	 CreateHisto("h_Phi_met", "#Phi(met)",20,0,3.2);
	 
	/* 
	 fOutput->Add(h_weight_photonpt);
   fOutput->Add(h_weight_fakept);
	 
	 //fOutput->Add(h_cutflow);
	 fOutput->Add(h_met);
	 fOutput->Add(h_DPhi_met_highjet);
	 fOutput->Add(h_Phi_met);
	 fOutput->Add(h_Phi_jet);
	 fOutput->Add(h_Phi_jet2);
	 fOutput->Add(h_Phi_jet3);
	 fOutput->Add(h_n_photon);
	 fOutput->Add(h_n_photon_2);
	 fOutput->Add(h_n_photon_loose);
	 fOutput->Add(h_loose_n);
	 fOutput->Add(h_tight_n);
	 fOutput->Add(h_photon_tight_DeltaPhi);
	 fOutput->Add(h_HT);
	 fOutput->Add(h_n_jet);
	 fOutput->Add(h_n_jet2);*/
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
			TVector3 caloPos(photons_photons_caloPosition_fX[i], photons_photons_caloPosition_fY[i], photons_photons_caloPosition_fZ[i]); 
			double calo_Eta = caloPos.Eta();
			photon.SetPhotonPt(photon_pt);
			photon.SetCaloEta(calo_Eta);
			photon.SetRho25(rho25);
			photon.SetChargedHadronIso(photons_photons_chargedHadronIso[i]);
			photon.SetNeutralHadronIso(photons_photons_neutralHadronIso[i]);
			photon.SetPhotonIso(photons_photons_photonIso[i]);
			photon.SetSigmaIetaIeta(photons_photons_sigmaIetaIeta[i]);
			photon.SetSigmaIphiIphi(photons_photons_sigmaIphiIphi[i]);
			photon.SetNPixelSeeds(photons_photons_nPixelSeeds[i]);
			photon.SetHadTowOverEm(photons_photons_hadTowOverEm[i]);
			
    //  photon.SetIsolation(Photon_Iso[i]);
      Photons.push_back(photon);
   }
	
	MET.SetXYZM(met_pfMet_mEt_fX, met_pfMet_mEt_fY, 0, 0); 
}

void MySelector::CreateHisto(const char * name, const char * title,
			     int nBins, double xlow, double xup)
{
  TH1F * h = new TH1F(name, title, nBins, xlow, xup);
  h->SetXTitle(title);
  h->SetTitle(name);
  histo.Add(name, h);
}



void MySelector::Fill(const char * name, double value)
{
  TH1F * h = histo[name];
  if (h != 0)
    h->Fill(value);
  else {
    std::cout << std::string("Histogram \"") + name + std::string("\" not existing. Did you misspell or forgot to create?") << std::endl;
  }
}


/*
bool MySelector::QcdWeightSelection() const
{
  return (met<100. && ht>450.);
}

bool MySelector::isTightIsolated(unsigned i) const
{
    float pt = photon_pt[i];
    return ( photon_hadTowOverEm[i]  < 0.05  &&
             photon_sigmaIetaIeta[i] < 0.012 &&
             photon_chargedIso[i]    < 2.6    &&
             photon_neutralIso[i]    < 3.5 + 0.04*pt  &&
             photon_photonIso[i]     < 1.3 + 0.005*pt );
}


bool MySelector::IsTightPhoton(unsigned i) const
{  
    return( photon_pt[i] > 80. && 
						std::abs(photon_eta[i]) < 1.4442 &&
						!photon_pixelseed[i] &&
						isTightIsolated(i)			           );
}

bool MySelector::IsLoosePhoton(unsigned i) const
{
    //same as tight
    float pt = photon_pt[i];
		return ( pt > 80. &&
						 std::abs(photon_eta[i]) < 1.4442 &&
						 !photon_pixelseed[i] &&
  				   //loose isolation
  					 photon_sigmaIetaIeta[i] < 0.014 &&    
    				 photon_hadTowOverEm[i]  < 0.15  &&     
    				 photon_chargedIso[i]    < 4.6   &&       
    				 photon_neutralIso[i]    < 4.5 + 0.04*pt &&
						//    if ( photon_photonIso[i]     > 4 + 0.01*pt ) continue;
   					 //not tight isolated!!
					 	 !isTightIsolated(i)          );
}
*/

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

	 BuildObjects();
   //read full event:
   fChain->GetTree()->GetEntry(entry);
	 
	 //Get background file
	 int p = fChain->GetTreeNumber();
	// std::cout << "file: " << p << std::endl;
	 
   //std::cout << "file location: " << s << std::endl;
	 //cout << "Starting Process for event: " << entry << endl;
 
   //read only specific branches: 
	 //(may be faster if a lot are unused and selection is nearly final)
	 
/*   b_met->GetEntry(entry);
   b_ht->GetEntry(entry);
   b_photon_pt->GetEntry(entry);   
   b_photon_eta->GetEntry(entry);
   b_photon_pixelseed->GetEntry(entry);
   b_photon_sigmaIetaIeta->GetEntry(entry);
   b_photon_hadTowOverEm->GetEntry(entry);
   b_photon_chargedIso->GetEntry(entry);
   b_photon_neutralIso->GetEntry(entry);
   b_photon_photonIso->GetEntry(entry);
	 b_jet_phi->GetEntry(entry);
	 b_metPhi->GetEntry(entry);*/
 
 
  // if (!QcdWeightSelection()) return kFALSE;


	 //Laufvariablen
	 
   unsigned idx_photon = 0;
	 unsigned idx_jet = 0;
	 
	 // Define cuts
	 
	 bool cut_n_photon  = (Photons.size() > 0);
	 bool cut_photon_pt = (Photons[0].Pt() > 35); // if exactely one photon is reqired [0] is sufficient
	 bool cut_met			  = (MET.Pt() > 30);
	 
	 //vector definition to get the index of specified objects
//	 vector<int> photons;
//	 vector<int> tight_photons; 

	 vector<int> loose_photons;
	 
//	 vector<int> jets;
//	std::cout << "---------------Test Area-------------------" << std::endl;	
//	cout << "Anzahl Photons:  " << Photons.size() << endl;	 
   for (unsigned int i = 0; i < Photons.size(); i++) {
  //  h_pt_photon->Fill(Photons[i].Pt());
	/*	std::cout<<"------------------------------------------"<<std::endl;	
		cout << "Photon pt = " << Photons[i].Pt() << " and bool pt > 100 says : " << Photons[i].PtTest() << endl;
		cout << "corrected charged hadron iso:  " << Photons[i].GetChargedHadronIso_corrected() << endl;
		cout << "corrected neutral hadron iso:  " << Photons[i].GetNeutralHadronIso_corrected() << endl;
		cout << "corrected photon iso:  " << Photons[i].GetPhotonIso_corrected() << endl;
		cout << "number of Pixelseeds:   " << Photons[i].nPixelSeeds << endl;
		cout << "Photon is a loose isolated photon:  " << Photons[i].IsLooseIsolated() << endl; */
		if ( Photons[i].IsLooseIsolated() ) {
			loose_photons.push_back(i);
	//	  cout << "Photon is a loose isolated photon:  " << Photons[i].IsLooseIsolated() << endl;
			}
	}
//	cout << "Anzahl loose photons:   " << loose_photons.size() << endl;
//	std::cout << "-------------------------------------------" << std::endl;
	 
	 h_n_photon->Fill(photons_photons_);
	 h_n_photon_2->Fill(Photons.size());
	 h_n_photon_loose->Fill(loose_photons.size());

	 
	 /* Require trigger selection taking turn-on into account */
	 
	 
	 
	 // Plots vor und nach Cuts machen
	 
	// h_cutflow->Fill(0); 
	 
	 if (cut_n_photon == false) return kFALSE; // at least one photon
	// h_cutflow->Fill(1);
	 //cutflow ??
	 if (cut_photon_pt == false) return kFALSE; // photon has at least pt > 35 GeV 
	// h_cutflow->Fill(2);
	 if (cut_met == false) return kFALSE; // met at least 30 GeV
	// h_cutflow->Fill(3);
	
	 
	/////////Fill met for all events
	Fill("h_met",MET.Pt());
	
	
	/////////
/*	Float_t DeltaPhi_met_highjet = DeltaPhi(metPhi,jet_phi[idx_jet]);
	Float_t Phi_jet = fabs(jet_phi[idx_jet]);
	h_DPhi_met_highjet->Fill(DeltaPhi_met_highjet);
	h_Phi_met->Fill(fabs(metPhi));
	
  for (;idx_jet<jet_;++idx_jet){
		
			if ( p == 0){ h_Phi_jet->Fill(fabs(jet_phi[idx_jet]));}
		  if ( p == 1){ h_Phi_jet2->Fill(fabs(jet_phi[idx_jet]));}
			if ( p == 2){ h_Phi_jet3->Fill(fabs(jet_phi[idx_jet]));}
		
	}
	
   //sort tight and loose photons
   for (;idx_photon < photon_;idx_photon++){
	 	//	 photons.push_back(idx_photon);
       if (IsTightPhoton(idx_photon)) {
			 tight_photons.push_back(idx_photon);
			 }
       if (IsLoosePhoton(idx_photon)) {
			 loose_photons.push_back(idx_photon);
			 }
       //if (!IsLoosePhoton(idx_photon) && !IsTightPhoton(idx_photon)) {
		//	 return kFALSE; //useless event
		//	 }
   }
	 
 // Define own jets -> jet ID?
 for (int i = 0 ; i < jet_ ;i++){
	 jets.push_back(i); 
 	 }
	 
	 
 int tight_photon_n = tight_photons.size();
 int loose_photon_n = loose_photons.size();
 int jets_n = jets.size();
 h_loose_n->Fill(loose_photon_n); 
 h_tight_n->Fill(tight_photon_n);
 
 for (unsigned i = 0; i < tight_photon_n; i++){
 	 h_photon_tight_DeltaPhi->Fill(fabs(DeltaPhi(metPhi,photon_phi[tight_photons[i]])));
	 }
	 
 float HT = 0;  // Defined as usually -> Must be modified in this analysis
 for (int i = 0; i < jets_n; i++) { 
      HT += jet_pt[jets[i]]; 
      }
			
		
 h_HT->Fill(HT);
 h_n_jet->Fill(jets_n);
 h_n_jet2->Fill(jet_);
 */
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
   

 /*  h_weight_photonpt 				= dynamic_cast<TH1F *>(fOutput->FindObject("h_weight_photonpt"));
   h_weight_fakept   				= dynamic_cast<TH1F *>(fOutput->FindObject("h_weight_fakept"));
	 h_DPhi_met_highjet				= dynamic_cast<TH1F *>(fOutput->FindObject("h_DPhi_met_highjet"));
   h_Phi_met				 				= dynamic_cast<TH1F *>(fOutput->FindObject("h_Phi_met"));
	 h_Phi_jet				 				= dynamic_cast<TH1F *>(fOutput->FindObject("h_Phi_jet"));
	 h_Phi_jet2				 				= dynamic_cast<TH1F *>(fOutput->FindObject("h_Phi_jet2"));
	 h_Phi_jet3							  = dynamic_cast<TH1F *>(fOutput->FindObject("h_Phi_jet3"));
	 h_met 									  = dynamic_cast<TH1F *>(fOutput->FindObject("h_met"));
	 h_n_photon				 				= dynamic_cast<TH1F *>(fOutput->FindObject("h_n_photon"));
	 h_n_photon_2			 				= dynamic_cast<TH1F *>(fOutput->FindObject("h_n_photon_2"));
	 h_n_photon_loose	 				= dynamic_cast<TH1F *>(fOutput->FindObject("h_n_photon_loose"));
	 h_loose_n				 				= dynamic_cast<TH1F *>(fOutput->FindObject("h_loose_n"));
	 h_tight_n				 			  = dynamic_cast<TH1F *>(fOutput->FindObject("h_tight_n"));
	 h_photon_tight_DeltaPhi  = dynamic_cast<TH1F *>(fOutput->FindObject("h_photon_tight_DeltaPhi"));
	 h_HT										  = dynamic_cast<TH1F *>(fOutput->FindObject("h_HT"));
	 h_n_jet								  = dynamic_cast<TH1F *>(fOutput->FindObject("h_n_jet"));
	 h_n_jet2								  = dynamic_cast<TH1F *>(fOutput->FindObject("h_n_jet2"));
	// h_cutflow				 = dynamic_cast<TH1F *>(fOutput->FindObject("h_cutflow"));	
	*/
	 
	 std::string fileName = "results.root";
   
// Create a canvas, with 100 pads
/*   TCanvas *c1 = new TCanvas("c1", "Proof canvas 1",3,3,600,600);
	 c1->Divide(1,2);
   c1->cd(1);
   if (h_weight_photonpt) h_weight_photonpt->Draw("h");
	 c1->Update();
	 c1->cd(2);
	 h_met->Draw("h");
   c1->Update();

	
	 if (h_weight_fakept && h_weight_photonpt) {
     TCanvas *c3 = new TCanvas("c3", "Proof canvas 3",3,3,600,600);
     c3->cd();
     
     h_weight_fakept->Sumw2();
     h_weight_photonpt->Sumw2();
     TH1F * h_weight = (TH1F*)h_weight_photonpt->Clone();
     h_weight->Divide( h_weight_fakept );

     TH1F * h_w1m = (TH1F*)h_weight_photonpt->Clone();
     TH1F * h_w1p = (TH1F*)h_weight_photonpt->Clone();
     for (int i=0; i<=h_w1m->GetXaxis()->GetNbins()+1;++i) {
       h_w1m->SetBinContent(i, h->GetBinContent(i)-h->GetBinError(i));
       h_w1p->SetBinContent(i, h->GetBinContent(i)+h->GetBinError(i));
     }
     h_w1m->SetLineColor(2);
     h_w1p->SetLineColor(8);

     h_weight->GetXaxis()->SetTitle("photon-object pT [GeV]");
     h_weight->GetYaxis()->SetTitle("QCD weight");
     h_weight->GetYaxis()->SetTitleOffset(1.4);
     h_weight->Draw("pe");
     c3->Update(); */
 
  /*   TFile* file = new TFile(fileName.c_str(),"recreate");
     file->cd();
		 h_met->Write("met");
		 h_DPhi_met_highjet->Write("DPhi_met_highjet");
		 h_Phi_met->Write("Phi_met");
		 h_Phi_jet->Write("Phi_jet");
		 h_Phi_jet2->Write("Phi_jet2");
		 h_Phi_jet3->Write("Phi_jet3");
     h_n_photon->Write("n_photon");
     h_n_photon_2->Write("n_photon_2");
     h_n_photon_loose->Write("n_photon_loose");
		 h_tight_n->Write("n_tight");
     h_loose_n->Write("n_loose");
		 h_photon_tight_DeltaPhi->Write("photon_tight_DeltaPhi");
		 h_HT->Write("HT");
		 h_n_jet->Write("n_jet");
		 h_n_jet2->Write("n_jet2");
		 file->Write();
     file->Close();
   //  delete file;

  */ 
   std::cout << "End of terminate()" <<std::endl;
}
