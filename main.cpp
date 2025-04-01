#include <iostream>
#include "complex_number.hpp"  // Includiamo la classe

int main() {
    // Creiamo due numeri complessi
    complex_number<double> c1(3.0, 4.0);
    complex_number<double> c2(-11.0, -4.0);
		
	double x = 10;
	complex_number<double> c3 = x+c1;
	complex_number<double> c4 = x*c2;
	complex_number<double> c5 = c1+x;
	complex_number<double> c6 = c2*x;
	complex_number<double> c7 = 10.0+c3;

	
    // Stampiamo i valori
    std::cout << c7 << std::endl;

    return 0;
}