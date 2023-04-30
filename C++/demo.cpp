#include<iostream>
using namespace std;
int main()
{
    int n0 = 5;
    int n1= 6;
    int n2 = 10;
    int *p = &n1;
    *p = 9;
    //
    cout << *p << endl;
    p = p + 1;
    //*p = 15;
    cout << *p;
   //p--;
    // p--;
    // *p = 3;
    // cout << *p;
    //
    //
    //
}