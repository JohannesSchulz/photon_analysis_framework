#ifndef MYMuon_H
#define MYMuon_H

#include <TLorentzVector.h>
#include <iostream>


class MyMuon: public TLorentzVector {

public:

  MyMuon();
  MyMuon(Double_t P_x, Double_t P_y, Double_t P_z, Double_t E) {
    SetPxPyPzE(P_x, P_y, P_z, E);
  };

  virtual ~MyMuon();
	
	double muon_pt;
	double muon_eta;	
	double muon_vertex_x;
	double muon_vertex_y;
	double muon_vertex_z;
	double muon_track_px;
	double muon_track_py;
	double muon_track_pz;
	double muon_chargedHadronPt04;
	double muon_neutralHadronEt04;
	double muon_photonEt04;
	double muon_PUPt04;
	double muon_Chi2;
	double muon_NDF;
	double muon_PixelLayers;
	double muon_StripLayers;		
/*	Set variables to check for isolation etc. 
		variables are set in MySelector and chosen
		from NtupleSelector.h */

  void SetMuonPt(double x) {
    muon_pt = x;
  	}
		
  void SetMuonEta(double x) {
    muon_eta = x;
  	}		
		
  void SetMuonType(UChar_t x) {
    muon_type = x;
  	}
  void SetMuonQualityFlag(UChar_t x) {
    muon_quality_flag = x;
  	}		
		
	void SetVertexX(double x) {
		muon_vertex_x = x;
		}	
	void SetVertexY(double x) {
		muon_vertex_y = x;
		}			
	void SetVertexZ(double x) {
		muon_vertex_z = x;
		}
	void SetTrackPX(double x) {
		muon_track_px = x;
		}		
	void SetTrackPY(double x) {
		muon_track_py = x;
		}							
	void SetTrackPZ(double x) {
		muon_track_pz = x;
		}	
	void SetChargedHadronPt(double x) {
		muon_chargedHadronPt04 = x;
		}			
	void SetNeutralHadronEt(double x) {
		muon_neutralHadronEt04 = x;
		}					
	void SetPhotonEt(double x) {
		muon_photonEt04 = x;
		}			
	void SetPUPt(double x) {
		muon_PUPt04 = x;
		}
	void SetChi2(double x) {
		muon_Chi2 = x;
		}	
	void SetNDF(double x) {
		muon_NDF = x;
		}		
	void SetPixelLayers(double x) {
		muon_PixelLayers = x;
		}			
	void SetStripLayers(double x) {
		muon_StripLayers = x;
		}	
						
		
 const bool IsPfMuon() {
    return ( (muon_type & (0x1 << 5)) );
  	};	
		
 const bool IsGlobalMuon() {
    return ( (muon_type & (0x1 << 1)) );
  	};
		
 const bool IsTrackerMuon() {
    return ( (muon_type & (0x1 << 2)) );
  	};
		
 const bool IsGoodOneStationTightMuon() {
    return ( (muon_quality_flag & (0x1 << 3)) );
  	};		
		
	double muon_deltaB_iso() {

        double iso = muon_chargedHadronPt04 + std::max((double)0., muon_neutralHadronEt04 + muon_photonEt04 - 0.5*muon_PUPt04);
        return iso;
				};
				
	double muon_chi2pNDF() {

        return (muon_Chi2/muon_NDF);
				};						
				
									
   Float_t muon_dz(TVector3 const& _vtx = TVector3(0., 0., 0.)) const {		
		  return
		
((muon_vertex_z-_vtx.Z())-((muon_vertex_x-_vtx.X())*muon_track_px+(muon_vertex_y-_vtx.Y())*muon_track_py)/(TMath::Sqrt((muon_track_px*muon_track_px)+(muon_track_py*muon_track_py))) *muon_track_pz/(TMath::Sqrt((muon_track_px*muon_track_px) + (muon_track_py*muon_track_py))));
		 }
		 
    Float_t muon_dsz(TVector3 const& _vtx = TVector3(0., 0., 0.)) const { 
			return muon_dz(_vtx)*(TMath::Sqrt((muon_track_px*muon_track_px) + (muon_track_py*muon_track_py) ))/(TMath::Sqrt((muon_track_px*muon_track_px) + (muon_track_py*muon_track_py) + (muon_track_pz*muon_track_pz) )); 
			}
			
    Float_t muon_dxy(TVector3 const& _vtx = TVector3(0., 0., 0.)) const { 
			return ((-(muon_vertex_x-_vtx.X())*muon_track_py+(muon_vertex_y-_vtx.Y())*muon_track_px)/(TMath::Sqrt((muon_track_px*muon_track_px) +(muon_track_py*muon_track_py) ))); 
			}
			
    Float_t muon_d0(TVector3 const& _vtx = TVector3(0., 0., 0.)) const { 
			return -muon_dxy(); 
			} 
			
 const bool IsSoftMuon() {
 
    return ( muon_pt					> 20							&&
					 	(fabs(muon_eta) < 1.4442 || (fabs(muon_eta) > 1.556 )) 		&&
					 	 fabs(muon_eta) 	< 2.5							&&
						 IsPfMuon()													&&
						 IsGlobalMuon()											&&
						 fabs(muon_d0())	< 3								&&
						 fabs(muon_dz())	< 30							&&
						 muon_chi2pNDF()		< 1.8						&&
						 muon_PixelLayers > 1								&&
						 (muon_PixelLayers + muon_StripLayers) > 5 &&
						 muon_deltaB_iso()/muon_pt < 0.12		);
  	};
					
private:

	UChar_t muon_type;
	UChar_t muon_quality_flag;
	
	
};

#endif
