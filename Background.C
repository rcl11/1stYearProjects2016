#define Background_cxx
#include "Background.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Background::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L Background.C
//      Root > Background t
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

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   TH1D* histo1 = new TH1D("Muon + Tau", "Invariant Mass (Muon_1+Tau_1)", 20, 0,200);
   TH1D* histo2 = new TH1D("taupt1", "taupt1", 20, 0,200);
   TH1D* histo3 = new TH1D("mupt1", "mupt1", 20, 0,200);
   histo1->SetFillStyle(3005);
   histo1->SetFillColor(kBlue);
   histo1->GetYaxis()->SetTitle("Events");
   histo1->GetXaxis()->SetTitle("Invariant mass");
   
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
	  histo1->Fill(m_vis);
	  histo2->Fill(tpt_1);
	  histo3->Fill(mpt_1);
      // if (Cut(ientry) < 0) continue;
   }
   
   TFile *f1 = new TFile("background.root", "RECREATE");
   histo1->Write("mvis_background");
   histo2->Write("tpt1_background");
   histo3->Write("mpt1_background");
}
