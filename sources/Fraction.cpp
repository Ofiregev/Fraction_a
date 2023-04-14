#include <iostream>
#include <stdio.h>
#include "Fraction.hpp"
namespace ariel
{
            Fraction::Fraction(int a, int b) {
            this->n = a;
            this->d = b;
        }
        int Fraction::get_n()
        {
            return this->n;
        }
        int Fraction::get_d()
        {
            return this->d;
        }
        Fraction::Fraction(double d){}

        Fraction Fraction::operator+(Fraction& f) 
        {
            return f;
        }
        Fraction Fraction::operator+(double d)
        {
            return Fraction(d);
        }
        Fraction Fraction::operator-(Fraction& f) 
        {
            return f;
        }
        Fraction Fraction::operator-(double d)
        {
            return Fraction(d);
        }
        
        Fraction Fraction::operator*(Fraction& f) 
        {
            return f;
        }
        Fraction operator*(double d, const Fraction& f)
        {
            return f;
        }
        Fraction Fraction::operator/(Fraction& f) 
        {
            return f;
        }
        bool Fraction::operator==(Fraction& f) 
        {
            return true;
        }
        bool Fraction::operator>(Fraction& f) 
        {
            return true;
        }
        bool Fraction::operator>(double d)
        {
            return true;
        }
        bool Fraction::operator>=(Fraction& f) 
        {
            return true;
        }
        bool Fraction::operator<(Fraction& f) 
        {
            return true;
        }
        bool Fraction::operator<=(Fraction& f) 
        {
            return true;
        }
        Fraction& Fraction::operator++()
        {
             n += d;
            return *this;
        }
        Fraction& Fraction::operator--()
        {
             n += d;
            return *this;
        }
        Fraction Fraction::operator++(int)
        {
            Fraction f = Fraction(1,1);
            return f;
        }
        Fraction Fraction::operator--(int)
        {
            Fraction f = Fraction(1,1);
            return f;
        }
        std::ostream& operator<<(std::ostream& stream, const Fraction& f) {
        stream << f.n << "/" << f.d;
        return stream;
    }
        std::istream& operator>>(std::istream& stream, Fraction& f)
        {
            int t;
            stream >> t;
            return stream;
        }

}