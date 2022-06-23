#include <iostream>
using namespace std;

class MyClass {
    private:
        int data_;
    public:
        MyClass(int data) {
            data_ = data;
            cout << "I'm constructor with a " << data_ << "\n";
        }
        ~MyClass() {
            cout << "I'm destructor\n";
        }
};

int main() {
    int dataToEnter; 
    cout << "Enter a data:\n";
    cin >> dataToEnter;   
    MyClass firstClass(dataToEnter);
    return 0;   
}