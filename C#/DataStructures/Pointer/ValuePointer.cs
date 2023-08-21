unsafe {
    int x = 10;
    int* ptr = &x; //Declare pointer ptr to variable x
    Console.WriteLine("Value of var x: " + x);
    Console.WriteLine("Add of var x: " + (int)ptr);
    Console.WriteLine("Value of variable x through pointer y ptr: " + *ptr);
};