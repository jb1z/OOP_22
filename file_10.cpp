#include <iostream>
using namespace std;

class IBicycle{ // interface is an abstract class with all methods pure virtual
    public:
        virtual void turnWheel() = 0;
        virtual void ride() = 0;
};

class SimpleBicycle : public IBicycle{ // class which realize interface
    public:
        void turnWheel() override{
            cout << "Turn wheel on simple\n";
        }
        void ride() override{
            cout << "Ride on simple\n";
        }
};

class SportBicycle : public IBicycle{ // class which realize interface
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
        void rideOn(IBicycle &bicycle){
            cout << "Turning wheel:\n";
            bicycle.turnWheel();
            cout << "Riding:\n";
            bicycle.ride();
        }
};

class Component{
    public:
        Component(string companyName){
            cout << "Component contructor\n";
            this->companyName = companyName;
        }
        string companyName;        
};

class Gpu : public Component{
    public:
        Gpu(string companyName) : Component (companyName) {
            cout << "GPU constructor\n";
        }
};

class Memory : public Component{
    public:
        Memory(string companyName) : Component (companyName) {
            cout << "Memory constructor\n";
        }
};

class GraphicCard : public Gpu, public Memory{
    public:
        GraphicCard(string gpuCompanyName, string memotyCompanyName) : Gpu(gpuCompanyName), Memory(memotyCompanyName){
            cout << "Graphic card constructor\n";
        }
};

// diamond-shaped inheritance

class Character{
    public:
        Character(){
            cout << "Character constructor\n";
        }
        int HP;
};

class Orc : public virtual Character{
    public:
        Orc(){
            cout << "Orc constructor\n";
        }
};

class Warrior : public virtual Character{
    public:
        Warrior(){
            cout << "Warrior constructor\n";
        }
};

class OrcWarrior : public Orc, public Warrior{
    public:
        OrcWarrior(){
            cout << "OrcWarrior constructor\n";
        }
};

// we have 2 HP fields!
// class Orc : public virtual Character
// class Warrior : public virtual Character
// if we add virtual we will have 1 HP field

int main(){
    SimpleBicycle sb;
    SportBicycle sb1;
    Human h;
    h.rideOn(sb);
    h.rideOn(sb1);

    GraphicCard gc("AMD", "Samsung");
    OrcWarrior ow;
    return 0;
}