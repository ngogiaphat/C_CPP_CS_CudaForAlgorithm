#include<bits/stdc++.h>
using namespace std;
bool CheckStringReverseByStack(string str){
    stack<char> myStack;
    for(char ch: str){
        myStack.push(ch);
    }
    // character compare from pop() and character from root string
    while(!myStack.empty()){
        if(myStack.top() != str.front()){
            return false;
        };
        myStack.pop();
        // remove first character of string
        str.erase(str.begin());
    };
    return true;
};
int main(){
    string str;
    cout << "Enter string: ";
    cin >> str;
    if(CheckStringReverseByStack(str)){
        cout << "String is reverse by stack";
    }
    else {
        cout << "String is not reverse by stack" << endl;
    }
    return 0;
};