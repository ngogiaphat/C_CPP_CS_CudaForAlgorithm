#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<ctime>
#include<queue>
#include<deque>
#include<vector>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<unordered_set>
#include<unordered_map>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool isDivisibleBy11(long long num){
    ll oddSum = 0, evenSum = 0;
    bool isOdd = true;
    while(num > 0){
        int digit = num % 10;
        if(isOdd){
            oddSum += digit;
        }
        else {
            evenSum += digit;
        };
        num /= 10;
        isOdd = !isOdd;
    };
    return(oddSum - evenSum) % 11 == 0;
};
bool isPossibleDivisibleBy11(long long n, int k){
    if(k == 0)
        return isDivisibleBy11(n);
    int numDigits = log10(n) + 1;
    if(n > 0 && k >= numDigits - 1)
        return true;
    return false;
};
int main(){
    ll n;
    int k;
    cin >> n;
    cin >> k;
    if(isPossibleDivisibleBy11(n, k)){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    };
    return 0;
};