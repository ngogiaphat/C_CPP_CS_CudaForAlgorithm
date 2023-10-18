#include<iostream>
using namespace std;
// base class
class shape {
    public:
        string name;
        int sides;
        // constructor
        shape(string name, int sides){
            // this's pointer
            this->name = name;
            this->sides = sides;
        };
};
// mode is public
class triangle: public shape {
    private:
        int base;
        int height;
    public:
        // shape constructor taking arguments from triagle constructor
        triangle(string name, int sides, int base, int height): shape(name, sides){
            this -> base = base;
            this -> height = height;
        };
        void area(){
            cout << "area of triagle: " << (0.5*base*height) << endl;
        };
        void details(){
            cout << "shape is: " << name << endl;
            cout << "no. of sides are: " << sides << endl;
            cout << "base is: " << base << endl;
            cout << "height is: " << height << endl;
            // calling area function
            area();
        };

};
// derived class
class square: public shape {
    private:
        int hight;
    public:
        // shape constructor taking arguments from square constructor
        square(string name, int sides, int side): shape(name, sides){
            this->hight = hight;
        };
        void area(){
            cout << "area of square: " << (hight * hight) << endl;
        };
        void details(){
            cout << "shape is: " << name << endl;
            cout << "no. of sides are: " << sides << endl;
            cout << "side is: " << hight << endl;
            // calling area function
            area();
        };
};
int main(){
    // creating object of triangle class
    triangle tri("triangle", 3, 10, 20);
    square s("square", 4, 10);
    tri.details();
    cout << endl << endl;
    s.details();
    return 0;
};