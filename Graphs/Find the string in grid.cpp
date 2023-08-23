/*
Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. 
A word can be matched in all 8 directions at any point. Word is said to be found in a direction if all characters match 
in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, 
vertically down, and 4 diagonal directions.

Note: The returning list should be lexicographically smallest. If the word can be found in multiple directions starting 
from the same coordinates, the list should contain the coordinates only once. 

Example 1:

Input: 
grid = {{a,b,c},{d,r,f},{g,h,i}},
word = "abc"
Output: 
{{0,0}}
Explanation: 
From (0,0) we can find "abc" in horizontally right direction.
Example 2:

Input: 
grid = {{a,b,a,b},{a,b,e,b},{e,b,e,b}}
word = "abe"
Output: 
{{0,0},{0,2},{1,0}}
Explanation: 
From (0,0) we can find "abe" in right-down diagonal. 
From (0,2) we can find "abe" in left-down diagonal. 
From (1,0) we can find "abe" in horizontally right direction.
Your Task:
You don't need to read or print anything, Your task is to complete the function searchWord() which takes grid and word as 
input parameters and returns a list containing the positions from where the word originates in any direction. 
If there is no such position then returns an empty list.

Expected Time Complexity: O(n*m*k) where k is constant
Expected Space Complexity: O(1)

Constraints:
1 <= n <= m <= 50
1 <= |word| <= 15
  */

// Solution using recursion

class Solution {
public:
    // bool solve(int idx, int r, int c, int dir_i, int dir_j, vector<vector<char>>&grid, string &word)
    // {
    //     int n=grid.size(), m=grid[0].size();
    //     if(idx==word.length())
    //         return true;
    //     if(r<0 || c<0 || r>=n || c>=m || (idx<word.length() && grid[r][c]!=word[idx]))
    //         return false;
    //     return solve(idx+1, r+dir_i, c+dir_j, dir_i, dir_j, grid, word);
    // }
    bool f(int x,int y,int dx,int dy,int ind,string word, vector<vector<char>>grid){
    if(ind==word.size()){
        return true;
    }
       int xi = dx + x;
       int yj = dy + y;
    
        if(xi>=0 && yj>=0 && xi<grid.size() && yj<grid[0].size()){
            if(grid[xi][yj]==word[ind]){
                
                if(f(xi,yj,dx,dy,ind+1,word,grid))
                return true;
            }
        }
    return false;
}
    
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	   // vector<vector<int,int>>ans;
	   // int s=word.length(), n=grid.size(), m=grid[0].size();
	   // queue<pair<int,pair<int,pair<int,int>>>>q;
	   // for(int i=0; i<grid.size(); i++)
	   // {
	   //     for(int j=0; j<grid[0].size(); j++)
	   //     {
	   //         if(grid[i][j]==word[0])
	   //         {
	   //             for(int k=0; k<8; k++)
	   //                 q.push({k,{1,{i,j}}});
	   //         }
	   //     }
	   // }
	   // int dir[8][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
	   // while(!q.empty())
	   // {
	   //     int d=q.front().first;
	   //     int len=q.front().second.first;
	   //     int y=q.front().second.second.first;
	   //     int x=q.front().second.second.second;
	   //     q.pop();
	   //     if(len==s)
	   //     {
	   //         ans.push_back({y-s,x-s});
	   //     }
	   //     else
	   //     {
	   //         int tx=x+dir[d][1];
    // 	        int ty=y+dir[d][0];
    // 	        if(tx>=0 && ty>=0 && tx<n && ty<m && grid[ty][tx]==word[len])
    // 	        {
    // 	            q.push({d,{len+1,{ty,tx}}});
    // 	        }   
	   //     }
	   // }
	   // return ans;
	    int n = grid.size();
    int m = grid[0].size();
    set<vector<int>> result_set;
    
    int dx[] = {1,0,-1,0,1,1,-1,-1};
    int dy[] = {0,1,0,-1,-1,1,1,-1};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==word[0]){
                for(int k=0;k<8;k++){
                      
                    if(f(i,j,dx[k],dy[k],1,word,grid)){
                       result_set.insert({i,j}); 
                    }
                }
            }
        }
    }
    vector<vector<int>> ds(result_set.begin(), result_set.end());
    return ds;
	}
};
