/*
Given a string s containing 0's and 1's. You have to return the smallest positive integer C, such that the 
binary string can be cut into C pieces and each piece should be of the power of 5  with no leading zeros.
Note: The string s is a binary string. And if no such cuts are possible, then return -1.
Example 1:
Input:
s = "101101101"
Output: 
3
Explanation: 
We can split the given string into 
three 101s, where 101 is the binary 
representation of 5.
Example 2:
Input:
s = "00000"
Output: 
-1
Explanation: 
0 is not a power of 5.
Your Task:
Your task is to complete the function cuts() which take a single argument(string s). 
You need not take any input or print anything. Return an int C if the cut is possible else return -1.
Expected Time Complexity: O(|s|*|s|*|s|).
Expected Auxiliary Space: O(|s|).

Constraints:
1<= |s| <=50
*/

// Solution- Recursion plus memoization

class Solution{
    public:
    static bool pos(string s, int start, int end)
    {
        long long num=0, j=1;
        for(int i=end; i>=start; i--)
        {
            if(s[i]=='1')
            {
                num+=j;
            }
            j*=2;
        }
        while(num>1)
        {
            if(num%5!=0)   return false;
            num/=5;
        }
        return true;
    }
    static int solve(string s, int start, int end, vector<vector<int>>&dp)
    {
        if(end<start)
        {
            return 0;
        }
        if(s[start]=='0')
            {
                return -1;
            }
        if(dp[start][end]!=-1)  return dp[start][end];
        if(pos(s, start, end)) return 1;
        int ans=INT_MAX;
        for(int i=start; i<=end; i++)
        {
            if(pos(s, start, i))
            {
                int second=solve(s, i+1, end, dp);
                if(second!=-1)
                {
                    ans=min(ans, 1+second);
                }
            }
            
        }
        return dp[start][end]=ans==INT_MAX?-1:ans;
    }
    int cuts(string s){
        //code
        int n=s.length();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return solve(s, 0, n-1, dp);
        
    }
};
