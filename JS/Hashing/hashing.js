function hashCode(obj){
  let hash = 0;
  const str = JSON.stringify(obj);
  for(let i = 0; i < str.length; i++){
    hash = (hash << 5) - hash + str.charCodeAt(i);
    hash |= 0; // Convert to 32bit integer
  }
  return hash;
}
const person = {
  name: "John",
  age: 30,
  city: "New York"
};
const hashValue = hashCode(person);
console.log(hashValue);