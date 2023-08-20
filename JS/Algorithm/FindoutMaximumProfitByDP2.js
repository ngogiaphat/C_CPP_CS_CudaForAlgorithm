let B;
let A = [];
let dp = new Array(501);
for(let i = 0; i < 501; i++){
	dp[i] = new Array(201);
	for(let j = 0; j < 201; j++)
		dp[i][j] = new Array(2);
};
function solve(j, i, b){
	// if the result has already been calculated return that result
	if(dp[i][j][b] != -1)
		return dp[i][j][b];
	// if i has reached the end of the array return 0
	if(i == B)
		return 0;
	// if we have exhausted the number of transaction return 0
	if(j == 0)
		return 0;
	let res;
	// if we're to buy stocks
	if(b == 1)
		res = Math.max(-A[i] + solve(j, i + 1, 0), solve(j, i + 1, 1));
	// if we're to sell stock and complete one transaction
	else
		res = Math.max(A[i] + solve(j - 1, i + 1, 1), solve(j, i + 1, 0));
	// return the result
	return dp[i][j][b] = res;
};
function maxProfit(K, N, C){
	A = new Array(N).fill(0);
	// copying C to global A
	for(i = 0; i < N; i++)
		A[i] = C[i];
	// initializing Dynamic Programming with -1
	for(i = 0; i <= N; i++)
		for(j = 0; j <= K; j++){
			dp[i][j][1] = -1;
			dp[i][j][0] = -1;
		}
	// copying n to global B
	B = N;
	return solve(K, 0, 1);
};
// driver code
// test 1
let k1 = 3;
let price1 = [12, 14, 17, 10, 14, 13, 12, 15];
let n1 = price1.length;
console.log("Maximum profit is: " + maxProfit(k1, n1, price1));
// test 2
let k2 = 2;
let price2 = [10, 22, 5, 75, 65, 80];
let n2 = price2.length;
console.log("Maximum profit is: " + maxProfit(k2, n2, price2));
// contributed by phasing17