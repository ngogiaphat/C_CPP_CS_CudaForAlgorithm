#include<bits/stdc++.h>
using namespace std;
bool isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'){
        return true;
    }
    return false;
};
int calculate(char op, int num1, int num2){
    switch(op){
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1*num2;
        case '/':
            return num1/num2;
        case '^':
            return pow(num1,num2);
        default:
            return 0;
    }
};
int evaluatePostfix(string postfix){
    stack<int> operands;
    for(char ch: postfix){
        if(isOperator(ch)){
            int num2 = operands.top();
            operands.pop();
            int num1 = operands.top();
            operands.pop();
            int result = calculate(ch, num1, num2);
            operands.push(result);
        }
        else {
            operands.push(ch-'0');
        };
    };
    return operands.top();
};
int main(){
    string postfix = "231*+";
    int result = evaluatePostfix(postfix);
    cout<< "The result is: " << result << endl;
    return 0;
};