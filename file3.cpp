#include <iostream>
#include <string>
using namespace std;

class Apple{
    private:
        int weight_;
        string color_;
        int id_;
    public:
        static int appleCount;
        Apple(int weight, string color){
            weight_ = weight;
            color_ = color;
            appleCount++;
            setId(appleCount);
        }
        void setId(int id){
            id_ = id;
        }
        int getId(){
            return id_;
        }
};

int Apple::appleCount = 0; // static initializing outside an object

int main() 
{ 
    Apple apple(150, "green");   
    cout << "Apple id: " << apple.getId() << "\n";
    Apple apple2(150, "green");   
    cout << "Apple id: " << apple2.getId() << "\n";
    Apple apple3(150, "green");   
    cout << "Apple id: " << apple3.getId() << "\n";
    Apple apple4(150, "green");
    cout << "Apple id: " << apple4.getId() << "\n";
    cout << "Amount of apples: " << Apple::appleCount << "\n";   
    return 0;
}

