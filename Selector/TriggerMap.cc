#include "TriggerMap.h"
#include <iostream>
#include "TTree.h"



TriggerMap::TriggerMap(TString const& _type) :
  trigType_(_type),
  core_(),
  prescales_(0),
  decisions_(0),
  menuInEvent_(new TString),
  currentMenu_(""),
  treeNumber_(-1),
  inputTree_(0),
  outputTrees_()
{
}

TriggerMap::~TriggerMap()
{
  releaseTrees(kTRUE);

  clear_();

  delete menuInEvent_;
}

void
TriggerMap::Print(std::ostream& os/* = std::cout*/) const
{
  os << "Trigger Table: " << currentMenu_ << std::endl;
  for(CoreConstIter itr(core_.begin()); itr != core_.end(); ++itr)
    os << itr->first << "(prescale=" << *(itr->second.first) << ", fire=" << int(*(itr->second.second)) << ")" << std::endl;
}

Bool_t
TriggerMap::pass(TString const& _path) const
{
  CoreConstIter itr(core_.lower_bound(_path));
  if(itr == core_.end()) return kFALSE;

  TString const& found(itr->first);

  if((_path.First('*') == _path.Length() - 1 && found.Index(_path.SubString(0, _path.Length() - 1)) == 0) || _path == found)
    return *itr->second.second != 0;
  else
    return kFALSE;
}

UInt_t
TriggerMap::prescale(TString const& _path) const
{
  CoreConstIter itr(core_.lower_bound(_path));
  if(itr == core_.end()) return kFALSE;

  TString const& found(itr->first);

  if((_path.First('*') == _path.Length() - 1 && found.Index(_path.SubString(0, _path.Length() - 1)) == 0) || _path == found)
    return *itr->second.first;
  else
    return 0;
}

std::pair<UInt_t, Bool_t>
TriggerMap::operator[](TString const& _path) const
{
  std::pair<UInt_t, Bool_t> value(0, kFALSE);

  CoreConstIter itr(core_.lower_bound(_path));
  if(itr == core_.end()) return value;

  TString const& found(itr->first);

  if((_path.First('*') == _path.Length() - 1 && found.Index(_path.SubString(0, _path.Length() - 1)) == 0) || _path == found){
    value.first = *itr->second.first;
    value.second = *itr->second.second != 0;
  }
  return value;
}

void
TriggerMap::setInput(TTree& _input)
{

//	std::cout << "setinput: " << &_input << std::endl;
//	std::cout << "*menuInEvent_= " << *menuInEvent_ << std::endl;
  if(inputTree_) releaseTree(*inputTree_, kTRUE);

  inputTree_ = &_input;
	
//	std::cout << "setinput_inputtree: " << inputTree_ << std::endl;

  inputTree_->SetBranchAddress(trigType_ + "Config", &menuInEvent_);

  currentMenu_ = "";
  treeNumber_ = -1;
}

void
TriggerMap::addOutput(TTree& _output)
{


//  std::cout << "setinput_inputtree_1: " << inputTree_ << std::endl;
  outputTrees_.push_back(&_output);

  TBranch* configBranch(_output.GetBranch(trigType_ + "Config"));
  if(configBranch){
    // output is a halfway-filled susyTree
    _output.SetBranchAddress(trigType_ + "Config", &menuInEvent_);
  }
  else{
    configBranch = _output.Branch(trigType_ + "Config", "TString", &menuInEvent_);
    configBranch->SetFirstEntry(_output.GetEntries());
  }

  if(currentMenu_ == "") return;

  // look for current trigger table
  TBranch* bitBranch(0);
  TBranch* psBranch(0);
  if(configBranch){
    bitBranch = _output.GetBranch(trigType_ + "Prescales_" + currentMenu_);
    psBranch = _output.GetBranch(trigType_ + "Bits_" + currentMenu_);
  }

  if(bitBranch && psBranch){
    _output.SetBranchAddress(trigType_ + "Bits_" + currentMenu_, decisions_);
    _output.SetBranchAddress(trigType_ + "Prescales_" + currentMenu_, prescales_);
  }
  else{
    TString bitLeaves(formLeafList_());
    TString psLeaves(bitLeaves);
    psLeaves.ReplaceAll("/b", "/i");

    bitBranch = _output.Branch(trigType_ + "Bits_" + currentMenu_, decisions_, bitLeaves);
    psBranch = _output.Branch(trigType_ + "Prescales_" + currentMenu_, prescales_, psLeaves);

    bitBranch->SetFirstEntry(_output.GetEntries());
    psBranch->SetFirstEntry(_output.GetEntries());
  }
//std::cout << "setinput_inputtree_2: " << inputTree_ << std::endl;
}

