/*
You are given an array arr of n integers. For each index i, you have to find the sum of all integers present in the array with a value less than arr[i].

Example 1:

Input:
n = 3
arr = {1, 2, 3}
Output:
0 1 3
Explanation:
For 1, there are no elements lesser than itself.
For 2, only 1 is lesser than 2.
And for 3, 1 and 2 are lesser than 3, so the sum is 3.
Example 2:

Input:
n = 2
arr = {4, 4}
Output:
0 0
Explanation:
For 4, there are no elements lesser than itself. 
For 4, there are no elements lesser than itself.
There are no smaller elements than 4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function smallerSum() which takes an integer n and an array arr and returns an array of length n , the answer for every index.

Expected Time Complexity:O(n log n)
Expected Space Complexity:O(n)

Constraints:
1 <= n <= 105
1 <= arr[i] <= 109

*/

// Solution using binary search

class Solution{
public:
    int Bin(vector<int>&tmp, int val)
    {
        int l=0, r=tmp.size()-1, m;
        while(l<=r)
        {
            m=l+(r-l)/2;
            if(tmp[m]>=val)
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return l;
    }
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int>tmp;
        tmp=arr;
        sort(tmp.begin(), tmp.end());
        vector<long long>ans, sum(n);
        sum[0]=tmp[0];
        for(int i=1; i<n; i++)
        {
            sum[i]=sum[i-1]+tmp[i];
        }
        for(int i=0; i<n; i++)
        {
            int index=Bin(tmp,arr[i]);
            ans.push_back(sum[index]-arr[i]);
        }
        return ans;
    }
};

// Solution using hashmap

class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        unordered_map<int, long long>m;
        vector<int>tmp;
        tmp=arr;
        vector<long long>ans;
        sort(tmp.begin(), tmp.end());
        int prev=tmp[0];
        long long sum=0;
        for(int i=1; i<n; i++)
        {
            sum+=prev;
            if(tmp[i]>prev)
            {
                m[tmp[i]]=sum;
                prev=tmp[i];
            }
        }
        for(int i=0; i<n; i++)
        {
            ans.push_back(m[arr[i]]);
        }
        return ans;
    }
};
