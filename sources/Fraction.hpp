#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <string>
using namespace std;

namespace ariel
{
    
    class Fraction
    {
        private:
        int n;
        int d;
        public:
            Fraction(int a, int b);
            Fraction(double a);
            int get_n();
            int get_d();
            void set_n(int a);
            void set_d(int b);
            Fraction operator+(Fraction& f) ;
            Fraction operator+(double d);
            Fraction operator-(Fraction& f) ;
            Fraction operator-(double d);
            Fraction operator*(Fraction& f) ;
            friend Fraction operator*(double d, const Fraction& f);
            Fraction operator/(Fraction& f) ;
            bool operator==(Fraction& f) ;
            bool operator>(Fraction& f) ;
            bool operator>(double d);
            bool operator>=(Fraction& f) ;
            bool operator<(Fraction& f) ;
            bool operator<=(Fraction& f) ;
            Fraction& operator++();   // prefix increment operator
            Fraction& operator--();   // prefix decrement operator
            Fraction operator++(int); // postfix increment operator
            Fraction operator--(int); // postfix decrement operator 
            friend std::ostream& operator<<(std::ostream& os, const Fraction& f); // output stream operator
            friend std::istream& operator>>(std::istream& is, Fraction& f); // input stream operator
        };

    };


#endif