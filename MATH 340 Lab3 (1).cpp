//Don Parker
//MATH 340 Lab 3
//April 8th 2023
//This is my own owrk and has not been copied from another student or the internet. 

#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


void Composite_Trapezoid(int steps)
{
	double area = 0;
	
	for (double i = 0; i < steps; i++)
	{
		area += sin(i / steps * M_PI) + sin((i + 1) /  steps * M_PI);
	}
	
	area *= M_PI / (2 * steps);
	
	cout << "Trapezoid\n";
	cout << "int = " << setprecision(16) << area << endl;
	cout << "error = " << setprecision(16) << (2 - area) << endl << endl;
}

void Composite_Simpsons(int steps)
{
	double area = 0;
	
	for (double i = 0; i < steps; i+=2)
	{
		area += sin(i / steps * M_PI) + 4 * sin((i + 1) /  steps * M_PI) + sin((i + 2) / steps * M_PI);
	}
	
	area *= M_PI / (3 * steps);
	cout << "Simpsons\n";
	cout << "int = " << setprecision(16) << area <<  endl;
	cout << "error = " << setprecision(16) << (2 - area) << endl << endl;
	
	
}

void RombergQ3(int steps)
{
	double area = 0;
	
	for (double i = 0; i < steps; i+=4)
	{
		area += 14 * sin(i / steps * M_PI) + 64 * sin((i + 1) /  steps * M_PI) + 24 * sin((i + 2) / steps * M_PI) + 64 * sin((i + 3) / steps * M_PI) + 14 * sin((i + 4) / steps * M_PI);
	}
	
	area *= M_PI / (45 * steps);
	cout << "Romberg Q3\n";
	cout << "int = " << setprecision(16) << area << endl;
	cout << "error = " << setprecision(16) << (2 - area) << endl << endl;
	
	
}

void GaussianQuad2(int steps)
{
	double area = 0;
	
	area = (M_PI / 2) * ( sin( (M_PI  * 0.5773502691896257645091488 + M_PI) / 2 ) + sin( (M_PI * -0.5773502691896257645091488 + M_PI) / 2 ) );
	
	cout << "Gaussian (n=2)\n";
	cout << "double = " << setprecision(17) << area << endl;
	cout << "error = " << setprecision(16) << (2 - area) << endl << endl;
	
}


int main()
{
	int steps;
	
	cout << "How many steps? ";
	cin >> steps;
	
	Composite_Trapezoid(steps);
	Composite_Simpsons(steps);
	RombergQ3(steps);
	GaussianQuad2(steps);
	
	return 0;
}
