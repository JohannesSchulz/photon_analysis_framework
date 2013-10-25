#ifndef MYPHOTON_H
#define MYPHOTON_H

#include <TLorentzVector.h>
#include <iostream>


class MyPhoton: public TLorentzVector {

public:

  MyPhoton();
  MyPhoton(Double_t P_x, Double_t P_y, Double_t P_z, Double_t E) {
    SetPxPyPzE(P_x, P_y, P_z, E);
  };

  virtual ~MyPhoton();
	
	int nPixelSeeds;
	
	
/*	Set variables to check for isolation etc. 
		variables are set in MySelector and chosen
		from NtupleSelector.h */

  void SetPhotonPt(double x) {
    pt = x;
  	}
	
  void SetCaloEta(double x) {
    calo_Eta = x;
  	}	
	
  void SetRho25(double x) {
    rho25 = x;
 	  }
	
	void SetChargedHadronIso(double x) {
		chargedHadronIso = x;
		}
		
	void SetNeutralHadronIso(double x) {
		neutralHadronIso = x;
		}
		
		
	void SetPhotonIso(double x) {
		photonIso = x;
		}

	void SetSigmaIetaIeta(double x) {
		sigmaIetaIeta = x;
		}

	void SetSigmaIphiIphi(double x) {
		sigmaIphiIphi = x;
		}

	void SetNPixelSeeds(int x) {
		nPixelSeeds = x;
		}

	void SetHadTowOverEm(double x) {
		hadTowOverEm = x;
		}
		
	
	/*Calculate corrected Isolation values */	
		
	double GetChargedHadronIso_corrected() {
        /** Correct isolation for charged hadrons,
         * see https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedPhotonID2012
         */
        double eta = fabs(calo_Eta);
        double ea;

				/* see https://twiki.cern.ch/twiki/bin/viewauth/CMS/SusyPhotonID */

        if(eta < 1.0)				 ea = 0.012;
        else if(eta < 1.479) ea = 0.010;
        else if(eta < 2.0)	 ea = 0.014;
        else if(eta < 2.2)	 ea = 0.012;
        else if(eta < 2.3)	 ea = 0.016;
        else if(eta < 2.4)	 ea = 0.020;
        else 								 ea = 0.012;

        double iso = chargedHadronIso;
        iso = std::max(iso - rho25*ea, (double)0.);

        return iso;
				}

	double GetNeutralHadronIso_corrected() {
        /** Correct isolation for neutral hadrons,
         * see https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedPhotonID2012
         */
        double eta = fabs(calo_Eta);
        double ea;

				/* see https://twiki.cern.ch/twiki/bin/viewauth/CMS/SusyPhotonID */

        if(eta < 1.0) 			 ea = 0.030;
        else if(eta < 1.479) ea = 0.057;
        else if(eta < 2.0)	 ea = 0.039;
        else if(eta < 2.2)	 ea = 0.015;
        else if(eta < 2.3)	 ea = 0.024;
        else if(eta < 2.4)	 ea = 0.039;
        else 								 ea = 0.072;

        double iso = neutralHadronIso;
        iso = std::max(iso - rho25*ea, (double)0.);

        return iso;
				}


	double GetPhotonIso_corrected() {
        /** Correct isolation for photons,
         * see https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedPhotonID2012
         */
        double eta = fabs(calo_Eta);
        double ea;

				/* see https://twiki.cern.ch/twiki/bin/viewauth/CMS/SusyPhotonID */

        if(eta < 1.0)				 ea = 0.148;
        else if(eta < 1.479) ea = 0.130;
        else if(eta < 2.0)	 ea = 0.112;
        else if(eta < 2.2)	 ea = 0.216;
        else if(eta < 2.3)	 ea = 0.262;
        else if(eta < 2.4)	 ea = 0.260;
        else								 ea = 0.266;

        double iso = photonIso;
        iso = std::max(iso - rho25*ea, (double)0.);

        return iso;
				}

	
	const bool PtTest()	{
		return ( pt > 100 );
		}


/*	Serve bool IsLooseIsolated to save vectors 
		in analysis code vector<int> loose_photons 
		for further analysis !!loose photons are
		our correct photons!! */
		
  const bool IsLooseIsolated() {
    return ( hadTowOverEm  			 < 0.05  &&
             sigmaIetaIeta			 < 0.012 &&
             chargedHadronIso    < 2.6   &&
             neutralHadronIso    < 3.5 + 0.04*pt  &&
             photonIso     			 < 1.3 + 0.005*pt &&
						 nPixelSeeds				 < 1 );
  	}; 

private:

  double isolation;
	double pt;
	double calo_Eta;
	double rho25;
	double chargedHadronIso;
	double neutralHadronIso;
	double photonIso;
	double sigmaIetaIeta;
	double sigmaIphiIphi;
	double hadTowOverEm;
	
};

#endif
