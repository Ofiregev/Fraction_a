#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include "sources/Fraction.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - Initialization")
{
    Fraction f(1, 2);
    CHECK(f.get_fraction().get_n() == 1);
    CHECK(f.get_fraction().get_d() == 2);

    f.set_n(0);
    CHECK(f.get_fraction().get_n() == 0);
    CHECK(f.get_fraction().get_d() == 1);

    // check reducing while creatinf new fraction
    Fraction w(14, 21);
    CHECK(w.get_fraction().get_n() == 2);
    CHECK(w.get_fraction().get_d() == 3);

    // check reducing while copy fraction
    Fraction & q = w;
    Fraction s = q;
    CHECK(s.get_fraction().get_n() == 2);
    CHECK(s.get_fraction().get_d() == 3);

    //check exception of dividing by 0
    for (int i = 0; i < 10; i++)
    {
        CHECK_THROWS(Fraction(i, 0));
    }

    // check float constructor
    float d = 0.5;
    Fraction t(1, 2);
    CHECK(Fraction(d) == t); 
}
TEST_CASE("Test 2 - operator +")
{
    Fraction a(1, 2), b(1, 4), q(1, -4), d(0, 1), t(3, 4), j(1 / 1);
    float c = 0.5;
    CHECK(a + b == t);   // fraction and fraction
    CHECK((a + c) == j); // fraction and float
    CHECK((b + q) == d); // float and fraction
}
TEST_CASE("Test 3 - operator -")
{
    Fraction a(1, 2), b(1, 4), x(1, -4), t(1, 4), n(0, 1), s(1,100);
    CHECK(a - b == t); // fraction and fraction
    float c = 0.49;
    float g = 0.5;
    CHECK(b - a == x); // negative result
    CHECK(b - x == a); //positive and negative
    CHECK(b - t == n); // result zero
    CHECK(a - c == s); // fraction and flaut
    CHECK(g - b == b); // flaut and fraction
    
}
TEST_CASE("Test 4 - operator *")
{
    Fraction a(1, 2), b(1, 4),t(1, 8);
    float c = 0.5;
    CHECK(a * b == t);
    CHECK(a * c == b);
    CHECK(c * a == b);
}
TEST_CASE("Test 5 - operator /")
{
    Fraction a(1, 2), b(1, 4), t(2, 1), j(1, 1);
    float d = 0.5;

    CHECK(a / b == t); // fraction and fraction
    CHECK(b / a == a);
    CHECK(a / d == j); // fraction and flaut
    CHECK(d / a == j); // flaut and fraction

    Fraction x(0, 2);
    CHECK_THROWS(a / x); // divide in zero
}
TEST_CASE("Test 6 - operator ==")
{
    Fraction a(1, 2), b(2, 4);
    float c = 0.5;
    CHECK(a == b); // fraction and fraction
    CHECK(a == c); // fraction and float
    CHECK(c == a); // float and fraction
}
TEST_CASE("Test 7 - operator > , >=")
{
    Fraction a(1, 2), b(1, 3);
    float c = 0.3;
    float f = 0.6;
    float t = 0.5;

    CHECK_FALSE(b > a); // fraction and fraction
    CHECK(a > c);// fraction and float
    CHECK(f > a); // float and fraction

    CHECK(a >= c);
    CHECK(a >= t);
    CHECK(t >= a);
}
TEST_CASE("Test 8 - operator < , <=")
{
    Fraction a(1, 2), b(1, 3), f(1, 8);
    float c = 0.3, t = 0.5;

    CHECK_FALSE(a < b); //  fraction and fraction
    CHECK_FALSE(a < c); // fraction and float
    CHECK_FALSE(a < t);
    CHECK(f <= c);
    CHECK(a <= t);
    CHECK(t <= a);

}
TEST_CASE("Test 9 - operator ++a, --a")
{
    Fraction a(1, 2), b(3, 2), f(1, -2);

    Fraction &d = ++a; //pre-increments the value of 'a' by 1, and assigns the result to a reference variable d
    CHECK(a == d);
    CHECK(d == b);
    Fraction z(1, 2);
    Fraction &s = --z; //re-decrements the value of 'z' by 1, and assigns the result to a reference variable s
    CHECK(z == s);
    Fraction v(s.get_n(), s.get_d());
    CHECK(v == f);
}
TEST_CASE("Test 10  operator a++, a--")
{
    Fraction a(1, 2), b(3, 2), f(1, 2);
    Fraction d = a++; //post-increments the value of a by 1, and assigns the original value to a new Fraction object d
    CHECK(d == f); // check if d equal to a before incrementing
    CHECK(a == b);
    Fraction v = b--;
    Fraction z(3, 2);
    CHECK(v == z);
    CHECK(b == f);
}
TEST_CASE("Test 11  operator << , >> ")
{
    Fraction f1(3, 5);
    std::stringstream out_stream;
    out_stream << f1;
    CHECK(out_stream.str() == "3/5");
    Fraction f2;
    std::stringstream in_stream("1/7");
    in_stream >> f2;
    CHECK(f2.get_n() == 1);
    CHECK(f2.get_d() == 7);
}
