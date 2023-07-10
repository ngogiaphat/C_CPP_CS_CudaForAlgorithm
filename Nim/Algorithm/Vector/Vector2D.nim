import math 
proc sumArrays(arr1, arr2: array[float64, 2]) : array[float64, 2] = var result: array[float64, 2]
    for i in 0..<arr1.len:
        for j in 0..<arr1[0].len:
            result[i][j] = arr1[i][j] + arr2[i][j]
    return result
var vector1 = [
    [1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]
]
var vector2 = [
    [9.0, 8.0, 7.0], [6.0, 5.0, 4.0], [3.0, 2.0, 1.0]
]
var result = sumArrays(vector1, vector2)
echo "Total 2 vector:"
for i in 0..<result.len:
    for j in 0..<result[0].len:
        echo result[i][j]
    echo ""