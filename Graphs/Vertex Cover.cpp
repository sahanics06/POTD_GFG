/*
Vertex cover of an undirected graph is a list of vertices such that every vertex not in the vertex cover shares their every 
edge with the vertices in the vertex cover. In other words, for every edge in the graph, atleast one of the endpoints of the 
graph should belong to the vertex cover. You will be given an undirected graph G, and your task is to determine the smallest 
possible size of a vertex cover.

Example 1:

Input:
N=5
M=6
edges[][]={{1,2}
           {4, 1},
           {2, 4},
           {3, 4},
           {5, 2},
           {1, 3}}
Output:
3
Explanation:
{2, 3, 4} forms a vertex cover
with the smallest size.
Example 2:

Input:
N=2
M=1
edges[][]={{1,2}} 
Output: 
1 
Explanation: 
Include either node 1 or node 2
in the vertex cover.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function vertexCover() which takes the edge 
list and an integer n for the number of nodes of the graph as input parameters and returns the size of the smallest possible 
vertex cover.

Expected Time Complexity: O(M*N2log(N))
Expected Auxiliary Space: O(N2)

 Constraints:
1 <= N <= 16
1 <= M <= N*(N-1)/2
1 <= edges[i][0], edges[i][1] <= N

  */

// Solution

class Solution{
    public:
        int solve(vector<int>adj[], vector<int>vis, int count, int v_taken, int n, int m, int vertex)
        {
            if(count==m)
                return v_taken;
            if(vertex==n+1)
                return INT_MAX;
            int taken=INT_MAX, not_taken=INT_MAX;
            
            not_taken = solve(adj, vis, count, v_taken, n, m, vertex+1);
            count+=adj[vertex].size();
            for(auto it: adj[vertex])
            {
                if(vis[it])
                    count--;
            }
            vis[vertex]++;
            taken = solve(adj, vis, count, v_taken+1, n, m, vertex+1);
            return min(taken, not_taken);
        }
        int vertexCover(int n, vector<pair<int, int>> &edges) {
            int m=edges.size();
            vector<int>adj[n+1];
            for(auto it: edges)
            {
                adj[it.first].push_back(it.second);
                adj[it.second].push_back(it.first);
            }
            vector<int>vis(n+1, 0);
            int count=0, taken=0, vertex=1;
            return solve(adj, vis, count, taken, n, m, vertex);
    }
};
