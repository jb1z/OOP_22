#include <iostream>
using namespace std;

template<class T1, class T2> // typename ~=~ class
T1 sum(T1 a, T2 b){
    return a + b;
}

class Point {
    public:
        Point(){
            x_ = y_ = z_ = 0;
        };
        int getX(){
            return x_;
        }
    private:
        int x_;
        int y_;
        int z_;
};

template<class T>
class MyClass{
    public:
        MyClass(T value){
            value_ = value;
        }
        /*T getValue(){
            return value_;
        }
        void setValue(T value){
            value_ = value;
        }*/
        void dataTypeSize(){
            cout << sizeof(value_) << endl;
        }
    private:
        T value_;

};

int main(){
    cout << sum(1,2) << endl;
    cout << sum(1.5,2.6) << endl;
    string s1 = "abc";
    string s2 = "ABC";
    cout << sum(s1,s2) << endl;
    cout << sum(1.5,2) << endl;

    Point a;
    MyClass<Point> mc(a);
    mc.dataTypeSize();
    //mc.setValue(4.7);
    //cout << mc.getValue() << endl;
    return 0;
}