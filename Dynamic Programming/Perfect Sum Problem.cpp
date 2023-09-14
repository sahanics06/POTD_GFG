/*
Given an array arr[] of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal
to a given sum.

Note: Answer can be very large, so, output answer modulo 109+7

Example 1:

Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10} are 
possible subsets.
Example 2:
Input: N = 5, arr[] = {1, 2, 3, 4, 5}
       sum = 10
Output: 3
Explanation: {1, 2, 3, 4}, {1, 4, 5}, 
{2, 3, 5} are possible subsets.
Your Task:  
You don't need to read input or print anything. Complete the function perfectSum() which takes N, array arr[] and sum as input 
parameters and returns an integer value

Expected Time Complexity: O(N*sum)
Expected Auxiliary Space: O(N*sum)

Constraints:
1 ≤ N*sum ≤ 106
0<=arr[I]<=106
  */

// Solution using recursion and memoization

class Solution{

	public:
	int mod=1e9+7;
	int solve(int arr[], int n, int sum, int tmp, int i, vector<vector<int>>&dp)
	{
	    if(i>=n)
	    {
	        if(tmp==sum)
	        {
	            return 1;
	        }
	        return 0;
	    }
	    if(dp[i][tmp]!=-1)
	        return dp[i][tmp];
	    int cur=0;
	    
	    if(tmp+arr[i]<=sum)
	    {
	        cur+=solve(arr, n, sum, tmp+arr[i], i+1, dp);
	    }
	    cur=(cur+solve(arr, n, sum, tmp, i+1, dp))%mod;
	    return dp[i][tmp] = cur;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return solve(arr, n, sum, 0, 0, dp);
	}
	  
};
