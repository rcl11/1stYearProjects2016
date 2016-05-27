#include "TH1.h"
#include "TCanvas.h"

int plot_macro(){

TFile *bkgfile = new TFile("background.root"); 
TFile *sigfile = new TFile("signal.root"); 

TH1F *h1 = (TH1F*)bkgfile->Get("mvis_background"); 
TH1F *h2 = (TH1F*)sigfile->Get("mvis_signal");

TCanvas *c1 = new TCanvas("c1", "Invariant mass plot");
h1->Draw();
h2->SetLineColor(kRed);
h2->Draw("same");

return 0;

}
