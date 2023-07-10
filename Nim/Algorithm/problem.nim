proc hanoi(n: int, fromPeg, toPeg, auxPeg: string) = if n > 0:
    hanoi(n - 1, fromPeg, auxPeg, toPeg)
    echo("Move disk ", n, " from ", fromPeg, " to ", toPeg)
    hanoi(n - 1, auxPeg, toPeg, fromPeg)
var n: int 
echo("Enter number of disks: ")
readLine(n)
hanoi(n, "A", "C", "B")