#ifndef MYVERTICES_H
#define MYVERTICES_H

#include <TLorentzVector.h>
#include <iostream>


class MyVertices: public TLorentzVector {

public:

  MyVertices();
  MyVertices(Double_t P_x, Double_t P_y, Double_t P_z, Double_t E) {
    SetPxPyPzE(P_x, P_y, P_z, E);
  };

  virtual ~MyVertices();


	
};

#endif
