#include <iostream>
#include <string.h>
using namespace std;

struct birthday{
    int day, year;
    string month;
    // enum months {jan = 1, feb, mar, apr, may, jun, jul, aug, oct, nov, dec};

    void get_bd(){
        cout << "ENTER D.O.B\n";
        cout << "Day : ";
        cin >> day;
        while(day < 1 || day > 30){
            cout << "Wrong day! reenetr: ";
            cin >> day;
        }
        cout << "Month : ";
        cin >> month;
        cout << "Year : ";
        cin >> year;
    }

    bool check(int d, string m, int y){
        if(d == day)
            if(m == month)
                if(y == year)
                    return 1;

        return 0;
    }
};

struct record{

    string name, city;
    int age;
    birthday bd;

    void get_details(){
        cout << "ENTER RECORD\n";
        cout << "Name : ";
        cin >> name;
        cout << "Age : ";
        cin >> age;
        cout << "City : ";
        cin >> city;
        bd.get_bd();
    }
};

int main(){
    int n;
    cout << "how many records? : ";
    cin >> n;

    record *r = new record[n];

    for(int i = 0; i < n; i++){
        r[i].get_details();
    }

    birthday check;
    cout << endl << "TO CHECK ";
    check.get_bd();
    for(int i = 0; i < n; i++){
        if(r[i].bd.check(check.day, check.month, check.year)){
            cout << endl << "It's " << r[i].name << "'s Birthday. Happy birthday, " << r[i].name;
        }
    }
}