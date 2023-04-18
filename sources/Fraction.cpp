#include <iostream>
#include <stdio.h>
#include <numeric>
#include <iomanip> 
#include <math.h>
#include "Fraction.hpp"
namespace ariel
{
    Fraction::Fraction(){}
    Fraction::Fraction(int a, int b)
    {
        if (b == 0)
        {
            throw std::runtime_error("Invalid fraction: denominator cannot be zero.");
        }
        else if (a == 0)
        {
            this->n = 0;
            this->d = 1;
        }
        else
        {
            this->n = a;
            this->d = b;
            this->reduce();
        }
    }
    Fraction::Fraction(float f){
        
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
    this->short_the_float(f);
    float res = this->short_the_float(d + f);
    return res;
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
Fraction Fraction::operator-(int p)
{
    int a = this->d;
    Fraction w(p*a,p*a);
    Fraction res = (*this) - w;
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
    if(f.n == 0)
    {
        throw std::runtime_error("Invalid fraction: denominator cannot be zero.");
    }
    int new_n = this->n * f.d;
    int new_d = this->d* f.n;
    Fraction res(new_n, new_d);
    res.reduce();
    return res;
}
bool Fraction::operator==(const Fraction &f)
{
  
    this->reduce();
    Fraction temp = f;
    temp.reduce();
    return (this->n == temp.n) && (this->d == temp.d);
}
bool Fraction::operator==(float f){
    float a = this->to_float();
    return a == f;
}
bool Fraction::operator>(Fraction &f)
{
    int n_a = this->n *f.d;
    int n_b = f.n * this->d;

        // Compare the numerators of the two fractions
    return n_a > n_b;
}
bool Fraction::operator>(float d)
{
    float temp = this->to_float();
    return temp > d;
}
bool Fraction::operator>=(Fraction &f)
{
    int n_a = this->n *f.d;
    int n_b = f.n * this->d;

        // Compare the numerators of the two fractions
    return n_a >= n_b;
}
bool Fraction::operator>=(float d)
{
    float temp = this->to_float();
    return temp >= d;
}
bool Fraction::operator<(Fraction &f)
{
    int n_a = this->n *f.d;
    int n_b = f.n * this->d;

        // Compare the numerators of the two fractions
    return n_a < n_b;
}
bool Fraction::operator<(float d)
{
    float temp = this->to_float();
    return temp < d;
}
bool Fraction::operator<=(Fraction &f)
{
    int n_a = this->n *f.d;
    int n_b = f.n * this->d;

        // Compare the numerators of the two fractions
    return n_a <= n_b;
}
bool Fraction::operator<=(float d)
{
    float temp = this->to_float();
    return temp <= d;
}
Fraction &Fraction::operator++()
{
    this->n = this->n + this->d;
    this->reduce();
    return *this;
}
Fraction &Fraction::operator--()
{
    this->n = this->n - this->d;
    this->reduce();
    return *this;
}
Fraction Fraction::operator++(int)
{
    Fraction old_fraction = *this;
    ++(*this);
    return old_fraction;
}
Fraction Fraction::operator--(int)
{
    Fraction old_fraction = *this;
    --(*this);
    return old_fraction;
}
std::ostream &operator<<(std::ostream &stream, const Fraction &f)
{
    
    stream << f.to_string();
    return stream;
}
// std::ostream& operator<<(std::ostream& stream, const float& f) {
//     stream << std::fixed << std::setprecision(3) << f;
//     return stream;
// }


std::istream &operator>>(std::istream &stream, Fraction &f)
{
    char s;
    stream >> f.n >> s >> f.d;
    f.reduce();
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
    float rounded_down = floorf(f * 1000) / 1000;  
    return rounded_down;
}
string Fraction::to_string() const
{
    return std::to_string(this->n) +'/'+std::to_string(this->d);
}

}