#include <iostream>
int main() {
    int a = 5;
    int b = 10;
    int *ptr_a = &a;
    int *ptr_b = &b;
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    int temp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = temp;
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    return 0;
}
