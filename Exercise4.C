//////////////////////////////////////////////////////////
// Universidad de Cantabria 
// Ciencias Físicas - Partículas
// Curso 2014 - 2015 
// Analysis de datos del detector de partículas CMS 
// Autor: Alicia Calderon 
// 07 October 2014 - Version v1.2 
// Root version 5.30.06
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
//
// ================= NOMBRE ALUMNO:  
//
//////////////////////////////////////////////////////////





#include "Exercise4.h"

#include <TFile.h>
#include <math.h>

#include <iostream>
#include <fstream>
#include <TH2.h>
#include <TH1.h>
#include <TChain.h>

#include "TLorentzVector.h"

using namespace std;

//--------------------------------------------------------------------------------------------------


Exercise4::Exercise4(TTree *tree, bool save, string sample) : 
  fIsInitialized(kFALSE) {

  cout << "-----------------------------------" << endl;
  cout << "Creating constructor for Exercise 4" << endl;
  cout << "-----------------------------------" << endl;

  Initialize(tree, save, sample); 

}

//-------------------------------------------------------------------------------------------------

Exercise4::~Exercise4() {};


void Exercise4::Initialize(TTree *tree, bool save, string sample) { 

 if (!tree) return;
 
 TChain* mytree = new TChain("ZTree", "ZTree");
 mytree->Add("nTuples/DoubleMuNtuple.root");

 if (save) { 

   if (sample == "data") outputFile = new TFile("output/Histograms_Exercise4.root", "RECREATE"); 
   if (sample == "mc") outputFile = new TFile("output/Histograms_Exercise4_DY.root", "RECREATE"); 
 }


 cout << "1 ---- Initializing variables" << endl;

 //--- DEFINE VARIABLES TO BE USED
 Muon_IsGlobalMuon = 0;
 Muon_IsAllTrackerMuons = 0;
 Muon_IsAllStandAloneMuons = 0;
 Muon_IsTMLastStationAngTight = 0;
 Muon_Px = 0;
 Muon_Py = 0;
 Muon_Pz = 0;
 Muon_Pt = 0;
 Muon_deltaPt = 0;
 Muon_Energy = 0;
 Muon_Charge = 0;
 Muon_NormChi2GTrk = 0;
 Muon_NValidHitsSATrk = 0;
 Muon_NumOfMatches = 0;
 Muon_Chi2InTrk = 0;
 Muon_dofInTrk = 0;
 Muon_NValidHitsInTrk = 0;
 Muon_NValidPixelHitsInTrk = 0;
 Muon_SumIsoCalo = 0;
 Muon_SumIsoTrack = 0;
 Muon_dzPV = 0;
 Muon_IPPV = 0;
  

 //--- SET BRACH ADDRESS 
 tree->SetBranchAddress("Run", &Run, &b_Run);
 tree->SetBranchAddress("Event", &Event, &b_Event);
 tree->SetBranchAddress("Lumi", &Lumi, &b_Lumi);
 tree->SetBranchAddress("nPU", &nPU, &b_nPU);
 tree->SetBranchAddress("Muon_IsGlobalMuon", &Muon_IsGlobalMuon, &b_Muon_IsGlobalMuon);
 tree->SetBranchAddress("Muon_IsAllTrackerMuons", &Muon_IsAllTrackerMuons, &b_Muon_IsAllTrackerMuons);
 tree->SetBranchAddress("Muon_IsAllStandAloneMuons", &Muon_IsAllStandAloneMuons, &b_Muon_IsAllStandAloneMuons);
 tree->SetBranchAddress("Muon_IsTMLastStationAngTight", &Muon_IsTMLastStationAngTight, &b_Muon_IsTMLastStationAngTight);
 tree->SetBranchAddress("Muon_Px", &Muon_Px, &b_Muon_Px);
 tree->SetBranchAddress("Muon_Py", &Muon_Py, &b_Muon_Py);
 tree->SetBranchAddress("Muon_Pz", &Muon_Pz, &b_Muon_Pz);
 tree->SetBranchAddress("Muon_Pt", &Muon_Pt, &b_Muon_Pt);
 tree->SetBranchAddress("Muon_deltaPt", &Muon_deltaPt, &b_Muon_deltaPt);
 tree->SetBranchAddress("Muon_Energy", &Muon_Energy, &b_Muon_Energy);
 tree->SetBranchAddress("Muon_Charge", &Muon_Charge, &b_Muon_Charge);
 tree->SetBranchAddress("Muon_NormChi2GTrk", &Muon_NormChi2GTrk, &b_Muon_NormChi2GTrk);
 tree->SetBranchAddress("Muon_NValidHitsSATrk", &Muon_NValidHitsSATrk, &b_Muon_NValidHitsSATrk);
 tree->SetBranchAddress("Muon_NumOfMatches", &Muon_NumOfMatches, &b_Muon_NumOfMatches);
 tree->SetBranchAddress("Muon_Chi2InTrk", &Muon_Chi2InTrk, &b_Muon_Chi2InTrk);
 tree->SetBranchAddress("Muon_dofInTrk", &Muon_dofInTrk, &b_Muon_dofInTrk);
 tree->SetBranchAddress("Muon_NValidHitsInTrk", &Muon_NValidHitsInTrk, &b_Muon_NValidHitsInTrk);
 tree->SetBranchAddress("Muon_NValidPixelHitsInTrk", &Muon_NValidPixelHitsInTrk, &b_Muon_NValidPixelHitsInTrk);
 tree->SetBranchAddress("Muon_SumIsoCalo", &Muon_SumIsoCalo, &b_Muon_SumIsoCalo);
 tree->SetBranchAddress("Muon_SumIsoTrack", &Muon_SumIsoTrack, &b_Muon_SumIsoTrack);
 tree->SetBranchAddress("Muon_dzPV", &Muon_dzPV, &b_Muon_dzPV);
 tree->SetBranchAddress("Muon_IPPV", &Muon_IPPV, &b_Muon_IPPV);

 cout << "2 ---- Initializing histograms" << endl;
 cout << "" << endl;


 //--- INITIALIZE HISTOGRAMS
 test = new TH1F("test","test",20,0,200);

 h_Mu_cutWorkflow = new TH1F("h_Mu_cutWorkflow","Number of muons after each cut",10 ,1 ,11); 

 h_Mu_pt_all = new TH1F("h_Mu_pt_all","All muons transverse momentum",100,0,100); 

 h_Mu_pt_GoodMu = new TH1F("h_Mu_pt_GoodMu","Good muons transverse momentum",100,0,100); 

 h_Mu_eta_all = new TH1F("h_Mu_eta_all","All muons eta angle",50,-2.5,2.5);
 
 h_Mu_eta_GoodMu = new TH1F("h_Mu_eta_GoodMu","Good muons eta angle",50,-2.5,2.5); 

 h_Mu_InvMass_all = new TH1F("h_Mu_InvMass_all","MuMu Invariant mass",200,0,200);

 h_Mu_InvMass_GoodMu = new TH1F("h_Mu_InvMass_GoodMu","MuMu Invariant mass for Good Muons",200,0,200);

 h_Mu_ZInvMass_GlbGlb = new TH1F("h_Mu_ZInvMass_GlbGlb","MuMu Invariant mass Glb+Glb",60,60,120);

 h_Mu_ZInvMass_StaSta = new TH1F("h_Mu_ZInvMass_StaSta","MuMu Invariant mass Sta+Sta",60,60,120);

 h_Mu_ZInvMass_TkTk = new TH1F("h_Mu_ZInvMass_TkTk","MuMu Invariant mass Tk+Tk",60,60,120);

 h_Mu_ZInvMass_GoodMu = new TH1F("h_Mu_ZInvMass_GoodMu","MuMu Invariant mass for Good Muons",60,60,120);

};


