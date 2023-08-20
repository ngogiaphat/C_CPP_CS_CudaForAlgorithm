#include<iostream>
int main(){
    int n;
    std::cin >> n;
    int count10 = 0, count5 = 0, count2 = 0, count1 = 0;
    count10 = n / 10;
    n -= count10 * 10;
    count5 = n / 5;
    n -= count5 * 5;
    count2 = n / 2;
    n -= count2 * 2;
    count1 = n;
    std::cout << count10 << " " << count5 << " " << count2 << " " << count1 << std::endl;
    return 0;
}