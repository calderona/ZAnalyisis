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



void doPlotsExercise4( string sample ){

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

  if ( sample == "all" || sample == "data" ) 
    data = TFile::Open(pwd1  + "Histograms_Exercise4.root");
  
  if ( sample == "all"  ) 
    mc = TFile::Open(pwd1  + "Histograms_Exercise4_DY.root");
  

  if ( sample != "all" && sample != "data" ) cout << "No available option  ......" << endl;


  if ( sample == "all" || sample == "data" ) {

  data->cd();


  // Compare all muons and the ones identified and isolated


  TCanvas *Mu_1 = new TCanvas("Mu_1","Mu_1",1100,700);
  Mu_1->Divide(2,1);
 
  TVirtualPad* Mu_1_1 = Mu_1->cd(1);
  TVirtualPad* Mu_1_2 = Mu_1->cd(2);
 
  h_Mu_pt_all->Scale(1./(h_Mu_pt_all->Integral()));
  h_Mu_eta_all->Scale(1./(h_Mu_eta_all->Integral()));

  h_Mu_pt_GoodMu->Scale(1/(h_Mu_pt_GoodMu->Integral()));
  h_Mu_eta_GoodMu->Scale(1/(h_Mu_eta_GoodMu->Integral()));


  DrawTH1F(Mu_1_1, h_Mu_pt_all,"","","pT (GeV)","");
  LineOpt(h_Mu_pt_all,kBlue,2,kSolid);
  MarkerOpt(h_Mu_pt_all,kBlue,1,kFullCircle);

  DrawTH1F(Mu_1_1, h_Mu_pt_GoodMu ,"same","","Eta","");
  LineOpt(h_Mu_pt_GoodMu ,kRed,2,kSolid);
  MarkerOpt(h_Mu_pt_GoodMu ,kRed,1,kFullCircle);

  DrawTH1F(Mu_1_2, h_Mu_eta_all,"","","eta","");
  LineOpt(h_Mu_eta_all,kBlue,2,kSolid);
  MarkerOpt(h_Mu_eta_all,kBlue,1,kFullCircle);

  DrawTH1F(Mu_1_2, h_Mu_eta_GoodMu ,"same","","Eta","");
  LineOpt(h_Mu_eta_GoodMu ,kRed,2,kSolid);
  MarkerOpt(h_Mu_eta_GoodMu ,kRed,1,kFullCircle);


  TCanvas *Mu_2 = new TCanvas("Mu_2","Mu_2",800,800);

  h_Mu_cutWorkflow->GetXaxis()->SetBinLabel(1,"all");
  h_Mu_cutWorkflow->GetXaxis()->SetBinLabel(2,"GLB");
  h_Mu_cutWorkflow->GetXaxis()->SetBinLabel(3,"TK");
  h_Mu_cutWorkflow->GetXaxis()->SetBinLabel(4,"TK arb.");
  h_Mu_cutWorkflow->GetXaxis()->SetBinLabel(5,"STA hits");
  h_Mu_cutWorkflow->GetXaxis()->SetBinLabel(6,"GLB Chi2");
  h_Mu_cutWorkflow->GetXaxis()->SetBinLabel(7,"TK Hits");
  h_Mu_cutWorkflow->GetXaxis()->SetBinLabel(8,"TK Pixel");
  h_Mu_cutWorkflow->GetXaxis()->SetBinLabel(9,"IP");
  h_Mu_cutWorkflow->GetXaxis()->SetBinLabel(10,"dZ");

  DrawTH1F(Mu_2, h_Mu_cutWorkflow,"","","","");
  LineOpt(h_Mu_cutWorkflow,kBlue,2,kSolid);
  MarkerOpt(h_Mu_cutWorkflow,kBlue,1,kFullCircle);


  TCanvas *Mu_3 = new TCanvas("Mu_3","Mu_3",800,800);

  Mu_3->SetLogy();

  DrawTH1F(Mu_3, h_Mu_InvMass_all,"","","Mll (GeV)","");
  LineOpt(h_Mu_InvMass_all,kBlue,2,kSolid);
  MarkerOpt(h_Mu_InvMass_all,kBlue,1,kFullCircle);

  DrawTH1F(Mu_3, h_Mu_InvMass_GoodMu,"sameE1","","Mll (GeV)","");
  LineOpt(h_Mu_InvMass_GoodMu,kRed,2,kSolid);
  MarkerOpt(h_Mu_InvMass_GoodMu,kRed,1,kFullCircle);

  DrawLegend(0.75,0.80, h_Mu_InvMass_all , "All Muons", "LP",0.030,0.12, 0.10);
  DrawLegend(0.75,0.70, h_Mu_InvMass_GoodMu , "Good Muons", "LP",0.030,0.12, 0.10);



  TCanvas *Mu_4 = new TCanvas("Mu_4","Mu_4",1200,800);

  Mu_4->Divide(3,1);
 
  TVirtualPad* Mu_4_1 = Mu_4->cd(1);
  TVirtualPad* Mu_4_2 = Mu_4->cd(2);
  TVirtualPad* Mu_4_3 = Mu_4->cd(3);

  DrawTH1F(Mu_4_1, h_Mu_ZInvMass_GlbGlb,"","","Mll (GeV)","");
  LineOpt(h_Mu_ZInvMass_GlbGlb,kBlue,2,kSolid);
  MarkerOpt(h_Mu_ZInvMass_GlbGlb,kBlue,1,kFullCircle);

  DrawTH1F(Mu_4_2, h_Mu_ZInvMass_StaSta,"","","Mll (GeV)","");
  LineOpt(h_Mu_ZInvMass_StaSta,kBlue,2,kSolid);
  MarkerOpt(h_Mu_ZInvMass_StaSta,kBlue,1,kFullCircle);

  DrawTH1F(Mu_4_3, h_Mu_ZInvMass_TkTk,"","","Mll (GeV)","");
  LineOpt(h_Mu_ZInvMass_TkTk,kBlue,2,kSolid);
  MarkerOpt(h_Mu_ZInvMass_TkTk,kBlue,1,kFullCircle);



  TCanvas *Mu_5 = new TCanvas("Mu_5","Mu_5",800,800);


  float dataIntegralZ = h_Mu_ZInvMass_GoodMu->Integral(25,36); 

  Mu_5->SetLogy();

  mc->cd();

  float mcIntegralZ =  h_Mu_ZInvMass_GoodMu->Integral(25,36);


  h_Mu_ZInvMass_GoodMu->Scale(dataIntegralZ / mcIntegralZ);

  DrawTH1F(Mu_5, h_Mu_ZInvMass_GoodMu,"","","Mll (GeV)","");
  LineOpt(h_Mu_ZInvMass_GoodMu,kRed,2,kSolid);
  MarkerOpt(h_Mu_ZInvMass_GoodMu,kRed,1,kFullCircle);

  DrawLegend(0.25,0.80, h_Mu_ZInvMass_GoodMu , "Simulation", "LP",0.030,0.12, 0.10);

  data->cd();

   DrawTH1F(Mu_5, h_Mu_ZInvMass_GoodMu,"sameE1","","","");
  LineOpt(h_Mu_ZInvMass_GoodMu,kBlue,2,kSolid);
  MarkerOpt(h_Mu_ZInvMass_GoodMu,kBlue,1,kFullCircle);

  DrawLegend(0.25,0.70,h_Mu_ZInvMass_GoodMu , "Data", "LP",0.030,0.12, 0.10);




  }




}
