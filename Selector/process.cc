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



int main(int argc, char** argv)
{

/* cross section in pb */

double xs = 1;
double Ngen = 1;
double lumi =  7369.;
double lumiPart = 1.; //(2665629./96848304.);
double Eventweight = 1;
double theory_factor = 0.355514623;
		
	#ifdef __MC 

	std::cout << ">> MC flag <<" << std::endl; 

	MySelector *evt = new MySelector;
	evt->SetPileUpWeightFile("puWeights.root");	

string GJets40 = "GJets_40_100_V06";
string GJets40_9 = "GJets_40_100_V09";
string GJets100 = "GJets_100_200_V02";
string GJets100_9 = "GJets_100_200_V09";
string GJets200 = "GJets_200_400_V02";
string GJets200_9 = "GJets_200_400_V09";
string GJets400 = "GJets_400_inf_V02";
string GJets400_9 = "GJets_400_inf_V09";
string GJets4002 = "GJets_400_inf_V03";
string QCD100 = "QCD_100_250_V06";
string QCD100_9 = "QCD_100_250_V09";
string QCD250 = "QCD_250_500_V02";
string QCD250_9 = "QCD_250_500_V09";
string QCD500 = "QCD_500_1000_V02";
string QCD500_9 = "QCD_500_1000_V09";
string QCD1000 = "QCD_1000_inf_V02";
string QCD1000_9 = "QCD_1000_inf_V09";
string TTJets = "TTJets_V02";
string TTGamma = "TTGamma_V02";
string TTGamma2 = "TTGamma_V03";
string TTGamma_9 = "TTGamma_V09";
string ZGamma = "ZGamma_V02";
string ZGamma_9 = "ZGamma_V09";
string WGamma_10_15 = "WGamma_10_15_V07";
string WGamma_15_20 = "WGamma_15_20_V07";
string WGamma_20_30 = "WGamma_20_30_V07";
string WGamma_20_30_9 = "WGamma_20_30_V09";
string WGamma_30_50 = "WGamma_30_50_V07";
string WGamma_30_50_9 = "WGamma_30_50_V09";
string WGamma_50_130 = "WGamma_50_130_V07";
string WGamma_50_130_9 = "WGamma_50_130_V09";
string WGamma_130_inf = "WGamma_130_inf_V07";
string WGamma_130_inf_9 = "WGamma_130_inf_V09";
string ZGammaNuNu = "ZGammaNuNu_V02";
string ZGammaNuNu2 = "ZGammaNuNu_V03";
string ZGammaNuNu_9 = "ZGammaNuNu_V09";
string ZGammaLL = "ZGammaLL_V02";
string ZGammaLL2 = "ZGammaLL_V03";
string ZGammaLL_9 = "ZGammaLL_V09";
string WW_incl = "WW_incl_V06";
string WW_incl_9 = "WW_incl_V09";
string WZ_incl = "WZ_incl_V06";
string WZ_incl_9 = "WZ_incl_V09";
string ZZ_incl = "ZZ_incl_V06";
string ZZ_incl_9 = "ZZ_incl_V09";
string Signal_540_280 = "Signal_540_280";
string Signal_340_130 = "Signal_340_130";
string Signal_340_180 = "Signal_340_180";
string Signal_440_430 = "Signal_440_430";
string Signal_490_480 = "Signal_490_480";
string Signal_515_505 = "Signal_515_505";
string Signal_515_480 = "Signal_515_480";
string Signal_540_530 = "Signal_540_530";
string Signal_540_530_FULL = "Signal_540_530_FULL";
string Signal_540_505 = "Signal_540_505";
string Signal_540_480 = "Signal_540_480";
string Signal_565_555 = "Signal_565_555";
string Signal_565_530 = "Signal_565_530";
string Signal_565_505 = "Signal_565_505";
string Signal_590_580 = "Signal_590_580";
string Signal_590_530 = "Signal_590_530";
string Signal_590_555 = "Signal_590_555";
string Signal_615_605 = "Signal_615_605";
string Signal_615_580 = "Signal_615_580";
string Signal_615_555 = "Signal_615_555";
string Signal_640_630 = "Signal_640_630";
string Signal_640_630_FULL = "Signal_640_630_FULL";
string Signal_640_630_FULL_2 = "Signal_640_630_FULL_2";
string Signal_640_605 = "Signal_640_605";
string Signal_640_580 = "Signal_640_580";
string Signal_665_655 = "Signal_665_655";
string Signal_690_680 = "Signal_690_680";
string Signal_715_705 = "Signal_715_705";
string Signal_740_730 = "Signal_740_730";
string Signal_Bino_1300_1720 = "Signal_Bino_1300_1720";
string Signal_Bino_1700_1120 = "Signal_Bino_1700_1120";
string Signal_Wino_1700_720 = "Signal_Wino_1700_720";
string Signal_Wino_900_1720 = "Signal_Wino_900_1720";
string TChiNg_130 = "TChiNg_130";
string TChiNg_150 = "TChiNg_150";
string TChiNg_175 = "TChiNg_175";
string TChiNg_200 = "TChiNg_200";
string TChiNg_225 = "TChiNg_225";
string TChiNg_250 = "TChiNg_250";
string TChiNg_275 = "TChiNg_275";
string TChiNg_300 = "TChiNg_300";
string TChiNg_325 = "TChiNg_325";
string TChiNg_350 = "TChiNg_350";
string TChiNg_375 = "TChiNg_375";
string TChiNg_400 = "TChiNg_400";
string TChiNg_425 = "TChiNg_425";
string TChiNg_450 = "TChiNg_450";
string TChiNg_475 = "TChiNg_475";
string TChiNg_500 = "TChiNg_500";

string TChiwg_150 = "TChiwg_150";
string TChiwg_180 = "TChiwg_180";
string TChiwg_200 = "TChiwg_200";
string TChiwg_230 = "TChiwg_230";
string TChiwg_250 = "TChiwg_250";
string TChiwg_280 = "TChiwg_280";
string TChiwg_300 = "TChiwg_300";
string TChiwg_330 = "TChiwg_330";
string TChiwg_350 = "TChiwg_350";
string TChiwg_380 = "TChiwg_380";
string TChiwg_400 = "TChiwg_400";
string TChiwg_410 = "TChiwg_410";
string TChiwg_420 = "TChiwg_420";
string TChiwg_430 = "TChiwg_430";
string TChiwg_440 = "TChiwg_440";
string TChiwg_450 = "TChiwg_450";
string TChiwg_460 = "TChiwg_460";
string TChiwg_470 = "TChiwg_470";
string TChiwg_480 = "TChiwg_480";
string TChiwg_490 = "TChiwg_490";
string TChiwg_500 = "TChiwg_500";
string TChiwg_510 = "TChiwg_510";
string TChiwg_520 = "TChiwg_520";
string TChiwg_530 = "TChiwg_530";
string TChiwg_540 = "TChiwg_540";
string TChiwg_550 = "TChiwg_550";
string TChiwg_560 = "TChiwg_560";
string TChiwg_570 = "TChiwg_570";
string TChiwg_580 = "TChiwg_580";
string TChiwg_590 = "TChiwg_590";
string TChiwg_600 = "TChiwg_600";
string TChiwg_610 = "TChiwg_610";
string TChiwg_620 = "TChiwg_620";
string TChiwg_630 = "TChiwg_630";
string TChiwg_640 = "TChiwg_640";
string TChiwg_650 = "TChiwg_650";
string TChiwg_660 = "TChiwg_660";
string TChiwg_670 = "TChiwg_670";
string TChiwg_680 = "TChiwg_680";
string TChiwg_690 = "TChiwg_690";
string TChiwg_700 = "TChiwg_700";
string TChiwg_710 = "TChiwg_710";
string TChiwg_720 = "TChiwg_720";
string TChiwg_730 = "TChiwg_730";
string TChiwg_740 = "TChiwg_740";
string TChiwg_750 = "TChiwg_750";
string TChiwg_760 = "TChiwg_760";
string TChiwg_770 = "TChiwg_770";
string TChiwg_780 = "TChiwg_780";
string TChiwg_790 = "TChiwg_790";
string TChiwg_800 = "TChiwg_800";


string Signal_500_500_500 = "Signal_500_500_500";
string Signal_2000_530_540 = "Signal_2000_530_540";
string Signal_mu_250_m1_300_m2_600 = "Signal_mu_250_m1_300_m2_600";
string Signal_mu_350_m1_350_m2_600 = "Signal_mu_350_m1_350_m2_600";

/* total Ngen after Ntuplizer

 GJets100 = Ngen = 9662703;
 GJets200 = Ngen = 58927146;
 GJets400 = Ngen = 42441678;
 QCD250 = Ngen 	 = 27062078;
 QCD500 = Ngen	 = 30649292;
 QCD1000 = Ngen	 = 13843863;
 TTJets = Ngen	 = 6923652;
 ZGamma = Ngen	 = 6321549;
 WJets = Ngen		 = 57659905;

*/ 

if ( GJets100.compare(argv[1]) == 0 ) {
	xs = 5212.0;
	Ngen = 9662703;//473815; 9612703 	
	} 
		else if ( GJets100_9.compare(argv[1]) == 0 ) {
		xs = 5212.0;
		Ngen = 9612703;//456205;
		}	
		else if ( GJets200.compare(argv[1]) == 0 ) {
		xs = 960.5;
		Ngen = 58927146;//456205;
		}
		else if ( GJets200_9.compare(argv[1]) == 0 ) {
		xs = 960.5;
		Ngen = 58577146;//456205;
		}		
		else if ( GJets40.compare(argv[1]) == 0 ) {
		xs = 20930;
		Ngen = 19957930;
		}
		else if ( GJets40_9.compare(argv[1]) == 0 ) {
		xs = 20930;
		Ngen = 19857930;
		}		
		else if ( GJets400.compare(argv[1]) == 0 ) {
		xs = 107.5;
		Ngen = 42441678;//204239;
		}	
		else if ( GJets400_9.compare(argv[1]) == 0 ) {
		xs = 107.5;
		Ngen = 42253630;//204239;
		}		
		else if ( GJets4002.compare(argv[1]) == 0 ) {
		xs = 107.5;
		Ngen = 42441678;//204239;
		}		
				
		else if ( QCD100.compare(argv[1]) == 0 ) {
		xs = 10360000;
		Ngen = 50229518;//500000;
		}						
		else if ( QCD250.compare(argv[1]) == 0 ) {
		xs = 276000;
		Ngen = 27062078;//500000;
		}
		else if ( QCD500.compare(argv[1]) == 0 ) {
		xs = 8426;
		Ngen = 30649292;//413547;
		}
		else if ( QCD1000.compare(argv[1]) == 0 ) {
		xs = 204;
		Ngen = 13843863;//405506;
		}
		
		else if ( QCD100_9.compare(argv[1]) == 0 ) {
		xs = 10360000;
		Ngen = 50129518;//500000;
		}						
		else if ( QCD250_9.compare(argv[1]) == 0 ) {
		xs = 276000;
		Ngen = 27062078;//500000;
		}
		else if ( QCD500_9.compare(argv[1]) == 0 ) {
		xs = 8426;
		Ngen = 30599292;//413547;
		}
		else if ( QCD1000_9.compare(argv[1]) == 0 ) {
		xs = 204;
		Ngen = 13843863;//405506;
		}		
		
		else if ( TTJets.compare(argv[1]) == 0 ) {
		xs = 245.8; //NNLO
		Ngen = 6923652;//423652;
		}
		else if ( TTGamma.compare(argv[1]) == 0 ) {
		xs = 2.4; // 2.4 is measurement   2.63 NNLO TTJets times Ratio measured for ttg/tt
		Ngen = 2414200;//423652;
		}	
		else if ( TTGamma2.compare(argv[1]) == 0 ) {
		xs = 2.4; // 2.4 is measurement   2.63 NNLO TTJets times Ratio measured for ttg/tt
		Ngen = 2414200;//423652;
		}	
		else if ( TTGamma_9.compare(argv[1]) == 0 ) {
		xs = 2.4; // 2.4 is measurement   2.63 NNLO TTJets times Ratio measured for ttg/tt
		Ngen = 1719954;//423652;
		}			
			
		else if ( ZGamma.compare(argv[1]) == 0 ) {
		xs = 123.9;
		Ngen = 6321549;//456458;
		}	
		else if ( ZGamma_9.compare(argv[1]) == 0 ) {
		xs = 123.9;
		Ngen = 6321549;//456458;
		}		
		else if ( ZGammaLL.compare(argv[1]) == 0 ) {
		xs = 132.6;
		Ngen = 6588161;//456458;
		}
		else if ( ZGammaLL_9.compare(argv[1]) == 0 ) {
		xs = 132.6;
		Ngen = 6588161;//456458;
		}		
		else if ( ZGammaLL2.compare(argv[1]) == 0 ) {
		xs = 132.6;
		Ngen = 6588161;//456458;
		}						
		else if ( ZGammaNuNu.compare(argv[1]) == 0 ) {
		xs = 0.074;
		Ngen = 489474;//500000;
		}
		else if ( ZGammaNuNu2.compare(argv[1]) == 0 ) {
		xs = 0.074;
		Ngen = 489474;//500000;
		}
		else if ( ZGammaNuNu_9.compare(argv[1]) == 0 ) {
		xs = 0.074;
		Ngen = 489474;//500000;
		}						
		else if ( WW_incl.compare(argv[1]) == 0 ) {
		xs = 56.0; //xs = 54.838; //NLO //56.0
		Ngen = 10000431;//500000;
		}	
		else if ( WW_incl_9.compare(argv[1]) == 0 ) {
		xs = 56.0; //xs = 54.838; //NLO //56.0
		Ngen = 9950431;//500000;
		}				
		else if ( WZ_incl.compare(argv[1]) == 0 ) {
		xs = 33.6;//xs = 12.63; //LO //23.7
		Ngen = 10000283;//500000;
		}	
		else if ( WZ_incl_9.compare(argv[1]) == 0 ) {
		xs = 33.6;//xs = 12.63; //LO //23.7
		Ngen = 10000283;//500000;
		}				
		else if ( ZZ_incl.compare(argv[1]) == 0 ) {
		xs = 17.0;//xs = 5.196; //LO // 7.6
		Ngen = 9799908;//500000;
		}	
		else if ( ZZ_incl_9.compare(argv[1]) == 0 ) {
		xs = 17.0;//xs = 5.196; //LO // 7.6
		Ngen = 9799908;//500000;
		}			
		else if ( Signal_540_280.compare(argv[1]) == 0 ) {
		xs = 0.009425;
		Ngen = 7992;
		}	
		else if ( Signal_Bino_1300_1720.compare(argv[1]) == 0 ) {
		xs = 0.005325;
		Ngen = 10000;
		}		
		else if ( Signal_Bino_1700_1120.compare(argv[1]) == 0 ) {
		xs = 0.0097;
		Ngen = 10000;
		}			
		else if ( Signal_Wino_1700_720.compare(argv[1]) == 0 ) {
		xs = 0.3164;
		Ngen = 60000;
		}	
		else if ( Signal_Wino_900_1720.compare(argv[1]) == 0 ) {
		xs = 0.75;
		Ngen = 60000;
		}			
		
			
		else if ( Signal_540_530.compare(argv[1]) == 0 ) {
		xs = 0.009501;
		Ngen = 10000;
		}
		else if ( Signal_540_530_FULL.compare(argv[1]) == 0 ) {
		xs = 0.009566;
		Ngen = 4000;
		}					
		else if ( Signal_340_130.compare(argv[1]) == 0 ) {
		xs = 0.0983;
		Ngen = 499;
		}		
		else if ( Signal_340_180.compare(argv[1]) == 0 ) {
		xs = 0.09724;
		Ngen = 5734;
		}	
		else if ( Signal_440_430.compare(argv[1]) == 0 ) {
		xs = 0.0983;
		Ngen = 499;
		}		
		else if ( Signal_490_480.compare(argv[1]) == 0 ) {
		xs = 0.01634;
		Ngen = 10000;
		}			
		else if ( Signal_590_580.compare(argv[1]) == 0 ) {
		xs = 0.005774;
		Ngen = 10000;
		}	
		else if ( Signal_590_555.compare(argv[1]) == 0 ) {
		xs = 0.005769;
		Ngen = 10000;
		}		
		else if ( Signal_590_530.compare(argv[1]) == 0 ) {
		xs = 0.005806;
		Ngen = 10000;
		}	
		else if ( Signal_640_580.compare(argv[1]) == 0 ) {
		xs = 0.003553;
		Ngen = 10000;
		}				
		else if ( Signal_640_605.compare(argv[1]) == 0 ) {
		xs = 0.003534;
		Ngen = 10000;
		}				
		else if ( Signal_640_630.compare(argv[1]) == 0 ) {
		xs = 0.00352;
		Ngen = 10000;
		}		
		else if ( Signal_640_630_FULL.compare(argv[1]) == 0 ) {
		xs = 0.003574;
		Ngen = 1300;
		}
		else if ( Signal_640_630_FULL_2.compare(argv[1]) == 0 ) {
		xs = 0.003520;
		Ngen = 10000;
		}		
					
		else if ( Signal_690_680.compare(argv[1]) == 0 ) {
		xs = 0.002181;
		Ngen = 10000;
		}			
		else if ( Signal_540_480.compare(argv[1]) == 0 ) {
		xs = 0.009638;
		Ngen = 10000;
		}	
		else if ( Signal_540_505.compare(argv[1]) == 0 ) {
		xs = 0.009539;
		Ngen = 10000;
		}		
		else if ( Signal_515_505.compare(argv[1]) == 0 ) {
		xs = 0.01238;
		Ngen = 10000;
		}	
		else if ( Signal_515_480.compare(argv[1]) == 0 ) {
		xs = 0.01241;
		Ngen = 10000;
		}			
		else if ( Signal_565_555.compare(argv[1]) == 0 ) {
		xs = 0.007475;
		Ngen = 10000;
		}	
		else if ( Signal_565_530.compare(argv[1]) == 0 ) {
		xs = 0.007441;
		Ngen = 10000;
		}			
		else if ( Signal_565_505.compare(argv[1]) == 0 ) {
		xs = 0.007430;
		Ngen = 10000;
		}		
		else if ( Signal_615_555.compare(argv[1]) == 0 ) {
		xs = 0.00454;
		Ngen = 10000;
		}				
		else if ( Signal_615_580.compare(argv[1]) == 0 ) {
		xs = 0.004518;
		Ngen = 10000;
		}			
		else if ( Signal_615_605.compare(argv[1]) == 0 ) {
		xs = 0.004457;
		Ngen = 10000;
		}		
		else if ( Signal_665_655.compare(argv[1]) == 0 ) {
		xs = 0.002764;
		Ngen = 10000;
		}		
		else if ( Signal_715_705.compare(argv[1]) == 0 ) {
		xs = 0.001715;
		Ngen = 10000;
		}				
			
		else if ( Signal_740_730.compare(argv[1]) == 0 ) {
		xs = 0.001378;
		Ngen = 10000;
		}			
		else if ( Signal_500_500_500.compare(argv[1]) == 0 ) {
		xs = 0.02674;
		Ngen = 10000;
		}		
		else if ( Signal_2000_530_540.compare(argv[1]) == 0 ) {
		xs = 0.005434;
		Ngen = 10000;
		}				
		else if ( Signal_mu_250_m1_300_m2_600.compare(argv[1]) == 0 ) {
		xs = 0.223;
		Ngen = 1000;
		}
		else if ( Signal_mu_350_m1_350_m2_600.compare(argv[1]) == 0 ) {
		xs = 0.007;
		Ngen = 1000;
		}				

		else if ( WGamma_10_15.compare(argv[1]) == 0 ) {
		xs = 19.9;
		Ngen = 2100181;//500000;
		}			
		else if ( WGamma_15_20.compare(argv[1]) == 0 ) {
		xs = 12.4;
		Ngen = 2025394;//500000;
		}				
	/*	else if ( WGamma_20_30.compare(argv[1]) == 0 ) {
		xs = 13.07;
		Ngen = 903435;//500000;
		}			
		else if ( WGamma_30_50.compare(argv[1]) == 0 ) {
		xs = 6.9;
		Ngen = 869591;//500000;
		}					
		else if ( WGamma_50_130.compare(argv[1]) == 0 ) {
		xs = 1.17;
		Ngen = 1135698;//500000;
		}		*/	
		else if ( WGamma_20_30.compare(argv[1]) == 0 ) {
		xs = 136.347;
		Ngen = 3000000;//500000;
		}
							
		else if ( WGamma_20_30_9.compare(argv[1]) == 0 ) {
		xs = 136.347;
		Ngen = 3000000;//500000;  //LHE numbers to get the correct cross sections!!!
		}
		else if ( WGamma_30_50.compare(argv[1]) == 0 ) {
		xs = 75.48;
		Ngen = 3000000;//500000;//LHE numbers to get the correct cross sections!!!
		}
		else if ( WGamma_30_50_9.compare(argv[1]) == 0 ) {
		xs = 75.48;
		Ngen = 3000000;//500000;//LHE numbers to get the correct cross sections!!!
		}			
						
		else if ( WGamma_50_130.compare(argv[1]) == 0 ) {
		xs = 9.633;
		Ngen = 3000000;//500000;//LHE numbers to get the correct cross sections!!!
		}
		
		else if ( WGamma_50_130_9.compare(argv[1]) == 0 ) {
		xs = 9.633;
		Ngen = 3000000;//500000;//LHE numbers to get the correct cross sections!!!
		}		
		
		else if ( WGamma_130_inf.compare(argv[1]) == 0 ) {
		xs = 0.2571;
		Ngen = 471458;//500000;
		}			
		else if ( WGamma_130_inf_9.compare(argv[1]) == 0 ) {
		xs = 0.2571;
		Ngen = 471458;//500000;
		}	
		
		

				
		else if ( TChiwg_150.compare(argv[1]) == 0 ) {
		xs = 2.39;
		Ngen = 46105;//500000;
		}		
		else if ( TChiwg_180.compare(argv[1]) == 0 ) {
		xs = 1.18;
		Ngen = 51463;//500000;
		}	
		else if ( TChiwg_200.compare(argv[1]) == 0 ) {
		xs = 0.785;
		Ngen = 47667;//500000;
		}	
		else if ( TChiwg_230.compare(argv[1]) == 0 ) {
		xs = 0.447;
		Ngen = 44326;//500000;
		}		
		else if ( TChiwg_250.compare(argv[1]) == 0 ) {
		xs = 0.318;
		Ngen = 47952;//500000;
		}		
		else if ( TChiwg_280.compare(argv[1]) == 0 ) {
		xs = 0.197;
		Ngen = 42352;//500000;
		}		
		else if ( TChiwg_300.compare(argv[1]) == 0 ) {
		xs = 0.146;
		Ngen = 44502;//500000;
		}	
		else if ( TChiwg_330.compare(argv[1]) == 0 ) {
		xs = 0.0956;
		Ngen = 47362;//500000;
		}		
		else if ( TChiwg_350.compare(argv[1]) == 0 ) {
		xs = 0.0737;
		Ngen = 38484;//500000;
		}		
		else if ( TChiwg_380.compare(argv[1]) == 0 ) {
		xs = 0.0498;
		Ngen = 46102;//500000;
		}				
		else if ( TChiwg_400.compare(argv[1]) == 0 ) {
		xs = 0.0393;
		Ngen = 44167;//500000;
		}						
		else if ( TChiwg_480.compare(argv[1]) == 0 ) {
		xs = 0.0156;
		Ngen = 45247;//500000;
		}
		else if ( TChiwg_490.compare(argv[1]) == 0 ) {
		xs = 0.0136292;
		Ngen = 36009;//500000;
		}					
		else if ( TChiwg_500.compare(argv[1]) == 0 ) {
		xs = 0.0125;
		Ngen = 35824;//500000;
		}
		else if ( TChiwg_510.compare(argv[1]) == 0 ) {
		xs = 0.0112515;
		Ngen = 39434;//500000;
		}					
		else if ( TChiwg_520.compare(argv[1]) == 0 ) {
		xs = 0.0102231;
		Ngen = 42556;//500000;
		}
		else if ( TChiwg_530.compare(argv[1]) == 0 ) {
		xs = 0.0092886;
		Ngen = 44687;//500000;
		}		
		else if ( TChiwg_540.compare(argv[1]) == 0 ) {
		xs = 0.00843956;
		Ngen = 42490;//500000;
		}					
		else if ( TChiwg_550.compare(argv[1]) == 0 ) {
		xs = 0.00761;
		Ngen = 35148;//500000;
		}	
		else if ( TChiwg_560.compare(argv[1]) == 0 ) {
		xs = 0.00696722;
		Ngen = 34856;//500000;
		}		
		else if ( TChiwg_570.compare(argv[1]) == 0 ) {
		xs = 0.00633037;
		Ngen = 37358;//500000;
		}
		else if ( TChiwg_580.compare(argv[1]) == 0 ) {
		xs = 0.00575173;
		Ngen = 42317;//500000;
		}		
		else if ( TChiwg_590.compare(argv[1]) == 0 ) {
		xs = 0.00522599;
		Ngen = 42684;//500000;
		}							
		else if ( TChiwg_600.compare(argv[1]) == 0 ) {
		xs = 0.00474;
		Ngen = 36954;//500000;
		}	
		else if ( TChiwg_610.compare(argv[1]) == 0 ) {
		xs = 0.00431427;
		Ngen = 33343;//500000;
		}			
		else if ( TChiwg_620.compare(argv[1]) == 0 ) {
		xs = 0.00391992;
		Ngen = 38600;//500000;
		}	
		else if ( TChiwg_630.compare(argv[1]) == 0 ) {
		xs = 0.00356161;
		Ngen = 32177;//500000;
		}
		else if ( TChiwg_640.compare(argv[1]) == 0 ) {
		xs = 0.00323606;
		Ngen = 40043;//500000;
		}				
		else if ( TChiwg_650.compare(argv[1]) == 0 ) {
		xs = 0.00288;
		Ngen = 31243;//500000;
		}
		else if ( TChiwg_660.compare(argv[1]) == 0 ) {
		xs = 0.0026715;
		Ngen = 38673;//500000;
		}							
		else if ( TChiwg_670.compare(argv[1]) == 0 ) {
		xs = 0.00242731;
		Ngen = 41517;//500000;
		}	
		else if ( TChiwg_680.compare(argv[1]) == 0 ) {
		xs = 0.00220544;
		Ngen = 30300;//500000;
		}						
		else if ( TChiwg_690.compare(argv[1]) == 0 ) {
		xs = 0.00200385;
		Ngen = 34229;//500000;
		}			
		else if ( TChiwg_700.compare(argv[1]) == 0 ) {
		xs = 0.00182068;
		Ngen = 29730;//500000;
		}		
		else if ( TChiwg_710.compare(argv[1]) == 0 ) {
		xs = 0.00165426;
		Ngen = 38723;//500000;
		}			
		else if ( TChiwg_720.compare(argv[1]) == 0 ) {
		xs = 0.00150305;
		Ngen = 31467;//500000;
		}	
		else if ( TChiwg_730.compare(argv[1]) == 0 ) {
		xs = 0.00136566;
		Ngen = 39199;//500000;
		}
		else if ( TChiwg_740.compare(argv[1]) == 0 ) {
		xs = 0.00124083;
		Ngen = 43856;//500000;
		}				
		else if ( TChiwg_750.compare(argv[1]) == 0 ) {
		xs = 0.00112741;
		Ngen = 38394;//500000;
		}
		else if ( TChiwg_760.compare(argv[1]) == 0 ) {
		xs = 0.00102436;
		Ngen = 38252;//500000;
		}							
		else if ( TChiwg_770.compare(argv[1]) == 0 ) {
		xs = 0.000930727;
		Ngen = 32753;//500000;
		}	
		else if ( TChiwg_780.compare(argv[1]) == 0 ) {
		xs = 0.000845652;
		Ngen = 32543;//500000;
		}						
		else if ( TChiwg_790.compare(argv[1]) == 0 ) {
		xs = 0.000768354;
		Ngen = 36396;//500000;
		}			
		else if ( TChiwg_800.compare(argv[1]) == 0 ) {
		xs = 0.000698122;
		Ngen = 34190;//500000;
		}			
		

/*	//Pure Higgsino n2n3 production without any further factors		
		else if ( TChiNg_130.compare(argv[1]) == 0 ) {
		xs = 0.58;
		Ngen = 413352;//500000;
		}	
		else if ( TChiNg_150.compare(argv[1]) == 0 ) {
		xs = 0.33;
		Ngen = 323609;//500000;
		}	
		else if ( TChiNg_175.compare(argv[1]) == 0 ) {
		xs = 0.179;
		Ngen = 312296;//500000;
		}	 
		else if ( TChiNg_200.compare(argv[1]) == 0 ) {
		xs = 0.104;
		Ngen = 343875;//500000;
		}	  
 		else if ( TChiNg_225.compare(argv[1]) == 0 ) {
		xs = 0.0642;
		Ngen = 336934;//500000;
		}	  
 		else if ( TChiNg_250.compare(argv[1]) == 0 ) {
		xs = 0.0412;
		Ngen = 240281;//500000;
		}	  
 		else if ( TChiNg_275.compare(argv[1]) == 0 ) {
		xs = 0.0273;
		Ngen = 236783;//500000;
		}	   
 		else if ( TChiNg_300.compare(argv[1]) == 0 ) {
		xs = 0.0186;
		Ngen = 231208;//500000;
		}	  
 		else if ( TChiNg_325.compare(argv[1]) == 0 ) {
		xs = 0.0129;
		Ngen = 229808;//500000;
		}	   
 		else if ( TChiNg_350.compare(argv[1]) == 0 ) {
		xs = 0.00914;
		Ngen = 170443;//500000;
		}	   
 		else if ( TChiNg_375.compare(argv[1]) == 0 ) {
		xs = 0.00658;
		Ngen = 167666;//500000;
		}	   
 		else if ( TChiNg_400.compare(argv[1]) == 0 ) {
		xs = 0.0048;
		Ngen = 166326;//500000;
		}	  
 		else if ( TChiNg_425.compare(argv[1]) == 0 ) {
		xs = 0.00355;
		Ngen = 162377;//500000;
		}	  
 		else if ( TChiNg_450.compare(argv[1]) == 0 ) {
		xs = 0.00264;
		Ngen = 163722;//500000;
		}	   
 		else if ( TChiNg_475.compare(argv[1]) == 0 ) {
		xs = 0.00199;
		Ngen = 163123;//500000;
		}	  
 		else if ( TChiNg_500.compare(argv[1]) == 0 ) {
		xs = 0.00151;
		Ngen = 162553;//500000;
		}	   	
*/
	// Pure Wino c+c and c+n scaled with theory factor sin^2(Theta)*cos^2(Theta)*2

		else if ( TChiNg_130.compare(argv[1]) == 0 ) {
		xs = 5.841*theory_factor;
		Ngen = 413352;//500000;
		}	
		else if ( TChiNg_150.compare(argv[1]) == 0 ) {
		xs = 3.385*theory_factor;
		Ngen = 323609;//500000;
		}	
		else if ( TChiNg_175.compare(argv[1]) == 0 ) {
		xs = 1.851*theory_factor;
		Ngen = 312296;//500000;
		}	 
		else if ( TChiNg_200.compare(argv[1]) == 0 ) {
		xs = 1.095*theory_factor;
		Ngen = 343875;//500000;
		}	  
 		else if ( TChiNg_225.compare(argv[1]) == 0 ) {
		xs = 0.68*theory_factor;
		Ngen = 336934;//500000;
		}	  
 		else if ( TChiNg_250.compare(argv[1]) == 0 ) {
		xs = 0.44*theory_factor;
		Ngen = 240281;//500000;
		}	  
 		else if ( TChiNg_275.compare(argv[1]) == 0 ) {
		xs = 0.294*theory_factor;
		Ngen = 236783;//500000;
		}	   
 		else if ( TChiNg_300.compare(argv[1]) == 0 ) {
		xs = 0.199*theory_factor;
		Ngen = 231208;//500000;
		}	  
 		else if ( TChiNg_325.compare(argv[1]) == 0 ) {
		xs = 0.137*theory_factor;
		Ngen = 229808;//500000;
		}	   
 		else if ( TChiNg_350.compare(argv[1]) == 0 ) {
		xs = 0.0967*theory_factor;
		Ngen = 170443;//500000;
		}	   
 		else if ( TChiNg_375.compare(argv[1]) == 0 ) {
		xs = 0.0691*theory_factor;
		Ngen = 167666;//500000;
		}	   
 		else if ( TChiNg_400.compare(argv[1]) == 0 ) {
		xs = 0.0500*theory_factor;
		Ngen = 166326;//500000;
		}	  
 		else if ( TChiNg_425.compare(argv[1]) == 0 ) {
		xs = 0.0366*theory_factor;
		Ngen = 162377;//500000;
		}	  
 		else if ( TChiNg_450.compare(argv[1]) == 0 ) {
		xs = 0.027*theory_factor;
		Ngen = 163722;//500000;
		}	   
 		else if ( TChiNg_475.compare(argv[1]) == 0 ) {
		xs = 0.0201*theory_factor;
		Ngen = 163123;//500000;
		}	  
 		else if ( TChiNg_500.compare(argv[1]) == 0 ) {
		xs = 0.0151*theory_factor;
		Ngen = 162553;//500000;
		}


	
	Eventweight = ( xs / Ngen ) * lumi * lumiPart;

	#endif 

  TFile* MyFile = new TFile(argv[2], "recreate");
  MyFile->cd();

	#ifdef __Data
	
  std::cout << ">> Data flag <<" << std::endl;  
  
 
  MySelector *evt = new MySelector;
	
	#endif

	std::cout << "Cross-section of " << argv[1] << " is: " << xs << " pb and the event weight: " << Eventweight << std::endl;
	if( argc < 3 ) {
		std::cout << "usage: ./process job_name output.root input1.root input2.root ..." << std::endl;
		return 1;
		}
		
	TChain * tchain = new TChain( "susyTree" );

 	for(int i=3; i<argc; ++i){
	  tchain->Add( argv[i] );
		}

  evt->AddSignalTrigger("HLT_Photon30_R9Id90_CaloId_HE10_Iso40_EBOnly_Met25_HBHENoiseCleaned");
	evt->AddPhotonHadTrigger("HLT_Photon70_CaloIdXL_PFNoPUHT400");
  evt->AddMETTrigger("HLT_MET100_HBHENoiseCleaned");
  evt->AddIsoGammaTrigger("HLT_Photon30_R9Id90_CaloId_HE10_Iso40_EBOnly");   
  evt->AddDisplacedTrigger("HLT_DisplacedPhoton65EBOnly_CaloIdVL_IsoL_PFMET30");
  evt->AddDisplacedTrigger("HLT_DisplacedPhoton65_CaloIdVL_IsoL_PFMET25"); 
  evt->AddGamma135Trigger("HLT_Photon135");
  evt->AddGamma30Trigger("HLT_Photon30");
  evt->AddHLTPhysicsTrigger("HLT_Physics");           
	evt->BGInfo( argv[1] );
  evt->Init( tchain );
	
  Long64_t nentries = evt->fChain->GetEntries();

cout << "entries:  " << nentries << endl;
  evt->Begin( tchain );

  evt->SlaveBegin( tchain );

	
	std::cout<<"-----------------------------------------------"<<std::endl;
	std::cout<<"   "<<argv[1]<<" has total number of Events: "<<nentries<<std::endl;
	std::cout<<"-----------------------------------------------"<<std::endl;
  for (Long64_t i = 0; i < nentries; i++){
     evt->SetLumiWeight(Eventweight);
	   evt->GetEntry(i);
     evt->Process(i);
	   }
  evt->SlaveTerminate();
  evt->Terminate();

	TTree* MyTree = evt->GetPdfTree();
	cout << MyTree->GetEntries() << endl;
	MyFile->cd();
	MyTree->Write();
//	MyFile->Close();
	evt->histo.Write(argv[2]);
	evt->histo2.Update(argv[2]);

	MyFile->Close();

	return 0;
}
