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
    CHECK(f.get_fraction().get_d() == 0);
    CHECK(f.get_fraction().get_d() == 0);
    CHECK_THROWS(Fraction(1,0));
}
TEST_CASE("Test 2 - operator +")
{
    Fraction a(1,2), b(1,4);
    Fraction t(3,4);
    CHECK(a + b == t);
    float c = 0.51;
    float z = 1.01;
    CHECK((a+c) == z);
}
TEST_CASE("Test 3 - operator -")
{
    Fraction a(1,2), b(1,4);
    Fraction t(1,4);
    CHECK(a - b == t);
    float c = 0.49;
    float z = 0.01;
    CHECK((a-c) == z);
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