/*
Given a string s of length n, find all the possible subsequences of the string s in lexicographically-sorted order.

Example 1:

Input : 
s = "abc"
Output: 
a ab abc ac b bc c
Explanation : 
There are a total 7 number of subsequences possible 
for the given string, and they are mentioned above 
in lexicographically sorted order.
Example 2:

Input: 
s = "aa"
Output: 
a a aa
Explanation : 
There are a total 3 number of subsequences possible 
for the given string, and they are mentioned above 
in lexicographically sorted order.
Your Task:
You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes a 
string s as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from s in 
lexicographically-sorted order.

Expected Time Complexity: O( n*2n  )
Expected Space Complexity: O( n * 2n )

Constraints: 
1 <= n <= 16
s will constitute of lower case english alphabets

*/

// Solution using Recursion. T.C- O(2^n)

class Solution{
	public:
	    void solve(string s, string tmp, int idx, vector<string>&ans)
	    {
	        if(idx>=s.length())
	            return;
	       string t=tmp;
	       t+=s[idx];
	       ans.push_back(t);
	       solve(s, t, idx+1, ans);
	       solve(s, tmp, idx+1, ans);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string>ans;
		    string tmp="";
		    solve(s, tmp, 0, ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};


// Solution using Bitmask. T.C- O(n*2^n)

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n=s.length();
		    vector<string>ans;
		    // In subsequence we can give number to every subsequence from 1 to 2^n-1
		    for(int i=1; i<(1<<n); i++) // value of i=1 to 2^n-1
		    {
		        string tmp="";
		        for(int j=0; j<n; j++) // to check all the set bits in i
		        {
		            if(i&(1<<j))
		            {
		                tmp+=s[j];
		            }
		        }
		        ans.push_back(tmp);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};
