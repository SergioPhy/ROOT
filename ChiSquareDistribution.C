#include<iostream>
#include "Math/Math.h"
#include "Math/SpecFuncMathCore.h"
#include "TF1.h"

int run(){
	
	TF1* f1=new TF1("f1","ROOT::Math::chisquared_pdf(x,2,0)",0,12);
	
	f1->SetTitle("Chi-Square Distribution;#Delta #Chi^{2};Probability");
	f1->Draw();


	//values of confidence levels
	double medianX[1];
	double sigma1X[1];
	double sigma2X[1];
	double sigma3X[1];
	
	//the values given by the GetQuantiles function will save here
	double medianY[1];
	double sigma1Y[1];
	double sigma2Y[1];
	double sigma3Y[1];

	medianX[0]=0.5;
	sigma1X[0]=0.68;
	sigma2X[0]=0.95;
	sigma3X[0]=0.997;

	f1->GetQuantiles(1,medianY,medianX);
	f1->GetQuantiles(1,sigma1Y,sigma1X);
	f1->GetQuantiles(1,sigma2Y,sigma2X);
	f1->GetQuantiles(1,sigma3Y,sigma3X);
  
  cout<<"The integral of the plot is:"<<f1->Integral(0,10)<<endl;
	cout<<"The median is: "<<medianY[0]<<endl;
	cout<<"The 1 sigma value is: "<<sigma1Y[0]<<endl;
	cout<<"The 2 sigma value is: "<<sigma2Y[0]<<endl;
	cout<<"The 3 sigma value is: "<<sigma3Y[0]<<endl;
	
	return 0;
}
