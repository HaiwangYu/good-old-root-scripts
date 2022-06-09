#include <iostream>

using namespace std;

void comp_waveform(
const char* fn = "waveform.root",
const char* h1n = "h1",
const char* h2n = "h2",
const int ch = 51
) {
    cout << " fn: " << fn << " h1n: " << h1n << " h2n: " << h2n << endl;
    TFile* infile = TFile::Open(fn,"READ");

    TCanvas *c1 = new TCanvas("c1","c2");
    auto h1 = (TH2F*) infile->Get(h1n); // raw
    auto h2 = (TH2F*) infile->Get(h2n); // SC
    h1->SetMinimum(100); // to remove bkg
    h1->SetStats(0);
    h1->Draw("colz");
    //h1->GetYaxis()->SetRangeUser(1000,3000);
    h2->Draw("box,same");

    TCanvas *c2 = new TCanvas("c2","c2");
    auto h1y = h1->ProjectionY("h1y",ch,ch);
    auto h2y = h2->ProjectionY("h2y",ch,ch);
    h1y->Scale(1./h1y->GetMaximum());
    h2y->Scale(1./h2y->GetMaximum());
    h1y->Draw("hist");
    h2y->SetLineColor(kRed);
    h2y->Draw("hist,same");
    //h2y->Draw("hist");
}
