//////////////////////////////////////////////////////////
// Universidad de Cantabria 
// Ciencias Físicas - Partículas
// Curso 2014 - 2015 
// EXERCISE NUMBER 4 :: Analysis de datos del detector de partículas CMS 
// Author: Alicia Calderon 
// 07 October 2014 - Version v1.2 
// Root version 5.30.06
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
//
// ================= NOMBRE ALUMNO:  
//
//////////////////////////////////////////////////////////



#ifndef EXERCISE4_H
#define EXERCISE4_H

#include <TH2.h>
#include <TH1.h>
#include <TROOT.h>
#include <TBranch.h>


class Exercise4 {


public:

  Exercise4(TTree *tree, bool save, string sample);
  ~Exercise4(); 
  

 //--- INITIALIZE FUNCTIONS

  Bool_t IsInitialized() const { return fIsInitialized; } 

  void Initialize(TTree *tree, bool save, string sample);

  void FillHistograms(Long64_t jentry);

  bool isGoodMuonISO (int iMu);

  void SaveHistrograms(bool save, string sample); 

  bool isGoodGLBMuonID (int iMu);





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

   TH1F *h_Mu_cutWorkflow;

   TH1F *h_Mu_pt_all;

   TH1F *h_Mu_pt_GoodMu;

   TH1F *h_Mu_eta_all;

   TH1F *h_Mu_eta_GoodMu;

   TH1F *h_Mu_InvMass_all;

   TH1F *h_Mu_InvMass_GoodMu;

   TH1F *h_Mu_ZInvMass_GlbGlb;
  
   TH1F *h_Mu_ZInvMass_StaSta;

   TH1F *h_Mu_ZInvMass_TkTk;

   TH1F *h_Mu_ZInvMass_GoodMu;

   //--- 2D H
   




  //--- DEFINE FILES

   TFile  *outputFile;


protected:
  
  Bool_t                    fIsInitialized;



};

#endif
