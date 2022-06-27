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



int main(){
    Image image;
    image.getImageInfo();   
    return 0;
}