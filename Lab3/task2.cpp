#include <iostream>

int highest(int arr[], int size){
    int highest = 0;
    int second_highest;
    for(int j = 0; j < size; j++){
        if(arr[j] > highest){
            second_highest = highest;
            highest = arr[j];
            // continue;
        } else if (arr[j] > second_highest){
            second_highest = arr[j];
        }
    }
    return second_highest;
}

int lowest(int arr[], int size){
    int lowest = 99999;
    int second_lowest;
    for(int j = 0; j < size; j++){
        if(arr[j] < lowest){
            second_lowest = lowest;
            lowest = arr[j];
            continue;
        } else if (arr[j] < second_lowest){
            second_lowest = arr[j];
        }
    }
    return second_lowest;
}

int main(){
    int size;
    std::cout << "enter arr size: ";
    std::cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size; i++){
        std::cin >> arr[i];
    }

    std::cout << "2nd highest = " << highest(arr, size) << std::endl;
    std::cout << "2nd lowest = " << lowest(arr, size);

    return 0;
}