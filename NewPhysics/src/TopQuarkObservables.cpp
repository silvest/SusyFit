#include "TopQuarkObservables.h"
#include "std_make_vector.h"


TopQuarkObservables::TopQuarkObservables(const NPSMEFTd6General& NP_i) : NP(NP_i) {};


//// ALL THE UNITS OF THE WILSON COEFFICIENTS ARE IN TeV^(-2). THIS FACTOR IS CONSIDERED IN THE GETTER 




////// ttbar Forward Backward asymmetry at Tevatron ///////////////////////////////////


FB_asymmetry_Tevatron_tt_diff_mtt_LO::FB_asymmetry_Tevatron_tt_diff_mtt_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{

    setParametersForObservable(make_vector<std::string>() 
            << "SM_FB_asymmetry_bin_mtt_350_450" << "SM_FB_asymmetry_deno_bin_mtt_350_450"
            << "SM_FB_asymmetry_bin_mtt_450_550" << "SM_FB_asymmetry_deno_bin_mtt_450_550"
            << "SM_FB_asymmetry_bin_mtt_550_650" << "SM_FB_asymmetry_deno_bin_mtt_550_650"
            << "SM_FB_asymmetry_bin_mtt_650_750" << "SM_FB_asymmetry_deno_bin_mtt_650_750");
            
    
};


double FB_asymmetry_Tevatron_tt_diff_mtt_LO::computeThValue()
{
    
    b_min = getBinMin();
    b_max = getBinMax();
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    
    //double C_tG = ewgc("CuGR",2,2);

    
    
    
    if(b_min == 350 && b_max == 450){
        
        
        double SM_FB_asymmetry_bin_mtt_350_450 = SM.getOptionalParameter("SM_FB_asymmetry_bin_mtt_350_450");
        double SM_FB_asymmetry_deno_bin_mtt_350_450 = SM.getOptionalParameter("SM_FB_asymmetry_deno_bin_mtt_350_450");
        double SM_FB_asymmetry_num_bin_mtt_350_450 = SM_FB_asymmetry_bin_mtt_350_450*SM_FB_asymmetry_deno_bin_mtt_350_450;
        
        double SM_sigma_pos_bin_mtt_350_450 =0.5*(SM_FB_asymmetry_num_bin_mtt_350_450+SM_FB_asymmetry_deno_bin_mtt_350_450);
        double SM_sigma_neg_bin_mtt_350_450 =0.5*(SM_FB_asymmetry_deno_bin_mtt_350_450-SM_FB_asymmetry_num_bin_mtt_350_450);

        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            
            
            double sigma_pos_bin_mtt_350_450_madgraph = 1.675650;
            double sigma_pos_bin_mtt_350_450_NP = -0.006110*ewgc("CG")+0.015540*ewgc("Cqd8R",2,2,0,0)
            +0.304934*ewgc("Cqq1R",0,2,2,0)+0.419488*ewgc("Cqq3R",0,2,2,0)+0.004257*ewgc("Cqq3R",1,2,2,1)
            +0.087584*ewgc("Cqu8R",0,0,2,2)+0.073317*ewgc("Cqu8R",2,2,0,0)+0.014866*ewgc("Cud8R",2,2,0,0)
            -0.385947*ewgc("CuGR",2,2)+0.298571*ewgc("CuuR",0,2,2,0);
            double sigma_neg_bin_mtt_350_450_madgraph = 1.674510;
            double sigma_neg_bin_mtt_350_450_NP = -0.007566*ewgc("CG")+0.014887*ewgc("Cqd8R",2,2,0,0)
            +0.305105*ewgc("Cqq1R",0,2,2,0)+0.418602*ewgc("Cqq3R",0,2,2,0)+0.002955*ewgc("Cqq3R",1,2,2,1)
            +0.085906*ewgc("Cqu8R",0,0,2,2)+0.073521*ewgc("Cqu8R",2,2,0,0)+0.015697*ewgc("Cud8R",2,2,0,0)
            -0.383667*ewgc("CuGR",2,2)+0.300446*ewgc("CuuR",0,2,2,0);
            
            double sigma_pos_bin_mtt_350_450_NP_Corrected = SM_sigma_pos_bin_mtt_350_450*sigma_pos_bin_mtt_350_450_NP/sigma_pos_bin_mtt_350_450_madgraph;
            double sigma_neg_bin_mtt_350_450_NP_Corrected = SM_sigma_neg_bin_mtt_350_450*sigma_neg_bin_mtt_350_450_NP/sigma_neg_bin_mtt_350_450_madgraph;
            
            double NP_FB_asymmetry_num_bin_mtt_350_450 = sigma_pos_bin_mtt_350_450_NP_Corrected - sigma_neg_bin_mtt_350_450_NP_Corrected;
            double NP_FB_asymmetry_deno_bin_mtt_350_450 = sigma_pos_bin_mtt_350_450_NP_Corrected + sigma_neg_bin_mtt_350_450_NP_Corrected;;
            
            return  SM_FB_asymmetry_bin_mtt_350_450*(1+(NP_FB_asymmetry_num_bin_mtt_350_450-NP_FB_asymmetry_deno_bin_mtt_350_450)/SM_FB_asymmetry_deno_bin_mtt_350_450);            
        
        }
        
    } else if(b_min == 450 && b_max == 550){
        
        
        double SM_FB_asymmetry_bin_mtt_450_550 = SM.getOptionalParameter("SM_FB_asymmetry_bin_mtt_450_550");
        double SM_FB_asymmetry_deno_bin_mtt_450_550 = SM.getOptionalParameter("SM_FB_asymmetry_deno_bin_mtt_450_550");
        double SM_FB_asymmetry_num_bin_mtt_450_550 = SM_FB_asymmetry_bin_mtt_450_550*SM_FB_asymmetry_deno_bin_mtt_450_550;
        
        double SM_sigma_pos_bin_mtt_450_550 =0.5*(SM_FB_asymmetry_num_bin_mtt_450_550+SM_FB_asymmetry_deno_bin_mtt_450_550);
        double SM_sigma_neg_bin_mtt_450_550 =0.5*(SM_FB_asymmetry_deno_bin_mtt_450_550-SM_FB_asymmetry_num_bin_mtt_450_550);

        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            
            
            double sigma_pos_bin_mtt_450_550_madgraph = 0.683803;
            double sigma_pos_bin_mtt_450_550_NP = -0.003753*ewgc("CG")+0.007844*ewgc("Cqd8R",2,2,0,0)
            +0.201208*ewgc("Cqq1R",0,2,2,0)+0.257805*ewgc("Cqq3R",0,2,2,0)+0.000709*ewgc("Cqq3R",1,2,2,1)
            +0.056092*ewgc("Cqu8R",0,0,2,2)+0.047574*ewgc("Cqu8R",2,2,0,0)+0.008085*ewgc("Cud8R",2,2,0,0)
            -0.168317*ewgc("CuGR",2,2)+0.198755*ewgc("CuuR",0,2,2,0);
            double sigma_neg_bin_mtt_450_550_madgraph = 0.685429;
            double sigma_neg_bin_mtt_450_550_NP = -0.004203*ewgc("CG")+0.008080*ewgc("Cqd8R",2,2,0,0)
            +0.201688*ewgc("Cqq1R",0,2,2,0)+0.257507*ewgc("Cqq3R",0,2,2,0)+0.000816*ewgc("Cqq3R",1,2,2,1)
            +0.056997*ewgc("Cqu8R",0,0,2,2)+0.047589*ewgc("Cqu8R",2,2,0,0)+0.007820*ewgc("Cud8R",2,2,0,0)
            -0.169079*ewgc("CuGR",2,2)+0.198609*ewgc("CuuR",0,2,2,0);
            
            double sigma_pos_bin_mtt_450_550_NP_Corrected = SM_sigma_pos_bin_mtt_450_550*sigma_pos_bin_mtt_450_550_NP/sigma_pos_bin_mtt_450_550_madgraph;
            double sigma_neg_bin_mtt_450_550_NP_Corrected = SM_sigma_neg_bin_mtt_450_550*sigma_neg_bin_mtt_450_550_NP/sigma_neg_bin_mtt_450_550_madgraph;
            
            double NP_FB_asymmetry_num_bin_mtt_450_550 = sigma_pos_bin_mtt_450_550_NP_Corrected - sigma_neg_bin_mtt_450_550_NP_Corrected;
            double NP_FB_asymmetry_deno_bin_mtt_450_550 = sigma_pos_bin_mtt_450_550_NP_Corrected + sigma_neg_bin_mtt_450_550_NP_Corrected;;
            
            return  SM_FB_asymmetry_bin_mtt_450_550*(1+(NP_FB_asymmetry_num_bin_mtt_450_550-NP_FB_asymmetry_deno_bin_mtt_450_550)/SM_FB_asymmetry_deno_bin_mtt_450_550);            
        
        }
        
    } else if(b_min == 550 && b_max == 650){
        
        
        double SM_FB_asymmetry_bin_mtt_550_650 = SM.getOptionalParameter("SM_FB_asymmetry_bin_mtt_550_650");
        double SM_FB_asymmetry_deno_bin_mtt_550_650 = SM.getOptionalParameter("SM_FB_asymmetry_deno_bin_mtt_550_650");
        double SM_FB_asymmetry_num_bin_mtt_550_650 = SM_FB_asymmetry_bin_mtt_550_650*SM_FB_asymmetry_deno_bin_mtt_550_650;
        
        double SM_sigma_pos_bin_mtt_550_650 =0.5*(SM_FB_asymmetry_num_bin_mtt_550_650+SM_FB_asymmetry_deno_bin_mtt_550_650);
        double SM_sigma_neg_bin_mtt_550_650 =0.5*(SM_FB_asymmetry_deno_bin_mtt_550_650-SM_FB_asymmetry_num_bin_mtt_550_650);

        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            
            
            double sigma_pos_bin_mtt_550_650_madgraph = 0.216436;
            double sigma_pos_bin_mtt_550_650_NP = -0.001345*ewgc("CG")+0.002993*ewgc("Cqd8R",2,2,0,0)
            +0.098574*ewgc("Cqq1R",0,2,2,0)+0.119856*ewgc("Cqq3R",0,2,2,0)+0.000356*ewgc("Cqq3R",1,2,2,1)
            +0.026186*ewgc("Cqu8R",0,0,2,2)+0.023259*ewgc("Cqu8R",2,2,0,0)+0.002973*ewgc("Cud8R",2,2,0,0)
            -0.057346*ewgc("CuGR",2,2)+0.095602*ewgc("CuuR",0,2,2,0);
            double sigma_neg_bin_mtt_550_650_madgraph = 0.216949;
            double sigma_neg_bin_mtt_550_650_NP = -0.001414*ewgc("CG")+0.002846*ewgc("Cqd8R",2,2,0,0)
            +0.098612*ewgc("Cqq1R",0,2,2,0)+0.120103*ewgc("Cqq3R",0,2,2,0)+0.000216*ewgc("Cqq3R",1,2,2,1)
            +0.025800*ewgc("Cqu8R",0,0,2,2)+0.023527*ewgc("Cqu8R",2,2,0,0)+0.002835*ewgc("Cud8R",2,2,0,0)
            -0.057275*ewgc("CuGR",2,2)+0.095612*ewgc("CuuR",0,2,2,0);
            
            double sigma_pos_bin_mtt_550_650_NP_Corrected = SM_sigma_pos_bin_mtt_550_650*sigma_pos_bin_mtt_550_650_NP/sigma_pos_bin_mtt_550_650_madgraph;
            double sigma_neg_bin_mtt_550_650_NP_Corrected = SM_sigma_neg_bin_mtt_550_650*sigma_neg_bin_mtt_550_650_NP/sigma_neg_bin_mtt_550_650_madgraph;
            
            double NP_FB_asymmetry_num_bin_mtt_550_650 = sigma_pos_bin_mtt_550_650_NP_Corrected - sigma_neg_bin_mtt_550_650_NP_Corrected;
            double NP_FB_asymmetry_deno_bin_mtt_550_650 = sigma_pos_bin_mtt_550_650_NP_Corrected + sigma_neg_bin_mtt_550_650_NP_Corrected;;
            
            return  SM_FB_asymmetry_bin_mtt_550_650*(1+(NP_FB_asymmetry_num_bin_mtt_550_650-NP_FB_asymmetry_deno_bin_mtt_550_650)/SM_FB_asymmetry_deno_bin_mtt_550_650);            
        
        }
        
    } else if(b_min == 650 && b_max == 750){
        
        
        double SM_FB_asymmetry_bin_mtt_650_750 = SM.getOptionalParameter("SM_FB_asymmetry_bin_mtt_650_750");
        double SM_FB_asymmetry_deno_bin_mtt_650_750 = SM.getOptionalParameter("SM_FB_asymmetry_deno_bin_mtt_650_750");
        double SM_FB_asymmetry_num_bin_mtt_650_750 = SM_FB_asymmetry_bin_mtt_650_750*SM_FB_asymmetry_deno_bin_mtt_650_750;
        
        double SM_sigma_pos_bin_mtt_650_750 =0.5*(SM_FB_asymmetry_num_bin_mtt_650_750+SM_FB_asymmetry_deno_bin_mtt_650_750);
        double SM_sigma_neg_bin_mtt_650_750 =0.5*(SM_FB_asymmetry_deno_bin_mtt_650_750-SM_FB_asymmetry_num_bin_mtt_650_750);

        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            
            
            double sigma_pos_bin_mtt_650_750_madgraph = 0.097727;
            double sigma_pos_bin_mtt_650_750_NP = -0.000271*ewgc("CG")+0.001360*ewgc("Cqd8R",2,2,0,0)
            +0.073375*ewgc("Cqq1R",0,2,2,0)+0.084010*ewgc("Cqq3R",0,2,2,0)+0.000196*ewgc("Cqq3R",1,2,2,1)
            +0.018728*ewgc("Cqu8R",0,0,2,2)+0.017419*ewgc("Cqu8R",2,2,0,0)+0.001357*ewgc("Cud8R",2,2,0,0)
            -0.026810*ewgc("CuGR",2,2)+0.071319*ewgc("CuuR",0,2,2,0);
            double sigma_neg_bin_mtt_650_750_madgraph = 0.097766;
            double sigma_neg_bin_mtt_650_750_NP = -0.000309*ewgc("CG")+0.001327*ewgc("Cqd8R",2,2,0,0)
            +0.073361*ewgc("Cqq1R",0,2,2,0)+0.083778*ewgc("Cqq3R",0,2,2,0)+0.000188*ewgc("Cqq3R",1,2,2,1)
            +0.018756*ewgc("Cqu8R",0,0,2,2)+0.017360*ewgc("Cqu8R",2,2,0,0)+0.001327*ewgc("Cud8R",2,2,0,0)
            -0.026852*ewgc("CuGR",2,2)+0.071283*ewgc("CuuR",0,2,2,0);
            
            double sigma_pos_bin_mtt_650_750_NP_Corrected = SM_sigma_pos_bin_mtt_650_750*sigma_pos_bin_mtt_650_750_NP/sigma_pos_bin_mtt_650_750_madgraph;
            double sigma_neg_bin_mtt_650_750_NP_Corrected = SM_sigma_neg_bin_mtt_650_750*sigma_neg_bin_mtt_650_750_NP/sigma_neg_bin_mtt_650_750_madgraph;
            
            double NP_FB_asymmetry_num_bin_mtt_650_750 = sigma_pos_bin_mtt_650_750_NP_Corrected - sigma_neg_bin_mtt_650_750_NP_Corrected;
            double NP_FB_asymmetry_deno_bin_mtt_650_750 = sigma_pos_bin_mtt_650_750_NP_Corrected + sigma_neg_bin_mtt_650_750_NP_Corrected;;
            
            return  SM_FB_asymmetry_bin_mtt_650_750*(1+(NP_FB_asymmetry_num_bin_mtt_650_750-NP_FB_asymmetry_deno_bin_mtt_650_750)/SM_FB_asymmetry_deno_bin_mtt_650_750);            
        
        }
        
    } else {
        throw std::runtime_error("\nERROR: Please specify a correct binning range for FB_asymmetry_Tevatron_tt_diff_mtt_LO.\n");
    }
    
    
    
    
    
    
}






////// ttbar differential cross section ///////////////////////////////////

sigma_tt_diff_LO::sigma_tt_diff_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{

    setParametersForObservable(make_vector<std::string>() << "SM_sigma_tt_bin_250_400" << "SM_sigma_tt_bin_400_480" <<
            "SM_sigma_tt_bin_480_560" << "SM_sigma_tt_bin_560_640" << "SM_sigma_tt_bin_640_720" << "SM_sigma_tt_bin_720_800" <<
            "SM_sigma_tt_bin_800_900" << "SM_sigma_tt_bin_900_1000" << "SM_sigma_tt_bin_1000_1150" << "SM_sigma_tt_bin_1150_1300" <<
            "SM_sigma_tt_bin_1300_1500" << "SM_sigma_tt_bin_1500_1700" << "SM_sigma_tt_bin_1700_2000" << "SM_sigma_tt_bin_2000_2300" <<
            "SM_sigma_tt_bin_2300_3500");
            //"SM_sigma_tt_bin_2300_2600" << "SM_sigma_tt_bin_2600_3000" << "SM_sigma_tt_bin_3000_3500" << "SM_sigma_tt_bin_3500_4000");
    
};

