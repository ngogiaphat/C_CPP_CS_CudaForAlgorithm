#include <iostream>
using namespace std;
//Declare class Point
class Point {
    //Private data members
    private:
        int x, y; 
    public:
        //Constructor
        Point(int a, int b) {
            x = a;
            y = b;
        }
        //Getter methods
        int getX() const {
            return x;
        }
        int getY() const {
            return y;
        }
        //Setter methods
        void setX(int a) {
            x = a;
        }
        void setY(int b) {
            y = b;
        }
        //Print method
        void print() const {
            cout << "(" << x << "," << y << ")" << endl;
        }
};
//Funtion main
int main() {
    //Create object p of class Point
    Point p(1, 2);
    //Use method print of class Point
    p.print();
    //Use method setX of class Point
    p.setX(3);
    //Use method setY of class Point
    p.setY(4);
    //Use method print of class Point
    p.print();
    return 0;
}