#include <iostream>
#include <conio.h>

int menu(){
    int selector = 1;
    int ascii;
    char input;
    while(1){
        system("CLS");
        std::cout << "MENU OPTIONS HERE";
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
