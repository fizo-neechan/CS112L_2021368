#include <iostream>
using namespace std;

int main(){

    int size;
    cout << "Enter array size: ";
    cin >> size;

    int *list = new int[size];
    for(int i = 0; i < size; i++){
        cin >> list[i];
    }
    
    while(size != 0){
        int *A = new int[size-1];
        for(int i = 0; i <size - 1; i++){
            A[i] = list[i+1] - list[i];
        }

        for(int i = 0; i < size-1; i++){
            cout << A[i] << ", ";
        }
        cout << endl;
        delete [] list;
        size--;
        list = A;
    }

    


    return 0;
}