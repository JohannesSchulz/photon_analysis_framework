//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Oct 30 15:34:35 2013 by ROOT version 5.32/00
// from TChain susyTree/
//////////////////////////////////////////////////////////

#ifndef DataSelector_h
#define DataSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include <TVector3.h>
#include <TObject.h>
#include <TLorentzVector.h>
#include <TVector2.h>
#include <TString.h>
#include <vector>

#include "TriggerMap.h"

using namespace std;

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxbeamSpot = 1*10;
const Int_t kMaxvertices = 35*10;
const Int_t kMaxtracks = 369*10;
const Int_t kMaxsuperClusters = 12*10;
const Int_t kMaxclusters = 44*10;
const Int_t kMaxpfParticles = 1180*10;
const Int_t kMaxpu = 1*10;
const Int_t kMaxgenParticles = 1*10;
const Int_t kMaxmet_caloType1CorrectedMet = 1*10;
const Int_t kMaxmet_caloType1p2CorrectedMet = 1*10;
const Int_t kMaxmet_corMetGlobalMuons = 1*10;
const Int_t kMaxmet_met = 1*10;
const Int_t kMaxmet_pfMet = 1*10;
const Int_t kMaxmet_pfType01CorrectedMet = 1*10;
const Int_t kMaxmet_pfType01p2CorrectedMet = 1*10;
const Int_t kMaxmet_pfType1CorrectedMet = 1*10;
const Int_t kMaxmet_pfType1p2CorrectedMet = 1*10;
const Int_t kMaxmet_tcMet = 1*10;
const Int_t kMaxmuons_muons = 22*10;
const Int_t kMaxmuons_muonsFromCosmics = 23*10;
const Int_t kMaxelectrons_gsfElectrons = 8*10;
const Int_t kMaxphotons_pfPhotonTranslator_pfphot = 3*10;
const Int_t kMaxphotons_photons = 8*10;
const Int_t kMaxpfJets_ak5 = 13*10;
const Int_t kMaxpfJets_ak5chs = 34*10;

