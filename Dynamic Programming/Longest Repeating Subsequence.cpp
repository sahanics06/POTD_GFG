/*
Given string str, find the length of the longest repeating subsequence such that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from string str if and only if that ith character has different indices in A and B. 
For example, A = "xax" and B = "xax" then the index of first "x" must be different in the original string for A and B.

Example 1:

Input:
str = "axxzxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x z x y 
0 1 2 3 4 5

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 4  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.
Example 2:

Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y 
0 1 2 3 4

The longest subsequence is "xx". 
It appears twice as explained below.

subsequence A
x x
0 1  <-- index of subsequence A
------
1 2  <-- index of str 


subsequence B
x x
0 1  <-- index of subsequence B
------
2 3  <-- index of str 

We are able to use character 'x' 
(at index 2 in str) in both subsequences
as it appears on index 1 in subsequence A 
and index 0 in subsequence B.

Your Task:
You don't need to read or print anything. Your task is to complete the LongestRepeatingSubsequence() which takes str as input parameter and returns the length of the 
longest repeating subsequnece.


Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)


Constraints:
1 <= |str| <= 103
  */

// Solution using DP. Time- O(N^2). Space- O(N).

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.length();
		    vector<int>down(n+1), cur(n+1);
		    for(int i=n; i>=0; i--)
		    {
		        for(int j=n; j>=0; j--)
		        {
		            if(i==n || j==n)
		            {
		                cur[j]=0;
		            }
		            else if(str[i]==str[j] && i!=j)
		            {
		                cur[j]=1+down[j+1];
		            }
		            else
		            {
		                cur[j]=max(down[j], cur[j+1]);
		            }
		        }
		        down=cur;
		    }
		    return down[0];
		}

};


// Solution using DP. Time- O(N^2). Space- O(N*N).

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n=str.length();
		    vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
		    for(int i=n; i>=0; i--)
		    {
		        for(int j=n; j>=0; j--)
		        {
		            if(i==n || j==n)
		            {
		                dp[i][j]=0;
		            }
		            else if(str[i]==str[j] && i!=j)
		            {
		                dp[i][j]=1+dp[i+1][j+1];
		            }
		            else
		            {
		                dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
		            }
		        }
		    }
		    return dp[0][0];
		}

};


// Solution using Recursion and memoization.

class Solution {
	public:
	    int dp[1001][1001];
	    int solve(string s, int i, int j)
	    {
	        if(i==s.length() || j==s.length())
	            return 0;
	        if(dp[i][j]!=-1)    return dp[i][j];
	        if(s[i]==s[j] && i!=j)
	        {
	            return dp[i][j]=1+solve(s, i+1, j+1);
	        }
	        return dp[i][j]=max(solve(s, i, j+1), solve(s, i+1, j));
	    }
		int LongestRepeatingSubsequence(string str){
		    int n=str.length();
		    //vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
		    memset(dp, -1, sizeof(dp));
		    return solve(str, 0, 0);
		}

};

// Solution using Recursion. TLE. O(2^N)

class Solution {
	public:
	    int solve(string s, int i, int j)
	    {
	        if(i==s.length() || j==s.length())
	            return 0;
	        if(s[i]==s[j] && i!=j)
	        {
	            return 1+solve(s, i+1, j+1);
	        }
	        return max(solve(s, i, j+1), solve(s, i+1, j));
	    }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    return solve(str, 0, 0);
		}

};
