/*
Given a binary matrix mat[][] of dimensions NxM such that 1 denotes land and 0 denotes water. Find the number of closed islands in the given matrix.
Note: A closed island is a group of 1s surrounded by only 0s on all the boundaries (except diagonals). 
In simple words, a closed island is an island whose none of the 1s lie on the edges of the matrix.
Example 1:
Input:
N = 5, M = 8
mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 0, 1}, 
           {0, 1, 0, 1, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 1, 0}, 
           {1, 0, 0, 0, 0, 1, 0, 1}}
Output:
2
Explanation:
mat[][] = {{0, 0, 0, 0, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 0, 1}, 
           {0, 1, 0, 1, 0, 0, 0, 1}, 
           {0, 1, 1, 1, 1, 0, 1, 0}, 
           {1, 0, 0, 0, 0, 1, 0, 1}} 
There are 2 closed islands. The islands in dark are closed because they are completely surrounded by 0s (water). 
There are two more islands in the last column of the matrix, but they are not completely surrounded by 0s. Hence they are not closed islands. 
Example 2:
Input:
N = 3, M = 3
mat[][] = {{1, 0, 0},
           {0, 1, 0},
           {0, 0, 1}}
Output: 
1
Explanation:
mat[][] = {{1, 0, 0},
          {0, 1, 0},
          {0, 0, 1}}
There is just a one closed island.
Your task:
You dont need to read input or print anything. Your task is to complete the function closedIslands() which takes two integers N and M, and 
a 2D binary matrix mat as input parameters and returns the number of closed islands.
Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(N*M)
Constraints:
1 ≤ N,M ≤ 500
*/

// Solution using BFS

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        vector<vector<int>>vis(N, vector<int>(M, 0));
        int count=0;
        int dx[]={0, 1, 0, -1};
        int dy[]={1, 0, -1, 0};
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(matrix[i][j]==0)    continue;
                if(vis[i][j])  continue;
                bool yes=true;
                queue<pair<int,int>>q({{i,j}});
                vis[i][j]=1;
                while(!q.empty())
                {
                    int x=q.front().second;
                    int y=q.front().first;
                    q.pop();
                    for(int k=0; k<4; k++)
                    {
                        int tx=dx[k]+x;
                        int ty=dy[k]+y;
                        if(tx<0 || ty<0||tx>M-1|| ty>N-1)
                        {
                            yes=false;  // If node is at edge then mark false and continue finding the nodes adjacent to this nodes.
                            continue;
                        }
                        if(vis[ty][tx]) continue;
                        if(!vis[ty][tx]&&matrix[ty][tx])
                        {
                            vis[ty][tx]=1;
                            q.push({ty,tx});
                        }
                    }
                }
                if(yes) // If the whole traversed nodes in BFS are closed then we increment count by one.
                {
                    count++;
                }
                
            }
        }
        return count;
    }
};
