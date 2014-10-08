//////////////////////////////////////////////////////////
// Universidad de Cantabria 
// Ciencias Físicas - Partículas
// Curso 2013 - 2014 
// Analysis de datos del detector de partículas CMS 
// Autor: Alicia Calderon 
// 10 September 2013 - Version v1.1 
// Root version 5.30.06
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
//
// ================= AÑO ACADEMICO: 
//
// ================= NOMBRE ALUMNO:  
//
//////////////////////////////////////////////////////////




#include "TF1.h"
#include "TH1.h"
#include "TMath.h"

void doPlotsExercise5( string sample, int fit){

  // LOADING MACROS. 

  gInterpreter->LoadMacro   ("utils/draw.C+");
  gROOT->LoadMacro("utils/ZmassFitFunctions.C");


  gStyle      ->SetOptStat  (1);
  gStyle      ->SetPalette  (1);

  gStyle->SetOptFit(111111);
  
  SetupEnviorement();


  //------------------------------------------
  //Load the .root files to use in this script
  //------------------------------------------
  
  TString pwd1 = "output/";
  
  TFile* data = 0;
  TFile* mc = 0;

  if ( sample == "data" ) { 
    data = TFile::Open(pwd1  + "Histograms_Exercise4.root");
  } 
  else if ( sample == "MC"  ) { 
    mc = TFile::Open(pwd1  + "Histograms_Exercise4_DY.root");
  }
  else cout << "No available option  ......" << endl;


  if ( sample == "data" ) {

    //-- Firts step:: Fit DATA 

    data->cd();

    TCanvas *Mu_1 = new TCanvas("Mu_1","Mu_1",800,800);
    
    DrawTH1F(Mu_1, h_Mu_ZInvMass_GoodMu,"sameE1","","","");
    LineOpt(h_Mu_ZInvMass_GoodMu,kBlue,2,kSolid);
    MarkerOpt(h_Mu_ZInvMass_GoodMu,kBlue,1,kFullCircle);

    DrawLegend(0.25,0.70,h_Mu_ZInvMass_GoodMu , "Data", "LP",0.030,0.12, 0.10);


    /// Standar Gauss function
    if( fit == 1)    {
     
      TH1F *Zmass_1 = (TH1F*) h_Mu_ZInvMass_GoodMu->Clone();   

      Zmass_1->Fit("gaus"); 

      TF1 *Zfit = Zmass_1->GetFunction("gaus");

      Zfit->SetLineColor(kRed);

    }

    /// Custom Gauss function
    if (fit == 2) { 

      TH1F *Zmass_2 = (TH1F*) h_Mu_ZInvMass_GoodMu->Clone();

      int   division = Zmass_2->GetNbinsX();
      float massMIN = Zmass_2->GetBinLowEdge(1);
      float massMAX = Zmass_2->GetBinLowEdge(division+1);
      float BIN_SIZE = Zmass_2->GetBinWidth(1);

      TF1 *func = new TF1("mygauss",mygauss,massMIN, massMAX,3);

      func->SetParameter(0, 1);
      func->SetParameter(2, 5);
      func->SetParameter(1, 95);


      Zmass_2->Fit("mygauss","QR");

      TF1 *Zfit = Zmass_2->GetFunction("mygauss");

      Zfit->SetLineColor(kRed);


      // Printout fit results
      Double_t chi2 = Zfit->GetChisquare();
      Double_t p1 = Zfit->GetParameter(1);
      Double_t e1 = Zfit->GetParError(1);

      Double_t p2 = Zfit->GetParameter(2);
      Double_t e2 = Zfit->GetParError(2);

      cout << " " << endl;
      cout << " ------ Results from Gauss Fit ------ " << endl; 
      cout << " Chi2: " << chi2 << endl;
      cout << " Mean: " << p1 << endl; 
      cout << " RMS: " << p2 << endl; 
      cout << " " << endl;


    }



/// Custom Breit-Wigner function
    
    if (fit == 4) { 

      TH1F *Zmass_4 = (TH1F*) h_Mu_ZInvMass_GoodMu->Clone();

      int   division = Zmass_4->GetNbinsX();
      float massMIN = Zmass_4->GetBinLowEdge(1);
      float massMAX = Zmass_4->GetBinLowEdge(division+1);
      float BIN_SIZE = Zmass_4->GetBinWidth(1);

      TF1 *func = new TF1("mybw",mybw,massMIN, massMAX,3);

      func->SetParameter(0, 1);
      func->SetParameter(2, 5);
      func->SetParameter(1, 95);


      Zmass_4->Fit("mybw","QR");

      TF1 *Zfit = Zmass_4->GetFunction("mybw");

      Zfit->SetLineColor(kRed);


      // Printout fit results
      Double_t chi2 = Zfit->GetChisquare();
      Double_t p1 = Zfit->GetParameter(1);
      Double_t e1 = Zfit->GetParError(1);

      Double_t p2 = Zfit->GetParameter(2);
      Double_t e2 = Zfit->GetParError(2);

      cout << " " << endl;
      cout << " ------ Results from Breit-Wigner Fit ------ " << endl; 
      cout << " Chi2: " << chi2 << endl;
      cout << " Mean: " << p2 << endl; 
      cout << " RMS: " << p1 << endl; 
      cout << " " << endl;

    }



  }




}
