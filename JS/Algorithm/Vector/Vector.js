const vector = [2, 3, 4];
let length = 0;
for(let i = 0; i < vector.length; i++){
   length += vector[i] * vector[i];
}
length = Math.sqrt(length);
console.log('Độ dài của vector là:', length);