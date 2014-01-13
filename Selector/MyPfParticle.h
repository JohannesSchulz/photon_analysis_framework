#ifndef MYPFPARTICLE_H
#define MYPFPARTICLE_H

#include <TLorentzVector.h>
#include <iostream>


class MyPfParticle: public TLorentzVector {

public:

  MyPfParticle();
  MyPfParticle(Double_t P_x, Double_t P_y, Double_t P_z, Double_t E) {
    SetPxPyPzE(P_x, P_y, P_z, E);
  };

  virtual ~MyPfParticle();
	


//	int nPixelSeeds;
	
	
/*	Set variables to check for isolation etc. 
		variables are set in MySelector and chosen
		from NtupleSelector.h */

  void SetPfPt(double x) {
    pt = x;
  	}
	


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
