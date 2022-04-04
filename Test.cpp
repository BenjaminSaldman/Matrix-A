/**
 * @file Test.cpp
 * @author Benjamin Saldman
 * @brief 
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include "doctest.h"
#include "Matrix.hpp"
using namespace zich;
using namespace std;

/**
 * @brief check if we don't get a throw on valid input.
 * 
 */
TEST_CASE("Valid Input")
{
    vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    CHECK_NOTHROW(Matrix(arr,3,3)); // valid 3X3 matrix.
    CHECK_NOTHROW(Matrix(arr,9,1)); // valid 9X1 matrix.
    CHECK_NOTHROW(Matrix(arr,1,9)); // valid 1X9 matrix.
    Matrix a(arr,3,3);
    Matrix b(a); 
    CHECK_NOTHROW(+a); // valid + unary on valid matrix.
    CHECK_NOTHROW(-a); // valid - unaray on valid matrix
    CHECK_NOTHROW(a+b);
    CHECK_NOTHROW(a-b);
    CHECK_NOTHROW(3*a);
    CHECK_NOTHROW(a*b); // * is defined because a=b.
    CHECK_NOTHROW(a++);
    CHECK_NOTHROW(a--);
    CHECK_NOTHROW(a+=b);
    CHECK_NOTHROW(a-=b);
    CHECK_EQ(a>b,false);
    CHECK_EQ(a<b,false);
    CHECK_EQ(a==b,true);
    CHECK_EQ(a!=b,false);
}
/**
 * @brief check that we get exception on invalid input.
 * 
 */
TEST_CASE("Invalid input")
{
    vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    for(int i=1;i<100;i++)
    {
        CHECK_THROWS(Matrix(arr,i,i+9)); // Invalid matrix size.
        CHECK_THROWS(Matrix(arr,-i,-(i+9))); // rows, cols can't be negative.
        CHECK_THROWS(Matrix(arr,i,-(i+9)));
        CHECK_THROWS(Matrix(arr,-i,(i+9)));
    }
    CHECK_THROWS(Matrix(arr,-3,-3));
    CHECK_THROWS(Matrix(arr,-9,-1));
    CHECK_THROWS(Matrix(arr,-1,-9));
    Matrix a(arr,3,3);
    Matrix b(arr,9,1);
    CHECK_THROWS(a+b); // + undefiend when size of a != size of b.
    CHECK_THROWS(a-b); // - undefiend when size of a != size of b.
    CHECK_THROWS(a*b); // * undefiend when the columns of a != rows of b.
    CHECK_THROWS(a+=b);
    CHECK_THROWS(a-=b);
}
/**
 * @brief test case that check the validity of the operators.
 * 
 */
TEST_CASE("Testing operators")
{
    vector<double> arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    vector<double> arr2 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix a(arr,3,3);
    Matrix b(arr2,3,3);
    CHECK_EQ(a*b==a,true);
    CHECK_EQ(b*a==a,true);
    arr={0,-1,2,4,11,2};
    arr2={3,-1,1,2,6,1};
    vector<double> arr3 = {11,0,35,20};
    Matrix c(arr,2,3);
    Matrix d(arr2,3,2);
    CHECK_EQ(c*d==Matrix(arr3,2,2),true);
    a++;
    arr = {4, 1, 1, 1, 4, 1, 1, 1, 4};
    CHECK_EQ(a==Matrix(arr,3,3),true);
    arr = {5, 2, 2, 2, 5, 2, 2, 2, 5};
    CHECK_EQ(++a==Matrix(arr,3,3),true);
    CHECK_EQ(a>=a,true);
    CHECK_EQ(a<=a,true);
    CHECK_EQ(a==a,true);
    CHECK_EQ(a!=a,false);
    CHECK_EQ(a<a,false);
    CHECK_EQ(a>a,false);
    CHECK_EQ(c*d>a,true);
    CHECK_EQ(c*d>=a,true);
    CHECK_EQ(c*d!=a,true);
    CHECK_EQ(c*d==a,false);
    arr={10,4,4,4,10,4,4,4,10};
    CHECK_EQ(2*a==Matrix(arr,3,3),true);
    CHECK_EQ(2*a==Matrix(arr,9,1),false);
    CHECK_EQ(2*a==Matrix(arr,1,9),false);
    arr = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix a1(arr,3,3);
    Matrix b1(arr,3,3);
    arr={9,0,0,0,9,0,0,0,9};
    CHECK_EQ(2*a1+b1==Matrix(arr,3,3),true);
    arr={10,1,1,1,10,1,1,1,10};
    CHECK_EQ(++(2*a1)+b1==Matrix(arr,3,3),true);


}