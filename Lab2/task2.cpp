#include <iostream>
using namespace std;


#define read(type, var) type var; cin >> var;
#define macro(x, y) x=x<<y;

int main(){
    read(int, x);
    read(int, y);
    macro(x, y);
    cout << x;
}