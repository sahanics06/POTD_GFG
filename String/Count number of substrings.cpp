/*
Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that have exactly k distinct 
characters. 

Example 1:

Input:
S = "aba", K = 2
Output:
3
Explanation:
The substrings are: "ab", "ba" and "aba".
Example 2:

Input: 
S = "abaaca", K = 1
Output:
7
Explanation:
The substrings are: "a", "b", "a", "aa", "a", "c", "a". 
Your Task:
You don't need to read input or print anything. Your task is to complete the function substrCount() which takes the string S
and an integer K as inputs and returns the number of substrings having exactly K distinct characters.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ |S| ≤ 106
1 ≤ K ≤ 26

*/

//**********************************************************************************************

// Solution
// Here we find count of substring with atmost k and k-1 unique characters 
// Then we subtract to find the substring with k unique characters
class Solution
{
  public:
    long long int solve(string s, int k)
    {
        int ans=0, i=0, j=0, c=0, n=s.length();
        int arr[26]={0};
        while(i<n)
        {
            arr[s[i]-'a']++;
            if(arr[s[i]-'a']==1)
            {
                c++;
            }
            while(c>k)
            {
                arr[s[j]-'a']--;
                if(arr[s[j]-'a']==0)
                {
                    c--;
                }
                j++;
            }
            ans+=i-j+1;
            i++;
        }
        return ans;
    }
    long long int substrCount (string s, int k) {
        long long int t1 = solve(s,k);
        long long int t2 = solve(s,k-1);
        return t1-t2;
    }
};
