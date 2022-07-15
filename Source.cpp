#include "Header.h"

double f(double x)
{
	if (x != 0.0)
	{
		return 3 * x * x + 1 / x;
	}
	std::cout << "Error! x == 0!" << std::endl;
	return -1;
}


double intF()
{
	return 7 + log(2);
}


double Trapeze(double a, double b, double h)
{
	double trap = 0.0;
	double x = a;
	while (x < b)
	{
		trap += 0.5 * h * (f(x) + f(x + h)); //std::cout << trap << "\n";
		x += h;
	}

	return trap;
}

double Simpson(double a, double b, double h)
{
	double simp = f(a) + f(b);
	double x = a + h;
	int i = 1;
	while (x < b)
	{
		if (i % 2 == 1)
			simp += 4.0 * f(x);
		else
			simp += 2.0 * f(x);
		x += h;
		i++;
	}

	return simp * h / 3.0;
}

double threeOfeight(double a, double b, double h)
{
	double res = f(a) + f(b);
	double x = a + h;
	int i = 1;

	while (x < b)
	{
		if (i % 3 == 0)
			res += 2.0 * f(x);
		else
			res += 3.0 * f(x);
		x += h;
		i++;					//std::cout << i << " " << res << std::endl;
	}
	
	return 0.3750 * res * h;
}


double epsT(double h) 
{
	return 2.0 * h * h / 3.0;
}

double epsS(double h)
{
	return 0.1333 * h * h * h * h;
}
double epsTE(double h)
{
	return 0.3 * h * h * h * h;
}

double checkH(double a, double b, double n)
{
	double h = 1.0 / n;
	while (abs(a - b + (n - 1) * h) > 0.000001)
	{
		n += 1.0;
		h = 1.0 / n;
	}
	return h;
}

void CalculateByEps(double eps)
{
	double mTr = 1.0;
	double mSm = 1.0;
	double mTe = 1.0;


	while (epsT(1.0 /mTr) > eps)
	{
		mTr += 1.0;
	}

	while (epsS(1.0 / mSm) > eps)
	{
		mSm += 1.0;
	}

	while (epsTE(1.0 / mTe) > eps)
	{
		mTe += 1.0;
	}

	double hTr = checkH(1.0, 2.0, mTr);
	double hSm = checkH(1.0, 2.0, mSm);
	double hTe = checkH(1.0, 2.0, mTe);



	std::cout << "\n====================	Calculation of the step by th specified EPS 	=====================\n";
	std::cout << "Trapeze:          \t" << std::setprecision(precision) << std::setw(10) << hTr << "	\t" << std::setprecision(precision) << std::setw(10) << Trapeze(1.0, 2.0, hTr) << std::endl;
	std::cout << "Simpson:          \t" << std::setprecision(precision) << std::setw(10) << hSm << "	\t" << std::setprecision(precision) << std::setw(10) << Simpson(1.0, 2.0, hSm) << std::endl;
	std::cout << "3/8:              \t" << std::setprecision(precision) << std::setw(10) << hTe << "	\t" << std::setprecision(precision) <<	std::setw(10) << threeOfeight(1.0, 2.0, hTe) << std::endl;
	std::cout << "\==============================================================================================\n";
}

void Runge(double _eps)
{
	double Tr, Tr2, Sm, Sm2, Te, Te2;
	double h1 = 0.1, h2 = 0.1, h3 = _eps;

	Tr = Trapeze(1.0, 2.0, h1);
	Tr2 = Trapeze(1.0, 2.0, h1 / 2.0);
	while (abs(Tr2 - Tr) * 4 / 3 > _eps)
	{
		h1 /= 2.0;
		Tr = Trapeze(1.0, 2.0, h1);
		Tr2 = Trapeze(1.0, 2.0, h1 / 2.0);
	}

	Sm = Simpson(1.0, 2.0, h2);
	Sm2 = Simpson(1.0, 2.0, h2 / 2.0);
	while (abs(Sm2 - Sm) * 16 / 15 > _eps)
	{
		h2 /= 2.0;
		Sm = Simpson(1.0, 2.0, h2);
		Sm2 = Simpson(1.0, 2.0, h2 / 2.0);
	}

	Te = threeOfeight(1.0, 2.0, h3);
	Te2 = threeOfeight(1.0, 2.0, h3 / 2.0);
	while (abs(Te2 - Te) * 32 / 31 > _eps)
	{
		h3 /= 2.0;
		Te = threeOfeight(1.0, 2.0, h3);
		Tr2 = threeOfeight(1.0, 2.0, h3 / 2.0);
	}

	//double h;
	//if (h1 < h2)
	//	if (h1 < h3)
	//		h = h1;
	//	else
	//		if (h2 < h3)
	//			h = h2;
	//		else 
	//			h = h3;

	std::cout << "\n====================		Calculaton of the step by Runge method		======================\n";
	std::cout << "Trapeze:          \t" << std::setprecision(precision) <<	std::setw(10) <<  h1 << "	\t" <<  std::setprecision(precision) << std::setw(10) << Tr << std::endl;
	std::cout << "Simpson:          \t" << std::setprecision(precision) <<	std::setw(10) <<  h2 << "	\t" <<  std::setprecision(precision) << std::setw(10) << Sm << std::endl;
	std::cout << "3/8:              \t" << std::setprecision(precision) <<	std::setw(10) <<  h3 << "	\t" <<  std::setprecision(precision) << std::setw(10) << Te << std::endl;
	std::cout << "\===============================================================================================\n";
}