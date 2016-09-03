#include <iostream>
#include <stdlib.h>
#include "Sphere.h"
#define PI 3.14159265

/*	------------------------MC_Sphere by Richard Brosius-----------------------------
	-Build with makefile by typing "make" in the src directory
	-This program demonstrates a simple Monte Carlo Method for calculating the average 
	 distance between two points picked at random on the surface of a unit sphere.
	-The sample size can be passed as a command line argument 
*/

using namespace std;
int main(int argc, char** argv)
{
	int EVENTS = 0;    

	if (argc < 2) {
			EVENTS        = 100000;
			cout << "Running with default sample size 100,000 points";
	}
	else {
			EVENTS = atoi(argv[1]);			
			cout << "Running with sample size " << EVENTS << " points";
	}

    int       NumberOfLines = 0;
    double rand_Theta    = 0.0;
    double rand_Phi      = 0.0;
    double distance   	 = 0.0;
    double TotalDistance = 0.0;
    srand((unsigned)time(0));
    Sphere   unitSphere;
    cout << "\n";    

	for(int i = 1; i < EVENTS + 1; ++i)    
	{
             rand_Theta =   (float)rand() / (float)RAND_MAX * PI   ;	//Rand    0 < Phi      < 2*PI
 	     rand_Phi  =   (float)rand() / (float)RAND_MAX * PI*2 ;  //Rand    0 < Theta  <   PI
	     unitSphere.CalcXYZ_Point1(rand_Theta, rand_Phi);
             rand_Theta =   (float)rand() / (float)RAND_MAX * PI   ;	//Rand    0 < Phi      < 2*PI
 	     rand_Phi  =   (float)rand() / (float)RAND_MAX * PI*2 ;  //Rand    0 < Theta  <   PI
	     unitSphere.CalcXYZ_Point2(rand_Theta, rand_Phi);
	     distance = unitSphere.CalcDistance();
	     ++NumberOfLines;
	     TotalDistance += distance;  
   	}
	cout << " Total Events: " << NumberOfLines;  
	cout << " \n Average Distance: " << TotalDistance / NumberOfLines << " units \n";	
return 0;
}
