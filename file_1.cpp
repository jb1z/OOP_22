#include <iostream>
#include <string>
using namespace std;

class Human{
    private:
        int age_;
        int height_;
        string name_;
    public:
        Human(int age, int height, string name){
            age_ = age;
            height_ = height;
            name_ = name;
        }
        bool operator != (const Human &other){ // overloaded != operator
            return !(this->age_ == other.age_ && this->height_ == other.height_ && this->name_== other.name_);
        }
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
        Point(const Point & other){
            this->x_ = other.x_;
            this->y_ = other.y_;
        }
        int getX(){
            return x_;
        }
        int getY(){
            return y_;
        }
        bool operator == (const Point &other){ // overloaded == operator
            return this->x_ == other.x_ && this->y_ == other.y_;
        };
        // without a copy constructor the error accures with a addition if we allocate dynamic memory
        Point operator + (const Point &other){ // overloaded + operator
            Point temp(this->x_ + other.x_, this->y_ + other.y_);
            return temp;
        }
        Point & operator ++ (){ // overloaded ++ operator (prefix)
            this->x_++;
            this->y_++;
            return *this;
        }
        // postfix form deffers from prefix by inused int parametr
        // we cant return a reference to temp because its lifetime is limited by this block of code 
        Point operator ++ (int value){ // overloaded ++ operator (postfix)
            Point temp(*this);
            this->x_++;
            this->y_++;
            return temp;
        }
};

class MyClassOther{
    private:
        int privateInfo_;
    public:
        MyClassOther(){
            privateInfo_ = 10;
            cout << "I'm a MyClassOther constructor\n";
        }
        int getInfo(){
            return privateInfo_;
        }
};

class MyClass {
    private:
        int* data_ = nullptr;
        int size_;
        int myInfo_;
    public:
        // constructor with 1 perametr
        MyClass(int size) {
            size_ = size;
            data_ = new int[size];
            for(int i = 0; i < size; i++) {
                data_[i] = 2 * i;
            }
            cout << "I'm constructor with an data adress " << data_ << "\n";
        }

        // constructor which receive an MyClassOther object
        MyClass(MyClassOther &object) {
            myInfo_ = object.getInfo();
            cout << "I'm constructor with an MyOtherClass\n";
        }

        // copy constuctor
        MyClass(const MyClass &other){ 
            this->data_ = new int[other.size_];
            this->size_ = other.size_; // able to access private field "MyClass" constructor - receive object of "MyClass" 
            for(int i = 0; i < size_; i++){
                data_[i] = other.data_[i];
            }
            cout << "I'm copy constructor\n";
        }

        // overload assignment operator
        MyClass & operator = (const MyClass &other){ // must return a link to this object
            this->size_ = other.size_;          
            if(this->data_ != nullptr) delete[] this->data_; // to prevent memory leak
            this->data_ = new int[size_];
            for(int i = 0; i < size_; i++){
                this->data_[i] = other.data_[i];
            }
            return *this;
        }

        // destructor
        ~MyClass() {
            delete[] data_;
            cout << "I'm destructor\n";
        }
};

// class for testing an overloading of [] (indexing)
class TestIndexing{
    private:
        int size_ = 4;
        int array_[4]{1, 2 , 25 , 0};
    public:
        int & operator [] (int index){ // we use reference to be able to change the value by index
            return array_[index];      // without returning reference we can only get a value by index
        }
        void print(){
            cout << "Array: ";
            for(int i = 0; i < size_; i++){
                cout << array_[i] << " ";
            }
             cout << "\n";
        }
};

int main() {
    int dataToEnter = 5;    
    MyClass firstObject(dataToEnter);
    // same things
    MyClass secondObject(firstObject); // Copy constructor is used here
    MyClass thirdObject = firstObject; // And here copy constructor too, not assignment
    // same things
    MyClassOther firstOtherObject;
    MyClass fourthObject(firstOtherObject);
    MyClass fifthObject(2);
    MyClass sixthObject(2);
    sixthObject = fifthObject = firstObject; // overloaded operator returns reference to object so we able to do this

    Point a(1, 2);
    Point b(1, 2);
    bool compareResultPoint = a == b;
    cout << "Are two \"Point\" equal: " << compareResultPoint << "\n" ;

    Point c = a + b;
    cout << "(.) c with x = " << c.getX() << " y = " << c.getY() << "\n";
    Point c1 = ++c;
    cout << "(.) new c1 after prefix increment of c x = " << c1.getX() << " y = " << c1.getY() << "\n";
    Point c2 = c++;
    cout << "(.) new c2 after postfix increment of c x = " << c2.getX() << " y = " << c2.getY() << "\n";
    cout << "(.) c with x = " << c.getX() << " y = " << c.getY() << "\n";

    Human aH(19, 180, "Oleg");
    Human bH(19, 180, "Hugo");
    bool compareResultHuman = aH != bH;
    cout << "Are two \"Human\" equal: " << compareResultHuman << "\n" ;

    TestIndexing indexObject;
    indexObject.print();
    cout << "Index 2: " << indexObject[2] << "\n";
    indexObject[2] = 1000;
    indexObject.print();
    cout << "Index 2: " << indexObject[2] << "\n";
    return 0;   
}