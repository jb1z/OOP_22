#include <iostream>
using namespace std;

class Point{
    private:
        int x_;
        int y_;
    public:
        Point(){
            x_ = 0;
            y_ = 0;
        }
        Point(int x, int y){
            x_ = x;
            y_ = y;
        }
        int getX(){
            return x_;
        }
        int getY(){
            return y_;
        }
        void setX(int x){
            x_ = x;
        }
        void setY(int y){
            y_ = y;
        }
        void print(){
            cout << "x = " << x_ << " y = " << y_ << "\n";
        }
        friend void changeX(Point & pointChange); // friend function
        friend void changeY(Point & pointChange); // friend function
};

void changeX(Point & pointChange){
    pointChange.x_ = 0;
}

void changeY(Point & pointChange){
    pointChange.y_ = 0;
}

int main() 
{ 
    Point a(5, 26);
    a.print();
    changeX(a);
    a.print();
    changeY(a);
    a.print();
    return 0;
}