//////////////////////////////////////////////////////////
// Universidad de Cantabria 
// Ciencias F-Amsicas - Partmculas
// Curso 2013 - 2014 
// Analysis de datos del detector de partmculas CMS 
// Autor: Alicia Calderon 
// 10 September 2013 - Version v1.1 
// Root version 5.30.06
//////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////
//
// ================= AQO ACADEMICO: 
//
// ================= NOMBRE ALUMNO:  
//
//////////////////////////////////////////////////////////





#include "Exercise3.h"

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


Exercise3::Exercise3(TTree *tree, bool save, string sample) : 
  fIsInitialized(kFALSE) {

  cout << "-----------------------------------" << endl;
  cout << "Creating constructor for Exercise 3" << endl;
  cout << "-----------------------------------" << endl;

  Initialize(tree, save, sample); 

}

//-------------------------------------------------------------------------------------------------

Exercise3::~Exercise3() {};


void Exercise3::Initialize(TTree *tree, bool save, string sample) { 

  if (!tree) return;

 TChain* mytree = new TChain("ZTree", "ZTree");
 mytree->Add("nTuples/DoubleMuNtuple.root");

 if (save) { 

   if (sample == "data") outputFile = new TFile("output/Histograms_Exercise3.root", "RECREATE"); 
   if (sample == "mc") outputFile = new TFile("output/Histograms_Exercise3_DY.root", "RECREATE"); 
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

 h_nPV = new TH1F("h_nPV","Number of PV",30,0,30);

 h_Mu_px = new TH1F("h_Mu_px","Muon Px momentum component",100,0,100);
 
 h_Mu_py = new TH1F("h_Mu_py","Muon Py momentum component",100,0,100);
 
 h_Mu_pz = new TH1F("h_Mu_pz","Muon Pz momentum component",100,0,100);
 
 h_Mu_pt = new TH1F("h_Mu_pt","Muon transverse momentum",100,0,100); 
 
 h_Mu_pt_fromPxAndPy = new TH1F("h_Mu_pt_fromPxAndPy","Muon transverse momentum from Px and Py", 100,0,100);
 
 h_Mu_eta_fromTLorentz = new TH1F("h_Mu_eta_fromTLorentz","Muon eta angle",50,-2.5,2.5); 
 
 h_Mu_phi_fromTLorentz = new TH1F("h_Mu_phi_fromTLorentz","Muon phi angle",50,-3.2,3.2); 

 h_Mu_Nhits_eta = new TH2F("h_Mu_Nhits_eta", "Number of Tk hits vs eta angle",50,-2.5,2.5,35,0,35);
 
 h_Mu_Nhits_phi = new TH2F("h_Mu_Nhits_phi", "Number of Tk hits vs phi angle",50,-3.2,3.2,35,0,35);
 
 h_Mu_Npixel_eta =  new TH2F("h_Mu_Npixel_eta","Number of Tk pixels vs eta angle",50,-2.5,2.5,10,0,10);

 h_Mu_deltaPt = new TH1F("h_Mu_deltaPt","Error on the transverse mometum assignment",30,0,30);
 
 h_Mu_deltaPt_overPt = new TH1F("h_Mu_deltaPt_overPt","Relative error on the transverse mometum assignment,",50,0,0.2);

 h_Mu_NormChi2GTrk  = new TH1F("h_Mu_NormChi2GTrk","Normalize Chi2 of the GLB track",50,0,50);

 h_Mu_NValidHitsSATrk = new TH1F("h_Mu_NValidHitsSATrk","Number of Sta hits",50,0,50);

 h_Mu_NValidHitsSATrk_eta = new TH2F("h_Mu_NValidHitsSATrk_eta","Number of Sta hits vs eta angle",50,-2.5,2.5,50,0,50);

 h_Mu_NumOfMatches = new TH1F("h_Mu_NumOfMatches","Number of Muon chambers matchets",10,0,10);

 h_Mu_NValidHitsInTrk = new TH1F("h_Mu_NValidHitsInTrk","Number of Tk hits",35,0,35);

 h_Mu_NValidPixelHitsInTrk = new TH1F("h_Mu_NValidPixelHitsInTrk","Number of Tk pixel",10,0,10);

 h_Mu_SumIsoCalo = new TH1F("h_Mu_SumIsoCalo","Sum of energy in the calorimeters around the muon",100,0,200);

 h_Mu_SumIsoTrack = new TH1F("h_Mu_SumIsoTrack","Sum of pt of the tracks in Tk around the muon",100,0,200);

 h_Mu_RelativeIso = new TH1F("h_Mu_RelativeIso","RelativeIso = IsoCalo+IsoTrack / Mu_pt",100,0,1);

 h_Mu_dzPV = new TH1F("h_Mu_dzPV","Distance of each muon vertex to the primary vertex in Z axis",80,-40,40);

 h_Mu_IPPV = new TH1F("h_Mu_IPPV","Distance of each muon vertex to the primary vertex in XY plane",45,0,45);

 h_Mu_type = new TH1F("h_Mu_type","Types of muons",7,0,7);



};


void Exercise3::FillHistograms(Long64_t jentry) { 

  if(jentry == 0.0) cout << "...... Running ......" << endl;
  
  //Number of reconstructed vertex per events.
  h_nPV->Fill(nPU);
 

  for( unsigned int Mu = 0.0; Mu < Muon_Charge->size(); Mu++) { 
    

    // ======= 1. Components of the muon momentum 
    float px,py;
    px = Muon_Px->at(Mu);
    py = Muon_Py->at(Mu);
 
    h_Mu_px->Fill(Muon_Px->at(Mu));
  
    // --> TO DO ... // 



    // ======= 2. Angular muon distributions.

    //Remember how Eta angle is defined: Ng = −ln(tan(Nh/2)

    TLorentzVector iMu;
    iMu.SetPxPyPzE(Muon_Px->at(Mu),Muon_Py->at(Mu),Muon_Pz->at(Mu), Muon_Energy->at(Mu));
    
    h_Mu_eta_fromTLorentz->Fill(iMu.Eta());
    h_Mu_phi_fromTLorentz->Fill(iMu.Phi());




    // ======= 3. Hits and pixel variables. 

    h_Mu_NValidHitsInTrk->Fill(Muon_NValidHitsInTrk->at(Mu));
  
    // ... TO DO ... // 




    // ======= 4. Error on transverse momentum assignment
    
    h_Mu_deltaPt->Fill(Muon_deltaPt->at(Mu));

    //Error? 

    // ... TO DO ... // 



    // ======= 5. Normalize Chi2 of the GLB track
   
    // ... TO DO ... // 

 


    // ======= 6. Muon isolation
   
    h_Mu_SumIsoCalo->Fill(Muon_SumIsoCalo->at(Mu));
    h_Mu_SumIsoTrack->Fill(Muon_SumIsoTrack->at(Mu));

    //relative isolation?
 
    // ... TO DO ... // 
    



    // ======= 7. Distance of earch muon vertex to the primary vertex reconstructed in each event
  
    // ... TO DO ... // 
 

    // ======= 8. Number of muons of different type
    
    // Which different selection you can do based on GLB, TK and/or STA muons? 

    if (Muon_IsGlobalMuon->at(Mu)) h_Mu_type->Fill(0); 

    // ... TO DO ... // 


    // ======= 9. Define a muon selection cut sequence and plot kinematical variables (phi, eta, pt...) after such selection...

    // ... TO DO ... // 



  } // end on loop over muons per event
 
 
};


void Exercise3::SaveHistrograms(bool save, string sample) { 
 
  if (save) { 
    outputFile->Write("",TObject::kOverwrite);
    outputFile->Close();

    cout << "" << endl;
    if(sample == "data")  cout << "3 ---- Create output file: output/Histograms_Exercise3.root" << endl;
    if(sample == "mc")  cout << "3 ---- Create output file: output/Histograms_Exercise3_DY.root" << endl;
    cout << "" << endl;
  }

};
