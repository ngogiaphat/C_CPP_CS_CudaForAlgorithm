#include<vector>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<numeric>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// teturns true if the given number is Abundant
bool isAbundantNumber(int n){
	// to store the sum of divisors
	int sum = 1;
	// loop through the numbers [2,sqrt(n)]
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			if(i * i != n){
				sum += i + n / i;
			}
            else {
				sum += i;
			};
		};
	};
	// a number n is said to be Abundant Number if sum of all the proper divisors of the number is greater than the value of the number n.
	if(sum > n){
		return true;
	}
	else {
		return false;
	};
};
// Function to find all abundant numbers up to n using DP
vector<int> getAllAbundantNumbers(int n){
	vector<int> abundantNumbers;
	vector<int> dp(n + 1, 0);
	// calculate the sum of divisors for all numbers [1, n]
	for(int i = 1; i <= n; i++){
		for(int j = i * 2; j <= n; j += i){
			dp[j] += i;
		};
	};
	// find all abundant numbers up to n
	for(int i = 12; i <= n; i++){
		if(dp[i] > i){
			abundantNumbers.push_back(i);
		};
	};
	return abundantNumbers;
};
// driver program
int main(){
	// check if 12 is an abundant number
	if(isAbundantNumber(12)){
		cout << "YES" << endl;
	}
    else {
		cout << "NO" << endl;
	};
	return 0;
};