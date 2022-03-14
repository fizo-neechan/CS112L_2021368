#include <iostream>
using namespace std;

class parity{
    private:
        int n;
        int *arr;
    public:
        parity(){
            n = 0;
            arr = new int [n];
        }

        void put(int x){

            int *temp = new int [n+1];
            for(int i = 0; i < n; i++){
                temp[i] = arr[i];
            }
            delete [] arr;
            temp[n] = x;
            n++;
            arr = temp;
            delete [] temp;
        }

        void print(){
            for(int i = 0; i < n; i++){
                cout << arr[i] << ", ";
            }
            cout << endl;
        }
        
        // Deletes the last index, as stated in the question paper
        // the x which is passed has no use; but it was stated in question, thus added
        void Delete(int x){
            int *temp = new int [--n];
            for(int i = 0; i < n; i++){
                temp[i] = arr[i];
            }
            delete [] arr;
            arr = temp;
            delete [] temp;
        }

        bool test(){
            return !(n%2);
        }

        ~parity(){
            delete &n;
            delete [] arr;
            cout << endl << "destructor oh noooooooooo";
        }
};

// NO MENU AS IT WAS NOT MENTIONED
int main(){
    parity p;
    for(int i = 0 ; i < 10; i++){
        p.put(i);
    }
    p.print();
    p.Delete(10);
    p.print();
    cout << endl << p.test();
}