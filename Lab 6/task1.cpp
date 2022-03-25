#include <iostream>
#include <string>

class Person{
    std::string comp_uni;
    std::string comp, uni;

    friend class Coordinator;
    public:
        Person(){
            std::cout << "Enter competition and University name: ";
            getline(std::cin, comp_uni);
            tokenize(comp_uni, comp, uni);
        }

        void tokenize(std::string comp_uni, std::string &comp, std::string &uni){
            comp = "";
            uni = "";
            int i;
            for(i = 0; i < comp_uni.length(); i++){
                if(comp_uni[i] != ' ')
                    comp += comp_uni[i];
                else
                    break;
            }
            for(i++; i < comp_uni.length(); i++){
                uni += comp_uni[i];
            }

        }
};

class Coordinator{
    Person p1, p2;

    public:
        void checkRoommate(){
            if(p1.uni == p2.uni){
                std::cout << "P1 and P2 are roommates, room number is " 
                    << (p1.comp.length() > p2.comp.length() ? p1.comp.length() : p2.comp.length());
            } else {
                std::cout << "p1 and p2 are not room mates :(";
            } 
        }

};

int main(){
    Coordinator c;
    c.checkRoommate();
    return 0;
}