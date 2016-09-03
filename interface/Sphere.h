#ifndef Sphere_H
#define Sphere_H

class Sphere
{
	public: 
	
	Sphere( double Radius = 1);
	~Sphere(void);
	void CalcXYZ_Point1( double theta, double phi);
	void CalcXYZ_Point2( double theta, double phi);	
	double CalcDistance(void);
	void PrintValues(void);

	private:
	
	//Angles
	double theta1_;
	double phi1_;
	
	double theta2_;
	double phi2_;

	// Point 1
	double X1_;
	double Y1_;
	double Z1_;

	// Point 2
    double X2_;
	double Y2_;
	double Z2_;
	
	// Lines calculated
	
	double LineDistance_;
	double NumberOfLines_;
	double SumOfDistances_;

	// Radius Default to 1
	double Radius_;
	
	double CalcX(double theta, double phi);
	double CalcY(double theta, double phi);
	double CalcZ(double theta, double phi);


};

#endif
