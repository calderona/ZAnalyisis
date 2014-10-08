//////////////////////////////////////////////////////////
// Universidad de Cantabria 
// Ciencias Físicas - Partículas
// Curso 2014 - 2015 
// EXERCISE NUMBER 3 :: Analysis de datos del detector de partículas CMS 
// Author: Alicia Calderon 
// 07 October 2014 - Version v1.2 
// Root version 5.30.06
//////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////
//
// ================= NOMBRE ALUMNO:  
//
//////////////////////////////////////////////////////////


#ifndef EXERCISE3_H
#define EXERCISE3_H

#include <TH2.h>
#include <TH1.h>
#include <TROOT.h>
#include <TBranch.h>

class Exercise3 {


public:

  Exercise3(TTree *tree, bool save, string sample);
  ~Exercise3(); 
  

 //--- INITIALIZE FUNCTIONS

  Bool_t IsInitialized() const { return fIsInitialized; } 

  void Initialize(TTree *tree, bool save, string sample);

  void FillHistograms(Long64_t jentry);

  void SaveHistrograms(bool save, string sample); 


  //--- DEFINE VARIABLES
 
  Int_t           Run;
  Int_t           Event;
  Int_t           Lumi;
  Int_t           nPU;
  vector<bool>    *Muon_IsGlobalMuon;
  vector<bool>    *Muon_IsAllTrackerMuons;
  vector<bool>    *Muon_IsAllStandAloneMuons;
  vector<bool>    *Muon_IsTMLastStationAngTight;  
  vector<float>   *Muon_Px;
  vector<float>   *Muon_Py;
  vector<float>   *Muon_Pz;
  vector<float>   *Muon_Pt;
  vector<float>   *Muon_deltaPt;
  vector<float>   *Muon_Energy;
  vector<int>     *Muon_Charge;
  vector<float>   *Muon_NormChi2GTrk;
  vector<int>     *Muon_NValidHitsSATrk;
  vector<int>     *Muon_NumOfMatches;
  vector<float>   *Muon_Chi2InTrk;
  vector<float>   *Muon_dofInTrk;
  vector<int>     *Muon_NValidHitsInTrk;
  vector<int>     *Muon_NValidPixelHitsInTrk;
  vector<float>   *Muon_SumIsoCalo;
  vector<float>   *Muon_SumIsoTrack;
  vector<float>   *Muon_dzPV;
  vector<float>   *Muon_IPPV;

  // List of branches
   TBranch        *b_Run;   //!
   TBranch        *b_Event;   //!
   TBranch        *b_Lumi;   //!
   TBranch        *b_nPU;   //!
   TBranch        *b_Muon_IsGlobalMuon;   //!
   TBranch        *b_Muon_IsAllTrackerMuons;   //!
   TBranch        *b_Muon_IsAllStandAloneMuons;   //!
   TBranch        *b_Muon_IsTMLastStationAngTight;   //!
   TBranch        *b_Muon_Px;   //!
   TBranch        *b_Muon_Py;   //!
   TBranch        *b_Muon_Pz;   //!
   TBranch        *b_Muon_Pt;   //!
   TBranch        *b_Muon_deltaPt;   //!
   TBranch        *b_Muon_Energy;   //!
   TBranch        *b_Muon_Charge;   //!
   TBranch        *b_Muon_NormChi2GTrk;   //!
   TBranch        *b_Muon_NValidHitsSATrk;   //!
   TBranch        *b_Muon_NumOfMatches;   //!
   TBranch        *b_Muon_Chi2InTrk;   //!
   TBranch        *b_Muon_dofInTrk;   //!
   TBranch        *b_Muon_NValidHitsInTrk;   //!
   TBranch        *b_Muon_NValidPixelHitsInTrk;   //!
   TBranch        *b_Muon_SumIsoCalo;   //!
   TBranch        *b_Muon_SumIsoTrack;   //!
   TBranch        *b_Muon_dzPV;   //!
   TBranch        *b_Muon_IPPV;   //!

   //--- DEFINE HISTOGRAMS

   //--- 1D H
   
   TH1F *test;
   
   TH1F *h_nPV;
   TH1F *h_Mu_px;
   TH1F *h_Mu_py;
   TH1F *h_Mu_pz;
   TH1F *h_Mu_pt;
   TH1F *h_Mu_pt_fromPxAndPy;
   TH1F *h_Mu_eta_fromTLorentz;
   TH1F *h_Mu_phi_fromTLorentz;
   TH1F *h_Mu_phi;
   TH1F *h_Mu_deltaPt;
   TH1F *h_Mu_deltaPt_overPt;
   TH1F *h_Mu_NormChi2GTrk;
   TH1F *h_Mu_NumOfMatches;
   TH1F *h_Mu_SumIsoCalo;
   TH1F *h_Mu_SumIsoTrack;
   TH1F *h_Mu_RelativeIso;
   TH1F *h_Mu_dzPV;
   TH1F *h_Mu_IPPV;
   TH1F *h_Mu_NValidHitsSATrk;
   TH1F *h_Mu_NValidHitsInTrk;
   TH1F *h_Mu_NValidPixelHitsInTrk;
   TH1F *h_Mu_type;

   //--- 2D H
   
   TH2F *h_Mu_Nhits_eta;
   TH2F *h_Mu_Nhits_phi;
   TH2F *h_Mu_Npixel_eta;
   TH2F *h_Mu_NValidHitsSATrk_eta;



  //--- DEFINE FILES

   TFile  *outputFile;


protected:
  
  Bool_t                    fIsInitialized;



};

#endif
