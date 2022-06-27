#include <iostream>
#include <string>
using namespace std;

class Human{ // base class for Student, ExtramuralStudent and Professor
    public:
        string name;
};

class Student: public Human{ // inherited from Human
                             // base class for ExtramuralStudent
    public:
        string group;
        void Learn(){
            cout << "Im ochnik!\n"; 
        }

};

class ExtramuralStudent : public Student{ // inherited from Student
    public:
        void Learn(){
            cout << "Im extra!\n"; 
        }
};

class Professor: public Human{ // inherited from Human
    public:
        string subject;

};

int main(){
    Student st;
    st.Learn();
    ExtramuralStudent stExtra;
    stExtra.Learn();
    return 0;
}