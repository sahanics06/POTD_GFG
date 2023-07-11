/*
Given a matrix with n rows and m columns. Your task is to find the kth element which is obtained while traversing the matrix spirally. 
You need to complete the method findK which takes four arguments the first argument is the matrix A and the next two arguments will be n and m denoting the size of the 
matrix A and then the forth argument is an integer k. The function will return the kth element obtained while traversing the matrix spirally.

Example 1:

Input:
n = 4, m = 4, k = 10
A[][] = {{1  2  3  4},
         {5  6  7  8},
         {9  10 11 12},
         {13 14 15 16}}
Output:
13
Explanation:

The spiral order of matrix will look like 1->2->3->4->8->12->16->15->14->13->9->5->6->7->11->10. So the 10th element in this order is 13. 
Example 2:

Input:
n = 3, m = 3, k = 4
A[][] = {{1 2 3},
         {4 5 6},
         {7 8 9}}
Output:
6
Explanation:
The spiral order of matrix will look like 1->2->3->6->9->8->7->4->5. So the 4th element in this order is 6.
Your Task:
You only need to implement the given function findK(). Do not read input, instead use the arguments given in the function. Return the K'th element obtained by 
traversing matrix spirally.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1<=n,m<=103
1<=k<=n*m
  */

// Solution

class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int cu=m-1, cl=0, rl=0, ru=n-1, count=0;
 		while(count!=n*m)
 		{
 		    for(int i=cl; i<=cu; i++)
 		    {
 		        count++;
 		        if(count==k)
 		        {
 		            return a[rl][i];
 		        }
 		    }
 		    rl++;
 		    for(int i=rl; i<=ru; i++)
 		    {
 		        count++;
 		        if(count==k)
 		        {
 		            return a[i][cu];
 		        }
 		    }
 		    cu--;
 		    for(int i=cu; i>=cl; i--)
 		    {
 		        count++;
 		        if(count==k)
 		        {
 		            return a[ru][i];
 		        }
 		    }
 		    ru--;
 		    for(int i=ru; i>=rl; i--)
 		    {
 		        count++;
 		        if(count==k)
 		        {
 		            return a[i][cl];
 		        }
 		    }
 		    cl++;
 		}
 		return 0;
    }
};
