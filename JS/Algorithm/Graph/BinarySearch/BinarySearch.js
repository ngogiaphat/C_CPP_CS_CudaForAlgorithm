function binarySearch(arr, target){
    let left = 0;
    let right = arr.length - 1;
    while (left <= right){
      let mid = Math.floor((left + right) / 2);
      if(arr[mid] === target){
        return mid;
      } 
      else if (arr[mid] < target){
        left = mid + 1;
      } 
      else {
        right = mid - 1;
      }
    }
    return -1;   
    //When target is not found in array arr, return -1
  }
  //Example of using the algorithm Binary Search
  const arr = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91];
  const target = 23;
  const result = binarySearch(arr, target);
  console.log("Kết quả tìm kiếm: " + result);      
  //Results returned: 5  