double sigma_tt_diff_LO::computeThValue()
{
    
    b_min = getBinMin();
    b_max = getBinMax();
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    
    //double C_tG = ewgc("CuGR",2,2);

    
    
    
    if(b_min == 250 && b_max == 400){
        
        double SM_sigma_tt_bin_250_400 = SM.getOptionalParameter("SM_sigma_tt_bin_250_400");
        //double sigma_tt_bin_250_400_madgraph = 105600.0;//fb maybe over the bin width? Check!
        double sigma_tt_bin_250_400_madgraph = 95.612100;//pb
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            

            
            return SM_sigma_tt_bin_250_400 + (-2.422920*ewgc("CG")+0.401694*ewgc("Cqd8R",2,2,0,0)+0.123768*ewgc("Cqd8R",2,2,1,1)
                    +2.248510*ewgc("Cqq1R",0,2,2,0)+0.184272*ewgc("Cqq1R",1,2,2,1)+4.951130*ewgc("Cqq3R",0,2,2,0)
                    +0.780684*ewgc("Cqq3R",1,2,2,1)+0.926298*ewgc("Cqu8R",0,0,2,2)+0.152874*ewgc("Cqu8R",1,1,2,2)
                    +0.575544*ewgc("Cqu8R",2,2,0,0)+0.079620*ewgc("Cqu8R",2,2,1,1)+0.404088*ewgc("Cud8R",2,2,0,0)
                    +0.127740*ewgc("Cud8R",2,2,1,1)-31.370400*ewgc("CuGR",2,2)+2.216290*ewgc("CuuR",0,2,2,0)
                    +0.180834*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_250_400/sigma_tt_bin_250_400_madgraph);
            
        }
        
    } else if(b_min == 400 && b_max == 480){
        
        double SM_sigma_tt_bin_400_480 = SM.getOptionalParameter("SM_sigma_tt_bin_400_480");
        double sigma_tt_bin_400_480_madgraph = 147.218000;//pb
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_400_480 + (-8.063800*ewgc("CG")+0.537774*ewgc("Cqd8R",2,2,0,0)+0.102036*ewgc("Cqd8R",2,2,1,1)
                    +3.659260*ewgc("Cqq1R",0,2,2,0)+0.168744*ewgc("Cqq1R",1,2,2,1)+7.940650*ewgc("Cqq3R",0,2,2,0)
                    +1.036730*ewgc("Cqq3R",1,2,2,1)+1.420910*ewgc("Cqu8R",0,0,2,2)+0.147192*ewgc("Cqu8R",1,1,2,2)
                    +0.859650*ewgc("Cqu8R",2,2,0,0)+0.036930*ewgc("Cqu8R",2,2,1,1)+0.537786*ewgc("Cud8R",2,2,0,0)
                    +0.101004*ewgc("Cud8R",2,2,1,1)-42.879900*ewgc("CuGR",2,2)+3.585550*ewgc("CuuR",0,2,2,0)
                    +0.166566*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_400_480/sigma_tt_bin_400_480_madgraph);
            
        }
        
    } else if(b_min == 480 && b_max == 560){
        
        double SM_sigma_tt_bin_480_560 = SM.getOptionalParameter("SM_sigma_tt_bin_480_560");
        double sigma_tt_bin_480_560_madgraph = 93.593900;//pb
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_480_560+(-7.025760*ewgc("CG")+0.449310*ewgc("Cqd8R",2,2,0,0)+0.079662*ewgc("Cqd8R",2,2,1,1)
                    +2.769450*ewgc("Cqq1R",0,2,2,0)+0.129120*ewgc("Cqq1R",1,2,2,1)+6.058480*ewgc("Cqq3R",0,2,2,0)
                    +0.711270*ewgc("Cqq3R",1,2,2,1)+1.107320*ewgc("Cqu8R",0,0,2,2)+0.113052*ewgc("Cqu8R",1,1,2,2)
                    +0.676488*ewgc("Cqu8R",2,2,0,0)+0.029088*ewgc("Cqu8R",2,2,1,1)+0.448860*ewgc("Cud8R",2,2,0,0)
                    +0.080076*ewgc("Cud8R",2,2,1,1)-26.003200*ewgc("CuGR",2,2)+2.714080*ewgc("CuuR",0,2,2,0)
                    +0.128328*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_480_560/sigma_tt_bin_480_560_madgraph);
            
        }
        
    } else if(b_min == 560 && b_max == 640){
        
        double SM_sigma_tt_bin_560_640 = SM.getOptionalParameter("SM_sigma_tt_bin_560_640");
        double sigma_tt_bin_560_640_madgraph = 55.041700;//pb
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_560_640+(-4.951430*ewgc("CG")+0.305342*ewgc("Cqd8R",2,2,0,0)+0.048212*ewgc("Cqd8R",2,2,1,1)
                    +2.089870*ewgc("Cqq1R",0,2,2,0)+0.073246*ewgc("Cqq1R",1,2,2,1)+4.469060*ewgc("Cqq3R",0,2,2,0)
                    +0.460417*ewgc("Cqq3R",1,2,2,1)+0.799277*ewgc("Cqu8R",0,0,2,2)+0.062208*ewgc("Cqu8R",1,1,2,2)
                    +0.489781*ewgc("Cqu8R",2,2,0,0)+0.018157*ewgc("Cqu8R",2,2,1,1)+0.304480*ewgc("Cud8R",2,2,0,0)
                    +0.048640*ewgc("Cud8R",2,2,1,1)-15.174600*ewgc("CuGR",2,2)+2.032110*ewgc("CuuR",0,2,2,0)
                    +0.070646*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_560_640/sigma_tt_bin_560_640_madgraph);
            
        }
        
    } else if(b_min == 640 && b_max == 720){
        
        double SM_sigma_tt_bin_640_720 = SM.getOptionalParameter("SM_sigma_tt_bin_640_720");
        double sigma_tt_bin_640_720_madgraph = 32.530700;//pb
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_640_720+(-3.219570*ewgc("CG")+0.232042*ewgc("Cqd8R",2,2,0,0)+0.037100*ewgc("Cqd8R",2,2,1,1)
                    +1.550940*ewgc("Cqq1R",0,2,2,0)+0.053066*ewgc("Cqq1R",1,2,2,1)+3.301500*ewgc("Cqq3R",0,2,2,0)
                    +0.307033*ewgc("Cqq3R",1,2,2,1)+0.604172*ewgc("Cqu8R",0,0,2,2)+0.049607*ewgc("Cqu8R",1,1,2,2)
                    +0.375725*ewgc("Cqu8R",2,2,0,0)+0.014703*ewgc("Cqu8R",2,2,1,1)+0.232665*ewgc("Cud8R",2,2,0,0)
                    +0.036439*ewgc("Cud8R",2,2,1,1)-8.998020*ewgc("CuGR",2,2)+1.513220*ewgc("CuuR",0,2,2,0)
                    +0.052060*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_640_720/sigma_tt_bin_640_720_madgraph);
            
        }
        
    } else if(b_min == 720 && b_max == 800){
        
        double SM_sigma_tt_bin_720_800 = SM.getOptionalParameter("SM_sigma_tt_bin_720_800");
        double sigma_tt_bin_720_800_madgraph = 19.672800;//pb
        
        //PROBABLY THE OPERATORS PURELY FROM THE THIRD FAMILY NEED TO BE NEGLECTED SINCE THEIR CONTRIBUTION IS REALLY SMALL
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_720_800+(-2.083310*ewgc("CG")+0.175894*ewgc("Cqd8R",2,2,0,0)+0.025732*ewgc("Cqd8R",2,2,1,1)
                    +1.182780*ewgc("Cqq1R",0,2,2,0)+0.038678*ewgc("Cqq1R",1,2,2,1)+2.528020*ewgc("Cqq3R",0,2,2,0)
                    +0.209536*ewgc("Cqq3R",1,2,2,1)+0.457521*ewgc("Cqu8R",0,0,2,2)+0.034597*ewgc("Cqu8R",1,1,2,2)
                    +0.282292*ewgc("Cqu8R",2,2,0,0)+0.011773*ewgc("Cqu8R",2,2,1,1)+0.176461*ewgc("Cud8R",2,2,0,0)
                    +0.026183*ewgc("Cud8R",2,2,1,1)-5.490750*ewgc("CuGR",2,2)+1.152010*ewgc("CuuR",0,2,2,0)
                    +0.037207*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_720_800/sigma_tt_bin_720_800_madgraph);
            
        }
        
    } else if(b_min == 800 && b_max == 900){
        
        double SM_sigma_tt_bin_800_900 = SM.getOptionalParameter("SM_sigma_tt_bin_800_900");
        double sigma_tt_bin_800_900_madgraph = 14.503700;//pb
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_800_900+(-1.630550*ewgc("CG")+0.163468*ewgc("Cqd8R",2,2,0,0)+0.019984*ewgc("Cqd8R",2,2,1,1)
                    +1.108320*ewgc("Cqq1R",0,2,2,0)+0.030141*ewgc("Cqq1R",1,2,2,1)+2.335190*ewgc("Cqq3R",0,2,2,0)
                    +0.177932*ewgc("Cqq3R",1,2,2,1)+0.423182*ewgc("Cqu8R",0,0,2,2)+0.026737*ewgc("Cqu8R",1,1,2,2)
                    +0.263074*ewgc("Cqu8R",2,2,0,0)+0.007495*ewgc("Cqu8R",2,2,1,1)+0.162380*ewgc("Cud8R",2,2,0,0)
                    +0.019683*ewgc("Cud8R",2,2,1,1)-4.096130*ewgc("CuGR",2,2)+1.080140*ewgc("CuuR",0,2,2,0)
                    +0.029855*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_800_900/sigma_tt_bin_800_900_madgraph);
            
        }
        
    } else if(b_min == 900 && b_max == 1000){
        
        double SM_sigma_tt_bin_900_1000 = SM.getOptionalParameter("SM_sigma_tt_bin_900_1000");
        double sigma_tt_bin_900_1000_madgraph = 8.319110;
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_900_1000+(-0.968369*ewgc("CG")+0.119704*ewgc("Cqd8R",2,2,0,0)+0.014122*ewgc("Cqd8R",2,2,1,1)
                    +0.816250*ewgc("Cqq1R",0,2,2,0)+0.021400*ewgc("Cqq1R",1,2,2,1)+1.722240*ewgc("Cqq3R",0,2,2,0)
                    +0.118511*ewgc("Cqq3R",1,2,2,1)+0.313127*ewgc("Cqu8R",0,0,2,2)+0.019055*ewgc("Cqu8R",1,1,2,2)
                    +0.193743*ewgc("Cqu8R",2,2,0,0)+0.005861*ewgc("Cqu8R",2,2,1,1)+0.118769*ewgc("Cud8R",2,2,0,0)
                    +0.014256*ewgc("Cud8R",2,2,1,1)-2.388600*ewgc("CuGR",2,2)+0.792650*ewgc("CuuR",0,2,2,0)
                    +0.020774*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_900_1000/sigma_tt_bin_900_1000_madgraph);
            
        }
        
    } else if(b_min == 1000 && b_max == 1150){
        
        double SM_sigma_tt_bin_1000_1150 = SM.getOptionalParameter("SM_sigma_tt_bin_1000_1150");
        double sigma_tt_bin_1000_1150_madgraph = 6.639310;
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_1000_1150+(-0.804304*ewgc("CG")+0.123780*ewgc("Cqd8R",2,2,0,0)+0.012627*ewgc("Cqd8R",2,2,1,1)
                    +0.861600*ewgc("Cqq1R",0,2,2,0)+0.019534*ewgc("Cqq1R",1,2,2,1)+1.803180*ewgc("Cqq3R",0,2,2,0)
                    +0.110947*ewgc("Cqq3R",1,2,2,1)+0.330188*ewgc("Cqu8R",0,0,2,2)+0.016923*ewgc("Cqu8R",1,1,2,2)
                    +0.204389*ewgc("Cqu8R",2,2,0,0)+0.004738*ewgc("Cqu8R",2,2,1,1)+0.124652*ewgc("Cud8R",2,2,0,0)
                    +0.012582*ewgc("Cud8R",2,2,1,1)-1.942700*ewgc("CuGR",2,2)+0.840043*ewgc("CuuR",0,2,2,0)
                    +0.018953*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_1000_1150/sigma_tt_bin_1000_1150_madgraph);
            
        }
        
    } else if(b_min == 1150 && b_max == 1300){
        
        double SM_sigma_tt_bin_1150_1300 = SM.getOptionalParameter("SM_sigma_tt_bin_1150_1300");
        double sigma_tt_bin_1150_1300_madgraph = 3.246500;
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_1150_1300+(-0.401966*ewgc("CG")+0.083879*ewgc("Cqd8R",2,2,0,0)+0.007322*ewgc("Cqd8R",2,2,1,1)
                    +0.586193*ewgc("Cqq1R",0,2,2,0)+0.011479*ewgc("Cqq1R",1,2,2,1)+1.212270*ewgc("Cqq3R",0,2,2,0)
                    +0.066123*ewgc("Cqq3R",1,2,2,1)+0.220114*ewgc("Cqu8R",0,0,2,2)+0.009786*ewgc("Cqu8R",1,1,2,2)
                    +0.138518*ewgc("Cqu8R",2,2,0,0)+0.002758*ewgc("Cqu8R",2,2,1,1)+0.083424*ewgc("Cud8R",2,2,0,0)
                    +0.007362*ewgc("Cud8R",2,2,1,1)-0.974239*ewgc("CuGR",2,2)+0.569482*ewgc("CuuR",0,2,2,0)
                    +0.011161*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_1150_1300/sigma_tt_bin_1150_1300_madgraph);
            
        }
        
    } else if(b_min == 1300 && b_max == 1500){
        
        double SM_sigma_tt_bin_1300_1500 = SM.getOptionalParameter("SM_sigma_tt_bin_1300_1500");
        double sigma_tt_bin_1300_1500_madgraph = 2.043090;
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_1300_1500+(-0.257644*ewgc("CG")+0.071800*ewgc("Cqd8R",2,2,0,0)+0.005583*ewgc("Cqd8R",2,2,1,1)
                    +0.514089*ewgc("Cqq1R",0,2,2,0)+0.009040*ewgc("Cqq1R",1,2,2,1)+1.057920*ewgc("Cqq3R",0,2,2,0)
                    +0.049771*ewgc("Cqq3R",1,2,2,1)+0.193778*ewgc("Cqu8R",0,0,2,2)+0.007659*ewgc("Cqu8R",1,1,2,2)
                    +0.121016*ewgc("Cqu8R",2,2,0,0)+0.002184*ewgc("Cqu8R",2,2,1,1)+0.071700*ewgc("Cud8R",2,2,0,0)
                    +0.005503*ewgc("Cud8R",2,2,1,1)-0.630898*ewgc("CuGR",2,2)+0.499461*ewgc("CuuR",0,2,2,0)
                    +0.008718*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_1300_1500/sigma_tt_bin_1300_1500_madgraph);
            
        }
        
    } else if(b_min == 1500 && b_max == 1700){
        
        double SM_sigma_tt_bin_1500_1700 = SM.getOptionalParameter("SM_sigma_tt_bin_1500_1700");
        double sigma_tt_bin_1500_1700_madgraph = 0.914445;
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_1500_1700+(-0.117785*ewgc("CG")+0.045019*ewgc("Cqd8R",2,2,0,0)+0.003048*ewgc("Cqd8R",2,2,1,1)
                    +0.324342*ewgc("Cqq1R",0,2,2,0)+0.005084*ewgc("Cqq1R",1,2,2,1)+0.662237*ewgc("Cqq3R",0,2,2,0)
                    +0.028217*ewgc("Cqq3R",1,2,2,1)+0.121878*ewgc("Cqu8R",0,0,2,2)+0.004270*ewgc("Cqu8R",1,1,2,2)
                    +0.077000*ewgc("Cqu8R",2,2,0,0)+0.001206*ewgc("Cqu8R",2,2,1,1)+0.045112*ewgc("Cud8R",2,2,0,0)
                    +0.003088*ewgc("Cud8R",2,2,1,1)-0.292794*ewgc("CuGR",2,2)+0.315186*ewgc("CuuR",0,2,2,0)
                    +0.004977*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_1500_1700/sigma_tt_bin_1500_1700_madgraph);
            
        }
        
    } else if(b_min == 1700 && b_max == 2000){
        
        double SM_sigma_tt_bin_1700_2000 = SM.getOptionalParameter("SM_sigma_tt_bin_1700_2000");
        double sigma_tt_bin_1700_2000_madgraph = 0.562282;
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_1700_2000+(-0.071302*ewgc("CG")+0.039170*ewgc("Cqd8R",2,2,0,0)+0.002352*ewgc("Cqd8R",2,2,1,1)
                    +0.289186*ewgc("Cqq1R",0,2,2,0)+0.004238*ewgc("Cqq1R",1,2,2,1)+0.584013*ewgc("Cqq3R",0,2,2,0)
                    +0.021609*ewgc("Cqq3R",1,2,2,1)+0.107387*ewgc("Cqu8R",0,0,2,2)+0.003355*ewgc("Cqu8R",1,1,2,2)
                    +0.068348*ewgc("Cqu8R",2,2,0,0)+0.001051*ewgc("Cqu8R",2,2,1,1)+0.039148*ewgc("Cud8R",2,2,0,0)
                    +0.002369*ewgc("Cud8R",2,2,1,1)-0.187937*ewgc("CuGR",2,2)+0.281115*ewgc("CuuR",0,2,2,0)
                    +0.004135*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_1700_2000/sigma_tt_bin_1700_2000_madgraph);
            
        }
        
    } else if(b_min == 2000 && b_max == 2300){
        
        double SM_sigma_tt_bin_2000_2300 = SM.getOptionalParameter("SM_sigma_tt_bin_2000_2300");
        double sigma_tt_bin_2000_2300_madgraph = 0.204084;
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_2000_2300+(-0.025926*ewgc("CG")+0.020907*ewgc("Cqd8R",2,2,0,0)+0.001111*ewgc("Cqd8R",2,2,1,1)
                    +0.158780*ewgc("Cqq1R",0,2,2,0)+0.002134*ewgc("Cqq1R",1,2,2,1)+0.315561*ewgc("Cqq3R",0,2,2,0)
                    +0.010496*ewgc("Cqq3R",1,2,2,1)+0.058108*ewgc("Cqu8R",0,0,2,2)+0.001605*ewgc("Cqu8R",1,1,2,2)
                    +0.037313*ewgc("Cqu8R",2,2,0,0)+0.000506*ewgc("Cqu8R",2,2,1,1)+0.020857*ewgc("Cud8R",2,2,0,0)
                    +0.001103*ewgc("Cud8R",2,2,1,1)-0.072063*ewgc("CuGR",2,2)+0.154056*ewgc("CuuR",0,2,2,0)
                    +0.002073*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_2000_2300/sigma_tt_bin_2000_2300_madgraph);
            
        }
        
    } else if(b_min == 2300 && b_max == 3500){
        
        double SM_sigma_tt_bin_2300_3500 = SM.getOptionalParameter("SM_sigma_tt_bin_2300_3500");
        double sigma_tt_bin_2300_3500_madgraph = 0.140478;
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tt_bin_2300_3500+(-0.016913*ewgc("CG")+0.025555*ewgc("Cqd8R",2,2,0,0)+0.001168*ewgc("Cqd8R",2,2,1,1)
                    +0.211627*ewgc("Cqq1R",0,2,2,0)+0.002920*ewgc("Cqq1R",1,2,2,1)+0.406226*ewgc("Cqq3R",0,2,2,0)
                    +0.011576*ewgc("Cqq3R",1,2,2,1)+0.075650*ewgc("Cqu8R",0,0,2,2)+0.001858*ewgc("Cqu8R",1,1,2,2)
                    +0.049952*ewgc("Cqu8R",2,2,0,0)+0.000687*ewgc("Cqu8R",2,2,1,1)+0.025594*ewgc("Cud8R",2,2,0,0)
                    +0.001165*ewgc("Cud8R",2,2,1,1)-0.054955*ewgc("CuGR",2,2)+0.205602*ewgc("CuuR",0,2,2,0)
                    +0.002840*ewgc("CuuR",1,2,2,1))*(SM_sigma_tt_bin_2300_3500/sigma_tt_bin_2300_3500_madgraph);
            
        }
        
    } else {
        throw std::runtime_error("\nERROR: Please specify a correct binning range for sigma_tt_diff_LO.\n");
    }

}



