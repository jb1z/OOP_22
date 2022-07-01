#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <forward_list>
#include <array>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
using namespace std;

template <class T>
void printList(const list<T> &lst){
    for(auto i = lst.begin(); i != lst.end(); ++i){
        cout << *i << endl;
    }
    // for iterators its better to use ++i not i++
    cout << endl;
}

int main(){
    /*Auto keyword*/
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
    /*Auto keyword*/

    /*Vector*/
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
    cout << endl;
    /*Vector*/

    /*Iterator*/
    vector<int> myVector3 = {45, 60, 12, 125, 444, 1010};
    vector<int>::iterator it1;
    it1 = myVector3.begin();
    *it1 = 1001;
    it1+=2;
    vector<int>::iterator it3;
    it3 = myVector3.end();
    it3--;
    cout << *it1 << endl;
    cout << *it3 << endl;
    cout << endl;
    for(vector<int>::const_iterator i = myVector3.cbegin(); i != myVector3.cend(); i++){ // const iterator
        // cbegin and cend return constant iterator
        //*i = 5; // we cant cahnge anything by const iterator
        cout << *i << endl;
    }
    cout << endl;
    for(vector<int>::reverse_iterator i = myVector3.rbegin(); i != myVector3.rend(); i++){ // reverse iterator     
        cout << *i << endl;
    }
    cout << endl;
    
    vector<int>::iterator it4 = myVector3.begin();
    /*advance(it4, 3); // (iterator, step)
    cout << *it4 << endl;*/ // we will have 125
    myVector3.insert(it4, 9999);
    for(vector<int>::const_iterator i = myVector3.cbegin(); i != myVector3.cend(); i++){
        cout << *i << endl;
    }

    vector<int>::iterator itErase = myVector3.begin();
    myVector3.erase(itErase);
    //myVector3.erase(itErase, itErase + 3); // erasing from 0 to 3 
    cout << endl;
    for(vector<int>::const_iterator i = myVector3.cbegin(); i != myVector3.cend(); i++){
        cout << *i << endl;
    }
    cout << endl;
    /*Iterator*/
    
    /*List*/
    list<int> myList = {1255, 12, 5323};
    myList.push_back(5);
    myList.push_front(205);

    list<int>::iterator itList = myList.begin();
    cout << "First element: " << *itList << endl;
    cout << endl;
    for(list<int>::iterator i = myList.begin(); i != myList.end(); i++){
        cout << *i << endl;
    }
    cout << endl;
    printList(myList);
    myList.sort();
    printList(myList);
    cout << myList.size() << endl;
    cout << endl;

    list<int> myList1 = {1,2,3, 99, 3, 2, 1, 99,99,99,99};
    myList1.unique(); // deletes recurring element which are in sequence
    printList(myList1);
    //myList1.reverse(); // reverses list
    //myList1.clear();
    auto itList1 = myList1.begin();
    advance(itList1, 5);
    myList1.insert(itList1, 1111);
    itList1 = myList1.begin();
    myList1.erase(itList1);
    myList1.remove(99);
    printList(myList1);
    //myList1.assign(3, 1241); // filling by 3 element data of 1241
    printList(myList1);
    list<int> myList2;
    myList2.assign(myList1.begin(), myList1.end());
    printList(myList2);
    /*List*/

    /*PrefixVS_Postfix*/
    // prefix has a higher priority than postfix!!!
    list<int>::iterator it5;
    //it5++; //
    //++it5; //
    // the temp variable is creating when the postfix increment realizing
    // that's why postfix incrementing is slower
    // need this because of priority of postfix incrementing
    /*PrefixVS_Postfix*/

    /*Forward list*/
    forward_list<int> fl = {1, 5 , 0 ,244};
    fl.push_front(1);
    fl.push_front(3);
    forward_list<int>::iterator itFl = fl.begin();
    //itFl++;
    fl.insert_after(itFl, 999909);
    fl.erase_after(itFl);
    //itFl--; // decrement is not overloaded because forward list is singly connected  
    cout << *itFl << endl << endl;
    forward_list<int>::iterator itFl1 = fl.before_begin();
    fl.insert_after(itFl1, 999909); // we can insert element before 1st in list
    for(auto el : fl){
        cout << el << endl;
    }
    /*Forward list*/ 

    /*Array*/ // wrapper for static array
    array<int, 5> array1 = {5, 3, 1, 2, 4};
    cout << array1[0] << endl;
    cout << array1.at(4) << endl << endl;
    array1.fill(2);
    for(auto el : array1){
        cout << el << endl;
    }
    cout << endl;
    /*Array*/
   
    /*Compare operators*/
    array<int, 5> arr1 = {5, 3, 1, 2, 5};
    array<int, 5> arr2 = {5, 3, 1, 2, 4};
    bool result = (arr1 == arr2);
    bool result1 = (arr1 > arr2);
    cout << result << endl;
    cout << result1 << endl;
    cout << endl;
    /*Compare operators*/

    /*Deque*/
    /*list of small dynamic arrays*/
    // accessing is faster than in list but slower than in vector
    // inserting is faster than in vector
    deque<int> dq = {1, 2, 999};
    dq.at(0);
    /*Deque*/

    /*Set/multiset*/
    // set keeps only unique values
    // elements in set are ordered
    set<int> mySet;
    //mySet.insert(5);
    //mySet.insert(2);
    //mySet.insert(8);
    for(int i = 0; i < 10; i++){
        mySet.insert(rand() % 10);
    }  
    for(auto el : mySet){
        cout << el << endl;
    }
    mySet.clear();
    mySet.insert(1);
    mySet.insert(5);
    mySet.insert(15);
    mySet.insert(30);
    // the element finding is realiazed by binary search
    auto itSet = mySet.find(15); 
    // we cant change element in set
    // but we can delete and insert them
    mySet.erase(5);
    mySet.insert(64);
    cout << endl;
    for(auto el : mySet){
        cout << el << endl;
    }
    cout << endl;
    auto res = mySet.insert(30);
    // returning a pair: iterator and bool (is set or not (because element already was in set))    
    cout << endl;

    multiset<int> myMultiSet = {-1, -2, 1, 1, 1, 4, 55, 125};
    for(auto el : myMultiSet){
        cout << el << endl;
    }
    cout << endl;
    auto itMS1 = myMultiSet.lower_bound(1); // returns an iterator to first 1
    auto itMS2 = myMultiSet.upper_bound(1); // returns an iterator to first element bigger than 1
    cout << *itMS1 << endl;
    cout << *itMS2 << endl;
    cout << endl;
    auto itMS3 = myMultiSet.equal_range(1); // returns a range of element from lower_bound to upper_bound 
    cout << endl;
    /*Set/multiset*/

    /*Map/multimap*/
    // map unique values
    // multimap duplicate values
    pair<int, string> p(0, "Samsung");
    cout << p.first << endl;
    cout << p.second << endl;
    cout << endl;
    map<int, string> myMap;
    myMap.insert(pair<int, string> (2, "AOC")); 
    myMap.emplace(3, "Honor");
    myMap.insert(p);
    myMap.insert(make_pair(1, "LG"));
    auto itMM = myMap.find(3);
    cout << itMM->first << endl;
    cout << itMM->second << endl;
    cout << endl;
    map<string, int> myMap1;
    myMap1.emplace("Bruce", 1000000);
    myMap1.emplace("Marta", 12125);
    myMap1.emplace("Kal-El", 5555);
    myMap1["Bruce"] = 20000000;
    // myMap1.at("Robbin") = 212512; // out of range exception
    myMap1["Robbin"] = 212512;
    cout << myMap1["Bruce"] << endl;
    cout << myMap1["Marta"] << endl;
    cout << myMap1["Kal-El"] << endl;
    cout << myMap1["Robbin"] << endl;
    myMap1.erase("Robbin");

    multimap<string, int> myMultiMap;
    myMultiMap.emplace("Marta", 12125);
    myMultiMap.emplace("Marta", 5555);
    // at is missing & [] is not overloaded   
    cout << endl;
    /*Map/multimap*/  
    return 0;
}