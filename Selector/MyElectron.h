#ifndef MYELECTRON_H
#define MYELECTRON_H

#include <TLorentzVector.h>
#include <iostream>
#include "TMath.h"

class MyElectron: public TLorentzVector {

public:

  MyElectron();
  MyElectron(Double_t P_x, Double_t P_y, Double_t P_z, Double_t E) {
    SetPxPyPzE(P_x, P_y, P_z, E);
  };

  virtual ~MyElectron();
	
	
	double electron_vertex_x;
	double electron_vertex_y;
	double electron_vertex_z;
	double electron_track_px;
	double electron_track_py;
	double electron_track_pz;
	TVector3 electron_vertex;
	int electron_n_missing_hits;
	Bool_t electron_pass_conversion_veto; 
	
/*	Set variables to check for isolation etc. 
		variables are set in MySelector and chosen
		from NtupleSelector.h */

  void SetElectronPt(double x) {
    electron_pt = x;
  	}
		
  void SetElectronEta(double x) {
    electron_eta = x;
  	}		
	

	void SetSigmaIetaIeta(double x) {
		electron_sigmaIetaIeta = x;
		}

		
	void SetDeltaEtaSuperCluster(double x) {
		electron_deltaEta = x;
		}

		
	void SetDeltaPhiSuperCluster(double x) {
		electron_deltaPhi = x;
		}		
			
	void SetHoverE(double x) {
		electron_HoverE = x;
		}	
			
	void SetEoverP(double x) {
		electron_EoverP = x;
		}		
			
	void SetEcalEnergy(double x) {
		electron_ecalEnergy = x;
		}		
		
	void SetChargedHadronIso(double x) {
		electron_chargedHadronIso = x;
		}	
			
	void SetNeutralHadronIso(double x) {
		electron_neutralHadronIso = x;
		}		
		
			
	void SetnMissingHits(int x) {
		electron_n_missing_hits = x;
		}	
	void SetPassConversionVeto(Bool_t x) {
		electron_pass_conversion_veto = x;
		}			
			
	void SetPhotonIso(double x) {
		electron_photonIso = x;
		}	
	void SetTrackIndex(Short_t x) {
		electron_track_index = x;
		}			
		
	void SetVertexX(double x) {
		electron_vertex_x = x;
		}	
	void SetVertexY(double x) {
		electron_vertex_y = x;
		}			
	void SetVertexZ(double x) {
		electron_vertex_z = x;
		}
	void SetTrackPX(double x) {
		electron_track_px = x;
		}		
	void SetTrackPY(double x) {
		electron_track_py = x;
		}							
	void SetTrackPZ(double x) {
		electron_track_pz = x;
		}	
		
	void SetVertex(TVector3 x) {
		electron_vertex = x;
		}			
	/*	
	void SetTrackPt(double x) {
		electron_track_pt = x;
		}
	void SetTrackP(double x) {
		electron_track_p = x;
		}			 */			
	/*Calculate corrected Isolation values */	
		
 
   Float_t electron_dz(TVector3 const& _vtx = TVector3(0., 0., 0.)) const {		
		  return
		
((electron_vertex_z-_vtx.Z())-((electron_vertex_x-_vtx.X())*electron_track_px+(electron_vertex_y-_vtx.Y())*electron_track_py)/(TMath::Sqrt((electron_track_px*electron_track_px)+(electron_track_py*electron_track_py))) *electron_track_pz/(TMath::Sqrt((electron_track_px*electron_track_px) + (electron_track_py*electron_track_py))));
		 }
		 
    Float_t electron_dsz(TVector3 const& _vtx = TVector3(0., 0., 0.)) const { 
			return electron_dz(_vtx)*(TMath::Sqrt((electron_track_px*electron_track_px) + (electron_track_py*electron_track_py) ))/(TMath::Sqrt((electron_track_px*electron_track_px) + (electron_track_py*electron_track_py) + (electron_track_pz*electron_track_pz) )); 
			}
			
    Float_t electron_dxy(TVector3 const& _vtx = TVector3(0., 0., 0.)) const { 
			return ((-(electron_vertex_x-_vtx.X())*electron_track_py+(electron_vertex_y-_vtx.Y())*electron_track_px)/(TMath::Sqrt((electron_track_px*electron_track_px) +(electron_track_py*electron_track_py) ))); 
			}
			
    Float_t electron_d0(TVector3 const& _vtx = TVector3(0., 0., 0.)) const { 
			return -electron_dxy(electron_vertex); 
			} 
 
		
	double electron_iso() {
        /** Correct isolation for charged hadrons,
         * see https://twiki.cern.ch/twiki/bin/view/CMS/CutBasedPhotonID2012
         */
        double eta = fabs(electron_eta);
        double ea;

				/* see https://twiki.cern.ch/twiki/bin/viewauth/CMS/SusyPhotonID */

        if(eta < 1.0)				 ea = 0.208;
        else if(eta < 1.479) ea = 0.209;
        else if(eta < 2.0)	 ea = 0.115;
        else if(eta < 2.2)	 ea = 0.143;
        else if(eta < 2.3)	 ea = 0.183;
        else if(eta < 2.4)	 ea = 0.194;
        else 								 ea = 0.261;

        double iso = electron_neutralHadronIso + electron_photonIso - electron_rho*ea;
        iso =electron_chargedHadronIso + std::max(iso, (double)0.);

        return iso;
				}
					
//Barrel electrons only
		
 const bool IsMediumIsolated() {
 
    return ( electron_pt						> 20				&&
					 ((fabs(electron_eta) 			 < 1.479  &&
             electron_sigmaIetaIeta		 < 0.01   &&
             electron_deltaEta    < 0.004  			&&
             electron_deltaPhi    < 0.06  			&&
             electron_HoverE			< 0.12				&&
						 fabs(electron_d0(electron_vertex))	<0.02					&&
						 fabs(electron_dz(electron_vertex))	<0.2					&&
						 electron_pass_conversion_veto			&&
						 electron_n_missing_hits < 2				&&
						 fabs((1./electron_ecalEnergy)-(electron_EoverP/electron_ecalEnergy)) < 0.05 &&
						 electron_iso()/electron_pt < 0.15) || 
						 (fabs(electron_eta) 			 > 1.479  &&
						 fabs(electron_eta) 			 < 2.5    &&
             electron_sigmaIetaIeta		 < 0.03   &&
             electron_deltaEta    < 0.007  			&&
             electron_deltaPhi    < 0.03  			&&
             electron_HoverE			< 0.10				&&
						 fabs(electron_d0(electron_vertex))	<0.02					&&
						 fabs(electron_dz(electron_vertex))	<0.2					&&	
						 electron_pass_conversion_veto			&&
						 electron_n_missing_hits < 2				&&						 					 
						 fabs((1./electron_ecalEnergy)-(electron_EoverP/electron_ecalEnergy)) < 0.05 &&
						 electron_iso()/electron_pt < 0.15))	);
  	};		
		
			

private:
	Short_t electron_track_index;
	double electron_pt;
	double electron_eta;
	double electron_HoverE;
	double electron_sigmaIetaIeta;
	double electron_deltaEta;
	double electron_deltaPhi;
	double electron_EoverP;
	double electron_ecalEnergy;
	double electron_rho;
	double electron_chargedHadronIso;
	double electron_neutralHadronIso;
	double electron_photonIso;
	
};

#endif
