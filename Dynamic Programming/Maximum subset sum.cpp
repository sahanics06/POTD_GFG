/*
Given an array A of size N. Find the maximum subset-sum of elements that you can make from the given array such that for every two consecutive
elements in the array, at least one of the elements is present in our subset. 

Example 1:

Input: 
N = 4
A[] = {1, -1, 3, 4}
Output: 8
Explanation: 
We can choose 0th,2nd & 3rd index(0 based 
Index),so that it can satisfy the 
condition & can make maximum sum 8. 
Example 2:

Input: 
N = 3
A[] =  {0, 2, 0};
Output: 2
Explanation: 
We can choose 1st index. Here the 
maximum possible sum is 2.
Your task:

You don't have to read input or print anything. Your task is to complete the function findMaxSubsetSum() which takes the array A and
its size N as input and returns the Maximum possible subset-sum.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
2 ≤ N ≤ 105
-105 ≤ A[i] ≤ 105
*/

// Solution using loop.
class Solution {

  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<long long>cur(2), prev(2);
        prev[0]=0;
        prev[1]=A[0];
        for(int i=1; i<N; i++)
        {
            cur[1]=A[i]+max(prev[0], prev[1]);
            cur[0]=prev[1];
            prev=cur;
        }
        return max(cur[0], cur[1]);
    }
};

//Solution using recursion and memoization.

class Solution {

  public:
    long long solve(vector<int>&a, int n, int i, int f, vector<vector<int>>&dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i][f]!=-1)   return dp[i][f];
        long long taken=INT_MIN, not_taken=INT_MIN;
        if(f==1)
        {
            not_taken= solve(a, n, i+1, 0, dp);
        }
        taken=solve(a,n,i+1,1, dp)+a[i];
        return dp[i][f]=max(taken, not_taken);
    }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        vector<vector<int>>dp(N+1, vector<int>(2,-1));
        return solve(A, N, 0, 1, dp);
    }
};
