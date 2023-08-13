#include<bits/stdc++.h>
using namespace std;
bool CheckingBracket(const string& string){
    std:stack<char> stack_bracket;
    for(char c: string){
        if(c == '(' || c == '[' || c == '{'){
            stack_bracket.push(c);
        }
        else if(c == ')' || c == ']' || c == '}'){
            if(stack_bracket.empty()){
                // if the stack is empty and the closing bracket is met, it is invalid
                return false;
            }
            else if((c ==')' && stack_bracket.top() == '(') || (c ==']' && stack_bracket.top() == '[') || (c =='}' && stack_bracket.top() == '{')){
                // if a closing brace is encountered or matches an opening parenthesis on the top of the stack, remove it from the stack
                stack_bracket.pop();
            }
            else {
                return false;
                // if the closing bracket does not match the opening bracket on the top of the stack, it is invalid
            };
        };
    };
    // finally, if the stack is empty, it is valid
    return stack_bracket.empty(); 
};
int main(){
    string string;
    cout << "Enter the string containing the brackets: ";
    getline(cin, string);
    if(CheckingBracket(string)){
        cout << "The string is valid" << endl;
    }
    else {
        cout << "The string is invalid" << endl;
    };
    return 0;
};