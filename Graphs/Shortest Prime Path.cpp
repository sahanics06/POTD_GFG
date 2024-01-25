/*
  You are given two four digit prime numbers Num1 and Num2. Find the distance of the shortest path from Num1 to Num2 
  that can be attained by altering only single digit at a time such that every number that we get after changing a digit 
  is a four digit prime number with no leading zeros.

Example 1:

Input:
Num1 = 1033 
Num2 = 8179
Output: 6
Explanation:
1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179.
There are only 6 steps reuired to reach Num2 from Num1. 
and all the intermediate numbers are 4 digit prime numbers.
Example 2:

Input:
Num1 = 1033 
Num2 = 1033
Output:
0
Your Task:  
You don't need to read input or print anything. Your task is to complete the function solve() which takes two integers 
Num1 and Num2 as input parameters and returns the distance of the shortest path from Num1 to Num2. If it is unreachable 
then return -1.

Expected Time Complexity: O(nlogn)
Expected Auxiliary Space: O(n)

Constraints:
1000<=Num1,Num2<=9999
Num1 and Num2 are prime numbers.

  */


// Solution using BFS, Find shortest path using BFS, find all the prime numbers and then find the distance from one prime 
// to next prime i.e ans+1

class Solution{   
public:
    int flag = 0;
    void seive(vector<string>&mp)
    {
        int n=9999;
        vector<bool>tmp(n+1, true);
        tmp[0]=false;
        tmp[1]=false;
        for(int i=2; i*i<=n; i++)
        {
            if(tmp[i])
            {
                for(int j=i*i; j<=n; j+=i)
                {
                    tmp[j]=0;
                }
            }
        }
        for(int i=1000; i<=n; i++)
        {
            if(tmp[i])
            {
                mp.push_back(to_string(i));
            }
        }
        flag = 1;
    }
    int solve(int Num1,int Num2)
    {   
      //code here
      if(Num1==Num2)
        return 0;
      unordered_map<string,int>mp;
      vector<string>tmp;
      queue<string>q;
      int mx=1e9;
      if(!flag)
        seive(tmp); // calculate seize only one time. Since there are multiple test cases
      for(int i=0; i<tmp.size(); i++)
      {
          mp[tmp[i]]=mx;
      }
      string start = to_string(Num1);
      string end = to_string(Num2);
      mp[start]=0;
      q.push(start);
      while(!q.empty())
      {
          string s = q.front();
          q.pop();
          for(int i=0; i<4; i++)
          {
              for(char j=(i==0?'1':'0'); j<='9'; j++) // if i==0 then start from j=1
              {
                  if(j!=s[i])
                  {
                      string nxt = s;
                      nxt[i]=j;
                      auto it = mp.find(nxt);
                      if(it!=mp.end() && mp[nxt]>mp[s]+1)
                      {
                          //it->second = mp[s]+1;
                          q.push(nxt);
                          mp[nxt]= mp[s]+1;
                          if(nxt==end)
                            return mp[nxt];
                      }
                  }
              }
          }
      }
      return -1;
    }
};
