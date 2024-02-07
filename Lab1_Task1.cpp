
//Don Parker
//Lab1_Task1
// March 23rd 2023 
//This is my original work and was not obtained through the internet or other people

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

double factorial(double x)
{
	double value = 1;
	
	if(x < 2)
	{
		return value;
	}
	else
	{
		for(double i = 1; i <= x; i++)
		{
			value = value * i;
		}
		return value;
		
	}
	
}


double msin(double x, double stop_tolerance)
{
	double tolerance = 1;
	double value = 0;
	double valueNext = 0;
	int n = 0;
	stop_tolerance = pow(10, -1 * stop_tolerance);
	
	while(tolerance > stop_tolerance)
	{
		
		valueNext = value + pow(-1,n) * pow(x,2*n+1) / factorial(2*n + 1);
		n ++;
		tolerance = abs(valueNext - value);
		value = valueNext;
	}
	
	return value;
	
}

double mcos(double x, double stop_tolerance)
{
	double tolerance = 1;
	double value = 0;
	double valueNext = 0;
	int n = 0;
	stop_tolerance = pow(10, -1 * stop_tolerance);
	
	while(tolerance > stop_tolerance)
	{
		
		valueNext = value + pow(-1,n) * pow(x,2*n) / factorial(2*n);
		n ++;
		tolerance = abs(valueNext - value);
		value = valueNext;
	}
	
	return value;
	
	
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
		valueNext = value - (msin(value,precision) / mcos(value,precision));
		cout << setprecision(12) << valueNext << endl;
		n ++;
		tolerance = abs(valueNext - value);
		value = valueNext;
	}
	
	cout << setprecision(12) << value << " is fixed point\n";
	cout << setprecision(12) << "with f(p) = " << msin(value,precision) << endl;
	cout << "tolerance = " << setprecision(12) << stop_tolerance;
	
	
}

int main()
{

	method_Newton();
	
	return 0;
}
