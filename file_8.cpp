#include <iostream>
using namespace std;

class Human{
    private:
        string name_;
        int age_;
        int weight_;
    public:
        // delegating constructors !!!
        Human(string name){
            name_ = name;
            age_ = 0;
            weight_ = 0;
        }
        Human(string name, int age) : Human(name){ // firstly calling Human(name)
            age_ = age;
        }
        Human(string name, int age, int weight) : Human(name, age){ // firstly calling Human(name)
            weight_ = weight;
        }
        void print(){
            cout << "Name: " << name_ << ", age: " << age_ << ", weight: " << weight_ << "\n";
        }
};

int main(){
    Human human("John", 15);
    human.print();
    Human humanoid("Jack", 20, 72);
    humanoid.print();
    return 0;
}