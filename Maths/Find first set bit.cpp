/*
Given an integer N. The task is to return the position of first set bit found from the right side in the binary representation of the number.
Note: If there is no set bit in the integer N, then return 0 from the function.  

Example 1:

Input: 
N = 18
Output: 
2
Explanation: 
Binary representation of 18 is 010010,the first set bit from the right side is at position 2.
Example 2:

Input: 
N = 12 
Output: 
3 
Explanation: 
Binary representation of  12 is 1100, the first set bit from the right side is at position 3.
Your Task:
The task is to complete the function getFirstSetBit() that takes an integer n as a parameter and returns the position of first set bit.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
0 <= N <= 108
  */

// Solution, we do bitwise and operation by 1 and if it gives 1 then that is set bit or else we right shift by 1 bit 

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int ans=1;
        while(n)
        {
            if(n&1)
                return ans;
            ans++;
            n>>=1;
        }
        return 0;
    }
};

// Solution by dividing by 2, if it is divisible then for that first bit it has 0.
// Example 4=100, it is divisble 2 times by 2 i.e 4->2->1, in 3rd time we have 1. Therefore 3rd bit is 1

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int ans=1;
        while(n)
        {
            if(n%2)
                return ans;
            ans++;
            n/=2;
        }
        return 0;
    }
};
