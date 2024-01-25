/*
You are given an undirected graph of N nodes (numbered from 0 to N-1) and M edges. Return 1 if the graph is a tree, 
else return 0.

Note: The input graph can have self-loops and multiple edges.

Example 1:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [1, 3]]
Output: 
1
Explanation: 
Every node is reachable and the graph has no loops, so it is a tree
Example 2:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [2, 0]]
Output: 
0
Explanation: 
3 is not connected to any node and there is a loop 0->1->2->0, so it is not a tree.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function isTree() which takes the 
integer N (the number nodes in the input graph) and the edges representing the graph as input parameters and returns 1 
if the input graph is a tree, else 0.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 2*105
0 <= M <= 2*105

*/

// Solution using BFS

class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &arr) {
        vector<vector<int>>adj(n);
        for(int i=0; i<m; i++)
        {
            adj[arr[i][0]].push_back(arr[i][1]);
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        vector<int>vis(n, 0);
        queue<pair<int,int>>q;
        q.push({0,-1});
        vis[0]=1;
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push({it, node});
                }
                else
                {
                    if(it!=parent)
                        return 0;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
                return 0;
        }
        return 1;
    }
};


// Solution using DFS

class Solution {
  public:
    bool dfs(int node, int parent, vector<vector<int>>&adj, vector<bool>& vis)
    {
        vis[node]=true;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, node, adj, vis))
                    return true;
            }
            else
            {
                if(it!=parent) // if it !=parent then it is visisted from other nodes which means there is a cycle
                    return true;
            }
        }
        return false;
    }
    int isTree(int n, int m, vector<vector<int>> &arr) {
        // code here
        vector<vector<int>>adj(n);
        for(int i=0; i<m; i++)
        {
            adj[arr[i][0]].push_back(arr[i][1]);
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        vector<bool>vis(n,false);
        if(dfs(0, -1, adj, vis))
            return 0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
                return 0;
        }
        return 1;
    }
};
