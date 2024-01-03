/*
Given a string S consisting of the characters 0, 1 and 2. Your task is to find the length of the smallest substring of string S that contains all the three characters 0, 1 
and 2. If no such substring exists, then return -1.

Example 1:

Input:
S = 10212
Output:
3
Explanation:
The substring 102 is the smallest substring
that contains the characters 0, 1 and 2.
Example 2:

Input: 
S = 12121
Output:
-1
Explanation: 
As the character 0 is not present in the
string S, therefor no substring containing
all the three characters 0, 1 and 2
exists. Hence, the answer is -1 in this case.
Your Task:
Complete the function smallestSubstring() which takes the string S as input, and returns the length of the smallest substring of string S that contains all the three 
characters 0, 1 and 2.

Expected Time Complexity: O( length( S ) )
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ length( S ) ≤ 105
All the characters of String S lies in the set {'0', '1', '2'}
  */

// Solution

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        int l=0, r=0, n=s.length(), a=0, b=0, c=0, ans=INT_MAX;
        vector<int>chk(3,0);
        for(int i=0; i<n; i++)
        {
            if(s[i]=='0')
            {
                a++;
            }
            else if(s[i]=='1')
            {
                b++;
            }
            else
            {
                c++;
            }
            while(a>0 && b>0 && c>0)
            {
                ans=min(ans, i-l+1);
                if(s[l]=='0')
                {
                    a--;
                }
                else if(s[l]=='1')
                {
                    b--;
                }
                else
                {
                    c--;
                }
                l++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
