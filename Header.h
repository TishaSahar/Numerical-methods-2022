#pragma once

#include <iostream>
#include <math.h>
#include <iomanip>

#define precision 7
//#define psiTrapeze 0.667
//#define psiSimpson 0.00833
//#define psiTE 0.00416



double f(double x);
double intF();

double Trapeze(double a, double b, double h);
double Simpson(double a, double b, double h);
double threeOfeight(double a, double b, double h);

double epsT(double h);
double epsS(double h);
double epsTE(double h);

double checkH(double a = 1.0, double b = 2.0, double n = 100);
void CalculateByEps(double eps = 0.0001);
void Runge(double _eps);