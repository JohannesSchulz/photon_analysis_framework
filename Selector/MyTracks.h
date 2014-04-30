#ifndef MYTRACKS_H
#define MYTRACKS_H

#include <TLorentzVector.h>
#include <iostream>


class MyTracks: public TLorentzVector {

public:

  MyTracks();
  MyTracks(Double_t P_x, Double_t P_y, Double_t P_z, Double_t E) {
    SetPxPyPzE(P_x, P_y, P_z, E);
  };

  virtual ~MyTracks();

	
/*	Set variables to check for isolation etc. 
		variables are set in MySelector and chosen
		from NtupleSelector.h */


};

#endif
