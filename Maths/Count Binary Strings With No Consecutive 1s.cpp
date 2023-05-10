/*
Given an integer N. Your task is to find the number of binary strings of length N having no consecutive 1s.
As the number can be large, return the answer modulo 10^9+7.

Example 1:

Input:
N = 3
Output:
5
Explanation:
All the binary strings of length 3 having
no consecutive 1s are "000", "001", "101",
"100" and "010".
Example 2:

Input: 
N = 2
Output:
3
Explanation: 
All the binary strings of length 2 having no 
consecutive 1s are "10", "00" and "01".
Your Task:
You dont need to read input or print anything. Complete the function countStrings() which takes the integer N as the input parameter, 
and returns the number of binary strings of length N with no consecutive 1s.

Expected Time Complexity: O(log(N))
Expected Auxiliary Space: O(Height of the recursive call stack)

Constraints:
1 ≤ N ≤ 1018
*/

// Solution using recursion. // TLE

class Solution {
  public:
    int mod=1e9+7;
    void solve(long long int N, long long int i, int f, int &ans)
    {
        if(i==N)
        {
            ans=(ans+1)%mod;
            return;
        }
        if(f==0)
        {
            solve(N, i+1, 1, ans);
        }
        solve(N, i+1, 0, ans);
        
    }
    int countStrings(long long int N) {
        // Code here
        int ans=0;
        solve(N, 1, 0, ans);
        solve(N, 1, 1, ans);
        return ans;
    }
};

// Solution using fibonacci serries, multiplication, power function.

class Solution {
  public:
    const int mod = 1e9+7;
    
    vector<vector<long long int>> multiply(vector<vector<long long int>>&a,vector<vector<long long int>>&b){
        vector<vector<long long int>>ans (2,vector<long long int>(2,0));
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                for(int k=0; k<2; k++)ans[i][j]+=(a[i][k]*b[k][j])%mod;
            }
        }
        return ans;
    }
    
    vector<vector<long long int>> matrix(vector<vector<long long int>>&v,long long int n){
        if(n==0)return {{1,0},{0,1}};
        if(n==1)return v;
        vector<vector<long long int>>temp = matrix(v,n/2);
        vector<vector<long long int>>ans = multiply(temp,temp);
        if(n%2)ans=multiply(v,ans);
        return ans;
    }
  
    int countStrings(long long int N) {
    vector<vector<long long int>> v = {{1,1},{1,0}};
    vector<vector<long long int>> ans = matrix(v,N);
    return (ans[0][1]+ans[0][0])%mod;
    }
};
