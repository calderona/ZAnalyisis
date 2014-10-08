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




void doPlotsExercise3(){

 // LOADING MACROS. 

  gInterpreter->LoadMacro   ("utils/draw.C+");

  gStyle      ->SetOptStat  (0);
  gStyle      ->SetPalette  (1);

  SetupEnviorement();

  //------------------------------------------
  //Load the .root files to use in this script
  //------------------------------------------
  
  TString pwd1 = "output/";
  
  TFile* data = 0;
  TFile* mc = 0;


  data = TFile::Open(pwd1  + "Histograms_Exercise3.root");

  data->cd();



  TCanvas *Mu_1 = new TCanvas("Mu_1","Mu_1",800,800);
  Mu_1->Divide(2,2);
 
  TVirtualPad* Mu_1_1 = Mu_1->cd(1);
  TVirtualPad* Mu_1_2 = Mu_1->cd(2);
  TVirtualPad* Mu_1_3 = Mu_1->cd(3);
  TVirtualPad* Mu_1_4 = Mu_1->cd(4);

  Mu_1_4->SetLogy();

  DrawTH1F(Mu_1_1, h_nPV,"","","nPV","");
  LineOpt(h_nPV,kBlue,2,kSolid);
  MarkerOpt(h_nPV,kBlue,1,kFullCircle);

  DrawTH1F(Mu_1_2, h_Mu_eta_fromTLorentz ,"","","Eta","");
  LineOpt(h_Mu_eta_fromTLorentz ,kBlue,2,kSolid);
  MarkerOpt(h_Mu_eta_fromTLorentz ,kBlue,1,kFullCircle);

  DrawTH1F(Mu_1_3, h_Mu_phi_fromTLorentz ,"","","Phi","");
  LineOpt(h_Mu_phi_fromTLorentz ,kBlue,2,kSolid);
  MarkerOpt(h_Mu_phi_fromTLorentz ,kBlue,1,kFullCircle);

  DrawTH1F(Mu_1_4, h_Mu_NormChi2GTrk ,"","","Chi2/ndof (Glb Mu)","");
  LineOpt(h_Mu_NormChi2GTrk ,kBlue,2,kSolid);
  MarkerOpt(h_Mu_NormChi2GTrk ,kBlue,1,kFullCircle);


  TCanvas *Mu_2 = new TCanvas("Mu_2","Mu_2",800,800);
  Mu_2->Divide(2,2);
  
  TVirtualPad* Mu_2_1 = Mu_2->cd(1);
  TVirtualPad* Mu_2_2 = Mu_2->cd(2);
  TVirtualPad* Mu_2_3 = Mu_2->cd(3);
  TVirtualPad* Mu_2_4 = Mu_2->cd(4);

  DrawTH1F(Mu_2_1, h_Mu_NValidHitsSATrk,"","","#Hits STA Muon","");
  LineOpt(h_Mu_NValidHitsSATrk,kBlue,2,kSolid);
  MarkerOpt(h_Mu_NValidHitsSATrk,kBlue,1,kFullCircle);

  DrawTH1F(Mu_2_2, h_Mu_NumOfMatches,"","","#Matches in Muon system","");
  LineOpt(h_Mu_NumOfMatches,kBlue,2,kSolid);
  MarkerOpt(h_Mu_NumOfMatches,kBlue,1,kFullCircle);

  DrawTH1F(Mu_2_3, h_Mu_NValidHitsInTrk,"","","#Hits TK Muon","");
  LineOpt(h_Mu_NValidHitsInTrk,kBlue,2,kSolid);
  MarkerOpt(h_Mu_NValidHitsInTrk,kBlue,1,kFullCircle);

  DrawTH1F(Mu_2_4, h_Mu_NValidPixelHitsInTrk,"","","#Pixel TK Muon","");
  LineOpt(h_Mu_NValidPixelHitsInTrk,kBlue,2,kSolid);
  MarkerOpt(h_Mu_NValidPixelHitsInTrk,kBlue,1,kFullCircle);
  


  TCanvas *Mu_3 = new TCanvas("Mu_3","Mu_3",800,800);
  Mu_3->Divide(2,2);
  

  TVirtualPad* Mu_3_1 = Mu_3->cd(1);
  TVirtualPad* Mu_3_2 = Mu_3->cd(2);
  TVirtualPad* Mu_3_3 = Mu_3->cd(3);
  TVirtualPad* Mu_3_4 = Mu_3->cd(4);

  Mu_3_1->SetLogy();
  Mu_3_2->SetLogy();
  Mu_3_3->SetLogy();
  Mu_3_4->SetLogy();

  DrawTH1F(Mu_3_1, h_Mu_dzPV,"","","Muon dZ to PV","");
  LineOpt(h_Mu_dzPV,kBlue,2,kSolid);
  MarkerOpt(h_Mu_dzPV,kBlue,1,kFullCircle);

  DrawTH1F(Mu_3_2, h_Mu_IPPV,"","","Muon dxy to PV","");
  LineOpt(h_Mu_IPPV,kBlue,2,kSolid);
  MarkerOpt(h_Mu_IPPV,kBlue,1,kFullCircle);

  DrawTH1F(Mu_3_3, h_Mu_RelativeIso,"","","Relative Isolation","");
  LineOpt(h_Mu_RelativeIso,kBlue,2,kSolid);
  MarkerOpt(h_Mu_RelativeIso,kBlue,1,kFullCircle);

  DrawTH1F(Mu_3_4, h_Mu_deltaPt_overPt,"","","deltaPt/pt","");
  LineOpt(h_Mu_deltaPt_overPt,kBlue,2,kSolid);
  MarkerOpt(h_Mu_deltaPt_overPt,kBlue,1,kFullCircle);


  TCanvas *Mu_4 = new TCanvas("Mu_4","Mu_4",800,800);

  h_Mu_type->GetXaxis()->SetBinLabel(1,"GLB Mu");
  h_Mu_type->GetXaxis()->SetBinLabel(2,"STA Mu");
  h_Mu_type->GetXaxis()->SetBinLabel(3,"TK Mu");
  h_Mu_type->GetXaxis()->SetBinLabel(4,"STA&&GLB Mu");
  h_Mu_type->GetXaxis()->SetBinLabel(5,"TK&&GLB Mu");
  h_Mu_type->GetXaxis()->SetBinLabel(6,"STA&&!GLB Mu");
  h_Mu_type->GetXaxis()->SetBinLabel(7,"TK&&!GLB Mu");

  DrawTH1F(Mu_4, h_Mu_type,"","","","");
  LineOpt(h_Mu_type,kBlue,2,kSolid);
  MarkerOpt(h_Mu_type,kBlue,1,kFullCircle);

  TH1F *h_Mu_selected = new TH1F("h_Mu_selected","",7,0,7);

  
  h_Mu_selected->SetBinContent(5, h_Mu_type->GetBinContent(5));

  DrawTH1F(Mu_4, h_Mu_selected,"same","same","","");
  LineOpt(h_Mu_selected,kRed,2,kSolid);
  MarkerOpt(h_Mu_selected,kRed,1,kFullCircle);
  FillOpt(h_Mu_selected,kRed,1001);


}
