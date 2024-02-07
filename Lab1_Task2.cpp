//Don Parker
//Lab1_Task2
// March 23rd 2023 
//This is my original work and was not obtained through the internet or other people

#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double msqrt(double x, double stop_tolerance)
{
	double cons = x;
	double value = x;
	double valueNext;
	double tolerance = 3;

	while(tolerance > stop_tolerance)
	{	
		valueNext = value - (( value * value - cons ) / (2 * value));
		tolerance = abs(valueNext - value);
		value = valueNext;
	}
	return value;
}

double f(double x,double stop_tolerance)
{	
	return 2 * pow(x,4) - (1 + msqrt(5,stop_tolerance)) * pow(x,2) - (3 + msqrt(5,stop_tolerance));
}

double df(double x, double stop_tolerance)
{
	return 8 * pow(x,3) - (2 + 2 * msqrt(5,stop_tolerance)) * x;	
}


void method_Newton()
{
	double precision;
	double value;
	double valueNext;
	double stop_tolerance;
	double tolerance = 1;
	int n = 1;
	int count = 1;
	
	cout << "Enter precision t: ";
	cin >> precision;
	
	cout << "Enter initial guess: ";
	cin >> value;
	
	cout << "i  pn\n";
	
	stop_tolerance = pow(10, -1 * precision);
	
	
	while(tolerance > stop_tolerance)
	{	
		cout << count << " ";
		count++;
		valueNext = value - f(value,stop_tolerance) / df(value,stop_tolerance);
		cout << setprecision(12) << valueNext << endl;
		n ++;
		tolerance = abs(valueNext - value);
		value = valueNext;
	}
	
	cout << setprecision(12) << value << " is fixed point\n";
	cout << setprecision(12) << "with f(p) = " << f(value,stop_tolerance) << endl;
	cout << "tolerance = " << setprecision(12) << stop_tolerance;
	
	
}

int main()
{
	method_Newton();
	return 0;
}
