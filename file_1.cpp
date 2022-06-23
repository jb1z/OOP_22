#include <iostream>
using namespace std;

class MyClassOther{
    private:
        int privateInfo_;
    public:
        int getInfo(){
            return privateInfo_;
        }
};

class MyClass {
    private:
        int* data_;
        int size_;
        int myInfo_;
    public:
        MyClass(int size) {
            size_ = size;
            data_ = new int[size];
            for(int i = 0; i < size; i++) {
                data_[i] = 2 * i;
            }
            cout << "I'm constructor with an data adress " << data_ << "\n";
        }
        MyClass(MyClassOther &object) {
            myInfo_ = object.getInfo();
        }
        MyClass(const MyClass &other){ // copy constuctor
            this->data_ = new int[other.size_];
            this->size_ = other.size_;
            for(int i = 0; i < size_; i++){
                data_[i] = other.data_[i];
            }
            cout << "I'm copy constructor\n";
        }
        ~MyClass() {
            delete[] data_;
            cout << "I'm destructor\n";
        }
};

int main() {
    int dataToEnter; 
    cout << "Enter a data:\n";
    cin >> dataToEnter;   
    MyClass firstClass(dataToEnter);
    MyClass secondClass(firstClass);
    return 0;   
}