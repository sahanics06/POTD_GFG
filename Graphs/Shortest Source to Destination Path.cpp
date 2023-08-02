/*
Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.

Example 1:

Input:
N=3, M=4
A=[[1,0,0,0], 
   [1,1,0,1],
   [0,1,1,1]]
X=2, Y=3 
Output:
5
Explanation:
The shortest path is as follows:
(0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
Example 2:

Input:
N=3, M=4
A=[[1,1,1,1],
   [0,0,0,1],
   [0,0,0,1]]
X=0, Y=3
Output:
3
Explanation:
The shortest path is as follows:
(0,0)->(0,1)->(0,2)->(0,3).
Your Task:
You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A 
as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. 
If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.

Expected Time Complexity:O(N*M)
Expected Auxillary Space:O(N*M)

Constraints:
1 <= N,M <= 250
0 <= X < N
0 <= Y < M
0 <= A[i][j] <= 1
*/

// Solution using BFS

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        queue<pair<int,int>>q;
        vector<vector<int>>vis(N, vector<int>(M, 0));
        int d=0;
        int dx[]={1, 0, -1, 0};
        int dy[]={0, -1, 0, 1};
        q.push({0,0});
        int n=q.size();
        while(!q.empty())
        {
             while(n)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==Y&&y==X)
                {
                    return d;
                }
                for(int i=0; i<4; i++)
                {
                    int tx=x+dx[i];
                    int ty=y+dy[i];
                    if(tx>=0&&ty>=0&&ty<N&&tx<M&&!vis[ty][tx]&&A[ty][tx])
                    {
                        q.push({tx, ty});
                        vis[ty][tx]=1;
                    }
                }
                n--;
            }
            n=q.size();
            d++;
        }
       
        return -1;
    }
};
