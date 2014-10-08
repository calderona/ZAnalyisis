#ifndef _DRAW_H
#define _DRAW_H (1)

#include "TCanvas.h"
#include "TF1.h"
#include "TFile.h"
#include "TFrame.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TGraphErrors.h"
#include "TH1F.h"
#include "TH2F.h"
#include "THStack.h"
#include "TImage.h"
#include "TLatex.h"
#include "TLegend.h"
#include "TMath.h"
#include "TPaveStats.h"
#include "TPaveText.h"
#include "TRandom.h"
#include "TString.h"
#include "TStyle.h"



const Color_t kDefaultColor   = kRed-7;
const Float_t default_xoffset =   1.30;
const Float_t default_yoffset =   1.80;
const Float_t default_xlow    =  0.195;
const Float_t default_yup     =  0.905;



// Functions
//------------------------------------------------------------------------------

void SetupEnviorement();

void          ExitPrint          (TString            method);

void          DrawTH1F           (TPad*              canvas,
				  TH1*               hist,
				  TString            option,
				  TString            title   = "",
				  TString            xtitle  = "",
				  TString            ytitle  = "",
				  Float_t            xoffset = default_xoffset,
				  Float_t            yoffset = default_yoffset);

void          DrawTH1F           (TVirtualPad*              canvas,
				  TH1*               hist,
				  TString            option,
				  TString            title   = "",
				  TString            xtitle  = "",
				  TString            ytitle  = "",
				  Float_t            xoffset = default_xoffset,
				  Float_t            yoffset = default_yoffset);

void          DrawTH2F           (TPad*              canvas,
				  TH2F*              hist,
				  TString            option,
				  TString            title   = "",
				  TString            xtitle  = "",
				  TString            ytitle  = "",
				  Float_t            xoffset = default_xoffset,
				  Float_t            yoffset = default_yoffset);

void          Axis               (TAxis*             axis,
				  TString            title,
				  Float_t            offset,
				  Bool_t             center);

void          AxisTH1F           (TH1*               hist,
				  TString            xtitle,
				  TString            ytitle,
				  Float_t            xoffset = default_xoffset,
				  Float_t            yoffset = default_yoffset);

void          AxisTH2F           (TH2F*              hist,
				  TString            xtitle,
				  TString            ytitle,
				  Float_t            xoffset = default_xoffset,
				  Float_t            yoffset = default_yoffset);

void          FillOpt            (TH1F*              hist,
				  Color_t            fcolor = kDefaultColor,
				  Style_t            fstyle = 1001);

void          LineOpt            (TH1F*              hist,
				  Color_t            lcolor = kDefaultColor,
				  Width_t            lwidth = 0,
				  Style_t            lstyle = kSolid);

void          LineOpt            (TH1*              hist,
				  Color_t            lcolor = kDefaultColor,
				  Width_t            lwidth = 0,
				  Style_t            lstyle = kSolid);

void          MarkerOpt          (TH1F*              hist,
				  Color_t            mcolor = kDefaultColor,
				  Size_t             msize  = 0,
				  Style_t            mstyle = kFullCircle);

void          MarkerOpt          (TH1*              hist,
				  Color_t            mcolor = kDefaultColor,
				  Size_t             msize  = 0,
				  Style_t            mstyle = kFullCircle);

TLegend*      DrawLegend         (Float_t            x1,
				  Float_t            y1,
				  TH1F*              hist,
				  TString            label,
				  TString            option,
				  Float_t            tsize   = 0.04,
				  Float_t            xoffset = 0.25,
				  Float_t            yoffset = 0.07);



TLegend*      DrawLegend         (Float_t            x1,
				  Float_t            y1,
				  TH1*              hist,
				  TString            label,
				  TString            option,
				  Float_t            tsize   = 0.04,
				  Float_t            xoffset = 0.25,
				  Float_t            yoffset = 0.07);
#endif
