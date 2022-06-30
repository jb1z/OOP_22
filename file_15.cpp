#include <iostream>
#include <vector>
using namespace std;

int main(){
    /*auto a = 10; // a becomes int
    auto b = 1.44; // b becomes double
    auto c = "string"; // c becomes const char[]
    //auto d; we cant do like this
    auto d = true;*/
    vector<int> myVector = {11,46,9};
    vector<int>::iterator it = myVector.begin(); // !!
    auto it2 = myVector.begin(); // !!
    for(auto it = myVector.begin(); it != myVector.end(); it++){
        cout << *it << endl;
    }
    // we can use auto instead of long type define
    // using for primitive worsens the readability of the code
    cout << endl;

    vector<int> myVector1;
    //vector<int> myVector1(20,55); // 20 elements with data: 55
    myVector1.reserve(100); // setting capacity
    myVector1.push_back(10);
    myVector1.push_back(2);
    myVector1.push_back(56);
    for(int i = 0; i < myVector1.size(); i++){
        cout << myVector1[i] << endl;
        cout << myVector1.at(i) << endl; // check for an array borders
        // at method is slower
    }
    //myVector1.clear(); // delete all elements
    myVector1.pop_back(); // delete last element
    cout << "Size: " << myVector1.size() << endl; // vector size
    cout << "Capacity: " << myVector1.capacity() << endl; // capacity of vector
    myVector1.shrink_to_fit(); // fitting capacity to size
    myVector1.empty(); // is empty
    myVector1.resize(20);
    for(int i = 0; i < myVector1.size(); i++){
        cout << myVector1[i] << endl;       
    }
    return 0;
}