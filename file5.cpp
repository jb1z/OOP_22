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

class A{
    private:
        string msgPriv = "Message private\n";
    protected:
        string msgProt = "Message protected\n";
    public:
        string msgPub = "Message public\n";
};

class B : public A{
    public: 
        void printMessage(){
            cout << msgPub;
            cout << msgProt;
            //cout << msgPriv; // - private section is locked from here
        }
};

// when inheriting: public -> fields: public - public; protected - protected; private - private
// when inheriting: protected -> fields: public - protected; protected - protected; private - private
// when inheriting: private -> fields: public - private; protected - private; private - private


int main(){
    Student st;
    st.Learn();
    ExtramuralStudent stExtra;
    stExtra.Learn();
    cout << "\n";

    B b;
    b.printMessage();
    b.msgPub;
    //b.msgProt; - protected section locked from here
    //b.msgPriv; - private section locked from here
    return 0;
}