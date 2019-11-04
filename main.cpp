
#include <iostream>
#include <vector>
#include <fstream>

#include "Riostream.h"
#include "TString.h"
#include "TStyle.h"
#include "TVector3.h"
#include "TObjArray.h"
#include "TObjString.h"
#include "TH2.h"
#include "TGraph2D.h"
#include "TGraph.h"
#include "TColor.h"
#include "TPolyMarker3D.h"  // for 3D case
#include "TMarker.h"        // for 2D case
#include "TPolyLine3D.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH3F.h"
#include "TF3.h"
#include "TRandom.h"
#include "TApplication.h" // to keep canvas alive.
#include "TStyle.h"       // for gStyle pointer

using std::vector;
using namespace std;



 

int main(int argc,char** argv)
{

	TCanvas* c1 = new TCanvas("c1", "title" );

	// histogram 1d
	#if 0
	int xbin = 100;
	double xmin = 0;
	double xmax = 10;
	TH1D* h1 = new TH1D("h1", "histo1d", xbin, xmin, xmax);	

	for( int i=0; i<100; i++) {
	
		h1->Fill( gRandom->Uniform(xmin, xmax) );
		h1->Fill( (xmin+xmax)/2. );
	}

	h1->Draw();
	#endif

    TGraph* gr = new TGraph(); int	ipt = 0;

	gr->SetPoint( ipt, 0, 1 ); ipt++;
	gr->SetPoint( ipt, 1, 2 ); ipt++;
	gr->SetPoint( ipt, 1, 3 ); ipt++;
	gr->Draw("ALP");
		
	c1->SaveAs("result.png");





    return 0;
}
