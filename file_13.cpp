#include <iostream>
#include <memory>
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
    auto_ptr<int> ap1 (new int(1));
    auto_ptr<int> ap2 (ap1);

    unique_ptr<int> up1(new int(1));
    //unique_ptr<int> up2(up1); we cant do like this (UNIQUE pointer)
    unique_ptr<int> up2;
    //up2 = move(up1);
    // when we try to make second pointer, which point to the same memory block, previous pointer lost the way to memory block
    up2.swap(up1); // move analogue
    int *p = up1.get();

    int *p1 = new int(5);
    unique_ptr<int> up3(p1);
    //up3.reset(); // data overwritten in memory
    up3.reset(); // pointer stops point to this memoty block

    // data deleted when last shared_poiner deleting 
    shared_ptr<int> sp1(new int(1));
    shared_ptr<int> sp2(sp1);

    const int SIZE = 5;
    int *arr = new int[SIZE] {78, 22, 50, 12, 2};
    shared_ptr<int[]> ptr(arr);
    // shared_ptr<int[]> ptr(new int[SIZE] {78, 22, 50, 12, 2});
    for(int i = 0; i < SIZE; i++)
    {
        //ptr[i] = rand() % 10;
        cout << ptr[i] << endl;
    }
    return 0;
}