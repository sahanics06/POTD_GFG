/*
You are given a binary string s and an integer m. You need to return an integer r. Where r = k%m, k is the binary equivalent of string s.

Example 1:

Input:
s = "101" 
m = 2
Output:
1
Explanation: Here k=5 because (101)2 = (5)10.
Hence 5 mod 2 = 1.
Example 2:

Input:
s = "1000"
m = 4
Output:
0
Explanation: Here k=8 and m=4 hence 
r = k mod m = 8 mod 4 = 0.
Your Task:
You don't need to read input or print anything. Your task is to complete the function modulo() which takes the string s and integer m as input parameters and returns the value of r as described above.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= len(s) <= 105
1 <= m <= 100
*/

class Solution{
    public:
        int modulo(string s,int m)
        {
            //code here
            int ans=0, tmp=1;
            int i=s.length()-1;
            while(i>=0)
            {
                if(s[i]=='1')
                {
                    ans+=tmp;
                    ans%=m;
                }
                tmp*=2; //We Can't use power function becaus string length is 10^5 and pow(2, 10^5) is too big.
                tmp%=m;
                i--;
            }
            return ans%m;
        }
};
