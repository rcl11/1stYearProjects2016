#define why_cxx
#include "why.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <math.h>

void why::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L H:/project/.C
//      Root > H:/project/ t
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
   histo1->GetYaxis()->SetTitle("Events");
   histo1->GetXaxis()->SetTitle("Invariant mass");

   histo1->SetFillStyle(3005);
   histo1->SetFillColor(kBlue);


   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
   double mu1phi;
   float e = 2.71828182846;

   double mtheta;
   double ttheta;


   mtheta = 2*atan(exp(-meta_1));

   ttheta = 2*atan(exp(-teta_1));
   
 //  mtheta = atan(2*exp(-meta_1));

   //ttheta = atan(2*exp(-teta_1));


   //double m1px = mpt_1*cos(mphi_1)*sin(mtheta);
   //double m1py = mpt_1*sin(mphi_1)*sin(mtheta);
   //double m1pz = mpt_1*cos(mtheta);

   //double t1px = tpt_1*cos(tphi_1)*sin(ttheta);
   //double t1py = tpt_1*sin(tphi_1)*sin(ttheta);
   //double t1pz = tpt_1*cos(ttheta);
   
   double m1px = mpt_1*cos(mphi_1);
   double m1py = mpt_1*sin(mphi_1);
  // double m1pz = mpt_1*sinh(meta_1);
   double m1pz = mpt_1/tan(mtheta);

   double t1px = tpt_1*cos(tphi_1);
   double t1py = tpt_1*sin(tphi_1);
   //double t1pz = tpt_1*sinh(teta_1);
   double t1pz = tpt_1/tan(ttheta);
   double m_mutau;

   std::cout << mtheta << " " << cos(mtheta)/sin(mtheta) << " " << sinh(meta_1) << " " << std::endl; 

   m_mutau = sqrt((mE_1 + tE_1)*(mE_1 + tE_1) - (m1px + t1px)*(m1px + t1px) - (m1py + t1py)*(m1py + t1py) - (m1pz + t1pz)*(m1pz + t1pz));

	  histo1->Fill(m_mutau);

      // if (Cut(ientry) < 0) continue;
   }

   TCanvas *c1 = new TCanvas("c1", "Invariant mass plot");
   histo1->Draw();
   

}
