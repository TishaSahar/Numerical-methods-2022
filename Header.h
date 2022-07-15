#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>


using namespace std;

//class DE
//{
//public:
//	double x1, x2;
//
//	DE(double _x1 = 0.0, double _x2 = 1.0) { x1 = _x1; x2 = _x2; }
//};
//
//class Fu



class Solution
{
public:
	double x1, x2;
	int n;

	Solution(double _x1 = 0.0, double _x2 = 1.0, int _n = 10) { x1 = _x1; x2 = _x2; n = _n; }


	// x' = 2y*e^y + x
	// y = [0, 1], x(0) = 2

	double Fxy(double x, double y)
	{
		return 2.0 * y * exp(y) + x;
	}

	// System of fiffernt equations
	// {y' = x^2 - z, z' = y + x} 
	// x = [0, 1], y(0) = 1, z(0) = 1
		
	// #1 y' = x^2 - z

	double Yxz(double x, double z)
	{
		return x * x - z;
	}

	// #2 z' = y + x

	double Zxy(double x, double y)
	{
		return y + x;
	}

	void JustEiler(double X0 = 2.0, double Y0 = 0.0, int n = 10);
	void RK2(double X0 = 2.0, double Y0 = 0.0, int n = 10);
	void AdvancedEiler(double X0 = 2.0, double Y0 = 0.0, int n = 10);
};

