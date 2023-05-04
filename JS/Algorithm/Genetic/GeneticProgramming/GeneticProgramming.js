function longestIncreasingSubsequence(arr) {
    //Initialize array dp with length equal to array arr and initial value is 1
    const dp = new Array(arr.length).fill(1);
    for (let i = 1; i < arr.length; i++) {
      for (let j = 0; j < i; j++) {
        if (arr[i] > arr[j]) {
          dp[i] = Math.max(dp[i], dp[j] + 1);
        }
      }
    }
    //Find the maximum value in the array dp
    let max = 0;
    for (let i = 0; i < dp.length; i++) {
      if (dp[i] > max) {
        max = dp[i];
      }
    }
    return max;
  }
  //Example
  const arr = [10, 22, 9, 33, 21, 50, 41, 60];
  const lis = longestIncreasingSubsequence(arr);
  console.log(lis); 