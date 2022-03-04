#include <iostream>
using namespace std;

#define read(type, var) type var; cin >> var;
#define check(x) if(!(x & (x-1)))cout << "yes it is a power of 2";else cout << "no it is not a power of 2";

int main(){
    read(int, x);
    check(x);
    return 0;
}