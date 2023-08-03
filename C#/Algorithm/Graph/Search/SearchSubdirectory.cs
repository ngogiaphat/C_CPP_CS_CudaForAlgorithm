using System;
using System.IO;
class GFG {
	static void Main(){
		// Here we search the file present in C drive and GFG directory. Using SearchOption
		string[] list = Directory.GetFiles("C:\\GFG\\", "*.*", SearchOption.AllDirectories);
		string value = "GFG.txt"; // File to be searched
		int flag = 0;
		// Search the file names
		// Present in the A directory
		foreach(string file in list){
			if(file == value){
				flag = 1;
				break;
			}
		};
		if(flag == 1){
			Console.WriteLine("yes");
		}
		else {
			Console.WriteLine("no");
		};
	};
};