let n;
	n = parseInt(prompt('Enter a number:'));
let count10 = 0, count5 = 0, count2 = 0, count1 = 0;
	count10 = Math.floor(n / 10);
	n -= count10 * 10;
	count5 = Math.floor(n / 5);
	n -= count5 * 5;
	count2 = Math.floor(n / 2);
	n -= count2 * 2;
	count1 = n;
console.log(count10 + " " + count5 + " " + count2 + " " + count1);