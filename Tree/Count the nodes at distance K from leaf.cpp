/*
Given a binary tree with n nodes and a non-negative integer k, the task is to count the number of special nodes.
A node is considered special if there exists at least one leaf in its subtree such that the distance between the node and 
leaf is exactly k.

Note: Any such node should be counted only once. For example, if a node is at a distance k from 2 or more leaf nodes, 
then it would add only 1 to our count.

Example 1:

Input:
Binary tree
        1
      /   \
     2     3
   /  \   /  \
  4   5  6    7
          \ 
          8
k = 2
Output: 
2
Explanation: 
There are only two unique nodes that are at a distance of 2 units from the leaf node. (node 3 for leaf with value 8 and 
node 1 for leaves with values 4, 5 and 7) Note that node 2 isn't considered for leaf with value 8 because it isn't a direct 
ancestor of node 8.
Example 2:

Input:
Binary tree
          1
         /
        3
       /
      5
    /  \
   7    8
         \
          9
k = 4
Output: 
1
Explanation: 
Only one node is there which is at a distance of 4 units from the leaf node.(node 1 for leaf with value 9) 
Your Task:
You don't have to read input or print anything. Complete the function printKDistantfromLeaf() that takes root node and 
k as inputs and returns the number of nodes that are at distance k from a leaf node. 

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= n <= 105

  */

// Solution- Using DFS; using set and vector for visited vector; T.C- O(N); Space- O(height of tree)

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    void dfs(Node *root, unordered_set<Node*>&st, vector<Node*>&vec, int k, int level)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            if(k==0)
            {
                st.insert(root);
            }
            else if(level-k>=0)
            {
                st.insert(vec[level-k]);
            }
            return;
        }
        vec.push_back(root);
        dfs(root->left, st, vec, k, level+1);
        dfs(root->right, st, vec, k, level+1);
        vec.pop_back();
        return;
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here. 
    	unordered_set<Node*>st;
    	vector<Node*> vec;
    	dfs(root, st, vec, k, 0);
    	return st.size();
    }
};


// Solution using BFS. TLE. Space- O(N), T.C- O(N^2).

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    bool isLeaf(Node* root)
    {
        if(root->left==NULL && root->right==NULL)
            return true;
        return false;
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here. 
    	unordered_map<Node*, int>mp;
    	queue<pair<Node*, pair<Node*, int>>>q;
    	int ans=0;
    	q.push({root,{root, 0}});
    	while(!q.empty())
    	{
    	    Node *parent=q.front().first;
    	    Node *node =q.front().second.first;
    	    int d=q.front().second.second;
    	    //cout<<d<<endl;
    	    q.pop();
    	    if(isLeaf(node))
    	    {
    	        //cout<<node->data<<endl;
    	        if(k==0 && mp.find(parent)==mp.end() && mp.find(node)==mp.end())
    	        {
    	            mp[node]=1;
    	            ans++;
    	        }
    	        else if(d==k && mp.find(parent)==mp.end())
    	        {
    	            //cout<<node->data<<endl;
    	            mp[parent]=1;
    	            ans++;
    	        }
    	    }
    	    else
    	    {
    	        if(node->left)
    	        {
    	            q.push({parent, {node->left, d+1}});
    	            q.push({node, {node->left, 1}});
    	        }
    	        if(node->right)
    	        {
    	            q.push({parent, {node->right, d+1}});
    	            q.push({node, {node->right, 1}});
    	        }
    	    }
    	}
    	return ans;
    }
};
