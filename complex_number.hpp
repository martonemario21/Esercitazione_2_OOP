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
	
	complex_number operator*(const complex_number& altro) const {		//overload dell'operatore *
		return complex_number(a*altro.parte_reale() - b*altro.parte_immaginaria() , a*altro.parte_immaginaria()+b*altro.parte_reale());		//(a + ib)(c + id) = (ac - bd) + i(ad + bc)
	}
	
	complex_number& operator*=(const complex_number& altro) {		//overload dell'operatore *=
		T a_momentanea = a*altro.parte_reale()-b*altro.parte_immaginaria();
		T b_momentanea = a*altro.parte_immaginaria()+b*altro.parte_reale();
		a = a_momentanea;
		b = b_momentanea;
		return *this;
	}
	
	complex_number operator+(const T& altro) const {		//overload dell'operatore + tra complex e T
		return complex_number(a+altro, b);
	}
	
	complex_number operator*(const T& altro) const {		//overload dell'operatore * tra complex e T

		return complex_number(a*altro, b*altro);
	}
	
};



template<typename I>

complex_number<I> operator+(const I& reale, const complex_number<I>& comp) {		//overload dell'operatore + tra T e complex
		return complex_number(reale+comp.parte_reale(), comp.parte_immaginaria());
}


template<typename I>

complex_number<I> operator*(const I& reale, const complex_number<I>& comp) {		//overload dell'operatore * tra T e complex
		return complex_number(reale*comp.parte_reale(), reale*comp.parte_immaginaria());
}




template<typename I>		//overload dell'operatore <<

std::ostream &operator<<(std::ostream& x, const complex_number<I>& r) {
	
	if (r.parte_immaginaria() > 0){
    x<<r.parte_reale()<<"+"<<r.parte_immaginaria()<<"i";
    }else if (r.parte_immaginaria() == 0){
	x<<r.parte_reale();
    }else{ 
    x<<r.parte_reale()<<r.parte_immaginaria()<<"i";
    }
    return x;
};




#endif	
