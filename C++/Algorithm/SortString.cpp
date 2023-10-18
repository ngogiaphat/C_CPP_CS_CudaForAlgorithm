#include<bits/stdc++.h>
using namespace std;
void SortStringUsingStack(string& inputStr){
    stack<char> sotedStack;
    // put each character of the string on the stack
    for(char c: inputStr){
        sotedStack.push(c);
    };
    // delete character from string
    inputStr.clear();
    // get character from stack and add to deleted string
    while(!sotedStack.empty()){
        inputStr.push_back(sotedStack.top());
        sotedStack.pop();
    };
};
int main(){
    string input = "stack";
    SortStringUsingStack(input);
    cout << "Sorted string" << input << endl;
    return 0;
};