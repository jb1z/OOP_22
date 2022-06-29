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
    return 0;
}