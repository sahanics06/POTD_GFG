/*
Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated sequence of dictionary 
words. Return 1 if it is possible to break A into sequence of dictionary words, else return 0. 

Note: From the dictionary B each word can be taken any number of times and in any order.

Example 1:

Input:
n = 6
B = { "i", "like", "sam", "sung", "samsung", "mobile"}
A = "ilike"
Output:
1
Explanation:
The string can be segmented as "i like".
Example 2:

Input:
n = 6
B = { "i", "like", "sam", "sung", "samsung", "mobile"}
A = "ilikesamsung"
Output:
1
Explanation:
The string can be segmented as 
"i like samsung" or "i like sam sung".
Your Task:
Complete wordBreak() function which takes a string and list of strings as a parameter and returns 1 if it is possible to 
break words, else return 0. You don't need to read any input or print any output, it is done by driver code.

Expected Time Complexity: O(len(A)2)
Expected Space Complexity: O(len(A))

Constraints:
1 ≤ n ≤ 12
1 ≤ len(A) ≤ 1100

*/

// Solution recursion plus memoization

class Solution
{
public:
    bool solve(string a, int idx, unordered_map<string ,int>&mp, vector<int>&dp)
    {
        if(idx==a.length())
        {
            return true;
        }
        if(dp[idx]!=-1)
            return dp[idx];
        bool ans=false;
        string tmp="";
        for(int i=idx; i<a.length(); i++)
        {
            tmp+=a[i];
            if(mp.find(tmp)!=mp.end())
            {
                ans= ans||solve(a, i+1, mp, dp);
                if(ans)
                    return dp[i]=true;// optimised step
            }
        }
        return dp[idx]=ans;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string, int>mp;
        vector<int>dp(A.length(), -1);
        for(int i=0; i<B.size(); i++)
        {
            mp[B[i]]++;
        }
        return solve(A, 0, mp, dp);
    }
};



// Solution using recursion

//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    
    bool solve(string a, string tmp, int idx, unordered_map<string ,int>&mp)
    {
        if(idx==a.length())
        {
            return true;
        }
        bool ans=false;
        for(int i=idx; i<a.length(); i++)
        {
            tmp+=a[i];
            if(mp.find(tmp)!=mp.end())
            {
                ans= ans||solve(a, "", i+1, mp);
                if(ans)
                    return true;
            }
        }
        return ans;
        
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string, int>mp;
        for(int i=0; i<B.size(); i++)
        {
            mp[B[i]]++;
        }
        string t="";
        return solve(A, t, 0, mp);
    }
};
