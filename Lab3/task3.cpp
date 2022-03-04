#include <iostream>
using namespace std;

int main() {

    int size;
    cout << "enter size: ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // for (int i = 0; i < size; i++) {
    //     cout << arr[i] << ", ";
    // }
    // cout << endl;

    int negs = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0)
            negs++;
    }

    int n = 0, p = 0;
    int* negArr = new int[negs];
    int* posArr = new int[size - negs];

    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            negArr[n++] = arr[i];
            // cout << negArr[n - 1] << endl;
        }
        else {
            posArr[p++] = arr[i];
        }
    }

    int i;
    for (i = 0; i < p; i++) {
        arr[i] = posArr[i];
    }
    for (i = p; i < size; i++) {
        arr[i] = negArr[i - p];
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }

    delete [] negArr;
    delete [] posArr;
    // delete [] arr;
    
    return 0;
}