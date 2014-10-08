#include "draw.h"

#include "TStyle.h"


void SetupEnviorement()
{
  
TStyle* GloStyle;
GloStyle = gStyle;

TStyle* Style = new TStyle("Style", "Style");
gStyle = Style;

  //----------------------------------------------------------------------------
  // Canvas
  //----------------------------------------------------------------------------
  Style->SetCanvasBorderMode(  0);
  Style->SetCanvasBorderSize( 10);
  Style->SetCanvasColor     (  0);
  Style->SetCanvasDefH      (600);
  Style->SetCanvasDefW      (550);
  Style->SetCanvasDefX      ( 10);
  Style->SetCanvasDefY      ( 10);

  //----------------------------------------------------------------------------
  // Pad
  //----------------------------------------------------------------------------
  Style->SetPadBorderMode  (   0);
  Style->SetPadBorderSize  (  10);
  Style->SetPadColor       (   0);
  Style->SetPadBottomMargin(0.20);
  Style->SetPadTopMargin   (0.08);
  Style->SetPadLeftMargin  (0.18);
  Style->SetPadRightMargin (0.05);

  //----------------------------------------------------------------------------
  // Frame
  //----------------------------------------------------------------------------
  Style->SetFrameFillStyle ( 0);
  Style->SetFrameFillColor ( 0);
  Style->SetFrameLineColor ( 1);
  Style->SetFrameLineStyle ( 0);
  Style->SetFrameLineWidth ( 2);
  Style->SetFrameBorderMode( 0);
  Style->SetFrameBorderSize(10);

  //----------------------------------------------------------------------------
  // Hist
  //----------------------------------------------------------------------------
  Style->SetHistFillColor(0);
  Style->SetHistFillStyle(1);
  Style->SetHistLineColor(1);
  Style->SetHistLineStyle(0);
  Style->SetHistLineWidth(1);

  //----------------------------------------------------------------------------
  // Axis
  //----------------------------------------------------------------------------
  Style->SetLabelFont  (   42, "xyz");
  Style->SetLabelOffset(0.015, "xyz");
  Style->SetLabelSize  (0.050, "xyz");
  Style->SetNdivisions (  505, "xyz");
  Style->SetTitleFont  (   42, "xyz");
  Style->SetTitleSize  (0.050, "xyz");

  Style->SetTitleOffset(  1.4,   "x");
  Style->SetTitleOffset(  1.2,   "y");
  Style->SetPadTickX   (           1);  // Tick marks on the opposite side of the frame
  Style->SetPadTickY   (           1);  // Tick marks on the opposite side of the frame


  //----------------------------------------------------------------------------
  // Title
  //----------------------------------------------------------------------------
  Style->SetTitleBorderSize( 0);
  Style->SetTitleFillColor (10);
  Style->SetTitleFont      (42, "");

  //----------------------------------------------------------------------------
  // Stat
  //----------------------------------------------------------------------------
  Style->SetOptStat       (1110);
  Style->SetStatBorderSize(   0);
  Style->SetStatColor     (  10);
  Style->SetStatFont      (  42);
  Style->SetStatX         (0.94);
  Style->SetStatY         (0.91);

  
}





//------------------------------------------------------------------------------
// ExitPrint
//------------------------------------------------------------------------------
void ExitPrint(TString method)
{
  printf(" draw::%-11s exit\n", method.Data());
}




//------------------------------------------------------------------------------
// DrawTH1F
//------------------------------------------------------------------------------
void DrawTH1F(TPad*    canvas,
	      TH1*     hist,
	      TString  option,
	      TString  title,
	      TString  xtitle,
	      TString  ytitle,
	      Float_t  xoffset,
	      Float_t  yoffset)
{
  if (!hist) {ExitPrint("DrawTH1F()"); return;}

  TString name = hist->GetName();

  canvas ? canvas->cd() : canvas = new TCanvas(name, name);

   hist->SetDirectory(     0);
  hist->Draw        (option);

  if (!option.Contains("same")) {
    //hist->SetTitle(title);
    AxisTH1F(hist, xtitle, ytitle, xoffset, yoffset);
  }
}