void Exercise4::FillHistograms(Long64_t jentry) { 

  if(jentry == 0) cout << "...... Running ......" << endl;
  

  // ===== 1. Select good muons 

  for( unsigned int iMu = 0; iMu < Muon_Charge->size(); iMu++) { //Loop over all muons. 


    // ... TO DO ... //
    // --> Study the efficiency of each muon ID and ISO cuts
    
    h_Mu_cutWorkflow->Fill(1);  



    // ... TO DO ... //
    // -->  Define pt and eta before and after good muon selection.

    TLorentzVector Muon;
    Muon.SetPxPyPzE(Muon_Px->at(iMu),Muon_Py->at(iMu),Muon_Pz->at(iMu), Muon_Energy->at(iMu));

    h_Mu_pt_all->Fill(Muon.Pt());

    h_Mu_eta_all->Fill(Muon.Eta());

    if (!isGoodGLBMuonID(iMu)) continue;
    if (!isGoodMuonISO(iMu)) continue; 
    
    h_Mu_pt_GoodMu->Fill(Muon.Pt());

    h_Mu_eta_GoodMu->Fill(Muon.Eta());
    
  } // end loop over all muons




  
      
  // ===== 2. Select those events with pair of muons in the final state: hypotesis, we are looking for 
  // pair of muons from a Z boson decay.



  // ... TO DO ... //
  // Pair of muons


  // ... TO DO ... //
  // Remember how we define the cuadrimoment of each muon and how we 
  // define invariant mass (what at the end we want!) 
  
  float Mass = 0;

  // --> invarian mass for all muons all muons

  h_Mu_InvMass_all->Fill(Mass);
      


  // ... TO DO ... //
  // Do distributions selecting events only inside the Z mass peak. 
  if ( true ) {

    int aMu = 0;
    int bMu = 1; 
    
    // --> only global muons 
    if ( Muon_IsGlobalMuon->at(aMu) && Muon_IsGlobalMuon->at(bMu))  
      h_Mu_ZInvMass_GlbGlb->Fill(Mass);
    
    // --> only STA muons 
    if ( Muon_IsAllStandAloneMuons->at(aMu) && Muon_IsAllStandAloneMuons->at(bMu) ) 
      h_Mu_ZInvMass_StaSta->Fill(Mass);
    
    // --> only TK muons 
    if ( Muon_IsAllTrackerMuons->at(aMu) && Muon_IsAllTrackerMuons->at(bMu) ) 
      h_Mu_ZInvMass_TkTk->Fill(Mass);
  }	   



  // ... TO DO ... //
  // --> select high quality isolated pair of muons and plot the invariant mass.  

  h_Mu_InvMass_GoodMu->Fill(Mass);
  

  //Only selected events inside de Z mass window. 
  if (true ) h_Mu_ZInvMass_GoodMu->Fill(Mass);




      // obtener la masa con un fit a la señal y al fondo. 
      // Que masa medimos y que anchura? es comparable a la del DPG ? 


  

    

};



bool Exercise4::isGoodGLBMuonID (int iMu) {

  bool isGoodMu = false;

  if ( true

      // ... TO DO ... //
      // define selection 

)  isGoodMu = true;

    return isGoodMu;
}



bool Exercise4::isGoodMuonISO (int iMu) {

  bool isGoodMu = false;
  
  // ... TO DO ... //
  // define isolation 
 
  return isGoodMu;
}



void Exercise4::SaveHistrograms(bool save, string sample) { 
 
  if (save) { 
    outputFile->Write("",TObject::kOverwrite);
    outputFile->Close();

    cout << "" << endl;
    if(sample == "data")  cout << "3 ---- Create output file: output/Histrograms_Exercise4.root" << endl;
    if(sample == "mc")  cout << "3 ---- Create output file: output/Histrograms_Exercise4_DY.root" << endl;
    cout << "" << endl;
  }

};
