/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain 
rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize
the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. 
He asks for your help to find the maximum money he can get if he strictly follows the rule. ith house has a[i] amount of money present
in it.

Example 1:

Input:
n = 5
a[] = {6,5,5,7,4}
Output: 
15
Explanation: 
Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6+5+4=15.
Example 2:

Input:
n = 3
a[] = {1,5,3}
Output: 
5
Explanation: 
Loot only 2nd house and get maximum amount of 5.
Your Task:
Complete the functionFindMaxSum() which takes an array arr[] and n as input which returns the maximum money he can get following the 
rules.

Expected Time Complexity:O(N).
Expected Space Complexity:O(N).

Constraints:
1 ≤ n ≤ 105
1 ≤ a[i] ≤ 104

*/

//*******************************************************************************************************

// Solution

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n==1)
            return arr[0];
        if(n==2)
            return max(arr[0],arr[1]);
        int dp[n]={0};
        dp[0]=arr[0];
        dp[1]=max(arr[0], arr[1]);
        for(int i=2; i<n; i++)
        {
            dp[i]=max(arr[i]+dp[i-2], dp[i-1]);
        }
        return dp[n-1];
    }
};
