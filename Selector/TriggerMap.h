#ifndef TRIGGERMAP_H
#define TRIGGERMAP_H

#include <map>
#include <utility>
#include <iostream>

#include "TTree.h"



class TriggerMap {
    typedef std::map<TString, std::pair<UInt_t*, UChar_t*> > MapCore;
    typedef MapCore::const_iterator CoreConstIter;
    typedef MapCore::iterator CoreIter;

  public:
    class const_iterator {
      friend class TriggerMap;
    public:
      typedef std::pair<TString, std::pair<UInt_t, Bool_t> > value_type;

      const_iterator() : core_(), pair_() {}
      const_iterator& operator++() { ++core_; setPair(); return *this; }
      const_iterator operator++(int) { const_iterator tmp(*this); ++core_; setPair(); return tmp; }
      value_type const* operator->() const { return &pair_; }
      value_type const& operator*() const { return pair_; }
      bool operator==(const_iterator const& _rhs) const { return core_ == _rhs.core_; }
      bool operator!=(const_iterator const& _rhs) const { return !operator==(_rhs); }
    protected:
      CoreConstIter core_;
      value_type pair_;
      const_iterator(CoreConstIter const& _core) :
        core_(_core),
        pair_()
      {
        setPair();
      }
      void setPair()
      {
        pair_.first = core_->first;
        pair_.second.first = *core_->second.first;
        pair_.second.second = *core_->second.second != 0;
      }
    };
		
	typedef const_iterator iterator;

    TriggerMap(TString const&);
    ~TriggerMap();

    void Print(std::ostream& = std::cout) const;

    /*---- Functions for analysis use ----*/
    Bool_t pass(TString const&) const;
    UInt_t prescale(TString const&) const;

    TString getMenuName() const { return menuInEvent_ ? *menuInEvent_ : ""; }

    std::pair<UInt_t, Bool_t> operator[](TString const&) const;
    size_t size() const { return core_.size(); }
    const_iterator begin() const { return const_iterator(core_.begin()); }
    const_iterator end() const { return const_iterator(core_.end()); }
    iterator begin() { return iterator(core_.begin()); }
    iterator end() { return iterator(core_.end()); }
    const_iterator find(TString const& _path) const { return const_iterator(core_.find(_path)); }
    iterator find(TString const& _path) { return iterator(core_.find(_path)); }
    const_iterator lower_bound(TString const& _path) const { return const_iterator(core_.lower_bound(_path)); }
    iterator lower_bound(TString const& _path) { return iterator(core_.lower_bound(_path)); }
    const_iterator upper_bound(TString const& _path) const { return const_iterator(core_.upper_bound(_path)); }
    iterator upper_bound(TString const& _path) { return iterator(core_.upper_bound(_path)); }
    /*---- Functions for analysis use ----*/

    void setInput(TTree&);
    void addOutput(TTree&);
    void checkInput(TTree&);
    void setMenu(TString const&, std::vector<std::string> const&);
    void set(TString const&, UInt_t, Bool_t);
    void copy(TriggerMap const&);
    void releaseTree(TTree&, Bool_t);
    void releaseTrees(Bool_t);

  private:
    void clear_();
    TString formLeafList_() const;

    TString const trigType_; // hlt or l1
    MapCore core_;
    UInt_t* prescales_;
    UChar_t* decisions_;
    TString* menuInEvent_;
    TString currentMenu_;
    Int_t treeNumber_;
    TTree* inputTree_;
    std::vector<TTree*> outputTrees_;
  };

	
#endif
