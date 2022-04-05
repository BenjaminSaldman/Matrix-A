/**
 * @file Matrix.cpp
 * @author Benjamin Saldman
 * @brief 
 * @version 0.1
 * @date 2022-04-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdexcept>
#include <cmath>
#include "Matrix.hpp"
const int ZERO=0; // default value to the char's.
const char c2=','; // c2 represent's the char ','.
const int down=10; // ascii value of enter (used in the overload of the operator >>).
/**
 * @brief convert a 1d array to 2d array (used in the overload of the operator *).
 * 
 * @param mat 
 * @param mat2 
 * @param row 
 * @param col 
 */
void convert(vector<vector<double>>&mat,const vector<double>&mat2,int row, int col)
{
        int temp=0;
        unsigned index=0;
        for(unsigned i=0;i<row;i++)
        {
            for(unsigned j=0;j<col;j++)
            {
                mat[i][j]=mat2[index++];
            }
        }

}
namespace zich{
    /**
     * @brief Construct a new Matrix:: Matrix object
     * 
     * @param row 
     * @param col 
     */
    Matrix::Matrix(const vector<double> &vec,int row ,int col)
    {
        if(row<=ZERO || col <=ZERO || vec.size()!=row*col)
        {
            throw invalid_argument{"Invalid input!"}; // check the validity of the values.
        }
        this->row=row;
        this->col=col;
        this->mat.assign((unsigned)(row*col),ZERO);
        for(unsigned i=0;i<vec.size();i++) // (deep) copy the vector to the matrix vector.
        {
            mat.at(i)=vec.at(i);
        }
    }
    /**
     * @brief Construct a new Matrix:: Matrix object 
     * copy constructor.
     * @param other 
     */
    Matrix::Matrix(const Matrix& other):Matrix(other.mat,other.row,other.col){}
    /**
     * @brief overload operator +.
     * 
     * @param other 
     * @return Matrix 
     */
    Matrix Matrix::operator+(const Matrix& other){
        if(other.col!=col || other.row!=row)
        {
            throw invalid_argument{"Can't add this matrix!"}; // + is undefined if the sizes aren't equal.
        }
        Matrix ans(mat,row,col); // matrix that represent the sum of A+B.
        for(unsigned i=0;i<other.mat.size();i++)
        {
            ans.mat.at(i)+=other.mat.at(i);
        }
        return ans; 
    }
    /**
     * @brief overload operator + (unary +).
     * 
     * @return Matrix 
     */
    Matrix Matrix::operator+(){
        // return a duplicate of the matrix.
        return Matrix(this->mat,this->row,this->col);
    }
    /**
     * @brief overload operator +=.
     * 
     * @param other 
     * @return Matrix& 
     */
    Matrix& Matrix::operator+=(const Matrix& other)
    {
        if(other.col!=col || other.row!=row)
        {
            throw invalid_argument{"Can't add this matrix!"}; // + is undefined if the sizes aren't equal.
        }
        for(unsigned i=0;i<other.mat.size();i++)
        {
            mat.at(i)+=other.mat.at(i); // add the other matrix to the current matrix.
        }
        return *this;
    }
    /**
     * @brief overload operator -.
     * 
     * @return Matrix 
     */
    Matrix Matrix::operator-(const Matrix& other){
        if(other.col!=col || other.row!=row)
        {
            throw invalid_argument{"Can't sub this matrix!"}; // sub is undefined if the sizes aren't equal.
        }
        Matrix ans(mat,row,col);
        for(unsigned i=0;i<other.mat.size();i++)
        {
            ans.mat.at(i)-=other.mat.at(i);
        }
        return ans;
    }
    /**
     * @brief overload operator - (unary -).
     * 
     * @return Matrix 
     */
    Matrix Matrix::operator-(){
        Matrix ans(this->mat,this->row,this->col);
        // return new matrix with negative values.
        for(unsigned i=0;i<ans.mat.size();i++)
        {
            ans.mat.at(i)*=-1;
        }
        return ans;
    }
    /**
     * @brief overload operator -=.
     * 
     * @param other 
     * @return Matrix& 
     */
    Matrix& Matrix::operator-=(const Matrix& other)
    {
        if(other.col!=col || other.row!=row) // if the dimansion are'nt equal we can't sub two matrix.
        {
            throw invalid_argument{"Can't sub this matrix!"};
        }
        for(unsigned i=0;i<other.mat.size();i++)
        {
            mat.at(i)-=other.mat.at(i); // sub the other matrix from the current matrix.
        }
        return *this;
    }
    /**
     * @brief overload operator >.
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool Matrix::operator>(const Matrix& other)
    {
        
        if(other.col!=col || other.row!=row) // check validity of sizes.
        {
            throw invalid_argument{"Invalid input"};
        }
        double sumA=0; // sum of current matrix.
        double sumB=0; // sum of other matrix.
        for(unsigned i=0;i<this->mat.size();i++)
        {
            sumA+=this->mat.at(i);
        }
        for(unsigned i=0;i<other.mat.size();i++)
        {
            sumB+=other.mat.at(i);
        }
        // mat a > mat b if sumA>sumB.
        return sumA>sumB;
    }
    /**
     * @brief overload operator <.
     * 
     * @param other 
     * @return true 
     * @return false 
     */
     bool Matrix::operator<(const Matrix& other)
    {
        if(other.col!=col || other.row!=row) // check validity of sizes.
        {
            throw invalid_argument{"Invalid input"};
        }
        double sumA=0; // sum of current matrix.
        double sumB=0; // sum of other matrix.

        for(unsigned i=0;i<this->mat.size();i++)
        {
            sumA+=this->mat.at(i);
        }
        for(unsigned i=0;i<other.mat.size();i++)
        {
            sumB+=other.mat.at(i);
        }
        // mat a < mat b if sumA<sumB.
        return sumA<sumB;
    }
    /**
     * @brief overload operator >=.
     * 
     * @param other 
     * @return true 
     * @return false 
     */
     bool Matrix::operator>=(const Matrix& other)
    {
         if(other.col!=col || other.row!=row) // check validity of sizes.
        {
            throw invalid_argument{"Invalid input"};
        }
      
        return (*this>other) || (*this == other);
    }
    /**
     * @brief overload operator <=.
     * 
     * @param other 
     * @return true 
     * @return false 
     */
     bool Matrix::operator<=(const Matrix& other)
    {
         if(other.col!=col || other.row!=row) // check validity of sizes.
        {
            throw invalid_argument{"Invalid input"};
        }
        
        return (*this<other) || (*this == other);
    }
    /**
     * @brief overload operator ==.
     * 
     * @param other 
     * @return true 
     * @return false 
     */
     bool Matrix::operator==(const Matrix& other)
    {
        
        bool ans=true;
        if(other.col!=col || other.row!=row) // check validity of sizes.
        {
            throw invalid_argument{"Invalid input"};
        }
        
        for(unsigned i=0;i<this->mat.size();i++)
        {
            if(mat.at(i)!=other.mat.at(i)) // check if the two matrix are the same.
            {
                ans=false;
                break;
            }
        }
        
        return ans;
    }
    /**
     * @brief overload operator !=.
     * 
     * @param other 
     * @return true 
     * @return false 
     */
    bool Matrix::operator!=(const Matrix& other)
    {
         if(other.col!=col || other.row!=row) // check validity of sizes.
        {
            throw invalid_argument{"Invalid input"};
        }

        return !(*this==other);
    }
     /**
     * @brief overload operator -- (given a matrix a, then we overload ++a).
     * 
     * @return Matrix 
     */
    Matrix& Matrix::operator++(){
        for(unsigned i=0;i<mat.size();i++)
        {
            mat.at(i)++;
        }
        return *this;
    }
    /**
     * @brief overload operator -- (given a matrix a, then we overload a++).
     * 
     * @return Matrix 
     */
    Matrix Matrix::operator++(int)
    {
        Matrix matrix(mat,row,col); // temp matrix, the current matrix changing after the call of ++.
        for(unsigned i=0;i<mat.size();i++)
        {
            mat.at(i)++; 
        }
        return matrix;
    }
    /**
     * @brief overload operator -- (given a matrix a, then we overload --a).
     * 
     * @return Matrix& 
     */
    Matrix& Matrix::operator--(){
        for(unsigned i=0;i<mat.size();i++)
        {
            mat.at(i)--;
        }
        return *this;
    }
    /**
     * @brief overload operator -- (given a matrix a, then we overload a--).
     * 
     * @return Matrix 
     */
    Matrix Matrix::operator--(int)
    {
        Matrix matrix(mat,row,col); // temp matrix, the current matrix changing after the call of --.
        for(unsigned i=0;i<mat.size();i++)
        {
            mat.at(i)--;
        }
        return matrix;
    }
    /**
     * @brief overload operator * (between two matrix).
     * 
     * @param other 
     * @return Matrix 
     */
    Matrix Matrix::operator*(const Matrix& other)
    {
        if(col!=other.row) // multipication defined when the number of the columns equal to the number of rows.
        {
            throw invalid_argument{"multipication is undifiend"};
        }
       vector<vector<double>>origin((unsigned)row,vector<double>((unsigned)col)); // 2d matrix of the current matrix.
       vector<vector<double>>mult((unsigned)other.row,vector<double>((unsigned)other.col)); // 2d matrix of the other matrix.
       vector<vector<double>>ans((unsigned)row,vector<double>((unsigned)other.col)); // multipication matrix.
       convert(origin,mat,row,col); // convert the 1d mat to 2d mat.
       convert(mult,other.mat,other.row,other.col); // convert the 1d mat to 2d mat.
       //multipication between the matrix.
        for(unsigned i=0;i<row;i++)
        {
            for(unsigned j=0;j<other.col;j++)
            {
                for(unsigned k=0;k<col;k++)
                {
                    ans[i][j]+=origin[i][k]*mult[k][j];
                }
            }
        }
        vector<double>ans2((unsigned)(other.col*row)); // 1d matrix (that equals to ans in the size).
        unsigned index=0; // current index.
        // convert the 2d matrix to 1d matrix.
        for(unsigned i=0;i<ans.size();i++)
        {
            for(unsigned j=0;j<ans[i].size();j++)
            {
                ans2[index++]=ans[i][j];
            }
        }
    
        return  Matrix(ans2,row,other.col);
    }
    /**
     * @brief overload operator *= (number and current matrix).
     * 
     * @param num 
     * @return Matrix& 
     */
    Matrix& Matrix::operator*=(double num)
    {
        for(unsigned i=0;i<mat.size();i++)
        {
            mat.at(i)*=num; // assign the multipication on the current matrix.
        }
        return *this;
    }
    /**
     * @brief overload operator * (number and matrix).
     * 
     * @param num 
     * @param mat 
     * @return Matrix 
     */
    Matrix operator*(double num,Matrix& mat)
    {
        Matrix m(mat.mat,mat.row,mat.col); // creating a new matrix.
        for(unsigned i=0;i<m.mat.size();i++)
        {
            m.mat.at(i)*=num; // multiply each value by the given number.
        }
        return m;
    }
    /**
     * @brief overload the operator <<.
     * 
     * @param output 
     * @param mat 
     * @return std::ostream& 
     */
    std::ostream& operator<<(ostream& output,const Matrix& mat)
    {
        int temp=0; // check that there is no space between last number to ']'
        unsigned index=0; // current mat index.
        string ans; // answer string to print.
        for(unsigned i=0;i<mat.row;i++)
        {
            ans+='['; // adding '['.
            while((temp)-mat.col<0 && index<mat.mat.size())
            {
                // add the numbers to the string.
                ans+=to_string((mat.mat.at(index++)));
                temp++;
                if((temp)-mat.col<0){
                    ans+=' ';
                }
            }
            temp=0;
            ans+=']'; //adding ']'.
            ans+='\n'; 
        }
        return(output<<ans);
    }
   
  /**
   * @brief overload operator >>.
   * 
   * @param input 
   * @param mat 
   * @return std::istream& 
   */
    std::istream& operator>>(istream& input,Matrix& mat)
    {
        vector<double>vec; // Matrix mat.
        char curr=ZERO; // Current character to read.
        int rows=0; // Number of rows in the mat.
        double num=0; // Current number to read.
        while(input.peek()!=down) // while we don't pressed enter.
        {
        
         input>>curr; // read the char '['.
        // while the next char is not ']' or enter read numbers and
        // push them to the mat.
         while(input.peek()!=']'&& input.peek()!=down) 
         {
             input>>num;
             vec.push_back(num);
         }
         rows++; // previously we read a row.
         input>>curr; // read the char ']'.
         // check if we can read the ',' char, if not 
         // we read the whole matrix.
         if(input.peek()==down){
            break;
         }
         input>>curr; //read ','.
    
        }
       if (rows==0)
       {
           throw invalid_argument{"could'nt read the matrix"};
       }
        mat.mat=vec; //assign the new mat to the matrix.
        mat.row=rows; // assign the rows to the matrix.
        
        mat.col=(int)(vec.size()/(unsigned)rows); // calculate the cols and assign it to the matrix.
           

        
        
        return input;
    }





};