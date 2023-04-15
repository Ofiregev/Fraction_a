#include <iostream>
#include <stdio.h>
#include <numeric>
#include <iomanip> 
#include <cmath>
#include "Fraction.hpp"
namespace ariel
{
    Fraction::Fraction(int a, int b)
    {
        if (b == 0)
        {
            throw std::runtime_error("Invalid fraction: denominator cannot be zero.");
        }
        else if (a == 0)
        {
            this->n = 0;
            this->d = 0;
        }
        else
        {
            this->n = a;
            this->d = b;
        }
    }
    void Fraction::set_n(int a)
    {
        this->n = a;
    }
    void Fraction::set_d(int b)
    {
        this->d = b;
    }


Fraction Fraction::get_fraction()
{
    return Fraction(this->get_n(), this->get_d());
}
int Fraction::get_n()
{
    return this->n;
}
int Fraction::get_d()
{
    return this->d;
}
Fraction::Fraction(float d) {}

Fraction Fraction::operator+(Fraction &f)
{
    // Calculate the sum of the two fractions
    int sum_of_n = (this->n * f.d) + (this->d * f.n);
    int sum_of_d = this->d * f.d;
    Fraction new_fraction = Fraction(sum_of_n, sum_of_d);
    new_fraction.reduce();
    
    // Create and return a new fraction object representing the sum
    return new_fraction;
}

float Fraction::operator+(float d)
{
    float f = this->to_float();
    return d+f;
}
Fraction Fraction::operator-(Fraction &f)
{
      // Calculate the new numerator and denominator
    int n = (this->n * f.d) - (f.n * this->d);
    int d = this->d * f.d;
    Fraction new_fraction = Fraction(n, d);
    new_fraction.reduce();
    return new_fraction;
}

float Fraction::operator-(float d)
{
    float f = this->to_float();
    f = this->short_the_float(f);
    d = this->short_the_float(d);
    float res = short_the_float(f-d);
    return res;
}


Fraction Fraction::operator*(Fraction &f)
{
    int n = this->n * f.n;
    int d = this->d * f.d;
    Fraction new_fraction = Fraction(n, d);
    new_fraction.reduce();
    return new_fraction;
}

float Fraction::operator*(float d)
{
    float f = this->to_float();
    f = this->short_the_float(f);
    d = this->short_the_float(d);
    float res = short_the_float(f*d);
    return res;
}

Fraction operator*(float d, const Fraction &f)
{
    return f;
}
Fraction Fraction::operator/(Fraction &f)
{
    return f;
}
bool Fraction::operator==(const Fraction &f)
{
    return (this->n == f.n) && (this->d == f.d);
}
bool Fraction::operator==(float f) const {
    float a = this->to_float();
    return a == f;
}
bool Fraction::operator>(Fraction &f)
{
    return true;
}
bool Fraction::operator>(float d)
{
    return true;
}
bool Fraction::operator>=(Fraction &f)
{
    return true;
}
bool Fraction::operator<(Fraction &f)
{
    return true;
}
bool Fraction::operator<=(Fraction &f)
{
    return true;
}
Fraction &Fraction::operator++()
{
    n += d;
    return *this;
}
Fraction &Fraction::operator--()
{
    n += d;
    return *this;
}
Fraction Fraction::operator++(int)
{
    Fraction f = Fraction(1, 1);
    return f;
}
Fraction Fraction::operator--(int)
{
    Fraction f = Fraction(1, 1);
    return f;
}
std::ostream &operator<<(std::ostream &stream, const Fraction &f)
{
    stream << f.n << "/" << f.d;
    return stream;
}
std::istream &operator>>(std::istream &stream, Fraction &f)
{
    int t;
    stream >> t;
    return stream;
}
void Fraction::reduce()
{
    // Find the greatest common divisor of the numerator and denominator
    int gcd = this->gcd(this->n, this->d);

    // Divide the numerator and denominator by the gcd to reduce the fraction
    this->n = this->n / gcd;
    this->d = this->d / gcd;
}
int Fraction::gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
float Fraction::to_float() const {
    return static_cast<float>(n) / static_cast<float>(d);
}
float Fraction::short_the_float(float f)
{
    return std::round(f * 1000.0) / 1000.0;
}
}