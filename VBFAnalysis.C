#define VBFAnalysis_cxx
#include "VBFAnalysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include "TMath.h"

void VBFAnalysis::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L VBFAnalysis.C
//      Root > VBFAnalysis t
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
//
TH1D* histo1 = new TH1D("hmu1phi","#phi (Muon 1)", 64,-3.2,3.2);
TH1D* histo2 = new TH1D("m_inv","m_inv", 30,0,300);
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      histo1->Fill(mphi_1);
      double deltaR = sqrt( pow((mphi_1-tphi_1),2) + pow((meta_1-teta_1),2) );
      if(mpt_1>0 && tpt_1>0 && deltaR>0.5){
        double m_inv = sqrt(pow((mE_1+tE_1),2) - pow((mpt_1*cos(mphi_1) + tpt_1*cos(tphi_1)),2) - pow((mpt_1*sin(mphi_1) + tpt_1*sin(tphi_1)),2) - pow((mpt_1*sinh(meta_1)+tpt_1*sinh(teta_1)),2));
        histo2->Fill(m_inv);
      }
      // if (Cut(ientry) < 0) continue;
   }

TCanvas *c1 = new TCanvas("c1","Phi plot");
histo2->Draw();

}
