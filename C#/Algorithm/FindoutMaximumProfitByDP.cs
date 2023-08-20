// C# progarm to find out maximum profit by buying & selling a share atmost k times given stock price of n days
using System;
class H32 {
    static int maxProfit(int[] price, int n, int k){
        // table to store results of subproblems, ptrofit[t][i] stores maximum profit using atmost t transactions up to day i (including day i)
        int[, ] profit = new int[k+1, n+1];
        // for day 0, you can't arn money irrespective of how many times you trades
        for(int i = 0; i <= k; i++)
            profit[i, 0] = 0;
        // profit is 0 if we don't do any transactions
        for(int j = 0; j <= n; j++)
            profit[0, j] = 0;
        // fill the table in bottom-up fashion
        for(int i =1; i <= k; i++){
            int prevDiff = int.MinValue;
            for(int j = 1; j < n; j++){
                prevDiff = Math.Max(prevDiff, profit[i - 1, j - 1] - price[j - 1]);
                profit[i, j] = Math.Max(profit[i, j - 1], price[j] + prevDiff);
            };
        };
        return profit[k, n - 1];
    };
    // driver code to test above
    public static void Main(){
        int k = 3;
        int[] price = {12, 14, 17, 10, 14, 13, 12, 15};
        int n = price.Length;
        Console.Write("Maximum profit is: " + maxProfit(price, n, k));
    };
};
// Cre: Sam007 on GeeksforGeeks