class DataSelector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
	 
   TriggerMap l1Map;
   TriggerMap hltMap;
	
   // Declaration of leaf types
   UChar_t         isRealData;
   UInt_t          runNumber;
   UInt_t          eventNumber;
   UInt_t          luminosityBlockNumber;
   UShort_t        bunchCrossing;
   UChar_t         cosmicFlag;
   Float_t         avgInsRecLumi;
   Float_t         intgRecLumi;
   Float_t         rho;
   Float_t         rhoBarrel;
   Float_t         rho25;
   Int_t           metFilterBit;
   Int_t           metFilterMask;
 //TVector3        *beamSpot_;
   UInt_t          beamSpot_TObject_fUniqueID;
   UInt_t          beamSpot_TObject_fBits;
   Double_t        beamSpot_fX;
   Double_t        beamSpot_fY;
   Double_t        beamSpot_fZ;
   Int_t           vertices_;
   UShort_t        vertices_tracksSize[kMaxvertices];   //[vertices_]
   Float_t         vertices_sumPt2[kMaxvertices];   //[vertices_]
   Float_t         vertices_chi2[kMaxvertices];   //[vertices_]
   Float_t         vertices_ndof[kMaxvertices];   //[vertices_]
   UInt_t          vertices_position_fUniqueID[kMaxvertices];   //[vertices_]
   UInt_t          vertices_position_fBits[kMaxvertices];   //[vertices_]
   Double_t        vertices_position_fX[kMaxvertices];   //[vertices_]
   Double_t        vertices_position_fY[kMaxvertices];   //[vertices_]
   Double_t        vertices_position_fZ[kMaxvertices];   //[vertices_]
   Int_t           tracks_;
   UChar_t         tracks_algorithm[kMaxtracks];   //[tracks_]
   UChar_t         tracks_quality[kMaxtracks];   //[tracks_]
   UChar_t         tracks_numberOfValidHits[kMaxtracks];   //[tracks_]
   UChar_t         tracks_numberOfValidTrackerHits[kMaxtracks];   //[tracks_]
   UChar_t         tracks_numberOfValidMuonHits[kMaxtracks];   //[tracks_]
   UChar_t         tracks_numberOfValidPixelHits[kMaxtracks];   //[tracks_]
   UChar_t         tracks_numberOfValidStripHits[kMaxtracks];   //[tracks_]
   Short_t         tracks_vertexIndex[kMaxtracks];   //[tracks_]
   Float_t         tracks_chi2[kMaxtracks];   //[tracks_]
   Float_t         tracks_ndof[kMaxtracks];   //[tracks_]
   Float_t         tracks_charge[kMaxtracks];   //[tracks_]
   Float_t         tracks_error[kMaxtracks][5];   //[tracks_]
   Float_t         tracks_ptError[kMaxtracks];   //[tracks_]
   UInt_t          tracks_vertex_fUniqueID[kMaxtracks];   //[tracks_]
   UInt_t          tracks_vertex_fBits[kMaxtracks];   //[tracks_]
   Double_t        tracks_vertex_fX[kMaxtracks];   //[tracks_]
   Double_t        tracks_vertex_fY[kMaxtracks];   //[tracks_]
   Double_t        tracks_vertex_fZ[kMaxtracks];   //[tracks_]
   UInt_t          tracks_momentum_fUniqueID[kMaxtracks];   //[tracks_]
   UInt_t          tracks_momentum_fBits[kMaxtracks];   //[tracks_]
   UInt_t          tracks_momentum_fP_fUniqueID[kMaxtracks];   //[tracks_]
   UInt_t          tracks_momentum_fP_fBits[kMaxtracks];   //[tracks_]
   Double_t        tracks_momentum_fP_fX[kMaxtracks];   //[tracks_]
   Double_t        tracks_momentum_fP_fY[kMaxtracks];   //[tracks_]
   Double_t        tracks_momentum_fP_fZ[kMaxtracks];   //[tracks_]
   Double_t        tracks_momentum_fE[kMaxtracks];   //[tracks_]
   Int_t           superClusters_;
   Short_t         superClusters_seedClusterIndex[kMaxsuperClusters];   //[superClusters_]
   Float_t         superClusters_energy[kMaxsuperClusters];   //[superClusters_]
   Float_t         superClusters_preshowerEnergy[kMaxsuperClusters];   //[superClusters_]
   Float_t         superClusters_phiWidth[kMaxsuperClusters];   //[superClusters_]
   Float_t         superClusters_etaWidth[kMaxsuperClusters];   //[superClusters_]
   UInt_t          superClusters_position_fUniqueID[kMaxsuperClusters];   //[superClusters_]
   UInt_t          superClusters_position_fBits[kMaxsuperClusters];   //[superClusters_]
   Double_t        superClusters_position_fX[kMaxsuperClusters];   //[superClusters_]
   Double_t        superClusters_position_fY[kMaxsuperClusters];   //[superClusters_]
   Double_t        superClusters_position_fZ[kMaxsuperClusters];   //[superClusters_]
   vector<unsigned short> superClusters_basicClusterIndices[kMaxsuperClusters];
   Int_t           clusters_;
   UChar_t         clusters_nCrystals[kMaxclusters];   //[clusters_]
   Float_t         clusters_energy[kMaxclusters];   //[clusters_]
   UInt_t          clusters_position_fUniqueID[kMaxclusters];   //[clusters_]
   UInt_t          clusters_position_fBits[kMaxclusters];   //[clusters_]
   Double_t        clusters_position_fX[kMaxclusters];   //[clusters_]
   Double_t        clusters_position_fY[kMaxclusters];   //[clusters_]
   Double_t        clusters_position_fZ[kMaxclusters];   //[clusters_]
   Int_t           pfParticles_;
   Char_t          pfParticles_charge[kMaxpfParticles];   //[pfParticles_]
   Bool_t          pfParticles_isPU[kMaxpfParticles];   //[pfParticles_]
   Short_t         pfParticles_pdgId[kMaxpfParticles];   //[pfParticles_]
   Float_t         pfParticles_ecalEnergy[kMaxpfParticles];   //[pfParticles_]
   Float_t         pfParticles_hcalEnergy[kMaxpfParticles];   //[pfParticles_]
   UInt_t          pfParticles_vertex_fUniqueID[kMaxpfParticles];   //[pfParticles_]
   UInt_t          pfParticles_vertex_fBits[kMaxpfParticles];   //[pfParticles_]
   Double_t        pfParticles_vertex_fX[kMaxpfParticles];   //[pfParticles_]
   Double_t        pfParticles_vertex_fY[kMaxpfParticles];   //[pfParticles_]
   Double_t        pfParticles_vertex_fZ[kMaxpfParticles];   //[pfParticles_]
   UInt_t          pfParticles_momentum_fUniqueID[kMaxpfParticles];   //[pfParticles_]
   UInt_t          pfParticles_momentum_fBits[kMaxpfParticles];   //[pfParticles_]
   UInt_t          pfParticles_momentum_fP_fUniqueID[kMaxpfParticles];   //[pfParticles_]
   UInt_t          pfParticles_momentum_fP_fBits[kMaxpfParticles];   //[pfParticles_]
   Double_t        pfParticles_momentum_fP_fX[kMaxpfParticles];   //[pfParticles_]
   Double_t        pfParticles_momentum_fP_fY[kMaxpfParticles];   //[pfParticles_]
   Double_t        pfParticles_momentum_fP_fZ[kMaxpfParticles];   //[pfParticles_]
   Double_t        pfParticles_momentum_fE[kMaxpfParticles];   //[pfParticles_]
   Int_t           pu_;
   Char_t          pu_BX[kMaxpu];   //[pu_]
   UChar_t         pu_numInteractions[kMaxpu];   //[pu_]
   Float_t         pu_trueNumInteractions[kMaxpu];   //[pu_]
   vector<Float_t> pu_zPositions[kMaxpu];
   vector<Float_t> pu_sumPTLowPT[kMaxpu];
   vector<Float_t> pu_sumPTHighPT[kMaxpu];
   vector<unsigned short> pu_numTracksLowPT[kMaxpu];
   vector<unsigned short> pu_numTracksHighPT[kMaxpu];
   vector<Float_t> pu_instLumi[kMaxpu];
   vector<UInt_t>  pu_dataMixerRun[kMaxpu];
   vector<UInt_t>  pu_dataMixerEvt[kMaxpu];
   vector<UInt_t>  pu_dataMixerLumiSection[kMaxpu];
   Int_t           genParticles_;
   UChar_t         genParticles_status[kMaxgenParticles];   //[genParticles_]
   Char_t          genParticles_charge[kMaxgenParticles];   //[genParticles_]
   Short_t         genParticles_motherIndex[kMaxgenParticles];   //[genParticles_]
   Int_t           genParticles_pdgId[kMaxgenParticles];   //[genParticles_]
   UInt_t          genParticles_vertex_fUniqueID[kMaxgenParticles];   //[genParticles_]
   UInt_t          genParticles_vertex_fBits[kMaxgenParticles];   //[genParticles_]
   Double_t        genParticles_vertex_fX[kMaxgenParticles];   //[genParticles_]
   Double_t        genParticles_vertex_fY[kMaxgenParticles];   //[genParticles_]
   Double_t        genParticles_vertex_fZ[kMaxgenParticles];   //[genParticles_]
   UInt_t          genParticles_momentum_fUniqueID[kMaxgenParticles];   //[genParticles_]
   UInt_t          genParticles_momentum_fBits[kMaxgenParticles];   //[genParticles_]
   UInt_t          genParticles_momentum_fP_fUniqueID[kMaxgenParticles];   //[genParticles_]
   UInt_t          genParticles_momentum_fP_fBits[kMaxgenParticles];   //[genParticles_]
   Double_t        genParticles_momentum_fP_fX[kMaxgenParticles];   //[genParticles_]
   Double_t        genParticles_momentum_fP_fY[kMaxgenParticles];   //[genParticles_]
   Double_t        genParticles_momentum_fP_fZ[kMaxgenParticles];   //[genParticles_]
   Double_t        genParticles_momentum_fE[kMaxgenParticles];   //[genParticles_]
 //susy::MET       *met_caloType1CorrectedMet_;
   Float_t         met_caloType1CorrectedMet_sumEt;
   Float_t         met_caloType1CorrectedMet_significance;
   UInt_t          met_caloType1CorrectedMet_mEt_fUniqueID;
   UInt_t          met_caloType1CorrectedMet_mEt_fBits;
   Double_t        met_caloType1CorrectedMet_mEt_fX;
   Double_t        met_caloType1CorrectedMet_mEt_fY;
 //susy::MET       *met_caloType1p2CorrectedMet_;
   Float_t         met_caloType1p2CorrectedMet_sumEt;
   Float_t         met_caloType1p2CorrectedMet_significance;
   UInt_t          met_caloType1p2CorrectedMet_mEt_fUniqueID;
   UInt_t          met_caloType1p2CorrectedMet_mEt_fBits;
   Double_t        met_caloType1p2CorrectedMet_mEt_fX;
   Double_t        met_caloType1p2CorrectedMet_mEt_fY;
 //susy::MET       *met_corMetGlobalMuons_;
   Float_t         met_corMetGlobalMuons_sumEt;
   Float_t         met_corMetGlobalMuons_significance;
   UInt_t          met_corMetGlobalMuons_mEt_fUniqueID;
   UInt_t          met_corMetGlobalMuons_mEt_fBits;
   Double_t        met_corMetGlobalMuons_mEt_fX;
   Double_t        met_corMetGlobalMuons_mEt_fY;
 //susy::MET       *met_met_;
   Float_t         met_met_sumEt;
   Float_t         met_met_significance;
   UInt_t          met_met_mEt_fUniqueID;
   UInt_t          met_met_mEt_fBits;
   Double_t        met_met_mEt_fX;
   Double_t        met_met_mEt_fY;
 //susy::MET       *met_pfMet_;
   Float_t         met_pfMet_sumEt;
   Float_t         met_pfMet_significance;
   UInt_t          met_pfMet_mEt_fUniqueID;
   UInt_t          met_pfMet_mEt_fBits;
   Double_t        met_pfMet_mEt_fX;
   Double_t        met_pfMet_mEt_fY;
 //susy::MET       *met_pfType01CorrectedMet_;
   Float_t         met_pfType01CorrectedMet_sumEt;
   Float_t         met_pfType01CorrectedMet_significance;
   UInt_t          met_pfType01CorrectedMet_mEt_fUniqueID;
   UInt_t          met_pfType01CorrectedMet_mEt_fBits;
   Double_t        met_pfType01CorrectedMet_mEt_fX;
   Double_t        met_pfType01CorrectedMet_mEt_fY;
 //susy::MET       *met_pfType01p2CorrectedMet_;
   Float_t         met_pfType01p2CorrectedMet_sumEt;
   Float_t         met_pfType01p2CorrectedMet_significance;
   UInt_t          met_pfType01p2CorrectedMet_mEt_fUniqueID;
   UInt_t          met_pfType01p2CorrectedMet_mEt_fBits;
   Double_t        met_pfType01p2CorrectedMet_mEt_fX;
   Double_t        met_pfType01p2CorrectedMet_mEt_fY;
 //susy::MET       *met_pfType1CorrectedMet_;
   Float_t         met_pfType1CorrectedMet_sumEt;
   Float_t         met_pfType1CorrectedMet_significance;
   UInt_t          met_pfType1CorrectedMet_mEt_fUniqueID;
   UInt_t          met_pfType1CorrectedMet_mEt_fBits;
   Double_t        met_pfType1CorrectedMet_mEt_fX;
   Double_t        met_pfType1CorrectedMet_mEt_fY;
 //susy::MET       *met_pfType1p2CorrectedMet_;
   Float_t         met_pfType1p2CorrectedMet_sumEt;
   Float_t         met_pfType1p2CorrectedMet_significance;
   UInt_t          met_pfType1p2CorrectedMet_mEt_fUniqueID;
   UInt_t          met_pfType1p2CorrectedMet_mEt_fBits;
   Double_t        met_pfType1p2CorrectedMet_mEt_fX;
   Double_t        met_pfType1p2CorrectedMet_mEt_fY;
 //susy::MET       *met_tcMet_;
   Float_t         met_tcMet_sumEt;
   Float_t         met_tcMet_significance;
   UInt_t          met_tcMet_mEt_fUniqueID;
   UInt_t          met_tcMet_mEt_fBits;
   Double_t        met_tcMet_mEt_fX;
   Double_t        met_tcMet_mEt_fY;
   Int_t           muons_muons_;
   UChar_t         muons_muons_type[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_bestTrackType[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_highPtBestTrackType[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_qualityFlags[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_nChambers[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_nMatches[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_stationMask[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_nMatchedStations[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_nValidHits[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_nValidTrackerHits[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_nValidMuonHits[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_nPixelLayersWithMeasurement[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_nStripLayersWithMeasurement[kMaxmuons_muons];   //[muons_muons_]
   UChar_t         muons_muons_timeNDof[kMaxmuons_muons];   //[muons_muons_]
   Char_t          muons_muons_timeDirection[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_timeAtIp[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_timeAtIpError[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_caloCompatibility[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_segmentCompatibility[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_emEnergy[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_hadEnergy[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_trackIsoR03[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_ecalIsoR03[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_hcalIsoR03[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_trackIsoR05[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_ecalIsoR05[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_hcalIsoR05[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumChargedHadronPt03[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumChargedParticlePt03[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumNeutralHadronEt03[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumPhotonEt03[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumNeutralHadronEtHighThreshold03[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumPhotonEtHighThreshold03[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumPUPt03[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumChargedHadronPt04[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumChargedParticlePt04[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumNeutralHadronEt04[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumPhotonEt04[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumNeutralHadronEtHighThreshold04[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumPhotonEtHighThreshold04[kMaxmuons_muons];   //[muons_muons_]
   Float_t         muons_muons_sumPUPt04[kMaxmuons_muons];   //[muons_muons_]
   Short_t         muons_muons_trackIndex[kMaxmuons_muons];   //[muons_muons_]
   Short_t         muons_muons_standAloneTrackIndex[kMaxmuons_muons];   //[muons_muons_]
   Short_t         muons_muons_combinedTrackIndex[kMaxmuons_muons];   //[muons_muons_]
   Short_t         muons_muons_tpfmsTrackIndex[kMaxmuons_muons];   //[muons_muons_]
   Short_t         muons_muons_pickyTrackIndex[kMaxmuons_muons];   //[muons_muons_]
   Short_t         muons_muons_dytTrackIndex[kMaxmuons_muons];   //[muons_muons_]
   UInt_t          muons_muons_momentum_fUniqueID[kMaxmuons_muons];   //[muons_muons_]
   UInt_t          muons_muons_momentum_fBits[kMaxmuons_muons];   //[muons_muons_]
   UInt_t          muons_muons_momentum_fP_fUniqueID[kMaxmuons_muons];   //[muons_muons_]
   UInt_t          muons_muons_momentum_fP_fBits[kMaxmuons_muons];   //[muons_muons_]
   Double_t        muons_muons_momentum_fP_fX[kMaxmuons_muons];   //[muons_muons_]
   Double_t        muons_muons_momentum_fP_fY[kMaxmuons_muons];   //[muons_muons_]
   Double_t        muons_muons_momentum_fP_fZ[kMaxmuons_muons];   //[muons_muons_]
   Double_t        muons_muons_momentum_fE[kMaxmuons_muons];   //[muons_muons_]
   Int_t           muons_muonsFromCosmics_;
   UChar_t         muons_muonsFromCosmics_type[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_bestTrackType[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_highPtBestTrackType[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_qualityFlags[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_nChambers[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_nMatches[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_stationMask[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_nMatchedStations[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_nValidHits[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_nValidTrackerHits[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_nValidMuonHits[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_nPixelLayersWithMeasurement[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_nStripLayersWithMeasurement[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UChar_t         muons_muonsFromCosmics_timeNDof[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Char_t          muons_muonsFromCosmics_timeDirection[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_timeAtIp[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_timeAtIpError[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_caloCompatibility[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_segmentCompatibility[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_emEnergy[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_hadEnergy[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_trackIsoR03[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_ecalIsoR03[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_hcalIsoR03[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_trackIsoR05[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_ecalIsoR05[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_hcalIsoR05[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumChargedHadronPt03[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumChargedParticlePt03[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumNeutralHadronEt03[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumPhotonEt03[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumNeutralHadronEtHighThreshold03[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumPhotonEtHighThreshold03[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumPUPt03[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumChargedHadronPt04[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumChargedParticlePt04[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumNeutralHadronEt04[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumPhotonEt04[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumNeutralHadronEtHighThreshold04[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumPhotonEtHighThreshold04[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Float_t         muons_muonsFromCosmics_sumPUPt04[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Short_t         muons_muonsFromCosmics_trackIndex[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Short_t         muons_muonsFromCosmics_standAloneTrackIndex[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Short_t         muons_muonsFromCosmics_combinedTrackIndex[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Short_t         muons_muonsFromCosmics_tpfmsTrackIndex[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Short_t         muons_muonsFromCosmics_pickyTrackIndex[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Short_t         muons_muonsFromCosmics_dytTrackIndex[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UInt_t          muons_muonsFromCosmics_momentum_fUniqueID[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UInt_t          muons_muonsFromCosmics_momentum_fBits[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UInt_t          muons_muonsFromCosmics_momentum_fP_fUniqueID[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   UInt_t          muons_muonsFromCosmics_momentum_fP_fBits[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Double_t        muons_muonsFromCosmics_momentum_fP_fX[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Double_t        muons_muonsFromCosmics_momentum_fP_fY[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Double_t        muons_muonsFromCosmics_momentum_fP_fZ[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Double_t        muons_muonsFromCosmics_momentum_fE[kMaxmuons_muonsFromCosmics];   //[muons_muonsFromCosmics_]
   Int_t           electrons_gsfElectrons_;
   UChar_t         electrons_gsfElectrons_fidBit[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Char_t          electrons_gsfElectrons_scPixCharge[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UShort_t        electrons_gsfElectrons_boolPack[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Short_t         electrons_gsfElectrons_convFlag[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_eSuperClusterOverP[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_eSeedClusterOverP[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_eSeedClusterOverPout[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_eEleClusterOverPout[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_deltaEtaSuperClusterTrackAtVtx[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_deltaEtaSeedClusterTrackAtCalo[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_deltaEtaEleClusterTrackAtCalo[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_deltaPhiSuperClusterTrackAtVtx[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_deltaPhiSeedClusterTrackAtCalo[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_deltaPhiEleClusterTrackAtCalo[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_shFracInnerHits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_sigmaEtaEta[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_sigmaIetaIeta[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_sigmaIphiIphi[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_e1x5[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_e2x5Max[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_e5x5[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_r9[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_hcalDepth1OverEcal[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_hcalDepth2OverEcal[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_hcalOverEcalBc[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr03TkSumPt[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr03EcalRecHitSumEt[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr03HcalDepth1TowerSumEt[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr03HcalDepth2TowerSumEt[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr03HcalDepth1TowerSumEtBc[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr03HcalDepth2TowerSumEtBc[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr04TkSumPt[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr04EcalRecHitSumEt[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr04HcalDepth1TowerSumEt[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr04HcalDepth2TowerSumEt[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr04HcalDepth1TowerSumEtBc[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_dr04HcalDepth2TowerSumEtBc[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_convDist[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_convDcot[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_convRadius[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_chargedHadronIso[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_neutralHadronIso[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_photonIso[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Int_t           electrons_gsfElectrons_mvaStatus[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_mva[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_mvaTrig[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_mvaNonTrig[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Char_t          electrons_gsfElectrons_bremClass[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_fbrem[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_ecalEnergy[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_ecalEnergyError[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Float_t         electrons_gsfElectrons_trackMomentumError[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Short_t         electrons_gsfElectrons_gsfTrackIndex[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Short_t         electrons_gsfElectrons_closestCtfTrackIndex[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Short_t         electrons_gsfElectrons_electronClusterIndex[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Short_t         electrons_gsfElectrons_superClusterIndex[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Int_t           electrons_gsfElectrons_nMissingHits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Bool_t          electrons_gsfElectrons_passConversionVeto[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackPositionAtVtx_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackPositionAtVtx_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackPositionAtVtx_fX[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackPositionAtVtx_fY[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackPositionAtVtx_fZ[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackPositionAtCalo_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackPositionAtCalo_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackPositionAtCalo_fX[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackPositionAtCalo_fY[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackPositionAtCalo_fZ[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtVtx_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtVtx_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtVtx_fP_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtVtx_fP_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtVtx_fP_fX[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtVtx_fP_fY[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtVtx_fP_fZ[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtVtx_fE[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtCalo_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtCalo_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtCalo_fP_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtCalo_fP_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtCalo_fP_fX[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtCalo_fP_fY[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtCalo_fP_fZ[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtCalo_fE[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumOut_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumOut_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumOut_fP_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumOut_fP_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumOut_fP_fX[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumOut_fP_fY[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumOut_fP_fZ[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumOut_fE[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtEleClus_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtEleClus_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtEleClus_fP_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtEleClus_fP_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtEleClus_fP_fX[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtEleClus_fP_fY[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtEleClus_fP_fZ[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtEleClus_fE[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fX[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fY[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fZ[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fE[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_vertex_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_vertex_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_vertex_fX[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_vertex_fY[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_vertex_fZ[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_momentum_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_momentum_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_momentum_fP_fUniqueID[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   UInt_t          electrons_gsfElectrons_momentum_fP_fBits[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_momentum_fP_fX[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_momentum_fP_fY[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_momentum_fP_fZ[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Double_t        electrons_gsfElectrons_momentum_fE[kMaxelectrons_gsfElectrons];   //[electrons_gsfElectrons_]
   Int_t           photons_pfPhotonTranslator_pfphot_;
   Int_t           photons_pfPhotonTranslator_pfphot_fidBit[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Int_t           photons_pfPhotonTranslator_pfphot_nPixelSeeds[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Bool_t          photons_pfPhotonTranslator_pfphot_passelectronveto[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_hadronicOverEm[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_hadTowOverEm[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_hadronicDepth1OverEm[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_hadronicDepth2OverEm[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_e1x2[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_e1x5[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_e2x5[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_e3x3[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_e5x5[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_maxEnergyXtal[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_sigmaEtaEta[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_sigmaIetaIeta[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_sigmaIphiIphi[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_r9[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_ecalRecHitSumEtConeDR04[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_hcalDepth1TowerSumEtConeDR04[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_hcalDepth2TowerSumEtConeDR04[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_hcalIsoConeDR04_2012[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_trkSumPtSolidConeDR04[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_trkSumPtHollowConeDR04[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UChar_t         photons_pfPhotonTranslator_pfphot_nTrkSolidConeDR04[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UChar_t         photons_pfPhotonTranslator_pfphot_nTrkHollowConeDR04[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_ecalRecHitSumEtConeDR03[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_hcalDepth1TowerSumEtConeDR03[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_hcalDepth2TowerSumEtConeDR03[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_hcalIsoConeDR03_2012[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_trkSumPtSolidConeDR03[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_trkSumPtHollowConeDR03[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UChar_t         photons_pfPhotonTranslator_pfphot_nTrkSolidConeDR03[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UChar_t         photons_pfPhotonTranslator_pfphot_nTrkHollowConeDR03[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_chargedHadronIso[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_neutralHadronIso[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_photonIso[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_worstOtherVtxChargedHadronIso[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Short_t         photons_pfPhotonTranslator_pfphot_worstOtherVtxChargedHadronIsoVtxIdx[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_chargedHadronIsoDeposit[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_neutralHadronIsoDeposit[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_photonIsoDeposit[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_seedTime[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_mipChi2[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_mipTotEnergy[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_mipSlope[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_mipIntercept[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Int_t           photons_pfPhotonTranslator_pfphot_mipNhitCone[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Bool_t          photons_pfPhotonTranslator_pfphot_mipIsHalo[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Bool_t          photons_pfPhotonTranslator_pfphot_convInfo[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convDist[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convDcot[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convVtxChi2[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convVtxNdof[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UInt_t          photons_pfPhotonTranslator_pfphot_convVertex_fUniqueID[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UInt_t          photons_pfPhotonTranslator_pfphot_convVertex_fBits[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_convVertex_fX[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_convVertex_fY[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_convVertex_fZ[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convDxy[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convDz[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convLxy[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convLz[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convZofPVFromTracks[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Int_t           photons_pfPhotonTranslator_pfphot_convTrackChargeProd[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Int_t           photons_pfPhotonTranslator_pfphot_convTrack1nHit[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Int_t           photons_pfPhotonTranslator_pfphot_convTrack2nHit[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack1chi2[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack2chi2[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack1pT[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack2pT[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack1InnerZ[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack2InnerZ[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack1InnerX[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack2InnerX[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack1InnerY[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack2InnerY[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack1Signedd0[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_convTrack2Signedd0[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Short_t         photons_pfPhotonTranslator_pfphot_superClusterIndex[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_superClusterPreshowerEnergy[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_superClusterPhiWidth[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Float_t         photons_pfPhotonTranslator_pfphot_superClusterEtaWidth[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UInt_t          photons_pfPhotonTranslator_pfphot_caloPosition_fUniqueID[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UInt_t          photons_pfPhotonTranslator_pfphot_caloPosition_fBits[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_caloPosition_fX[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_caloPosition_fY[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_caloPosition_fZ[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_MVAregEnergy[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_MVAregErr[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UInt_t          photons_pfPhotonTranslator_pfphot_momentum_fUniqueID[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UInt_t          photons_pfPhotonTranslator_pfphot_momentum_fBits[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UInt_t          photons_pfPhotonTranslator_pfphot_momentum_fP_fUniqueID[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   UInt_t          photons_pfPhotonTranslator_pfphot_momentum_fP_fBits[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_momentum_fP_fX[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_momentum_fP_fY[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_momentum_fP_fZ[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Double_t        photons_pfPhotonTranslator_pfphot_momentum_fE[kMaxphotons_pfPhotonTranslator_pfphot];   //[photons_pfPhotonTranslator_pfphot_]
   Int_t           photons_photons_;
   Int_t           photons_photons_fidBit[kMaxphotons_photons];   //[photons_photons_]
   Int_t           photons_photons_nPixelSeeds[kMaxphotons_photons];   //[photons_photons_]
   Bool_t          photons_photons_passelectronveto[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_hadronicOverEm[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_hadTowOverEm[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_hadronicDepth1OverEm[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_hadronicDepth2OverEm[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_e1x2[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_e1x5[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_e2x5[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_e3x3[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_e5x5[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_maxEnergyXtal[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_sigmaEtaEta[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_sigmaIetaIeta[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_sigmaIphiIphi[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_r9[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_ecalRecHitSumEtConeDR04[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_hcalDepth1TowerSumEtConeDR04[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_hcalDepth2TowerSumEtConeDR04[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_hcalIsoConeDR04_2012[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_trkSumPtSolidConeDR04[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_trkSumPtHollowConeDR04[kMaxphotons_photons];   //[photons_photons_]
   UChar_t         photons_photons_nTrkSolidConeDR04[kMaxphotons_photons];   //[photons_photons_]
   UChar_t         photons_photons_nTrkHollowConeDR04[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_ecalRecHitSumEtConeDR03[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_hcalDepth1TowerSumEtConeDR03[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_hcalDepth2TowerSumEtConeDR03[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_hcalIsoConeDR03_2012[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_trkSumPtSolidConeDR03[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_trkSumPtHollowConeDR03[kMaxphotons_photons];   //[photons_photons_]
   UChar_t         photons_photons_nTrkSolidConeDR03[kMaxphotons_photons];   //[photons_photons_]
   UChar_t         photons_photons_nTrkHollowConeDR03[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_chargedHadronIso[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_neutralHadronIso[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_photonIso[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_worstOtherVtxChargedHadronIso[kMaxphotons_photons];   //[photons_photons_]
   Short_t         photons_photons_worstOtherVtxChargedHadronIsoVtxIdx[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_chargedHadronIsoDeposit[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_neutralHadronIsoDeposit[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_photonIsoDeposit[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_seedTime[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_mipChi2[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_mipTotEnergy[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_mipSlope[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_mipIntercept[kMaxphotons_photons];   //[photons_photons_]
   Int_t           photons_photons_mipNhitCone[kMaxphotons_photons];   //[photons_photons_]
   Bool_t          photons_photons_mipIsHalo[kMaxphotons_photons];   //[photons_photons_]
   Bool_t          photons_photons_convInfo[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convDist[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convDcot[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convVtxChi2[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convVtxNdof[kMaxphotons_photons];   //[photons_photons_]
   UInt_t          photons_photons_convVertex_fUniqueID[kMaxphotons_photons];   //[photons_photons_]
   UInt_t          photons_photons_convVertex_fBits[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_convVertex_fX[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_convVertex_fY[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_convVertex_fZ[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convDxy[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convDz[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convLxy[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convLz[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convZofPVFromTracks[kMaxphotons_photons];   //[photons_photons_]
   Int_t           photons_photons_convTrackChargeProd[kMaxphotons_photons];   //[photons_photons_]
   Int_t           photons_photons_convTrack1nHit[kMaxphotons_photons];   //[photons_photons_]
   Int_t           photons_photons_convTrack2nHit[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack1chi2[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack2chi2[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack1pT[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack2pT[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack1InnerZ[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack2InnerZ[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack1InnerX[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack2InnerX[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack1InnerY[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack2InnerY[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack1Signedd0[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_convTrack2Signedd0[kMaxphotons_photons];   //[photons_photons_]
   Short_t         photons_photons_superClusterIndex[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_superClusterPreshowerEnergy[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_superClusterPhiWidth[kMaxphotons_photons];   //[photons_photons_]
   Float_t         photons_photons_superClusterEtaWidth[kMaxphotons_photons];   //[photons_photons_]
   UInt_t          photons_photons_caloPosition_fUniqueID[kMaxphotons_photons];   //[photons_photons_]
   UInt_t          photons_photons_caloPosition_fBits[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_caloPosition_fX[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_caloPosition_fY[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_caloPosition_fZ[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_MVAregEnergy[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_MVAregErr[kMaxphotons_photons];   //[photons_photons_]
   UInt_t          photons_photons_momentum_fUniqueID[kMaxphotons_photons];   //[photons_photons_]
   UInt_t          photons_photons_momentum_fBits[kMaxphotons_photons];   //[photons_photons_]
   UInt_t          photons_photons_momentum_fP_fUniqueID[kMaxphotons_photons];   //[photons_photons_]
   UInt_t          photons_photons_momentum_fP_fBits[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_momentum_fP_fX[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_momentum_fP_fY[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_momentum_fP_fZ[kMaxphotons_photons];   //[photons_photons_]
   Double_t        photons_photons_momentum_fE[kMaxphotons_photons];   //[photons_photons_]
   Int_t           pfJets_ak5_;
   Int_t           pfJets_ak5_phyDefFlavour[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Int_t           pfJets_ak5_algDefFlavour[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_jetCharge[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_etaMean[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_phiMean[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_etaEtaMoment[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_etaPhiMoment[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_phiPhiMoment[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_maxDistance[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_jetArea[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_pileup[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UChar_t         pfJets_ak5_nPasses[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UChar_t         pfJets_ak5_nConstituents[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_chargedHadronEnergy[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_neutralHadronEnergy[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_photonEnergy[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_electronEnergy[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_muonEnergy[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_HFHadronEnergy[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_HFEMEnergy[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_chargedEmEnergy[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_chargedMuEnergy[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_neutralEmEnergy[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UChar_t         pfJets_ak5_chargedHadronMultiplicity[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UChar_t         pfJets_ak5_neutralHadronMultiplicity[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UChar_t         pfJets_ak5_photonMultiplicity[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UChar_t         pfJets_ak5_electronMultiplicity[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UChar_t         pfJets_ak5_muonMultiplicity[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UChar_t         pfJets_ak5_HFHadronMultiplicity[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UChar_t         pfJets_ak5_HFEMMultiplicity[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UChar_t         pfJets_ak5_chargedMultiplicity[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UChar_t         pfJets_ak5_neutralMultiplicity[kMaxpfJets_ak5];   //[pfJets_ak5_]
   vector<unsigned short> pfJets_ak5_tracklist[kMaxpfJets_ak5];
   vector<unsigned short> pfJets_ak5_pfParticleList[kMaxpfJets_ak5];
   Float_t         pfJets_ak5_puJetIdDiscriminants[kMaxpfJets_ak5][3];   //[pfJets_ak5_]
   Int_t           pfJets_ak5_puJetIdFlags[kMaxpfJets_ak5][3];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_bTagDiscriminators[kMaxpfJets_ak5][9];   //[pfJets_ak5_]
   Float_t         pfJets_ak5_qgDiscriminators[kMaxpfJets_ak5][2];   //[pfJets_ak5_]
   UInt_t          pfJets_ak5_momentum_fUniqueID[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UInt_t          pfJets_ak5_momentum_fBits[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UInt_t          pfJets_ak5_momentum_fP_fUniqueID[kMaxpfJets_ak5];   //[pfJets_ak5_]
   UInt_t          pfJets_ak5_momentum_fP_fBits[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Double_t        pfJets_ak5_momentum_fP_fX[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Double_t        pfJets_ak5_momentum_fP_fY[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Double_t        pfJets_ak5_momentum_fP_fZ[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Double_t        pfJets_ak5_momentum_fE[kMaxpfJets_ak5];   //[pfJets_ak5_]
 //map<TString,float> pfJets_ak5_jecScaleFactors[kMaxpfJets_ak5];
   Float_t         pfJets_ak5_jecUncertainty[kMaxpfJets_ak5];   //[pfJets_ak5_]
   Int_t           pfJets_ak5chs_;
   Int_t           pfJets_ak5chs_phyDefFlavour[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Int_t           pfJets_ak5chs_algDefFlavour[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_jetCharge[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_etaMean[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_phiMean[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_etaEtaMoment[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_etaPhiMoment[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_phiPhiMoment[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_maxDistance[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_jetArea[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_pileup[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UChar_t         pfJets_ak5chs_nPasses[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UChar_t         pfJets_ak5chs_nConstituents[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_chargedHadronEnergy[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_neutralHadronEnergy[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_photonEnergy[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_electronEnergy[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_muonEnergy[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_HFHadronEnergy[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_HFEMEnergy[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_chargedEmEnergy[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_chargedMuEnergy[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_neutralEmEnergy[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UChar_t         pfJets_ak5chs_chargedHadronMultiplicity[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UChar_t         pfJets_ak5chs_neutralHadronMultiplicity[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UChar_t         pfJets_ak5chs_photonMultiplicity[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UChar_t         pfJets_ak5chs_electronMultiplicity[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UChar_t         pfJets_ak5chs_muonMultiplicity[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UChar_t         pfJets_ak5chs_HFHadronMultiplicity[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UChar_t         pfJets_ak5chs_HFEMMultiplicity[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UChar_t         pfJets_ak5chs_chargedMultiplicity[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UChar_t         pfJets_ak5chs_neutralMultiplicity[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   vector<unsigned short> pfJets_ak5chs_tracklist[kMaxpfJets_ak5chs];
   vector<unsigned short> pfJets_ak5chs_pfParticleList[kMaxpfJets_ak5chs];
   Float_t         pfJets_ak5chs_puJetIdDiscriminants[kMaxpfJets_ak5chs][3];   //[pfJets_ak5chs_]
   Int_t           pfJets_ak5chs_puJetIdFlags[kMaxpfJets_ak5chs][3];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_bTagDiscriminators[kMaxpfJets_ak5chs][9];   //[pfJets_ak5chs_]
   Float_t         pfJets_ak5chs_qgDiscriminators[kMaxpfJets_ak5chs][2];   //[pfJets_ak5chs_]
   UInt_t          pfJets_ak5chs_momentum_fUniqueID[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UInt_t          pfJets_ak5chs_momentum_fBits[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UInt_t          pfJets_ak5chs_momentum_fP_fUniqueID[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   UInt_t          pfJets_ak5chs_momentum_fP_fBits[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Double_t        pfJets_ak5chs_momentum_fP_fX[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Double_t        pfJets_ak5chs_momentum_fP_fY[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Double_t        pfJets_ak5chs_momentum_fP_fZ[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
   Double_t        pfJets_ak5chs_momentum_fE[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]
 //map<TString,float> pfJets_ak5chs_jecScaleFactors[kMaxpfJets_ak5chs];
   Float_t         pfJets_ak5chs_jecUncertainty[kMaxpfJets_ak5chs];   //[pfJets_ak5chs_]

   // List of branches
   TBranch        *b_isRealData;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_luminosityBlockNumber;   //!
   TBranch        *b_bunchCrossing;   //!
   TBranch        *b_cosmicFlag;   //!
   TBranch        *b_avgInsRecLumi;   //!
   TBranch        *b_intgRecLumi;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_rhoBarrel;   //!
   TBranch        *b_rho25;   //!
   TBranch        *b_metFilterBit;   //!
   TBranch        *b_metFilterMask;   //!
   TBranch        *b_beamSpot_TObject_fUniqueID;   //!
   TBranch        *b_beamSpot_TObject_fBits;   //!
   TBranch        *b_beamSpot_fX;   //!
   TBranch        *b_beamSpot_fY;   //!
   TBranch        *b_beamSpot_fZ;   //!
   TBranch        *b_vertices_;   //!
   TBranch        *b_vertices_tracksSize;   //!
   TBranch        *b_vertices_sumPt2;   //!
   TBranch        *b_vertices_chi2;   //!
   TBranch        *b_vertices_ndof;   //!
   TBranch        *b_vertices_position_fUniqueID;   //!
   TBranch        *b_vertices_position_fBits;   //!
   TBranch        *b_vertices_position_fX;   //!
   TBranch        *b_vertices_position_fY;   //!
   TBranch        *b_vertices_position_fZ;   //!
   TBranch        *b_tracks_;   //!
   TBranch        *b_tracks_algorithm;   //!
   TBranch        *b_tracks_quality;   //!
   TBranch        *b_tracks_numberOfValidHits;   //!
   TBranch        *b_tracks_numberOfValidTrackerHits;   //!
   TBranch        *b_tracks_numberOfValidMuonHits;   //!
   TBranch        *b_tracks_numberOfValidPixelHits;   //!
   TBranch        *b_tracks_numberOfValidStripHits;   //!
   TBranch        *b_tracks_vertexIndex;   //!
   TBranch        *b_tracks_chi2;   //!
   TBranch        *b_tracks_ndof;   //!
   TBranch        *b_tracks_charge;   //!
   TBranch        *b_tracks_error;   //!
   TBranch        *b_tracks_ptError;   //!
   TBranch        *b_tracks_vertex_fUniqueID;   //!
   TBranch        *b_tracks_vertex_fBits;   //!
   TBranch        *b_tracks_vertex_fX;   //!
   TBranch        *b_tracks_vertex_fY;   //!
   TBranch        *b_tracks_vertex_fZ;   //!
   TBranch        *b_tracks_momentum_fUniqueID;   //!
   TBranch        *b_tracks_momentum_fBits;   //!
   TBranch        *b_tracks_momentum_fP_fUniqueID;   //!
   TBranch        *b_tracks_momentum_fP_fBits;   //!
   TBranch        *b_tracks_momentum_fP_fX;   //!
   TBranch        *b_tracks_momentum_fP_fY;   //!
   TBranch        *b_tracks_momentum_fP_fZ;   //!
   TBranch        *b_tracks_momentum_fE;   //!
   TBranch        *b_superClusters_;   //!
   TBranch        *b_superClusters_seedClusterIndex;   //!
   TBranch        *b_superClusters_energy;   //!
   TBranch        *b_superClusters_preshowerEnergy;   //!
   TBranch        *b_superClusters_phiWidth;   //!
   TBranch        *b_superClusters_etaWidth;   //!
   TBranch        *b_superClusters_position_fUniqueID;   //!
   TBranch        *b_superClusters_position_fBits;   //!
   TBranch        *b_superClusters_position_fX;   //!
   TBranch        *b_superClusters_position_fY;   //!
   TBranch        *b_superClusters_position_fZ;   //!
   TBranch        *b_superClusters_basicClusterIndices;   //!
   TBranch        *b_clusters_;   //!
   TBranch        *b_clusters_nCrystals;   //!
   TBranch        *b_clusters_energy;   //!
   TBranch        *b_clusters_position_fUniqueID;   //!
   TBranch        *b_clusters_position_fBits;   //!
   TBranch        *b_clusters_position_fX;   //!
   TBranch        *b_clusters_position_fY;   //!
   TBranch        *b_clusters_position_fZ;   //!
   TBranch        *b_pfParticles_;   //!
   TBranch        *b_pfParticles_charge;   //!
   TBranch        *b_pfParticles_isPU;   //!
   TBranch        *b_pfParticles_pdgId;   //!
   TBranch        *b_pfParticles_ecalEnergy;   //!
   TBranch        *b_pfParticles_hcalEnergy;   //!
   TBranch        *b_pfParticles_vertex_fUniqueID;   //!
   TBranch        *b_pfParticles_vertex_fBits;   //!
   TBranch        *b_pfParticles_vertex_fX;   //!
   TBranch        *b_pfParticles_vertex_fY;   //!
   TBranch        *b_pfParticles_vertex_fZ;   //!
   TBranch        *b_pfParticles_momentum_fUniqueID;   //!
   TBranch        *b_pfParticles_momentum_fBits;   //!
   TBranch        *b_pfParticles_momentum_fP_fUniqueID;   //!
   TBranch        *b_pfParticles_momentum_fP_fBits;   //!
   TBranch        *b_pfParticles_momentum_fP_fX;   //!
   TBranch        *b_pfParticles_momentum_fP_fY;   //!
   TBranch        *b_pfParticles_momentum_fP_fZ;   //!
   TBranch        *b_pfParticles_momentum_fE;   //!
   TBranch        *b_pu_;   //!
   TBranch        *b_pu_BX;   //!
   TBranch        *b_pu_numInteractions;   //!
   TBranch        *b_pu_trueNumInteractions;   //!
   TBranch        *b_pu_zPositions;   //!
   TBranch        *b_pu_sumPTLowPT;   //!
   TBranch        *b_pu_sumPTHighPT;   //!
   TBranch        *b_pu_numTracksLowPT;   //!
   TBranch        *b_pu_numTracksHighPT;   //!
   TBranch        *b_pu_instLumi;   //!
   TBranch        *b_pu_dataMixerRun;   //!
   TBranch        *b_pu_dataMixerEvt;   //!
   TBranch        *b_pu_dataMixerLumiSection;   //!
   TBranch        *b_genParticles_;   //!
   TBranch        *b_genParticles_status;   //!
   TBranch        *b_genParticles_charge;   //!
   TBranch        *b_genParticles_motherIndex;   //!
   TBranch        *b_genParticles_pdgId;   //!
   TBranch        *b_genParticles_vertex_fUniqueID;   //!
   TBranch        *b_genParticles_vertex_fBits;   //!
   TBranch        *b_genParticles_vertex_fX;   //!
   TBranch        *b_genParticles_vertex_fY;   //!
   TBranch        *b_genParticles_vertex_fZ;   //!
   TBranch        *b_genParticles_momentum_fUniqueID;   //!
   TBranch        *b_genParticles_momentum_fBits;   //!
   TBranch        *b_genParticles_momentum_fP_fUniqueID;   //!
   TBranch        *b_genParticles_momentum_fP_fBits;   //!
   TBranch        *b_genParticles_momentum_fP_fX;   //!
   TBranch        *b_genParticles_momentum_fP_fY;   //!
   TBranch        *b_genParticles_momentum_fP_fZ;   //!
   TBranch        *b_genParticles_momentum_fE;   //!
   TBranch        *b_met_caloType1CorrectedMet_sumEt;   //!
   TBranch        *b_met_caloType1CorrectedMet_significance;   //!
   TBranch        *b_met_caloType1CorrectedMet_mEt_fUniqueID;   //!
   TBranch        *b_met_caloType1CorrectedMet_mEt_fBits;   //!
   TBranch        *b_met_caloType1CorrectedMet_mEt_fX;   //!
   TBranch        *b_met_caloType1CorrectedMet_mEt_fY;   //!
   TBranch        *b_met_caloType1p2CorrectedMet_sumEt;   //!
   TBranch        *b_met_caloType1p2CorrectedMet_significance;   //!
   TBranch        *b_met_caloType1p2CorrectedMet_mEt_fUniqueID;   //!
   TBranch        *b_met_caloType1p2CorrectedMet_mEt_fBits;   //!
   TBranch        *b_met_caloType1p2CorrectedMet_mEt_fX;   //!
   TBranch        *b_met_caloType1p2CorrectedMet_mEt_fY;   //!
   TBranch        *b_met_corMetGlobalMuons_sumEt;   //!
   TBranch        *b_met_corMetGlobalMuons_significance;   //!
   TBranch        *b_met_corMetGlobalMuons_mEt_fUniqueID;   //!
   TBranch        *b_met_corMetGlobalMuons_mEt_fBits;   //!
   TBranch        *b_met_corMetGlobalMuons_mEt_fX;   //!
   TBranch        *b_met_corMetGlobalMuons_mEt_fY;   //!
   TBranch        *b_met_met_sumEt;   //!
   TBranch        *b_met_met_significance;   //!
   TBranch        *b_met_met_mEt_fUniqueID;   //!
   TBranch        *b_met_met_mEt_fBits;   //!
   TBranch        *b_met_met_mEt_fX;   //!
   TBranch        *b_met_met_mEt_fY;   //!
   TBranch        *b_met_pfMet_sumEt;   //!
   TBranch        *b_met_pfMet_significance;   //!
   TBranch        *b_met_pfMet_mEt_fUniqueID;   //!
   TBranch        *b_met_pfMet_mEt_fBits;   //!
   TBranch        *b_met_pfMet_mEt_fX;   //!
   TBranch        *b_met_pfMet_mEt_fY;   //!
   TBranch        *b_met_pfType01CorrectedMet_sumEt;   //!
   TBranch        *b_met_pfType01CorrectedMet_significance;   //!
   TBranch        *b_met_pfType01CorrectedMet_mEt_fUniqueID;   //!
   TBranch        *b_met_pfType01CorrectedMet_mEt_fBits;   //!
   TBranch        *b_met_pfType01CorrectedMet_mEt_fX;   //!
   TBranch        *b_met_pfType01CorrectedMet_mEt_fY;   //!
   TBranch        *b_met_pfType01p2CorrectedMet_sumEt;   //!
   TBranch        *b_met_pfType01p2CorrectedMet_significance;   //!
   TBranch        *b_met_pfType01p2CorrectedMet_mEt_fUniqueID;   //!
   TBranch        *b_met_pfType01p2CorrectedMet_mEt_fBits;   //!
   TBranch        *b_met_pfType01p2CorrectedMet_mEt_fX;   //!
   TBranch        *b_met_pfType01p2CorrectedMet_mEt_fY;   //!
   TBranch        *b_met_pfType1CorrectedMet_sumEt;   //!
   TBranch        *b_met_pfType1CorrectedMet_significance;   //!
   TBranch        *b_met_pfType1CorrectedMet_mEt_fUniqueID;   //!
   TBranch        *b_met_pfType1CorrectedMet_mEt_fBits;   //!
   TBranch        *b_met_pfType1CorrectedMet_mEt_fX;   //!
   TBranch        *b_met_pfType1CorrectedMet_mEt_fY;   //!
   TBranch        *b_met_pfType1p2CorrectedMet_sumEt;   //!
   TBranch        *b_met_pfType1p2CorrectedMet_significance;   //!
   TBranch        *b_met_pfType1p2CorrectedMet_mEt_fUniqueID;   //!
   TBranch        *b_met_pfType1p2CorrectedMet_mEt_fBits;   //!
   TBranch        *b_met_pfType1p2CorrectedMet_mEt_fX;   //!
   TBranch        *b_met_pfType1p2CorrectedMet_mEt_fY;   //!
   TBranch        *b_met_tcMet_sumEt;   //!
   TBranch        *b_met_tcMet_significance;   //!
   TBranch        *b_met_tcMet_mEt_fUniqueID;   //!
   TBranch        *b_met_tcMet_mEt_fBits;   //!
   TBranch        *b_met_tcMet_mEt_fX;   //!
   TBranch        *b_met_tcMet_mEt_fY;   //!
   TBranch        *b_muons_muons_;   //!
   TBranch        *b_muons_muons_type;   //!
   TBranch        *b_muons_muons_bestTrackType;   //!
   TBranch        *b_muons_muons_highPtBestTrackType;   //!
   TBranch        *b_muons_muons_qualityFlags;   //!
   TBranch        *b_muons_muons_nChambers;   //!
   TBranch        *b_muons_muons_nMatches;   //!
   TBranch        *b_muons_muons_stationMask;   //!
   TBranch        *b_muons_muons_nMatchedStations;   //!
   TBranch        *b_muons_muons_nValidHits;   //!
   TBranch        *b_muons_muons_nValidTrackerHits;   //!
   TBranch        *b_muons_muons_nValidMuonHits;   //!
   TBranch        *b_muons_muons_nPixelLayersWithMeasurement;   //!
   TBranch        *b_muons_muons_nStripLayersWithMeasurement;   //!
   TBranch        *b_muons_muons_timeNDof;   //!
   TBranch        *b_muons_muons_timeDirection;   //!
   TBranch        *b_muons_muons_timeAtIp;   //!
   TBranch        *b_muons_muons_timeAtIpError;   //!
   TBranch        *b_muons_muons_caloCompatibility;   //!
   TBranch        *b_muons_muons_segmentCompatibility;   //!
   TBranch        *b_muons_muons_emEnergy;   //!
   TBranch        *b_muons_muons_hadEnergy;   //!
   TBranch        *b_muons_muons_trackIsoR03;   //!
   TBranch        *b_muons_muons_ecalIsoR03;   //!
   TBranch        *b_muons_muons_hcalIsoR03;   //!
   TBranch        *b_muons_muons_trackIsoR05;   //!
   TBranch        *b_muons_muons_ecalIsoR05;   //!
   TBranch        *b_muons_muons_hcalIsoR05;   //!
   TBranch        *b_muons_muons_sumChargedHadronPt03;   //!
   TBranch        *b_muons_muons_sumChargedParticlePt03;   //!
   TBranch        *b_muons_muons_sumNeutralHadronEt03;   //!
   TBranch        *b_muons_muons_sumPhotonEt03;   //!
   TBranch        *b_muons_muons_sumNeutralHadronEtHighThreshold03;   //!
   TBranch        *b_muons_muons_sumPhotonEtHighThreshold03;   //!
   TBranch        *b_muons_muons_sumPUPt03;   //!
   TBranch        *b_muons_muons_sumChargedHadronPt04;   //!
   TBranch        *b_muons_muons_sumChargedParticlePt04;   //!
   TBranch        *b_muons_muons_sumNeutralHadronEt04;   //!
   TBranch        *b_muons_muons_sumPhotonEt04;   //!
   TBranch        *b_muons_muons_sumNeutralHadronEtHighThreshold04;   //!
   TBranch        *b_muons_muons_sumPhotonEtHighThreshold04;   //!
   TBranch        *b_muons_muons_sumPUPt04;   //!
   TBranch        *b_muons_muons_trackIndex;   //!
   TBranch        *b_muons_muons_standAloneTrackIndex;   //!
   TBranch        *b_muons_muons_combinedTrackIndex;   //!
   TBranch        *b_muons_muons_tpfmsTrackIndex;   //!
   TBranch        *b_muons_muons_pickyTrackIndex;   //!
   TBranch        *b_muons_muons_dytTrackIndex;   //!
   TBranch        *b_muons_muons_momentum_fUniqueID;   //!
   TBranch        *b_muons_muons_momentum_fBits;   //!
   TBranch        *b_muons_muons_momentum_fP_fUniqueID;   //!
   TBranch        *b_muons_muons_momentum_fP_fBits;   //!
   TBranch        *b_muons_muons_momentum_fP_fX;   //!
   TBranch        *b_muons_muons_momentum_fP_fY;   //!
   TBranch        *b_muons_muons_momentum_fP_fZ;   //!
   TBranch        *b_muons_muons_momentum_fE;   //!
   TBranch        *b_muons_muonsFromCosmics_;   //!
   TBranch        *b_muons_muonsFromCosmics_type;   //!
   TBranch        *b_muons_muonsFromCosmics_bestTrackType;   //!
   TBranch        *b_muons_muonsFromCosmics_highPtBestTrackType;   //!
   TBranch        *b_muons_muonsFromCosmics_qualityFlags;   //!
   TBranch        *b_muons_muonsFromCosmics_nChambers;   //!
   TBranch        *b_muons_muonsFromCosmics_nMatches;   //!
   TBranch        *b_muons_muonsFromCosmics_stationMask;   //!
   TBranch        *b_muons_muonsFromCosmics_nMatchedStations;   //!
   TBranch        *b_muons_muonsFromCosmics_nValidHits;   //!
   TBranch        *b_muons_muonsFromCosmics_nValidTrackerHits;   //!
   TBranch        *b_muons_muonsFromCosmics_nValidMuonHits;   //!
   TBranch        *b_muons_muonsFromCosmics_nPixelLayersWithMeasurement;   //!
   TBranch        *b_muons_muonsFromCosmics_nStripLayersWithMeasurement;   //!
   TBranch        *b_muons_muonsFromCosmics_timeNDof;   //!
   TBranch        *b_muons_muonsFromCosmics_timeDirection;   //!
   TBranch        *b_muons_muonsFromCosmics_timeAtIp;   //!
   TBranch        *b_muons_muonsFromCosmics_timeAtIpError;   //!
   TBranch        *b_muons_muonsFromCosmics_caloCompatibility;   //!
   TBranch        *b_muons_muonsFromCosmics_segmentCompatibility;   //!
   TBranch        *b_muons_muonsFromCosmics_emEnergy;   //!
   TBranch        *b_muons_muonsFromCosmics_hadEnergy;   //!
   TBranch        *b_muons_muonsFromCosmics_trackIsoR03;   //!
   TBranch        *b_muons_muonsFromCosmics_ecalIsoR03;   //!
   TBranch        *b_muons_muonsFromCosmics_hcalIsoR03;   //!
   TBranch        *b_muons_muonsFromCosmics_trackIsoR05;   //!
   TBranch        *b_muons_muonsFromCosmics_ecalIsoR05;   //!
   TBranch        *b_muons_muonsFromCosmics_hcalIsoR05;   //!
   TBranch        *b_muons_muonsFromCosmics_sumChargedHadronPt03;   //!
   TBranch        *b_muons_muonsFromCosmics_sumChargedParticlePt03;   //!
   TBranch        *b_muons_muonsFromCosmics_sumNeutralHadronEt03;   //!
   TBranch        *b_muons_muonsFromCosmics_sumPhotonEt03;   //!
   TBranch        *b_muons_muonsFromCosmics_sumNeutralHadronEtHighThreshold03;   //!
   TBranch        *b_muons_muonsFromCosmics_sumPhotonEtHighThreshold03;   //!
   TBranch        *b_muons_muonsFromCosmics_sumPUPt03;   //!
   TBranch        *b_muons_muonsFromCosmics_sumChargedHadronPt04;   //!
   TBranch        *b_muons_muonsFromCosmics_sumChargedParticlePt04;   //!
   TBranch        *b_muons_muonsFromCosmics_sumNeutralHadronEt04;   //!
   TBranch        *b_muons_muonsFromCosmics_sumPhotonEt04;   //!
   TBranch        *b_muons_muonsFromCosmics_sumNeutralHadronEtHighThreshold04;   //!
   TBranch        *b_muons_muonsFromCosmics_sumPhotonEtHighThreshold04;   //!
   TBranch        *b_muons_muonsFromCosmics_sumPUPt04;   //!
   TBranch        *b_muons_muonsFromCosmics_trackIndex;   //!
   TBranch        *b_muons_muonsFromCosmics_standAloneTrackIndex;   //!
   TBranch        *b_muons_muonsFromCosmics_combinedTrackIndex;   //!
   TBranch        *b_muons_muonsFromCosmics_tpfmsTrackIndex;   //!
   TBranch        *b_muons_muonsFromCosmics_pickyTrackIndex;   //!
   TBranch        *b_muons_muonsFromCosmics_dytTrackIndex;   //!
   TBranch        *b_muons_muonsFromCosmics_momentum_fUniqueID;   //!
   TBranch        *b_muons_muonsFromCosmics_momentum_fBits;   //!
   TBranch        *b_muons_muonsFromCosmics_momentum_fP_fUniqueID;   //!
   TBranch        *b_muons_muonsFromCosmics_momentum_fP_fBits;   //!
   TBranch        *b_muons_muonsFromCosmics_momentum_fP_fX;   //!
   TBranch        *b_muons_muonsFromCosmics_momentum_fP_fY;   //!
   TBranch        *b_muons_muonsFromCosmics_momentum_fP_fZ;   //!
   TBranch        *b_muons_muonsFromCosmics_momentum_fE;   //!
   TBranch        *b_electrons_gsfElectrons_;   //!
   TBranch        *b_electrons_gsfElectrons_fidBit;   //!
   TBranch        *b_electrons_gsfElectrons_scPixCharge;   //!
   TBranch        *b_electrons_gsfElectrons_boolPack;   //!
   TBranch        *b_electrons_gsfElectrons_convFlag;   //!
   TBranch        *b_electrons_gsfElectrons_eSuperClusterOverP;   //!
   TBranch        *b_electrons_gsfElectrons_eSeedClusterOverP;   //!
   TBranch        *b_electrons_gsfElectrons_eSeedClusterOverPout;   //!
   TBranch        *b_electrons_gsfElectrons_eEleClusterOverPout;   //!
   TBranch        *b_electrons_gsfElectrons_deltaEtaSuperClusterTrackAtVtx;   //!
   TBranch        *b_electrons_gsfElectrons_deltaEtaSeedClusterTrackAtCalo;   //!
   TBranch        *b_electrons_gsfElectrons_deltaEtaEleClusterTrackAtCalo;   //!
   TBranch        *b_electrons_gsfElectrons_deltaPhiSuperClusterTrackAtVtx;   //!
   TBranch        *b_electrons_gsfElectrons_deltaPhiSeedClusterTrackAtCalo;   //!
   TBranch        *b_electrons_gsfElectrons_deltaPhiEleClusterTrackAtCalo;   //!
   TBranch        *b_electrons_gsfElectrons_shFracInnerHits;   //!
   TBranch        *b_electrons_gsfElectrons_sigmaEtaEta;   //!
   TBranch        *b_electrons_gsfElectrons_sigmaIetaIeta;   //!
   TBranch        *b_electrons_gsfElectrons_sigmaIphiIphi;   //!
   TBranch        *b_electrons_gsfElectrons_e1x5;   //!
   TBranch        *b_electrons_gsfElectrons_e2x5Max;   //!
   TBranch        *b_electrons_gsfElectrons_e5x5;   //!
   TBranch        *b_electrons_gsfElectrons_r9;   //!
   TBranch        *b_electrons_gsfElectrons_hcalDepth1OverEcal;   //!
   TBranch        *b_electrons_gsfElectrons_hcalDepth2OverEcal;   //!
   TBranch        *b_electrons_gsfElectrons_hcalOverEcalBc;   //!
   TBranch        *b_electrons_gsfElectrons_dr03TkSumPt;   //!
   TBranch        *b_electrons_gsfElectrons_dr03EcalRecHitSumEt;   //!
   TBranch        *b_electrons_gsfElectrons_dr03HcalDepth1TowerSumEt;   //!
   TBranch        *b_electrons_gsfElectrons_dr03HcalDepth2TowerSumEt;   //!
   TBranch        *b_electrons_gsfElectrons_dr03HcalDepth1TowerSumEtBc;   //!
   TBranch        *b_electrons_gsfElectrons_dr03HcalDepth2TowerSumEtBc;   //!
   TBranch        *b_electrons_gsfElectrons_dr04TkSumPt;   //!
   TBranch        *b_electrons_gsfElectrons_dr04EcalRecHitSumEt;   //!
   TBranch        *b_electrons_gsfElectrons_dr04HcalDepth1TowerSumEt;   //!
   TBranch        *b_electrons_gsfElectrons_dr04HcalDepth2TowerSumEt;   //!
   TBranch        *b_electrons_gsfElectrons_dr04HcalDepth1TowerSumEtBc;   //!
   TBranch        *b_electrons_gsfElectrons_dr04HcalDepth2TowerSumEtBc;   //!
   TBranch        *b_electrons_gsfElectrons_convDist;   //!
   TBranch        *b_electrons_gsfElectrons_convDcot;   //!
   TBranch        *b_electrons_gsfElectrons_convRadius;   //!
   TBranch        *b_electrons_gsfElectrons_chargedHadronIso;   //!
   TBranch        *b_electrons_gsfElectrons_neutralHadronIso;   //!
   TBranch        *b_electrons_gsfElectrons_photonIso;   //!
   TBranch        *b_electrons_gsfElectrons_mvaStatus;   //!
   TBranch        *b_electrons_gsfElectrons_mva;   //!
   TBranch        *b_electrons_gsfElectrons_mvaTrig;   //!
   TBranch        *b_electrons_gsfElectrons_mvaNonTrig;   //!
   TBranch        *b_electrons_gsfElectrons_bremClass;   //!
   TBranch        *b_electrons_gsfElectrons_fbrem;   //!
   TBranch        *b_electrons_gsfElectrons_ecalEnergy;   //!
   TBranch        *b_electrons_gsfElectrons_ecalEnergyError;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumError;   //!
   TBranch        *b_electrons_gsfElectrons_gsfTrackIndex;   //!
   TBranch        *b_electrons_gsfElectrons_closestCtfTrackIndex;   //!
   TBranch        *b_electrons_gsfElectrons_electronClusterIndex;   //!
   TBranch        *b_electrons_gsfElectrons_superClusterIndex;   //!
   TBranch        *b_electrons_gsfElectrons_nMissingHits;   //!
   TBranch        *b_electrons_gsfElectrons_passConversionVeto;   //!
   TBranch        *b_electrons_gsfElectrons_trackPositionAtVtx_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackPositionAtVtx_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackPositionAtVtx_fX;   //!
   TBranch        *b_electrons_gsfElectrons_trackPositionAtVtx_fY;   //!
   TBranch        *b_electrons_gsfElectrons_trackPositionAtVtx_fZ;   //!
   TBranch        *b_electrons_gsfElectrons_trackPositionAtCalo_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackPositionAtCalo_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackPositionAtCalo_fX;   //!
   TBranch        *b_electrons_gsfElectrons_trackPositionAtCalo_fY;   //!
   TBranch        *b_electrons_gsfElectrons_trackPositionAtCalo_fZ;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtx_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtx_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtx_fP_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtx_fP_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtx_fP_fX;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtx_fP_fY;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtx_fP_fZ;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtx_fE;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtCalo_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtCalo_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtCalo_fP_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtCalo_fP_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtCalo_fP_fX;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtCalo_fP_fY;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtCalo_fP_fZ;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtCalo_fE;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumOut_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumOut_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumOut_fP_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumOut_fP_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumOut_fP_fX;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumOut_fP_fY;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumOut_fP_fZ;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumOut_fE;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtEleClus_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtEleClus_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtEleClus_fP_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtEleClus_fP_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtEleClus_fP_fX;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtEleClus_fP_fY;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtEleClus_fP_fZ;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtEleClus_fE;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fX;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fY;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fZ;   //!
   TBranch        *b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fE;   //!
   TBranch        *b_electrons_gsfElectrons_vertex_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_vertex_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_vertex_fX;   //!
   TBranch        *b_electrons_gsfElectrons_vertex_fY;   //!
   TBranch        *b_electrons_gsfElectrons_vertex_fZ;   //!
   TBranch        *b_electrons_gsfElectrons_momentum_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_momentum_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_momentum_fP_fUniqueID;   //!
   TBranch        *b_electrons_gsfElectrons_momentum_fP_fBits;   //!
   TBranch        *b_electrons_gsfElectrons_momentum_fP_fX;   //!
   TBranch        *b_electrons_gsfElectrons_momentum_fP_fY;   //!
   TBranch        *b_electrons_gsfElectrons_momentum_fP_fZ;   //!
   TBranch        *b_electrons_gsfElectrons_momentum_fE;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_fidBit;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_nPixelSeeds;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_passelectronveto;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_hadronicOverEm;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_hadTowOverEm;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_hadronicDepth1OverEm;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_hadronicDepth2OverEm;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_e1x2;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_e1x5;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_e2x5;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_e3x3;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_e5x5;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_maxEnergyXtal;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_sigmaEtaEta;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_sigmaIetaIeta;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_sigmaIphiIphi;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_r9;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_ecalRecHitSumEtConeDR04;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_hcalDepth1TowerSumEtConeDR04;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_hcalDepth2TowerSumEtConeDR04;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_hcalIsoConeDR04_2012;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_trkSumPtSolidConeDR04;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_trkSumPtHollowConeDR04;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_nTrkSolidConeDR04;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_nTrkHollowConeDR04;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_ecalRecHitSumEtConeDR03;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_hcalDepth1TowerSumEtConeDR03;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_hcalDepth2TowerSumEtConeDR03;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_hcalIsoConeDR03_2012;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_trkSumPtSolidConeDR03;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_trkSumPtHollowConeDR03;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_nTrkSolidConeDR03;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_nTrkHollowConeDR03;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_chargedHadronIso;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_neutralHadronIso;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_photonIso;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_worstOtherVtxChargedHadronIso;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_worstOtherVtxChargedHadronIsoVtxIdx;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_chargedHadronIsoDeposit;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_neutralHadronIsoDeposit;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_photonIsoDeposit;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_seedTime;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_mipChi2;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_mipTotEnergy;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_mipSlope;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_mipIntercept;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_mipNhitCone;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_mipIsHalo;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convInfo;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convDist;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convDcot;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convVtxChi2;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convVtxNdof;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convVertex_fUniqueID;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convVertex_fBits;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convVertex_fX;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convVertex_fY;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convVertex_fZ;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convDxy;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convDz;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convLxy;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convLz;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convZofPVFromTracks;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrackChargeProd;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack1nHit;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack2nHit;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack1chi2;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack2chi2;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack1pT;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack2pT;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack1InnerZ;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack2InnerZ;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack1InnerX;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack2InnerX;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack1InnerY;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack2InnerY;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack1Signedd0;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_convTrack2Signedd0;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_superClusterIndex;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_superClusterPreshowerEnergy;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_superClusterPhiWidth;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_superClusterEtaWidth;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_caloPosition_fUniqueID;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_caloPosition_fBits;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_caloPosition_fX;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_caloPosition_fY;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_caloPosition_fZ;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_MVAregEnergy;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_MVAregErr;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_momentum_fUniqueID;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_momentum_fBits;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_momentum_fP_fUniqueID;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_momentum_fP_fBits;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_momentum_fP_fX;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_momentum_fP_fY;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_momentum_fP_fZ;   //!
   TBranch        *b_photons_pfPhotonTranslator_pfphot_momentum_fE;   //!
   TBranch        *b_photons_photons_;   //!
   TBranch        *b_photons_photons_fidBit;   //!
   TBranch        *b_photons_photons_nPixelSeeds;   //!
   TBranch        *b_photons_photons_passelectronveto;   //!
   TBranch        *b_photons_photons_hadronicOverEm;   //!
   TBranch        *b_photons_photons_hadTowOverEm;   //!
   TBranch        *b_photons_photons_hadronicDepth1OverEm;   //!
   TBranch        *b_photons_photons_hadronicDepth2OverEm;   //!
   TBranch        *b_photons_photons_e1x2;   //!
   TBranch        *b_photons_photons_e1x5;   //!
   TBranch        *b_photons_photons_e2x5;   //!
   TBranch        *b_photons_photons_e3x3;   //!
   TBranch        *b_photons_photons_e5x5;   //!
   TBranch        *b_photons_photons_maxEnergyXtal;   //!
   TBranch        *b_photons_photons_sigmaEtaEta;   //!
   TBranch        *b_photons_photons_sigmaIetaIeta;   //!
   TBranch        *b_photons_photons_sigmaIphiIphi;   //!
   TBranch        *b_photons_photons_r9;   //!
   TBranch        *b_photons_photons_ecalRecHitSumEtConeDR04;   //!
   TBranch        *b_photons_photons_hcalDepth1TowerSumEtConeDR04;   //!
   TBranch        *b_photons_photons_hcalDepth2TowerSumEtConeDR04;   //!
   TBranch        *b_photons_photons_hcalIsoConeDR04_2012;   //!
   TBranch        *b_photons_photons_trkSumPtSolidConeDR04;   //!
   TBranch        *b_photons_photons_trkSumPtHollowConeDR04;   //!
   TBranch        *b_photons_photons_nTrkSolidConeDR04;   //!
   TBranch        *b_photons_photons_nTrkHollowConeDR04;   //!
   TBranch        *b_photons_photons_ecalRecHitSumEtConeDR03;   //!
   TBranch        *b_photons_photons_hcalDepth1TowerSumEtConeDR03;   //!
   TBranch        *b_photons_photons_hcalDepth2TowerSumEtConeDR03;   //!
   TBranch        *b_photons_photons_hcalIsoConeDR03_2012;   //!
   TBranch        *b_photons_photons_trkSumPtSolidConeDR03;   //!
   TBranch        *b_photons_photons_trkSumPtHollowConeDR03;   //!
   TBranch        *b_photons_photons_nTrkSolidConeDR03;   //!
   TBranch        *b_photons_photons_nTrkHollowConeDR03;   //!
   TBranch        *b_photons_photons_chargedHadronIso;   //!
   TBranch        *b_photons_photons_neutralHadronIso;   //!
   TBranch        *b_photons_photons_photonIso;   //!
   TBranch        *b_photons_photons_worstOtherVtxChargedHadronIso;   //!
   TBranch        *b_photons_photons_worstOtherVtxChargedHadronIsoVtxIdx;   //!
   TBranch        *b_photons_photons_chargedHadronIsoDeposit;   //!
   TBranch        *b_photons_photons_neutralHadronIsoDeposit;   //!
   TBranch        *b_photons_photons_photonIsoDeposit;   //!
   TBranch        *b_photons_photons_seedTime;   //!
   TBranch        *b_photons_photons_mipChi2;   //!
   TBranch        *b_photons_photons_mipTotEnergy;   //!
   TBranch        *b_photons_photons_mipSlope;   //!
   TBranch        *b_photons_photons_mipIntercept;   //!
   TBranch        *b_photons_photons_mipNhitCone;   //!
   TBranch        *b_photons_photons_mipIsHalo;   //!
   TBranch        *b_photons_photons_convInfo;   //!
   TBranch        *b_photons_photons_convDist;   //!
   TBranch        *b_photons_photons_convDcot;   //!
   TBranch        *b_photons_photons_convVtxChi2;   //!
   TBranch        *b_photons_photons_convVtxNdof;   //!
   TBranch        *b_photons_photons_convVertex_fUniqueID;   //!
   TBranch        *b_photons_photons_convVertex_fBits;   //!
   TBranch        *b_photons_photons_convVertex_fX;   //!
   TBranch        *b_photons_photons_convVertex_fY;   //!
   TBranch        *b_photons_photons_convVertex_fZ;   //!
   TBranch        *b_photons_photons_convDxy;   //!
   TBranch        *b_photons_photons_convDz;   //!
   TBranch        *b_photons_photons_convLxy;   //!
   TBranch        *b_photons_photons_convLz;   //!
   TBranch        *b_photons_photons_convZofPVFromTracks;   //!
   TBranch        *b_photons_photons_convTrackChargeProd;   //!
   TBranch        *b_photons_photons_convTrack1nHit;   //!
   TBranch        *b_photons_photons_convTrack2nHit;   //!
   TBranch        *b_photons_photons_convTrack1chi2;   //!
   TBranch        *b_photons_photons_convTrack2chi2;   //!
   TBranch        *b_photons_photons_convTrack1pT;   //!
   TBranch        *b_photons_photons_convTrack2pT;   //!
   TBranch        *b_photons_photons_convTrack1InnerZ;   //!
   TBranch        *b_photons_photons_convTrack2InnerZ;   //!
   TBranch        *b_photons_photons_convTrack1InnerX;   //!
   TBranch        *b_photons_photons_convTrack2InnerX;   //!
   TBranch        *b_photons_photons_convTrack1InnerY;   //!
   TBranch        *b_photons_photons_convTrack2InnerY;   //!
   TBranch        *b_photons_photons_convTrack1Signedd0;   //!
   TBranch        *b_photons_photons_convTrack2Signedd0;   //!
   TBranch        *b_photons_photons_superClusterIndex;   //!
   TBranch        *b_photons_photons_superClusterPreshowerEnergy;   //!
   TBranch        *b_photons_photons_superClusterPhiWidth;   //!
   TBranch        *b_photons_photons_superClusterEtaWidth;   //!
   TBranch        *b_photons_photons_caloPosition_fUniqueID;   //!
   TBranch        *b_photons_photons_caloPosition_fBits;   //!
   TBranch        *b_photons_photons_caloPosition_fX;   //!
   TBranch        *b_photons_photons_caloPosition_fY;   //!
   TBranch        *b_photons_photons_caloPosition_fZ;   //!
   TBranch        *b_photons_photons_MVAregEnergy;   //!
   TBranch        *b_photons_photons_MVAregErr;   //!
   TBranch        *b_photons_photons_momentum_fUniqueID;   //!
   TBranch        *b_photons_photons_momentum_fBits;   //!
   TBranch        *b_photons_photons_momentum_fP_fUniqueID;   //!
   TBranch        *b_photons_photons_momentum_fP_fBits;   //!
   TBranch        *b_photons_photons_momentum_fP_fX;   //!
   TBranch        *b_photons_photons_momentum_fP_fY;   //!
   TBranch        *b_photons_photons_momentum_fP_fZ;   //!
   TBranch        *b_photons_photons_momentum_fE;   //!
   TBranch        *b_pfJets_ak5_;   //!
   TBranch        *b_pfJets_ak5_phyDefFlavour;   //!
   TBranch        *b_pfJets_ak5_algDefFlavour;   //!
   TBranch        *b_pfJets_ak5_jetCharge;   //!
   TBranch        *b_pfJets_ak5_etaMean;   //!
   TBranch        *b_pfJets_ak5_phiMean;   //!
   TBranch        *b_pfJets_ak5_etaEtaMoment;   //!
   TBranch        *b_pfJets_ak5_etaPhiMoment;   //!
   TBranch        *b_pfJets_ak5_phiPhiMoment;   //!
   TBranch        *b_pfJets_ak5_maxDistance;   //!
   TBranch        *b_pfJets_ak5_jetArea;   //!
   TBranch        *b_pfJets_ak5_pileup;   //!
   TBranch        *b_pfJets_ak5_nPasses;   //!
   TBranch        *b_pfJets_ak5_nConstituents;   //!
   TBranch        *b_pfJets_ak5_chargedHadronEnergy;   //!
   TBranch        *b_pfJets_ak5_neutralHadronEnergy;   //!
   TBranch        *b_pfJets_ak5_photonEnergy;   //!
   TBranch        *b_pfJets_ak5_electronEnergy;   //!
   TBranch        *b_pfJets_ak5_muonEnergy;   //!
   TBranch        *b_pfJets_ak5_HFHadronEnergy;   //!
   TBranch        *b_pfJets_ak5_HFEMEnergy;   //!
   TBranch        *b_pfJets_ak5_chargedEmEnergy;   //!
   TBranch        *b_pfJets_ak5_chargedMuEnergy;   //!
   TBranch        *b_pfJets_ak5_neutralEmEnergy;   //!
   TBranch        *b_pfJets_ak5_chargedHadronMultiplicity;   //!
   TBranch        *b_pfJets_ak5_neutralHadronMultiplicity;   //!
   TBranch        *b_pfJets_ak5_photonMultiplicity;   //!
   TBranch        *b_pfJets_ak5_electronMultiplicity;   //!
   TBranch        *b_pfJets_ak5_muonMultiplicity;   //!
   TBranch        *b_pfJets_ak5_HFHadronMultiplicity;   //!
   TBranch        *b_pfJets_ak5_HFEMMultiplicity;   //!
   TBranch        *b_pfJets_ak5_chargedMultiplicity;   //!
   TBranch        *b_pfJets_ak5_neutralMultiplicity;   //!
   TBranch        *b_pfJets_ak5_tracklist;   //!
   TBranch        *b_pfJets_ak5_pfParticleList;   //!
   TBranch        *b_pfJets_ak5_puJetIdDiscriminants;   //!
   TBranch        *b_pfJets_ak5_puJetIdFlags;   //!
   TBranch        *b_pfJets_ak5_bTagDiscriminators;   //!
   TBranch        *b_pfJets_ak5_qgDiscriminators;   //!
   TBranch        *b_pfJets_ak5_momentum_fUniqueID;   //!
   TBranch        *b_pfJets_ak5_momentum_fBits;   //!
   TBranch        *b_pfJets_ak5_momentum_fP_fUniqueID;   //!
   TBranch        *b_pfJets_ak5_momentum_fP_fBits;   //!
   TBranch        *b_pfJets_ak5_momentum_fP_fX;   //!
   TBranch        *b_pfJets_ak5_momentum_fP_fY;   //!
   TBranch        *b_pfJets_ak5_momentum_fP_fZ;   //!
   TBranch        *b_pfJets_ak5_momentum_fE;   //!
   TBranch        *b_pfJets_ak5_jecUncertainty;   //!
   TBranch        *b_pfJets_ak5chs_;   //!
   TBranch        *b_pfJets_ak5chs_phyDefFlavour;   //!
   TBranch        *b_pfJets_ak5chs_algDefFlavour;   //!
   TBranch        *b_pfJets_ak5chs_jetCharge;   //!
   TBranch        *b_pfJets_ak5chs_etaMean;   //!
   TBranch        *b_pfJets_ak5chs_phiMean;   //!
   TBranch        *b_pfJets_ak5chs_etaEtaMoment;   //!
   TBranch        *b_pfJets_ak5chs_etaPhiMoment;   //!
   TBranch        *b_pfJets_ak5chs_phiPhiMoment;   //!
   TBranch        *b_pfJets_ak5chs_maxDistance;   //!
   TBranch        *b_pfJets_ak5chs_jetArea;   //!
   TBranch        *b_pfJets_ak5chs_pileup;   //!
   TBranch        *b_pfJets_ak5chs_nPasses;   //!
   TBranch        *b_pfJets_ak5chs_nConstituents;   //!
   TBranch        *b_pfJets_ak5chs_chargedHadronEnergy;   //!
   TBranch        *b_pfJets_ak5chs_neutralHadronEnergy;   //!
   TBranch        *b_pfJets_ak5chs_photonEnergy;   //!
   TBranch        *b_pfJets_ak5chs_electronEnergy;   //!
   TBranch        *b_pfJets_ak5chs_muonEnergy;   //!
   TBranch        *b_pfJets_ak5chs_HFHadronEnergy;   //!
   TBranch        *b_pfJets_ak5chs_HFEMEnergy;   //!
   TBranch        *b_pfJets_ak5chs_chargedEmEnergy;   //!
   TBranch        *b_pfJets_ak5chs_chargedMuEnergy;   //!
   TBranch        *b_pfJets_ak5chs_neutralEmEnergy;   //!
   TBranch        *b_pfJets_ak5chs_chargedHadronMultiplicity;   //!
   TBranch        *b_pfJets_ak5chs_neutralHadronMultiplicity;   //!
   TBranch        *b_pfJets_ak5chs_photonMultiplicity;   //!
   TBranch        *b_pfJets_ak5chs_electronMultiplicity;   //!
   TBranch        *b_pfJets_ak5chs_muonMultiplicity;   //!
   TBranch        *b_pfJets_ak5chs_HFHadronMultiplicity;   //!
   TBranch        *b_pfJets_ak5chs_HFEMMultiplicity;   //!
   TBranch        *b_pfJets_ak5chs_chargedMultiplicity;   //!
   TBranch        *b_pfJets_ak5chs_neutralMultiplicity;   //!
   TBranch        *b_pfJets_ak5chs_tracklist;   //!
   TBranch        *b_pfJets_ak5chs_pfParticleList;   //!
   TBranch        *b_pfJets_ak5chs_puJetIdDiscriminants;   //!
   TBranch        *b_pfJets_ak5chs_puJetIdFlags;   //!
   TBranch        *b_pfJets_ak5chs_bTagDiscriminators;   //!
   TBranch        *b_pfJets_ak5chs_qgDiscriminators;   //!
   TBranch        *b_pfJets_ak5chs_momentum_fUniqueID;   //!
   TBranch        *b_pfJets_ak5chs_momentum_fBits;   //!
   TBranch        *b_pfJets_ak5chs_momentum_fP_fUniqueID;   //!
   TBranch        *b_pfJets_ak5chs_momentum_fP_fBits;   //!
   TBranch        *b_pfJets_ak5chs_momentum_fP_fX;   //!
   TBranch        *b_pfJets_ak5chs_momentum_fP_fY;   //!
   TBranch        *b_pfJets_ak5chs_momentum_fP_fZ;   //!
   TBranch        *b_pfJets_ak5chs_momentum_fE;   //!
   TBranch        *b_pfJets_ak5chs_jecUncertainty;   //!


   DataSelector(TTree * /*tree*/ =0) : fChain(0) ,l1Map("l1"), hltMap("hlt"){ }
   virtual ~DataSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 1) {
	 int result = fChain ? fChain->GetEntry(entry, getall) : 0;
     if(fChain > 0){   
//		 fChain->LoadTree(entry);
//		 hltMap.setInput( *fChain);
 //    l1Map.setInput( *fChain);
//		 hltMap.addOutput(*fChain );
//     l1Map.addOutput( *fChain);
     l1Map.checkInput(*fChain );
     hltMap.checkInput( *fChain);
     } 
	   return result; 
	 }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
#ifdef rootcint
   ClassDef(DataSelector,0);
#endif
};

#endif

#ifdef DataSelector_cxx
void DataSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);
	 fChain->LoadTree(0);
   hltMap.setInput( *fChain);
   l1Map.setInput( *fChain);
 //  hltMap.addOutput( *fChain);
//   l1Map.addOutput( *fChain);
//	 l1Map.checkInput();
//   hltMap.checkInput(); 
   fChain->SetBranchAddress("isRealData", &isRealData, &b_isRealData);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("luminosityBlockNumber", &luminosityBlockNumber, &b_luminosityBlockNumber);
   fChain->SetBranchAddress("bunchCrossing", &bunchCrossing, &b_bunchCrossing);
   fChain->SetBranchAddress("cosmicFlag", &cosmicFlag, &b_cosmicFlag);
   fChain->SetBranchAddress("avgInsRecLumi", &avgInsRecLumi, &b_avgInsRecLumi);
   fChain->SetBranchAddress("intgRecLumi", &intgRecLumi, &b_intgRecLumi);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("rhoBarrel", &rhoBarrel, &b_rhoBarrel);
   fChain->SetBranchAddress("rho25", &rho25, &b_rho25);
   fChain->SetBranchAddress("metFilterBit", &metFilterBit, &b_metFilterBit);
   fChain->SetBranchAddress("metFilterMask", &metFilterMask, &b_metFilterMask);
   fChain->SetBranchAddress("beamSpot.TObject.fUniqueID", &beamSpot_TObject_fUniqueID, &b_beamSpot_TObject_fUniqueID);
   fChain->SetBranchAddress("beamSpot.TObject.fBits", &beamSpot_TObject_fBits, &b_beamSpot_TObject_fBits);
   fChain->SetBranchAddress("beamSpot.fX", &beamSpot_fX, &b_beamSpot_fX);
   fChain->SetBranchAddress("beamSpot.fY", &beamSpot_fY, &b_beamSpot_fY);
   fChain->SetBranchAddress("beamSpot.fZ", &beamSpot_fZ, &b_beamSpot_fZ);
   fChain->SetBranchAddress("vertices", &vertices_, &b_vertices_);
   fChain->SetBranchAddress("vertices.tracksSize", vertices_tracksSize, &b_vertices_tracksSize);
   fChain->SetBranchAddress("vertices.sumPt2", vertices_sumPt2, &b_vertices_sumPt2);
   fChain->SetBranchAddress("vertices.chi2", vertices_chi2, &b_vertices_chi2);
   fChain->SetBranchAddress("vertices.ndof", vertices_ndof, &b_vertices_ndof);
   fChain->SetBranchAddress("vertices.position.fUniqueID", vertices_position_fUniqueID, &b_vertices_position_fUniqueID);
   fChain->SetBranchAddress("vertices.position.fBits", vertices_position_fBits, &b_vertices_position_fBits);
   fChain->SetBranchAddress("vertices.position.fX", vertices_position_fX, &b_vertices_position_fX);
   fChain->SetBranchAddress("vertices.position.fY", vertices_position_fY, &b_vertices_position_fY);
   fChain->SetBranchAddress("vertices.position.fZ", vertices_position_fZ, &b_vertices_position_fZ);
   fChain->SetBranchAddress("tracks", &tracks_, &b_tracks_);
   fChain->SetBranchAddress("tracks.algorithm", tracks_algorithm, &b_tracks_algorithm);
   fChain->SetBranchAddress("tracks.quality", tracks_quality, &b_tracks_quality);
   fChain->SetBranchAddress("tracks.numberOfValidHits", tracks_numberOfValidHits, &b_tracks_numberOfValidHits);
   fChain->SetBranchAddress("tracks.numberOfValidTrackerHits", tracks_numberOfValidTrackerHits, &b_tracks_numberOfValidTrackerHits);
   fChain->SetBranchAddress("tracks.numberOfValidMuonHits", tracks_numberOfValidMuonHits, &b_tracks_numberOfValidMuonHits);
   fChain->SetBranchAddress("tracks.numberOfValidPixelHits", tracks_numberOfValidPixelHits, &b_tracks_numberOfValidPixelHits);
   fChain->SetBranchAddress("tracks.numberOfValidStripHits", tracks_numberOfValidStripHits, &b_tracks_numberOfValidStripHits);
   fChain->SetBranchAddress("tracks.vertexIndex", tracks_vertexIndex, &b_tracks_vertexIndex);
   fChain->SetBranchAddress("tracks.chi2", tracks_chi2, &b_tracks_chi2);
   fChain->SetBranchAddress("tracks.ndof", tracks_ndof, &b_tracks_ndof);
   fChain->SetBranchAddress("tracks.charge", tracks_charge, &b_tracks_charge);
   fChain->SetBranchAddress("tracks.error[5]", tracks_error, &b_tracks_error);
   fChain->SetBranchAddress("tracks.ptError", tracks_ptError, &b_tracks_ptError);
   fChain->SetBranchAddress("tracks.vertex.fUniqueID", tracks_vertex_fUniqueID, &b_tracks_vertex_fUniqueID);
   fChain->SetBranchAddress("tracks.vertex.fBits", tracks_vertex_fBits, &b_tracks_vertex_fBits);
   fChain->SetBranchAddress("tracks.vertex.fX", tracks_vertex_fX, &b_tracks_vertex_fX);
   fChain->SetBranchAddress("tracks.vertex.fY", tracks_vertex_fY, &b_tracks_vertex_fY);
   fChain->SetBranchAddress("tracks.vertex.fZ", tracks_vertex_fZ, &b_tracks_vertex_fZ);
   fChain->SetBranchAddress("tracks.momentum.fUniqueID", tracks_momentum_fUniqueID, &b_tracks_momentum_fUniqueID);
   fChain->SetBranchAddress("tracks.momentum.fBits", tracks_momentum_fBits, &b_tracks_momentum_fBits);
   fChain->SetBranchAddress("tracks.momentum.fP.fUniqueID", tracks_momentum_fP_fUniqueID, &b_tracks_momentum_fP_fUniqueID);
   fChain->SetBranchAddress("tracks.momentum.fP.fBits", tracks_momentum_fP_fBits, &b_tracks_momentum_fP_fBits);
   fChain->SetBranchAddress("tracks.momentum.fP.fX", tracks_momentum_fP_fX, &b_tracks_momentum_fP_fX);
   fChain->SetBranchAddress("tracks.momentum.fP.fY", tracks_momentum_fP_fY, &b_tracks_momentum_fP_fY);
   fChain->SetBranchAddress("tracks.momentum.fP.fZ", tracks_momentum_fP_fZ, &b_tracks_momentum_fP_fZ);
   fChain->SetBranchAddress("tracks.momentum.fE", tracks_momentum_fE, &b_tracks_momentum_fE);
   fChain->SetBranchAddress("superClusters", &superClusters_, &b_superClusters_);
   fChain->SetBranchAddress("superClusters.seedClusterIndex", superClusters_seedClusterIndex, &b_superClusters_seedClusterIndex);
   fChain->SetBranchAddress("superClusters.energy", superClusters_energy, &b_superClusters_energy);
   fChain->SetBranchAddress("superClusters.preshowerEnergy", superClusters_preshowerEnergy, &b_superClusters_preshowerEnergy);
   fChain->SetBranchAddress("superClusters.phiWidth", superClusters_phiWidth, &b_superClusters_phiWidth);
   fChain->SetBranchAddress("superClusters.etaWidth", superClusters_etaWidth, &b_superClusters_etaWidth);
   fChain->SetBranchAddress("superClusters.position.fUniqueID", superClusters_position_fUniqueID, &b_superClusters_position_fUniqueID);
   fChain->SetBranchAddress("superClusters.position.fBits", superClusters_position_fBits, &b_superClusters_position_fBits);
   fChain->SetBranchAddress("superClusters.position.fX", superClusters_position_fX, &b_superClusters_position_fX);
   fChain->SetBranchAddress("superClusters.position.fY", superClusters_position_fY, &b_superClusters_position_fY);
   fChain->SetBranchAddress("superClusters.position.fZ", superClusters_position_fZ, &b_superClusters_position_fZ);
   fChain->SetBranchAddress("superClusters.basicClusterIndices", superClusters_basicClusterIndices, &b_superClusters_basicClusterIndices);
   fChain->SetBranchAddress("clusters", &clusters_, &b_clusters_);
   fChain->SetBranchAddress("clusters.nCrystals", clusters_nCrystals, &b_clusters_nCrystals);
   fChain->SetBranchAddress("clusters.energy", clusters_energy, &b_clusters_energy);
   fChain->SetBranchAddress("clusters.position.fUniqueID", clusters_position_fUniqueID, &b_clusters_position_fUniqueID);
   fChain->SetBranchAddress("clusters.position.fBits", clusters_position_fBits, &b_clusters_position_fBits);
   fChain->SetBranchAddress("clusters.position.fX", clusters_position_fX, &b_clusters_position_fX);
   fChain->SetBranchAddress("clusters.position.fY", clusters_position_fY, &b_clusters_position_fY);
   fChain->SetBranchAddress("clusters.position.fZ", clusters_position_fZ, &b_clusters_position_fZ);
   fChain->SetBranchAddress("pfParticles", &pfParticles_, &b_pfParticles_);
   fChain->SetBranchAddress("pfParticles.charge", pfParticles_charge, &b_pfParticles_charge);
   fChain->SetBranchAddress("pfParticles.isPU", pfParticles_isPU, &b_pfParticles_isPU);
   fChain->SetBranchAddress("pfParticles.pdgId", pfParticles_pdgId, &b_pfParticles_pdgId);
   fChain->SetBranchAddress("pfParticles.ecalEnergy", pfParticles_ecalEnergy, &b_pfParticles_ecalEnergy);
   fChain->SetBranchAddress("pfParticles.hcalEnergy", pfParticles_hcalEnergy, &b_pfParticles_hcalEnergy);
   fChain->SetBranchAddress("pfParticles.vertex.fUniqueID", pfParticles_vertex_fUniqueID, &b_pfParticles_vertex_fUniqueID);
   fChain->SetBranchAddress("pfParticles.vertex.fBits", pfParticles_vertex_fBits, &b_pfParticles_vertex_fBits);
   fChain->SetBranchAddress("pfParticles.vertex.fX", pfParticles_vertex_fX, &b_pfParticles_vertex_fX);
   fChain->SetBranchAddress("pfParticles.vertex.fY", pfParticles_vertex_fY, &b_pfParticles_vertex_fY);
   fChain->SetBranchAddress("pfParticles.vertex.fZ", pfParticles_vertex_fZ, &b_pfParticles_vertex_fZ);
   fChain->SetBranchAddress("pfParticles.momentum.fUniqueID", pfParticles_momentum_fUniqueID, &b_pfParticles_momentum_fUniqueID);
   fChain->SetBranchAddress("pfParticles.momentum.fBits", pfParticles_momentum_fBits, &b_pfParticles_momentum_fBits);
   fChain->SetBranchAddress("pfParticles.momentum.fP.fUniqueID", pfParticles_momentum_fP_fUniqueID, &b_pfParticles_momentum_fP_fUniqueID);
   fChain->SetBranchAddress("pfParticles.momentum.fP.fBits", pfParticles_momentum_fP_fBits, &b_pfParticles_momentum_fP_fBits);
   fChain->SetBranchAddress("pfParticles.momentum.fP.fX", pfParticles_momentum_fP_fX, &b_pfParticles_momentum_fP_fX);
   fChain->SetBranchAddress("pfParticles.momentum.fP.fY", pfParticles_momentum_fP_fY, &b_pfParticles_momentum_fP_fY);
   fChain->SetBranchAddress("pfParticles.momentum.fP.fZ", pfParticles_momentum_fP_fZ, &b_pfParticles_momentum_fP_fZ);
   fChain->SetBranchAddress("pfParticles.momentum.fE", pfParticles_momentum_fE, &b_pfParticles_momentum_fE);
   fChain->SetBranchAddress("pu", &pu_, &b_pu_);
   fChain->SetBranchAddress("pu.BX", &pu_BX, &b_pu_BX);
   fChain->SetBranchAddress("pu.numInteractions", &pu_numInteractions, &b_pu_numInteractions);
   fChain->SetBranchAddress("pu.trueNumInteractions", &pu_trueNumInteractions, &b_pu_trueNumInteractions);
   fChain->SetBranchAddress("pu.zPositions", &pu_zPositions, &b_pu_zPositions);
   fChain->SetBranchAddress("pu.sumPTLowPT", &pu_sumPTLowPT, &b_pu_sumPTLowPT);
   fChain->SetBranchAddress("pu.sumPTHighPT", &pu_sumPTHighPT, &b_pu_sumPTHighPT);
   fChain->SetBranchAddress("pu.numTracksLowPT", &pu_numTracksLowPT, &b_pu_numTracksLowPT);
   fChain->SetBranchAddress("pu.numTracksHighPT", &pu_numTracksHighPT, &b_pu_numTracksHighPT);
   fChain->SetBranchAddress("pu.instLumi", &pu_instLumi, &b_pu_instLumi);
   fChain->SetBranchAddress("pu.dataMixerRun", &pu_dataMixerRun, &b_pu_dataMixerRun);
   fChain->SetBranchAddress("pu.dataMixerEvt", &pu_dataMixerEvt, &b_pu_dataMixerEvt);
   fChain->SetBranchAddress("pu.dataMixerLumiSection", &pu_dataMixerLumiSection, &b_pu_dataMixerLumiSection);
   fChain->SetBranchAddress("genParticles", &genParticles_, &b_genParticles_);
   fChain->SetBranchAddress("genParticles.status", &genParticles_status, &b_genParticles_status);
   fChain->SetBranchAddress("genParticles.charge", &genParticles_charge, &b_genParticles_charge);
   fChain->SetBranchAddress("genParticles.motherIndex", &genParticles_motherIndex, &b_genParticles_motherIndex);
   fChain->SetBranchAddress("genParticles.pdgId", &genParticles_pdgId, &b_genParticles_pdgId);
   fChain->SetBranchAddress("genParticles.vertex.fUniqueID", &genParticles_vertex_fUniqueID, &b_genParticles_vertex_fUniqueID);
   fChain->SetBranchAddress("genParticles.vertex.fBits", &genParticles_vertex_fBits, &b_genParticles_vertex_fBits);
   fChain->SetBranchAddress("genParticles.vertex.fX", &genParticles_vertex_fX, &b_genParticles_vertex_fX);
   fChain->SetBranchAddress("genParticles.vertex.fY", &genParticles_vertex_fY, &b_genParticles_vertex_fY);
   fChain->SetBranchAddress("genParticles.vertex.fZ", &genParticles_vertex_fZ, &b_genParticles_vertex_fZ);
   fChain->SetBranchAddress("genParticles.momentum.fUniqueID", &genParticles_momentum_fUniqueID, &b_genParticles_momentum_fUniqueID);
   fChain->SetBranchAddress("genParticles.momentum.fBits", &genParticles_momentum_fBits, &b_genParticles_momentum_fBits);
   fChain->SetBranchAddress("genParticles.momentum.fP.fUniqueID", &genParticles_momentum_fP_fUniqueID, &b_genParticles_momentum_fP_fUniqueID);
   fChain->SetBranchAddress("genParticles.momentum.fP.fBits", &genParticles_momentum_fP_fBits, &b_genParticles_momentum_fP_fBits);
   fChain->SetBranchAddress("genParticles.momentum.fP.fX", &genParticles_momentum_fP_fX, &b_genParticles_momentum_fP_fX);
   fChain->SetBranchAddress("genParticles.momentum.fP.fY", &genParticles_momentum_fP_fY, &b_genParticles_momentum_fP_fY);
   fChain->SetBranchAddress("genParticles.momentum.fP.fZ", &genParticles_momentum_fP_fZ, &b_genParticles_momentum_fP_fZ);
   fChain->SetBranchAddress("genParticles.momentum.fE", &genParticles_momentum_fE, &b_genParticles_momentum_fE);
   fChain->SetBranchAddress("met_caloType1CorrectedMet.sumEt", &met_caloType1CorrectedMet_sumEt, &b_met_caloType1CorrectedMet_sumEt);
   fChain->SetBranchAddress("met_caloType1CorrectedMet.significance", &met_caloType1CorrectedMet_significance, &b_met_caloType1CorrectedMet_significance);
   fChain->SetBranchAddress("met_caloType1CorrectedMet.mEt.fUniqueID", &met_caloType1CorrectedMet_mEt_fUniqueID, &b_met_caloType1CorrectedMet_mEt_fUniqueID);
   fChain->SetBranchAddress("met_caloType1CorrectedMet.mEt.fBits", &met_caloType1CorrectedMet_mEt_fBits, &b_met_caloType1CorrectedMet_mEt_fBits);
   fChain->SetBranchAddress("met_caloType1CorrectedMet.mEt.fX", &met_caloType1CorrectedMet_mEt_fX, &b_met_caloType1CorrectedMet_mEt_fX);
   fChain->SetBranchAddress("met_caloType1CorrectedMet.mEt.fY", &met_caloType1CorrectedMet_mEt_fY, &b_met_caloType1CorrectedMet_mEt_fY);
   fChain->SetBranchAddress("met_caloType1p2CorrectedMet.sumEt", &met_caloType1p2CorrectedMet_sumEt, &b_met_caloType1p2CorrectedMet_sumEt);
   fChain->SetBranchAddress("met_caloType1p2CorrectedMet.significance", &met_caloType1p2CorrectedMet_significance, &b_met_caloType1p2CorrectedMet_significance);
   fChain->SetBranchAddress("met_caloType1p2CorrectedMet.mEt.fUniqueID", &met_caloType1p2CorrectedMet_mEt_fUniqueID, &b_met_caloType1p2CorrectedMet_mEt_fUniqueID);
   fChain->SetBranchAddress("met_caloType1p2CorrectedMet.mEt.fBits", &met_caloType1p2CorrectedMet_mEt_fBits, &b_met_caloType1p2CorrectedMet_mEt_fBits);
   fChain->SetBranchAddress("met_caloType1p2CorrectedMet.mEt.fX", &met_caloType1p2CorrectedMet_mEt_fX, &b_met_caloType1p2CorrectedMet_mEt_fX);
   fChain->SetBranchAddress("met_caloType1p2CorrectedMet.mEt.fY", &met_caloType1p2CorrectedMet_mEt_fY, &b_met_caloType1p2CorrectedMet_mEt_fY);
   fChain->SetBranchAddress("met_corMetGlobalMuons.sumEt", &met_corMetGlobalMuons_sumEt, &b_met_corMetGlobalMuons_sumEt);
   fChain->SetBranchAddress("met_corMetGlobalMuons.significance", &met_corMetGlobalMuons_significance, &b_met_corMetGlobalMuons_significance);
   fChain->SetBranchAddress("met_corMetGlobalMuons.mEt.fUniqueID", &met_corMetGlobalMuons_mEt_fUniqueID, &b_met_corMetGlobalMuons_mEt_fUniqueID);
   fChain->SetBranchAddress("met_corMetGlobalMuons.mEt.fBits", &met_corMetGlobalMuons_mEt_fBits, &b_met_corMetGlobalMuons_mEt_fBits);
   fChain->SetBranchAddress("met_corMetGlobalMuons.mEt.fX", &met_corMetGlobalMuons_mEt_fX, &b_met_corMetGlobalMuons_mEt_fX);
   fChain->SetBranchAddress("met_corMetGlobalMuons.mEt.fY", &met_corMetGlobalMuons_mEt_fY, &b_met_corMetGlobalMuons_mEt_fY);
   fChain->SetBranchAddress("met_met.sumEt", &met_met_sumEt, &b_met_met_sumEt);
   fChain->SetBranchAddress("met_met.significance", &met_met_significance, &b_met_met_significance);
   fChain->SetBranchAddress("met_met.mEt.fUniqueID", &met_met_mEt_fUniqueID, &b_met_met_mEt_fUniqueID);
   fChain->SetBranchAddress("met_met.mEt.fBits", &met_met_mEt_fBits, &b_met_met_mEt_fBits);
   fChain->SetBranchAddress("met_met.mEt.fX", &met_met_mEt_fX, &b_met_met_mEt_fX);
   fChain->SetBranchAddress("met_met.mEt.fY", &met_met_mEt_fY, &b_met_met_mEt_fY);
   fChain->SetBranchAddress("met_pfMet.sumEt", &met_pfMet_sumEt, &b_met_pfMet_sumEt);
   fChain->SetBranchAddress("met_pfMet.significance", &met_pfMet_significance, &b_met_pfMet_significance);
   fChain->SetBranchAddress("met_pfMet.mEt.fUniqueID", &met_pfMet_mEt_fUniqueID, &b_met_pfMet_mEt_fUniqueID);
   fChain->SetBranchAddress("met_pfMet.mEt.fBits", &met_pfMet_mEt_fBits, &b_met_pfMet_mEt_fBits);
   fChain->SetBranchAddress("met_pfMet.mEt.fX", &met_pfMet_mEt_fX, &b_met_pfMet_mEt_fX);
   fChain->SetBranchAddress("met_pfMet.mEt.fY", &met_pfMet_mEt_fY, &b_met_pfMet_mEt_fY);
   fChain->SetBranchAddress("met_pfType01CorrectedMet.sumEt", &met_pfType01CorrectedMet_sumEt, &b_met_pfType01CorrectedMet_sumEt);
   fChain->SetBranchAddress("met_pfType01CorrectedMet.significance", &met_pfType01CorrectedMet_significance, &b_met_pfType01CorrectedMet_significance);
   fChain->SetBranchAddress("met_pfType01CorrectedMet.mEt.fUniqueID", &met_pfType01CorrectedMet_mEt_fUniqueID, &b_met_pfType01CorrectedMet_mEt_fUniqueID);
   fChain->SetBranchAddress("met_pfType01CorrectedMet.mEt.fBits", &met_pfType01CorrectedMet_mEt_fBits, &b_met_pfType01CorrectedMet_mEt_fBits);
   fChain->SetBranchAddress("met_pfType01CorrectedMet.mEt.fX", &met_pfType01CorrectedMet_mEt_fX, &b_met_pfType01CorrectedMet_mEt_fX);
   fChain->SetBranchAddress("met_pfType01CorrectedMet.mEt.fY", &met_pfType01CorrectedMet_mEt_fY, &b_met_pfType01CorrectedMet_mEt_fY);
   fChain->SetBranchAddress("met_pfType01p2CorrectedMet.sumEt", &met_pfType01p2CorrectedMet_sumEt, &b_met_pfType01p2CorrectedMet_sumEt);
   fChain->SetBranchAddress("met_pfType01p2CorrectedMet.significance", &met_pfType01p2CorrectedMet_significance, &b_met_pfType01p2CorrectedMet_significance);
   fChain->SetBranchAddress("met_pfType01p2CorrectedMet.mEt.fUniqueID", &met_pfType01p2CorrectedMet_mEt_fUniqueID, &b_met_pfType01p2CorrectedMet_mEt_fUniqueID);
   fChain->SetBranchAddress("met_pfType01p2CorrectedMet.mEt.fBits", &met_pfType01p2CorrectedMet_mEt_fBits, &b_met_pfType01p2CorrectedMet_mEt_fBits);
   fChain->SetBranchAddress("met_pfType01p2CorrectedMet.mEt.fX", &met_pfType01p2CorrectedMet_mEt_fX, &b_met_pfType01p2CorrectedMet_mEt_fX);
   fChain->SetBranchAddress("met_pfType01p2CorrectedMet.mEt.fY", &met_pfType01p2CorrectedMet_mEt_fY, &b_met_pfType01p2CorrectedMet_mEt_fY);
   fChain->SetBranchAddress("met_pfType1CorrectedMet.sumEt", &met_pfType1CorrectedMet_sumEt, &b_met_pfType1CorrectedMet_sumEt);
   fChain->SetBranchAddress("met_pfType1CorrectedMet.significance", &met_pfType1CorrectedMet_significance, &b_met_pfType1CorrectedMet_significance);
   fChain->SetBranchAddress("met_pfType1CorrectedMet.mEt.fUniqueID", &met_pfType1CorrectedMet_mEt_fUniqueID, &b_met_pfType1CorrectedMet_mEt_fUniqueID);
   fChain->SetBranchAddress("met_pfType1CorrectedMet.mEt.fBits", &met_pfType1CorrectedMet_mEt_fBits, &b_met_pfType1CorrectedMet_mEt_fBits);
   fChain->SetBranchAddress("met_pfType1CorrectedMet.mEt.fX", &met_pfType1CorrectedMet_mEt_fX, &b_met_pfType1CorrectedMet_mEt_fX);
   fChain->SetBranchAddress("met_pfType1CorrectedMet.mEt.fY", &met_pfType1CorrectedMet_mEt_fY, &b_met_pfType1CorrectedMet_mEt_fY);
   fChain->SetBranchAddress("met_pfType1p2CorrectedMet.sumEt", &met_pfType1p2CorrectedMet_sumEt, &b_met_pfType1p2CorrectedMet_sumEt);
   fChain->SetBranchAddress("met_pfType1p2CorrectedMet.significance", &met_pfType1p2CorrectedMet_significance, &b_met_pfType1p2CorrectedMet_significance);
   fChain->SetBranchAddress("met_pfType1p2CorrectedMet.mEt.fUniqueID", &met_pfType1p2CorrectedMet_mEt_fUniqueID, &b_met_pfType1p2CorrectedMet_mEt_fUniqueID);
   fChain->SetBranchAddress("met_pfType1p2CorrectedMet.mEt.fBits", &met_pfType1p2CorrectedMet_mEt_fBits, &b_met_pfType1p2CorrectedMet_mEt_fBits);
   fChain->SetBranchAddress("met_pfType1p2CorrectedMet.mEt.fX", &met_pfType1p2CorrectedMet_mEt_fX, &b_met_pfType1p2CorrectedMet_mEt_fX);
   fChain->SetBranchAddress("met_pfType1p2CorrectedMet.mEt.fY", &met_pfType1p2CorrectedMet_mEt_fY, &b_met_pfType1p2CorrectedMet_mEt_fY);
   fChain->SetBranchAddress("met_tcMet.sumEt", &met_tcMet_sumEt, &b_met_tcMet_sumEt);
   fChain->SetBranchAddress("met_tcMet.significance", &met_tcMet_significance, &b_met_tcMet_significance);
   fChain->SetBranchAddress("met_tcMet.mEt.fUniqueID", &met_tcMet_mEt_fUniqueID, &b_met_tcMet_mEt_fUniqueID);
   fChain->SetBranchAddress("met_tcMet.mEt.fBits", &met_tcMet_mEt_fBits, &b_met_tcMet_mEt_fBits);
   fChain->SetBranchAddress("met_tcMet.mEt.fX", &met_tcMet_mEt_fX, &b_met_tcMet_mEt_fX);
   fChain->SetBranchAddress("met_tcMet.mEt.fY", &met_tcMet_mEt_fY, &b_met_tcMet_mEt_fY);
   fChain->SetBranchAddress("muons_muons", &muons_muons_, &b_muons_muons_);
   fChain->SetBranchAddress("muons_muons.type", muons_muons_type, &b_muons_muons_type);
   fChain->SetBranchAddress("muons_muons.bestTrackType", muons_muons_bestTrackType, &b_muons_muons_bestTrackType);
   fChain->SetBranchAddress("muons_muons.highPtBestTrackType", muons_muons_highPtBestTrackType, &b_muons_muons_highPtBestTrackType);
   fChain->SetBranchAddress("muons_muons.qualityFlags", muons_muons_qualityFlags, &b_muons_muons_qualityFlags);
   fChain->SetBranchAddress("muons_muons.nChambers", muons_muons_nChambers, &b_muons_muons_nChambers);
   fChain->SetBranchAddress("muons_muons.nMatches", muons_muons_nMatches, &b_muons_muons_nMatches);
   fChain->SetBranchAddress("muons_muons.stationMask", muons_muons_stationMask, &b_muons_muons_stationMask);
   fChain->SetBranchAddress("muons_muons.nMatchedStations", muons_muons_nMatchedStations, &b_muons_muons_nMatchedStations);
   fChain->SetBranchAddress("muons_muons.nValidHits", muons_muons_nValidHits, &b_muons_muons_nValidHits);
   fChain->SetBranchAddress("muons_muons.nValidTrackerHits", muons_muons_nValidTrackerHits, &b_muons_muons_nValidTrackerHits);
   fChain->SetBranchAddress("muons_muons.nValidMuonHits", muons_muons_nValidMuonHits, &b_muons_muons_nValidMuonHits);
   fChain->SetBranchAddress("muons_muons.nPixelLayersWithMeasurement", muons_muons_nPixelLayersWithMeasurement, &b_muons_muons_nPixelLayersWithMeasurement);
   fChain->SetBranchAddress("muons_muons.nStripLayersWithMeasurement", muons_muons_nStripLayersWithMeasurement, &b_muons_muons_nStripLayersWithMeasurement);
   fChain->SetBranchAddress("muons_muons.timeNDof", muons_muons_timeNDof, &b_muons_muons_timeNDof);
   fChain->SetBranchAddress("muons_muons.timeDirection", muons_muons_timeDirection, &b_muons_muons_timeDirection);
   fChain->SetBranchAddress("muons_muons.timeAtIp", muons_muons_timeAtIp, &b_muons_muons_timeAtIp);
   fChain->SetBranchAddress("muons_muons.timeAtIpError", muons_muons_timeAtIpError, &b_muons_muons_timeAtIpError);
   fChain->SetBranchAddress("muons_muons.caloCompatibility", muons_muons_caloCompatibility, &b_muons_muons_caloCompatibility);
   fChain->SetBranchAddress("muons_muons.segmentCompatibility", muons_muons_segmentCompatibility, &b_muons_muons_segmentCompatibility);
   fChain->SetBranchAddress("muons_muons.emEnergy", muons_muons_emEnergy, &b_muons_muons_emEnergy);
   fChain->SetBranchAddress("muons_muons.hadEnergy", muons_muons_hadEnergy, &b_muons_muons_hadEnergy);
   fChain->SetBranchAddress("muons_muons.trackIsoR03", muons_muons_trackIsoR03, &b_muons_muons_trackIsoR03);
   fChain->SetBranchAddress("muons_muons.ecalIsoR03", muons_muons_ecalIsoR03, &b_muons_muons_ecalIsoR03);
   fChain->SetBranchAddress("muons_muons.hcalIsoR03", muons_muons_hcalIsoR03, &b_muons_muons_hcalIsoR03);
   fChain->SetBranchAddress("muons_muons.trackIsoR05", muons_muons_trackIsoR05, &b_muons_muons_trackIsoR05);
   fChain->SetBranchAddress("muons_muons.ecalIsoR05", muons_muons_ecalIsoR05, &b_muons_muons_ecalIsoR05);
   fChain->SetBranchAddress("muons_muons.hcalIsoR05", muons_muons_hcalIsoR05, &b_muons_muons_hcalIsoR05);
   fChain->SetBranchAddress("muons_muons.sumChargedHadronPt03", muons_muons_sumChargedHadronPt03, &b_muons_muons_sumChargedHadronPt03);
   fChain->SetBranchAddress("muons_muons.sumChargedParticlePt03", muons_muons_sumChargedParticlePt03, &b_muons_muons_sumChargedParticlePt03);
   fChain->SetBranchAddress("muons_muons.sumNeutralHadronEt03", muons_muons_sumNeutralHadronEt03, &b_muons_muons_sumNeutralHadronEt03);
   fChain->SetBranchAddress("muons_muons.sumPhotonEt03", muons_muons_sumPhotonEt03, &b_muons_muons_sumPhotonEt03);
   fChain->SetBranchAddress("muons_muons.sumNeutralHadronEtHighThreshold03", muons_muons_sumNeutralHadronEtHighThreshold03, &b_muons_muons_sumNeutralHadronEtHighThreshold03);
   fChain->SetBranchAddress("muons_muons.sumPhotonEtHighThreshold03", muons_muons_sumPhotonEtHighThreshold03, &b_muons_muons_sumPhotonEtHighThreshold03);
   fChain->SetBranchAddress("muons_muons.sumPUPt03", muons_muons_sumPUPt03, &b_muons_muons_sumPUPt03);
   fChain->SetBranchAddress("muons_muons.sumChargedHadronPt04", muons_muons_sumChargedHadronPt04, &b_muons_muons_sumChargedHadronPt04);
   fChain->SetBranchAddress("muons_muons.sumChargedParticlePt04", muons_muons_sumChargedParticlePt04, &b_muons_muons_sumChargedParticlePt04);
   fChain->SetBranchAddress("muons_muons.sumNeutralHadronEt04", muons_muons_sumNeutralHadronEt04, &b_muons_muons_sumNeutralHadronEt04);
   fChain->SetBranchAddress("muons_muons.sumPhotonEt04", muons_muons_sumPhotonEt04, &b_muons_muons_sumPhotonEt04);
   fChain->SetBranchAddress("muons_muons.sumNeutralHadronEtHighThreshold04", muons_muons_sumNeutralHadronEtHighThreshold04, &b_muons_muons_sumNeutralHadronEtHighThreshold04);
   fChain->SetBranchAddress("muons_muons.sumPhotonEtHighThreshold04", muons_muons_sumPhotonEtHighThreshold04, &b_muons_muons_sumPhotonEtHighThreshold04);
   fChain->SetBranchAddress("muons_muons.sumPUPt04", muons_muons_sumPUPt04, &b_muons_muons_sumPUPt04);
   fChain->SetBranchAddress("muons_muons.trackIndex", muons_muons_trackIndex, &b_muons_muons_trackIndex);
   fChain->SetBranchAddress("muons_muons.standAloneTrackIndex", muons_muons_standAloneTrackIndex, &b_muons_muons_standAloneTrackIndex);
   fChain->SetBranchAddress("muons_muons.combinedTrackIndex", muons_muons_combinedTrackIndex, &b_muons_muons_combinedTrackIndex);
   fChain->SetBranchAddress("muons_muons.tpfmsTrackIndex", muons_muons_tpfmsTrackIndex, &b_muons_muons_tpfmsTrackIndex);
   fChain->SetBranchAddress("muons_muons.pickyTrackIndex", muons_muons_pickyTrackIndex, &b_muons_muons_pickyTrackIndex);
   fChain->SetBranchAddress("muons_muons.dytTrackIndex", muons_muons_dytTrackIndex, &b_muons_muons_dytTrackIndex);
   fChain->SetBranchAddress("muons_muons.momentum.fUniqueID", muons_muons_momentum_fUniqueID, &b_muons_muons_momentum_fUniqueID);
   fChain->SetBranchAddress("muons_muons.momentum.fBits", muons_muons_momentum_fBits, &b_muons_muons_momentum_fBits);
   fChain->SetBranchAddress("muons_muons.momentum.fP.fUniqueID", muons_muons_momentum_fP_fUniqueID, &b_muons_muons_momentum_fP_fUniqueID);
   fChain->SetBranchAddress("muons_muons.momentum.fP.fBits", muons_muons_momentum_fP_fBits, &b_muons_muons_momentum_fP_fBits);
   fChain->SetBranchAddress("muons_muons.momentum.fP.fX", muons_muons_momentum_fP_fX, &b_muons_muons_momentum_fP_fX);
   fChain->SetBranchAddress("muons_muons.momentum.fP.fY", muons_muons_momentum_fP_fY, &b_muons_muons_momentum_fP_fY);
   fChain->SetBranchAddress("muons_muons.momentum.fP.fZ", muons_muons_momentum_fP_fZ, &b_muons_muons_momentum_fP_fZ);
   fChain->SetBranchAddress("muons_muons.momentum.fE", muons_muons_momentum_fE, &b_muons_muons_momentum_fE);
   fChain->SetBranchAddress("muons_muonsFromCosmics", &muons_muonsFromCosmics_, &b_muons_muonsFromCosmics_);
   fChain->SetBranchAddress("muons_muonsFromCosmics.type", muons_muonsFromCosmics_type, &b_muons_muonsFromCosmics_type);
   fChain->SetBranchAddress("muons_muonsFromCosmics.bestTrackType", muons_muonsFromCosmics_bestTrackType, &b_muons_muonsFromCosmics_bestTrackType);
   fChain->SetBranchAddress("muons_muonsFromCosmics.highPtBestTrackType", muons_muonsFromCosmics_highPtBestTrackType, &b_muons_muonsFromCosmics_highPtBestTrackType);
   fChain->SetBranchAddress("muons_muonsFromCosmics.qualityFlags", muons_muonsFromCosmics_qualityFlags, &b_muons_muonsFromCosmics_qualityFlags);
   fChain->SetBranchAddress("muons_muonsFromCosmics.nChambers", muons_muonsFromCosmics_nChambers, &b_muons_muonsFromCosmics_nChambers);
   fChain->SetBranchAddress("muons_muonsFromCosmics.nMatches", muons_muonsFromCosmics_nMatches, &b_muons_muonsFromCosmics_nMatches);
   fChain->SetBranchAddress("muons_muonsFromCosmics.stationMask", muons_muonsFromCosmics_stationMask, &b_muons_muonsFromCosmics_stationMask);
   fChain->SetBranchAddress("muons_muonsFromCosmics.nMatchedStations", muons_muonsFromCosmics_nMatchedStations, &b_muons_muonsFromCosmics_nMatchedStations);
   fChain->SetBranchAddress("muons_muonsFromCosmics.nValidHits", muons_muonsFromCosmics_nValidHits, &b_muons_muonsFromCosmics_nValidHits);
   fChain->SetBranchAddress("muons_muonsFromCosmics.nValidTrackerHits", muons_muonsFromCosmics_nValidTrackerHits, &b_muons_muonsFromCosmics_nValidTrackerHits);
   fChain->SetBranchAddress("muons_muonsFromCosmics.nValidMuonHits", muons_muonsFromCosmics_nValidMuonHits, &b_muons_muonsFromCosmics_nValidMuonHits);
   fChain->SetBranchAddress("muons_muonsFromCosmics.nPixelLayersWithMeasurement", muons_muonsFromCosmics_nPixelLayersWithMeasurement, &b_muons_muonsFromCosmics_nPixelLayersWithMeasurement);
   fChain->SetBranchAddress("muons_muonsFromCosmics.nStripLayersWithMeasurement", muons_muonsFromCosmics_nStripLayersWithMeasurement, &b_muons_muonsFromCosmics_nStripLayersWithMeasurement);
   fChain->SetBranchAddress("muons_muonsFromCosmics.timeNDof", muons_muonsFromCosmics_timeNDof, &b_muons_muonsFromCosmics_timeNDof);
   fChain->SetBranchAddress("muons_muonsFromCosmics.timeDirection", muons_muonsFromCosmics_timeDirection, &b_muons_muonsFromCosmics_timeDirection);
   fChain->SetBranchAddress("muons_muonsFromCosmics.timeAtIp", muons_muonsFromCosmics_timeAtIp, &b_muons_muonsFromCosmics_timeAtIp);
   fChain->SetBranchAddress("muons_muonsFromCosmics.timeAtIpError", muons_muonsFromCosmics_timeAtIpError, &b_muons_muonsFromCosmics_timeAtIpError);
   fChain->SetBranchAddress("muons_muonsFromCosmics.caloCompatibility", muons_muonsFromCosmics_caloCompatibility, &b_muons_muonsFromCosmics_caloCompatibility);
   fChain->SetBranchAddress("muons_muonsFromCosmics.segmentCompatibility", muons_muonsFromCosmics_segmentCompatibility, &b_muons_muonsFromCosmics_segmentCompatibility);
   fChain->SetBranchAddress("muons_muonsFromCosmics.emEnergy", muons_muonsFromCosmics_emEnergy, &b_muons_muonsFromCosmics_emEnergy);
   fChain->SetBranchAddress("muons_muonsFromCosmics.hadEnergy", muons_muonsFromCosmics_hadEnergy, &b_muons_muonsFromCosmics_hadEnergy);
   fChain->SetBranchAddress("muons_muonsFromCosmics.trackIsoR03", muons_muonsFromCosmics_trackIsoR03, &b_muons_muonsFromCosmics_trackIsoR03);
   fChain->SetBranchAddress("muons_muonsFromCosmics.ecalIsoR03", muons_muonsFromCosmics_ecalIsoR03, &b_muons_muonsFromCosmics_ecalIsoR03);
   fChain->SetBranchAddress("muons_muonsFromCosmics.hcalIsoR03", muons_muonsFromCosmics_hcalIsoR03, &b_muons_muonsFromCosmics_hcalIsoR03);
   fChain->SetBranchAddress("muons_muonsFromCosmics.trackIsoR05", muons_muonsFromCosmics_trackIsoR05, &b_muons_muonsFromCosmics_trackIsoR05);
   fChain->SetBranchAddress("muons_muonsFromCosmics.ecalIsoR05", muons_muonsFromCosmics_ecalIsoR05, &b_muons_muonsFromCosmics_ecalIsoR05);
   fChain->SetBranchAddress("muons_muonsFromCosmics.hcalIsoR05", muons_muonsFromCosmics_hcalIsoR05, &b_muons_muonsFromCosmics_hcalIsoR05);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumChargedHadronPt03", muons_muonsFromCosmics_sumChargedHadronPt03, &b_muons_muonsFromCosmics_sumChargedHadronPt03);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumChargedParticlePt03", muons_muonsFromCosmics_sumChargedParticlePt03, &b_muons_muonsFromCosmics_sumChargedParticlePt03);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumNeutralHadronEt03", muons_muonsFromCosmics_sumNeutralHadronEt03, &b_muons_muonsFromCosmics_sumNeutralHadronEt03);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumPhotonEt03", muons_muonsFromCosmics_sumPhotonEt03, &b_muons_muonsFromCosmics_sumPhotonEt03);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumNeutralHadronEtHighThreshold03", muons_muonsFromCosmics_sumNeutralHadronEtHighThreshold03, &b_muons_muonsFromCosmics_sumNeutralHadronEtHighThreshold03);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumPhotonEtHighThreshold03", muons_muonsFromCosmics_sumPhotonEtHighThreshold03, &b_muons_muonsFromCosmics_sumPhotonEtHighThreshold03);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumPUPt03", muons_muonsFromCosmics_sumPUPt03, &b_muons_muonsFromCosmics_sumPUPt03);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumChargedHadronPt04", muons_muonsFromCosmics_sumChargedHadronPt04, &b_muons_muonsFromCosmics_sumChargedHadronPt04);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumChargedParticlePt04", muons_muonsFromCosmics_sumChargedParticlePt04, &b_muons_muonsFromCosmics_sumChargedParticlePt04);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumNeutralHadronEt04", muons_muonsFromCosmics_sumNeutralHadronEt04, &b_muons_muonsFromCosmics_sumNeutralHadronEt04);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumPhotonEt04", muons_muonsFromCosmics_sumPhotonEt04, &b_muons_muonsFromCosmics_sumPhotonEt04);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumNeutralHadronEtHighThreshold04", muons_muonsFromCosmics_sumNeutralHadronEtHighThreshold04, &b_muons_muonsFromCosmics_sumNeutralHadronEtHighThreshold04);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumPhotonEtHighThreshold04", muons_muonsFromCosmics_sumPhotonEtHighThreshold04, &b_muons_muonsFromCosmics_sumPhotonEtHighThreshold04);
   fChain->SetBranchAddress("muons_muonsFromCosmics.sumPUPt04", muons_muonsFromCosmics_sumPUPt04, &b_muons_muonsFromCosmics_sumPUPt04);
   fChain->SetBranchAddress("muons_muonsFromCosmics.trackIndex", muons_muonsFromCosmics_trackIndex, &b_muons_muonsFromCosmics_trackIndex);
   fChain->SetBranchAddress("muons_muonsFromCosmics.standAloneTrackIndex", muons_muonsFromCosmics_standAloneTrackIndex, &b_muons_muonsFromCosmics_standAloneTrackIndex);
   fChain->SetBranchAddress("muons_muonsFromCosmics.combinedTrackIndex", muons_muonsFromCosmics_combinedTrackIndex, &b_muons_muonsFromCosmics_combinedTrackIndex);
   fChain->SetBranchAddress("muons_muonsFromCosmics.tpfmsTrackIndex", muons_muonsFromCosmics_tpfmsTrackIndex, &b_muons_muonsFromCosmics_tpfmsTrackIndex);
   fChain->SetBranchAddress("muons_muonsFromCosmics.pickyTrackIndex", muons_muonsFromCosmics_pickyTrackIndex, &b_muons_muonsFromCosmics_pickyTrackIndex);
   fChain->SetBranchAddress("muons_muonsFromCosmics.dytTrackIndex", muons_muonsFromCosmics_dytTrackIndex, &b_muons_muonsFromCosmics_dytTrackIndex);
   fChain->SetBranchAddress("muons_muonsFromCosmics.momentum.fUniqueID", muons_muonsFromCosmics_momentum_fUniqueID, &b_muons_muonsFromCosmics_momentum_fUniqueID);
   fChain->SetBranchAddress("muons_muonsFromCosmics.momentum.fBits", muons_muonsFromCosmics_momentum_fBits, &b_muons_muonsFromCosmics_momentum_fBits);
   fChain->SetBranchAddress("muons_muonsFromCosmics.momentum.fP.fUniqueID", muons_muonsFromCosmics_momentum_fP_fUniqueID, &b_muons_muonsFromCosmics_momentum_fP_fUniqueID);
   fChain->SetBranchAddress("muons_muonsFromCosmics.momentum.fP.fBits", muons_muonsFromCosmics_momentum_fP_fBits, &b_muons_muonsFromCosmics_momentum_fP_fBits);
   fChain->SetBranchAddress("muons_muonsFromCosmics.momentum.fP.fX", muons_muonsFromCosmics_momentum_fP_fX, &b_muons_muonsFromCosmics_momentum_fP_fX);
   fChain->SetBranchAddress("muons_muonsFromCosmics.momentum.fP.fY", muons_muonsFromCosmics_momentum_fP_fY, &b_muons_muonsFromCosmics_momentum_fP_fY);
   fChain->SetBranchAddress("muons_muonsFromCosmics.momentum.fP.fZ", muons_muonsFromCosmics_momentum_fP_fZ, &b_muons_muonsFromCosmics_momentum_fP_fZ);
   fChain->SetBranchAddress("muons_muonsFromCosmics.momentum.fE", muons_muonsFromCosmics_momentum_fE, &b_muons_muonsFromCosmics_momentum_fE);
   fChain->SetBranchAddress("electrons_gsfElectrons", &electrons_gsfElectrons_, &b_electrons_gsfElectrons_);
   fChain->SetBranchAddress("electrons_gsfElectrons.fidBit", electrons_gsfElectrons_fidBit, &b_electrons_gsfElectrons_fidBit);
   fChain->SetBranchAddress("electrons_gsfElectrons.scPixCharge", electrons_gsfElectrons_scPixCharge, &b_electrons_gsfElectrons_scPixCharge);
   fChain->SetBranchAddress("electrons_gsfElectrons.boolPack", electrons_gsfElectrons_boolPack, &b_electrons_gsfElectrons_boolPack);
   fChain->SetBranchAddress("electrons_gsfElectrons.convFlag", electrons_gsfElectrons_convFlag, &b_electrons_gsfElectrons_convFlag);
   fChain->SetBranchAddress("electrons_gsfElectrons.eSuperClusterOverP", electrons_gsfElectrons_eSuperClusterOverP, &b_electrons_gsfElectrons_eSuperClusterOverP);
   fChain->SetBranchAddress("electrons_gsfElectrons.eSeedClusterOverP", electrons_gsfElectrons_eSeedClusterOverP, &b_electrons_gsfElectrons_eSeedClusterOverP);
   fChain->SetBranchAddress("electrons_gsfElectrons.eSeedClusterOverPout", electrons_gsfElectrons_eSeedClusterOverPout, &b_electrons_gsfElectrons_eSeedClusterOverPout);
   fChain->SetBranchAddress("electrons_gsfElectrons.eEleClusterOverPout", electrons_gsfElectrons_eEleClusterOverPout, &b_electrons_gsfElectrons_eEleClusterOverPout);
   fChain->SetBranchAddress("electrons_gsfElectrons.deltaEtaSuperClusterTrackAtVtx", electrons_gsfElectrons_deltaEtaSuperClusterTrackAtVtx, &b_electrons_gsfElectrons_deltaEtaSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("electrons_gsfElectrons.deltaEtaSeedClusterTrackAtCalo", electrons_gsfElectrons_deltaEtaSeedClusterTrackAtCalo, &b_electrons_gsfElectrons_deltaEtaSeedClusterTrackAtCalo);
   fChain->SetBranchAddress("electrons_gsfElectrons.deltaEtaEleClusterTrackAtCalo", electrons_gsfElectrons_deltaEtaEleClusterTrackAtCalo, &b_electrons_gsfElectrons_deltaEtaEleClusterTrackAtCalo);
   fChain->SetBranchAddress("electrons_gsfElectrons.deltaPhiSuperClusterTrackAtVtx", electrons_gsfElectrons_deltaPhiSuperClusterTrackAtVtx, &b_electrons_gsfElectrons_deltaPhiSuperClusterTrackAtVtx);
   fChain->SetBranchAddress("electrons_gsfElectrons.deltaPhiSeedClusterTrackAtCalo", electrons_gsfElectrons_deltaPhiSeedClusterTrackAtCalo, &b_electrons_gsfElectrons_deltaPhiSeedClusterTrackAtCalo);
   fChain->SetBranchAddress("electrons_gsfElectrons.deltaPhiEleClusterTrackAtCalo", electrons_gsfElectrons_deltaPhiEleClusterTrackAtCalo, &b_electrons_gsfElectrons_deltaPhiEleClusterTrackAtCalo);
   fChain->SetBranchAddress("electrons_gsfElectrons.shFracInnerHits", electrons_gsfElectrons_shFracInnerHits, &b_electrons_gsfElectrons_shFracInnerHits);
   fChain->SetBranchAddress("electrons_gsfElectrons.sigmaEtaEta", electrons_gsfElectrons_sigmaEtaEta, &b_electrons_gsfElectrons_sigmaEtaEta);
   fChain->SetBranchAddress("electrons_gsfElectrons.sigmaIetaIeta", electrons_gsfElectrons_sigmaIetaIeta, &b_electrons_gsfElectrons_sigmaIetaIeta);
   fChain->SetBranchAddress("electrons_gsfElectrons.sigmaIphiIphi", electrons_gsfElectrons_sigmaIphiIphi, &b_electrons_gsfElectrons_sigmaIphiIphi);
   fChain->SetBranchAddress("electrons_gsfElectrons.e1x5", electrons_gsfElectrons_e1x5, &b_electrons_gsfElectrons_e1x5);
   fChain->SetBranchAddress("electrons_gsfElectrons.e2x5Max", electrons_gsfElectrons_e2x5Max, &b_electrons_gsfElectrons_e2x5Max);
   fChain->SetBranchAddress("electrons_gsfElectrons.e5x5", electrons_gsfElectrons_e5x5, &b_electrons_gsfElectrons_e5x5);
   fChain->SetBranchAddress("electrons_gsfElectrons.r9", electrons_gsfElectrons_r9, &b_electrons_gsfElectrons_r9);
   fChain->SetBranchAddress("electrons_gsfElectrons.hcalDepth1OverEcal", electrons_gsfElectrons_hcalDepth1OverEcal, &b_electrons_gsfElectrons_hcalDepth1OverEcal);
   fChain->SetBranchAddress("electrons_gsfElectrons.hcalDepth2OverEcal", electrons_gsfElectrons_hcalDepth2OverEcal, &b_electrons_gsfElectrons_hcalDepth2OverEcal);
   fChain->SetBranchAddress("electrons_gsfElectrons.hcalOverEcalBc", electrons_gsfElectrons_hcalOverEcalBc, &b_electrons_gsfElectrons_hcalOverEcalBc);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr03TkSumPt", electrons_gsfElectrons_dr03TkSumPt, &b_electrons_gsfElectrons_dr03TkSumPt);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr03EcalRecHitSumEt", electrons_gsfElectrons_dr03EcalRecHitSumEt, &b_electrons_gsfElectrons_dr03EcalRecHitSumEt);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr03HcalDepth1TowerSumEt", electrons_gsfElectrons_dr03HcalDepth1TowerSumEt, &b_electrons_gsfElectrons_dr03HcalDepth1TowerSumEt);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr03HcalDepth2TowerSumEt", electrons_gsfElectrons_dr03HcalDepth2TowerSumEt, &b_electrons_gsfElectrons_dr03HcalDepth2TowerSumEt);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr03HcalDepth1TowerSumEtBc", electrons_gsfElectrons_dr03HcalDepth1TowerSumEtBc, &b_electrons_gsfElectrons_dr03HcalDepth1TowerSumEtBc);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr03HcalDepth2TowerSumEtBc", electrons_gsfElectrons_dr03HcalDepth2TowerSumEtBc, &b_electrons_gsfElectrons_dr03HcalDepth2TowerSumEtBc);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr04TkSumPt", electrons_gsfElectrons_dr04TkSumPt, &b_electrons_gsfElectrons_dr04TkSumPt);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr04EcalRecHitSumEt", electrons_gsfElectrons_dr04EcalRecHitSumEt, &b_electrons_gsfElectrons_dr04EcalRecHitSumEt);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr04HcalDepth1TowerSumEt", electrons_gsfElectrons_dr04HcalDepth1TowerSumEt, &b_electrons_gsfElectrons_dr04HcalDepth1TowerSumEt);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr04HcalDepth2TowerSumEt", electrons_gsfElectrons_dr04HcalDepth2TowerSumEt, &b_electrons_gsfElectrons_dr04HcalDepth2TowerSumEt);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr04HcalDepth1TowerSumEtBc", electrons_gsfElectrons_dr04HcalDepth1TowerSumEtBc, &b_electrons_gsfElectrons_dr04HcalDepth1TowerSumEtBc);
   fChain->SetBranchAddress("electrons_gsfElectrons.dr04HcalDepth2TowerSumEtBc", electrons_gsfElectrons_dr04HcalDepth2TowerSumEtBc, &b_electrons_gsfElectrons_dr04HcalDepth2TowerSumEtBc);
   fChain->SetBranchAddress("electrons_gsfElectrons.convDist", electrons_gsfElectrons_convDist, &b_electrons_gsfElectrons_convDist);
   fChain->SetBranchAddress("electrons_gsfElectrons.convDcot", electrons_gsfElectrons_convDcot, &b_electrons_gsfElectrons_convDcot);
   fChain->SetBranchAddress("electrons_gsfElectrons.convRadius", electrons_gsfElectrons_convRadius, &b_electrons_gsfElectrons_convRadius);
   fChain->SetBranchAddress("electrons_gsfElectrons.chargedHadronIso", electrons_gsfElectrons_chargedHadronIso, &b_electrons_gsfElectrons_chargedHadronIso);
   fChain->SetBranchAddress("electrons_gsfElectrons.neutralHadronIso", electrons_gsfElectrons_neutralHadronIso, &b_electrons_gsfElectrons_neutralHadronIso);
   fChain->SetBranchAddress("electrons_gsfElectrons.photonIso", electrons_gsfElectrons_photonIso, &b_electrons_gsfElectrons_photonIso);
   fChain->SetBranchAddress("electrons_gsfElectrons.mvaStatus", electrons_gsfElectrons_mvaStatus, &b_electrons_gsfElectrons_mvaStatus);
   fChain->SetBranchAddress("electrons_gsfElectrons.mva", electrons_gsfElectrons_mva, &b_electrons_gsfElectrons_mva);
   fChain->SetBranchAddress("electrons_gsfElectrons.mvaTrig", electrons_gsfElectrons_mvaTrig, &b_electrons_gsfElectrons_mvaTrig);
   fChain->SetBranchAddress("electrons_gsfElectrons.mvaNonTrig", electrons_gsfElectrons_mvaNonTrig, &b_electrons_gsfElectrons_mvaNonTrig);
   fChain->SetBranchAddress("electrons_gsfElectrons.bremClass", electrons_gsfElectrons_bremClass, &b_electrons_gsfElectrons_bremClass);
   fChain->SetBranchAddress("electrons_gsfElectrons.fbrem", electrons_gsfElectrons_fbrem, &b_electrons_gsfElectrons_fbrem);
   fChain->SetBranchAddress("electrons_gsfElectrons.ecalEnergy", electrons_gsfElectrons_ecalEnergy, &b_electrons_gsfElectrons_ecalEnergy);
   fChain->SetBranchAddress("electrons_gsfElectrons.ecalEnergyError", electrons_gsfElectrons_ecalEnergyError, &b_electrons_gsfElectrons_ecalEnergyError);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumError", electrons_gsfElectrons_trackMomentumError, &b_electrons_gsfElectrons_trackMomentumError);
   fChain->SetBranchAddress("electrons_gsfElectrons.gsfTrackIndex", electrons_gsfElectrons_gsfTrackIndex, &b_electrons_gsfElectrons_gsfTrackIndex);
   fChain->SetBranchAddress("electrons_gsfElectrons.closestCtfTrackIndex", electrons_gsfElectrons_closestCtfTrackIndex, &b_electrons_gsfElectrons_closestCtfTrackIndex);
   fChain->SetBranchAddress("electrons_gsfElectrons.electronClusterIndex", electrons_gsfElectrons_electronClusterIndex, &b_electrons_gsfElectrons_electronClusterIndex);
   fChain->SetBranchAddress("electrons_gsfElectrons.superClusterIndex", electrons_gsfElectrons_superClusterIndex, &b_electrons_gsfElectrons_superClusterIndex);
   fChain->SetBranchAddress("electrons_gsfElectrons.nMissingHits", electrons_gsfElectrons_nMissingHits, &b_electrons_gsfElectrons_nMissingHits);
   fChain->SetBranchAddress("electrons_gsfElectrons.passConversionVeto", electrons_gsfElectrons_passConversionVeto, &b_electrons_gsfElectrons_passConversionVeto);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackPositionAtVtx.fUniqueID", electrons_gsfElectrons_trackPositionAtVtx_fUniqueID, &b_electrons_gsfElectrons_trackPositionAtVtx_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackPositionAtVtx.fBits", electrons_gsfElectrons_trackPositionAtVtx_fBits, &b_electrons_gsfElectrons_trackPositionAtVtx_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackPositionAtVtx.fX", electrons_gsfElectrons_trackPositionAtVtx_fX, &b_electrons_gsfElectrons_trackPositionAtVtx_fX);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackPositionAtVtx.fY", electrons_gsfElectrons_trackPositionAtVtx_fY, &b_electrons_gsfElectrons_trackPositionAtVtx_fY);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackPositionAtVtx.fZ", electrons_gsfElectrons_trackPositionAtVtx_fZ, &b_electrons_gsfElectrons_trackPositionAtVtx_fZ);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackPositionAtCalo.fUniqueID", electrons_gsfElectrons_trackPositionAtCalo_fUniqueID, &b_electrons_gsfElectrons_trackPositionAtCalo_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackPositionAtCalo.fBits", electrons_gsfElectrons_trackPositionAtCalo_fBits, &b_electrons_gsfElectrons_trackPositionAtCalo_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackPositionAtCalo.fX", electrons_gsfElectrons_trackPositionAtCalo_fX, &b_electrons_gsfElectrons_trackPositionAtCalo_fX);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackPositionAtCalo.fY", electrons_gsfElectrons_trackPositionAtCalo_fY, &b_electrons_gsfElectrons_trackPositionAtCalo_fY);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackPositionAtCalo.fZ", electrons_gsfElectrons_trackPositionAtCalo_fZ, &b_electrons_gsfElectrons_trackPositionAtCalo_fZ);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtx.fUniqueID", electrons_gsfElectrons_trackMomentumAtVtx_fUniqueID, &b_electrons_gsfElectrons_trackMomentumAtVtx_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtx.fBits", electrons_gsfElectrons_trackMomentumAtVtx_fBits, &b_electrons_gsfElectrons_trackMomentumAtVtx_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtx.fP.fUniqueID", electrons_gsfElectrons_trackMomentumAtVtx_fP_fUniqueID, &b_electrons_gsfElectrons_trackMomentumAtVtx_fP_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtx.fP.fBits", electrons_gsfElectrons_trackMomentumAtVtx_fP_fBits, &b_electrons_gsfElectrons_trackMomentumAtVtx_fP_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtx.fP.fX", electrons_gsfElectrons_trackMomentumAtVtx_fP_fX, &b_electrons_gsfElectrons_trackMomentumAtVtx_fP_fX);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtx.fP.fY", electrons_gsfElectrons_trackMomentumAtVtx_fP_fY, &b_electrons_gsfElectrons_trackMomentumAtVtx_fP_fY);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtx.fP.fZ", electrons_gsfElectrons_trackMomentumAtVtx_fP_fZ, &b_electrons_gsfElectrons_trackMomentumAtVtx_fP_fZ);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtx.fE", electrons_gsfElectrons_trackMomentumAtVtx_fE, &b_electrons_gsfElectrons_trackMomentumAtVtx_fE);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtCalo.fUniqueID", electrons_gsfElectrons_trackMomentumAtCalo_fUniqueID, &b_electrons_gsfElectrons_trackMomentumAtCalo_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtCalo.fBits", electrons_gsfElectrons_trackMomentumAtCalo_fBits, &b_electrons_gsfElectrons_trackMomentumAtCalo_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtCalo.fP.fUniqueID", electrons_gsfElectrons_trackMomentumAtCalo_fP_fUniqueID, &b_electrons_gsfElectrons_trackMomentumAtCalo_fP_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtCalo.fP.fBits", electrons_gsfElectrons_trackMomentumAtCalo_fP_fBits, &b_electrons_gsfElectrons_trackMomentumAtCalo_fP_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtCalo.fP.fX", electrons_gsfElectrons_trackMomentumAtCalo_fP_fX, &b_electrons_gsfElectrons_trackMomentumAtCalo_fP_fX);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtCalo.fP.fY", electrons_gsfElectrons_trackMomentumAtCalo_fP_fY, &b_electrons_gsfElectrons_trackMomentumAtCalo_fP_fY);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtCalo.fP.fZ", electrons_gsfElectrons_trackMomentumAtCalo_fP_fZ, &b_electrons_gsfElectrons_trackMomentumAtCalo_fP_fZ);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtCalo.fE", electrons_gsfElectrons_trackMomentumAtCalo_fE, &b_electrons_gsfElectrons_trackMomentumAtCalo_fE);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumOut.fUniqueID", electrons_gsfElectrons_trackMomentumOut_fUniqueID, &b_electrons_gsfElectrons_trackMomentumOut_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumOut.fBits", electrons_gsfElectrons_trackMomentumOut_fBits, &b_electrons_gsfElectrons_trackMomentumOut_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumOut.fP.fUniqueID", electrons_gsfElectrons_trackMomentumOut_fP_fUniqueID, &b_electrons_gsfElectrons_trackMomentumOut_fP_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumOut.fP.fBits", electrons_gsfElectrons_trackMomentumOut_fP_fBits, &b_electrons_gsfElectrons_trackMomentumOut_fP_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumOut.fP.fX", electrons_gsfElectrons_trackMomentumOut_fP_fX, &b_electrons_gsfElectrons_trackMomentumOut_fP_fX);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumOut.fP.fY", electrons_gsfElectrons_trackMomentumOut_fP_fY, &b_electrons_gsfElectrons_trackMomentumOut_fP_fY);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumOut.fP.fZ", electrons_gsfElectrons_trackMomentumOut_fP_fZ, &b_electrons_gsfElectrons_trackMomentumOut_fP_fZ);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumOut.fE", electrons_gsfElectrons_trackMomentumOut_fE, &b_electrons_gsfElectrons_trackMomentumOut_fE);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtEleClus.fUniqueID", electrons_gsfElectrons_trackMomentumAtEleClus_fUniqueID, &b_electrons_gsfElectrons_trackMomentumAtEleClus_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtEleClus.fBits", electrons_gsfElectrons_trackMomentumAtEleClus_fBits, &b_electrons_gsfElectrons_trackMomentumAtEleClus_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtEleClus.fP.fUniqueID", electrons_gsfElectrons_trackMomentumAtEleClus_fP_fUniqueID, &b_electrons_gsfElectrons_trackMomentumAtEleClus_fP_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtEleClus.fP.fBits", electrons_gsfElectrons_trackMomentumAtEleClus_fP_fBits, &b_electrons_gsfElectrons_trackMomentumAtEleClus_fP_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtEleClus.fP.fX", electrons_gsfElectrons_trackMomentumAtEleClus_fP_fX, &b_electrons_gsfElectrons_trackMomentumAtEleClus_fP_fX);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtEleClus.fP.fY", electrons_gsfElectrons_trackMomentumAtEleClus_fP_fY, &b_electrons_gsfElectrons_trackMomentumAtEleClus_fP_fY);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtEleClus.fP.fZ", electrons_gsfElectrons_trackMomentumAtEleClus_fP_fZ, &b_electrons_gsfElectrons_trackMomentumAtEleClus_fP_fZ);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtEleClus.fE", electrons_gsfElectrons_trackMomentumAtEleClus_fE, &b_electrons_gsfElectrons_trackMomentumAtEleClus_fE);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtxWithConstraint.fUniqueID", electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fUniqueID, &b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtxWithConstraint.fBits", electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fBits, &b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtxWithConstraint.fP.fUniqueID", electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fUniqueID, &b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtxWithConstraint.fP.fBits", electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fBits, &b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtxWithConstraint.fP.fX", electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fX, &b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fX);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtxWithConstraint.fP.fY", electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fY, &b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fY);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtxWithConstraint.fP.fZ", electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fZ, &b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fP_fZ);
   fChain->SetBranchAddress("electrons_gsfElectrons.trackMomentumAtVtxWithConstraint.fE", electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fE, &b_electrons_gsfElectrons_trackMomentumAtVtxWithConstraint_fE);
   fChain->SetBranchAddress("electrons_gsfElectrons.vertex.fUniqueID", electrons_gsfElectrons_vertex_fUniqueID, &b_electrons_gsfElectrons_vertex_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.vertex.fBits", electrons_gsfElectrons_vertex_fBits, &b_electrons_gsfElectrons_vertex_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.vertex.fX", electrons_gsfElectrons_vertex_fX, &b_electrons_gsfElectrons_vertex_fX);
   fChain->SetBranchAddress("electrons_gsfElectrons.vertex.fY", electrons_gsfElectrons_vertex_fY, &b_electrons_gsfElectrons_vertex_fY);
   fChain->SetBranchAddress("electrons_gsfElectrons.vertex.fZ", electrons_gsfElectrons_vertex_fZ, &b_electrons_gsfElectrons_vertex_fZ);
   fChain->SetBranchAddress("electrons_gsfElectrons.momentum.fUniqueID", electrons_gsfElectrons_momentum_fUniqueID, &b_electrons_gsfElectrons_momentum_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.momentum.fBits", electrons_gsfElectrons_momentum_fBits, &b_electrons_gsfElectrons_momentum_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.momentum.fP.fUniqueID", electrons_gsfElectrons_momentum_fP_fUniqueID, &b_electrons_gsfElectrons_momentum_fP_fUniqueID);
   fChain->SetBranchAddress("electrons_gsfElectrons.momentum.fP.fBits", electrons_gsfElectrons_momentum_fP_fBits, &b_electrons_gsfElectrons_momentum_fP_fBits);
   fChain->SetBranchAddress("electrons_gsfElectrons.momentum.fP.fX", electrons_gsfElectrons_momentum_fP_fX, &b_electrons_gsfElectrons_momentum_fP_fX);
   fChain->SetBranchAddress("electrons_gsfElectrons.momentum.fP.fY", electrons_gsfElectrons_momentum_fP_fY, &b_electrons_gsfElectrons_momentum_fP_fY);
   fChain->SetBranchAddress("electrons_gsfElectrons.momentum.fP.fZ", electrons_gsfElectrons_momentum_fP_fZ, &b_electrons_gsfElectrons_momentum_fP_fZ);
   fChain->SetBranchAddress("electrons_gsfElectrons.momentum.fE", electrons_gsfElectrons_momentum_fE, &b_electrons_gsfElectrons_momentum_fE);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot", &photons_pfPhotonTranslator_pfphot_, &b_photons_pfPhotonTranslator_pfphot_);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.fidBit", photons_pfPhotonTranslator_pfphot_fidBit, &b_photons_pfPhotonTranslator_pfphot_fidBit);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.nPixelSeeds", photons_pfPhotonTranslator_pfphot_nPixelSeeds, &b_photons_pfPhotonTranslator_pfphot_nPixelSeeds);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.passelectronveto", photons_pfPhotonTranslator_pfphot_passelectronveto, &b_photons_pfPhotonTranslator_pfphot_passelectronveto);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.hadronicOverEm", photons_pfPhotonTranslator_pfphot_hadronicOverEm, &b_photons_pfPhotonTranslator_pfphot_hadronicOverEm);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.hadTowOverEm", photons_pfPhotonTranslator_pfphot_hadTowOverEm, &b_photons_pfPhotonTranslator_pfphot_hadTowOverEm);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.hadronicDepth1OverEm", photons_pfPhotonTranslator_pfphot_hadronicDepth1OverEm, &b_photons_pfPhotonTranslator_pfphot_hadronicDepth1OverEm);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.hadronicDepth2OverEm", photons_pfPhotonTranslator_pfphot_hadronicDepth2OverEm, &b_photons_pfPhotonTranslator_pfphot_hadronicDepth2OverEm);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.e1x2", photons_pfPhotonTranslator_pfphot_e1x2, &b_photons_pfPhotonTranslator_pfphot_e1x2);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.e1x5", photons_pfPhotonTranslator_pfphot_e1x5, &b_photons_pfPhotonTranslator_pfphot_e1x5);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.e2x5", photons_pfPhotonTranslator_pfphot_e2x5, &b_photons_pfPhotonTranslator_pfphot_e2x5);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.e3x3", photons_pfPhotonTranslator_pfphot_e3x3, &b_photons_pfPhotonTranslator_pfphot_e3x3);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.e5x5", photons_pfPhotonTranslator_pfphot_e5x5, &b_photons_pfPhotonTranslator_pfphot_e5x5);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.maxEnergyXtal", photons_pfPhotonTranslator_pfphot_maxEnergyXtal, &b_photons_pfPhotonTranslator_pfphot_maxEnergyXtal);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.sigmaEtaEta", photons_pfPhotonTranslator_pfphot_sigmaEtaEta, &b_photons_pfPhotonTranslator_pfphot_sigmaEtaEta);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.sigmaIetaIeta", photons_pfPhotonTranslator_pfphot_sigmaIetaIeta, &b_photons_pfPhotonTranslator_pfphot_sigmaIetaIeta);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.sigmaIphiIphi", photons_pfPhotonTranslator_pfphot_sigmaIphiIphi, &b_photons_pfPhotonTranslator_pfphot_sigmaIphiIphi);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.r9", photons_pfPhotonTranslator_pfphot_r9, &b_photons_pfPhotonTranslator_pfphot_r9);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.ecalRecHitSumEtConeDR04", photons_pfPhotonTranslator_pfphot_ecalRecHitSumEtConeDR04, &b_photons_pfPhotonTranslator_pfphot_ecalRecHitSumEtConeDR04);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.hcalDepth1TowerSumEtConeDR04", photons_pfPhotonTranslator_pfphot_hcalDepth1TowerSumEtConeDR04, &b_photons_pfPhotonTranslator_pfphot_hcalDepth1TowerSumEtConeDR04);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.hcalDepth2TowerSumEtConeDR04", photons_pfPhotonTranslator_pfphot_hcalDepth2TowerSumEtConeDR04, &b_photons_pfPhotonTranslator_pfphot_hcalDepth2TowerSumEtConeDR04);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.hcalIsoConeDR04_2012", photons_pfPhotonTranslator_pfphot_hcalIsoConeDR04_2012, &b_photons_pfPhotonTranslator_pfphot_hcalIsoConeDR04_2012);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.trkSumPtSolidConeDR04", photons_pfPhotonTranslator_pfphot_trkSumPtSolidConeDR04, &b_photons_pfPhotonTranslator_pfphot_trkSumPtSolidConeDR04);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.trkSumPtHollowConeDR04", photons_pfPhotonTranslator_pfphot_trkSumPtHollowConeDR04, &b_photons_pfPhotonTranslator_pfphot_trkSumPtHollowConeDR04);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.nTrkSolidConeDR04", photons_pfPhotonTranslator_pfphot_nTrkSolidConeDR04, &b_photons_pfPhotonTranslator_pfphot_nTrkSolidConeDR04);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.nTrkHollowConeDR04", photons_pfPhotonTranslator_pfphot_nTrkHollowConeDR04, &b_photons_pfPhotonTranslator_pfphot_nTrkHollowConeDR04);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.ecalRecHitSumEtConeDR03", photons_pfPhotonTranslator_pfphot_ecalRecHitSumEtConeDR03, &b_photons_pfPhotonTranslator_pfphot_ecalRecHitSumEtConeDR03);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.hcalDepth1TowerSumEtConeDR03", photons_pfPhotonTranslator_pfphot_hcalDepth1TowerSumEtConeDR03, &b_photons_pfPhotonTranslator_pfphot_hcalDepth1TowerSumEtConeDR03);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.hcalDepth2TowerSumEtConeDR03", photons_pfPhotonTranslator_pfphot_hcalDepth2TowerSumEtConeDR03, &b_photons_pfPhotonTranslator_pfphot_hcalDepth2TowerSumEtConeDR03);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.hcalIsoConeDR03_2012", photons_pfPhotonTranslator_pfphot_hcalIsoConeDR03_2012, &b_photons_pfPhotonTranslator_pfphot_hcalIsoConeDR03_2012);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.trkSumPtSolidConeDR03", photons_pfPhotonTranslator_pfphot_trkSumPtSolidConeDR03, &b_photons_pfPhotonTranslator_pfphot_trkSumPtSolidConeDR03);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.trkSumPtHollowConeDR03", photons_pfPhotonTranslator_pfphot_trkSumPtHollowConeDR03, &b_photons_pfPhotonTranslator_pfphot_trkSumPtHollowConeDR03);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.nTrkSolidConeDR03", photons_pfPhotonTranslator_pfphot_nTrkSolidConeDR03, &b_photons_pfPhotonTranslator_pfphot_nTrkSolidConeDR03);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.nTrkHollowConeDR03", photons_pfPhotonTranslator_pfphot_nTrkHollowConeDR03, &b_photons_pfPhotonTranslator_pfphot_nTrkHollowConeDR03);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.chargedHadronIso", photons_pfPhotonTranslator_pfphot_chargedHadronIso, &b_photons_pfPhotonTranslator_pfphot_chargedHadronIso);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.neutralHadronIso", photons_pfPhotonTranslator_pfphot_neutralHadronIso, &b_photons_pfPhotonTranslator_pfphot_neutralHadronIso);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.photonIso", photons_pfPhotonTranslator_pfphot_photonIso, &b_photons_pfPhotonTranslator_pfphot_photonIso);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.worstOtherVtxChargedHadronIso", photons_pfPhotonTranslator_pfphot_worstOtherVtxChargedHadronIso, &b_photons_pfPhotonTranslator_pfphot_worstOtherVtxChargedHadronIso);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.worstOtherVtxChargedHadronIsoVtxIdx", photons_pfPhotonTranslator_pfphot_worstOtherVtxChargedHadronIsoVtxIdx, &b_photons_pfPhotonTranslator_pfphot_worstOtherVtxChargedHadronIsoVtxIdx);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.chargedHadronIsoDeposit", photons_pfPhotonTranslator_pfphot_chargedHadronIsoDeposit, &b_photons_pfPhotonTranslator_pfphot_chargedHadronIsoDeposit);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.neutralHadronIsoDeposit", photons_pfPhotonTranslator_pfphot_neutralHadronIsoDeposit, &b_photons_pfPhotonTranslator_pfphot_neutralHadronIsoDeposit);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.photonIsoDeposit", photons_pfPhotonTranslator_pfphot_photonIsoDeposit, &b_photons_pfPhotonTranslator_pfphot_photonIsoDeposit);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.seedTime", photons_pfPhotonTranslator_pfphot_seedTime, &b_photons_pfPhotonTranslator_pfphot_seedTime);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.mipChi2", photons_pfPhotonTranslator_pfphot_mipChi2, &b_photons_pfPhotonTranslator_pfphot_mipChi2);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.mipTotEnergy", photons_pfPhotonTranslator_pfphot_mipTotEnergy, &b_photons_pfPhotonTranslator_pfphot_mipTotEnergy);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.mipSlope", photons_pfPhotonTranslator_pfphot_mipSlope, &b_photons_pfPhotonTranslator_pfphot_mipSlope);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.mipIntercept", photons_pfPhotonTranslator_pfphot_mipIntercept, &b_photons_pfPhotonTranslator_pfphot_mipIntercept);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.mipNhitCone", photons_pfPhotonTranslator_pfphot_mipNhitCone, &b_photons_pfPhotonTranslator_pfphot_mipNhitCone);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.mipIsHalo", photons_pfPhotonTranslator_pfphot_mipIsHalo, &b_photons_pfPhotonTranslator_pfphot_mipIsHalo);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convInfo", photons_pfPhotonTranslator_pfphot_convInfo, &b_photons_pfPhotonTranslator_pfphot_convInfo);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convDist", photons_pfPhotonTranslator_pfphot_convDist, &b_photons_pfPhotonTranslator_pfphot_convDist);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convDcot", photons_pfPhotonTranslator_pfphot_convDcot, &b_photons_pfPhotonTranslator_pfphot_convDcot);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convVtxChi2", photons_pfPhotonTranslator_pfphot_convVtxChi2, &b_photons_pfPhotonTranslator_pfphot_convVtxChi2);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convVtxNdof", photons_pfPhotonTranslator_pfphot_convVtxNdof, &b_photons_pfPhotonTranslator_pfphot_convVtxNdof);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convVertex.fUniqueID", photons_pfPhotonTranslator_pfphot_convVertex_fUniqueID, &b_photons_pfPhotonTranslator_pfphot_convVertex_fUniqueID);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convVertex.fBits", photons_pfPhotonTranslator_pfphot_convVertex_fBits, &b_photons_pfPhotonTranslator_pfphot_convVertex_fBits);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convVertex.fX", photons_pfPhotonTranslator_pfphot_convVertex_fX, &b_photons_pfPhotonTranslator_pfphot_convVertex_fX);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convVertex.fY", photons_pfPhotonTranslator_pfphot_convVertex_fY, &b_photons_pfPhotonTranslator_pfphot_convVertex_fY);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convVertex.fZ", photons_pfPhotonTranslator_pfphot_convVertex_fZ, &b_photons_pfPhotonTranslator_pfphot_convVertex_fZ);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convDxy", photons_pfPhotonTranslator_pfphot_convDxy, &b_photons_pfPhotonTranslator_pfphot_convDxy);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convDz", photons_pfPhotonTranslator_pfphot_convDz, &b_photons_pfPhotonTranslator_pfphot_convDz);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convLxy", photons_pfPhotonTranslator_pfphot_convLxy, &b_photons_pfPhotonTranslator_pfphot_convLxy);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convLz", photons_pfPhotonTranslator_pfphot_convLz, &b_photons_pfPhotonTranslator_pfphot_convLz);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convZofPVFromTracks", photons_pfPhotonTranslator_pfphot_convZofPVFromTracks, &b_photons_pfPhotonTranslator_pfphot_convZofPVFromTracks);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrackChargeProd", photons_pfPhotonTranslator_pfphot_convTrackChargeProd, &b_photons_pfPhotonTranslator_pfphot_convTrackChargeProd);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack1nHit", photons_pfPhotonTranslator_pfphot_convTrack1nHit, &b_photons_pfPhotonTranslator_pfphot_convTrack1nHit);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack2nHit", photons_pfPhotonTranslator_pfphot_convTrack2nHit, &b_photons_pfPhotonTranslator_pfphot_convTrack2nHit);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack1chi2", photons_pfPhotonTranslator_pfphot_convTrack1chi2, &b_photons_pfPhotonTranslator_pfphot_convTrack1chi2);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack2chi2", photons_pfPhotonTranslator_pfphot_convTrack2chi2, &b_photons_pfPhotonTranslator_pfphot_convTrack2chi2);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack1pT", photons_pfPhotonTranslator_pfphot_convTrack1pT, &b_photons_pfPhotonTranslator_pfphot_convTrack1pT);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack2pT", photons_pfPhotonTranslator_pfphot_convTrack2pT, &b_photons_pfPhotonTranslator_pfphot_convTrack2pT);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack1InnerZ", photons_pfPhotonTranslator_pfphot_convTrack1InnerZ, &b_photons_pfPhotonTranslator_pfphot_convTrack1InnerZ);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack2InnerZ", photons_pfPhotonTranslator_pfphot_convTrack2InnerZ, &b_photons_pfPhotonTranslator_pfphot_convTrack2InnerZ);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack1InnerX", photons_pfPhotonTranslator_pfphot_convTrack1InnerX, &b_photons_pfPhotonTranslator_pfphot_convTrack1InnerX);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack2InnerX", photons_pfPhotonTranslator_pfphot_convTrack2InnerX, &b_photons_pfPhotonTranslator_pfphot_convTrack2InnerX);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack1InnerY", photons_pfPhotonTranslator_pfphot_convTrack1InnerY, &b_photons_pfPhotonTranslator_pfphot_convTrack1InnerY);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack2InnerY", photons_pfPhotonTranslator_pfphot_convTrack2InnerY, &b_photons_pfPhotonTranslator_pfphot_convTrack2InnerY);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack1Signedd0", photons_pfPhotonTranslator_pfphot_convTrack1Signedd0, &b_photons_pfPhotonTranslator_pfphot_convTrack1Signedd0);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.convTrack2Signedd0", photons_pfPhotonTranslator_pfphot_convTrack2Signedd0, &b_photons_pfPhotonTranslator_pfphot_convTrack2Signedd0);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.superClusterIndex", photons_pfPhotonTranslator_pfphot_superClusterIndex, &b_photons_pfPhotonTranslator_pfphot_superClusterIndex);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.superClusterPreshowerEnergy", photons_pfPhotonTranslator_pfphot_superClusterPreshowerEnergy, &b_photons_pfPhotonTranslator_pfphot_superClusterPreshowerEnergy);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.superClusterPhiWidth", photons_pfPhotonTranslator_pfphot_superClusterPhiWidth, &b_photons_pfPhotonTranslator_pfphot_superClusterPhiWidth);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.superClusterEtaWidth", photons_pfPhotonTranslator_pfphot_superClusterEtaWidth, &b_photons_pfPhotonTranslator_pfphot_superClusterEtaWidth);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.caloPosition.fUniqueID", photons_pfPhotonTranslator_pfphot_caloPosition_fUniqueID, &b_photons_pfPhotonTranslator_pfphot_caloPosition_fUniqueID);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.caloPosition.fBits", photons_pfPhotonTranslator_pfphot_caloPosition_fBits, &b_photons_pfPhotonTranslator_pfphot_caloPosition_fBits);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.caloPosition.fX", photons_pfPhotonTranslator_pfphot_caloPosition_fX, &b_photons_pfPhotonTranslator_pfphot_caloPosition_fX);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.caloPosition.fY", photons_pfPhotonTranslator_pfphot_caloPosition_fY, &b_photons_pfPhotonTranslator_pfphot_caloPosition_fY);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.caloPosition.fZ", photons_pfPhotonTranslator_pfphot_caloPosition_fZ, &b_photons_pfPhotonTranslator_pfphot_caloPosition_fZ);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.MVAregEnergy", photons_pfPhotonTranslator_pfphot_MVAregEnergy, &b_photons_pfPhotonTranslator_pfphot_MVAregEnergy);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.MVAregErr", photons_pfPhotonTranslator_pfphot_MVAregErr, &b_photons_pfPhotonTranslator_pfphot_MVAregErr);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.momentum.fUniqueID", photons_pfPhotonTranslator_pfphot_momentum_fUniqueID, &b_photons_pfPhotonTranslator_pfphot_momentum_fUniqueID);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.momentum.fBits", photons_pfPhotonTranslator_pfphot_momentum_fBits, &b_photons_pfPhotonTranslator_pfphot_momentum_fBits);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.momentum.fP.fUniqueID", photons_pfPhotonTranslator_pfphot_momentum_fP_fUniqueID, &b_photons_pfPhotonTranslator_pfphot_momentum_fP_fUniqueID);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.momentum.fP.fBits", photons_pfPhotonTranslator_pfphot_momentum_fP_fBits, &b_photons_pfPhotonTranslator_pfphot_momentum_fP_fBits);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.momentum.fP.fX", photons_pfPhotonTranslator_pfphot_momentum_fP_fX, &b_photons_pfPhotonTranslator_pfphot_momentum_fP_fX);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.momentum.fP.fY", photons_pfPhotonTranslator_pfphot_momentum_fP_fY, &b_photons_pfPhotonTranslator_pfphot_momentum_fP_fY);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.momentum.fP.fZ", photons_pfPhotonTranslator_pfphot_momentum_fP_fZ, &b_photons_pfPhotonTranslator_pfphot_momentum_fP_fZ);
   fChain->SetBranchAddress("photons_pfPhotonTranslator_pfphot.momentum.fE", photons_pfPhotonTranslator_pfphot_momentum_fE, &b_photons_pfPhotonTranslator_pfphot_momentum_fE);
   fChain->SetBranchAddress("photons_photons", &photons_photons_, &b_photons_photons_);
   fChain->SetBranchAddress("photons_photons.fidBit", photons_photons_fidBit, &b_photons_photons_fidBit);
   fChain->SetBranchAddress("photons_photons.nPixelSeeds", photons_photons_nPixelSeeds, &b_photons_photons_nPixelSeeds);
   fChain->SetBranchAddress("photons_photons.passelectronveto", photons_photons_passelectronveto, &b_photons_photons_passelectronveto);
   fChain->SetBranchAddress("photons_photons.hadronicOverEm", photons_photons_hadronicOverEm, &b_photons_photons_hadronicOverEm);
   fChain->SetBranchAddress("photons_photons.hadTowOverEm", photons_photons_hadTowOverEm, &b_photons_photons_hadTowOverEm);
   fChain->SetBranchAddress("photons_photons.hadronicDepth1OverEm", photons_photons_hadronicDepth1OverEm, &b_photons_photons_hadronicDepth1OverEm);
   fChain->SetBranchAddress("photons_photons.hadronicDepth2OverEm", photons_photons_hadronicDepth2OverEm, &b_photons_photons_hadronicDepth2OverEm);
   fChain->SetBranchAddress("photons_photons.e1x2", photons_photons_e1x2, &b_photons_photons_e1x2);
   fChain->SetBranchAddress("photons_photons.e1x5", photons_photons_e1x5, &b_photons_photons_e1x5);
   fChain->SetBranchAddress("photons_photons.e2x5", photons_photons_e2x5, &b_photons_photons_e2x5);
   fChain->SetBranchAddress("photons_photons.e3x3", photons_photons_e3x3, &b_photons_photons_e3x3);
   fChain->SetBranchAddress("photons_photons.e5x5", photons_photons_e5x5, &b_photons_photons_e5x5);
   fChain->SetBranchAddress("photons_photons.maxEnergyXtal", photons_photons_maxEnergyXtal, &b_photons_photons_maxEnergyXtal);
   fChain->SetBranchAddress("photons_photons.sigmaEtaEta", photons_photons_sigmaEtaEta, &b_photons_photons_sigmaEtaEta);
   fChain->SetBranchAddress("photons_photons.sigmaIetaIeta", photons_photons_sigmaIetaIeta, &b_photons_photons_sigmaIetaIeta);
   fChain->SetBranchAddress("photons_photons.sigmaIphiIphi", photons_photons_sigmaIphiIphi, &b_photons_photons_sigmaIphiIphi);
   fChain->SetBranchAddress("photons_photons.r9", photons_photons_r9, &b_photons_photons_r9);
   fChain->SetBranchAddress("photons_photons.ecalRecHitSumEtConeDR04", photons_photons_ecalRecHitSumEtConeDR04, &b_photons_photons_ecalRecHitSumEtConeDR04);
   fChain->SetBranchAddress("photons_photons.hcalDepth1TowerSumEtConeDR04", photons_photons_hcalDepth1TowerSumEtConeDR04, &b_photons_photons_hcalDepth1TowerSumEtConeDR04);
   fChain->SetBranchAddress("photons_photons.hcalDepth2TowerSumEtConeDR04", photons_photons_hcalDepth2TowerSumEtConeDR04, &b_photons_photons_hcalDepth2TowerSumEtConeDR04);
   fChain->SetBranchAddress("photons_photons.hcalIsoConeDR04_2012", photons_photons_hcalIsoConeDR04_2012, &b_photons_photons_hcalIsoConeDR04_2012);
   fChain->SetBranchAddress("photons_photons.trkSumPtSolidConeDR04", photons_photons_trkSumPtSolidConeDR04, &b_photons_photons_trkSumPtSolidConeDR04);
   fChain->SetBranchAddress("photons_photons.trkSumPtHollowConeDR04", photons_photons_trkSumPtHollowConeDR04, &b_photons_photons_trkSumPtHollowConeDR04);
   fChain->SetBranchAddress("photons_photons.nTrkSolidConeDR04", photons_photons_nTrkSolidConeDR04, &b_photons_photons_nTrkSolidConeDR04);
   fChain->SetBranchAddress("photons_photons.nTrkHollowConeDR04", photons_photons_nTrkHollowConeDR04, &b_photons_photons_nTrkHollowConeDR04);
   fChain->SetBranchAddress("photons_photons.ecalRecHitSumEtConeDR03", photons_photons_ecalRecHitSumEtConeDR03, &b_photons_photons_ecalRecHitSumEtConeDR03);
   fChain->SetBranchAddress("photons_photons.hcalDepth1TowerSumEtConeDR03", photons_photons_hcalDepth1TowerSumEtConeDR03, &b_photons_photons_hcalDepth1TowerSumEtConeDR03);
   fChain->SetBranchAddress("photons_photons.hcalDepth2TowerSumEtConeDR03", photons_photons_hcalDepth2TowerSumEtConeDR03, &b_photons_photons_hcalDepth2TowerSumEtConeDR03);
   fChain->SetBranchAddress("photons_photons.hcalIsoConeDR03_2012", photons_photons_hcalIsoConeDR03_2012, &b_photons_photons_hcalIsoConeDR03_2012);
   fChain->SetBranchAddress("photons_photons.trkSumPtSolidConeDR03", photons_photons_trkSumPtSolidConeDR03, &b_photons_photons_trkSumPtSolidConeDR03);
   fChain->SetBranchAddress("photons_photons.trkSumPtHollowConeDR03", photons_photons_trkSumPtHollowConeDR03, &b_photons_photons_trkSumPtHollowConeDR03);
   fChain->SetBranchAddress("photons_photons.nTrkSolidConeDR03", photons_photons_nTrkSolidConeDR03, &b_photons_photons_nTrkSolidConeDR03);
   fChain->SetBranchAddress("photons_photons.nTrkHollowConeDR03", photons_photons_nTrkHollowConeDR03, &b_photons_photons_nTrkHollowConeDR03);
   fChain->SetBranchAddress("photons_photons.chargedHadronIso", photons_photons_chargedHadronIso, &b_photons_photons_chargedHadronIso);
   fChain->SetBranchAddress("photons_photons.neutralHadronIso", photons_photons_neutralHadronIso, &b_photons_photons_neutralHadronIso);
   fChain->SetBranchAddress("photons_photons.photonIso", photons_photons_photonIso, &b_photons_photons_photonIso);
   fChain->SetBranchAddress("photons_photons.worstOtherVtxChargedHadronIso", photons_photons_worstOtherVtxChargedHadronIso, &b_photons_photons_worstOtherVtxChargedHadronIso);
   fChain->SetBranchAddress("photons_photons.worstOtherVtxChargedHadronIsoVtxIdx", photons_photons_worstOtherVtxChargedHadronIsoVtxIdx, &b_photons_photons_worstOtherVtxChargedHadronIsoVtxIdx);
   fChain->SetBranchAddress("photons_photons.chargedHadronIsoDeposit", photons_photons_chargedHadronIsoDeposit, &b_photons_photons_chargedHadronIsoDeposit);
   fChain->SetBranchAddress("photons_photons.neutralHadronIsoDeposit", photons_photons_neutralHadronIsoDeposit, &b_photons_photons_neutralHadronIsoDeposit);
   fChain->SetBranchAddress("photons_photons.photonIsoDeposit", photons_photons_photonIsoDeposit, &b_photons_photons_photonIsoDeposit);
   fChain->SetBranchAddress("photons_photons.seedTime", photons_photons_seedTime, &b_photons_photons_seedTime);
   fChain->SetBranchAddress("photons_photons.mipChi2", photons_photons_mipChi2, &b_photons_photons_mipChi2);
   fChain->SetBranchAddress("photons_photons.mipTotEnergy", photons_photons_mipTotEnergy, &b_photons_photons_mipTotEnergy);
   fChain->SetBranchAddress("photons_photons.mipSlope", photons_photons_mipSlope, &b_photons_photons_mipSlope);
   fChain->SetBranchAddress("photons_photons.mipIntercept", photons_photons_mipIntercept, &b_photons_photons_mipIntercept);
   fChain->SetBranchAddress("photons_photons.mipNhitCone", photons_photons_mipNhitCone, &b_photons_photons_mipNhitCone);
   fChain->SetBranchAddress("photons_photons.mipIsHalo", photons_photons_mipIsHalo, &b_photons_photons_mipIsHalo);
   fChain->SetBranchAddress("photons_photons.convInfo", photons_photons_convInfo, &b_photons_photons_convInfo);
   fChain->SetBranchAddress("photons_photons.convDist", photons_photons_convDist, &b_photons_photons_convDist);
   fChain->SetBranchAddress("photons_photons.convDcot", photons_photons_convDcot, &b_photons_photons_convDcot);
   fChain->SetBranchAddress("photons_photons.convVtxChi2", photons_photons_convVtxChi2, &b_photons_photons_convVtxChi2);
   fChain->SetBranchAddress("photons_photons.convVtxNdof", photons_photons_convVtxNdof, &b_photons_photons_convVtxNdof);
   fChain->SetBranchAddress("photons_photons.convVertex.fUniqueID", photons_photons_convVertex_fUniqueID, &b_photons_photons_convVertex_fUniqueID);
   fChain->SetBranchAddress("photons_photons.convVertex.fBits", photons_photons_convVertex_fBits, &b_photons_photons_convVertex_fBits);
   fChain->SetBranchAddress("photons_photons.convVertex.fX", photons_photons_convVertex_fX, &b_photons_photons_convVertex_fX);
   fChain->SetBranchAddress("photons_photons.convVertex.fY", photons_photons_convVertex_fY, &b_photons_photons_convVertex_fY);
   fChain->SetBranchAddress("photons_photons.convVertex.fZ", photons_photons_convVertex_fZ, &b_photons_photons_convVertex_fZ);
   fChain->SetBranchAddress("photons_photons.convDxy", photons_photons_convDxy, &b_photons_photons_convDxy);
   fChain->SetBranchAddress("photons_photons.convDz", photons_photons_convDz, &b_photons_photons_convDz);
   fChain->SetBranchAddress("photons_photons.convLxy", photons_photons_convLxy, &b_photons_photons_convLxy);
   fChain->SetBranchAddress("photons_photons.convLz", photons_photons_convLz, &b_photons_photons_convLz);
   fChain->SetBranchAddress("photons_photons.convZofPVFromTracks", photons_photons_convZofPVFromTracks, &b_photons_photons_convZofPVFromTracks);
   fChain->SetBranchAddress("photons_photons.convTrackChargeProd", photons_photons_convTrackChargeProd, &b_photons_photons_convTrackChargeProd);
   fChain->SetBranchAddress("photons_photons.convTrack1nHit", photons_photons_convTrack1nHit, &b_photons_photons_convTrack1nHit);
   fChain->SetBranchAddress("photons_photons.convTrack2nHit", photons_photons_convTrack2nHit, &b_photons_photons_convTrack2nHit);
   fChain->SetBranchAddress("photons_photons.convTrack1chi2", photons_photons_convTrack1chi2, &b_photons_photons_convTrack1chi2);
   fChain->SetBranchAddress("photons_photons.convTrack2chi2", photons_photons_convTrack2chi2, &b_photons_photons_convTrack2chi2);
   fChain->SetBranchAddress("photons_photons.convTrack1pT", photons_photons_convTrack1pT, &b_photons_photons_convTrack1pT);
   fChain->SetBranchAddress("photons_photons.convTrack2pT", photons_photons_convTrack2pT, &b_photons_photons_convTrack2pT);
   fChain->SetBranchAddress("photons_photons.convTrack1InnerZ", photons_photons_convTrack1InnerZ, &b_photons_photons_convTrack1InnerZ);
   fChain->SetBranchAddress("photons_photons.convTrack2InnerZ", photons_photons_convTrack2InnerZ, &b_photons_photons_convTrack2InnerZ);
   fChain->SetBranchAddress("photons_photons.convTrack1InnerX", photons_photons_convTrack1InnerX, &b_photons_photons_convTrack1InnerX);
   fChain->SetBranchAddress("photons_photons.convTrack2InnerX", photons_photons_convTrack2InnerX, &b_photons_photons_convTrack2InnerX);
   fChain->SetBranchAddress("photons_photons.convTrack1InnerY", photons_photons_convTrack1InnerY, &b_photons_photons_convTrack1InnerY);
   fChain->SetBranchAddress("photons_photons.convTrack2InnerY", photons_photons_convTrack2InnerY, &b_photons_photons_convTrack2InnerY);
   fChain->SetBranchAddress("photons_photons.convTrack1Signedd0", photons_photons_convTrack1Signedd0, &b_photons_photons_convTrack1Signedd0);
   fChain->SetBranchAddress("photons_photons.convTrack2Signedd0", photons_photons_convTrack2Signedd0, &b_photons_photons_convTrack2Signedd0);
   fChain->SetBranchAddress("photons_photons.superClusterIndex", photons_photons_superClusterIndex, &b_photons_photons_superClusterIndex);
   fChain->SetBranchAddress("photons_photons.superClusterPreshowerEnergy", photons_photons_superClusterPreshowerEnergy, &b_photons_photons_superClusterPreshowerEnergy);
   fChain->SetBranchAddress("photons_photons.superClusterPhiWidth", photons_photons_superClusterPhiWidth, &b_photons_photons_superClusterPhiWidth);
   fChain->SetBranchAddress("photons_photons.superClusterEtaWidth", photons_photons_superClusterEtaWidth, &b_photons_photons_superClusterEtaWidth);
   fChain->SetBranchAddress("photons_photons.caloPosition.fUniqueID", photons_photons_caloPosition_fUniqueID, &b_photons_photons_caloPosition_fUniqueID);
   fChain->SetBranchAddress("photons_photons.caloPosition.fBits", photons_photons_caloPosition_fBits, &b_photons_photons_caloPosition_fBits);
   fChain->SetBranchAddress("photons_photons.caloPosition.fX", photons_photons_caloPosition_fX, &b_photons_photons_caloPosition_fX);
   fChain->SetBranchAddress("photons_photons.caloPosition.fY", photons_photons_caloPosition_fY, &b_photons_photons_caloPosition_fY);
   fChain->SetBranchAddress("photons_photons.caloPosition.fZ", photons_photons_caloPosition_fZ, &b_photons_photons_caloPosition_fZ);
   fChain->SetBranchAddress("photons_photons.MVAregEnergy", photons_photons_MVAregEnergy, &b_photons_photons_MVAregEnergy);
   fChain->SetBranchAddress("photons_photons.MVAregErr", photons_photons_MVAregErr, &b_photons_photons_MVAregErr);
   fChain->SetBranchAddress("photons_photons.momentum.fUniqueID", photons_photons_momentum_fUniqueID, &b_photons_photons_momentum_fUniqueID);
   fChain->SetBranchAddress("photons_photons.momentum.fBits", photons_photons_momentum_fBits, &b_photons_photons_momentum_fBits);
   fChain->SetBranchAddress("photons_photons.momentum.fP.fUniqueID", photons_photons_momentum_fP_fUniqueID, &b_photons_photons_momentum_fP_fUniqueID);
   fChain->SetBranchAddress("photons_photons.momentum.fP.fBits", photons_photons_momentum_fP_fBits, &b_photons_photons_momentum_fP_fBits);
   fChain->SetBranchAddress("photons_photons.momentum.fP.fX", photons_photons_momentum_fP_fX, &b_photons_photons_momentum_fP_fX);
   fChain->SetBranchAddress("photons_photons.momentum.fP.fY", photons_photons_momentum_fP_fY, &b_photons_photons_momentum_fP_fY);
   fChain->SetBranchAddress("photons_photons.momentum.fP.fZ", photons_photons_momentum_fP_fZ, &b_photons_photons_momentum_fP_fZ);
   fChain->SetBranchAddress("photons_photons.momentum.fE", photons_photons_momentum_fE, &b_photons_photons_momentum_fE);
   fChain->SetBranchAddress("pfJets_ak5", &pfJets_ak5_, &b_pfJets_ak5_);
   fChain->SetBranchAddress("pfJets_ak5.phyDefFlavour", pfJets_ak5_phyDefFlavour, &b_pfJets_ak5_phyDefFlavour);
   fChain->SetBranchAddress("pfJets_ak5.algDefFlavour", pfJets_ak5_algDefFlavour, &b_pfJets_ak5_algDefFlavour);
   fChain->SetBranchAddress("pfJets_ak5.jetCharge", pfJets_ak5_jetCharge, &b_pfJets_ak5_jetCharge);
   fChain->SetBranchAddress("pfJets_ak5.etaMean", pfJets_ak5_etaMean, &b_pfJets_ak5_etaMean);
   fChain->SetBranchAddress("pfJets_ak5.phiMean", pfJets_ak5_phiMean, &b_pfJets_ak5_phiMean);
   fChain->SetBranchAddress("pfJets_ak5.etaEtaMoment", pfJets_ak5_etaEtaMoment, &b_pfJets_ak5_etaEtaMoment);
   fChain->SetBranchAddress("pfJets_ak5.etaPhiMoment", pfJets_ak5_etaPhiMoment, &b_pfJets_ak5_etaPhiMoment);
   fChain->SetBranchAddress("pfJets_ak5.phiPhiMoment", pfJets_ak5_phiPhiMoment, &b_pfJets_ak5_phiPhiMoment);
   fChain->SetBranchAddress("pfJets_ak5.maxDistance", pfJets_ak5_maxDistance, &b_pfJets_ak5_maxDistance);
   fChain->SetBranchAddress("pfJets_ak5.jetArea", pfJets_ak5_jetArea, &b_pfJets_ak5_jetArea);
   fChain->SetBranchAddress("pfJets_ak5.pileup", pfJets_ak5_pileup, &b_pfJets_ak5_pileup);
   fChain->SetBranchAddress("pfJets_ak5.nPasses", pfJets_ak5_nPasses, &b_pfJets_ak5_nPasses);
   fChain->SetBranchAddress("pfJets_ak5.nConstituents", pfJets_ak5_nConstituents, &b_pfJets_ak5_nConstituents);
   fChain->SetBranchAddress("pfJets_ak5.chargedHadronEnergy", pfJets_ak5_chargedHadronEnergy, &b_pfJets_ak5_chargedHadronEnergy);
   fChain->SetBranchAddress("pfJets_ak5.neutralHadronEnergy", pfJets_ak5_neutralHadronEnergy, &b_pfJets_ak5_neutralHadronEnergy);
   fChain->SetBranchAddress("pfJets_ak5.photonEnergy", pfJets_ak5_photonEnergy, &b_pfJets_ak5_photonEnergy);
   fChain->SetBranchAddress("pfJets_ak5.electronEnergy", pfJets_ak5_electronEnergy, &b_pfJets_ak5_electronEnergy);
   fChain->SetBranchAddress("pfJets_ak5.muonEnergy", pfJets_ak5_muonEnergy, &b_pfJets_ak5_muonEnergy);
   fChain->SetBranchAddress("pfJets_ak5.HFHadronEnergy", pfJets_ak5_HFHadronEnergy, &b_pfJets_ak5_HFHadronEnergy);
   fChain->SetBranchAddress("pfJets_ak5.HFEMEnergy", pfJets_ak5_HFEMEnergy, &b_pfJets_ak5_HFEMEnergy);
   fChain->SetBranchAddress("pfJets_ak5.chargedEmEnergy", pfJets_ak5_chargedEmEnergy, &b_pfJets_ak5_chargedEmEnergy);
   fChain->SetBranchAddress("pfJets_ak5.chargedMuEnergy", pfJets_ak5_chargedMuEnergy, &b_pfJets_ak5_chargedMuEnergy);
   fChain->SetBranchAddress("pfJets_ak5.neutralEmEnergy", pfJets_ak5_neutralEmEnergy, &b_pfJets_ak5_neutralEmEnergy);
   fChain->SetBranchAddress("pfJets_ak5.chargedHadronMultiplicity", pfJets_ak5_chargedHadronMultiplicity, &b_pfJets_ak5_chargedHadronMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5.neutralHadronMultiplicity", pfJets_ak5_neutralHadronMultiplicity, &b_pfJets_ak5_neutralHadronMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5.photonMultiplicity", pfJets_ak5_photonMultiplicity, &b_pfJets_ak5_photonMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5.electronMultiplicity", pfJets_ak5_electronMultiplicity, &b_pfJets_ak5_electronMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5.muonMultiplicity", pfJets_ak5_muonMultiplicity, &b_pfJets_ak5_muonMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5.HFHadronMultiplicity", pfJets_ak5_HFHadronMultiplicity, &b_pfJets_ak5_HFHadronMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5.HFEMMultiplicity", pfJets_ak5_HFEMMultiplicity, &b_pfJets_ak5_HFEMMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5.chargedMultiplicity", pfJets_ak5_chargedMultiplicity, &b_pfJets_ak5_chargedMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5.neutralMultiplicity", pfJets_ak5_neutralMultiplicity, &b_pfJets_ak5_neutralMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5.tracklist", pfJets_ak5_tracklist, &b_pfJets_ak5_tracklist);
   fChain->SetBranchAddress("pfJets_ak5.pfParticleList", pfJets_ak5_pfParticleList, &b_pfJets_ak5_pfParticleList);
   fChain->SetBranchAddress("pfJets_ak5.puJetIdDiscriminants[3]", pfJets_ak5_puJetIdDiscriminants, &b_pfJets_ak5_puJetIdDiscriminants);
   fChain->SetBranchAddress("pfJets_ak5.puJetIdFlags[3]", pfJets_ak5_puJetIdFlags, &b_pfJets_ak5_puJetIdFlags);
   fChain->SetBranchAddress("pfJets_ak5.bTagDiscriminators[9]", pfJets_ak5_bTagDiscriminators, &b_pfJets_ak5_bTagDiscriminators);
   fChain->SetBranchAddress("pfJets_ak5.qgDiscriminators[2]", pfJets_ak5_qgDiscriminators, &b_pfJets_ak5_qgDiscriminators);
   fChain->SetBranchAddress("pfJets_ak5.momentum.fUniqueID", pfJets_ak5_momentum_fUniqueID, &b_pfJets_ak5_momentum_fUniqueID);
   fChain->SetBranchAddress("pfJets_ak5.momentum.fBits", pfJets_ak5_momentum_fBits, &b_pfJets_ak5_momentum_fBits);
   fChain->SetBranchAddress("pfJets_ak5.momentum.fP.fUniqueID", pfJets_ak5_momentum_fP_fUniqueID, &b_pfJets_ak5_momentum_fP_fUniqueID);
   fChain->SetBranchAddress("pfJets_ak5.momentum.fP.fBits", pfJets_ak5_momentum_fP_fBits, &b_pfJets_ak5_momentum_fP_fBits);
   fChain->SetBranchAddress("pfJets_ak5.momentum.fP.fX", pfJets_ak5_momentum_fP_fX, &b_pfJets_ak5_momentum_fP_fX);
   fChain->SetBranchAddress("pfJets_ak5.momentum.fP.fY", pfJets_ak5_momentum_fP_fY, &b_pfJets_ak5_momentum_fP_fY);
   fChain->SetBranchAddress("pfJets_ak5.momentum.fP.fZ", pfJets_ak5_momentum_fP_fZ, &b_pfJets_ak5_momentum_fP_fZ);
   fChain->SetBranchAddress("pfJets_ak5.momentum.fE", pfJets_ak5_momentum_fE, &b_pfJets_ak5_momentum_fE);
   fChain->SetBranchAddress("pfJets_ak5.jecUncertainty", pfJets_ak5_jecUncertainty, &b_pfJets_ak5_jecUncertainty);
   fChain->SetBranchAddress("pfJets_ak5chs", &pfJets_ak5chs_, &b_pfJets_ak5chs_);
   fChain->SetBranchAddress("pfJets_ak5chs.phyDefFlavour", pfJets_ak5chs_phyDefFlavour, &b_pfJets_ak5chs_phyDefFlavour);
   fChain->SetBranchAddress("pfJets_ak5chs.algDefFlavour", pfJets_ak5chs_algDefFlavour, &b_pfJets_ak5chs_algDefFlavour);
   fChain->SetBranchAddress("pfJets_ak5chs.jetCharge", pfJets_ak5chs_jetCharge, &b_pfJets_ak5chs_jetCharge);
   fChain->SetBranchAddress("pfJets_ak5chs.etaMean", pfJets_ak5chs_etaMean, &b_pfJets_ak5chs_etaMean);
   fChain->SetBranchAddress("pfJets_ak5chs.phiMean", pfJets_ak5chs_phiMean, &b_pfJets_ak5chs_phiMean);
   fChain->SetBranchAddress("pfJets_ak5chs.etaEtaMoment", pfJets_ak5chs_etaEtaMoment, &b_pfJets_ak5chs_etaEtaMoment);
   fChain->SetBranchAddress("pfJets_ak5chs.etaPhiMoment", pfJets_ak5chs_etaPhiMoment, &b_pfJets_ak5chs_etaPhiMoment);
   fChain->SetBranchAddress("pfJets_ak5chs.phiPhiMoment", pfJets_ak5chs_phiPhiMoment, &b_pfJets_ak5chs_phiPhiMoment);
   fChain->SetBranchAddress("pfJets_ak5chs.maxDistance", pfJets_ak5chs_maxDistance, &b_pfJets_ak5chs_maxDistance);
   fChain->SetBranchAddress("pfJets_ak5chs.jetArea", pfJets_ak5chs_jetArea, &b_pfJets_ak5chs_jetArea);
   fChain->SetBranchAddress("pfJets_ak5chs.pileup", pfJets_ak5chs_pileup, &b_pfJets_ak5chs_pileup);
   fChain->SetBranchAddress("pfJets_ak5chs.nPasses", pfJets_ak5chs_nPasses, &b_pfJets_ak5chs_nPasses);
   fChain->SetBranchAddress("pfJets_ak5chs.nConstituents", pfJets_ak5chs_nConstituents, &b_pfJets_ak5chs_nConstituents);
   fChain->SetBranchAddress("pfJets_ak5chs.chargedHadronEnergy", pfJets_ak5chs_chargedHadronEnergy, &b_pfJets_ak5chs_chargedHadronEnergy);
   fChain->SetBranchAddress("pfJets_ak5chs.neutralHadronEnergy", pfJets_ak5chs_neutralHadronEnergy, &b_pfJets_ak5chs_neutralHadronEnergy);
   fChain->SetBranchAddress("pfJets_ak5chs.photonEnergy", pfJets_ak5chs_photonEnergy, &b_pfJets_ak5chs_photonEnergy);
   fChain->SetBranchAddress("pfJets_ak5chs.electronEnergy", pfJets_ak5chs_electronEnergy, &b_pfJets_ak5chs_electronEnergy);
   fChain->SetBranchAddress("pfJets_ak5chs.muonEnergy", pfJets_ak5chs_muonEnergy, &b_pfJets_ak5chs_muonEnergy);
   fChain->SetBranchAddress("pfJets_ak5chs.HFHadronEnergy", pfJets_ak5chs_HFHadronEnergy, &b_pfJets_ak5chs_HFHadronEnergy);
   fChain->SetBranchAddress("pfJets_ak5chs.HFEMEnergy", pfJets_ak5chs_HFEMEnergy, &b_pfJets_ak5chs_HFEMEnergy);
   fChain->SetBranchAddress("pfJets_ak5chs.chargedEmEnergy", pfJets_ak5chs_chargedEmEnergy, &b_pfJets_ak5chs_chargedEmEnergy);
   fChain->SetBranchAddress("pfJets_ak5chs.chargedMuEnergy", pfJets_ak5chs_chargedMuEnergy, &b_pfJets_ak5chs_chargedMuEnergy);
   fChain->SetBranchAddress("pfJets_ak5chs.neutralEmEnergy", pfJets_ak5chs_neutralEmEnergy, &b_pfJets_ak5chs_neutralEmEnergy);
   fChain->SetBranchAddress("pfJets_ak5chs.chargedHadronMultiplicity", pfJets_ak5chs_chargedHadronMultiplicity, &b_pfJets_ak5chs_chargedHadronMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5chs.neutralHadronMultiplicity", pfJets_ak5chs_neutralHadronMultiplicity, &b_pfJets_ak5chs_neutralHadronMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5chs.photonMultiplicity", pfJets_ak5chs_photonMultiplicity, &b_pfJets_ak5chs_photonMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5chs.electronMultiplicity", pfJets_ak5chs_electronMultiplicity, &b_pfJets_ak5chs_electronMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5chs.muonMultiplicity", pfJets_ak5chs_muonMultiplicity, &b_pfJets_ak5chs_muonMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5chs.HFHadronMultiplicity", pfJets_ak5chs_HFHadronMultiplicity, &b_pfJets_ak5chs_HFHadronMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5chs.HFEMMultiplicity", pfJets_ak5chs_HFEMMultiplicity, &b_pfJets_ak5chs_HFEMMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5chs.chargedMultiplicity", pfJets_ak5chs_chargedMultiplicity, &b_pfJets_ak5chs_chargedMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5chs.neutralMultiplicity", pfJets_ak5chs_neutralMultiplicity, &b_pfJets_ak5chs_neutralMultiplicity);
   fChain->SetBranchAddress("pfJets_ak5chs.tracklist", pfJets_ak5chs_tracklist, &b_pfJets_ak5chs_tracklist);
   fChain->SetBranchAddress("pfJets_ak5chs.pfParticleList", pfJets_ak5chs_pfParticleList, &b_pfJets_ak5chs_pfParticleList);
   fChain->SetBranchAddress("pfJets_ak5chs.puJetIdDiscriminants[3]", pfJets_ak5chs_puJetIdDiscriminants, &b_pfJets_ak5chs_puJetIdDiscriminants);
   fChain->SetBranchAddress("pfJets_ak5chs.puJetIdFlags[3]", pfJets_ak5chs_puJetIdFlags, &b_pfJets_ak5chs_puJetIdFlags);
   fChain->SetBranchAddress("pfJets_ak5chs.bTagDiscriminators[9]", pfJets_ak5chs_bTagDiscriminators, &b_pfJets_ak5chs_bTagDiscriminators);
   fChain->SetBranchAddress("pfJets_ak5chs.qgDiscriminators[2]", pfJets_ak5chs_qgDiscriminators, &b_pfJets_ak5chs_qgDiscriminators);
   fChain->SetBranchAddress("pfJets_ak5chs.momentum.fUniqueID", pfJets_ak5chs_momentum_fUniqueID, &b_pfJets_ak5chs_momentum_fUniqueID);
   fChain->SetBranchAddress("pfJets_ak5chs.momentum.fBits", pfJets_ak5chs_momentum_fBits, &b_pfJets_ak5chs_momentum_fBits);
   fChain->SetBranchAddress("pfJets_ak5chs.momentum.fP.fUniqueID", pfJets_ak5chs_momentum_fP_fUniqueID, &b_pfJets_ak5chs_momentum_fP_fUniqueID);
   fChain->SetBranchAddress("pfJets_ak5chs.momentum.fP.fBits", pfJets_ak5chs_momentum_fP_fBits, &b_pfJets_ak5chs_momentum_fP_fBits);
   fChain->SetBranchAddress("pfJets_ak5chs.momentum.fP.fX", pfJets_ak5chs_momentum_fP_fX, &b_pfJets_ak5chs_momentum_fP_fX);
   fChain->SetBranchAddress("pfJets_ak5chs.momentum.fP.fY", pfJets_ak5chs_momentum_fP_fY, &b_pfJets_ak5chs_momentum_fP_fY);
   fChain->SetBranchAddress("pfJets_ak5chs.momentum.fP.fZ", pfJets_ak5chs_momentum_fP_fZ, &b_pfJets_ak5chs_momentum_fP_fZ);
   fChain->SetBranchAddress("pfJets_ak5chs.momentum.fE", pfJets_ak5chs_momentum_fE, &b_pfJets_ak5chs_momentum_fE);
   fChain->SetBranchAddress("pfJets_ak5chs.jecUncertainty", pfJets_ak5chs_jecUncertainty, &b_pfJets_ak5chs_jecUncertainty);
}

Bool_t DataSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef DataSelector_cxx
