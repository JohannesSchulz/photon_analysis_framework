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
	double chargedHadronIso;
	double neutralHadronIso;
	double photonIso;
	double chargedHadronIso_corr;
	double neutralHadronIso_corr;
	double photonIso_corr;
	double hadTowOverEm;
	double hadronicOverEm;	
	double r9;
	double e5x5;	
	double hcalDepth1;
	double trackSumHollow;
	
/*	Set variables to check for isolation etc. 
		variables are set in MySelector and chosen
		from NtupleSelector.h */

  void SetPhotonPt(double x) {
    pt = x;
  	}
		
  void SetPhotonEta(double x) {
    photon_eta = x;
  	}		
	
  void SetCaloEta(double x) {
    calo_Eta = x;
  	}	
	
  void SetRho(double x) {
    rho = x;
 	  }
		
  void Setr9(double x) {
    r9 = x;
 	  }	
		
  void SetE5x5(double x) {
    e5x5 = x;
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
		
	void SetChargedHadronIso_corr(double x) {
		chargedHadronIso_corr = x;
		}
		
	void SetNeutralHadronIso_corr(double x) {
		neutralHadronIso_corr = x;
		}
		
		
	void SetPhotonIso_corr(double x) {
		photonIso_corr = x;
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
		
	void SetHadronicOverEm(double x) {
		hadronicOverEm = x;
		}	
		
	void SetHcalDepth1(double x) {
		hcalDepth1 = x;
		}	
		
	void SetTrackSumHollow(double x) {
		trackSumHollow = x;
		}	
			
	/*Calculate corrected Isolation values */	
		
	double ChargedHadronIso_corrected() {
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
        iso = std::max(iso - rho*ea, (double)0.);

        return iso;
				}

	double NeutralHadronIso_corrected() {
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
        iso = std::max(iso - rho*ea, (double)0.);

        return iso;
				}


	double PhotonIso_corrected() {
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
        iso = std::max(iso - rho*ea, (double)0.);

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
             ChargedHadronIso_corrected()    < 2.6   &&
             NeutralHadronIso_corrected() < 3.5 + 0.04*pt  &&
             PhotonIso_corrected()		 < 1.3 + 0.005*pt &&
						 nPixelSeeds				 < 1 );
  	}; 
		
  const bool IsTightIsolated() {
    return ( hadTowOverEm  			 < 0.05  &&
             sigmaIetaIeta			 < 0.011 &&
             ChargedHadronIso_corrected()    < 0.7   &&
             NeutralHadronIso_corrected() < 0.4 + 0.04*pt  &&
             PhotonIso_corrected()		 < 0.5 + 0.005*pt &&
						 nPixelSeeds				 < 1 );
  	};
		
		// cuts a bit harder
  const bool PassTriggerIsolation() {
    return ( r9  			 > 0.91  &&
						 fabs(photon_eta) < 1.444 &&
             hadronicOverEm    < 0.1   &&
             hcalDepth1 < 3.9  &&
             trackSumHollow		 < 3.9 );
  	};				

private:

  double isolation;
	double pt;
	double photon_eta;
	double calo_Eta;
	double rho;
/*	double chargedHadronIso;
	double neutralHadronIso;
	double photonIso;
	double chargedHadronIso_corr;
	double neutralHadronIso_corr;
	double photonIso_corr;	 */
	double sigmaIetaIeta;
	double sigmaIphiIphi;
	
};

#endif
