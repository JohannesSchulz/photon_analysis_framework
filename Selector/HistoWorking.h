#ifndef _HistoWorking_h_
#define _HistoWorking_h_

#include <vector>
#include <map>
#include <string>

class TH1F;

class HistoWorking {
public:
  HistoWorking();
  ~HistoWorking();

  // add 1D/2D histogram to manager
  void Add(const std::string name, TH1F * h);
	
  // get number of histograms
  unsigned int size();

  // access histograms by name
  TH1F * operator[](const std::string name);

	
  // access histograms by index
  TH1F * operator[](const unsigned int i);

  // write histograms to a file
  void Write(const char * name);

private:
  std::map<std::string, TH1F *> histo;
  std::vector<std::string> hname;
};

#endif
