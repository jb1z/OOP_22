#include <iostream>
using namespace std;

class IBycycle{ // interface is an abstract class with all methods virtual
    public:
        virtual void turnWheel() = 0;
        virtual void ride() = 0;
};

class SimpleBycycle : public IBycycle{ // class which realize interface
    public:
        void turnWheel() override{
            cout << "Turn wheel on simple\n";
        }
        void ride() override{
            cout << "Ride on simple\n";
        }
};

class SportBycycle : public IBycycle{ // class which realize interface
    public:
        void turnWheel() override{
            cout << "Turn wheel on sport\n";
        }
        void ride() override{
            cout << "Ride on sport\n";
        }
};

class Human{
    public:
        void rideOn(IBycycle &bycycle){
            cout << "Turning wheel:\n";
            bycycle.turnWheel();
            cout << "Riding:\n";
            bycycle.ride();
        }
};

int main(){
    SimpleBycycle sb;
    SportBycycle sb1;
    Human h;
    h.rideOn(sb);
    h.rideOn(sb1);
    return 0;
}