//------------------------------------------------------------------------------
// DrawTH1F
//------------------------------------------------------------------------------
void DrawTH1F(TVirtualPad*    canvas,
	      TH1*     hist,
	      TString  option,
	      TString  title,
	      TString  xtitle,
	      TString  ytitle,
	      Float_t  xoffset,
	      Float_t  yoffset)
{
  if (!hist) {ExitPrint("DrawTH1F()"); return;}

  TString name = hist->GetName();

  canvas ? canvas->cd() : canvas = new TCanvas(name, name);

   hist->SetDirectory(     0);
  hist->Draw        (option);

  if (!option.Contains("same")) {
    //hist->SetTitle(title);
    AxisTH1F(hist, xtitle, ytitle, xoffset, yoffset);
  }
}



//------------------------------------------------------------------------------
// DrawTH2F
//------------------------------------------------------------------------------
void DrawTH2F(TPad*    canvas,
	      TH2F*    hist,
	      TString  option,
	      TString  title,
	      TString  xtitle,
	      TString  ytitle,
	      Float_t  xoffset,
	      Float_t  yoffset)
{
  if (!hist) {ExitPrint("DrawTH2F()"); return;}

  TString name = hist->GetName();

  canvas ? canvas->cd() : canvas = new TCanvas(name, name);

  hist->SetDirectory(     0);
  hist->Draw        (option);

  if (!option.Contains("same")) {
    //hist->SetTitle(title);
    AxisTH2F(hist, xtitle, ytitle, xoffset, yoffset);
  }
}



//------------------------------------------------------------------------------
// Axis
//------------------------------------------------------------------------------
void Axis(TAxis*  axis,
	  TString title,
	  Float_t offset,
	  Bool_t  center)
{
  axis->CenterTitle   (center);
  axis->SetTitle      ( title);
  axis->SetTitleOffset(offset);
}



//------------------------------------------------------------------------------
// AxisTH1F
//------------------------------------------------------------------------------
void AxisTH1F(TH1*    hist,
	      TString xtitle,
	      TString ytitle,
	      Float_t xoffset,
	      Float_t yoffset)
{
  if (!hist) {ExitPrint("AxisTH1F()"); return;}

  TAxis* xaxis = (TAxis*)hist->GetXaxis();
  TAxis* yaxis = (TAxis*)hist->GetYaxis();

  Axis(xaxis, xtitle, xoffset, kFALSE);
  Axis(yaxis, ytitle, yoffset, kTRUE );
}




//------------------------------------------------------------------------------
// AxisTH2F
//------------------------------------------------------------------------------
void AxisTH2F(TH2F*   hist,
	      TString xtitle,
	      TString ytitle,
	      Float_t xoffset,
	      Float_t yoffset)
{
  if (!hist) {ExitPrint("AxisTH2F()"); return;}
  
  TAxis* xaxis = (TAxis*)hist->GetXaxis();
  TAxis* yaxis = (TAxis*)hist->GetYaxis();

  Axis(xaxis, xtitle, xoffset, kFALSE);
  Axis(yaxis, ytitle, yoffset, kTRUE );
}


//------------------------------------------------------------------------------
// FillOpt
//------------------------------------------------------------------------------
void FillOpt(TH1F*   hist,
	     Color_t fcolor,
	     Style_t fstyle)
{
  if (!hist) {ExitPrint("FillOpt()"); return;}

  hist->SetFillColor(fcolor);
  hist->SetFillStyle(fstyle);
}


