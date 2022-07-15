// Numerical Integration.cpp : 
// This program calculate integral by 3𝑥^2 + 1/x in range x = [1: 2], h = 0.01, h = 0.02 by "Simpson" and "3/8" methods
//

#include "Header.h"


int main()
{
    double h1 = 0.10;
    double h2 = 0.020;

    double a = 1.0; double b = 2.0;

    std::cout << "Analytic solution:\t" << intF() << std::endl;

    double Tr1 = Trapeze(a, b, h1);
    double Sm1 = Simpson(a, b, h1);
    double TE1 = threeOfeight(a, b, h1);

    std::cout << "\n=========================================\n";
    std::cout << "Trapeze:  \t" << std::setprecision(precision) << std::setw(10) << Tr1 << std::setprecision(precision) << std::endl;
    std::cout << "Simpson:  \t" << std::setprecision(precision) << std::setw(10) << Sm1 << std::setprecision(precision) << std::endl;
    std::cout << "3/8:      \t" << std::setprecision(precision) << std::setw(10) << TE1 << std::setprecision(precision) << std::endl;
    std::cout << "\=========================================\n";
    
    double Tr2 = Trapeze(a, b, h2);
    double Sm2 = Simpson(a, b, h2);
    double TE2 = threeOfeight(a, b, h2);

    std::cout << "\n=========================================\n";
    std::cout << "Trapeze:   \t" << std::setprecision(precision) << std::setw(10) << Tr2 << std::setprecision(precision) << std::endl;
    std::cout << "Simpson:   \t" << std::setprecision(precision) << std::setw(10) << Sm2 << std::setprecision(precision) << std::endl;
    std::cout << "3/8:       \t" << std::setprecision(precision) << std::setw(10) << TE2 << std::setprecision(precision) << std::endl;
    std::cout << "\=========================================\n";

    std::cout << "\n=========================================\n";
    std::cout << "Trapeze Psi vs Real mistake:  \t" << std::setprecision(precision) << std::setw(10) << epsT(h1) << "\t vs \t" << std::setprecision(precision) <<  std::setw(10) << abs(Tr1 - intF()) << std::endl;
    std::cout << "Simpson Psi vs Real mistake:  \t" << std::setprecision(precision) << std::setw(10) << epsS(h1) << "\t vs \t" << std::setprecision(precision) <<  std::setw(10) << abs(Sm1 - intF()) << std::endl;
    std::cout << "3/8     Psi vs Real mistake:  \t" << std::setprecision(precision) << std::setw(10) << epsTE(h1) << "\t vs \t" << std::setprecision(precision) << std::setw(10) << abs(TE1 - intF()) << std::endl;
    std::cout << "\=========================================\n";                                              
                                                                                                              
    std::cout << "\n=========================================\n";                                             
    std::cout << "Trapeze Psi vs Real mistake:  \t" << std::setprecision(precision) << std::setw(10) << epsT(h2) << "\t vs \t" << std::setprecision(precision) << abs(Tr2 - intF()) << std::endl;
    std::cout << "Simpson Psi vs Real mistake:  \t" << std::setprecision(precision) << std::setw(10) << epsS(h2) << "\t vs \t" << std::setprecision(precision) << abs(Sm2 - intF()) << std::endl;
    std::cout << "3/8     Psi vs Real mistake:  \t" << std::setprecision(precision) << std::setw(10) << epsTE(h2) << "\t vs \t" << std::setprecision(precision) << abs(TE2 - intF()) << std::endl;
    std::cout << "\=========================================\n";


    CalculateByEps();
    Runge(0.00001);
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
