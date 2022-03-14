#include <iostream>
#include <conio.h>

class heater{
    private:
        int temp;
    public:
        heater(){
            temp = 15;
        }

        void print(){
            std::cout << "Temperature is: " << temp << std::endl;
        }

        void warmer(){
            temp += 5;
        }

        void cooler(){
            temp -= 5;
        }

        void getInput(){
            char input;
            int ascii;
            while(1){
                system("CLS");
                std::cout << "USE ARROW KEYS TO CHANGE TEMPERATURE :)" << std::endl
                    << "ESCAPE TO EXIT :(" << std::endl;
                print();
                input = getch(); 
                ascii = input;
                if(ascii == 80){
                    warmer();
                } else if(ascii == 72){
                    cooler();
                } else if(ascii == 27){
                    break;
                }
            }
        }

        ~heater(){
            delete &temp;
            std::cout << std::endl <<"destructor oh noooooooooo..."; 
        }
};

int main(){
    heater h;
    h.getInput();

    return 0;
}