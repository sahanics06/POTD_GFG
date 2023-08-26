/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. 
If there is no possible substring then print -1.

Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 
7
Explanation: 
"cbebebe" is the longest substring with 3 distinct characters.
Example 2:

Input: 
S = "aaaa", K = 2
Output: -1
Explanation: 
There's no substring with 2 distinct characters.
Your Task:
You don't need to read input or print anything. Your task is to complete the function longestKSubstr() which takes 
the string S and an integer K as input and returns the length of the longest substring with exactly K distinct characters. 
If there is no substring with exactly K distinct characters then return -1.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).

Constraints:
1 ≤ |S| ≤ 105
1 ≤ K ≤ 26
All characters are lowercase latin characters.

*/

// Solution

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int count=0, i=0, j=0, ans=-1, n=s.length();
    vector<int>freq(26, 0);
    while(i<n)
    {
        char tmp=s[i];
        freq[tmp-'a']++;
        if(freq[tmp-'a']==1) // If first occurence of charcter then increase count by 1
        {
            count++;
        }
        if(count==k)
        {
            if(count==k)
            {
                ans=max(ans,i-j+1);
            }
        }
        else if(count>k) // If count of unique characters>k then delete characters until unique count<=k
        {
            while(j<i && count>k)
            {
                freq[s[j]-'a']--;
                if(freq[s[j]-'a']==0) // If character becomes 0 then subtract unique character count by 1
                {
                    count--;
                }
                j++;
            }
        }
        i++;
    }
    return ans;
    }
};