////// ttbar charge asymmetry differential ///////////////////////////////////

charge_asymmetry_tt_diff_mtt_LO::charge_asymmetry_tt_diff_mtt_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{

    setParametersForObservable(make_vector<std::string>() << "SM_charge_asymmetry_bin_mtt_0_500" << "SM_charge_asymmetry_deno_bin_mtt_0_500"
            << "SM_charge_asymmetry_bin_mtt_500_750" << "SM_charge_asymmetry_deno_bin_mtt_500_750" << "SM_charge_asymmetry_bin_mtt_750_1000" 
            << "SM_charge_asymmetry_deno_bin_mtt_750_1000" << "SM_charge_asymmetry_bin_mtt_1000_1500" << "SM_charge_asymmetry_deno_bin_mtt_1000_1500"
            << "SM_charge_asymmetry_bin_mtt_1500_3000" << "SM_charge_asymmetry_deno_bin_mtt_1500_3000");
            //"SM_sigma_tt_bin_2300_2600" << "SM_sigma_tt_bin_2600_3000" << "SM_sigma_tt_bin_3000_3500" << "SM_sigma_tt_bin_3500_4000");
    
};


double charge_asymmetry_tt_diff_mtt_LO::computeThValue()
{
    
    b_min = getBinMin();
    b_max = getBinMax();
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    


    
    
    
    if(b_min == 0 && b_max == 500){
        
        double SM_charge_asymmetry_bin_mtt_0_500 = SM.getOptionalParameter("SM_charge_asymmetry_bin_mtt_0_500");
        double SM_charge_asymmetry_deno_bin_mtt_0_500 = SM.getOptionalParameter("SM_charge_asymmetry_deno_bin_mtt_0_500");
        double SM_charge_asymmetry_num_bin_mtt_0_500 = SM_charge_asymmetry_bin_mtt_0_500*SM_charge_asymmetry_deno_bin_mtt_0_500;
        
        double SM_sigma_pos_bin_mtt_0_500 =0.5*(SM_charge_asymmetry_num_bin_mtt_0_500+SM_charge_asymmetry_deno_bin_mtt_0_500);
        double SM_sigma_neg_bin_mtt_0_500 =0.5*(SM_charge_asymmetry_deno_bin_mtt_0_500-SM_charge_asymmetry_num_bin_mtt_0_500);

        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            
                    
            double sigma_pos_bin_mtt_0_500_madgraph = 135.533000;
            double sigma_pos_bin_mtt_0_500_NP = -6.478050*ewgc("CG")+0.364812*ewgc("Cqd8R",2,2,0,0)
            +0.065870*ewgc("Cqd8R",2,2,1,1)+4.159410*ewgc("Cqq1R",0,2,2,0)+0.184853*ewgc("Cqq1R",1,2,2,1)
            +8.461010*ewgc("Cqq3R",0,2,2,0)+0.893405*ewgc("Cqq3R",1,2,2,1)+1.126020*ewgc("Cqu8R",0,0,2,2)
            -0.010419*ewgc("Cqu8R",1,1,2,2)+0.588354*ewgc("Cqu8R",2,2,0,0)+-0.002524*ewgc("Cqu8R",2,2,1,1)
            +0.455566*ewgc("Cud8R",2,2,0,0)+0.131078*ewgc("Cud8R",2,2,1,1)-39.064300*ewgc("CuGR",2,2)
            +4.072180*ewgc("CuuR",0,2,2,0)+0.097783*ewgc("CuuR",1,2,2,1);
            double sigma_neg_bin_mtt_0_500_madgraph = 135.300000;
            double sigma_neg_bin_mtt_0_500_NP = -6.358540*ewgc("CG")+0.411874*ewgc("Cqd8R",2,2,0,0)
            +-0.006404*ewgc("Cqd8R",2,2,1,1)+2.642460*ewgc("Cqq1R",0,2,2,0)+0.063511*ewgc("Cqq1R",1,2,2,1)
            +5.970760*ewgc("Cqq3R",0,2,2,0)+0.714859*ewgc("Cqq3R",1,2,2,1)+1.615130*ewgc("Cqu8R",0,0,2,2)
            -0.079004*ewgc("Cqu8R",1,1,2,2)+0.944519*ewgc("Cqu8R",2,2,0,0)+0.028645*ewgc("Cqu8R",2,2,1,1)
            +0.301135*ewgc("Cud8R",2,2,0,0)+-0.078071*ewgc("Cud8R",2,2,1,1)-39.340100*ewgc("CuGR",2,2)
            +2.559810*ewgc("CuuR",0,2,2,0)+-0.060753*ewgc("CuuR",1,2,2,1);
;
            
            double sigma_pos_bin_mtt_0_500_NP_Corrected = SM_sigma_pos_bin_mtt_0_500*sigma_pos_bin_mtt_0_500_NP/sigma_pos_bin_mtt_0_500_madgraph;
            double sigma_neg_bin_mtt_0_500_NP_Corrected = SM_sigma_neg_bin_mtt_0_500*sigma_neg_bin_mtt_0_500_NP/sigma_neg_bin_mtt_0_500_madgraph;
            
            double NP_charge_asymmetry_num_bin_mtt_0_500 = sigma_pos_bin_mtt_0_500_NP_Corrected - sigma_neg_bin_mtt_0_500_NP_Corrected;
            double NP_charge_asymmetry_deno_bin_mtt_0_500 = sigma_pos_bin_mtt_0_500_NP_Corrected + sigma_neg_bin_mtt_0_500_NP_Corrected;;
            
            return  SM_charge_asymmetry_bin_mtt_0_500*(1+(NP_charge_asymmetry_num_bin_mtt_0_500-NP_charge_asymmetry_deno_bin_mtt_0_500)/SM_charge_asymmetry_deno_bin_mtt_0_500);            
        
        }
        
    } else if(b_min == 500 && b_max == 750){
        
        double SM_charge_asymmetry_bin_mtt_500_750 = SM.getOptionalParameter("SM_charge_asymmetry_bin_mtt_500_750");
        double SM_charge_asymmetry_deno_bin_mtt_500_750 = SM.getOptionalParameter("SM_charge_asymmetry_deno_bin_mtt_500_750");
        double SM_charge_asymmetry_num_bin_mtt_500_750 = SM_charge_asymmetry_bin_mtt_500_750*SM_charge_asymmetry_deno_bin_mtt_500_750;
        
        
        double SM_sigma_pos_bin_mtt_500_750 =0.5*(SM_charge_asymmetry_num_bin_mtt_500_750+SM_charge_asymmetry_deno_bin_mtt_500_750);
        double SM_sigma_neg_bin_mtt_500_750 =0.5*(SM_charge_asymmetry_deno_bin_mtt_500_750-SM_charge_asymmetry_num_bin_mtt_500_750);

        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            
            
            
            double sigma_pos_bin_mtt_500_750_madgraph = 80.589400;
            double sigma_pos_bin_mtt_500_750_NP = -6.999250*ewgc("CG")+0.386926*ewgc("Cqd8R",2,2,0,0)
            +0.078147*ewgc("Cqd8R",2,2,1,1)+4.115120*ewgc("Cqq1R",0,2,2,0)+0.207149*ewgc("Cqq1R",1,2,2,1)
            +8.367150*ewgc("Cqq3R",0,2,2,0)+0.726869*ewgc("Cqq3R",1,2,2,1)+0.814576*ewgc("Cqu8R",0,0,2,2)
            +0.182552*ewgc("Cqu8R",1,1,2,2)+0.471441*ewgc("Cqu8R",2,2,0,0)+0.020673*ewgc("Cqu8R",2,2,1,1)
            +0.603346*ewgc("Cud8R",2,2,0,0)+0.063159*ewgc("Cud8R",2,2,1,1)-20.819700*ewgc("CuGR",2,2)
            +3.980290*ewgc("CuuR",0,2,2,0)+0.169850*ewgc("CuuR",1,2,2,1);
;
            double sigma_neg_bin_mtt_500_750_madgraph = 80.891300;
            double sigma_neg_bin_mtt_500_750_NP = -7.057070*ewgc("CG")+0.573031*ewgc("Cqd8R",2,2,0,0)
            -0.004786*ewgc("Cqd8R",2,2,1,1)+2.052850*ewgc("Cqq1R",0,2,2,0)+0.125976*ewgc("Cqq1R",1,2,2,1)
            +4.836950*ewgc("Cqq3R",0,2,2,0)+0.711224*ewgc("Cqq3R",1,2,2,1)+1.470530*ewgc("Cqu8R",0,0,2,2)
            +0.069589*ewgc("Cqu8R",1,1,2,2)+0.938294*ewgc("Cqu8R",2,2,0,0)+-0.045546*ewgc("Cqu8R",2,2,1,1)
            +0.347501*ewgc("Cud8R",2,2,0,0)+0.011230*ewgc("Cud8R",2,2,1,1)+-20.768900*ewgc("CuGR",2,2)
            +1.942090*ewgc("CuuR",0,2,2,0)+0.161845*ewgc("CuuR",1,2,2,1);
            
            double sigma_pos_bin_mtt_500_750_NP_Corrected = SM_sigma_pos_bin_mtt_500_750*sigma_pos_bin_mtt_500_750_NP/sigma_pos_bin_mtt_500_750_madgraph;
            double sigma_neg_bin_mtt_500_750_NP_Corrected = SM_sigma_neg_bin_mtt_500_750*sigma_neg_bin_mtt_500_750_NP/sigma_neg_bin_mtt_500_750_madgraph;
            
            double NP_charge_asymmetry_num_bin_mtt_500_750 = sigma_pos_bin_mtt_500_750_NP_Corrected - sigma_neg_bin_mtt_500_750_NP_Corrected;
            double NP_charge_asymmetry_deno_bin_mtt_500_750 = sigma_pos_bin_mtt_500_750_NP_Corrected + sigma_neg_bin_mtt_500_750_NP_Corrected;;
            
            return  SM_charge_asymmetry_bin_mtt_500_750*(1+(NP_charge_asymmetry_num_bin_mtt_500_750-NP_charge_asymmetry_deno_bin_mtt_500_750)/SM_charge_asymmetry_deno_bin_mtt_500_750);            
        
            
            
            
            
        }
        
    }  else if(b_min == 750 && b_max == 1000){
        
        
        double SM_charge_asymmetry_deno_bin_mtt_750_1000 = SM.getOptionalParameter("SM_charge_asymmetry_deno_bin_mtt_750_1000");
        double SM_charge_asymmetry_bin_mtt_750_1000 = SM.getOptionalParameter("SM_charge_asymmetry_bin_mtt_750_1000");
        double SM_charge_asymmetry_num_bin_mtt_750_1000 = SM_charge_asymmetry_bin_mtt_750_1000*SM_charge_asymmetry_deno_bin_mtt_750_1000;
        
        double SM_sigma_pos_bin_mtt_750_1000 =0.5*(SM_charge_asymmetry_num_bin_mtt_750_1000+SM_charge_asymmetry_deno_bin_mtt_750_1000);
        double SM_sigma_neg_bin_mtt_750_1000 =0.5*(SM_charge_asymmetry_deno_bin_mtt_750_1000-SM_charge_asymmetry_num_bin_mtt_750_1000);

        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            
            
            
            double sigma_pos_bin_mtt_750_1000_madgraph = 16.986900;
            double sigma_pos_bin_mtt_750_1000_NP = -1.924360*ewgc("CG")+0.144619*ewgc("Cqd8R",2,2,0,0)
            +0.015897*ewgc("Cqd8R",2,2,1,1)+1.863020*ewgc("Cqq1R",0,2,2,0)+0.031168*ewgc("Cqq1R",1,2,2,1)
            +3.676260*ewgc("Cqq3R",0,2,2,0)+0.245826*ewgc("Cqq3R",1,2,2,1)+0.316581*ewgc("Cqu8R",0,0,2,2)
            +0.022092*ewgc("Cqu8R",1,1,2,2)+0.190067*ewgc("Cqu8R",2,2,0,0)+0.021485*ewgc("Cqu8R",2,2,1,1)
            +0.258731*ewgc("Cud8R",2,2,0,0)+0.013146*ewgc("Cud8R",2,2,1,1)-4.307000*ewgc("CuGR",2,2)
            +1.792720*ewgc("CuuR",0,2,2,0)+0.019910*ewgc("CuuR",1,2,2,1);
            
            double sigma_neg_bin_mtt_750_1000_madgraph = 16.965400;
            double sigma_neg_bin_mtt_750_1000_NP = -1.909310*ewgc("CG")+0.253028*ewgc("Cqd8R",2,2,0,0)
            +0.026868*ewgc("Cqd8R",2,2,1,1)+0.775801*ewgc("Cqq1R",0,2,2,0)+0.021341*ewgc("Cqq1R",1,2,2,1)
            +1.850950*ewgc("Cqq3R",0,2,2,0)+0.208119*ewgc("Cqq3R",1,2,2,1)+0.666539*ewgc("Cqu8R",0,0,2,2)
            +0.038662*ewgc("Cqu8R",1,1,2,2)+0.437622*ewgc("Cqu8R",2,2,0,0)+0.027679*ewgc("Cqu8R",2,2,1,1)
            +0.143565*ewgc("Cud8R",2,2,0,0)+0.028559*ewgc("Cud8R",2,2,1,1)+-4.304670*ewgc("CuGR",2,2)
            +0.748939*ewgc("CuuR",0,2,2,0)+0.029156*ewgc("CuuR",1,2,2,1);
            
            double sigma_pos_bin_mtt_750_1000_NP_Corrected = SM_sigma_pos_bin_mtt_750_1000*sigma_pos_bin_mtt_750_1000_NP/sigma_pos_bin_mtt_750_1000_madgraph;
            double sigma_neg_bin_mtt_750_1000_NP_Corrected = SM_sigma_neg_bin_mtt_750_1000*sigma_neg_bin_mtt_750_1000_NP/sigma_neg_bin_mtt_750_1000_madgraph;
            
            double NP_charge_asymmetry_num_bin_mtt_750_1000 = sigma_pos_bin_mtt_750_1000_NP_Corrected - sigma_neg_bin_mtt_750_1000_NP_Corrected;
            double NP_charge_asymmetry_deno_bin_mtt_750_1000 = sigma_pos_bin_mtt_750_1000_NP_Corrected + sigma_neg_bin_mtt_750_1000_NP_Corrected;;
            
            return  SM_charge_asymmetry_bin_mtt_750_1000*(1+(NP_charge_asymmetry_num_bin_mtt_750_1000-NP_charge_asymmetry_deno_bin_mtt_750_1000)/SM_charge_asymmetry_deno_bin_mtt_750_1000);            
        
            
            
            
            
        }
        
    }  else if(b_min == 1000 && b_max == 1500){
        
        
        double SM_charge_asymmetry_deno_bin_mtt_1000_1500 = SM.getOptionalParameter("SM_charge_asymmetry_deno_bin_mtt_1000_1500");
        double SM_charge_asymmetry_bin_mtt_1000_1500 = SM.getOptionalParameter("SM_charge_asymmetry_bin_mtt_1000_1500");
        double SM_charge_asymmetry_num_bin_mtt_1000_1500 = SM_charge_asymmetry_bin_mtt_1000_1500*SM_charge_asymmetry_deno_bin_mtt_1000_1500;
        
        
        double SM_sigma_pos_bin_mtt_1000_1500 =0.5*(SM_charge_asymmetry_num_bin_mtt_1000_1500+SM_charge_asymmetry_deno_bin_mtt_1000_1500);
        double SM_sigma_neg_bin_mtt_1000_1500 =0.5*(SM_charge_asymmetry_deno_bin_mtt_1000_1500-SM_charge_asymmetry_num_bin_mtt_1000_1500);

        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            
            double sigma_pos_bin_mtt_1000_1500_madgraph = 5.965330;
            double sigma_pos_bin_mtt_1000_1500_NP = -0.732765*ewgc("CG")+0.095774*ewgc("Cqd8R",2,2,0,0)
            +0.009861*ewgc("Cqd8R",2,2,1,1)+1.407820*ewgc("Cqq1R",0,2,2,0)+0.023055*ewgc("Cqq1R",1,2,2,1)
            +2.789740*ewgc("Cqq3R",0,2,2,0)+0.124751*ewgc("Cqq3R",1,2,2,1)+0.226047*ewgc("Cqu8R",0,0,2,2)
            +0.012025*ewgc("Cqu8R",1,1,2,2)+0.132009*ewgc("Cqu8R",2,2,0,0)+0.002076*ewgc("Cqu8R",2,2,1,1)
            +0.176967*ewgc("Cud8R",2,2,0,0)+0.014820*ewgc("Cud8R",2,2,1,1)-1.511020*ewgc("CuGR",2,2)
            +1.381670*ewgc("CuuR",0,2,2,0)+0.022990*ewgc("CuuR",1,2,2,1);
            double sigma_neg_bin_mtt_1000_1500_madgraph = 5.963920;
            double sigma_neg_bin_mtt_1000_1500_NP = -0.734104*ewgc("CG")+0.177167*ewgc("Cqd8R",2,2,0,0)
            +0.016263*ewgc("Cqd8R",2,2,1,1)+0.546178*ewgc("Cqq1R",0,2,2,0)+0.024062*ewgc("Cqq1R",1,2,2,1)
            +1.297260*ewgc("Cqq3R",0,2,2,0)+0.100018*ewgc("Cqq3R",1,2,2,1)+0.517319*ewgc("Cqu8R",0,0,2,2)
            +0.016952*ewgc("Cqu8R",1,1,2,2)+0.336176*ewgc("Cqu8R",2,2,0,0)+0.003311*ewgc("Cqu8R",2,2,1,1)
            +0.095957*ewgc("Cud8R",2,2,0,0)+0.011525*ewgc("Cud8R",2,2,1,1)-1.511200*ewgc("CuGR",2,2)
            +0.534920*ewgc("CuuR",0,2,2,0)+0.024264*ewgc("CuuR",1,2,2,1);
            
            
            double sigma_pos_bin_mtt_1000_1500_NP_Corrected = SM_sigma_pos_bin_mtt_1000_1500*sigma_pos_bin_mtt_1000_1500_NP/sigma_pos_bin_mtt_1000_1500_madgraph;
            double sigma_neg_bin_mtt_1000_1500_NP_Corrected = SM_sigma_neg_bin_mtt_1000_1500*sigma_neg_bin_mtt_1000_1500_NP/sigma_neg_bin_mtt_1000_1500_madgraph;
            
            double NP_charge_asymmetry_num_bin_mtt_1000_1500 = sigma_pos_bin_mtt_1000_1500_NP_Corrected - sigma_neg_bin_mtt_1000_1500_NP_Corrected;
            double NP_charge_asymmetry_deno_bin_mtt_1000_1500 = sigma_pos_bin_mtt_1000_1500_NP_Corrected + sigma_neg_bin_mtt_1000_1500_NP_Corrected;;
            
            return  SM_charge_asymmetry_bin_mtt_1000_1500*(1+(NP_charge_asymmetry_num_bin_mtt_1000_1500-NP_charge_asymmetry_deno_bin_mtt_1000_1500)/SM_charge_asymmetry_deno_bin_mtt_1000_1500);            
        
            
            
            
            
        }
        
    }     else if(b_min == 1500 && b_max == 3000){
        
        double SM_charge_asymmetry_bin_mtt_1500_3000 = SM.getOptionalParameter("SM_charge_asymmetry_bin_mtt_1500_3000");
        double SM_charge_asymmetry_deno_bin_mtt_1500_3000 = SM.getOptionalParameter("SM_charge_asymmetry_deno_bin_mtt_1500_3000");
        double SM_charge_asymmetry_num_bin_mtt_1500_3000 = SM_charge_asymmetry_bin_mtt_1500_3000*SM_charge_asymmetry_deno_bin_mtt_1500_3000;
        
        double SM_sigma_pos_bin_mtt_1500_3000 =0.5*(SM_charge_asymmetry_num_bin_mtt_1500_3000+SM_charge_asymmetry_deno_bin_mtt_1500_3000);
        double SM_sigma_neg_bin_mtt_1500_3000 =0.5*(SM_charge_asymmetry_deno_bin_mtt_1500_3000-SM_charge_asymmetry_num_bin_mtt_1500_3000);
        
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            
            
            
            double sigma_pos_bin_mtt_1500_3000_madgraph = 0.910259;
            double sigma_pos_bin_mtt_1500_3000_NP = -0.116441*ewgc("CG")+0.045409*ewgc("Cqd8R",2,2,0,0)
            +0.003096*ewgc("Cqd8R",2,2,1,1)+0.711655*ewgc("Cqq1R",0,2,2,0)+0.007175*ewgc("Cqq1R",1,2,2,1)
            +1.350330*ewgc("Cqq3R",0,2,2,0)+0.039100*ewgc("Cqq3R",1,2,2,1)+0.110131*ewgc("Cqu8R",0,0,2,2)
            +0.005191*ewgc("Cqu8R",1,1,2,2)+0.064112*ewgc("Cqu8R",2,2,0,0)+0.002451*ewgc("Cqu8R",2,2,1,1)
            +0.084721*ewgc("Cud8R",2,2,0,0)+0.004134*ewgc("Cud8R",2,2,1,1)-0.231007*ewgc("CuGR",2,2)
            +0.691483*ewgc("CuuR",0,2,2,0)+0.006844*ewgc("CuuR",1,2,2,1);
            double sigma_neg_bin_mtt_1500_3000_madgraph = 0.909569;
            double sigma_neg_bin_mtt_1500_3000_NP = -0.116979*ewgc("CG")+0.084970*ewgc("Cqd8R",2,2,0,0)
            +0.004067*ewgc("Cqd8R",2,2,1,1)+0.274254*ewgc("Cqq1R",0,2,2,0)+0.007000*ewgc("Cqq1R",1,2,2,1)
            +0.618997*ewgc("Cqq3R",0,2,2,0)+0.032143*ewgc("Cqq3R",1,2,2,1)+0.253632*ewgc("Cqu8R",0,0,2,2)
            +0.006071*ewgc("Cqu8R",1,1,2,2)+0.167569*ewgc("Cqu8R",2,2,0,0)+0.002373*ewgc("Cqu8R",2,2,1,1)
            +0.045316*ewgc("Cud8R",2,2,0,0)+0.003020*ewgc("Cud8R",2,2,1,1)-0.231248*ewgc("CuGR",2,2)
            +0.265616*ewgc("CuuR",0,2,2,0)+0.006959*ewgc("CuuR",1,2,2,1);
            
            
            
            double sigma_pos_bin_mtt_1500_3000_NP_Corrected = SM_sigma_pos_bin_mtt_1500_3000*sigma_pos_bin_mtt_1500_3000_NP/sigma_pos_bin_mtt_1500_3000_madgraph;
            double sigma_neg_bin_mtt_1500_3000_NP_Corrected = SM_sigma_neg_bin_mtt_1500_3000*sigma_neg_bin_mtt_1500_3000_NP/sigma_neg_bin_mtt_1500_3000_madgraph;
            
            double NP_charge_asymmetry_num_bin_mtt_1500_3000 = sigma_pos_bin_mtt_1500_3000_NP_Corrected - sigma_neg_bin_mtt_1500_3000_NP_Corrected;
            double NP_charge_asymmetry_deno_bin_mtt_1500_3000 = sigma_pos_bin_mtt_1500_3000_NP_Corrected + sigma_neg_bin_mtt_1500_3000_NP_Corrected;;
            
            return  SM_charge_asymmetry_bin_mtt_1500_3000*(1+(NP_charge_asymmetry_num_bin_mtt_1500_3000-NP_charge_asymmetry_deno_bin_mtt_1500_3000)/SM_charge_asymmetry_deno_bin_mtt_1500_3000);            
            //return 0.;

        }
        
    }
    
    
    else {
        throw std::runtime_error("\nERROR: Please specify a correct binning range for charge_asymmetry_tt_diff_mtt_LO.\n");
    }

}



