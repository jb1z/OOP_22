#include <iostream>
using namespace std;

class Point;

class Test{
    private:
        int value_;
    public:
        Test(){
            value_ = 5;
        }
        friend void changeX(Point & pointChange, Test & testChange);
};

class Point{
    private:
        int x_;
        int y_;
    public:
        Point(){
            x_ = 0;
            y_ = 0;
        }
        Point(int x, int y){
            x_ = x;
            y_ = y;
        }
        int getX(){
            return x_;
        }
        int getY(){
            return y_;
        }
        void setX(int x){
            x_ = x;
        }
        void setY(int y){
            y_ = y;
        }
        void print(){
            cout << "x = " << x_ << " y = " << y_ << "\n";
        }
        friend void changeX(Point & pointChange, Test & testChange); // friend function
        friend void changeY(Point & pointChange); // friend function
};

void changeX(Point & pointChange, Test & testChange){ // this function is friend to two classes
    pointChange.x_ = 0;                               // it has access to prevate fields in two classes (Point, Test)
    testChange.value_ = 0;
    // this-> doesnt work in friend functions
}

void changeY(Point & pointChange){
    pointChange.y_ = 0;
}

class MyClass{
    private:
        int data_;
    public:
        MyClass();
        void print();
};

MyClass::MyClass(){ // constructor outside the class
    data_ = 5;
}

void MyClass::print(){ // method outside the class
    cout << "Data is: " << data_ << "\n";
}

int main() 
{ 
    Point a(5, 26);
    Test test;
    a.print();
    changeX(a, test);
    a.print();
    changeY(a);
    a.print();

    MyClass dataCarrier;
    dataCarrier.print();
    return 0;
}