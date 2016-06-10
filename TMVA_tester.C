#include "TH1.h"
#include "TCanvas.h"

int TMVA_tester(){

TFile *file = new TFile("Test_BDT.root"); 


TH1F *h1 = (TH1F*)file->Get("Method_BDT/BDT/MVA_BDT_B"); 
TH1F *h2 = (TH1F*)file->Get("Method_BDT/BDT/MVA_BDT_S");

h1->Scale(1/h1->Integral());
h2->Scale(1/h2->Integral());
h2->Scale(3.413400e+04);
h1->Scale(4.822070e+05);

TCanvas *c1 = new TCanvas("c1", "Invariant mass plot");
h1->Draw();
h2->SetLineColor(kRed);
h2->Draw("same");


std::cout << "Applying cut of >0.2 on BDT discriminator yields S/B= " << h2->Integral(h2->GetXaxis()->FindBin(0.2),h2->GetNbinsX())/h1->Integral(h1->GetXaxis()->FindBin(0.2),h1->GetNbinsX()) << std::endl;

std::cout << "The S/B without any cuts is = " << h2->Integral()/h1->Integral() << std::endl;

std::cout << "How do these numbers compare to your attempts?" << std::endl;

return 0;

}