//------------------------------------------------------------------------------
// LineOpt
//------------------------------------------------------------------------------
void LineOpt(TH1F*   hist,
	     Color_t lcolor,
	     Width_t lwidth,
	     Style_t lstyle)
{
  if (!hist) {ExitPrint("LineOpt()"); return;}

  hist->SetLineColor(lcolor);
  hist->SetLineStyle(lstyle);
  hist->SetLineWidth(lwidth);
}

// LineOpt
//------------------------------------------------------------------------------
void LineOpt(TH1*   hist,
	     Color_t lcolor,
	     Width_t lwidth,
	     Style_t lstyle)
{
  if (!hist) {ExitPrint("LineOpt()"); return;}

  hist->SetLineColor(lcolor);
  hist->SetLineStyle(lstyle);
  hist->SetLineWidth(lwidth);
}




//------------------------------------------------------------------------------
// MarkerOpt
//------------------------------------------------------------------------------
void MarkerOpt(TH1F*   hist,
	       Color_t mcolor,
	       Size_t  msize,
	       Style_t mstyle)
{
  if (!hist) {ExitPrint("MarkerOpt()"); return;}

  hist->SetMarkerColor(mcolor);
  hist->SetMarkerSize (msize );
  hist->SetMarkerStyle(mstyle);
}

//------------------------------------------------------------------------------
// MarkerOpt
//------------------------------------------------------------------------------
void MarkerOpt(TH1*   hist,
	       Color_t mcolor,
	       Size_t  msize,
	       Style_t mstyle)
{
  if (!hist) {ExitPrint("MarkerOpt()"); return;}

  hist->SetMarkerColor(mcolor);
  hist->SetMarkerSize (msize );
  hist->SetMarkerStyle(mstyle);
}


//------------------------------------------------------------------------------
// DrawLegend
//------------------------------------------------------------------------------
TLegend* DrawLegend(Float_t x1,
		    Float_t y1,
		    TH1F*   hist,
		    TString label,
		    TString option,
		    Float_t tsize,
		    Float_t xoffset,
		    Float_t yoffset)
{
  TLegend* legend = new TLegend(x1,
				y1,
				x1 + xoffset,
				y1 + yoffset);
  
  legend->SetBorderSize(    0);
  legend->SetFillColor (    0);
  legend->SetTextAlign (   12);
  legend->SetTextFont  (   42);
  legend->SetTextSize  (tsize);

  legend->AddEntry(hist, label.Data(), option.Data());
  legend->Draw();

  return legend;
}


//------------------------------------------------------------------------------
// DrawLegend
//------------------------------------------------------------------------------
TLegend* DrawLegend(Float_t x1,
		    Float_t y1,
		    TH1*   hist,
		    TString label,
		    TString option,
		    Float_t tsize,
		    Float_t xoffset,
		    Float_t yoffset)
{
  TLegend* legend = new TLegend(x1,
				y1,
				x1 + xoffset,
				y1 + yoffset);
  
  legend->SetBorderSize(    0);
  legend->SetFillColor (    0);
  legend->SetTextAlign (   12);
  legend->SetTextFont  (   42);
  legend->SetTextSize  (tsize);

  legend->AddEntry(hist, label.Data(), option.Data());
  legend->Draw();

  return legend;
}



//------------------------------------------------------------------------------
// DrawLegend
//------------------------------------------------------------------------------
TLegend* DrawLegendG (Float_t x1,
		      Float_t y1,
		      TGraph*   hist,
		      TString label,
		      TString option,
		      Float_t tsize,
		      Float_t xoffset,
		      Float_t yoffset)
{
  TLegend* legend = new TLegend(x1,
				y1,
				x1 + xoffset,
				y1 + yoffset);
  
  legend->SetBorderSize(    0);
  legend->SetFillColor (    0);
  legend->SetTextAlign (   12);
  legend->SetTextFont  (   42);
  legend->SetTextSize  (tsize);

  legend->AddEntry(hist, label.Data(), option.Data());
  legend->Draw();

  return legend;
}

