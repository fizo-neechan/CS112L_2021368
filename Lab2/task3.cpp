#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <bitset>
#include <math.h>
#include <iomanip>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int base_menu(){
    char key_press;
    int ascii_value, selector = 1;
    while(1){
        system("CLS");

        SetConsoleTextAttribute(hConsole, 15);
        cout << "\tSELECT BASE\nUSE ARROW KEYS TO TARVERSE!\nPRESS ESC TO EXIT\n\n\n";
        switch(selector){
            case 1:
                SetConsoleTextAttribute(hConsole, 112);
                cout << "\t1) base 2\n";
                SetConsoleTextAttribute(hConsole, 8);
                cout << "\t2) base 8\n\t3) base 16\n";
                break;
            case 2:
                SetConsoleTextAttribute(hConsole, 8);
                cout << "\t1) base 2\n";
                SetConsoleTextAttribute(hConsole, 112);
                cout << "\t2) base 8\n";
                SetConsoleTextAttribute(hConsole, 8);
                cout << "\t3) base 16\n";
                break;
            case 3:
                SetConsoleTextAttribute(hConsole, 8);
                cout << "\t1) base 2\n\t2) base 8\n";
                SetConsoleTextAttribute(hConsole, 112);
                cout << "\t3) base 16\n";
                SetConsoleTextAttribute(hConsole, 8);
                break;
        }

        key_press = getch();
        ascii_value = key_press;
        if(ascii_value == 80){
            if(selector < 3)
                selector++;
        } else if(ascii_value == 72){
            if(selector > 1)
                selector--;
        } else if(ascii_value == 27){
            break;
        } else if(ascii_value == 13){
            if(selector == 1)
                return 2;
            else if(selector == 2)
                return 8;
            else
                return 16;
        }  
    }
        SetConsoleTextAttribute(hConsole, 8);
        SetConsoleTextAttribute(hConsole, 112);
}

void Input_2(string &num1, string &num2,int base){
    char key_press;
    int ascii_value, selector = 1;
    while(1){
        system("CLS");
        switch(selector){
            case 1:
                SetConsoleTextAttribute(hConsole, 15);
                cout << "\n\n\nNUM 1:";
                SetConsoleTextAttribute(hConsole, 112);
                cout << setw(10) << num1;
                SetConsoleTextAttribute(hConsole, 15);
                cout << "\nNUM 2:" << setw(10) << num2;
                break;
            case 2:
                SetConsoleTextAttribute(hConsole, 15);
                cout << "\n\n\nNUM 1:" << setw(10) << num1;
                cout << "\nNUM 2:";
                SetConsoleTextAttribute(hConsole, 112);
                cout << setw(10) << num2;
                SetConsoleTextAttribute(hConsole, 15);
                break;
        }
        key_press = getch();
        ascii_value = key_press;

        if(ascii_value == 80){
            if(selector < 2)
                selector++;
        } else if(ascii_value == 72){
            if(selector > 1)
                selector--;
        } else if(ascii_value == 13){
            break;
        } else if(base == 2){
            if(ascii_value == '0' || ascii_value == '1'){
                if(selector == 1){
                    num1 += key_press;
                } else {
                    num2 += key_press;
                } 
            }
        } else if(base == 8){
            if(ascii_value == '0' || ascii_value == '1' || ascii_value == '2' || ascii_value == '3' 
            || ascii_value == '4' || ascii_value == '5' || ascii_value == '6' || ascii_value == '7'){
                if(selector == 1){
                    num1 += key_press;
                } else {
                    num2 += key_press;
                }
            }
        } else if(base == 16){
            if(ascii_value == '0' || ascii_value == '1' || ascii_value == '2' || ascii_value == '3' 
            || ascii_value == '4' || ascii_value == '5' || ascii_value == '6' || ascii_value == '7'
            || ascii_value == '8' || ascii_value == '9' || ascii_value == 'a' || ascii_value == 'b' 
            || ascii_value == 'c' || ascii_value == 'd' || ascii_value == 'e' || ascii_value == 'f'){
                if(selector == 1){
                    num1 += key_press;
                } else {
                    num2 += key_press;
                }
            }
        }
    }
}

int toDecimal(string num, int base){
    int hexConvert, ans = 0;
    for(int i = 0; i < num.length(); i++){
        if(num[i] < 58){
            ans += (int(num[i]) - '0') * pow(base, num.length() - 1 - i);
        } else {
            ans += (int(num[i]) - 87) * pow(base, num.length() - 1 - i);
        }
    }
    return ans;
}

string bitwiseAddition(int num1,int num2){
    int carry;
    while (num2 != 0)
    {
        carry = num1 & num2;
        num1 = num1 ^ num2;
        num2 = carry << 1;
    }
    // cout << endl << num1 << endl;

    return bitset<8>(num1).to_string();
    // return stoi((Ans).to_string());
}

string toBase(string binNum, int base){
    string output = "";
    int quotient;
    int decimal = toDecimal(binNum, base);
    // cout << endl << decimal << endl;

    while(decimal > 0){
        quotient = decimal % base;
        decimal = decimal / base;
        // cout << endl << quotient << endl;
        if (quotient < 10){
            output += char(48 + quotient); 
        } else {
            output += char(87 + quotient);
        }   
    }
    cout << endl << "hello" << output << endl;
    return output;  
}

void OutputAns(string Ans){
    SetConsoleTextAttribute(hConsole, 112);
    cout << "\n\nTHE FINAL ANSWER: " << setw(10); 
    for(int i = 0; i < Ans.length(); i++){
        cout << Ans[Ans.length()-1-i];
    }
    cout << "\n\n";
}

int main(){
    string num1 = "", num2 = "";
    int base = base_menu();
    Input_2(num1, num2, base);
    int dec1 = toDecimal(num1, base), dec2 = toDecimal(num2, base);
    string bitwiseAdd = bitwiseAddition(dec1, dec2);
    string inbase = toBase(bitwiseAdd, base);
    OutputAns(inbase);

    // cout << endl << endl << dec1 << " " << dec2 << ' ' << bitwiseAdd << ' ' << inbase;
    // cout << num1 << " " << num2 << endl;
    // OutputAns(toBase(, base));
    return 0;
}