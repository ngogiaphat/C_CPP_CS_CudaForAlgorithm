#include <iostream>
int main(){
    int n;
    std::cin >> n;
    int a, b;
    if(n >= 0){
        a = n;
        b = 0;
    } 
    else {
        a = 0;
        b = n;
    }
    std::cout << a << " " << b << std::endl;
    return 0;
}