sigma_tta_diff_LO_ATLAS_emu_200706946::sigma_tta_diff_LO_ATLAS_emu_200706946(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{

    setParametersForObservable(make_vector<std::string>() << "SM_sigma_tta_bin_20_25_ATLAS_emu" << "SM_sigma_tta_bin_25_30_ATLAS_emu"
            << "SM_sigma_tta_bin_30_35_ATLAS_emu" << "SM_sigma_tta_bin_35_40_ATLAS_emu" << "SM_sigma_tta_bin_40_47_ATLAS_emu" 
            << "SM_sigma_tta_bin_47_55_ATLAS_emu" << "SM_sigma_tta_bin_55_70_ATLAS_emu" << "SM_sigma_tta_bin_70_85_ATLAS_emu"
            << "SM_sigma_tta_bin_85_132_ATLAS_emu" << "SM_sigma_tta_bin_132_180_ATLAS_emu" << "SM_sigma_tta_bin_180_300_ATLAS_emu");

    
};


double sigma_tta_diff_LO_ATLAS_emu_200706946::computeThValue()
{
    
    b_min = getBinMin();
    b_max = getBinMax();
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    

    if(b_min == 20 && b_max == 25){
        
        double SM_sigma_tta_bin_20_25 = SM.getOptionalParameter("SM_sigma_tta_bin_20_25_ATLAS_emu");
        double sigma_tta_bin_20_25_madgraph = 0.247297; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            //There is no dependence on ewgc("Cqd8R",2,2,2,2) neither on ewgc("Cud8R",2,2,2,2) with the precision considered
        
            return SM_sigma_tta_bin_20_25 +(-0.014297*ewgc("CG")+0.002013*ewgc("Cqd8R",2,2,0,0)
                    +0.000242*ewgc("Cqd8R",2,2,1,1)+0.035750*ewgc("Cqq1R",0,2,2,0)
                    +0.001121*ewgc("Cqq1R",1,2,2,1)+0.062345*ewgc("Cqq3R",0,2,2,0)
                    +0.004594*ewgc("Cqq3R",1,2,2,1)+0.015299*ewgc("Cqu8R",0,0,2,2)
                    +0.000694*ewgc("Cqu8R",1,1,2,2)+0.013298*ewgc("Cqu8R",2,2,0,0)
                    +0.000390*ewgc("Cqu8R",2,2,1,1)+-0.002389*ewgc("CuBR",2,2)
                    +0.003507*ewgc("Cud8R",2,2,0,0)+0.000447*ewgc("Cud8R",2,2,1,1)
                    -0.065862*ewgc("CuGR",2,2)+0.034943*ewgc("CuuR",0,2,2,0)
                    +0.001094*ewgc("CuuR",1,2,2,1)+-0.001764*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_20_25/sigma_tta_bin_20_25_madgraph);
        }
    } else if(b_min == 25 && b_max == 30){
        
    
        double SM_sigma_tta_bin_25_30 = SM.getOptionalParameter("SM_sigma_tta_bin_25_30_ATLAS_emu");
        double sigma_tta_bin_25_30_madgraph = 0.187804; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_25_30 +(-0.010872*ewgc("CG")+0.001566*ewgc("Cqd8R",2,2,0,0)
                    +0.000215*ewgc("Cqd8R",2,2,1,1)+0.026408*ewgc("Cqq1R",0,2,2,0)
                    +0.000870*ewgc("Cqq1R",1,2,2,1)+0.047162*ewgc("Cqq3R",0,2,2,0)
                    +0.003478*ewgc("Cqq3R",1,2,2,1)+0.000532*ewgc("Cqu8R",1,1,2,2)
                    +0.010073*ewgc("Cqu8R",2,2,0,0)+0.000333*ewgc("Cqu8R",2,2,1,1)
                    +-0.002372*ewgc("CuBR",2,2)+0.002749*ewgc("Cud8R",2,2,0,0)
                    +0.000356*ewgc("Cud8R",2,2,1,1)-0.049862*ewgc("CuGR",2,2)
                    +0.025851*ewgc("CuuR",0,2,2,0)+0.000867*ewgc("CuuR",1,2,2,1)
                    +-0.001656*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_25_30/sigma_tta_bin_25_30_madgraph);
            
        }
    } else if(b_min == 30 && b_max == 35){
        
    
        double SM_sigma_tta_bin_30_35 = SM.getOptionalParameter("SM_sigma_tta_bin_30_35_ATLAS_emu");
        double sigma_tta_bin_30_35_madgraph = 0.148458; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_30_35 +(-0.008634*ewgc("CG")+0.001254*ewgc("Cqd8R",2,2,0,0)
                    +0.000149*ewgc("Cqd8R",2,2,1,1)+0.020344*ewgc("Cqq1R",0,2,2,0)
                    +0.000623*ewgc("Cqq1R",1,2,2,1)+0.036940*ewgc("Cqq3R",0,2,2,0)
                    +0.002683*ewgc("Cqq3R",1,2,2,1)+0.009143*ewgc("Cqu8R",0,0,2,2)
                    +0.000393*ewgc("Cqu8R",1,1,2,2)+0.007956*ewgc("Cqu8R",2,2,0,0)
                    +0.000237*ewgc("Cqu8R",2,2,1,1)+-0.002334*ewgc("CuBR",2,2)
                    +0.002172*ewgc("Cud8R",2,2,0,0)+0.000281*ewgc("Cud8R",2,2,1,1)
                    -0.039223*ewgc("CuGR",2,2)+0.019888*ewgc("CuuR",0,2,2,0)
                    +0.000612*ewgc("CuuR",1,2,2,1)+-0.001536*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_30_35/sigma_tta_bin_30_35_madgraph);
            
        }
    } else if(b_min == 35 && b_max == 40){
        
    
        double SM_sigma_tta_bin_35_40 = SM.getOptionalParameter("SM_sigma_tta_bin_35_40_ATLAS_emu");
        double sigma_tta_bin_35_40_madgraph = 0.120694; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            return SM_sigma_tta_bin_35_40 +(-0.007257*ewgc("CG")+0.000987*ewgc("Cqd8R",2,2,0,0)
                    +0.000102*ewgc("Cqd8R",2,2,1,1)+0.016185*ewgc("Cqq1R",0,2,2,0)
                    +0.000464*ewgc("Cqq1R",1,2,2,1)+0.029650*ewgc("Cqq3R",0,2,2,0)
                    +0.002137*ewgc("Cqq3R",1,2,2,1)+0.007430*ewgc("Cqu8R",0,0,2,2)
                    +0.000309*ewgc("Cqu8R",1,1,2,2)+0.006422*ewgc("Cqu8R",2,2,0,0)
                    +0.000183*ewgc("Cqu8R",2,2,1,1)+-0.002287*ewgc("CuBR",2,2)
                    +0.001776*ewgc("Cud8R",2,2,0,0)+0.000208*ewgc("Cud8R",2,2,1,1)
                    -0.031798*ewgc("CuGR",2,2)+0.015826*ewgc("CuuR",0,2,2,0)
                    +0.000435*ewgc("CuuR",1,2,2,1)+-0.001438*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_35_40/sigma_tta_bin_35_40_madgraph);
            
        }
    } else if(b_min == 40 && b_max == 47){
        
    
        double SM_sigma_tta_bin_40_47 = SM.getOptionalParameter("SM_sigma_tta_bin_40_47_ATLAS_emu");
        double sigma_tta_bin_40_47_madgraph = 0.135826; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{

            return SM_sigma_tta_bin_40_47 +(-0.008293*ewgc("CG")+0.001098*ewgc("Cqd8R",2,2,0,0)
                    +0.000158*ewgc("Cqd8R",2,2,1,1)+0.017832*ewgc("Cqq1R",0,2,2,0)
                    +0.000514*ewgc("Cqq1R",1,2,2,1)+0.033274*ewgc("Cqq3R",0,2,2,0)
                    +0.002414*ewgc("Cqq3R",1,2,2,1)+0.008356*ewgc("Cqu8R",0,0,2,2)
                    +0.000370*ewgc("Cqu8R",1,1,2,2)+0.007249*ewgc("Cqu8R",2,2,0,0)
                    +0.000232*ewgc("Cqu8R",2,2,1,1)-0.00307051*ewgc("CuBR",2,2)
                    +0.002034*ewgc("Cud8R",2,2,0,0)+0.000278*ewgc("Cud8R",2,2,1,1)
                    -0.035596*ewgc("CuGR",2,2)+0.017419*ewgc("CuuR",0,2,2,0)
                    +0.000515*ewgc("CuuR",1,2,2,1)-0.001898*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_40_47/sigma_tta_bin_40_47_madgraph);
            
        }
    } else if(b_min == 47 && b_max == 55){
        
    
        double SM_sigma_tta_bin_47_55 = SM.getOptionalParameter("SM_sigma_tta_bin_47_55_ATLAS_emu");
        double sigma_tta_bin_47_55_madgraph = 0.121740; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_47_55 +(-0.007575*ewgc("CG")+0.001001*ewgc("Cqd8R",2,2,0,0)
                    +0.000125*ewgc("Cqd8R",2,2,1,1)+0.015576*ewgc("Cqq1R",0,2,2,0)
                    +0.000477*ewgc("Cqq1R",1,2,2,1)+0.029798*ewgc("Cqq3R",0,2,2,0)
                    +0.002128*ewgc("Cqq3R",1,2,2,1)+0.007469*ewgc("Cqu8R",0,0,2,2)
                    +0.000318*ewgc("Cqu8R",1,1,2,2)+0.006480*ewgc("Cqu8R",2,2,0,0)
                    +0.000197*ewgc("Cqu8R",2,2,1,1)+-0.003278*ewgc("CuBR",2,2)
                    +0.001854*ewgc("Cud8R",2,2,0,0)+0.000228*ewgc("Cud8R",2,2,1,1)
                    -0.031752*ewgc("CuGR",2,2)+0.015239*ewgc("CuuR",0,2,2,0)
                    +0.000455*ewgc("CuuR",1,2,2,1)+-0.001958*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_47_55/sigma_tta_bin_47_55_madgraph);
            
        }
    } else if(b_min == 55 && b_max == 70){
        
    
        double SM_sigma_tta_bin_55_70 = SM.getOptionalParameter("SM_sigma_tta_bin_55_70_ATLAS_emu");
        double sigma_tta_bin_55_70_madgraph = 0.165952; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_55_70 +(+-0.010297*ewgc("CG")+0.001358*ewgc("Cqd8R",2,2,0,0)
                    +0.000129*ewgc("Cqd8R",2,2,1,1)+0.020636*ewgc("Cqq1R",0,2,2,0)
                    +0.000570*ewgc("Cqq1R",1,2,2,1)+0.039909*ewgc("Cqq3R",0,2,2,0)
                    +0.002860*ewgc("Cqq3R",1,2,2,1)+0.010263*ewgc("Cqu8R",0,0,2,2)
                    +0.000378*ewgc("Cqu8R",1,1,2,2)+0.008906*ewgc("Cqu8R",2,2,0,0)
                    +0.000208*ewgc("Cqu8R",2,2,1,1)+-0.005566*ewgc("CuBR",2,2)
                    +0.002574*ewgc("Cud8R",2,2,0,0)+0.000267*ewgc("Cud8R",2,2,1,1)
                    -0.042950*ewgc("CuGR",2,2)+0.020254*ewgc("CuuR",0,2,2,0)
                    +0.000551*ewgc("CuuR",1,2,2,1)+-0.003266*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_55_70/sigma_tta_bin_55_70_madgraph);
            
        }
    } else if(b_min == 70 && b_max == 85){
        
    
        double SM_sigma_tta_bin_70_85 = SM.getOptionalParameter("SM_sigma_tta_bin_70_85_ATLAS_emu");
        double sigma_tta_bin_70_85_madgraph = 0.115196; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_70_85 +(-0.007459*ewgc("CG")+0.000912*ewgc("Cqd8R",2,2,0,0)
                    +0.000085*ewgc("Cqd8R",2,2,1,1)+0.013773*ewgc("Cqq1R",0,2,2,0)
                    +0.000343*ewgc("Cqq1R",1,2,2,1)+0.027638*ewgc("Cqq3R",0,2,2,0)
                    +0.001935*ewgc("Cqq3R",1,2,2,1)+0.007129*ewgc("Cqu8R",0,0,2,2)
                    +0.000241*ewgc("Cqu8R",1,1,2,2)+0.006201*ewgc("Cqu8R",2,2,0,0)
                    +0.000146*ewgc("Cqu8R",2,2,1,1)+-0.004693*ewgc("CuBR",2,2)
                    +0.001789*ewgc("Cud8R",2,2,0,0)+0.000183*ewgc("Cud8R",2,2,1,1)
                    -0.029503*ewgc("CuGR",2,2)+0.013479*ewgc("CuuR",0,2,2,0)
                    +0.000332*ewgc("CuuR",1,2,2,1)+-0.002681*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_70_85/sigma_tta_bin_70_85_madgraph);
            
        }
    } else if(b_min == 85 && b_max == 132){
        
    
        double SM_sigma_tta_bin_85_132 = SM.getOptionalParameter("SM_sigma_tta_bin_85_132_ATLAS_emu");
        double sigma_tta_bin_85_132_madgraph = 0.200083; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_85_132 +(-0.014099*ewgc("CG")+0.001631*ewgc("Cqd8R",2,2,0,0)
                    +0.000171*ewgc("Cqd8R",2,2,1,1)+0.023131*ewgc("Cqq1R",0,2,2,0)
                    +0.000580*ewgc("Cqq1R",1,2,2,1)+0.048084*ewgc("Cqq3R",0,2,2,0)
                    +0.003229*ewgc("Cqq3R",1,2,2,1)+0.012662*ewgc("Cqu8R",0,0,2,2)
                    +0.000456*ewgc("Cqu8R",1,1,2,2)+0.011006*ewgc("Cqu8R",2,2,0,0)
                    +0.000281*ewgc("Cqu8R",2,2,1,1)+-0.010083*ewgc("CuBR",2,2)
                    +0.003292*ewgc("Cud8R",2,2,0,0)+0.000342*ewgc("Cud8R",2,2,1,1)
                    -0.050663*ewgc("CuGR",2,2)+0.022549*ewgc("CuuR",0,2,2,0)
                    +0.000559*ewgc("CuuR",1,2,2,1)+-0.005730*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_85_132/sigma_tta_bin_85_132_madgraph);
            
        }
    } else if(b_min == 132 && b_max == 180){
        
    
        double SM_sigma_tta_bin_132_180 = SM.getOptionalParameter("SM_sigma_tta_bin_132_180_ATLAS_emu");
        double sigma_tta_bin_132_180_madgraph = 0.091916; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_132_180 +(-0.007853*ewgc("CG")+0.000817*ewgc("Cqd8R",2,2,0,0)
                    +0.000091*ewgc("Cqd8R",2,2,1,1)+0.010609*ewgc("Cqq1R",0,2,2,0)
                    +0.000257*ewgc("Cqq1R",1,2,2,1)+0.023194*ewgc("Cqq3R",0,2,2,0)
                    +0.001494*ewgc("Cqq3R",1,2,2,1)+0.006217*ewgc("Cqu8R",0,0,2,2)
                    +0.000215*ewgc("Cqu8R",1,1,2,2)+0.005413*ewgc("Cqu8R",2,2,0,0)
                    +0.000142*ewgc("Cqu8R",2,2,1,1)+-0.005438*ewgc("CuBR",2,2)
                    +0.001678*ewgc("Cud8R",2,2,0,0)+0.000183*ewgc("Cud8R",2,2,1,1)
                    -0.023098*ewgc("CuGR",2,2)+0.010347*ewgc("CuuR",0,2,2,0)
                    +0.000251*ewgc("CuuR",1,2,2,1)+-0.003075*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_132_180/sigma_tta_bin_132_180_madgraph);
            
        }
    } else if(b_min == 180 && b_max == 300){
        
    
        double SM_sigma_tta_bin_180_300 = SM.getOptionalParameter("SM_sigma_tta_bin_180_300_ATLAS_emu");
        double sigma_tta_bin_180_300_madgraph = 0.077596; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_180_300 +(-0.009519*ewgc("CG")+0.000800*ewgc("Cqd8R",2,2,0,0)
                    +0.000069*ewgc("Cqd8R",2,2,1,1)+0.009803*ewgc("Cqq1R",0,2,2,0)
                    +0.000190*ewgc("Cqq1R",1,2,2,1)+0.022629*ewgc("Cqq3R",0,2,2,0)
                    +0.001298*ewgc("Cqq3R",1,2,2,1)+0.006131*ewgc("Cqu8R",0,0,2,2)
                    +0.000175*ewgc("Cqu8R",1,1,2,2)+0.005339*ewgc("Cqu8R",2,2,0,0)
                    +0.000108*ewgc("Cqu8R",2,2,1,1)+-0.004601*ewgc("CuBR",2,2)
                    +0.001701*ewgc("Cud8R",2,2,0,0)+0.000146*ewgc("Cud8R",2,2,1,1)
                    -0.019949*ewgc("CuGR",2,2)+0.009534*ewgc("CuuR",0,2,2,0)
                    +0.000184*ewgc("CuuR",1,2,2,1)+-0.002603*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_180_300/sigma_tta_bin_180_300_madgraph);
            
        }
    } else{
        throw std::runtime_error("\nERROR: Please specify a correct binning range for sigma_tta_diff_LO_ATLAS_emu.\n");
    }
    
    

}



