#ifndef MYGENPARTICLES_H
#define MYGENPARTICLES_H

#include <TLorentzVector.h>
#include <iostream>


class MyGenParticles: public TLorentzVector {

public:

  MyGenParticles();
  MyGenParticles(Double_t P_x, Double_t P_y, Double_t P_z, Double_t E) {
    SetPxPyPzE(P_x, P_y, P_z, E);
  };

  virtual ~MyGenParticles();
	


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
