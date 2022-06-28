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
    return 0;
}