using System;
using System.Collections.Generic;
class GFG {
	// Main Method
	public static void Main(){
		// List creation
		List<string> Reth = new List<string>();
		// List elements
        Reth.Add("ABCD");
        Reth.Add("QRST");
        Reth.Add("XYZ");
        Reth.Add("IJKL");
		Console.WriteLine("The Original List is:");
		foreach(string g in Reth){
			// prints original List
			Console.WriteLine(g);
		};
		Console.WriteLine("\nThe List in Sorted form");
		// sort the List
	    Reth.Sort();
		Console.WriteLine();
		foreach(string g in Reth){
			// prints the sorted List
			Console.WriteLine(g);
		};
		Console.WriteLine("\nInsert EFGH :");
		// insert "EFGH" in the List
		//"EFGH" insert into its original
		// position when the List is sorted
		int index = Reth.BinarySearch("EFGH");
		if(index < 0){
            Reth.Insert(~index, "EFGH");
		};
		Console.WriteLine();
		foreach(string g in Reth){
			// prints the sorted list
			// after inserting "EFGH"
			Console.WriteLine(g);
		};
	};
};