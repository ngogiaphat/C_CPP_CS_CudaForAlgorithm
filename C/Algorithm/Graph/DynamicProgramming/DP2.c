#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int x, int y, int z){
	if(x < y && x < z)
		return x;
	else if(y < x && y < z)
		return y;
	else
		return z;
};
int minDis(char* s1, char* s2, int n, int m){
	int dp[n + 1][m + 1];
	// Fill dp[][] table in bottom up manner
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			// If first string is empty, only option is to insert all characters of second string
			if(i == 0)
				dp[i][j] = j;
			// If second string is empty, only option is to remove all characters of second string
			else if(j == 0)
				dp[i][j] = i;
			// If last characters are same, ignore last char and recur for remaining string
			else if(s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			// If last character are different, consider all possibilities and find minimum
			else
				dp[i][j] = 1 + min(
                    dp[i][j - 1], // Insert
                    dp[i - 1][j], // Remove
                    dp[i - 1][j - 1] // Replace
                );
		};
	};
	return dp[n][m];
};
int main(){
	char* str1 = "voldemort";
	char* str2 = "dumbledore";
	int n = strlen(str1), m = strlen(str2);
	printf("%d", minDis(str1, str2, n, m));
	return 0;
};