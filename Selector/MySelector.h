#ifndef MYSELECTOR_H
#define MYSELECTOR_H


#include "TH1F.h"
#include "TH2F.h"
#include <map>
#include <string>
#include <vector>

#include "MyPhoton.h"
#include "MyJet.h"
#include "MyElectron.h"
#include "MyMuon.h"
#include "MyPfParticle.h"
#include "MyGenParticles.h"
#include "MyVertices.h"
#include "MyTracks.h"
#include "HistoWorking.h"
#include "HistoWorking2.h"
#include "TLorentzVector.h"


#ifdef __MC

#include "MCSelector.h"
class MySelector : public MCSelector {

  public:
   MySelector(TTree * /*tree*/=0):MCSelector(0){}

#else

#include "DataSelector.h"
class MySelector : public DataSelector {

  public:
   MySelector(TTree *tree=0):DataSelector(tree){}

#endif 

	 
   virtual ~MySelector() { }

   virtual Int_t   Version() const { return 2; }
	 void 					 AddSignalTrigger(TString const& v) { SignalNames.push_back(v + "_v*"); }
	 void 					 AddPhotonHadTrigger(TString const& v) { PhotonHadNames.push_back(v + "_v*"); }	 
	 void 					 AddMETTrigger(TString const& v) { METNames.push_back(v + "_v*"); }
	 void 					 AddIsoGammaTrigger(TString const& v) { IsoGammaNames.push_back(v + "_v*"); }
	 void 					 AddDisplacedTrigger(TString const& v) { DisplacedNames.push_back(v + "_v*"); }
	 void 					 AddGamma135Trigger(TString const& v) { Gamma135Names.push_back(v + "_v*"); }	 
	 void 					 AddGamma30Trigger(TString const& v) { Gamma30Names.push_back(v + "_v*"); }		 
	 void 					 AddHLTPhysicsTrigger(TString const& v) { HLTPhysicsNames.push_back(v + "_v*"); }		 	 
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual Bool_t  Process(Long64_t entry);
   virtual void    SlaveTerminate();
   virtual void    Terminate();
	 virtual void 	 CreateHisto(const char * name, const char * title, int nBins, double xlow, double xup);
	 virtual void 	 CreateHisto2D(const char * name, const char * title, int nbinsx, double xlow, double xup, int nbinsy, double ylow,
	 double yup);
	 virtual void 	 CreateHistoArray(const char * name, const char * title, int nBins, const float * bins );
	// virtual void	  Fill(const char * name, double value);
	 virtual void		 Fill(const char * name, double value, double weight = 1.);
	 virtual void		 FillPerGev(const char * name, double value, double weight = 1.);	 
	 virtual void		 Fill(const char * name, const char * text, double weight = 1.);
	 virtual void 	 FillArray(const char * name, double value, double weight = 1.);
	 virtual void 	 FillArrayInverse(const char * name, double value, double weight = 1.);	 
	 virtual void 	 FillArraySignificance(const char * name, double value, double weight = 1.);
	 virtual void 	 FillMETsign(const char * name, double value, double weight = 1.);	 
	 virtual void 	 Fill2(const char * name, double x, double y);
	 virtual void	   BuildObjects();
	 virtual void 	 SetLumiWeight(double weight);
	 virtual void 	 BGInfo(std::string const & BG);	 
	 virtual void 	 SetPileUpWeightFile( std::string const & filename );
	 TTree* GetPdfTree(){ return pdfTree;}
	 
	 float getPileUpWeight();
	 double Eventweight;
	 string BGName;
   bool 		PassSignalTrigger() const;
   bool 		PassPhotonHadTrigger() const;	 
   bool 		PassMETTrigger() const;	 
   bool 		PassIsoGammaTrigger() const;	
   bool 		PassDisplacedTrigger() const;	 
   bool 		PassGamma135Trigger() const;	
   bool 		PassGamma30Trigger() const;	
   bool 		PassHLTPhysicsTrigger() const;	    
	 double zTiggerHitsInRun; 
	 double nTiggerHitsInRun;
	 int RunNumberCheck;

	 vector<MyPhoton> Photons;
	 vector<MyElectron> Electrons;	
	 vector<MyMuon> Muons;	  
	 vector<MyJet> Jets;
	 vector<MyPfParticle> PfParticles;
	 vector<MyGenParticles> GenParticles;	
	 vector<MyVertices> Vertices; 
	 vector<MyTracks> Tracks;
	 TLorentzVector MET;
	 TLorentzVector TypeOneMET; 
	 TLorentzVector metMET;
	 TLorentzVector CaloMET;
	 
	 int vertices_n;


	 HistoWorking histo;
	 HistoWorking2 histo2;	 

  //private member functions
  private:
//   void CreateHisto(const char * name, const char * title, Int_t nbinsx, Double_t xlow, Double_t xup);
//   void CreateHistoArray(const char * name, const char * title, Int_t nbinsx, const Float_t* xbins);
   bool isTightIsolated(unsigned i) const;
   bool QcdWeightSelection() const;
   bool IsTightPhoton(unsigned i) const;
   bool IsLoosePhoton(unsigned i) const;
   TTree* pdfTree;
   float pdf_x1, pdf_x2, pdf_scale, pdf_id1, pdf_id2, pdf_weight, pdf_selected;
	 
	 protected:
	 std::vector<TString> PhotonHadNames;	 
	 std::vector<TString> SignalNames;
	 std::vector<TString> METNames;
	 std::vector<TString> IsoGammaNames;   
	 std::vector<TString> DisplacedNames;
	 std::vector<TString> Gamma135Names;
	 std::vector<TString> Gamma30Names;	 
	 std::vector<TString> HLTPhysicsNames;		 

  //public member variables
  public: 
	TH1F *pileupHisto;

};

bool LorentzVectorSortPt(const TLorentzVector & l1,const TLorentzVector & l2);
	 
#endif
