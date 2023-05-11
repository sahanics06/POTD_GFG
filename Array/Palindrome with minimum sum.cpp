/*
Given a string, S.The string can contain small case English letters or '?'. You can replace '?' with any small English letter. Now if it is possible to make the string S a palindrome after replacing all '?' then find the palindromic string with a minimum ascii sum of differences of adjacent characters. Otherwise, return -1.

Example 1:

Input: S = a???c??c????
Output: 4
Explanation:
We can see that we can make the string
palindrome. Now to get minimum ascii sum we should
replace all the '?' between 'a' and 'c' with
'b' and all the '?' between two 'c' with 'c'.
So after replacing all the '?' the string: 
abbbccccbbba.
The sum of differences of adjacent characters is 4.   
Example 2:

Input: S = a???c??c???c
Output: -1
Explanation:
It is not possible to make the string palindrome.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minimumSum() which takes a string S input parameter and returns an integer denoting the sum of differences of adjacent characters. If it is not possible to make string palindrome, return -1. 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 <= |S| <= 105
*/

//   Solution- We change the '?' to latest finding character. 

class Solution {
  public:
    int minimumSum(string s) {
        // code here
        int n=s.length(), sum=0;
        for(int i=0; i<n/2; i++)
        {
            if(s[i]==s[n-i-1])
            {
                continue;
            }
            else if(s[i]=='?')
            {
                s[i]=s[n-i-1];
            }
            else if(s[n-i-1]=='?')
            {
                s[n-i-1]=s[i];
            }
            else
            {
                return -1;
            }
        }
        char c;
        for(int i=0; i<n; i++)
        {
            if(s[i]!='?')
            {
                c=s[i];
                break;
            }
        }
        for(int i=1; i<n/2; i++)
        {
            if(s[i]!='?')
            {
                sum+=(abs(c-s[i]));
                c=s[i];
            }
        }
        if(n%2)
        {
            sum+=abs(c-s[n/2]);
        }
        sum+=sum;
        return sum;
    }
};
