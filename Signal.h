//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed May 25 16:18:01 2016 by ROOT version 5.34/04
// from TChain ntuple/
//////////////////////////////////////////////////////////

#ifndef Signal_h
#define Signal_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class Signal {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   ULong64_t       event;
   Double_t        mpt_1;
   Double_t        tpt_1;
   Double_t        meta_1;
   Double_t        teta_1;
   Double_t        mphi_1;
   Double_t        tphi_1;
   Double_t        mE_1;
   Double_t        tE_1;
   Double_t        mq_1;
   Double_t        tq_1;
   Double_t        met;
   Int_t           n_jets;
   Int_t           n_bjets;
   Double_t        miso_1;
   Double_t        tiso_2;
   Double_t        mt_2;
   Double_t        mt_1;
   Double_t        pt_tt;
   Double_t        m_vis;
   Double_t        mdxy_1;
   Double_t        tdxy_1;
   Double_t        mdz_1;
   Double_t        tdz_1;
   Double_t        jpt_1;
   Double_t        jeta_1;
   Double_t        jphi_1;
   Double_t        bpt_1;
   Double_t        beta_1;
   Double_t        bphi_1;
   Double_t        dphi;
   Double_t        deta;

   // List of branches
   TBranch        *b_event;   //!
   TBranch        *b_mpt_1;   //!
   TBranch        *b_tpt_1;   //!
   TBranch        *b_meta_1;   //!
   TBranch        *b_teta_1;   //!
   TBranch        *b_mphi_1;   //!
   TBranch        *b_tphi_1;   //!
   TBranch        *b_mE_1;   //!
   TBranch        *b_tE_1;   //!
   TBranch        *b_mq_1;   //!
   TBranch        *b_tq_1;   //!
   TBranch        *b_met;   //!
   TBranch        *b_n_jets;   //!
   TBranch        *b_n_bjets;   //!
   TBranch        *b_miso_1;   //!
   TBranch        *b_tiso_2;   //!
   TBranch        *b_mt_2;   //!
   TBranch        *b_mt_1;   //!
   TBranch        *b_pt_tt;   //!
   TBranch        *b_m_vis;   //!
   TBranch        *b_mdxy_1;   //!
   TBranch        *b_tdxy_1;   //!
   TBranch        *b_mdz_1;   //!
   TBranch        *b_tdz_1;   //!
   TBranch        *b_jpt_1;   //!
   TBranch        *b_jeta_1;   //!
   TBranch        *b_jphi_1;   //!
   TBranch        *b_bpt_1;   //!
   TBranch        *b_beta_1;   //!
   TBranch        *b_bphi_1;   //!
   TBranch        *b_dphi;   //!
   TBranch        *b_deta;   //!

   Signal(TTree *tree=0);
   virtual ~Signal();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Signal_cxx
Signal::Signal(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {

#ifdef SINGLE_TREE
      // The following code should be used if you want this class to access
      // a single tree instead of a chain
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("Memory Directory");
      if (!f || !f->IsOpen()) {
         f = new TFile("Memory Directory");
      }
      f->GetObject("ntuple",tree);

#else // SINGLE_TREE

      // The following code should be used if you want this class to access a chain
      // of trees.
      TChain * chain = new TChain("ntuple","");
      chain->Add("VBFHToTauTau_M-125_mt_2015.root/ntuple");
      tree = chain;
#endif // SINGLE_TREE

   }
   Init(tree);
}

Signal::~Signal()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Signal::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Signal::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Signal::Init(TTree *tree)
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
   fChain->SetBranchAddress("mpt_1", &mpt_1, &b_mpt_1);
   fChain->SetBranchAddress("tpt_1", &tpt_1, &b_tpt_1);
   fChain->SetBranchAddress("meta_1", &meta_1, &b_meta_1);
   fChain->SetBranchAddress("teta_1", &teta_1, &b_teta_1);
   fChain->SetBranchAddress("mphi_1", &mphi_1, &b_mphi_1);
   fChain->SetBranchAddress("tphi_1", &tphi_1, &b_tphi_1);
   fChain->SetBranchAddress("mE_1", &mE_1, &b_mE_1);
   fChain->SetBranchAddress("tE_1", &tE_1, &b_tE_1);
   fChain->SetBranchAddress("mq_1", &mq_1, &b_mq_1);
   fChain->SetBranchAddress("tq_1", &tq_1, &b_tq_1);
   fChain->SetBranchAddress("met", &met, &b_met);
   fChain->SetBranchAddress("n_jets", &n_jets, &b_n_jets);
   fChain->SetBranchAddress("n_bjets", &n_bjets, &b_n_bjets);
   fChain->SetBranchAddress("miso_1", &miso_1, &b_miso_1);
   fChain->SetBranchAddress("tiso_2", &tiso_2, &b_tiso_2);
   fChain->SetBranchAddress("mt_2", &mt_2, &b_mt_2);
   fChain->SetBranchAddress("mt_1", &mt_1, &b_mt_1);
   fChain->SetBranchAddress("pt_tt", &pt_tt, &b_pt_tt);
   fChain->SetBranchAddress("m_vis", &m_vis, &b_m_vis);
   fChain->SetBranchAddress("mdxy_1", &mdxy_1, &b_mdxy_1);
   fChain->SetBranchAddress("tdxy_1", &tdxy_1, &b_tdxy_1);
   fChain->SetBranchAddress("mdz_1", &mdz_1, &b_mdz_1);
   fChain->SetBranchAddress("tdz_1", &tdz_1, &b_tdz_1);
   fChain->SetBranchAddress("jpt_1", &jpt_1, &b_jpt_1);
   fChain->SetBranchAddress("jeta_1", &jeta_1, &b_jeta_1);
   fChain->SetBranchAddress("jphi_1", &jphi_1, &b_jphi_1);
   fChain->SetBranchAddress("bpt_1", &bpt_1, &b_bpt_1);
   fChain->SetBranchAddress("beta_1", &beta_1, &b_beta_1);
   fChain->SetBranchAddress("bphi_1", &bphi_1, &b_bphi_1);
   fChain->SetBranchAddress("dphi", &dphi, &b_dphi);
   fChain->SetBranchAddress("deta", &deta, &b_deta);
   Notify();
}

Bool_t Signal::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Signal::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Signal::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Signal_cxx
