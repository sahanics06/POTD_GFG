/*
A critical connection refers to an edge that, upon removal, will make it impossible for certain nodes to reach each other through any path. You are given an undirected connected graph with v vertices and e edges and each vertex distinct and ranges from 0 to v-1, and you have to find all critical connections in the graph. It is ensured that there is at least one such edge present.

Note: The answers may be presented in various potential orders. Each edge should be displayed in sorted order. For instance, if there's an edge between node 1 and node 2, it should be stored as (1,2) rather than (2,1). Additionally, it is expected that you store the edges in sorted order.

Example 1:

Input:

Output:
0 1
0 2
Explanation: 
On removing edge (0, 1), you will not be able to
reach node 0 and 2 from node 1. Also, on removing
edge (0, 2), you will not be able to reach node 0
and 1 from node 2.
Example 2:

Input:

Output:
2 3
Explanation:
The edge between nodes 2 and 3 is the only
Critical connection in the given graph.
Your task:
You dont need to read input or print anything. Your task is to complete the function criticalConnections() which takes the integer v denoting the number of vertices and an adjacency list adj as input parameters and returns  a list of lists containing the Critical connections in the sorted order.

Expected Time Complexity: O(v + e)
Expected Auxiliary Space: O(v)

Constraints:
1 ≤ v, e ≤ 104


  */

// Solution

class Solution {
public:
    void dfs(vector<int> adj[], vector<vector<int>>&ans, vector<int>&lowtime, int node, int parent, int timer)
    {
        lowtime[node] = timer;
        int parentTime = timer;
        timer++;
        for(auto x:adj[node])
        {
            if(x==parent)
                continue;
            else if(!lowtime[x])
            {
                dfs(adj, ans, lowtime, x, node, timer);
            }
            lowtime[node]=min(lowtime[node], lowtime[x]);
            if(parentTime<lowtime[x]) // Critical section
            {
                if(node<x)
                {
                    ans.push_back({node, x});
                }
                else
                {
                    ans.push_back({x, node});
                }
            }
        }
    }
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    // Code here
	    vector<vector<int>>ans;
	    vector<int>lowtime(v, 0);
	    dfs(adj, ans, lowtime, 0, -1, 1);
	    sort(ans.begin(), ans.end());
	    return ans;
	}
};
