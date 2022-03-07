#include <iostream>
#include <random>
#include <time.h>
#include <conio.h>

class sad_matrices{
    private:
        const static int SIZE = 5;
        int A[SIZE][SIZE];
        int B[SIZE][SIZE];
        
    public:
        void initializeMatrix(int A[][SIZE]){
            srand(time(0));
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    A[i][j] = rand() % 9 + 1;             
                }
            }
        }

        void initialize(){
            initializeMatrix(A);
            initializeMatrix(B);
        }

        void print(){
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    std::cout << A[i][j] << '\t';            
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    std::cout << B[i][j] << '\t';            
                }
                std::cout << std::endl;
            }
        }

        void transpose(){
            int C[SIZE][SIZE];
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    C[i][j] = A[j][i];
                }
            }
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    A[i][j] = C[i][j];
                }
            }  
        }

        bool isSymmetric(){
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    if(A[i][j] != A[j][i])
                        return 0;
                }
            }
            return 1;
        }

        int *multiply(){
            // if(A.length() != B[0].length())
            int C[SIZE][SIZE] = {0};
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    for(int k = 0; k < SIZE; k++){
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    std::cout << C[i][j] << '\t';            
                }
                std::cout << std::endl;
            }
        }
};

int menu(){
    int selector = 1;
    int ascii;
    char input;
    while(1){
        system("CLS");
        std::cout << "WELCOME TO THE SAD MATRIX MACHINE :(" << std::endl;
        std::cout << "1) Print A & B\n2)Transpose matrix A\n3)isSymmetric for matrix A\n4)Multiply A & B-- plz dont try this :)";
        std::cout << std::endl << std::endl << selector;
        input = getch();
        ascii = input;
        // std::cout << ascii;
        // system("PAUSE");
        if(ascii == 80 && selector < 4){
            selector++;
        } else if(ascii == 72 && selector > 1){
            selector--;
        } else if(ascii == 13){
            return selector;
        }
    }

    
}

int main(){
    sad_matrices m;
    m.initialize();

    while(1){
        switch(menu()){
            case 1:
                m.print();
                break;
            case 2:
                m.transpose();
                break;
            case 3:
                std::cout << m.isSymmetric();
                break;
            case 4:
                m.multiply();
                break;
        }
        system("PAUSE");
    }
}