sigma_tta_diff_LO_CMS_semileptonic_210701508::sigma_tta_diff_LO_CMS_semileptonic_210701508(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{

    setParametersForObservable(make_vector<std::string>() << "SM_sigma_tta_bin_20_35_CMS_semileptonic"
            << "SM_sigma_tta_bin_35_50_CMS_semileptonic" << "SM_sigma_tta_bin_50_80_CMS_semileptonic"
            << "SM_sigma_tta_bin_80_120_CMS_semileptonic" << "SM_sigma_tta_bin_120_160_CMS_semileptonic" 
            << "SM_sigma_tta_bin_160_200_CMS_semileptonic" << "SM_sigma_tta_bin_200_260_CMS_semileptonic"
            << "SM_sigma_tta_bin_260_320_CMS_semileptonic" << "SM_sigma_tta_bin_320_380_CMS_semileptonic");

    
};


double sigma_tta_diff_LO_CMS_semileptonic_210701508::computeThValue()
{

    b_min = getBinMin();
    b_max = getBinMax();
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    

    
    
    
    if(b_min == 20 && b_max == 35){
        
        double SM_sigma_tta_bin_20_35 = SM.getOptionalParameter("SM_sigma_tta_bin_20_35_CMS_semileptonic");
        double sigma_tta_bin_20_35_madgraph = 0.583675; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
                    
            return SM_sigma_tta_bin_20_35 +(-0.034106*ewgc("CG")+0.004794*ewgc("Cqd8R",2,2,0,0)
                    +0.000605*ewgc("Cqd8R",2,2,1,1)+0.082493*ewgc("Cqq1R",0,2,2,0)
                    +0.002529*ewgc("Cqq1R",1,2,2,1)+0.146282*ewgc("Cqq3R",0,2,2,0)+0.010782*ewgc("Cqq3R",1,2,2,1)
                    +0.036042*ewgc("Cqu8R",0,0,2,2)+0.001578*ewgc("Cqu8R",1,1,2,2)+0.031190*ewgc("Cqu8R",2,2,0,0)
                    +0.000906*ewgc("Cqu8R",2,2,1,1)+-0.007204*ewgc("CuBR",2,2)+0.008516*ewgc("Cud8R",2,2,0,0)
                    +0.001057*ewgc("Cud8R",2,2,1,1)+-0.154829*ewgc("CuGR",2,2)
                    +0.080748*ewgc("CuuR",0,2,2,0)+0.002498*ewgc("CuuR",1,2,2,1)+-0.005006*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_20_35/sigma_tta_bin_20_35_madgraph);
        }
    } else if(b_min == 35 && b_max == 50){
        
    
        double SM_sigma_tta_bin_35_50 = SM.getOptionalParameter("SM_sigma_tta_bin_35_50_CMS_semileptonic");
        double sigma_tta_bin_35_50_madgraph = 0.305601; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_35_50 +(-0.018555*ewgc("CG")+0.002547*ewgc("Cqd8R",2,2,0,0)
                    +0.000295*ewgc("Cqd8R",2,2,1,1)+0.040351*ewgc("Cqq1R",0,2,2,0)
                    +0.001256*ewgc("Cqq1R",1,2,2,1)+0.075386*ewgc("Cqq3R",0,2,2,0)+0.005401*ewgc("Cqq3R",1,2,2,1)
                    +0.018788*ewgc("Cqu8R",0,0,2,2)+0.000807*ewgc("Cqu8R",1,1,2,2)+0.016262*ewgc("Cqu8R",2,2,0,0)
                    +0.000470*ewgc("Cqu8R",2,2,1,1)+-0.006535*ewgc("CuBR",2,2)+0.004622*ewgc("Cud8R",2,2,0,0)
                    +0.000557*ewgc("Cud8R",2,2,1,1)-0.080445*ewgc("CuGR",2,2)
                    +0.039496*ewgc("CuuR",0,2,2,0)+0.001217*ewgc("CuuR",1,2,2,1)+-0.004069*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_35_50/sigma_tta_bin_35_50_madgraph);
            
        }
    } else if(b_min == 50 && b_max == 80){
        
        double SM_sigma_tta_bin_50_80 = SM.getOptionalParameter("SM_sigma_tta_bin_50_80_CMS_semileptonic");
        double sigma_tta_bin_50_80_madgraph = 0.319505; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
                    
            return SM_sigma_tta_bin_50_80 +(-0.020248*ewgc("CG")+0.002577*ewgc("Cqd8R",2,2,0,0)
                    +0.000287*ewgc("Cqd8R",2,2,1,1)+0.039600*ewgc("Cqq1R",0,2,2,0)
                    +0.001092*ewgc("Cqq1R",1,2,2,1)+0.077011*ewgc("Cqq3R",0,2,2,0)
                    +0.005369*ewgc("Cqq3R",1,2,2,1)+0.019650*ewgc("Cqu8R",0,0,2,2)
                    +0.000769*ewgc("Cqu8R",1,1,2,2)+0.017049*ewgc("Cqu8R",2,2,0,0)
                    +0.000467*ewgc("Cqu8R",2,2,1,1)+-0.010718*ewgc("CuBR",2,2)
                    +0.004924*ewgc("Cud8R",2,2,0,0)+0.000555*ewgc("Cud8R",2,2,1,1)
                    -0.082799*ewgc("CuGR",2,2)+0.038642*ewgc("CuuR",0,2,2,0)
                    +0.001064*ewgc("CuuR",1,2,2,1)+-0.006289*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_50_80/sigma_tta_bin_50_80_madgraph);
        }
    } else if(b_min == 80 && b_max == 120){
        
    
        double SM_sigma_tta_bin_80_120 = SM.getOptionalParameter("SM_sigma_tta_bin_80_120_CMS_semileptonic");
        double sigma_tta_bin_80_120_madgraph = 0.198070; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_80_120 +(-0.013527*ewgc("CG")+0.001628*ewgc("Cqd8R",2,2,0,0)
                    +0.000164*ewgc("Cqd8R",2,2,1,1)+0.023160*ewgc("Cqq1R",0,2,2,0)
                    +0.000587*ewgc("Cqq1R",1,2,2,1)+0.047833*ewgc("Cqq3R",0,2,2,0)
                    +0.003240*ewgc("Cqq3R",1,2,2,1)+0.012405*ewgc("Cqu8R",0,0,2,2)
                    +0.000452*ewgc("Cqu8R",1,1,2,2)+0.010800*ewgc("Cqu8R",2,2,0,0)
                    +0.000273*ewgc("Cqu8R",2,2,1,1)+-0.009514*ewgc("CuBR",2,2)
                    +0.003221*ewgc("Cud8R",2,2,0,0)+0.000351*ewgc("Cud8R",2,2,1,1)
                    -0.050365*ewgc("CuGR",2,2)+0.022607*ewgc("CuuR",0,2,2,0)
                    +0.000576*ewgc("CuuR",1,2,2,1)+-0.005448*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_80_120/sigma_tta_bin_80_120_madgraph);
            
        }
    } else if(b_min == 120 && b_max == 160){
        
    
        double SM_sigma_tta_bin_120_160 = SM.getOptionalParameter("SM_sigma_tta_bin_120_160_CMS_semileptonic");
        double sigma_tta_bin_120_160_madgraph = 0.097725; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_120_160 +(-0.007834*ewgc("CG")+0.000808*ewgc("Cqd8R",2,2,0,0)
                    +0.000071*ewgc("Cqd8R",2,2,1,1)+0.011182*ewgc("Cqq1R",0,2,2,0)
                    +0.000245*ewgc("Cqq1R",1,2,2,1)+0.024260*ewgc("Cqq3R",0,2,2,0)
                    +0.001549*ewgc("Cqq3R",1,2,2,1)+0.006409*ewgc("Cqu8R",0,0,2,2)
                    +0.000204*ewgc("Cqu8R",1,1,2,2)+0.005568*ewgc("Cqu8R",2,2,0,0)
                    +0.000122*ewgc("Cqu8R",2,2,1,1)+-0.005632*ewgc("CuBR",2,2)
                    +0.001708*ewgc("Cud8R",2,2,0,0)+0.000162*ewgc("Cud8R",2,2,1,1)
                    -0.024540*ewgc("CuGR",2,2)+0.010926*ewgc("CuuR",0,2,2,0)
                    +0.000235*ewgc("CuuR",1,2,2,1)+-0.003185*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_120_160/sigma_tta_bin_120_160_madgraph);
            
        }
    } else if(b_min == 160 && b_max == 200){
        
    
        double SM_sigma_tta_bin_160_200 = SM.getOptionalParameter("SM_sigma_tta_bin_160_200_CMS_semileptonic");
        double sigma_tta_bin_160_200_madgraph = 0.053162; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_160_200 +(-0.005116*ewgc("CG")+0.000482*ewgc("Cqd8R",2,2,0,0)
                    +0.000047*ewgc("Cqd8R",2,2,1,1)+0.006230*ewgc("Cqq1R",0,2,2,0)
                    +0.000137*ewgc("Cqq1R",1,2,2,1)+0.013887*ewgc("Cqq3R",0,2,2,0)
                    +0.000853*ewgc("Cqq3R",1,2,2,1)+0.003756*ewgc("Cqu8R",0,0,2,2)
                    +0.000123*ewgc("Cqu8R",1,1,2,2)+0.003272*ewgc("Cqu8R",2,2,0,0)
                    +0.000076*ewgc("Cqu8R",2,2,1,1)+-0.003224*ewgc("CuBR",2,2)
                    +0.001020*ewgc("Cud8R",2,2,0,0)+0.000101*ewgc("Cud8R",2,2,1,1)
                    -0.013391*ewgc("CuGR",2,2)+0.006063*ewgc("CuuR",0,2,2,0)
                    +0.000133*ewgc("CuuR",1,2,2,1)+-0.001792*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_160_200/sigma_tta_bin_160_200_madgraph);
            
        }
    } else if(b_min == 200 && b_max == 260){
        
    
        double SM_sigma_tta_bin_200_260 = SM.getOptionalParameter("SM_sigma_tta_bin_200_260_CMS_semileptonic");
        double sigma_tta_bin_200_260_madgraph = 0.040676; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_200_260 +(-0.004958*ewgc("CG")+0.000418*ewgc("Cqd8R",2,2,0,0)
                    +0.000036*ewgc("Cqd8R",2,2,1,1)+0.005096*ewgc("Cqq1R",0,2,2,0)
                    +0.000101*ewgc("Cqq1R",1,2,2,1)+0.011849*ewgc("Cqq3R",0,2,2,0)
                    +0.000680*ewgc("Cqq3R",1,2,2,1)+0.003215*ewgc("Cqu8R",0,0,2,2)
                    +0.000093*ewgc("Cqu8R",1,1,2,2)+0.002804*ewgc("Cqu8R",2,2,0,0)
                    +0.000057*ewgc("Cqu8R",2,2,1,1)+-0.002405*ewgc("CuBR",2,2)
                    +0.000885*ewgc("Cud8R",2,2,0,0)+0.000078*ewgc("Cud8R",2,2,1,1)
                    -0.010460*ewgc("CuGR",2,2)+0.004970*ewgc("CuuR",0,2,2,0)
                    +0.000098*ewgc("CuuR",1,2,2,1)+-0.001356*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_200_260/sigma_tta_bin_200_260_madgraph);
            
        }
    } else if(b_min == 260 && b_max == 320){
        
    
        double SM_sigma_tta_bin_260_320 = SM.getOptionalParameter("SM_sigma_tta_bin_260_320_CMS_semileptonic");
        double sigma_tta_bin_260_320_madgraph = 0.018994; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_260_320 +(-0.003098*ewgc("CG")+0.000227*ewgc("Cqd8R",2,2,0,0)
                    +0.000013*ewgc("Cqd8R",2,2,1,1)+0.002712*ewgc("Cqq1R",0,2,2,0)
                    +0.000044*ewgc("Cqq1R",1,2,2,1)+0.006445*ewgc("Cqq3R",0,2,2,0)
                    +0.000337*ewgc("Cqq3R",1,2,2,1)+0.001768*ewgc("Cqu8R",0,0,2,2)
                    +0.000042*ewgc("Cqu8R",1,1,2,2)+0.001534*ewgc("Cqu8R",2,2,0,0)
                    +0.000025*ewgc("Cqu8R",2,2,1,1)+-0.001038*ewgc("CuBR",2,2)
                    +0.000492*ewgc("Cud8R",2,2,0,0)+0.000035*ewgc("Cud8R",2,2,1,1)
                    -0.005064*ewgc("CuGR",2,2)+0.002652*ewgc("CuuR",0,2,2,0)
                    +0.000042*ewgc("CuuR",1,2,2,1)+-0.000592*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_260_320/sigma_tta_bin_260_320_madgraph);
            
        }
    } else if(b_min == 320 && b_max == 380){
        
    
        double SM_sigma_tta_bin_320_380 = SM.getOptionalParameter("SM_sigma_tta_bin_320_380_CMS_semileptonic");
        double sigma_tta_bin_320_380_madgraph = 0.009391; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_320_380 +(-0.001921*ewgc("CG")+0.000136*ewgc("Cqd8R",2,2,0,0)
                    +0.000007*ewgc("Cqd8R",2,2,1,1)+0.001575*ewgc("Cqq1R",0,2,2,0)
                    +0.000023*ewgc("Cqq1R",1,2,2,1)+0.003819*ewgc("Cqq3R",0,2,2,0)
                    +0.000186*ewgc("Cqq3R",1,2,2,1)+0.001048*ewgc("Cqu8R",0,0,2,2)
                    +0.000022*ewgc("Cqu8R",1,1,2,2)+0.000910*ewgc("Cqu8R",2,2,0,0)
                    +0.000013*ewgc("Cqu8R",2,2,1,1)+-0.000451*ewgc("CuBR",2,2)
                    +0.000293*ewgc("Cud8R",2,2,0,0)+0.000019*ewgc("Cud8R",2,2,1,1)
                    -0.002605*ewgc("CuGR",2,2)+0.001534*ewgc("CuuR",0,2,2,0)
                    +0.000023*ewgc("CuuR",1,2,2,1)+-0.000262*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_320_380/sigma_tta_bin_320_380_madgraph);
            
        }
    }  else{
            throw std::runtime_error("\nERROR: Please specify a correct binning range for sigma_tta_diff_LO_CMS_semileptonic.\n");
    }



}





