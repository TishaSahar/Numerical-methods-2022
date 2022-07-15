// R-K-1

#include "Header.h"






void Solution::JustEiler(double X0, double Y0, int n)
{
	ofstream out1("SimpleEilerMethod - DE.txt");
	ofstream out2("SimpleEilerMethof - SDE.txt");

	double X1 = X0; double X12 = X0; double X14 = X0;
	double X2 = X0; double X22 = X0; double X24 = X0;
	double X3 = X0;	double X32 = X0; double X34 = X0;

	double Y4 = Y0; double Y2 = Y0; double Y1 = Y0;

	double h = 1.0 /(4.0 * (double) n );
	out1 << "Iter          F(h)           F(h/2)     F(h/2) - F(h)       F(h/4)      F(h/4) - F(h) " << std::endl;
	for (int i = 1; i <= n * 4 + 1; i++)
	{
		if (i % 4 == 1)
		{
			//std::out1.setw(ios::fixed);
			out1 << i / 4 << "\t  " << std::setw(10) << std::setprecision(n / 2) << X1
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << X12
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << X12 - X1
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << X14
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << X14 - X1 << std::endl;
			out2 << i / 4 << 
				"\t " << std::setw(10) << std::setprecision(n / 2) << X2 << "\t " << std::setw(10) << std::setprecision(n / 2) << X3 << " " <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << X22 << "\t " << std::setw(10) << std::setprecision(n / 2) << X32 << " " <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << X22 - X2 << "\t " << std::setw(10) << std::setprecision(n / 2) << X32 - X3 << " " <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << X24 << "\t " << std::setw(10) << std::setprecision(n / 2) << X34 << " " << 
				"\t " << std::setw(10) << std::setprecision(n / 2) << X24 - X2 << "\t " << std::setw(10) << std::setprecision(n / 2) << X34 - X3 << " " << std::endl;

		}



		// 1st DU solution

		// 2nd System solution,

		// where X2 <-> y, X3 <-> z

		Y4 = Y4 + h;
		X14 = X14 + h * Fxy(X14, Y4);
		X24 = X24 + h * Yxz(Y4, X34);
		X34 = X34 + h * Zxy(Y4, X24);
		if (i % 2 == 0)
		{
			X12 = X12 + 2.0 * h * Fxy(X12, Y4);
			X22 = X22 + 2.0 * h * Yxz(Y4, X32);
			X32 = X32 + 2.0 * h * Zxy(Y4, X22);
		}

		if (i % 4 == 0)
		{
			X1 = X1 + 4.0 * h * Fxy(X1, Y4);
			X2 = X2 + 4.0 * h * Yxz(Y4, X3);
			X3 = X3 + 4.0 * h * Zxy(Y4, X2);
		}
	}
}

void Solution::RK2(double X0, double Y0, int n)
{
	ofstream out1("Runge-Kutt-Method_DE.txt");
	ofstream out2("Runge-Kutt-Method_SDE.txt");

	double K1;
	double Ftmp;

	double Xde1 = X0, Xde2 = X0, Xde4 = X0;
	double Ysde1 = X0, Ysde2 = X0, Ysde4 = X0;
	double Zsde1 = X0, Zsde2 = X0, Zsde4 = X0;
	double h = 1.0 / (4.0 * (double) n);

	out1 << "Iter          F(h)           F(h/2)     F(h/2) - F(h)       F(h/4)      F(h/4) - F(h) " << std::endl;

	for (int i = 1; i <= 4 * n + 1; i++)
	{ 
		if (i % 4 == 1)
		{
			//std::out1.setw(ios::fixed);
			out1 << i / 4 << "\t  " << std::setw(10) << std::setprecision(n / 2) << Xde1
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << Xde2
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << Xde2 - Xde1
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << Xde4
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << Xde4 - Xde1 << std::endl;
			out2 << i / 4 <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << Ysde1 << "\t " << std::setw(10) << std::setprecision(n / 2) << Zsde1 << " " <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << Ysde2 << "\t " << std::setw(10) << std::setprecision(n / 2) << Zsde2 << " " <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << Ysde2 - Ysde1 << "\t " << std::setw(10) << std::setprecision(n / 2) << Zsde2 - Zsde1 << " " <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << Ysde4 << "\t " << std::setw(10) << std::setprecision(n / 2) << Zsde4 << " " <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << Ysde4 - Ysde2 << "\t " << std::setw(10) << std::setprecision(n / 2) << Zsde4 - Zsde1 << " " << std::endl;
		}
		Ftmp = Fxy(Xde4, Y0);
		K1 = Xde4 + h * Ftmp;
		Xde4 = Xde4 + 0.5 * h * (Ftmp + Fxy(K1, Y0 + h));
		Ysde4 = Ysde4 + 0.5 * h * (Yxz(Y0, Zsde4) + Yxz(Y0 + h, Zsde4 + h * Zxy(Y0, Ysde4)));
		Zsde4 = Zsde4 + 0.5 * h * (Zxy(Y0, Ysde4) + Zxy(Y0 + h, Ysde4 + h * Yxz(Y0, Zsde4)));
		if (i % 2 == 1)
		{
			Ftmp = Fxy(Xde2, Y0);
			K1 = Xde2 + 2.0 * h * Ftmp;
			Xde2 = Xde2 + h * (Ftmp + Fxy(K1, Y0 + 2.0 * h));
			Ysde2 = Ysde2 + h * (Yxz(Y0, Zsde2) + Yxz(Y0 + 2.0 * h, Zsde2 + 2.0 * h * Zxy(Y0, Ysde2)));
			Zsde2 = Zsde2 + h * (Zxy(Y0, Ysde2) + Zxy(Y0 + 2.0 * h, Ysde2 + 2.0 * h * Yxz(Y0, Zsde2)));
		}
		if (i % 4 == 1) 
		{
			Ftmp = Fxy(Xde1, Y0);
			K1 = Xde1 + 4.0 * h * Ftmp;
			//double Ytmp = Y0 + 3.0 * h;
			Xde1 = Xde1 + 2.0 * h * (Ftmp + Fxy(K1, Y0 + 4.0 * h));
			Ysde1 = Ysde1 + 2.0 * h * (Yxz(Y0, Zsde1) + Yxz(Y0 + 4 * h, Zsde1 + 4.0 * h * Zxy(Y0, Ysde1)));
			Zsde1 = Zsde1 + 2.0 * h * (Zxy(Y0, Ysde1) + Zxy(Y0 + 4 * h, Ysde1 + 4.0 * h * Yxz(Y0, Zsde1)));
		}
		Y0 += h;
	}
	
}

