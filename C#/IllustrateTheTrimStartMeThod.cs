using System;
class RETH {
	// Main Method
	public static void Main(){
		// string to be trimmed
		string s1 = "*****0000abc000****";
		char[] charsToTrim1 = {
            '*',
            '0'
        };
		// string to be trimmed
		string s2 = " abc";
		string s3 = " -RETH-";
		string s4 = " RethforMe";
		// Before TrimStart method call
		Console.WriteLine("Before:");
		Console.WriteLine(s1);
		Console.WriteLine(s2);
		Console.WriteLine(s3);
		Console.WriteLine(s4);
		Console.WriteLine("");
		// After TrimStart method call
		Console.WriteLine("After:");
		// argument as char array
		Console.WriteLine(s1.TrimStart(charsToTrim1));
		Console.WriteLine(s2.TrimStart());
		// White space is not remove
		Console.WriteLine(s3.TrimStart('-'));
		// not take char array but Argument only character
		Console.WriteLine(s4.TrimStart(' ', 'R', 'E', 'T', 'H'));
	};
};