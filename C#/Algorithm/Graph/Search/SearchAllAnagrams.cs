using System;
class GFG {
	public const int MAX = 256;
	// This function returns true if contents of arr1[] and arr2[] are same, otherwise false.
	public static bool compare(char[] arr1, char[] arr2){
		for(int i = 0; i < MAX; i++){
			if(arr1[i] != arr2[i]){
				return false;
			};
		};
		return true;
	};
	// This function search for all permutations of pat[] in txt[]
	public static void search(string pat, string txt){
		int M = pat.Length;
		int N = txt.Length;
		// countP[]: Store count of all
		// characters of pattern
		// countTW[]: Store count of current
		// window of text
		char[] countP = new char[MAX];
		char[] countTW = new char[MAX];
		for(int i = 0; i < M; i++){
			(countP[pat[i]])++;
			(countTW[txt[i]])++;
		};
		// Traverse through remaining characters of pattern
		for(int i = M; i < N; i++){
			// Compare counts of current window of text with counts of pattern[]
			if(compare(countP, countTW)){
				Console.WriteLine("Found at Index " + (i - M));
			};
			// Add current character to current window
			(countTW[txt[i]])++;
			// Remove the first character of previous window
			countTW[txt[i - M]]--;
		};
		// Check for the last window in text
		if(compare(countP, countTW)){
			Console.WriteLine("Found at Index " + (N - M));
		};
	};
	// Driver Code
	public static void Main(string[] args){
		string txt = "BACDGABCDA";
		string pat = "ABCD";
		search(pat, txt);
	};
};
// This code is contributed by Shrikant1