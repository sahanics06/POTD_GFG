/*
You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

Example 1:

Input:
N = 5
arr[] = {1,2,3,4,5}
Output: 6
Explanation: Smallest positive missing 
number is 6.
Example 2:

Input:
N = 5
arr[] = {0,-10,1,3,-20}
Output: 2
Explanation: Smallest positive missing 
number is 2.
Your Task:
The task is to complete the function missingNumber() which returns the smallest positive missing number in the array.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
-106 <= arr[i] <= 106
  */

// Solution using swap O(N).

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        for(int i=0; i<n; i++)
        {
            if(arr[i]>0 && arr[i]<=n&& arr[i]!=arr[arr[i]-1])  // here we are placing the elements greater than 0 and less than n into their correct index position.
            {                                                  // If their is duplicate then we ignore.
                swap(arr[i], arr[arr[i]-1]);
                i--;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(arr[i]!=i+1)
            {
                return i+1;
            }
        }
        return n+1;
    } 
};

// Solution using two for loop Brute force. O(N^2)

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        bool flag=true;
        int i;
        for(i=0; i<=n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[j]==i)
                {
                    flag=false;
                    break;
                }
            }
            if(flag && i!=0)
                return i;
            flag=true;
        }
        //if(i==n+1)
        return i+1;
    } 
};
