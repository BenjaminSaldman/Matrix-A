/**
 * @file Matrix.hpp
 * @author Benjamin Saldman
 * @brief 
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

using namespace std;

namespace zich{
    class Matrix
    {
        int row;
        int col;
        vector<double>mat;
        public:
            Matrix(vector<double>vec,int row ,int col);
            Matrix(const Matrix& other);
            Matrix operator+(const Matrix& other);
            Matrix operator+();
            Matrix& operator+=(const Matrix& other);
            Matrix operator-(const Matrix& other);
            Matrix operator-();
            Matrix& operator-=(const Matrix& other);

            bool operator>(const Matrix& other);
            bool operator>=(const Matrix& other);
            bool operator<(const Matrix& other);
            bool operator<=(const Matrix& other);
            bool operator!=(const Matrix& other);
            bool operator==(const Matrix& other);

            Matrix& operator++();
            Matrix operator++(int);
            Matrix& operator--();
            Matrix operator--(int);

            Matrix operator*(const Matrix& other);
            Matrix& operator*=(double num);

            friend std::ostream& operator<<(ostream& output,const Matrix& mat);
            friend std::istream& operator>>(istream& input,Matrix& mat);
            friend Matrix operator*(double num,Matrix& mat);
    };
};