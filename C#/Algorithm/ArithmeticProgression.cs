using System;
class RETH {
    static int MAX = 1000001;
    // function to find number of AP subsequences in the given array
    static int numofAP(int[]a, int n){
        // initializing the minimum value and maximum value of the array
        int minarr = +2147483647;
        int maxarr = -2147483648;
        int i;
        // finding the minimum and maximum value of the array
        for(int i = 0; i < n; i++){
            minarr = Math.Min(minarr, a[i]);
            maxarr = Math.Max(maxarr, a[i]);
        };
        int[]dp = new int[n];
        int[]sum = new int[MAX];
        // initialize answer with n+1 as single elements and empty array are alse Dynamic Progamming
        int ans = n + 1;
        // traversing with all common difference
        for(int d = (minarr - maxarr); d <= (maxarr - minarr); d++){
            dp[i] = 1;
            // adding counts of Arithmetic Progression with given difference and a[i] is last element. We consider all Arithmetic Progression where an array element is previous element of AP with a particular difference
            if(a[i] - d >= 1 && a[i] - d <= 1000000)
                dp[i] += sum[a[i] - d];
            ans += dp[i] - 1;
            sum[a[i]] += dp[i];
        };
        return ans;
    };
    // driver code
    public static void Main(){
        int[]arr = {1, 2, 3};
        int = arr.Length;
        Console.WriteLine(numfAP(arr, n));
    };
};