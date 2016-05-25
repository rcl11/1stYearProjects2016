//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun May 15 20:42:12 2016 by ROOT version 5.28/00c
// from TChain ntuple/
//////////////////////////////////////////////////////////

#ifndef why_h
#define why_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class why {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   ULong64_t       event;
   Double_t        wt;
   Double_t        mpt_1;
   Double_t        mpt_2;
   Double_t        mpt_3;
   Double_t        tpt_1;
   Double_t        tpt_2;
   Double_t        tpt_3;
   Double_t        meta_1;
   Double_t        meta_2;
   Double_t        meta_3;
   Double_t        teta_1;
   Double_t        teta_2;
   Double_t        teta_3;
   Double_t        mphi_1;
   Double_t        mphi_2;
   Double_t        mphi_3;
   Double_t        tphi_1;
   Double_t        tphi_2;
   Double_t        tphi_3;
   Double_t        mE_1;
   Double_t        mE_2;
   Double_t        mE_3;
   Double_t        tE_1;
   Double_t        tE_2;
   Double_t        tE_3;
   Double_t        mq_1;
   Double_t        mq_2;
   Double_t        mq_3;
   Double_t        tq_1;
   Double_t        tq_2;
   Double_t        tq_3;
   Double_t        met;

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_wt;   //!
   TBranch        *b_mpt_1;   //!
   TBranch        *b_mpt_2;   //!
   TBranch        *b_mpt_3;   //!
   TBranch        *b_tpt_1;   //!
   TBranch        *b_tpt_2;   //!
   TBranch        *b_tpt_3;   //!
   TBranch        *b_meta_1;   //!
   TBranch        *b_meta_2;   //!
   TBranch        *b_meta_3;   //!
   TBranch        *b_teta_1;   //!
   TBranch        *b_teta_2;   //!
   TBranch        *b_teta_3;   //!
   TBranch        *b_mphi_1;   //!
   TBranch        *b_mphi_2;   //!
   TBranch        *b_mphi_3;   //!
   TBranch        *b_tphi_1;   //!
   TBranch        *b_tphi_2;   //!
   TBranch        *b_tphi_3;   //!
   TBranch        *b_mE_1;   //!
   TBranch        *b_mE_2;   //!
   TBranch        *b_mE_3;   //!
   TBranch        *b_tE_1;   //!
   TBranch        *b_tE_2;   //!
   TBranch        *b_tE_3;   //!
   TBranch        *b_mq_1;   //!
   TBranch        *b_mq_2;   //!
   TBranch        *b_mq_3;   //!
   TBranch        *b_tq_1;   //!
   TBranch        *b_tq_2;   //!
   TBranch        *b_tq_3;   //!
   TBranch        *b_met;   //!

   why(TTree *tree=0);
   virtual ~why();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef why_cxx
why::why(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f) {
         f = new TFile("Memory Directory");
         f->cd("Rint:/");
      }
      tree = (TTree*)gDirectory->Get("ntuple");

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("ntuple","");
      chain->Add("./VBFHToTauTau_M-125_mt_2015.root/ntuple");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

why::~why()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t why::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t why::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void why::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("wt", &wt, &b_wt);
   fChain->SetBranchAddress("mpt_1", &mpt_1, &b_mpt_1);
   fChain->SetBranchAddress("mpt_2", &mpt_2, &b_mpt_2);
   fChain->SetBranchAddress("mpt_3", &mpt_3, &b_mpt_3);
   fChain->SetBranchAddress("tpt_1", &tpt_1, &b_tpt_1);
   fChain->SetBranchAddress("tpt_2", &tpt_2, &b_tpt_2);
   fChain->SetBranchAddress("tpt_3", &tpt_3, &b_tpt_3);
   fChain->SetBranchAddress("meta_1", &meta_1, &b_meta_1);
   fChain->SetBranchAddress("meta_2", &meta_2, &b_meta_2);
   fChain->SetBranchAddress("meta_3", &meta_3, &b_meta_3);
   fChain->SetBranchAddress("teta_1", &teta_1, &b_teta_1);
   fChain->SetBranchAddress("teta_2", &teta_2, &b_teta_2);
   fChain->SetBranchAddress("teta_3", &teta_3, &b_teta_3);
   fChain->SetBranchAddress("mphi_1", &mphi_1, &b_mphi_1);
   fChain->SetBranchAddress("mphi_2", &mphi_2, &b_mphi_2);
   fChain->SetBranchAddress("mphi_3", &mphi_3, &b_mphi_3);
   fChain->SetBranchAddress("tphi_1", &tphi_1, &b_tphi_1);
   fChain->SetBranchAddress("tphi_2", &tphi_2, &b_tphi_2);
   fChain->SetBranchAddress("tphi_3", &tphi_3, &b_tphi_3);
   fChain->SetBranchAddress("mE_1", &mE_1, &b_mE_1);
   fChain->SetBranchAddress("mE_2", &mE_2, &b_mE_2);
   fChain->SetBranchAddress("mE_3", &mE_3, &b_mE_3);
   fChain->SetBranchAddress("tE_1", &tE_1, &b_tE_1);
   fChain->SetBranchAddress("tE_2", &tE_2, &b_tE_2);
   fChain->SetBranchAddress("tE_3", &tE_3, &b_tE_3);
   fChain->SetBranchAddress("mq_1", &mq_1, &b_mq_1);
   fChain->SetBranchAddress("mq_2", &mq_2, &b_mq_2);
   fChain->SetBranchAddress("mq_3", &mq_3, &b_mq_3);
   fChain->SetBranchAddress("tq_1", &tq_1, &b_tq_1);
   fChain->SetBranchAddress("tq_2", &tq_2, &b_tq_2);
   fChain->SetBranchAddress("tq_3", &tq_3, &b_tq_3);
   fChain->SetBranchAddress("met", &met, &b_met);
   Notify();
}

Bool_t why::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void why::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t why::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef why_cxx