sigma_tta_diff_LO_CMS_dilepton_220107301::sigma_tta_diff_LO_CMS_dilepton_220107301(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{

    setParametersForObservable(make_vector<std::string>() << "SM_sigma_tta_bin_20_35_CMS_dilepton" << "SM_sigma_tta_bin_35_50_CMS_dilepton"
            << "SM_sigma_tta_bin_50_70_CMS_dilepton" << "SM_sigma_tta_bin_70_130_CMS_dilepton" 
            << "SM_sigma_tta_bin_130_200_CMS_dilepton" << "SM_sigma_tta_bin_200_300_CMS_dilepton");

    
};


double sigma_tta_diff_LO_CMS_dilepton_220107301::computeThValue()
{
    
    b_min = getBinMin();
    b_max = getBinMax();
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    

    if(b_min == 20 && b_max == 35){
        
        double SM_sigma_tta_bin_20_35 = SM.getOptionalParameter("SM_sigma_tta_bin_20_35_CMS_dilepton");
        double sigma_tta_bin_20_35_madgraph = 0.583675; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            //There is no dependence on ewgc("Cqd8R",2,2,2,2) neither on ewgc("Cud8R",2,2,2,2) with the precision considered
        
            return SM_sigma_tta_bin_20_35 +(-0.034106*ewgc("CG")+0.004794*ewgc("Cqd8R",2,2,0,0)
                    +0.000605*ewgc("Cqd8R",2,2,1,1)+0.082493*ewgc("Cqq1R",0,2,2,0)
                    +0.002529*ewgc("Cqq1R",1,2,2,1)+0.146282*ewgc("Cqq3R",0,2,2,0)+0.010782*ewgc("Cqq3R",1,2,2,1)
                    +0.036042*ewgc("Cqu8R",0,0,2,2)+0.001578*ewgc("Cqu8R",1,1,2,2)+0.031190*ewgc("Cqu8R",2,2,0,0)
                    +0.000906*ewgc("Cqu8R",2,2,1,1)+-0.007204*ewgc("CuBR",2,2)+0.008516*ewgc("Cud8R",2,2,0,0)
                    +0.001057*ewgc("Cud8R",2,2,1,1)+-0.154829*ewgc("CuGR",2,2)
                    +0.080748*ewgc("CuuR",0,2,2,0)+0.002498*ewgc("CuuR",1,2,2,1)+-0.005006*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_20_35/sigma_tta_bin_20_35_madgraph);
        }
    } else if(b_min == 35 && b_max == 50){
        
    
        double SM_sigma_tta_bin_35_50 = SM.getOptionalParameter("SM_sigma_tta_bin_35_50_CMS_dilepton");
        double sigma_tta_bin_35_50_madgraph = 0.305601; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_35_50 +(-0.018555*ewgc("CG")+0.002547*ewgc("Cqd8R",2,2,0,0)
                    +0.000295*ewgc("Cqd8R",2,2,1,1)+0.040351*ewgc("Cqq1R",0,2,2,0)
                    +0.001256*ewgc("Cqq1R",1,2,2,1)+0.075386*ewgc("Cqq3R",0,2,2,0)+0.005401*ewgc("Cqq3R",1,2,2,1)
                    +0.018788*ewgc("Cqu8R",0,0,2,2)+0.000807*ewgc("Cqu8R",1,1,2,2)+0.016262*ewgc("Cqu8R",2,2,0,0)
                    +0.000470*ewgc("Cqu8R",2,2,1,1)+-0.006535*ewgc("CuBR",2,2)+0.004622*ewgc("Cud8R",2,2,0,0)
                    +0.000557*ewgc("Cud8R",2,2,1,1)-0.080445*ewgc("CuGR",2,2)
                    +0.039496*ewgc("CuuR",0,2,2,0)+0.001217*ewgc("CuuR",1,2,2,1)+-0.004069*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_35_50/sigma_tta_bin_35_50_madgraph);
            
        }
    } else if(b_min == 50 && b_max == 70){
        
    
        double SM_sigma_tta_bin_50_70 = SM.getOptionalParameter("SM_sigma_tta_bin_50_70_CMS_dilepton");
        double sigma_tta_bin_50_70_madgraph = 0.238500; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_tta_bin_50_70 +(-0.014859*ewgc("CG")+0.001934*ewgc("Cqd8R",2,2,0,0)
                    +0.000192*ewgc("Cqd8R",2,2,1,1)+
                    +0.029858*ewgc("Cqq1R",0,2,2,0)+0.000825*ewgc("Cqq1R",1,2,2,1)
                    +0.057705*ewgc("Cqq3R",0,2,2,0)+0.004114*ewgc("Cqq3R",1,2,2,1)
                    +0.014644*ewgc("Cqu8R",0,0,2,2)+0.000602*ewgc("Cqu8R",1,1,2,2)
                    +0.012747*ewgc("Cqu8R",2,2,0,0)+-0.007537*ewgc("CuBR",2,2)
                    +0.003692*ewgc("Cud8R",2,2,0,0)+0.000409*ewgc("Cud8R",2,2,1,1)
                    -0.061847*ewgc("CuGR",2,2)
                    +0.029209*ewgc("CuuR",0,2,2,0)+0.000813*ewgc("CuuR",1,2,2,1)
                    +-0.004460*ewgc("CuWR",2,2))
                    *(SM_sigma_tta_bin_50_70/sigma_tta_bin_50_70_madgraph);
            
        }
    } else if(b_min == 70 && b_max == 130){
        
    
        double SM_sigma_tta_bin_70_130 = SM.getOptionalParameter("SM_sigma_tta_bin_70_130_CMS_dilepton");
        double sigma_tta_bin_70_100_madgraph = 0.198831; //pb
        double sigma_tta_bin_100_130_madgraph =0.110866; //pb
        double sigma_tta_bin_70_130_madgraph =sigma_tta_bin_70_100_madgraph+sigma_tta_bin_100_130_madgraph; //pb
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            double sigma_tta_bin_70_100_NP = (-0.013285*ewgc("CG")+0.001630*ewgc("Cqd8R",2,2,0,0)
                    +0.000250*ewgc("Cqd8R",2,2,1,1)
                    +0.023767*ewgc("Cqq1R",0,2,2,0)+0.000676*ewgc("Cqq1R",1,2,2,1)
                    +0.047671*ewgc("Cqq3R",0,2,2,0)+0.003336*ewgc("Cqq3R",1,2,2,1)
                    +0.012379*ewgc("Cqu8R",0,0,2,2)+0.000535*ewgc("Cqu8R",1,1,2,2)
                    +0.010765*ewgc("Cqu8R",2,2,0,0)+0.000350*ewgc("Cqu8R",2,2,1,1)
                    -0.008505*ewgc("CuBR",2,2)+0.003205*ewgc("Cud8R",2,2,0,0)
                    +0.000431*ewgc("Cud8R",2,2,1,1)
                    -0.050838*ewgc("CuGR",2,2)+0.023185*ewgc("CuuR",0,2,2,0)
                    +0.000655*ewgc("CuuR",1,2,2,1)-0.004930*ewgc("CuWR",2,2));
             
            
            double sigma_tta_bin_100_130_NP = (-0.008092*ewgc("CG")+0.000916*ewgc("Cqd8R",2,2,0,0)+0.000088*ewgc("Cqd8R",2,2,1,1)
                    +0.012744*ewgc("Cqq1R",0,2,2,0)+0.000316*ewgc("Cqq1R",1,2,2,1)
                    +0.026925*ewgc("Cqq3R",0,2,2,0)+0.001792*ewgc("Cqq3R",1,2,2,1)+0.007060*ewgc("Cqu8R",0,0,2,2)
                    +0.000247*ewgc("Cqu8R",1,1,2,2)+0.006144*ewgc("Cqu8R",2,2,0,0)+0.000162*ewgc("Cqu8R",2,2,1,1)
                    +-0.005920*ewgc("CuBR",2,2)+0.001849*ewgc("Cud8R",2,2,0,0)+0.000200*ewgc("Cud8R",2,2,1,1)
                    +-0.027969*ewgc("CuGR",2,2)+0.012428*ewgc("CuuR",0,2,2,0)
                    +0.000308*ewgc("CuuR",1,2,2,1)+-0.003364*ewgc("CuWR",2,2));
            
            return SM_sigma_tta_bin_70_130 + (sigma_tta_bin_70_100_NP + sigma_tta_bin_100_130_NP)*(SM_sigma_tta_bin_70_130/sigma_tta_bin_70_130_madgraph);
            
        }
    } else if(b_min == 130 && b_max == 200){
        
    
        double SM_sigma_tta_bin_130_200 = SM.getOptionalParameter("SM_sigma_tta_bin_130_200_CMS_dilepton");
        double sigma_tta_bin_130_165_madgraph = 0.075543; //pb
        double sigma_tta_bin_165_200_madgraph = 0.044687; //pb
        double sigma_tta_bin_130_200_madgraph = sigma_tta_bin_130_165_madgraph+sigma_tta_bin_165_200_madgraph;
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            double sigma_tta_bin_130_165_NP = (-0.006183*ewgc("CG")+0.000634*ewgc("Cqd8R",2,2,0,0)+0.000043*ewgc("Cqd8R",2,2,1,1)
                    +0.008637*ewgc("Cqq1R",0,2,2,0)+0.000173*ewgc("Cqq1R",1,2,2,1)
                    +0.018848*ewgc("Cqq3R",0,2,2,0)+0.001189*ewgc("Cqq3R",1,2,2,1)+0.005006*ewgc("Cqu8R",0,0,2,2)
                    +0.000145*ewgc("Cqu8R",1,1,2,2)+0.004346*ewgc("Cqu8R",2,2,0,0)+0.000081*ewgc("Cqu8R",2,2,1,1)
                    +-0.004429*ewgc("CuBR",2,2)+0.001330*ewgc("Cud8R",2,2,0,0)+0.000119*ewgc("Cud8R",2,2,1,1)
                    +-0.018971*ewgc("CuGR",2,2)+0.008402*ewgc("CuuR",0,2,2,0)
                    +0.000171*ewgc("CuuR",1,2,2,1)+-0.002499*ewgc("CuWR",2,2));
            
            double sigma_tta_bin_165_200_NP = (-0.004285*ewgc("CG")+0.000401*ewgc("Cqd8R",2,2,0,0)+0.000029*ewgc("Cqd8R",2,2,1,1)
                    +0.005252*ewgc("Cqq1R",0,2,2,0)+0.000104*ewgc("Cqq1R",1,2,2,1)
                    +0.011756*ewgc("Cqq3R",0,2,2,0)+0.000720*ewgc("Cqq3R",1,2,2,1)+0.003157*ewgc("Cqu8R",0,0,2,2)
                    +0.000089*ewgc("Cqu8R",1,1,2,2)+0.002752*ewgc("Cqu8R",2,2,0,0)+0.000051*ewgc("Cqu8R",2,2,1,1)
                    +-0.002716*ewgc("CuBR",2,2)+0.000855*ewgc("Cud8R",2,2,0,0)+0.000072*ewgc("Cud8R",2,2,1,1)
                    +-0.011315*ewgc("CuGR",2,2)+0.005106*ewgc("CuuR",0,2,2,0)
                    +0.000098*ewgc("CuuR",1,2,2,1)+-0.001515*ewgc("CuWR",2,2));
            
            return SM_sigma_tta_bin_130_200 + (sigma_tta_bin_130_165_NP+sigma_tta_bin_165_200_NP)*(SM_sigma_tta_bin_130_200/sigma_tta_bin_130_200_madgraph);
            
        }
    } else if(b_min == 200 && b_max == 300){
        
    
        double SM_sigma_tta_bin_200_300 = SM.getOptionalParameter("SM_sigma_tta_bin_200_300_CMS_dilepton");
        double sigma_tta_bin_200_250_madgraph = 0.035911; //pb
        double sigma_tta_bin_250_300_madgraph = 0.018900; //pb
        double sigma_tta_bin_200_300_madgraph = sigma_tta_bin_200_250_madgraph+sigma_tta_bin_250_300_madgraph; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            double sigma_tta_bin_200_250_NP = (-0.004232*ewgc("CG")+0.000362*ewgc("Cqd8R",2,2,0,0)+0.000028*ewgc("Cqd8R",2,2,1,1)
                    +0.004454*ewgc("Cqq1R",0,2,2,0)+0.000087*ewgc("Cqq1R",1,2,2,1)
                    +0.010395*ewgc("Cqq3R",0,2,2,0)+0.000590*ewgc("Cqq3R",1,2,2,1)+0.002802*ewgc("Cqu8R",0,0,2,2)
                    +0.000078*ewgc("Cqu8R",1,1,2,2)+0.002436*ewgc("Cqu8R",2,2,0,0)+0.000047*ewgc("Cqu8R",2,2,1,1)
                    -0.002135*ewgc("CuBR",2,2)+0.000773*ewgc("Cud8R",2,2,0,0)+0.000064*ewgc("Cud8R",2,2,1,1)
                    -0.009208*ewgc("CuGR",2,2)+0.004354*ewgc("CuuR",0,2,2,0)
                    +0.000086*ewgc("CuuR",1,2,2,1)+-0.001220*ewgc("CuWR",2,2));
            
            double sigma_tta_bin_250_300_NP = (-0.002904*ewgc("CG")+0.000216*ewgc("Cqd8R",2,2,0,0)+0.000014*ewgc("Cqd8R",2,2,1,1)
                    +0.002603*ewgc("Cqq1R",0,2,2,0)+0.000045*ewgc("Cqq1R",1,2,2,1)
                    +0.006131*ewgc("Cqq3R",0,2,2,0)+0.000331*ewgc("Cqq3R",1,2,2,1)+0.001689*ewgc("Cqu8R",0,0,2,2)
                    +0.000042*ewgc("Cqu8R",1,1,2,2)+0.001470*ewgc("Cqu8R",2,2,0,0)+0.000026*ewgc("Cqu8R",2,2,1,1)
                    -0.001064*ewgc("CuBR",2,2)+0.000469*ewgc("Cud8R",2,2,0,0)+0.000035*ewgc("Cud8R",2,2,1,1)
                    +-0.004994*ewgc("CuGR",2,2)+0.002538*ewgc("CuuR",0,2,2,0)
                    +0.000044*ewgc("CuuR",1,2,2,1)+-0.000597*ewgc("CuWR",2,2));
            
            return SM_sigma_tta_bin_200_300 + (sigma_tta_bin_200_250_NP + sigma_tta_bin_250_300_NP)*(SM_sigma_tta_bin_200_300/sigma_tta_bin_200_300_madgraph);
            
        }
    } else{
        throw std::runtime_error("\nERROR: Please specify a correct binning range for sigma_tta_diff_LO_CMS_dilepton.\n");
    }

}


