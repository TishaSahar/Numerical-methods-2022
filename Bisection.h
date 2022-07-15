#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
#include <fstream>
#include <iomanip>

#define EPS1 0.001
#define EPS 0.001

double F(double x);
double derivF(double x);


double Bisection(double a, double b);
void Newton(double x);
void simpleIteration(double x);


//double sysFist(double x, double y);
//double sysSec(double x, double y);


double* Sys(double* _m);
double Jacoby(double* _x);
void systemNewton(double* x);
void systemSimIteration(double* x);