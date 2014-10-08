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



#define Analysis_Zmumu_cxx
#include "Analysis_Zmumu.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TString.h"

#include "Exercise3.h"
#include "Exercise4.h"

#include <iostream>
#include <fstream>


void Analysis_Zmumu::Loop(string sample, bool save, int exe)
{
//   In a ROOT session, you can do:
//      Root > .L Analysis_Zmumu.C
//      Root > Analysis_Zmumu t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
 
  if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntries();

   cout << "nentries: " << nentries << endl;

   
   ////////////////
   /// EXERCISE 3// 
   ////////////////
  
   gROOT->LoadMacro("Exercise3.C+");  
   
   if(exe==3) {  
     
     myEx3 = new Exercise3(fChain, save, sample);
   }
   
   ////////////////
   /// EXERCISE 4// 
   ////////////////

   gROOT->LoadMacro("Exercise4.C+");   

   if(exe==4) {
     
     myEx4 = new Exercise4(fChain, save, sample);

   }

   ////////////////
   
   
   Long64_t nbytes = 0, nb = 0;
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {

      Long64_t ientry = LoadTree(jentry);

      if (ientry < 0) break;

      nb = fChain->GetEntry(jentry);   nbytes += nb;


    
      ////////////////
      /// EXERCISE 3// 
      ////////////////
      
      if (exe==3) myEx3->FillHistograms(jentry);
   
       
      ////////////////
      /// EXERCISE 4// 
      ////////////////
      
      if (exe==4) myEx4->FillHistograms(jentry);
       
      
   }
   

   ////////////////
   /// EXERCISE 3// 
   ////////////////
   
   if (exe==3) myEx3->SaveHistrograms(save, sample);


   ////////////////
   /// EXERCISE 4// 
   ////////////////

   if (exe==4) myEx4->SaveHistrograms(save, sample);


   


}
