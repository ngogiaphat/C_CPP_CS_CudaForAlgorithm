#include<bits/stdc++.h>
using namespace std;
void convertToBase(int n, int base){
    stack<int> s;
    // convert factor
    while(n > 0){
        s.push(n%base);
        n = n/base;
    };
    // print result from stack
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << endl;
};
int main(){
    // number need convert
    int num = 27;
    // base need convert
    int base = 2;
    convertToBase(num, base);
    return 0;
};