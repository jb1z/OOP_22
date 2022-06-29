#include <iostream>
using namespace std;

class Car{
    public:
        Car(){
            cout << "Im car\n";
        }
        void drive(){
            cout << "I'm driving" << endl;
        }
        ~Car(){
            cout << "Im car des\n";
        }
};

class Airplane{
    public:
        Airplane(){
            cout << "Im airplane\n";
        }
        void fly(){
            cout << "I'm flying" << endl;
        }
        ~Airplane(){
            cout << "Im airplane des\n";
        }
};

class FlyingCar : public Car, public Airplane{ // plural inheritance   
    public:
        FlyingCar(){
            cout << "Im flying car\n";
        }
        ~FlyingCar(){
            cout << "Im flying des\n";
        }
};

int main(){
    FlyingCar fc;

    // the order of constuctor calling depends on inheritance order
    // destructor are calling in reversed order

    //fc.drive();
    //fc.fly();

    //Car *ptrC = &fc;
    //Airplane *ptrA = &fc;
    return 0;
}