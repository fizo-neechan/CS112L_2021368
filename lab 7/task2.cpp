#include <iostream>
#include <random>
#include <time.h>
using namespace std;


class matrixType{
    int rows, cols;
    int **matrix;

    public:
        matrixType(int x = 1){
            cin >> rows;
            cin >> cols;
            init(x);
        }

        matrixType(int r, int c){
            rows = r;
            cols = c;
            init(0);
        }

        void init(bool x = 1) {
            srand(time(0));
            matrix = new int*[rows];
            for(int i = 0; i < rows; i++){
                matrix[i] = new int[cols];
            }

            for(int i = 0; i < rows; i++)
                for(int j = 0; j < cols; j++)
                    matrix[i][j] = (x ? rand() % 10 : 0);
        }
    
        matrixType operator + (matrixType q) {
            if(this->rows != q.rows && this->cols != q.cols)
                return *this;

            matrixType temp(rows, cols);

            for(int i = 0; i < rows; i++)
                for(int j = 0; j < cols; j++)
                    temp.matrix[i][j] = matrix[i][j] + q.matrix[i][j];
            return temp;
         }

         matrixType operator - (matrixType q) {
            if(this->rows != q.rows && this->cols != q.cols)
                return *this;

            matrixType temp(rows, cols);

            for(int i = 0; i < rows; i++)
                for(int j = 0; j < cols; j++)
                    temp.matrix[i][j] = matrix[i][j] - q.matrix[i][j];
            return temp;
         }

         matrixType operator * (matrixType q) {
            if(this->cols != q.rows)
                return *this;

            matrixType temp(this->rows, q.cols);

            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < q.cols; j++)
                    for(int k = 0; k < this->cols; k++)
                        temp.matrix[i][j] += matrix[i][k] * q.matrix[k][j];

            return temp;
         }

         friend ostream& operator << (ostream &op, matrixType A){
            for(int i = 0; i < A.rows; i++){
                for(int j = 0; j < A.cols; j++){
                    op << A.matrix[i][j] << " ";
                }
                op << '\n';
            }
            return op;
         }
};

int main(){
    matrixType A;
    matrixType B;
    matrixType C(0, 0);

    cout << A;
    cout << endl;
    
    cout << B;
    cout << endl;

    cout << A + B;
    cout << endl;

    cout << A - B;
    cout << endl;

    cout << A * B;
    cout << endl;
}