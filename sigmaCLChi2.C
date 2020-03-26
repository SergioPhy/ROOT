#include <iostream>
#include "TF1.h"
#include "TMath.h"
#include "Math/Math.h"

using namespace std;

double CalculateCLGivenSigma(double sigma){
	
	//Create a Gaussian TF1 object
	TF1* func=new TF1("func","TMath::Gaus(x,[0],[1],kTRUE)",-5,5);
	func->SetParameter(0,0);
	func->SetParameter(1,1);
	
	//Define the string that will save the confidence level
	double CL[1];

	//Integrate and return the confidence level
	CL[0] = func->Integral(-sigma,sigma);

	return CL[0];
}

double GetChi2ForCL(double CL){
	
	//Create a ChiSquare distribution TF1 object
	TF1* func=new TF1("func","ROOT::Math::chisquared_pdf(x,2,0)",0,20);
	//Define the strings that will save the confidence level and chi2 respectively
	double chi2X[1];
	double chi2Y[1];
	
	//Asign the value of confidence level
	chi2X[0] = CL;
	
	//Obtain the chi2 and retur its value
	func->GetQuantiles(1,chi2Y,chi2X);
	
	return chi2Y[0];
}

int main(){
	double sigma;
	double CL;
	double chi2;

	cout<<"enter the sigma value: ";
	cin >> sigma;
  
	CL = CalculateCLGivenSigma(sigma);
	cout<<"The confidence level is: "<<100*CL<<"% CL"<<endl;
	
	chi2 = GetChi2ForCL(CL);
	cout<<"The chi square correspond to this CL is: "<<chi2<<endl;
}
