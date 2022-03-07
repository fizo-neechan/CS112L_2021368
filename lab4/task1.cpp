#include <iostream>
using namespace std;

class swapperoni{
    private:
        int A, B;
        int *a = &A, *b = &B;
    public:
    
        void setter(){
            cout << "Enter 2 values: ";
            cin >> *a >> *b;
        }
        void swap(){
            a = &B;
            b = &A;
        }
        void display(){
            cout << "A: " << *a;
            cout << endl <<"B: " << *b;
        }
};

int main(){
    swapperoni swappy;
    swappy.setter();
    swappy.swap();
    swappy.display();

}