void Solution::AdvancedEiler(double X0, double Y0, int n)
{
	ofstream out1("AdvancedEilerMethod_DE.txt");
	ofstream out2("AdvancedEilerMethod_SDE.txt");

	double Xde1 = X0, Xde2 = X0, Xde4 = X0;
	double halfX;

	double Ysde1 = X0, Ysde2 = X0, Ysde4 = X0;
	double Zsde1 = X0, Zsde2 = X0, Zsde4 = X0;
	double h = 1.0 / (4.0 * (double)n);

	out1 << "Iter          F(h)           F(h/2)     F(h/2) - F(h)       F(h/4)      F(h/4) - F(h) " << std::endl;
	for (int i = 1; i <= 4 * n + 1; i++)
	{
		if (i % 4 == 1)
		{
			//std::out1.setw(ios::fixed);
			out1 << i / 4 << "\t  " << std::setw(10) << std::setprecision(n / 2) << Xde1
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << Xde2
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << Xde2 - Xde1
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << Xde4
				<< "\t  " << std::setw(10) << std::setprecision(n / 2) << Xde4 - Xde1 << std::endl;
			out2 << i / 4 <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << Ysde1 << "\t " << std::setw(10) << std::setprecision(n / 2) << Zsde1 << " " <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << Ysde2 << "\t " << std::setw(10) << std::setprecision(n / 2) << Zsde2 << " " <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << Ysde2 - Ysde1 << "\t " << std::setw(10) << std::setprecision(n / 2) << Zsde2 - Zsde1 << " " <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << Ysde4 << "\t " << std::setw(10) << std::setprecision(n / 2) << Zsde4 << " " <<
				"\t " << std::setw(10) << std::setprecision(n / 2) << Ysde4 - Ysde1 << "\t " << std::setw(10) << std::setprecision(n / 2) << Zsde4 - Zsde1 << " " << std::endl;
		}

		halfX = Xde4 + 0.5 * h * Fxy(Xde4, Y0);
		Xde4 = Xde4 + h * Fxy(halfX, Y0 + 0.5 * h);


		Ysde4 = Ysde4 + h * Yxz(Y0 + 0.5 * h, Zsde4 + 0.5 * h * Zxy(Y0, Ysde4));
		Zsde4 = Zsde4 + h * Zxy(Y0 + 0.5 * h, Ysde4 + 0.5 * h * Yxz(Y0, Zsde4));

		if (i % 2 == 1)
		{
			halfX = Xde2 + h * Fxy(Xde2, Y0);
			Xde2 = Xde2 + 2 * h * Fxy(halfX, Y0 + h);
			Ysde2 = Ysde2 + 2 * h * Yxz(Y0 + h, Zsde2 + h * Zxy(Y0, Ysde2));
			Zsde2 = Zsde2 + 2 * h * Zxy(Y0 + h, Ysde2 + h * Yxz(Y0, Zsde2));
		}

		if (i % 4 == 1)
		{
			halfX = Xde1 + 2.0 * h * Fxy(Xde1, Y0);
			Xde1 = Xde1 + 4.0 * h * Fxy(halfX, Y0 + 2 * h);
			Ysde1 = Ysde1 + 4.0 * h * Yxz(Y0 + 2 * h, Zsde1 + 2.0 * h * Zxy(Y0, Ysde1));
			Zsde1 = Zsde1 + 4.0 * h * Zxy(Y0 + 2 * h, Ysde1 + 2.0 * h * Yxz(Y0, Zsde1));
		}
		Y0 += h;
	}

}


