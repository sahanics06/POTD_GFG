/*
Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given 
strings.

Example 1:

Input:
A = "geeks"
B = "geeksfor", 
C = "geeksforgeeks"
Output: 5
Explanation: 
"geeks"is the longest common
subsequence with length 5.
Example 2:

Input: 
A = "abcd"
B = "efgh"
C = "ijkl"
Output: 0
Explanation: 
There's no subsequence common
in all the three strings.
Your Task:
You don't need to read input or print anything. Your task is to complete the function LCSof3() which takes the 
strings A, B, C and their lengths n1, n2, n3 as input and returns the length of the longest common subsequence in all 
the 3 strings.

Expected Time Complexity: O(n1*n2*n3).
Expected Auxiliary Space: O(n1*n2*n3).

Constraints:
1 <= n1, n2, n3 <= 20
Elements of the strings consitutes only of the lower case english alphabets.

*/

// Solution using recursion and memoization

class Solution
{
    public:
        int dp[21][21][21];
        int solve(string a, string b, string c, int i, int j, int k, int n1, int n2, int n3)
        {
            if(i>=n1 || j>=n2 || k>=n3)
                return 0;
            if(dp[i][j][k]!=-1)
                return dp[i][j][k];
            if(a[i]==b[j] && a[i]==c[k])
                return 1+solve(a, b, c, i+1, j+1, k+1, n1, n2, n3);
            int aa = solve(a, b, c, i+1, j, k, n1, n2, n3);
            int bb = solve(a, b, c, i, j+1, k, n1, n2, n3);
            int cc = solve(a, b, c, i, j, k+1, n1, n2, n3);
            return dp[i][j][k]=max({aa,bb,cc});
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            memset(dp, -1, sizeof(dp));
            return solve(A, B, C, 0, 0, 0, n1, n2, n3);
        }
};
