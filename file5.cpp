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

//!
// when inheriting: public -> fields: public - public; protected - protected; private - private
// when inheriting: protected -> fields: public - protected; protected - protected; private - private
// when inheriting: private -> fields: public - private; protected - private; private - private
//!

//the calling order of constructors and destructors
class C{
    public:
        C(){
            cout << "Im C constructor!\n"; 
        }
        ~C(){
            cout << "Im C destructor!\n";
        }
};

class D : public C{
    public:
        D(){
            cout << "Im D constructor!\n";
        }
        ~D(){
            cout << "Im D destructor!\n";
        }
};
//

class E{
    private:
        string msg_;
    public:
        E(){
            cout << "Im E constructor!\n"; 
        }
        E(string msg){
            msg_ = msg;
        }
        void printMsg(){
            cout << msg_ << "\n";
        }       
};

class F : public E{
    public:
        F(string msg) : E(msg){ // we call certain constructor
            cout << "Im F constructor!\n";
        }       
};

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

    D d;

<<<<<<< HEAD
    F f("Message");
=======
    F f;
>>>>>>> cac12d5aefdf47f33ef46c1909a3b57097ea82e1
    return 0;
}