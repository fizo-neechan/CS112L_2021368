#include <iostream>
#include <iomanip>
using namespace std;

struct student{
    string name, degree;
    int courses, marks[10], reg;
    float GPA;

    void get_marks(){
        cout << "Enter marks of courses:\n";
        for(int i = 0; i < courses; i++){
            cout << "\t course " << i+1 << " ";
            cin >> marks[i];
            if(marks[i] > 100 || marks[i] < 0){
                cout << "MARKS INCORRECT!\n";
                i--;
            }
        }
    }

    void get_details(){
        cout << "Name : ";
        cin >> name;
        cout << "Reg Num : ";
        cin >> reg;
        while(reg < 1000000 || reg > 2021999){
            cout << "Wrong Reg Num, Please Re-enter! : ";
            cin >> reg;
        }
        cout << "Degree : ";
        cin >> degree;
        cout << "Number of Courses : ";
        cin >> courses;
        get_marks();
        GPA = calculate_GPA();
    }

    float calculate_GPA(){
        float sum = 0;
        const int CH = 3;

        for(int i = 0; i < courses; i++){
            if(marks[i] >= 90)
                sum += 4 *CH;
            else if(marks[i] > 86)
                sum += 3.67 * CH;
            else if(marks[i] > 82)
                sum += 3.67 * CH;
            else if(marks[i] > 78)
                sum += 3.33 * CH;
            else if(marks[i] > 74)
                sum += 3 * CH;
            else if(marks[i] > 70)
                sum += 2.67 * CH;
            else if(marks[i] > 66)
                sum += 2.33 * CH;
            else if(marks[i] > 62)
                sum += 2 * CH;
            else if(marks[i] > 58)
                sum += 1.67 * CH;
            else if(marks[i] > 54)
                sum += 1.33 * CH;
            else if(marks[i] >= 50)
                sum += 1 * CH;          
        }
        return sum / (courses * CH);  
    }

    void print_details(){
        cout << name << setw(30) << reg 
            << setw(30) << degree << setw(30) 
            << GPA << endl;
    }
};

void bubble_sort(student std[]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            if(std[j].GPA < std[j+1].GPA)
                swap(std[j], std[j+1]);
        }
    }
}


int main(){

    student std[3];

    for(int i = 0; i < 3; i++){
        cout << "For student " << i+1 << ": \n";
        std[i].get_details();
    }

    cout << endl << endl << endl;

    cout << "NAME" << setw(30) << "REG NO" 
        << setw(30) << "DEGREE" << setw(30) << "GPA\n";
    for(int i = 0; i < 3; i++){
        std[i].print_details();
    }

    cout << endl << endl << endl;

    bubble_sort(std);
    cout << "NAME" << setw(30) << "REG NO" 
        << setw(30) << "DEGREE" << setw(30) << "GPA\n";
    for(int i = 0; i < 3; i++){
        std[i].print_details();
    }
    cout << "the best student is : \n";
    std[0].print_details();
    
}