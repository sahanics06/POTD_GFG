/*
Your are given an 2D integer array  ranges whose length is n where  ranges[i]=[starti,endi,coinsi] means all integers from starti to  endi inclusive starti and endi are present and  we get coinsi amount of coins when we select this ith range . You can select atmost two intervals so as to collect maximum coins but if u select two ranges than those two ranges should not intersect or overlapp than can touch each other.

Note : You can select at max 2 ranges and they should not intersect with each other but they can touch themselves.

Example 1:

Input :
n=3
ranges={{1,3,4},{2,3,5},{3,4,2}}
Output: 7
Explanation:
We can see that we can take 2nd and 
3rd ranges as they are not intersecting
(only touching) we get maximum Coins by 
taking these ranges(5+2=7).
Example 2:

Input :
n=5
ranges={{1,3,4},{2,3,5},{3,4,2},{5,8,9},{2,8,10}}
Output: 14
Explanation:
We can see that we can take 2nd and 
4th ranges as they are not intersecting 
we get maximum Coins(5+9=14) by taking 
these ranges.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxCoins() which takes an integer n(length of ranges) and integer 2D integer array ranges and you have to  return the maximum number of coins which you can get after selecting atmost two ranges which are not intersecting.

Expected Time Complexity: O(nlogn)
Expected Space Complexity: O(n)

Constraints:
1<=n<=105
0<=ranges[i][0]<=ranges[i][1]<=109
0<=ranges[i][2](coins)<=106
The sum of n over all test cases won't exceed 106
*/

class Solution{
public:
    int solve(int l, int r, int k, vector<vector<int>>&ranges)
    {
        int ans=-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(ranges[k][1]<=ranges[m][0])
            {
                ans=m;
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return ans;
    }
    int maxCoins(int n,vector<vector<int>> &ranges){
        // Code here
        vector<int>v(n);
        sort(ranges.begin(), ranges.end());
        int mx=INT_MIN;
        for(int i=n-1; i>=0; i--)
        {
            mx=max(ranges[i][2], mx);  // To find the greatest element from this index to right.
            v[i]=mx;
        }
        int ans=v[0];
        for(int i=0; i<n-1; i++)
        {
            int tmp=solve(i+1, n-1, i, ranges); // To find the left most first index which can be taken
            if(tmp!=-1)
                ans=max(ranges[i][2]+v[tmp], ans);
        }
        return ans;
    }
};
