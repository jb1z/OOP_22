#include <iostream>
using namespace std;

class Gun{
    public:
        virtual void shoot(){
            cout << "Bang!\n"; 
        }
};

class MachineGun : public Gun{
    public:
        void shoot() override{
            cout << "Bang! Bang! Bang!\n"; 
        }
};

class Player{
    public:
        void shoot(Gun *gun){
            gun->shoot();
        }
};

int main(){
    Gun gun;
    gun.shoot();
    MachineGun machineGun;
    machineGun.shoot();

    // pointer of base class type could point to the object of base class or to the object of inherited class (from base which considered)
    Gun gun1;
    Gun *weapon1 = &gun1;
    weapon1->shoot(); // Bang!
    //
    MachineGun gun2;
    Gun *weapon2 = &gun2;
    weapon2->shoot(); // Bang! Bang! Bang!
    // called methods are determined by "object" type!

    // if we dont use virtual:
    /*class Gun{
    public:
        void shoot(){
            cout << "Bang!\n"; 
        }
    };

    class MachineGun : public Gun{
    public:
        void shoot(){
            cout << "Bang! Bang! Bang!\n"; 
        }
    };*/ 
    // we will have another results for same function calling:
    /*weapon1->shoot(); // Bang!
    weapon2->shoot(); // Bang!*/
    // called methods are determined by "pointer" type!

    Player player1;
    player1.shoot(weapon1);
    Player player2;
    player2.shoot(weapon2);
    // we can hand over to method objects of both class, when shoot() method in Player accept a pointer to Gun
    // and we will see different realisation depends on object type!
    return 0;
}