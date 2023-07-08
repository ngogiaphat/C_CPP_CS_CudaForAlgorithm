const readline = require('readline');
const rl = readline.createInterface({
	input: process.stdin,
	output: process.stdout
});
rl.question("Enter the value of n: ", function(n){
	const A = new Array(parseInt(n));
	rl.question("Enter the elements of A: ", function(input){
		const elements = input.split(" ");
		for(let i = 0; i < n; i++){
			A[i] = parseInt(elements[i]);
		}
		let newSize = n;
		for(let i = 0; i < n; i++){
			if(A[i] % 2 == 0){
				newSize++;
			}
		}
		const newArray = new Array(newSize);
		let index = 0;
		for (let i = 0; i < n; i++){
			if(A[i] % 2 == 0){
				newArray[index] = 0;
				index++;
			}
			newArray[index] = A[i];
			index++;
		}
		console.log(newSize);
		for(let i = 0; i < newSize; i++){
			process.stdout.write(newArray[i] + " ");
		}
		rl.close();
	});
});
