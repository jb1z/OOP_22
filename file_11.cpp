#include <iostream>
using namespace std;

class Pc{
    public:
        enum PcStates{ // enumeration
            OFF,
            ON,
            SLEEP
        };
        void setState(PcStates state){
            state_ = state;
        }
        PcStates getState(){
            return state_;
        }
    private:
        PcStates state_;
};

enum Speed{
    MIN = 150,
    RECOMMEND = 600,
    MAX = 800
};

int main(){
    Pc pc;
    Pc::PcStates states;
    states = Pc::PcStates::OFF; // OFF = 0
    states = Pc::PcStates::ON; // ON = 1
    states = Pc::PcStates::SLEEP; // SLEEP = 2
    pc.setState(Pc::PcStates::OFF);
    cout << pc.getState() << "\n";

    // by if/else
    if(pc.getState() == Pc::PcStates::OFF) cout << "PC is off!\n";
    else if(pc.getState() == Pc::PcStates::ON) cout << "PC is on!\n";
    else cout << "PC is sleeping!\n";

    // by switch/case
    switch (pc.getState()){
        case Pc::PcStates::OFF:
            cout << "PC is off!\n";
            break;
        case Pc::PcStates::ON:
            cout << "PC is on!\n";
            break;
        case Pc::PcStates::SLEEP:
            cout << "PC is sleeping!\n";
            break;
    }

    Speed speed = Speed::MAX;
    cout << speed << "\n";
    return 0;
}