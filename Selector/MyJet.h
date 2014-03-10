#ifndef MYJET_H
#define MYJET_H

#include <TLorentzVector.h>
#include <iostream>


class MyJet: public TLorentzVector {

public:

  MyJet();
  MyJet(Double_t P_x, Double_t P_y, Double_t P_z, Double_t E) {
    SetPxPyPzE(P_x, P_y, P_z, E);
  };

  virtual ~MyJet();
	


//	int nPixelSeeds;
	double JetE;
	double JetEta;
	double neutralHadronEnergy;	
	double neutralEmEnergy;
	double chargedHadronEnergy;
	double photonEnergy;	
	double chargedEmEnergy;
	int nConstituents;
	int chargedHadronMultiplicity;
	int neutralHadronMultiplicity;	
	int chargedMultiplicity;
	int neutralMultiplicity;	
	int photonMultiplicity;		
	float bTagDisc;
	
/*	Set variables to check for isolation etc. 
		variables are set in MySelector and chosen
		from NtupleSelector.h */

  void SetJetPt(double x) {
    pt = x;
  	}
		
	void SetJetE(double x) {
    JetE = x;
  	}
	
  void SetJetEta(double x) {
    JetEta = x;
  	}	
	
 /* void SetRho25(double x) {
    rho25 = x;
 	  } */
	
	void SetChargedHadronEnergy(double x) {
		chargedHadronEnergy = x;
		}
		
	void SetNeutralHadronEnergy(double x) {
		neutralHadronEnergy = x;
		}
		
	void SetPhotonEnergy(double x) {
		photonEnergy = x;
		}		
		
	void SetChargedEmEnergy(double x) {
		chargedEmEnergy = x;
		}
		
	void SetNeutralEmEnergy(double x) {
		neutralEmEnergy = x;
		}
		
	void SetChargedHadronMultiplicity(int x) {
		chargedHadronMultiplicity = x;
		}
		
	void SetNeutralHadronMultiplicity(int x) {
		neutralHadronMultiplicity = x;
		}			
		
	void SetChargedMultiplicity(int x) {
		chargedMultiplicity = x;
		}
		
	void SetNeutralMultiplicity(int x) {
		neutralMultiplicity = x;
		}	
			
	void SetPhotonMultiplicity(int x) {
		photonMultiplicity = x;
		}		
		
	void SetNConstituents(int x) {
		nConstituents = x;
		}	
		
	void SetbTagDiscriminator(int x) {
		bTagDisc = x;
		}				



/*	Serve bool IsLooseIsolated to save vectors 
		in analysis code vector<int> loose_photons 
		for further analysis !!loose jets are
		official loose jets (loose ID)!! */
		
  const bool IsLooseIsolated() {
    return ( 															pt		 > 30 	&&
																			fabs(JetEta) < 2.4 &&
						 (neutralHadronEnergy / JetE)  			 < 0.99  &&
             (neutralEmEnergy / JetE)			 < 0.99 &&
						  nConstituents						> 1 &&

						 ( (fabs(JetEta)>= 2.4 ) ||
					     ( (chargedHadronEnergy / JetE) > 0   &&
               	 (chargedEmEnergy / JetE)   	 < 0.99   &&
		  				 	  chargedMultiplicity			 > 0 ) ) ); 
  	} 

private:

	double pt;


};


#endif
