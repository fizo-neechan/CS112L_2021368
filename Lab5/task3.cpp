#include <iostream>
using namespace std;

class stringType{
    private:
        string s1, s2;
    public:
        stringType(){
            s1 = "";
            s2 = "";
        }

        void setValues(string str1, string str2){
            s1 = str1;
            s2 = str2;
        }
        void copy(string &destination, string source) {
            destination = source;
        }

        string concatenate(string s1, string s2) {
            s1 += s2;
            return s1;
        }

        int compare(string s1, string s2) {
            return (s1==s2);
        }

        int maxLength(const string s) {
            int i;
            for (i = 0; s[i] != '\0'; i++);
            return i;
        }

        int searchWord(string word){
            bool found = 0;
            for(int i = 0; s1[i] != '\0'; i++){
                if(s1[i] == word[0]){
                    found = 1;
                    for(int j = 0; j < maxLength(word); j++){
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

        int searchChar(char ch){
            for(int i = 0; i < s1.length(); i++){
                if(s1[i] == ch){
                    return 1;
                }
            }
            return 0;
        }

        ~stringType(){
            delete &s1;
            delete &s2;
            cout << "destructor oh nooooo";
        }
};


// NO MENU AS IT WAS NOT MENTIONED
int main() {

    string s1 = "Hello my name is faizan", s2 = "faizan";
    stringType s;
    s.setValues(s1, s2);
    cout << endl << s.compare(s1, s2);
    cout << endl << s.maxLength(s1);
    string s3; 
    s.copy(s3, s1);
    cout << endl << s3;
    cout << endl << s.searchChar('f') << endl;
    cout << endl << s.searchWord("faizan") << endl;


    return 0;
}