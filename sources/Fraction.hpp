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
            Fraction(float a);
            Fraction get_fraction();
            int get_n();
            int get_d();
            void set_n(int a);
            void set_d(int b);
            Fraction operator+(Fraction& f) ;
            float operator+(float d);
            Fraction operator-(Fraction& f) ;
            float operator-(float d);
            Fraction operator*(Fraction& f) ;
            float operator*(float f);
            friend Fraction operator*(float d, const Fraction& f);
            Fraction operator/(Fraction& f) ;
            bool operator==(const Fraction& f) ;
            bool operator==(float f) const ;
            bool operator>(Fraction& f) ;
            bool operator>(float d);
            bool operator>=(Fraction& f) ;
            bool operator<(Fraction& f) ;
            bool operator<=(Fraction& f) ;
            Fraction& operator++();   // prefix increment operator
            Fraction& operator--();   // prefix decrement operator
            Fraction operator++(int); // postfix increment operator
            Fraction operator--(int); // postfix decrement operator 
            friend std::ostream& operator<<(std::ostream& os, const Fraction& f); // output stream operator
            friend std::istream& operator>>(std::istream& is, Fraction& f); // input stream operator
            void reduce();
            int gcd(int a, int b);
            float to_float() const;
            float short_the_float(float f);
        };

    };


#endif