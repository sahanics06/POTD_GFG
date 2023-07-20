/*
Given a String, find the longest palindromic subsequence.

NOTE: Subsequence of a given sequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the 
remaining elements

Example 1:

Input:
S = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the
longest subsequence which is also a palindrome.


Example 2:

Input: 
S = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are
palindromic and all have a length 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalinSubseq() which takes the string S as input and returns an integer 
denoting the length of the longest palindromic subsequence of S.

Expected Time Complexity: O(|S|*|S|).
Expected Auxiliary Space: O(|S|*|S|).

Constraints:
1 ≤ |S| ≤ 1000
  */

// Solution DP. Time- O(N^2), Space- O(N^2).

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int dp[n+1][n+1];
        string r=s;
        reverse(r.begin(), r.end());
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<n+1; j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(s[i-1]==r[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};

//Solution using Recursion. Longest common subsequence between the given string and reverse of given string. Memoization and Recursion.

class Solution{
  public:
    int dp[1001][1001];
    int solve(string a, string b, int i, int j)
    {
        if(i>=a.length()||j>=b.length())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
        {
            return dp[i][j]=1+solve(a, b, i+1, j+1);
        }
        return dp[i][j]=max(solve(a,b,i+1,j),solve(a,b,i,j+1));
        
    }
    int longestPalinSubseq(string a) {
        //code here
        memset(dp, -1, sizeof(dp));
        string b=a;
        reverse(b.begin(), b.end());
        return solve(a,b,0,0);
    }
};

//Solution using Recursion. Longest common subsequence between the given string and reverse of given string.

//User function Template for C++

class Solution{
  public:
    int solve(string a, string b, int i, int j)
    {
        if(i>=a.length()||j>=b.length())
        {
            return 0;
        }
        if(a[i]==b[j])
        {
            return 1+solve(a, b, i+1, j+1);
        }
        return max(solve(a,b,i+1,j),solve(a,b,i,j+1));
        
    }
    int longestPalinSubseq(string a) {
        //code here
        string b=a;
        reverse(b.begin(), b.end());
        return solve(a,b,0,0);
    }
};


// Solution using Recursion

//User function Template for C++

class Solution{
  public:
    int ans=0;
    bool check(string tmp)
    {
        int l=tmp.length()-1, i=0;
        while(i<l)
        {
            if(tmp[i]!=tmp[l])
            {
                return false;
            }
            i++;
            l--;
        }
        return true;
    }
    void solve(string s, int i, string tmp)
    {
        if(check(tmp))
        {
            int len=tmp.length();
            ans=max(ans, len);
        }
        if(i>=s.length())
            return;
        string t="";
        t=tmp+s[i];
        solve(s, i+1, t);
        solve(s, i+1, tmp);
    }
    int longestPalinSubseq(string A) {
        //code here
        string tmp="";
        solve(A, 0, tmp);
        return ans;
    }
};
