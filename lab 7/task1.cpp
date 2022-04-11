#include <iostream>

class Date {
    int day, month, year;
    public:
        bool operator < (Date d){
            if(this->year < d.year)
                return 1;
            else if(this->year == d.year){
                if( this->month < d.month)
                    return 1;
                else if(this->month == d.month){
                    if( this->day < d.day)
                        return 1;
                    else 
                        return 0;
                } else
                    return 0;
            } else
                return 0;
        } 

        friend std::istream& operator >> (std::istream& input, Date& d){
            do{
                input >> d.year >> d.month >> d.day;

                if(d.year < 1990 || d.year > 2022)
                    continue;
                else if(d.month < 1 || d.month > 12)
                    continue;
                else if(d.day < 1 || d.day > 31)
                    continue;
                else if(d.month == 2 && d.month > 28)
                    continue;
                else break;

            }while (1);
            
            return input;
        }

        friend std::ostream& operator << (std::ostream& op, Date& d){
            op << d.year << ' ' << d.month << ' ' << d.day;
            return op;
        }

        // friend class Person;    // NO PURPOSE BUT OK
        friend void Seniority(Person, Person);

};

class Person {

    std::string name, reg;
    Date dateOfJoining;
    static int count;
    public:
        Person(){
            std::cin >> this;
            count ++;
        }

        void printPerson(){
            std::cout << this;
        }

        friend std::istream& operator >> (std::istream& input, Person *p){
            input >> p->name;
            input >> p->reg;
            input >> p->dateOfJoining;
            return input;
        }

        friend std::ostream& operator << (std::ostream& op, Person *p){
            op << p->name << p->reg << p->dateOfJoining;
            return op;
        }

        friend void Seniority(Person p, Person q){
            if(p.dateOfJoining < q.dateOfJoining){
                std::cout << p.name << " is seniour to " <<  q.name << " cuz " << p.dateOfJoining << " is earlier than " << q.dateOfJoining;
            } else
                std::cout << q.name << " is seniour to " <<  p.name << " cuz " << q.dateOfJoining << " is earlier than " << p.dateOfJoining;
        }

        ~Person(){
            count--;
        }
};

int Person::count = 0;

int main(){
    Person p, q;
    Seniority(p, q);
}