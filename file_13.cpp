#include <iostream>
using namespace std;

template<class T>
class SmartPointer{
    private:
        T* ptr_;
    public:
        SmartPointer(T* ptr){
            ptr_ = ptr;
            cout << "Constructor\n";
        }
        T& operator * (){
            return *ptr_;
        }
        ~SmartPointer(){
            delete ptr_;
            cout << "Destructor\n";
        }
};

int main(){
    // with smart pointer we dont need to manage deleting 
    SmartPointer<int> pointer = new int(5);
    *pointer = 21214;
    cout << *pointer << endl;
    return 0;
}