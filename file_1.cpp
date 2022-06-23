#include <iostream>
using namespace std;

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

int main() {
    int dataToEnter = 5;    
    MyClass firstObject(dataToEnter);
    // same things
    MyClass secondObject(firstObject); // Copy constructor is used here
    MyClass thirdObject = firstObject; // And here copy constructor too, not assignment
    //
    MyClassOther firstOtherObject;
    MyClass fourthObject(firstOtherObject);
    MyClass fifthObject(2);
    MyClass sixthObject(2);
    sixthObject = fifthObject = firstObject; // overloaded operator return link to object so we able to do this
    return 0;   
}