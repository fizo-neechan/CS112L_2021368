#include <iostream>
using namespace std;

class stringType{
    private:
        string s1, s2;
    public:
        // constructor
        stringType(){
            s1 = "";
            s2 = "";
        }
        // setter
        void setValues(string str1, string str2){
            s1 = str1;
            s2 = str2;
        }
        // copies the source into destination; returns nothing
        void copy(string &destination, string source) {
            destination = source;
        }
        // concatenates the strings and return the result
        string concatenate(string s1, string s2) {
            s1 += s2;
            return s1;
        }
        // compares the ascii values of s1 and s2; returns 0 if both are equal
        int compare(string s1, string s2) {
            if(s1 > s2)
                return 1;
            else if(s1 < s2)
                return -1;
            else 
                return 0;
        }
        // returns length of strings
        int len(const string s) {
            int i;
            for (i = 0; s[i] != '\0'; i++);
            return i;
        }
        // returns the greater length of s1 and s2
        int maxLength(){
            return len(s1) > len(s2) ? len(s1) : len(s2);
        }
        // returns first occurance of word 
        int searchWord(string word){
            bool found = 0;
            for(int i = 0; s1[i] != '\0'; i++){
                if(s1[i] == word[0]){
                    found = 1;
                    for(int j = 0; j < len(word); j++){
                        if(s1[i+j] != word[j]){
                            found  = 0;
                            break;
                        }
                    }
                    if(found)
                        return i;
                }
            }
            return -1;
        }
        // returns the index of first occurance of ch
        int searchChar(char ch){
            for(int i = 0; i < s1.length(); i++){
                if(s1[i] == ch){
                    return i;
                }
            }
            return -1;
        }
        // destructor
        ~stringType(){
            delete &s1;
            delete &s2;
            cout << "destructor oh nooooo";
        }
};


// NO MENU AS IT WAS NOT MENTIONED
int main() {

    string s1 = "hello my name is faizan", s2 = "faizan";
    stringType s;
    s.setValues(s1, s2);
    cout << endl << s.compare(s1, s2);
    cout << endl << s.maxLength();
    string s3; 
    s.copy(s3, s1);
    cout << endl << s3;
    cout << endl << s.searchChar('f') << endl;
    cout << endl << s.searchWord("h") << endl;


    return 0;
}