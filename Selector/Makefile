C=g++
LD=g++

#O2 for optimization, g for debugging, pg for profiling
SPECIALFLAGS= -g #-g -Wall -pg#-O2
ROOTAUXCFLAGS=$(shell root-config --auxcflags)
ROOTCFLAGS=$(shell root-config --cflags)
ROOTLIBS=$(shell root-config --libs) #-lMath # -lMinuit
CFLAGS = $(SPECIALFLAGS) -Wall $(ROOTAUXCFLAGS)
LFLAGS = $(SPECIALFLAGS) #-lz 

RCXX=$(SPECIALFLAGS) -Wno-deprecated -Wall $(ROOTCFLAGS)
RLXX=$(LFLAGS) $(ROOTLIBS) 

SRC=TriggerMap.cc DataSelector.cc MCSelector.cc process.cc MySelector.cc HistoWorking.cc HistoWorking2.cc  MyPhoton.cc MyJet.cc MyPfParticle.cc MyGenParticles.cc


%.MC.o: %.cc
		$(C) $(RCXX)  -D__MC -c $< -o $@

%.Data.o: %.cc
		$(C) $(RCXX) -D__Data -c $< -o $@

all: MC Data


clean:
	@rm -f *.o 
	@rm -f processMC processData 

MC:  $(SRC:.cc=.MC.o)
	$(LD) $(SRC:.cc=.MC.o) $(RLXX) -lMathMore  -o processMC -D__MC
	@echo '-> executable processMC created.'

Data: $(SRC:.cc=.Data.o)
	$(LD) $(SRC:.cc=.Data.o) $(RLXX) -lMathMore  -o processData -D__Data
	@echo '-> executable processData created.'
