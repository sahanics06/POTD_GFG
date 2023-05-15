/*
You are given a number N. Find the total number of setbits in the numbers from 1 to N. 
Example 1:
Input: N = 3
Output: 4
Explaination: 
1 -> 01, 2 -> 10 and 3 -> 11. 
So total 4 setbits.
Example 2:
Input: N = 4
Output: 5
Explaination: 1 -> 01, 2 -> 10, 3 -> 11 
and 4 -> 100. So total 5 setbits.
Your Task:
You do not need to read input or print anything. Your task is to complete the function countBits() which takes N as input parameter
and returns the total number of setbits upto N.
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ N ≤ 109
*/

class Solution {
  public:
    long long countBits(long long N) {
        // code here
        long long sum=0;
        long long i=1, n=N;
        while(n!=0)
        {
            long long tmp=(N+1)/(2*i);
            sum+=tmp*i;
            tmp=(N+1)/i;
            if(tmp%2==1)
            {
                sum+=(N+1)%i;
            }
            i*=2;
            n>>=1;
        }
        return sum;
    }
};
