#include <iostream>
using namespace std;

class good_set{
    private:
        int size = 0;
        int *A = new int [size];
    public:
        void set(){
            int input;
            cin >> input;
            if(!test(input)){
                int *temp = new int[size+1] ;
                for(int i = 0; i <  size; i++){
                    temp[i] = A[i];
                }
                temp[size] = input;
                delete [] A;
                A = temp;
            }
        }

        void clear(){
            int input;
            cin >> input;
            int *temp = new int[--size] ;
            for(int i = 0; i <  size+1; i++){
                if(temp[i] != input)
                    temp[i] = A[i];
            }
            delete [] A;
            A = temp;
        }

        bool test(int input){
            for(int i = 0; i < size; i++){
                if(input == A[i])
                    return 1;
            }
            return 0;
        }

};

int main(){
    
    return 0;
}