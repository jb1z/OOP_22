#include <iostream>
using namespace std;

// these classes cant access each other private information 
class Image{
    private:
        class Pixel{ // inner class
            public:
                Pixel(int r, int g, int b){
                    r_ = r;
                    g_ = g;
                    b_ = b;
                }
                string getInfo(){
                    return "Pixel: r = " + to_string(r_) + " g = " + to_string(g_) + " b = " + to_string(b_) + "\n";
                }
            private:
                int r_;
                int g_;
                int b_;
        };
        static const int LENGTH = 5; // must be static
                                     // we can initialize it here because this field is CONSTANT
        Pixel pixels[LENGTH]
        {Pixel(150, 142, 12), Pixel(10, 12, 12), Pixel(250, 242, 12), Pixel(167, 169, 86), Pixel(123, 255, 208)};
    public:
        void getImageInfo(){
            for(int i = 0; i < LENGTH; i++){
                cout << pixels[i].getInfo();
            }
        }
};

class SecondPixel{
    private:
        int r_;
        int g_;
        int b_;
    public:
        SecondPixel(){
            r_ = 0;
            g_ = 0;
            b_ = 0;
        }
        SecondPixel(int r, int g, int b){
            r_ = r;
            g_ = g;
            b_ = b;
        }
        string getInfo(){
             return "SecondPixel: r = " + to_string(r_) + " g = " + to_string(g_) + " b = " + to_string(b_) + "\n";
        }
};

// we can use Cap not only with Human class - agregation
class Cap{
    private:
        string color_ = "red";
    public:
        string getColor(){
            return color_;
        }
};

class Mannequin{
    public:
        void inspectCap(){
            cout << cap.getColor() << "\n";
        }
    private:
        Cap cap;
};

// we can use Brain only with Human class - composition
class Human{
    public: 
        void think(){
            brain.think(); // delegation
        }
        void inspectCap(){
            cout << cap.getColor() << "\n";
        }
    private:
        class Brain{
            public:
                void think(){
                    cout << "I think!\n";
                }
        };
        Brain brain; // composition
        Cap cap; // agrregation
};



int main(){
    Image image;
    image.getImageInfo();

    SecondPixel pixel2(111,222,231);
    SecondPixel pixelArray[5]; // array of objects
    SecondPixel *dynamicPixelArray  = new SecondPixel[5];

    Human human; 
    human.think();
    human.inspectCap(); // we use cap for Human
    Mannequin mannequin; 
    mannequin.inspectCap(); // we use cap for Mannequin
    delete[] dynamicPixelArray;   
    return 0;
}