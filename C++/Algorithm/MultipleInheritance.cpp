#include<iostream>
using namespace std;
// parent to derived class
class A1 {
    public:
        // non virtual function
        void funct1(){
            cout << "A1::funct1() is called";
        };
        // virtual function
        virtual void funct2(int x){
            cout << "A1's val of x: " << x << endl;
        };
        // non virtual function
        void funct3(){
            cout << "A1 is the parent class !" << endl;
        };
};
// second parent to derived class
class A2 {
    public:
        void funct1(){
            cout << "A2::funct1() is called";
        };
        void funct2(int x){
            cout << "A2's val of x: " << x << endl;
        };
        // only virtual function in A2 parent class
        virtual void funct3(){
            cout << "A2 is the parent class !" << endl;
        };
};
// derived class of A1 and A2
class Derived: public A1, public A2 {
    private:
        void funct1(){
            cout << "Derived::funct1() is called";
        };
        void funct2(int x){
            cout << "Derived Class's val of x: " << x << endl;
        };
        void funct3(){
            cout << "Derived::funct3() is called " << "and not Base2::funct3() due" << " to RTP" << endl;
        };
};
int main(){
    Derived d;
    // run time polymorphism in multiple inheritance
    A1 * b1ptr = &d;
    // compile time binding, hence A1::funct1() will be called !
    b1ptr->funct1();
    // virtual function of A1 runTime polymorphism
    b1ptr->funct2(10);
    // now parent class A2 is also pointed to object 'd' of Derived (to demonstrate RTP)
    A2 * b2ptr = &d;
    // virtual function of A2 run time polymorphism
    b2ptr->funct3();
    return 0;
};