#ifndef COMPLEX_NUMBER_HPP
#define COMPLEX_NUMBER_HPP

#include <iostream>
#include <concepts>

template<typename T>
requires std::same_as<T, double> || std::same_as<T, float>


class complex_number {
	T a;
	T b;
	public:
	complex_number(){		//costruttore default
		a = 0.0;
		b = 0.0;
	} 
	complex_number(T reale, T immaginario){		 //costruttore user-defined
		a = reale;
		b = immaginario;
	}   
	
	
	complex_number coniugato() const {
		return complex_number(a, -b);
	}
	
	T parte_reale() const {
		return a;
		}
		
	T parte_immaginaria() const {
		return b;
		}
		
	complex_number operator+(const complex_number& altro) const {		//overload dell'operatore +
		return complex_number(a+altro.parte_reale() , b+altro.parte_immaginaria());
	}
	
	complex_number& operator+=(const complex_number& altro) {		//overload dell'operatore += 
		a+=altro.parte_reale();
		b+=altro.parte_immaginaria();
		return *this;
	}	
	
	complex_number operator*(const complex_number& altro) {		//overload dell'operatore *
		return complex_number(a*altro.parte_reale(),b*altro.parte_immaginaria());
	}
	
	complex_number& operator*=(const complex_number& altro) {		//overload dell'operatore *=
		a*=altro.parte_reale();
		b*=altro.parte_immaginaria();
		return *this;
	}
};

template<typename I>		//overload dell'operatore <<
std::ostream&
operator<<(std::ostream& x, const complex_number<I>& r) {
    x<<r.parte_reale()<<" + i"<<r.parte_immaginaria();
    return x;
};

#endif	