//// ttz differential cross section //////


sigma_ttz_diff_LO_CMS_190711270::sigma_ttz_diff_LO_CMS_190711270(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{

    setParametersForObservable(make_vector<std::string>() << "SM_sigma_ttz_bin_0_75_CMS_190711270"
            << "SM_sigma_ttz_bin_75_150_CMS_190711270" << "SM_sigma_ttz_bin_150_250_CMS_190711270"
            << "SM_sigma_ttz_bin_250_500_CMS_190711270");

    
};


double sigma_ttz_diff_LO_CMS_190711270::computeThValue()
{
    
    b_min = getBinMin();
    b_max = getBinMax();
    
    bool   flag_Quadratic= false; //Needs to be properly defined
   
    if(b_min == 0 && b_max == 75){
        
        double SM_sigma_ttz_bin_0_75 = SM.getOptionalParameter("SM_sigma_ttz_bin_0_75_CMS_190711270");
        double sigma_ttz_bin_0_75_madgraph = 0.177589; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return SM_sigma_ttz_bin_0_75 + (-0.031991*ewgc("CG")+-0.016710*ewgc("CHq1R",2,2)+0.016573*ewgc("CHq3R",2,2)
                    +0.009051*ewgc("CHuR",2,2)+0.003299*ewgc("Cqd8R",2,2,0,0)+0.000362*ewgc("Cqd8R",2,2,1,1)
                    +0.024362*ewgc("Cqq1R",0,2,2,0)+0.000624*ewgc("Cqq1R",1,2,2,1)+0.119583*ewgc("Cqq3R",0,2,2,0)
                    +0.012655*ewgc("Cqq3R",1,2,2,1)+0.015687*ewgc("Cqu8R",0,0,2,2)+0.001422*ewgc("Cqu8R",1,1,2,2)
                    +0.002967*ewgc("Cqu8R",2,2,0,0)+0.000052*ewgc("Cqu8R",2,2,1,1)+-0.000318*ewgc("CuBR",2,2)
                    +0.001835*ewgc("Cud8R",2,2,0,0)+0.000209*ewgc("Cud8R",2,2,1,1)-0.052919*ewgc("CuGR",2,2)
                    +0.006972*ewgc("CuuR",0,2,2,0)+0.000145*ewgc("CuuR",1,2,2,1)+-0.000317*ewgc("CuWR",2,2))
                    *(SM_sigma_ttz_bin_0_75/sigma_ttz_bin_0_75_madgraph);
        }
        
    } else if(b_min == 75 && b_max == 150){
        
        double SM_sigma_ttz_bin_75_150 = SM.getOptionalParameter("SM_sigma_ttz_bin_75_150_CMS_190711270");
        double sigma_ttz_bin_75_150_madgraph = 0.209588; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
                    
            return SM_sigma_ttz_bin_75_150 + (-0.051622*ewgc("CG")+-0.021757*ewgc("CHq1R",2,2)+0.021813*ewgc("CHq3R",2,2)
                    +0.013632*ewgc("CHuR",2,2)+0.004262*ewgc("Cqd8R",2,2,0,0)+0.000521*ewgc("Cqd8R",2,2,1,1)
                    +0.030335*ewgc("Cqq1R",0,2,2,0)+0.000796*ewgc("Cqq1R",1,2,2,1)+0.129627*ewgc("Cqq3R",0,2,2,0)
                    +0.012107*ewgc("Cqq3R",1,2,2,1)+0.016607*ewgc("Cqu8R",0,0,2,2)+0.001371*ewgc("Cqu8R",1,1,2,2)
                    +0.004665*ewgc("Cqu8R",2,2,0,0)+0.000163*ewgc("Cqu8R",2,2,1,1)+-0.000026*ewgc("CuBR",2,2)
                    +0.002538*ewgc("Cud8R",2,2,0,0)+0.000335*ewgc("Cud8R",2,2,1,1)-0.067116*ewgc("CuGR",2,2)
                    +0.011624*ewgc("CuuR",0,2,2,0)+0.000337*ewgc("CuuR",1,2,2,1)+-0.000735*ewgc("CuWR",2,2))
                    *(SM_sigma_ttz_bin_75_150/sigma_ttz_bin_75_150_madgraph);
        }
        
    } else if(b_min == 150 && b_max == 250){
        
        double SM_sigma_ttz_bin_150_250 = SM.getOptionalParameter("SM_sigma_ttz_bin_150_250_CMS_190711270");
        double sigma_ttz_bin_150_250_madgraph = 0.132915; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
                    
            return SM_sigma_ttz_bin_150_250 + (-0.044763*ewgc("CG")-0.014558*ewgc("CHq1R",2,2)+0.014567*ewgc("CHq3R",2,2)
                    +0.010078*ewgc("CHuR",2,2)+0.003298*ewgc("Cqd8R",2,2,0,0)+0.000314*ewgc("Cqd8R",2,2,1,1)
                    +0.022847*ewgc("Cqq1R",0,2,2,0)+0.000511*ewgc("Cqq1R",1,2,2,1)+0.084393*ewgc("Cqq3R",0,2,2,0)
                    +0.006512*ewgc("Cqq3R",1,2,2,1)+0.010724*ewgc("Cqu8R",0,0,2,2)+0.000696*ewgc("Cqu8R",1,1,2,2)
                    +0.004171*ewgc("Cqu8R",2,2,0,0)+0.000098*ewgc("Cqu8R",2,2,1,1)+0.000118*ewgc("CuBR",2,2)
                    +0.002011*ewgc("Cud8R",2,2,0,0)+0.000196*ewgc("Cud8R",2,2,1,1)-0.045686*ewgc("CuGR",2,2)
                    +0.011095*ewgc("CuuR",0,2,2,0)+0.000255*ewgc("CuuR",1,2,2,1)+-0.000811*ewgc("CuWR",2,2))
                    *(SM_sigma_ttz_bin_150_250/sigma_ttz_bin_150_250_madgraph);
        }
        
    } else if(b_min == 250 && b_max == 500){
        
        double SM_sigma_ttz_bin_250_500 = SM.getOptionalParameter("SM_sigma_ttz_bin_250_500_CMS_190711270");
        double sigma_ttz_bin_250_500_madgraph = 0.067464; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
                    
            return SM_sigma_ttz_bin_250_500 + (-0.031862*ewgc("CG")+-0.007411*ewgc("CHq1R",2,2)+0.007439*ewgc("CHq3R",2,2)
                    +0.005451*ewgc("CHuR",2,2)+0.002779*ewgc("Cqd8R",2,2,0,0)+0.000235*ewgc("Cqd8R",2,2,1,1)
                    +0.019482*ewgc("Cqq1R",0,2,2,0)+0.000381*ewgc("Cqq1R",1,2,2,1)+0.060750*ewgc("Cqq3R",0,2,2,0)
                    +0.003621*ewgc("Cqq3R",1,2,2,1)+0.007854*ewgc("Cqu8R",0,0,2,2)+0.000404*ewgc("Cqu8R",1,1,2,2)
                    +0.003938*ewgc("Cqu8R",2,2,0,0)+0.000089*ewgc("Cqu8R",2,2,1,1)+0.000042*ewgc("CuBR",2,2)
                    +0.001798*ewgc("Cud8R",2,2,0,0)+0.000162*ewgc("Cud8R",2,2,1,1)-0.026610*ewgc("CuGR",2,2)
                    +0.011353*ewgc("CuuR",0,2,2,0)+0.000235*ewgc("CuuR",1,2,2,1)+-0.000517*ewgc("CuWR",2,2))
                    *(SM_sigma_ttz_bin_250_500/sigma_ttz_bin_250_500_madgraph);
        }
        
    }  else throw std::runtime_error("wrong bin choice in sigma_ttz_diff_LO_CMS_190711270");
    
}





sigma_ttz_diff_LO_ATLAS_210312603::sigma_ttz_diff_LO_ATLAS_210312603(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{

    setParametersForObservable(make_vector<std::string>() << "SM_sigma_ttz_bin_0_40_ATLAS_210312603" << "SM_sigma_ttz_bin_40_70_ATLAS_210312603"
            << "SM_sigma_ttz_bin_70_110_ATLAS_210312603" << "SM_sigma_ttz_bin_110_160_ATLAS_210312603" << "SM_sigma_ttz_bin_160_220_ATLAS_210312603" 
            << "SM_sigma_ttz_bin_220_290_ATLAS_210312603" << "SM_sigma_ttz_bin_290_400_ATLAS_210312603");

    
};


double sigma_ttz_diff_LO_ATLAS_210312603::computeThValue()
{
    
    b_min = getBinMin();
    b_max = getBinMax();
    
    bool   flag_Quadratic= false; //Needs to be properly defined
   
    if(b_min == 0 && b_max == 40){
        
        double SM_sigma_ttz_bin_0_40 = SM.getOptionalParameter("SM_sigma_ttz_bin_0_40_ATLAS_210312603");
        double sigma_ttz_bin_0_40_madgraph = 0.064177; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
            
            return (sigma_ttz_bin_0_40_madgraph -0.010478*ewgc("CG")-0.005804*ewgc("CHq1R",2,2)
                    +0.005759*ewgc("CHq3R",2,2)+0.002967*ewgc("CHuR",2,2)+0.001126*ewgc("Cqd8R",2,2,0,0)
                    +0.000122*ewgc("Cqd8R",2,2,1,1)
                    +0.008742*ewgc("Cqq1R",0,2,2,0)+0.000211*ewgc("Cqq1R",1,2,2,1)
                    +0.045418*ewgc("Cqq3R",0,2,2,0)+0.004850*ewgc("Cqq3R",1,2,2,1)
                    +0.005860*ewgc("Cqu8R",0,0,2,2)+0.000532*ewgc("Cqu8R",1,1,2,2)
                    +0.000976*ewgc("Cqu8R",2,2,0,0)+0.000001*ewgc("Cqu8R",2,2,1,1)
                    -0.000170*ewgc("CuBR",2,2)+0.000666*ewgc("Cud8R",2,2,0,0)+0.000058*ewgc("Cud8R",2,2,1,1)
                    -0.018690*ewgc("CuGR",2,2)+0.002251*ewgc("CuuR",0,2,2,0)
                    +0.000036*ewgc("CuuR",1,2,2,1)-0.000098*ewgc("CuWR",2,2))
                    *(SM_sigma_ttz_bin_0_40/sigma_ttz_bin_0_40_madgraph);
        }
        
    } else if(b_min == 40 && b_max == 70){
        
        double SM_sigma_ttz_bin_40_70 = SM.getOptionalParameter("SM_sigma_ttz_bin_40_70_ATLAS_210312603");
        double sigma_ttz_bin_40_70_madgraph = 0.096642; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
                    
            return (sigma_ttz_bin_40_70_madgraph -0.018049*ewgc("CG")-0.009212*ewgc("CHq1R",2,2)
                    +0.009177*ewgc("CHq3R",2,2)+0.005078*ewgc("CHuR",2,2)+0.001840*ewgc("Cqd8R",2,2,0,0)
                    +0.000234*ewgc("Cqd8R",2,2,1,1)
                    +0.013449*ewgc("Cqq1R",0,2,2,0)+0.000372*ewgc("Cqq1R",1,2,2,1)
                    +0.065355*ewgc("Cqq3R",0,2,2,0)+0.006633*ewgc("Cqq3R",1,2,2,1)
                    +0.008494*ewgc("Cqu8R",0,0,2,2)+0.000775*ewgc("Cqu8R",1,1,2,2)
                    +0.001722*ewgc("Cqu8R",2,2,0,0)+0.000055*ewgc("Cqu8R",2,2,1,1)
                    -0.000190*ewgc("CuBR",2,2)+0.001097*ewgc("Cud8R",2,2,0,0)
                    +0.000148*ewgc("Cud8R",2,2,1,1)+-0.029042*ewgc("CuGR",2,2)
                    +0.003988*ewgc("CuuR",0,2,2,0)+0.000126*ewgc("CuuR",1,2,2,1)
                    -0.000106*ewgc("CuWR",2,2))
                    *(SM_sigma_ttz_bin_40_70/sigma_ttz_bin_40_70_madgraph);
        }
        
    } else if(b_min == 70 && b_max == 110){
        
        double SM_sigma_ttz_bin_70_110 = SM.getOptionalParameter("SM_sigma_ttz_bin_70_110_ATLAS_210312603");
        double sigma_ttz_bin_70_110_madgraph = 0.127419; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
                    
            return (sigma_ttz_bin_70_110_madgraph-0.028383*ewgc("CG")+-0.012875*ewgc("CHq1R",2,2)+0.012884*ewgc("CHq3R",2,2)
                    +0.007778*ewgc("CHuR",2,2)+0.002468*ewgc("Cqd8R",2,2,0,0)+0.000298*ewgc("Cqd8R",2,2,1,1)
                    +0.017859*ewgc("Cqq1R",0,2,2,0)+0.000464*ewgc("Cqq1R",1,2,2,1)
                    +0.080694*ewgc("Cqq3R",0,2,2,0)+0.007774*ewgc("Cqq3R",1,2,2,1)+0.010371*ewgc("Cqu8R",0,0,2,2)
                    +0.000893*ewgc("Cqu8R",1,1,2,2)+0.002610*ewgc("Cqu8R",2,2,0,0)+0.000063*ewgc("Cqu8R",2,2,1,1)
                    -0.000135*ewgc("CuBR",2,2)+0.001481*ewgc("Cud8R",2,2,0,0)+0.000183*ewgc("Cud8R",2,2,1,1)
                    -0.039573*ewgc("CuGR",2,2)+0.006317*ewgc("CuuR",0,2,2,0)+0.000171*ewgc("CuuR",1,2,2,1)
                    -0.000281*ewgc("CuWR",2,2))
                    *(SM_sigma_ttz_bin_70_110/sigma_ttz_bin_70_110_madgraph);
        }
        
    } else if(b_min == 110 && b_max == 160){
        
        double SM_sigma_ttz_bin_110_160 = SM.getOptionalParameter("SM_sigma_ttz_bin_110_160_ATLAS_210312603");
        double sigma_ttz_bin_110_160_madgraph = 0.118917; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
                    
            return (sigma_ttz_bin_110_160_madgraph -0.032594*ewgc("CG")-0.012662*ewgc("CHq1R",2,2)
                    +0.012643*ewgc("CHq3R",2,2)+0.008236*ewgc("CHuR",2,2)+0.002540*ewgc("Cqd8R",2,2,0,0)
                    +0.000253*ewgc("Cqd8R",2,2,1,1)+0.017566*ewgc("Cqq1R",0,2,2,0)+0.000417*ewgc("Cqq1R",1,2,2,1)
                    +0.071863*ewgc("Cqq3R",0,2,2,0)+0.006279*ewgc("Cqq3R",1,2,2,1)+0.009224*ewgc("Cqu8R",0,0,2,2)
                    +0.000682*ewgc("Cqu8R",1,1,2,2)+0.002931*ewgc("Cqu8R",2,2,0,0)+0.000049*ewgc("Cqu8R",2,2,1,1)
                    +-0.000017*ewgc("CuBR",2,2)+0.001474*ewgc("Cud8R",2,2,0,0)+0.000150*ewgc("Cud8R",2,2,1,1)
                    -0.038866*ewgc("CuGR",2,2)+0.007314*ewgc("CuuR",0,2,2,0)
                    +0.000171*ewgc("CuuR",1,2,2,1)+-0.000599*ewgc("CuWR",2,2))
                    *(SM_sigma_ttz_bin_110_160/sigma_ttz_bin_110_160_madgraph);
        }
        
    } else if(b_min == 160 && b_max == 220){
        
        double SM_sigma_ttz_bin_160_220 = SM.getOptionalParameter("SM_sigma_ttz_bin_160_220_ATLAS_210312603");
        double sigma_ttz_bin_160_220_madgraph = 0.086169; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
                    
            return (sigma_ttz_bin_160_220_madgraph -0.028727*ewgc("CG")+-0.009451*ewgc("CHq1R",2,2)
                    +0.009451*ewgc("CHq3R",2,2)+0.006505*ewgc("CHuR",2,2)+0.002109*ewgc("Cqd8R",2,2,0,0)
                    +0.000210*ewgc("Cqd8R",2,2,1,1)+0.014508*ewgc("Cqq1R",0,2,2,0)
                    +0.000323*ewgc("Cqq1R",1,2,2,1)+0.054025*ewgc("Cqq3R",0,2,2,0)+0.004204*ewgc("Cqq3R",1,2,2,1)
                    +0.006853*ewgc("Cqu8R",0,0,2,2)+0.000457*ewgc("Cqu8R",1,1,2,2)+0.002647*ewgc("Cqu8R",2,2,0,0)
                    +0.000061*ewgc("Cqu8R",2,2,1,1)+0.000070*ewgc("CuBR",2,2)+0.001274*ewgc("Cud8R",2,2,0,0)
                    +0.000130*ewgc("Cud8R",2,2,1,1)+-0.029532*ewgc("CuGR",2,2)
                    +0.006980*ewgc("CuuR",0,2,2,0)+0.000163*ewgc("CuuR",1,2,2,1)+-0.000537*ewgc("CuWR",2,2))
                    *(SM_sigma_ttz_bin_160_220/sigma_ttz_bin_160_220_madgraph);
        }
        
    } else if(b_min == 220 && b_max == 290){
        
        double SM_sigma_ttz_bin_220_290 = SM.getOptionalParameter("SM_sigma_ttz_bin_220_290_ATLAS_210312603");
        double sigma_ttz_bin_220_290_madgraph = 0.051619; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
                    
            return (sigma_ttz_bin_220_290_madgraph -0.020633*ewgc("CG")+-0.005708*ewgc("CHq1R",2,2)
                    +0.005730*ewgc("CHq3R",2,2)+0.004111*ewgc("CHuR",2,2)+0.001568*ewgc("Cqd8R",2,2,0,0)
                    +0.000156*ewgc("Cqd8R",2,2,1,1)+0.010800*ewgc("Cqq1R",0,2,2,0)
                    +0.000238*ewgc("Cqq1R",1,2,2,1)+0.036604*ewgc("Cqq3R",0,2,2,0)+0.002537*ewgc("Cqq3R",1,2,2,1)
                    +0.004688*ewgc("Cqu8R",0,0,2,2)+0.000287*ewgc("Cqu8R",1,1,2,2)+0.002098*ewgc("Cqu8R",2,2,0,0)
                    +0.000060*ewgc("Cqu8R",2,2,1,1)+0.000066*ewgc("CuBR",2,2)+0.000986*ewgc("Cud8R",2,2,0,0)
                    +0.000107*ewgc("Cud8R",2,2,1,1)-0.018706*ewgc("CuGR",2,2)
                    +0.005776*ewgc("CuuR",0,2,2,0)+0.000142*ewgc("CuuR",1,2,2,1)-0.000356*ewgc("CuWR",2,2))
                    *(SM_sigma_ttz_bin_220_290/sigma_ttz_bin_220_290_madgraph);
        }
        
    } else if(b_min == 290 && b_max == 400){
        
        double SM_sigma_ttz_bin_290_400 = SM.getOptionalParameter("SM_sigma_ttz_bin_290_400_ATLAS_210312603");
        double sigma_ttz_bin_290_400_madgraph = 0.032507; //pb
        
        
        if(flag_Quadratic){
        
            return  0.;
            
        }
        else{
                    
            return (sigma_ttz_bin_290_400_madgraph -0.015551*ewgc("CG")+-0.003576*ewgc("CHq1R",2,2)
                    +0.003588*ewgc("CHq3R",2,2)+0.002640*ewgc("CHuR",2,2)+0.001358*ewgc("Cqd8R",2,2,0,0)
                    +0.000110*ewgc("Cqd8R",2,2,1,1)+0.009422*ewgc("Cqq1R",0,2,2,0)
                    +0.000177*ewgc("Cqq1R",1,2,2,1)+0.029289*ewgc("Cqq3R",0,2,2,0)+0.001743*ewgc("Cqq3R",1,2,2,1)
                    +0.003812*ewgc("Cqu8R",0,0,2,2)+0.000192*ewgc("Cqu8R",1,1,2,2)+0.001922*ewgc("Cqu8R",2,2,0,0)
                    +0.000038*ewgc("Cqu8R",2,2,1,1)+0.000016*ewgc("CuBR",2,2)+0.000882*ewgc("Cud8R",2,2,0,0)
                    +0.000076*ewgc("Cud8R",2,2,1,1)-0.012764*ewgc("CuGR",2,2)
                    +0.005527*ewgc("CuuR",0,2,2,0)+0.000108*ewgc("CuuR",1,2,2,1)+-0.000264*ewgc("CuWR",2,2))
                    *(SM_sigma_ttz_bin_290_400/sigma_ttz_bin_290_400_madgraph);
        }
        
    }
    else throw std::runtime_error("wrong bin choice in sigma_ttz_diff_LO_ATLAS_210312603");
   
}