void
TriggerMap::checkInput(TTree& _input)
{
  // Check for menu or tree transition and set the branch addresses when necessary. Note that
  // when the input is a TChain, different constituent trees can have different trigger tables.
  // As such, SetBranchAddress is not issued on the inputTree itself (otherwise users will see
  // a lot of "SetBranchAddress: No branch XYZ found" messages) but only on the current tree.
  // The check for tree transition is required for this reason.
//	std::cout << "..:" << inputTree_ << std::endl;a
//	std::cout << "info: "<< trigType_ <<  menuInEvent_ << std::endl;

 /*   std::cout << "menu in event: "<<*menuInEvent_ 
						  << ", Treenumber: " << _input.GetTree()->GetTreeNumber()	
			  			<< ", treenumber in event: "<<inputTree_->GetTreeNumber()
	            << ", (curMenu: "<<currentMenu_ 
		  				<< ", curTreenumber: "<<treeNumber_ <<")"
							<< ", getReadEntry=" << inputTree_->GetReadEntry()
				  		<<std::endl; */
					
//	std::cout << " __" << _input.GetTreeNumber() << std::endl;
	
  if(!inputTree_) return;
	// *menuInEvent_ = "Run2012_8e33_v1p0_HLT_V2";	
  if(*menuInEvent_ == currentMenu_ && treeNumber_ == inputTree_->GetTreeNumber()) return;
	
 /*  std::cout << "menu in event: "<<*menuInEvent_ 
						  << ", Treenumber: " << _input.GetTree()->GetTreeNumber()	
			  			<< ", treenumber in event: "<<inputTree_->GetTreeNumber()
	            << ", (curMenu: "<<currentMenu_ 
		  				<< ", curTreenumber: "<<treeNumber_ <<")"
							<< ", getReadEntry=" << inputTree_->GetReadEntry()
				  		<<std::endl; */
											
  TBranch* bitBranch(inputTree_->GetBranch(trigType_ + "Bits_" + *menuInEvent_));
  TBranch* psBranch(inputTree_->GetBranch(trigType_ + "Prescales_" + *menuInEvent_));
	
//  std::cout << "hier: " << *menuInEvent_ << std::endl;
	
  if(!bitBranch || !psBranch){
    // Input tree is not properly formatted
    releaseTree(*inputTree_, kTRUE);
	//	std::cout << "hallo" << std::endl;
    return;
  }
	
 // std::cout << "dort: " << inputTree_ << std::endl;
  if(*menuInEvent_ != currentMenu_){
    // New trigger table
    TObjArray* leaves(bitBranch->GetListOfLeaves());

    std::vector<std::string> paths;
    for(int iL(0); iL != leaves->GetEntries(); ++iL){
      paths.push_back(leaves->At(iL)->GetName());
	//    std::cout << leaves->At(iL)->GetName() << " __  ";
	  	}
    setMenu(*menuInEvent_, paths); // currentMenu is set here
  }

  treeNumber_ = inputTree_->GetTreeNumber();

  bitBranch->SetAddress(decisions_);
  psBranch->SetAddress(prescales_);

  inputTree_->GetEntry(inputTree_->GetReadEntry());

}

