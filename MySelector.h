#ifndef MYSELECTOR_H
#define MYSELECTOR_H

#include "NtupleSelector.h"

#include "TH1F.h"
#include <map>
#include <string>
#include <vector>

#include "MyPhoton.h"
#include "HistoWorking.h"

class MySelector : public NtupleSelector {

  public:
   MySelector(TTree * /*tree*/=0):NtupleSelector(0){}
   virtual ~MySelector() { }

   virtual Int_t   Version() const { return 2; }

   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();
	 virtual void 	 CreateHisto(const char * name, const char * title, int nBins, double xlow, double xup);
	 virtual void		 Fill(const char * name, double value);
	 virtual void	   BuildObjects();
	 
	 
	 vector<MyPhoton> Photons;
	 TLorentzVector MET;

	 HistoWorking histo;

  //private member functions
  private:
//   void CreateHisto(const char * name, const char * title, Int_t nbinsx, Double_t xlow, Double_t xup);
//   void CreateHistoArray(const char * name, const char * title, Int_t nbinsx, const Float_t* xbins);
   bool isTightIsolated(unsigned i) const;
   bool QcdWeightSelection() const;
   bool IsTightPhoton(unsigned i) const;
   bool IsLoosePhoton(unsigned i) const;
   
   


  //public member variables
  public: 
   TH1F* h_weight_photonpt;
   TH1F* h_weight_fakept;
	// TH1F* h_cutflow;
   TH1F* h_met;
   TH1F* h_DPhi_met_highjet;
   TH1F* h_Phi_met;
   TH1F* h_Phi_jet;
   TH1F* h_Phi_jet2;
   TH1F* h_Phi_jet3;
	 TH1F* h_n_photon;
	 TH1F* h_n_photon_2;
	 TH1F* h_n_photon_loose;
	 TH1F* h_n_jet;
	 TH1F* h_n_jet2;
	 TH1F* h_photon_tight_DeltaPhi;
	 TH1F* h_tight_n;
	 TH1F* h_loose_n;
	 TH1F* h_HT;
};

#endif
