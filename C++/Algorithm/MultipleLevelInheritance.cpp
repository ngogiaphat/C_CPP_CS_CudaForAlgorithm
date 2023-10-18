#include<iostream>
using namespace std;
// parent class
class A1 {
    public:
        // virtual function
        virtual void funct1(){
            cout << "A1::funct1() is called";
        };
        // virtual function
        virtual void funct2(int x){
            cout << "A1 val of x: " << x << endl;
        };
        // non virtual function
        void funct3(){
            cout << "A1 is the parent class !" << endl;
        };
};
// Derived Class of A1 but parent to A3
class A2: public A1 {
    // virtual function can be private !
    private:
        void funct1(){
            cout << "A2::funct1() is called";
        };
        void funct2(int x){
            cout << "A2's val of x: " << x << endl;
        };
        void funct3(){
            cout << "A2 is the first" << "Derived class !" << endl;
        };
};
// Derived Class of A2 but parent to Derived
class A3: public A2 {
    private:
        void funct1(){
            cout << "A3::funct1() is called";
        };
        void funct2(int x){
            cout << "A3's val of x: " << x << endl;
        };
        void funct3(){
            cout << "Class A3 is second" << "Derived class !" << endl;
        };
};
// 3 levels of multi level inheritance and final child class
class Derived : public A3 {
    private:
        void funct1(){
            cout << "Derived::funct1() is called";
        };
        void funct2(int x){
            cout << "Derived Class's Val of x:" << x << endl;
        };
        void funct3(){
            cout << "Class Derived is Final" << " Child class !" << endl;
        };
};
int main(){
    // run time polymorphism in multi level inheritance
    A1 * b1ptr = new Derived;
    b1ptr->funct1();
    b1ptr->funct2(30);
    // compile time binding
    b1ptr->funct3();
    return 0;
};