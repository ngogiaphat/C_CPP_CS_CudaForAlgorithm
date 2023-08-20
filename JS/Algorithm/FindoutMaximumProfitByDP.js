function maxProfit(price, n, k){
	// vector to store results of subproblems profit[i] stores maximum profit using at most i transactions up to the current day
	let profit = new Array(k + 1).fill(0);
	let prevDiff = new Array(k + 1).fill(Number.MIN_SAFE_INTEGER);
	// fill the table in bottom-up fashion
	for(let j = 0; j < n; j++){
		for(let i = 1; i <= k; i++){
			prevDiff[i] = Math.max(prevDiff[i], profit[i - 1] - price[j]);
			profit[i] = Math.max(profit[i], price[j] + prevDiff[i]);
		};
	};
	return profit[k];
};
// driver code
let k = 3;
let price = [12, 14, 17, 10, 14, 13, 12, 15];
let n = price.length;
console.log("Maximum profit is: " + maxProfit(price, n, k));
// contributed by phasing17