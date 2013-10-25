//own
#include "process.h"
#include "MySelector.h"

//system
#include <iostream>
#include <string>

//root includes
#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TH1F.h"
#include "TCanvas.h"



int main()//int argc, char** argv)
{
//  std::string QCD250 = "/.automount/home/home__home4/institut_1b/jschulz/Master/usercode/ProofAnalysisTest/QCD_250_500.root";
//  std::string WJets = "/.automount/home/home__home4/institut_1b/jschulz/Master/usercode/ProofAnalysisTest/Wjets_V01.00_15_tree.root";
 // std::string TTJets = "/.automount/home/home__home4/institut_1b/jschulz/Master/usercode/ProofAnalysisTest/TTJets.root";
//	std::string QCD500 = "/.automount/home/home__home4/institut_1b/jschulz/Master/usercode/ProofAnalysisTest/QCD_500-1000.root";
	
//	if( argc < 1 ) {
//		std::cout << "usage: ./process input1.root input2.root ..." << std::endl;
//		return 1;
//		}
		
	TChain * tchain = new TChain( "susyTree" );
 // tchain->Add( QCD250.c_str() );
 // tchain->Add( WJets.c_str() );
//	tchain->Add( TTJets.c_str() );
 // tchain->Add( QCD500.c_str() );
// for( unsigned int i=1; i<argc; ++i)
//		tchain->Add( argv[i] );
 
  tchain->Add("/user/jschulz/smaller_study_file.root");
  MySelector *evt = new MySelector;
  evt->Init( tchain );
  Long64_t nentries = evt->fChain->GetEntries();
  evt->Begin( tchain );
  evt->SlaveBegin( tchain );
	std::cout<<"----------------------------------"<<std::endl;
	std::cout<<"   Total number of Events: "<<nentries<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;
  for (Long64_t i = 0; i < nentries; i++){
     evt->fChain->GetEntry(i);
     evt->Process( i);
  }
  evt->SlaveTerminate();
  evt->Terminate();
 // delete evt;
//	delete tchain;
	
	MySelector *evt2 = new MySelector;
	TChain * tchain2 = new TChain( "susyTree" );
	tchain2->Add( "/user/jschulz/study_file.root" );
	evt2->Init( tchain2 );
  Long64_t nentries2 = evt2->fChain->GetEntries();
  evt2->Begin( tchain2 );
  evt2->SlaveBegin( tchain2 );
	std::cout<<"----------------------------------"<<std::endl;
	std::cout<<"   Total number of Events: "<<nentries2<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;
  for (Long64_t i = 0; i < nentries2; i++){
     evt2->fChain->GetEntry(i);
     evt2->Process( i);
  }
  evt2->SlaveTerminate();
  evt2->Terminate();
//  delete evt2;
//	delete tchain2;

  TH1F *h_data1_met = evt->histo["h_met"];
	TH1F *h_data2_met = evt2->histo["h_met"];
	
	TFile f("differ.root", "RECREATE");
	h_data1_met->Write();
  h_data2_met->Write();
	f.Close();
	evt2->histo.Write("study_file.root");
	
	return 0;
}