void
TriggerMap::setMenu(TString const& _menuName, std::vector<std::string> const& _paths)
{
  // Configure the object for a new trigger table. Called either by the ntuplizer or internally
  // from checkInput() when the input configuration changes.

  if(_menuName == currentMenu_) return;

  releaseTrees(kFALSE);

  clear_();

  *menuInEvent_ = _menuName;
  currentMenu_ = _menuName;

  unsigned nP(_paths.size());

  prescales_ = new UInt_t[nP];
  decisions_ = new UChar_t[nP];

  // insert all paths to core first to make sure they are alphabetically ordered
  for(unsigned iP(0); iP != nP; ++iP)
    core_.insert(MapCore::value_type(_paths[iP], std::pair<UInt_t*, UChar_t*>(0, 0)));

  UInt_t* ps(prescales_);
  UChar_t* bit(decisions_);
  for(CoreIter itr(core_.begin()); itr != core_.end(); ++itr, ++ps, ++bit){
    itr->second.first = ps;
    itr->second.second = bit;
  }

  std::fill_n(prescales_, nP, 0);
  std::fill_n(decisions_, nP, 0);

  if(outputTrees_.size() == 0) return;

  // If outputs exist, new branches must be created on each of them.

  TString bitLeaves(formLeafList_());
  TString psLeaves(bitLeaves);
  psLeaves.ReplaceAll("/b", "/i");

  for(unsigned iT(0); iT != outputTrees_.size(); ++iT){
    TTree* tree(outputTrees_[iT]);

    TBranch* bitBranch(tree->GetBranch(trigType_ + "Bits_" + currentMenu_));
    TBranch* psBranch(tree->GetBranch(trigType_ + "Prescales_" + currentMenu_));

    if(bitBranch)
      tree->SetBranchAddress(trigType_ + "Bits_" + currentMenu_, decisions_);
    else{
      bitBranch = tree->Branch(trigType_ + "Bits_" + currentMenu_, decisions_, bitLeaves);
      bitBranch->SetFirstEntry(tree->GetEntries());
    }
    if(psBranch)
      tree->SetBranchAddress(trigType_ + "Prescales_" + currentMenu_, prescales_);
    else{
      psBranch = tree->Branch(trigType_ + "Prescales_" + currentMenu_, prescales_, psLeaves);
      psBranch->SetFirstEntry(tree->GetEntries());
    }
  }
}

void
TriggerMap::set(TString const& _path, UInt_t _prescale, Bool_t _decision)
{
  // Set the result of one trigger path

  CoreIter itr(core_.find(_path));
  if(itr == core_.end()) return;

  *itr->second.first = _prescale;
  *itr->second.second = _decision ? 1 : 0;
}

void
TriggerMap::copy(TriggerMap const& _orig)
{
  unsigned nO(_orig.size());

  if(currentMenu_ != _orig.currentMenu_){
    std::vector<std::string> paths;
    for(CoreConstIter itr(_orig.core_.begin()); itr != _orig.core_.end(); ++itr)
      paths.push_back(itr->first.Data());
    setMenu(_orig.currentMenu_, paths);
    treeNumber_ = -1;
  }

  std::copy(_orig.prescales_, _orig.prescales_ + nO, prescales_);
  std::copy(_orig.decisions_, _orig.decisions_ + nO, decisions_);
}

void
TriggerMap::releaseTree(TTree& _tree, Bool_t _fullRelease)
{
  TBranch* branch(0);
  if((branch = _tree.GetBranch(trigType_ + "Bits_" + currentMenu_)))
    _tree.ResetBranchAddress(branch);
  if((branch = _tree.GetBranch(trigType_ + "Prescales_" + currentMenu_)))
    _tree.ResetBranchAddress(branch);

  if(!_fullRelease) return;

  if((branch = _tree.GetBranch(trigType_ + "Config")))
    _tree.ResetBranchAddress(branch);

  if(inputTree_ == &_tree){
    inputTree_ = 0;
    treeNumber_ = -1;
  }
  else{
    for(unsigned iT(0); iT != outputTrees_.size(); ++iT){
      if(outputTrees_[iT] == &_tree){
        outputTrees_.erase(outputTrees_.begin() + iT);
        break;
      }
    }
  }
}

void
TriggerMap::releaseTrees(Bool_t _fullRelease)
{
  if(inputTree_) releaseTree(*inputTree_, _fullRelease);

  if(_fullRelease){
    while(outputTrees_.size() != 0)
      releaseTree(*outputTrees_[0], kTRUE); // releaseTree removes the tree from the vector
  }
  else{
    for(unsigned iT(0); iT != outputTrees_.size(); ++iT)
      releaseTree(*outputTrees_[iT], kFALSE);
  }
}

void
TriggerMap::clear_()
{
  core_.clear();

  delete [] prescales_;
  delete [] decisions_;
  prescales_ = 0;
  decisions_ = 0;

  currentMenu_ = "";
  treeNumber_ = -1;
}

TString
TriggerMap::formLeafList_() const
{
  TString leaves;
  for(CoreConstIter itr(core_.begin()); itr != core_.end(); ++itr)
    leaves += itr->first + "/b:";

  leaves.Remove(leaves.Length() - 1);

  return leaves;
}
