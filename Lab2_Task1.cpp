//Don Parker
//Lab2_Task1
// March 23rd 2023 
//This is my original work and was not obtained through the internet or other people

#include<iostream>
#include<cmath>
#include<string>
using namespace std;

double Q[30][30];

double Neville(double xv[], double yv[], int s, int n)
{

	for(int z = 0; z < n; z++)
	{
		Q[z][0] = yv[z];
	}
	
	for (int i = 1; i < n; i++)
		{
			for(int j = 1; j <= i; j++)
			{
				Q[i][j] = ((s - xv[i-j]) * Q[i][j-1] - (s - xv[i])* Q[i-1][j-1])/(xv[i] - xv[i-j]);
			}
		}
	
	return Q[n-1][n-1];
}

int main()
{
	char comma;
	int n;
	double z;
	double point;
	
	cout << "how many data points? ";
	cin >> n;
	
	double xv[n];
	double yv[n];
	
	for(int i = 0; i < n; i++)
	{
		cout << "Enter point " << i + 1 << " as x,y: ";
		cin >> xv[i] >> comma >>  yv[i];
	}
	
	cout << "Evaluate at what x-value: ";
	cin >> point;
	z = Neville(xv,yv,point,n);
	cout << "the value of P(" << point << ") is " << z << endl;
	cout << "with err = " << abs(z - (1/ point)) << " when f(x) = " << 1/point;
	
	
	
	return 0;
}
