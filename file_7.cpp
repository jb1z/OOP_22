#include <iostream>
using namespace std;

class Weapon{
    public:
        virtual void shoot() = 0; // pure virtual method
        void Fun(){
            cout << "Fun func!\n";
        }
};

class Gun : public Weapon{
    public:
        void shoot() override{
            cout << "Bang!\n";
        }
};

class MachineGun : public Gun{
    public:
        void shoot() override{
            cout << "Bang! Bang! Bang!\n";
        }
};

class Bazooka : public Weapon{
    public:
        void shoot() override{
            cout << "BOOM!\n";
        }
};

class Knife : public Weapon{
    public:
        void shoot() override{
            cout << "Cut!\n";
        }
};

class Player{
    public:
        void shoot(Weapon *weapon){
            weapon->shoot();
        }
};

class A{
    public: 
        A(){
            cout << "Memory allocated A \n";
        }
        virtual ~A(){
            cout << "Memory released A \n";
        }
};

class B : public A{
    public: 
        B(){
            cout << "Memory allocated B \n";
        }
        ~B() override{
            cout << "Memory released B \n";
        }
};

class C{
    public: 
        C(){
            cout << "Memory allocated C \n";
        }
        virtual ~C() = 0;
};

C::~C(){}; // !!! making virtual destructor like this

class D : public C{
    public: 
        D(){
            cout << "Memory allocated D \n";
        }
        ~D() override{
            cout << "Memory released D \n";
        }
};

int main(){
    Player player;
    Knife knife;
    Gun gun;
    MachineGun machineGun;
    Bazooka bazooka;
    player.shoot(&knife);
    player.shoot(&gun);
    player.shoot(&machineGun);
    player.shoot(&bazooka);
    knife.Fun();
    gun.Fun();
    machineGun.Fun();
    bazooka.Fun();

    A *bptr = new B;
    delete bptr;
    // we only release memory by A destructor, without B destructor
    // we should make ~A() - virtual
    // we need virtual destructor for a correct memory release

    //C c; we cant create an C object 
    C *d = new D;
    delete d; 
    return 0;
}