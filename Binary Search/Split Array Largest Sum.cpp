/*
Given an array arr[] of N elements and a number K., split the given array into K subarrays such that the maximum subarray 
sum achievable out of K subarrays formed is minimum possible. Find that possible subarray sum.

Example 1:

Input:
N = 4, K = 3
arr[] = {1, 2, 3, 4}
Output: 4
Explanation:
Optimal Split is {1, 2}, {3}, {4}.
Maximum sum of all subarrays is 4,
which is minimum possible for 3 splits. 
Example 2:

Input:
N = 3, K = 2
A[] = {1, 1, 2}
Output:
2
Explanation:
Splitting the array as {1,1} and {2} is optimal.
This results in a maximum sum subarray of 2.
Your Task:
You do not have to take any input or print anything. The task is to complete the function splitArray() which returns the 
maximum sum subarray after splitting the array into K subarrays such that maximum sum subarray is minimum possible.

Expected Time Complexity: O(N*log(sum(arr))).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
1 ≤ K ≤ N
1 ≤ arr[i] ≤ 104

*/

// Solution using Binary Search

class Solution {
  public:
    int solve(int arr[], int n, int k, int m)
    {
        int tmp=0, i=0, p=1;
        while(i<n)
        {
            if(tmp+arr[i]<=m)
            {
                tmp+=arr[i];
            }
            else
            {
                p++;
                tmp=arr[i];
            }
            i++;
        }
        return p;
    }
    int splitArray(int arr[] ,int n, int k) {
        int sum, r, m, ans;
        sum = accumulate(arr, arr+n, 0);
        int l=*max_element(arr, arr+n);
        r=sum;
        while(l<=r)
        {
            m=l+(r-l)/2;
            int p = solve(arr, n, k, m);
            if(p>k)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return l;
    }
};
