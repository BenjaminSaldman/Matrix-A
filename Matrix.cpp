#include <stdexcept>
#include <cmath>
#include "Matrix.hpp"
const int ZERO=0;

const char c2=',';
const int down=10;
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
    Matrix::Matrix(vector<double>vec,int row ,int col)
    {
        if(row<=ZERO || col <=ZERO || vec.size()!=row*col)
        {
            throw invalid_argument{"Invalid input!"};
        }
        this->row=row;
        this->col=col;
        this->mat.assign((unsigned)(row*col),ZERO);
        for(unsigned i=0;i<vec.size();i++)
        {
            mat.at(i)=vec.at(i);
        }
    }
    Matrix::Matrix(const Matrix& other):Matrix(other.mat,other.row,other.col){}
    Matrix Matrix::operator+(const Matrix& other){
        if(other.col!=col || other.row!=row)
        {
            throw invalid_argument{"Can't add this matrix!"};
        }
        Matrix ans(mat,row,col);
        for(unsigned i=0;i<other.mat.size();i++)
        {
            ans.mat.at(i)+=other.mat.at(i);
        }
        return ans;
    }
    Matrix Matrix::operator+(){
        return Matrix(this->mat,this->row,this->col);
    }
    Matrix& Matrix::operator+=(const Matrix& other)
    {
        if(other.col!=col || other.row!=row)
        {
            throw invalid_argument{"Can't add this matrix!"};
        }
        for(unsigned i=0;i<other.mat.size();i++)
        {
            mat.at(i)+=other.mat.at(i);
        }
        return *this;
    }
    Matrix Matrix::operator-(const Matrix& other){
        if(other.col!=col || other.row!=row)
        {
            throw invalid_argument{"Can't sub this matrix!"};
        }
        Matrix ans(mat,row,col);
        for(unsigned i=0;i<other.mat.size();i++)
        {
            ans.mat.at(i)-=other.mat.at(i);
        }
        return ans;
    }
    Matrix Matrix::operator-(){
        Matrix ans(this->mat,this->row,this->col);
        for(unsigned i=0;i<ans.mat.size();i++)
        {
            ans.mat.at(i)*=-1;
        }
        return ans;
    }
     Matrix& Matrix::operator-=(const Matrix& other)
    {
        if(other.col!=col || other.row!=row)
        {
            throw invalid_argument{"Can't add this matrix!"};
        }
        for(unsigned i=0;i<other.mat.size();i++)
        {
            mat.at(i)-=other.mat.at(i);
        }
        return *this;
    }
    bool Matrix::operator>(const Matrix& other)
    {
        double sumA=0;
        double sumB=0;
        for(unsigned i=0;i<this->mat.size();i++)
        {
            sumA+=this->mat.at(i);
        }
        for(unsigned i=0;i<other.mat.size();i++)
        {
            sumB+=other.mat.at(i);
        }
        return sumA>sumB;
    }
     bool Matrix::operator<(const Matrix& other)
    {
        double sumA=0;
        double sumB=0;
        for(unsigned i=0;i<this->mat.size();i++)
        {
            sumA+=this->mat.at(i);
        }
        for(unsigned i=0;i<other.mat.size();i++)
        {
            sumB+=other.mat.at(i);
        }
        return sumA<sumB;
    }
     bool Matrix::operator>=(const Matrix& other)
    {
        bool ans=true;
        if(other.col !=col || other.row!=row)
        {
            ans=false;
        }
        else{
            for(unsigned i=0;i<this->mat.size();i++)
            {
                if(mat.at(i)!=other.mat.at(i))
                {
                    ans=false;
                    break;
                }
            }
        }
        return (*this>other) || ans;
    }
     bool Matrix::operator<=(const Matrix& other)
    {
        bool ans=true;
        if(other.col !=col || other.row!=row)
        {
            ans=false;
        }
        else{
            for(unsigned i=0;i<this->mat.size();i++)
            {
                if(mat.at(i)!=other.mat.at(i))
                {
                    ans=false;
                    break;
                }
            }
        }
        
        return (*this<other) || ans;
    }
     bool Matrix::operator==(const Matrix& other)
    {
        
        bool ans=true;
        if(other.col !=col || other.row!=row)
        {
            ans=false;
        }
        else{
            for(unsigned i=0;i<this->mat.size();i++)
            {
                if(mat.at(i)!=other.mat.at(i))
                {
                    ans=false;
                    break;
                }
            }
        }
        return ans;
    }
    bool Matrix::operator!=(const Matrix& other)
    {

        return !(*this==other);
    }
    Matrix& Matrix::operator++(){
        for(unsigned i=0;i<mat.size();i++)
        {
            mat.at(i)++;
        }
        return *this;
    }
    Matrix Matrix::operator++(int)
    {
        Matrix matrix(mat,row,col);
        for(unsigned i=0;i<mat.size();i++)
        {
            mat.at(i)++;
        }
        return matrix;
    }
    Matrix& Matrix::operator--(){
        for(unsigned i=0;i<mat.size();i++)
        {
            mat.at(i)--;
        }
        return *this;
    }
    Matrix Matrix::operator--(int)
    {
        Matrix matrix(mat,row,col);
        for(unsigned i=0;i<mat.size();i++)
        {
            mat.at(i)--;
        }
        return matrix;
    }
    Matrix Matrix::operator*(const Matrix& other)
    {
        if(col!=other.row)
        {
            throw invalid_argument{"multipication is undifiend"};
        }
       vector<vector<double>>origin((unsigned)row,vector<double>((unsigned)col));
       vector<vector<double>>mult((unsigned)other.row,vector<double>((unsigned)other.col));
       vector<vector<double>>ans((unsigned)row,vector<double>((unsigned)other.col));
       convert(origin,mat,row,col);
       convert(mult,other.mat,other.row,other.col);
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
        vector<double>ans2((unsigned)(other.col*row));
        unsigned index=0;
        for(unsigned i=0;i<ans.size();i++)
        {
            for(unsigned j=0;j<ans[i].size();j++)
            {
                ans2[index++]=ans[i][j];
            }
        }
    
        return  Matrix(ans2,row,other.col);
    }
    Matrix& Matrix::operator*=(double num)
    {
        for(unsigned i=0;i<mat.size();i++)
        {
            mat.at(i)*=num;
        }
        return *this;
    }
    /**
     * @brief overload operator *
     * 
     * @param num 
     * @param mat 
     * @return Matrix 
     */
    Matrix operator*(double num,Matrix& mat)
    {
        Matrix m(mat.mat,mat.row,mat.col);
        for(unsigned i=0;i<m.mat.size();i++)
        {
            m.mat.at(i)*=num;
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