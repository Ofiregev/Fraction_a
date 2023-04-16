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
    Fraction f(1,2);

    CHECK(f.get_fraction().get_n() == 1);
    CHECK(f.get_fraction().get_d() == 2);
    f.set_n(0);
    CHECK(f.get_fraction().get_n() == 0);
    CHECK(f.get_fraction().get_d() == 1);
    CHECK_THROWS(Fraction(1,0));
}
TEST_CASE("Test 2 - operator +")
{
    Fraction a(1,2), b(1,4), q(1,-4), d(0,1);
    Fraction t(3,4);
    CHECK(a + b == t);
    float c = 0.51;
    float z = 1.01;
    CHECK((a+c) == z);
    CHECK((b+q) == d);

}
TEST_CASE("Test 3 - operator -")
{
    Fraction a(1,2), b(1,4), x(1,-4),t(1,4),n(0,1);
    CHECK(a - b == t);
    float c = 0.49;
    float z = 0.01;
    CHECK((a-c) == z);
    CHECK(b-a == x);
    CHECK(b-x == a);
    CHECK(b-t == n);
}
TEST_CASE("Test 4 - operator *")
{
    Fraction a(1,2), b(1,4);
    Fraction t(1,8);
    CHECK(a * b == t);
    float c = 0.5;
    float z = 0.25;
    CHECK((a*c) == z);
}
TEST_CASE("Test 5 - operator /")
{
    Fraction a(1,2), b(1,4);
    Fraction t(2,1);
    CHECK(a / b == t);
    Fraction x(0,2);
    CHECK_THROWS(a / x);
}
TEST_CASE("Test 5 - operator ==")
{
    Fraction a(1,2), b(2,4);
    CHECK(a == b );
    float c = 0.5;
    CHECK(a == c);
}
TEST_CASE("Test 6 - operator > , >=")
{
    Fraction a(1,2), b(1,3);
    CHECK_FALSE(b > a );
    float c = 0.3;
    CHECK(a > c);
    CHECK(a >= c);
    float t = 0.5;
    CHECK(a >= t);
    CHECK_FALSE(a > t);
}
TEST_CASE("Test 7 - operator < , <=")
{
    Fraction a(1,2), b(1,3), f(1,8);
    CHECK_FALSE(a < b );
    float c = 0.3;
    CHECK_FALSE(a < c);
    CHECK(f <= c);
    float t = 0.5;
    CHECK(a <= t);
    CHECK_FALSE(a < t);
}
TEST_CASE("Test 8 - operator ++a, --a")
{
    Fraction a(1,2), b(3,2), f(1,-2);
    Fraction& d= ++a;
    CHECK(a == d);
    CHECK(d == b);
    Fraction z(1,2);
    Fraction& s = --z;
    CHECK(z == s);
    Fraction v(s.get_n(),s.get_d());
    CHECK(v == f);
    
}
TEST_CASE("Test 9  operator a++, a--")
{
    Fraction a(1,2), b(3,2), f(1,2);
    Fraction d= a++;
    CHECK(d == f);
    CHECK(a == b);
    Fraction v= b--;
    Fraction z(3,2);
    CHECK(v == z);
    CHECK(b == f);
}
TEST_CASE("Test 10  operator << , >> ")
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