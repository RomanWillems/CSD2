/*
    Rekenen met complexe getallen in C++.          COPYLEFT Pieter Suurmond 2021

    Compileer op de unix-commandline met:
        g++ CGH1.cpp -o CGH1

    Run vervolgens met:
        ./CGH1

    Zie evt http://www.cplusplus.com/reference/complex/ voor meer functies.
*/

#include <iostream>
#include <complex>

using namespace std;

int main()
{
    cout << "Drie sommen uit Jan van de Craats CG voor wiskunde D:\n";

    // Bij de constructor moet je de grootte aangeven (float of double),
    // en daarna, tussen haakjes, reeele deel komma imaginaire deel.

    // Som 1.9 a: VERMENIGVULDIGEN
    complex<float> z1(1.0,-2.0);                        // 1-2i
    complex<float> z2(3.0,-4.0);                        // 3-4i
    cout << " Som 1.9 a: " << z1 * z2  << "\n";

    // Som 1.11 e: MACHTSVERHEFFEN en ABSOLUTE WAARDE
    complex<double> z(1.0,-1.0);                        // 1-i
    complex<double> zzz = pow(z, 3);
    cout << " Som 1.11 e: " << zzz << "\n";
    cout << "             " << abs(zzz)  << "\n";

    // Som 1.19 e: DELEN
    complex<double> teller(1.0, 3.0);                   // 1+3i
    complex<double> noemer(3.0,-1.0);                   // 3-i
    cout << " Som 1.19 e: " << teller / noemer  << "\n\n";

    return 0;
}
