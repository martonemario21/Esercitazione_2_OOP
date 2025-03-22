#include <iostream>
#include "complex_number.hpp"  // Includiamo la classe

int main() {
    // Creiamo due numeri complessi
    complex_number<double> c1(3.0, 4.0);
    complex_number<double> c2(11.0, 10.0);
	complex_number<double> c3=c1+c2;

    // Stampiamo i valori
    std::cout << c3 << "\n";

    return 0;
}