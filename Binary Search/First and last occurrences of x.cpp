/*
Given a sorted array arr containing n elements with possibly duplicate is to find indexes of first elements, the task is to find the 
first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.

Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  
2 5
Explanation: 
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  
6 6
Explanation: 
First and last occurrence of 7 is at index 6.
Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. 
You just need to complete the function find() that takes array arr, integer n and integer x as parameters and returns the required 
answer.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i],x ≤ 109

*/

//**********************************************************************************************************

// Solution 

class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int l=0, r=n-1, ans=-1;
        vector<int>tmp;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(arr[m]<x)
            {
                l=m+1;
            }
            else if(arr[m]>x)
            {
                r=m-1;
            }
            else
            {
                ans=m;
                r=m-1;
            }
        }
        tmp.push_back(ans);
        l=0;
        r=n-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(arr[m]<x)
            {
                l=m+1;
            }
            else if(arr[m]>x)
            {
                r=m-1;
            }
            else
            {
                ans=m;
                l=m+1;
            }
        }
        tmp.push_back(ans);
        return tmp;
    }
};

//**********************************************************************************************************

vector<int> find(int arr[], int n , int x )
{
    // code here
    int l=0, r=n-1, m;
    vector<int>v{-1,-1};
    while(l<=r)
    {
        m=l+(r-l)/2;
        if(arr[m]==x)
        {
            int lr=m,rl=m;
            while(l<=lr)
            {
                int a=l+(lr-l)/2;
                if(arr[a]==x)
                {
                    v[0]=a;
                    lr=a-1;
                }
                else
                {
                    l=a+1;
                }
                
            }
            
            while(rl<=r)
            {
                int a=rl+(r-rl)/2;
                if(arr[a]==x)
                {
                    v[1]=a;
                    rl=a+1;
                }
                else
                {
                    r=a-1;
                }
            }
            break;
            
        }
        else if(arr[m]<x)
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    return v;
    
}
