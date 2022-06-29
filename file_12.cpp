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
class TypeSize{
    public:
        TypeSize(T value){
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
    protected:
        T value_;

};

template <class T>
class TypeInfo : public TypeSize <T>{
    public:
        TypeInfo(T value) : TypeSize <T> (value){}
        void showTypeName(){
            cout << "Type name is " << typeid(this->value_).name() << endl;
        }
};

int main(){
    cout << sum(1,2) << endl;
    cout << sum(1.5,2.6) << endl;
    string s1 = "abc";
    string s2 = "ABC";
    cout << sum(s1,s2) << endl;
    cout << sum(1.5,2) << endl;

    Point a;
    TypeInfo<Point> mc(a);
    mc.dataTypeSize();
    mc.showTypeName();
    //mc.setValue(4.7);
    //cout << mc.getValue() << endl;
    return 0;
}