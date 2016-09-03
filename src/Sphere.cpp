#include "Sphere.h"
#include <math.h>
#include <iostream>

using namespace std;

Sphere::Sphere( double Radius) 
:  theta1_ (0), phi1_(0),
  theta2_ (0), phi2_(0),
  X1_ (0),  Y1_ (0), Z1_ (0), X2_ (0), Y2_ (0), Z2_ (0),
  LineDistance_ (0), NumberOfLines_ (0), SumOfDistances_ (0), 
  Radius_  (Radius)
{}

Sphere::~Sphere()
{}

void Sphere::CalcXYZ_Point1(double theta, double phi)
{
	theta1_ = theta;
	phi1_   = phi;
	X1_= Sphere::CalcX(theta,phi);
	Y1_= Sphere::CalcY(theta,phi);
	Z1_= Sphere::CalcZ(theta,phi);
		
}

void Sphere::CalcXYZ_Point2(double theta, double phi)
{
	theta2_ = theta;
	phi2_   = phi;
	X2_= Sphere::CalcX(theta,phi);
	Y2_= Sphere::CalcY(theta,phi);
	Z2_= Sphere::CalcZ(theta,phi);
}


double Sphere::CalcDistance(void)
{
	double dx = (X2_ - X1_);
	double dy = (Y2_ - Y1_);
	double dz = (Z2_ - Z1_);
	
	LineDistance_ = sqrt( pow(dx ,2.0) + pow(dy ,2.0) + pow(dz, 2.0) );
	SumOfDistances_ += LineDistance_;
	++NumberOfLines_; 
	return LineDistance_; 
}


double Sphere::CalcX(double theta, double phi)
{
	return Radius_*sin(theta)*cos(phi);
}

double Sphere::CalcY(double theta, double phi)
{
	return Radius_*sin(phi)*sin(theta);
}

double Sphere::CalcZ(double theta, double phi)
{
	return Radius_*cos(theta);
}

void Sphere::PrintValues(void)
{
  
  cout << "\n\nPoint1: " << " " << theta1_ << " " << phi1_ << "            " << X1_ << " " << Y1_ << " " << Z1_ << "\n";
  cout << "\nPoint2: " << " " << theta2_ << " " << phi2_ << "            " << X2_ << " " << Y2_ << " " << Z2_ << "\n";
  cout << "Result:     Distance" << LineDistance_ << "      Total Distance " << SumOfDistances_ << "\n\n\n";

}
