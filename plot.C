#include "TFile.h"
#include "TCanvas.h"
#include "TH2F.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

void plot(const char* hist_name)
{
    const char* in_file_name = "input.root";
    auto in_file = TFile::Open(in_file_name, "READ");

    TCanvas* c0 = new TCanvas("c0", "c0");
    auto hist = (TH2F*) in_file->Get(hist_name);
    if(!hist) {
        std::cerr << "Can not find " << hist_name << std::endl;
        return;
    }
    hist->SetStats(0);
    //hist->SetMinimum(0);
    hist->SetMinimum(1800);
    hist->SetMaximum(1900);
    hist->GetXaxis()->SetRangeUser(12120, 12160);
    hist->GetYaxis()->SetRangeUser(3100, 3300);
    hist->GetXaxis()->SetTitle("channel");
    hist->GetYaxis()->SetTitle("tick");
    hist->Draw("colz");
}
