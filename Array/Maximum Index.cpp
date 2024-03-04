/*
Given an array a of n positive integers. The task is to find the maximum of j - i subjected to 
the constraint of a[i] < a[j] and i < j.

Example 1:

Input:
n = 2
a[] = {1, 10}
Output:
1
Explanation:
a[0] < a[1] so (j-i) is 1-0 = 1.
Example 2:

Input:
n = 9
a[] = {34, 8, 10, 3, 2, 80, 30, 33, 1}
Output:
6
Explanation:
In the given array a[1] < a[7] satisfying the required condition(a[i] < a[j]) thus giving the maximum difference 
of j - i which is 6(7-1).
Your Task:
The task is to complete the function maxIndexDiff() which finds and returns maximum index difference. 
Printing the output will be handled by driver code. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ n ≤ 106
0 ≤ a[i] ≤ 109

*/

// Solution- Store elements and its index in vector of pair; sort the vector; now traverse from right to left and if current 
// second> prev second then update index to current second; else if current second<prev second then 
// ans =max(ans, prev second-current second)

class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    static bool comp(pair<int,int> a, pair<int,int> b)
    {
        if(a.first!=b.first)
        {
            return a.first<b.first;
        }
        else
        {
            return a.second<b.second;
        }
    }
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<pair<int,int>>tmp;
        for(int i=0; i<n; i++)
        {
            tmp.push_back({a[i], i});
        }
        sort(tmp.begin(), tmp.end(), comp);
        stack<int>st;
        int ans=INT_MIN, t=tmp[n-1].second;
        for(int i=n-2; i>=0; i--)
        {
            int sec = tmp[i].second;
            if(sec>t)
            {
                t=sec;
            }
            else
            {
                ans = max(ans, t-sec);
            }
        }
        return ans==INT_MIN?0:ans;
    }
};
