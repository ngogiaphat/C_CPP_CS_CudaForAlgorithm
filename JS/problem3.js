const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
rl.question('Enter the value of n: ', (n) => {
  const A = new Array(Number(n));
  console.log('Enter the array elements:');  
  rl.on('line', (input) => {
    const numbers = input.split(' ');
    if(numbers.length === A.length) {
      for(let i = 0; i < A.length; i++){
        A[i] = Number(numbers[i]);
      }
      rl.close();
      let newSize = A.length;
      for(let i = 0; i < A.length; i++){
        if(A[i] % 2 === 0){
          newSize++;
        }
      }
      const newArray = new Array(newSize);
      let index = 0;
      for(let i = 0; i < A.length; i++){
        if(A[i] % 2 === 0){
          newArray[index] = 0;
          index++;
        }
        newArray[index] = A[i];
        index++;
      }
      console.log(newSize);
      console.log(newArray.join(' '));
    } 
		else {
      console.log('Invalid input. Please enter correct number of array elements.');
    }
  });
});
