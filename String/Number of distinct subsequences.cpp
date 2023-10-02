/*
  Given a string consisting of lower case English alphabets, the task is to find the number of distinct subsequences of the string
Note: Answer can be very large, so, ouput will be answer modulo 109+7.

Example 1:

Input: 
s = "gfg"
Output: 
7
Explanation: 
The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .
Example 2:

Input: 
s = "ggg"
Output: 
4
Explanation: 
The four distinct subsequences are "", "g", "gg", "ggg".
Your task:
You do not need to read any input or print anything. The task is to complete the function distinctSubsequences(), 
which takes a string as input and returns an integer.

Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |s| ≤ 105
s contains lower case English alphabets

*/

// Solution dp
/*
  For unique subsequence if we see repeated character then subtract the subsequence created by that character previously 
  else just twice the previous subsequence.
*/

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int n=s.length();
	    int mod=1000000007;
	    int arr[26]={-1};
	    vector<int>dp(n+1, -1);
	    dp[0]=1;
	    for(int i=0; i<n; i++)
	    {
	        if(arr[s[i]-'a']==-1)
	        {
	            dp[i+1]=(dp[i]*2)%mod;
	        }
	        else
	        {
	            dp[i+1]=(dp[i]*2)%mod-dp[arr[s[i]-'a']-1]+mod; // here mod is added at last because we are subtracting by 
                                                             // dp[arr[s[i]-'a']-1] which might make some values beyond 0 towards 
                                                             // negative way so to add up the negative part we add 1000000007
	        }
	        arr[s[i]-'a']=i+1;
	        dp[i+1]=dp[i+1]%mod;
	    }
	    return dp[n];
	}
};
