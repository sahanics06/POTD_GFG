/*
Given two strings, one is a text string, txt and other is a pattern string, pat. The task is to print the indexes of all the occurences of pattern string in the text string. Use one-based indexing while returing the indices. 
Note: Return an empty list incase of no occurences of pattern. Driver will print -1 in this case.

Example 1:

Input:
txt = "geeksforgeeks"
pat = "geek"
Output: 
1 9
Explanation: 
The string "geek" occurs twice in txt, one starts are index 1 and the other at index 9. 
Example 2:

Input: 
txt = "abesdu"
pat = "edu"
Output: 
-1
Explanation: 
There's not substring "edu" present in txt.
Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes the string txt and the string pat as inputs and returns an array denoting the start indices (1-based) of substring pat in the string txt. 

Expected Time Complexity: O(|txt|).
Expected Auxiliary Space: O(|txt|).

Constraints:
1 ≤ |txt| ≤ 105
1 ≤ |pat| < |S|
Both the strings consists of lowercase English alphabets.

  */

// Solution

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int>ans;
            int i=0, j=0, n=txt.length(), m=pat.length();
            for(int k=0; k<n; k++)
            {
                if(txt[k]==pat[0])
                {
                    int p=1, q=k+1;
                    while(p<m && q<n)
                    {
                        if(txt[q]==pat[p])
                        {
                            q++;
                            p++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(p==m)
                    {
                        ans.push_back(k);
                    }
                }
            }
            if(ans.size()==0)
                return {-1};
            return ans;
            // while(i<n)
            // {
            //     int p=i, q=j;
            //     if(txt[p]==pat[q])
            //     {
            //         while()
            //     }
            // }
        }
     
};
