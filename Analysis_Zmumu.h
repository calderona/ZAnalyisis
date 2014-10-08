//////////////////////////////////////////////////////////
// Universidad de Cantabria 
// Ciencias Físicas - Partículas
// Curso 2014 - 2015 
// Analysis de datos del detector de partículas CMS 
// Author: Alicia Calderon 
// 07 October 2014 - Version v1.2 
// Root version 5.30.06
//////////////////////////////////////////////////////////


////////////////////////////////////////////////////////// 
//
// ================= NOMBRE ALUMNO:  
//
//////////////////////////////////////////////////////////



#ifndef Analysis_Zmumu_h
#define Analysis_Zmumu_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TString.h"

#include <math.h> 
//#include <TVector3.h>
#include <stdlib.h>


#include "Exercise3.h"
#include "Exercise4.h"


// Fixed size dimensions of array or collections stored in the TTree if any.

class Analysis_Zmumu {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
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

   Analysis_Zmumu(TTree *tree=0);
   virtual ~Analysis_Zmumu();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(string sample, bool save, int exe);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   Exercise3 *myEx3;  
   Exercise4 *myEx4; 


};

#endif

#ifdef Analysis_Zmumu_cxx
Analysis_Zmumu::Analysis_Zmumu(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
     // TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
     //if (!f || !f->IsOpen()) {
     //   f = new TFile("Memory Directory");
     //}
     //f->GetObject("ZTree",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("ZTree","");
     

      // DATA 

      chain->Add("nTuples/DoubleMuNtuple.root");

      // SIMULATION

      //chain->Add("nTuples/DoubleMuNtuple_DY.root");

      tree = chain;

#endif // SINGLE_TREE

   }
   Init(tree);
}

Analysis_Zmumu::~Analysis_Zmumu()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Analysis_Zmumu::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Analysis_Zmumu::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Analysis_Zmumu::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
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


   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Run", &Run, &b_Run);
   fChain->SetBranchAddress("Event", &Event, &b_Event);
   fChain->SetBranchAddress("Lumi", &Lumi, &b_Lumi);
   fChain->SetBranchAddress("nPU", &nPU, &b_nPU);
   fChain->SetBranchAddress("Muon_IsGlobalMuon", &Muon_IsGlobalMuon, &b_Muon_IsGlobalMuon);
   fChain->SetBranchAddress("Muon_IsAllTrackerMuons", &Muon_IsAllTrackerMuons, &b_Muon_IsAllTrackerMuons);
   fChain->SetBranchAddress("Muon_IsAllStandAloneMuons", &Muon_IsAllStandAloneMuons, &b_Muon_IsAllStandAloneMuons);
   fChain->SetBranchAddress("Muon_IsTMLastStationAngTight", &Muon_IsTMLastStationAngTight, &b_Muon_IsTMLastStationAngTight);
   fChain->SetBranchAddress("Muon_Px", &Muon_Px, &b_Muon_Px);
   fChain->SetBranchAddress("Muon_Py", &Muon_Py, &b_Muon_Py);
   fChain->SetBranchAddress("Muon_Pz", &Muon_Pz, &b_Muon_Pz);
   fChain->SetBranchAddress("Muon_Pt", &Muon_Pt, &b_Muon_Pt);
   fChain->SetBranchAddress("Muon_deltaPt", &Muon_deltaPt, &b_Muon_deltaPt);
   fChain->SetBranchAddress("Muon_Energy", &Muon_Energy, &b_Muon_Energy);
   fChain->SetBranchAddress("Muon_Charge", &Muon_Charge, &b_Muon_Charge);
   fChain->SetBranchAddress("Muon_NormChi2GTrk", &Muon_NormChi2GTrk, &b_Muon_NormChi2GTrk);
   fChain->SetBranchAddress("Muon_NValidHitsSATrk", &Muon_NValidHitsSATrk, &b_Muon_NValidHitsSATrk);
   fChain->SetBranchAddress("Muon_NumOfMatches", &Muon_NumOfMatches, &b_Muon_NumOfMatches);
   fChain->SetBranchAddress("Muon_Chi2InTrk", &Muon_Chi2InTrk, &b_Muon_Chi2InTrk);
   fChain->SetBranchAddress("Muon_dofInTrk", &Muon_dofInTrk, &b_Muon_dofInTrk);
   fChain->SetBranchAddress("Muon_NValidHitsInTrk", &Muon_NValidHitsInTrk, &b_Muon_NValidHitsInTrk);
   fChain->SetBranchAddress("Muon_NValidPixelHitsInTrk", &Muon_NValidPixelHitsInTrk, &b_Muon_NValidPixelHitsInTrk);
   fChain->SetBranchAddress("Muon_SumIsoCalo", &Muon_SumIsoCalo, &b_Muon_SumIsoCalo);
   fChain->SetBranchAddress("Muon_SumIsoTrack", &Muon_SumIsoTrack, &b_Muon_SumIsoTrack);
   fChain->SetBranchAddress("Muon_dzPV", &Muon_dzPV, &b_Muon_dzPV);
   fChain->SetBranchAddress("Muon_IPPV", &Muon_IPPV, &b_Muon_IPPV);
   Notify();
}

Bool_t Analysis_Zmumu::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Analysis_Zmumu::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Analysis_Zmumu::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Analysis_Zmumu_cxx
