using System;
using System.Collections.Generic;
class RETH {
    static int B;
    static List<int> A;
    static int[, , ] dp = new int[702, 502, 2];
    static int solve(int j, int i, int b){
        // if the result has already been calculated return that result
        if(dp[i, j, b] != -1)
            return dp[i, j, b];
        // if i has reached the end of the array return 0
        if(i == B)
            return 0;
        // if we have exhausted the number of transactions return 0
        if(j == 0)
            return 0;
        int res;
        // if we are to buy stocks
        if(b == 1)
            res = Math.Max(-A[i] + solve(j, i, + 1, 0), solve(j, i + 1, 1));
        // if we're to sell stock and complete 1 transaction
        else
            res = Math.Max(A[i] + solve(j - 1, i + 1, 1), solve(j, i + 1, 0));
        // return the result
        return dp[i, j, b] = res;
    };
    static int maxProfit(int K, int N, int[] C){
        A = new List<int>();
        // copying C to global A
        for(int i = 0; i < N; i++){
            A.Add(C[i]);
        };
        // initializing Dynamic Programming with -1
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= K; j++){
                dp[i, j, 1] = -1;
                dp[i, j, 0] = -1;
            };
        };
        // copying n to global B
        B = N;
        return solve(K, 0, 1);
    };
    // driver code
    public static void Main(string[] args){
        // test 1
        int k1 = 3;
        int[] price1 = {12, 14, 17, 10, 14, 13, 12, 15};
        int n1 = price1.Length;
        Console.WriteLine("Maximum profit is: " + maxProfit(k1, n1, price1));
        // test 2
        int k2 = 2;
        int[] price2 = {10, 22, 5, 75, 65, 80};
        int n2 = price2.Length;
        Console.WriteLine("Maximum profit is: " + maxProfit(k2, n2, price2));
    };
};