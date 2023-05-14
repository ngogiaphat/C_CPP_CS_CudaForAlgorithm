#include <iostream>
#include <vector>
using namespace std;
int main() {
    //Initialize vector of int type
    vector<int> numbers {1, 2, 3, 4, 5};
    //Initialize vector iterator to point to the first element
    vector<int>::iterator itr = numbers.begin();
    cout << "First Element: " << *itr << "  "<<endl;
    //Change iterator to point to the last element
    itr = numbers.end() - 1;
    cout << "Last Element: " << *itr;
    return 0;  
}