#include "HistoWorking.h"

#include <TH1F.h>
#include <TH2F.h>
#include <TFile.h>

HistoWorking::HistoWorking()
{
}

HistoWorking::~HistoWorking()
{
}

void HistoWorking::Add(const std::string name, TH1F * h)
{
  histo[name] = h;
  hname.push_back(name); 
}

TH1F * HistoWorking::operator[](const std::string name)  
{ 
  return histo[name];
}

TH1F * HistoWorking::operator[](const unsigned int i)
{ 
  return histo[hname[i]]; 
}

unsigned int HistoWorking::size()
{
  return hname.size();
}

void HistoWorking::Write(const char * name)
{
 // TFile f(name, "UPDATE");
  for (unsigned int i = 0; i < size(); i++) {
    histo[hname[i]]->Write();
  }
//  f.Close();
}
