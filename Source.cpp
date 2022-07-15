#include "Bisection.h"

double F(double x)
{
	if (x != 0.0)
		return cos(x) / sin(x) - x * x;
	else
		return 0;
}

double derivF(double x)
{
    if (x != 0.0)
        return (-1.0 / (sin(x) * sin(x))) - 2.0 * x;
    else
        return 0;
}


double Bisection(double a, double b)
{
    if (F(a) * F(b) >= 0)
    {
        std::cout << "You have not assumed right a and b in Bisection method: " << (a + b) / 2.0 <<  std::endl;
        return (a + b) / 2.0;
    }

    double c = a;
    int i = 0;
    while ((b - a) >= EPS)
    {
        i++;
        // Find middle point
        c = (a + b) / 2;

        // Check if middle point is root
        if (F(c) == 0.0)
            break;

        // Decide the side to repeat the steps
        else if (F(c) * F(a) < 0)
            b = c;
        else
            a = c;
    }
    std::cout << "Bisection iteratons:\t" << i << std::endl;
    return c;
}

void Newton(double x)
{
    if (derivF(x) == 0.0)
        std::cout << "You have not assumed x in Newton mathod!" << std::endl;
    double h = F(x) / derivF(x);
    int i = 0;
    while (abs(h) >= EPS)
    {
        h = F(x) / derivF(x);
        x -= h;
        i++;
    }

    std::cout << "The value of the root is : " << std::setprecision(7) << x << std::endl << "Newton num of iter:\t" << i << std::endl;
}

void simpleIteration(double x)
{
    double x0 = x;
    x = F(x0);
    double h = F(x) * (x - x0) / (F(x) - F(x0));
    int i = 0;
    while (abs(h) >= EPS)
    {
        x0 = x;
        x -= h;
        h = F(x) * (x - x0) / (F(x) - F(x0));
        i++;
    }
    std::cout << "The value of the root is: " << std::setprecision(7) << x << std::endl << "Simple Iter num of iter:\t" << i << std::endl;
}


double sysFist(double x, double y)
{
    return 0;
}

double* Sys(double* _m)
{
    double* res = new double[2];
    res[0] = cos(_m[0] + 0.5) + _m[1] - 0.8;
    res[1] = - 2 * _m[0] + sin(_m[1]) - 1.6;

    return res;
}

double Jacoby(double* _x)
{
    return -sin(_x[0] + 0.5) * cos(_x[1]) + 2.0;
}


void systemNewton(double* x)
{
    double Det = Jacoby(x);
    if (Det == 0.0)
        std::cout << "You have not assumed x in Newton mathod!" << std::endl;
    double h1 = Sys(x)[0] / Det;
    double h2 = Sys(x)[1] / Det;
    while (abs(h1) >= EPS || abs(h2) >= EPS) 
    {
        h1 = Sys(x)[0] / Jacoby(x);
        h2 = Sys(x)[1] / Jacoby(x);
        x[0] -= h1;
        x[1] -= h2;
    }

    std::cout << "System solution by Newton method: {" << std::setprecision(7) << x[0] << ", " << std::setprecision(7) << x[1] << "}" << std::endl;
}

void systemSimIteration(double* x)
{
    double* x0 = new double[2]; x0[0] = x[0]; x0[1] = x[1];
    x = Sys(x0);
    double S1 = Sys(x)[0]; double S01 = Sys(x0)[0];
    double S2 = Sys(x)[1]; double S02 = Sys(x0)[1];
    double h1 = Sys(x)[0] * (x[0] - x0[0]) / (Sys(x)[0] - Sys(x0)[0]);
    double h2 = Sys(x)[1] * (x[1] - x0[1]) / (Sys(x)[1] - Sys(x0)[1]);
    while (abs(h1) >= EPS1 || abs(h2) >= EPS1)
    {
        x0[0] = x[0];
        x0[1] = x[1];
        x[0] -= h1;
        x[1] -= h2;
        S01 = Sys(x0)[0];
        S02 = Sys(x0)[1];
        S1 = Sys(x)[0];
        S2 = Sys(x)[1];
        h1 = S1 * (x[0] - x0[0]) / (S1 - S01);
        h2 = S2 * (x[1] - x0[1]) / (S2 - S02);
    }

    std::cout << "System solution by Simple Iteration method : {" << std::setprecision(7) << x[0] << ", " << std::setprecision(7) << x[1] << "}" << std::endl;
}