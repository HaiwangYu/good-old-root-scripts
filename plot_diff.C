#include <iostream>

using namespace std;

void plot_diff(
const char* f1n = "ref+sp.root",
const char* f2n = "ref+sp2.root",
const char* h1n = "hu_orig13",
const char* h2n = "hu_orig13"
) {
    TFile* f1 = TFile::Open(f1n,"READ");
    TFile* f2 = TFile::Open(f2n,"READ");

    TCanvas *c1 = new TCanvas("c1","c2");
    auto h1 = (TH2F*) f1->Get(h1n); // raw
    auto h2 = (TH2F*) f2->Get(h2n); // SC
    auto hdiff = (TH2F*)h1->Clone("hdiff");
    hdiff->Add(h2, -1);
    hdiff->Draw("colz");
}