//// s-channel 13 TeV ////

sigma_tb_13_LO::sigma_tb_13_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{
    setParametersForObservable(make_vector<std::string>() << "SM_sigma_tb_13");
};

double sigma_tb_13_LO::computeThValue()
{
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    double sigma_tb_13_LO_madgraph = 8.005990; //pb?
    double sigma_tb_13_SM = SM.getOptionalParameter("SM_sigma_tb_13"); 

    
    
    if(flag_Quadratic){
        return  0.;
        }
        else{
            return sigma_tb_13_SM + (0.970643*ewgc("CHq3R",2,2)-3.718540*ewgc("CuWR",2,2) )*(sigma_tb_13_SM/sigma_tb_13_LO_madgraph);
        }

}




//// t-channel 13 TeV ////

sigma_tq_13_LO::sigma_tq_13_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{
    setParametersForObservable(make_vector<std::string>() << "SM_sigma_tq_13");
};

double sigma_tq_13_LO::computeThValue()
{
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    double sigma_tq_13_LO_madgraph = 186.321000; //pb?
    double sigma_tq_13_SM = SM.getOptionalParameter("SM_sigma_tq_13"); 

    
    
    if(flag_Quadratic){
        return  0.;
        }
        else{
            return sigma_tq_13_SM +(22.491500*ewgc("CHq3R",2,2)-4.598280*ewgc("CuWR",2,2) )*(sigma_tq_13_SM/sigma_tq_13_LO_madgraph);
        }

}



//// taq ////

sigma_taq_LO_CMS::sigma_taq_LO_CMS(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{
    setParametersForObservable(make_vector<std::string>() << "SM_sigma_taq_CMS");
};

double sigma_taq_LO_CMS::computeThValue()
{
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    double sigma_taq_LO_madgraph = 2.176180; //pb?
    double sigma_taq_SM_CMS = SM.getOptionalParameter("SM_sigma_taq_CMS"); 

    
    
    if(flag_Quadratic){
        return  0.;
        }
        else{
           
            return sigma_taq_SM_CMS +(0.262660*ewgc("CHq3R",2,2)-0.003262*ewgc("CuBR",2,2)-0.030453*ewgc("CuWR",2,2))*(sigma_taq_SM_CMS/sigma_taq_LO_madgraph);
        }

}


sigma_taq_LO_ATLAS::sigma_taq_LO_ATLAS(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{
    setParametersForObservable(make_vector<std::string>() << "SM_sigma_taq_ATLAS");
};

double sigma_taq_LO_ATLAS::computeThValue()
{
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    double sigma_taq_LO_madgraph = 2.176180; //pb?
    double sigma_taq_SM_ATLAS = SM.getOptionalParameter("SM_sigma_taq_ATLAS"); 

    
    
    if(flag_Quadratic){
        return  0.;
        }
        else{
            return sigma_taq_SM_ATLAS +(0.262660*ewgc("CHq3R",2,2)-0.003262*ewgc("CuBR",2,2)-0.030453*ewgc("CuWR",2,2))
                    *(sigma_taq_SM_ATLAS/sigma_taq_LO_madgraph);
        }

}



//// tzq ////

sigma_tzq_LO::sigma_tzq_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{
    setParametersForObservable(make_vector<std::string>() << "SM_sigma_tzq");
};

double sigma_tzq_LO::computeThValue()
{
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    double sigma_tzq_LO_madgraph = 0.725915; //pb?
    double sigma_tzq_SM = SM.getOptionalParameter("SM_sigma_tzq"); 

    
    
    if(flag_Quadratic){
        return  0.;
        }
        else{
            return sigma_tzq_SM +(0.015938*ewgc("CHq1R",2,2)+0.141467*ewgc("CHq3R",2,2)
                    +0.004390*ewgc("CHuR",2,2)+-0.002539*ewgc("CuBR",2,2)-0.001949*ewgc("CuWR",2,2))
                    *(sigma_tzq_SM/sigma_tzq_LO_madgraph);
        }

}



//// tw  ////

sigma_tw_13_LO::sigma_tw_13_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{
    setParametersForObservable(make_vector<std::string>() << "SM_sigma_tw_13");
};

double sigma_tw_13_LO::computeThValue()
{
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    double sigma_tw_13_LO_madgraph = 51.021400; //pb?
    double sigma_tw_13_SM = SM.getOptionalParameter("SM_sigma_tw_13"); 
    
//    std::cout<<"\033[1;33m ewgc(\"CuWR\",2,2)*1000000 \033[0m "<< ewgc("CuWR",2,2)*1000000 << std::endl;
//
//    std::cout<<"\033[1;33m sigma_tw_13_LO \033[0m "<< sigma_tw_13_LO_madgraph + 6.152940*ewgc("CHq3R",2,2)+4.361620*ewgc("CuWR",2,2)*1000000 << std::endl;
    
    if(flag_Quadratic){
        return  0.;
        }
        else{
            return sigma_tw_13_SM + (6.152940*ewgc("CHq3R",2,2)+4.361620*ewgc("CuWR",2,2))
                    *(sigma_tw_13_SM/sigma_tw_13_LO_madgraph);
        }

}




//// ttw  ////

sigma_ttw_LO::sigma_ttw_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{
    setParametersForObservable(make_vector<std::string>() << "SM_sigma_ttw");
};

double sigma_ttw_LO::computeThValue()
{
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    double sigma_ttw_LO_madgraph = 0.516319; //pb?
    double sigma_ttw_SM = SM.getOptionalParameter("SM_sigma_ttw"); 

    
    
    if(flag_Quadratic){
        return  0.;
        }
        else{
            return sigma_ttw_SM +(-0.000325*ewgc("CHq1R",2,2)+0.000604*ewgc("CHq3R",2,2)-0.000146*ewgc("CHuR",2,2)
                    +0.184757*ewgc("Cqq1R",0,2,2,0)+0.010580*ewgc("Cqq1R",1,2,2,1)+0.872452*ewgc("Cqq3R",0,2,2,0)
                    +0.054539*ewgc("Cqq3R",1,2,2,1)+0.133233*ewgc("Cqu8R",0,0,2,2)+0.008296*ewgc("Cqu8R",1,1,2,2)
                    +0.000098*ewgc("CuBR",2,2)-0.125985*ewgc("CuGR",2,2)-0.005842*ewgc("CuWR",2,2))
                    *(sigma_ttw_SM/sigma_ttw_LO_madgraph);
        }

}




//// R_ttw  ////

R_ttw_LO::R_ttw_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{
    setParametersForObservable(make_vector<std::string>() << "SM_R_ttw" << "SM_sigma_ttw");

};

double R_ttw_LO::computeThValue()
{
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    double sigma_ttwp_LO_madgraph = 0.349605; //pb?
    double sigma_ttwm_LO_madgraph = 0.166990; //pb?
    double sigma_ttw_SM = SM.getOptionalParameter("SM_sigma_ttw"); 
    double R_ttw_SM = SM.getOptionalParameter("SM_R_ttw"); 

    
    double sigma_ttwp_SM = sigma_ttw_SM/(1+1/R_ttw_SM);
    double sigma_ttwm_SM = sigma_ttw_SM/(1+R_ttw_SM);
    
   
    
    
    if(flag_Quadratic){
        return  0.;
    }
    else{
            
        double sigma_ttwp_NP = -0.000229*ewgc("CHq1R",2,2)+0.000409*ewgc("CHq3R",2,2)+-0.000105*ewgc("CHuR",2,2)
        +0.131627*ewgc("Cqq1R",0,2,2,0)+0.004173*ewgc("Cqq1R",1,2,2,1)+0.622300*ewgc("Cqq3R",0,2,2,0)
        +0.029216*ewgc("Cqq3R",1,2,2,1)+0.095061*ewgc("Cqu8R",0,0,2,2)+0.004239*ewgc("Cqu8R",1,1,2,2)
        +0.000066*ewgc("CuBR",2,2)-0.085559*ewgc("CuGR",2,2)-0.004044*ewgc("CuWR",2,2);
        double sigma_ttwm_NP = -0.000104*ewgc("CHq1R",2,2)+0.000188*ewgc("CHq3R",2,2)+-0.000050*ewgc("CHuR",2,2)
        +0.051853*ewgc("Cqq1R",0,2,2,0)+0.006487*ewgc("Cqq1R",1,2,2,1)+0.251097*ewgc("Cqq3R",0,2,2,0)
        +0.025657*ewgc("Cqq3R",1,2,2,1)+0.038346*ewgc("Cqu8R",0,0,2,2)+0.004035*ewgc("Cqu8R",1,1,2,2)
        +0.000030*ewgc("CuBR",2,2)-0.040504*ewgc("CuGR",2,2)-0.001812*ewgc("CuWR",2,2);
        
        double sigma_ttwp_NP_Corrected = sigma_ttwp_NP*(sigma_ttwp_SM/sigma_ttwp_LO_madgraph);
        double sigma_ttwm_NP_Corrected = sigma_ttwm_NP*(sigma_ttwm_SM/sigma_ttwm_LO_madgraph);
            
        return R_ttw_SM + (sigma_ttwp_NP_Corrected - sigma_ttwm_NP_Corrected*sigma_ttwp_SM/sigma_ttwm_SM)/sigma_ttwm_SM ;
    }

}



/////// Helicities  /////////////////////////////////////////////////////////////////////////////////////



F0_LO::F0_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{
    setParametersForObservable(make_vector<std::string>() << "SM_F0");
};

double F0_LO::computeThValue()
{
    
    bool   flag_Quadratic= false; //Needs to be properly defined
    
    
    double width_total_madgraph = 1.4724;
    double width_long_madgraph = 1.0252;
    
    double F0_madgraph = width_long_madgraph/width_total_madgraph;
    double F0_SM = SM.getOptionalParameter("SM_F0"); 

    
    
    if(flag_Quadratic){
        return  0.;
        }
        else{
        
            //The dependence with CHq3R vanish when dividing by the total width so we have not included it in the final result
            //The dependences with CdWR and CHudR vanish in the limit mb->0 
            //double width_total_NP = 0.009300*ewgc("CdWR",2,2)+0.178518*ewgc("CHq3R",2,2)+0.002502*ewgc("CHudR",2,2)+-0.246222*ewgc("CuWR",2,2);
            //double width_long_NP = +0.003102*ewgc("CdWR",2,2)+0.124307*ewgc("CHq3R",2,2)+0.000840*ewgc("CHudR",2,2)+-0.082068*ewgc("CuWR",2,2);
            
            double width_total_NP = 0.009300*ewgc("CdWR",2,2)+0.002502*ewgc("CHudR",2,2)-0.246222*ewgc("CuWR",2,2);
            double width_long_NP = +0.003102*ewgc("CdWR",2,2)+0.000840*ewgc("CHudR",2,2)-0.082068*ewgc("CuWR",2,2);
            
            double F0_NP = (width_long_NP - width_total_NP*width_long_madgraph/width_total_madgraph)/width_total_madgraph;
            
            return F0_SM + (F0_NP)*(F0_SM/F0_madgraph);
        }

}



FL_LO::FL_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{
    setParametersForObservable(make_vector<std::string>() << "SM_FL");
};

double FL_LO::computeThValue()
{
    
    
    
    bool   flag_Quadratic= false;//Needs to be properly defined
    
    double width_total_madgraph = 1.4724;
    double width_transleft_madgraph = 0.446800;
    double FL_madgraph = width_transleft_madgraph/width_total_madgraph;

    double FL_SM = SM.getOptionalParameter("SM_FL");
    
    

    if(flag_Quadratic){
        return  0.;
        }
    else{
        
        
        //The dependence with CHq3R vanish when dividing by the total width so we have not included it in the final result
        //The dependences with CdWR and CHudR vanish in the limit mb->0 
        //double width_total_NP = 0.009300*ewgc("CdWR",2,2)+0.178518*ewgc("CHq3R",2,2)+0.002502*ewgc("CHudR",2,2)+-0.246222*ewgc("CuWR",2,2);
        //double width_transleft_NP = +0.001108*ewgc("CdWR",2,2)+0.054172*ewgc("CHq3R",2,2)+0.000840*ewgc("CHudR",2,2)+-0.164114*ewgc("CuWR",2,2);
            
        double width_total_NP = 0.009300*ewgc("CdWR",2,2)+0.002502*ewgc("CHudR",2,2)-0.246222*ewgc("CuWR",2,2);
        double width_transleft_NP = +0.001108*ewgc("CdWR",2,2)+0.000840*ewgc("CHudR",2,2)+-0.164114*ewgc("CuWR",2,2);
            
        double FL_NP = (width_transleft_NP - width_total_NP*width_transleft_madgraph/width_total_madgraph)/width_total_madgraph;
            
        return FL_SM + (FL_NP)*(FL_SM/FL_madgraph);
        
        
    }

    
}





FR_LO::FR_LO(const StandardModel& SM_i)
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{
    setParametersForObservable(make_vector<std::string>() << "SM_FR");
};

double FR_LO::computeThValue()
{
    
    
    
    bool   flag_Quadratic= false;//Needs to be properly defined
    
    double width_total_madgraph = 1.4724;
    double width_transright_madgraph = 0.000430;
    double FR_madgraph = width_transright_madgraph/width_total_madgraph;

    double FR_SM = SM.getOptionalParameter("SM_FR");
    
    

    if(flag_Quadratic){
        return  0.;
        }
    else{
        
        
        //The dependence with CHq3R vanish when dividing by the total width so we have not included it in the final result
        //The dependences with CdWR and CHudR vanish in the limit mb->0 
        //double width_total_NP = 0.009300*ewgc("CdWR",2,2)+0.178518*ewgc("CHq3R",2,2)+0.002502*ewgc("CHudR",2,2)+-0.246222*ewgc("CuWR",2,2);
        //double width_transright_NP = 0.005088*ewgc("CdWR",2,2)+0.000052*ewgc("CHq3R",2,2)+0.000840*ewgc("CHudR",2,2)+-0.000034*ewgc("CuWR",2,2);
            
        double width_total_NP = 0.009300*ewgc("CdWR",2,2)+0.002502*ewgc("CHudR",2,2)-0.246222*ewgc("CuWR",2,2);
        double width_transright_NP = 0.005088*ewgc("CdWR",2,2)+0.000840*ewgc("CHudR",2,2)+-0.000034*ewgc("CuWR",2,2);
            
        double FR_NP = (width_transright_NP - width_total_NP*width_transright_madgraph/width_total_madgraph)/width_total_madgraph;
            
        return FR_SM + (FR_NP)*(FR_SM/FR_madgraph);
        
        
    }

    
}



Test_direct::Test_direct(const StandardModel& SM_i) 
: ThObservable(SM_i), mytopobs(static_cast<const NPSMEFTd6General&> (SM))
{ 

    setParametersForObservable(make_vector<std::string>() << "Test_direct_in");
};

double Test_direct::computeThValue()
{
    double Test_direct_in = SM.getOptionalParameter("Test_direct_in");
    
    return Test_direct_in;

    
}



