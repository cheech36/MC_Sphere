#include "MC_HManager.h"
#include  <math.h>

#include <TH1F.h>
#include <TH2F.h>
#include <TString.h>
#include <TFile.h>

#define PI 3.1415926

HManager::HManager(void)
{}

HManager::~HManager(void)
{}


void HManager::Book(void)
{
    hDistance = new TH1F("hDistance",  "Distance Distribution", 200, 0, 2 );
    hBiasCheck= new TH2F("BiasCheck", "Theta - Phi Space"     ,  80, 0, PI, 80, 0, 2*PI);
}
    
    
void HManager::BiasCheck(const double& theta, const double& phi )
{
    HManager::hBiasCheck->Fill(theta, phi);
}


void HManager::DistValue  (const double& dValue)
{
	hDistance->Fill(dValue);
}


void HManager::openFile(TString fileName)
{
    
  if(outFile_)
  {
    outFile_->Close();
    delete outFile_;
    outFile_ = 0;
  }
  
    outFile_ = new TFile(fileName, "RECREATE");
}

void HManager::writeAndCloseFile(void)
{
    if(outFile_)
    {
	outFile_->Write();
	delete outFile_;
	outFile_ = 0;
	  
        outFile_->Close();
        delete outFile_;
        outFile_ = 0;
    }
}
