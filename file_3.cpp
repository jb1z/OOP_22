#include <iostream>
#include <string>
using namespace std;

class Apple{
    private:
        static int appleCount_;
        int weight_;
        string color_;
        int id_;
    public:       
        Apple(int weight, string color){
            weight_ = weight;
            color_ = color;
            appleCount_++;
            setId(appleCount_);
        }
        void setId(int id){
            id_ = id;
        }
        int getId(){
            return id_;
        }
        void print(){
            cout << "Apple " << id_ << " weight: " << weight_ << ", color: " << color_ << "\n";
        }
        static int getAppleCount(){
            // weight_ = 0; we cant access to non-static field 
            return appleCount_;
        }
        static void changeColor(Apple &apple, string color){ // we can do like this
            apple.color_ = color;  
        }
        
};

int Apple::appleCount_ = 0; // static initializing outside a class

int main() 
{ 
    Apple apple1(150, "green");   
    cout << "Apple id: " << apple1.getId() << "\n";
    Apple apple2(150, "green");   
    cout << "Apple id: " << apple2.getId() << "\n";
    Apple apple3(150, "green");   
    cout << "Apple id: " << apple3.getId() << "\n";
    Apple apple4(150, "green");
    cout << "Apple id: " << apple4.getId() << "\n";
    cout << "Amount of apples: " << Apple::getAppleCount() << "\n";
    Apple::changeColor(apple2, "red");
    apple2.print();
    return 0;
}

