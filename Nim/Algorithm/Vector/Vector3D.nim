import math
proc sumArrays(arr1, arr2: array[array[float64, 3], 1]): array[array[float64, 3], 1] = var result: array[array[float64, 3], 1]
    for i in 0..<arr1.len:
        for j in 0..<arr1[0].len:
            for k in 0..<arr1[0][0].len:
                result[i][j][k] = arr1[i][j][k] + arr2[i][j][k]
    return result
var vector1 = [
    [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]], 
    [[9.0, 8.0, 7.0], [6.0, 5.0, 4.0], [3.0, 2.0, 1.0]]
]
var vector2 = [
    [[-1.0, -2.0, -3.0], [-4.0, -5.0, -6.0], [-7.0, -8.0, -9.0]], 
    [[-9.0, -8.0, -7.0], [-6.0, -5.0, -4.0], [-3.0, -2.0, -1.0]]
]
var result = sumArrays(vector1, vector2)
echo "Tổng hai vector:"
for i in 0..<result.len:
    for j in 0..<result[0].len:
        for k in 0..<result[0][0].len:
            echo result[i][j][k]
        echo ""
    echo ""