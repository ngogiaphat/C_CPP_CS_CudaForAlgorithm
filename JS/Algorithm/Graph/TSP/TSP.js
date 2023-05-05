const N = Infinity;
const n = 4;
const dist = [
  [0, 20, 42, 25],
  [20, 0, 30, 34],
  [42, 30, 0, 10],
  [25, 34, 10, 0]
];
let v = [];
function min(a, b){
  return (a < b) ? a : b;
}
function tsp(s){
  for (let i = 0; i < n; i++){
    if (i !== s){
      v.push(i);
    }
  }
  let minPath = N;
  do {
    let curPath = 0;
    let k = s;
    for (let i = 0; i < v.length; i++){
      curPath += dist[k][v[i]];
      k = v[i];
    }
    curPath += dist[k][s];
    minPath = min(minPath, curPath);
  } 
  while (nextPermutation(v));
  return minPath;
}
function nextPermutation(nums){
  let i = nums.length - 2;
  while (i >= 0 && nums[i] >= nums[i + 1]){
    i--;
  }
  if (i < 0){
    return false;
  }
  let j = nums.length - 1;
  while (nums[j] <= nums[i]){
    j--;
  }
  swap(nums, i, j);
  reverse(nums, i + 1, nums.length - 1);
  return true;
}
function swap(nums, i, j){
  let temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}
function reverse(nums, l, r){
  while (l < r){
    swap(nums, l, r);
    l++;
    r--;
  }
}
let s = 0;
console.log(tsp(s));