/*
Given a binary tree with n nodes, determine whether all the leaf nodes are at the same level or not. 
Return true if all leaf nodes are at the same level, and false otherwise.

Example 1:

Input:
Tree:
    1
   / \
  2   3
Output:
true
Explanation:
The binary tree has a height of 2 and the leaves are at the same level.
Example 2:

Input:
Tree:
    10
   /  \
 20   30
 /  \
 10   15
Output:
false
Explanation:
The binary tree has a height of 3 and the leaves are not at the same level.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of tree)

Your Task:
Implement the function check() that checks whether all the leaf nodes in the given binary tree are at the same level or not. 
The function takes the root node of the tree as an input and should return a boolean value (true/false) based on the 
condition.

Constraints:
1 ≤ n ≤ 105

  */

// Solution 

class Solution{
  public:
    /*You are required to complete this method*/
    void solve(Node *root, int d, int &mx, int &mn)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL)
        {
            mx=max(mx, d);
            mn=min(mn, d);
        }
        solve(root->left, d+1, mx, mn);
        solve(root->right, d+1, mx, mn);
    }
    bool check(Node *root)
    {
        int mx=INT_MIN, mn=INT_MAX;
        solve(root, 0, mx, mn);
        return mx==mn;
    }
};


// Solution

/* The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    /*You are required to complete this method*/
    void solve(Node *root, vector<int>&ans, int d)
    {
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(d);
        }
        d++;
        solve(root->left, ans, d);
        solve(root->right, ans, d);
        d--;
    }
    bool check(Node *root)
    {
        //Your code here
        vector<int>ans;
        solve(root, ans, 0);
        int c=ans[0];
        for(int i=1; i<ans.size(); i++)
        {
            if(ans[i]!=c)
                return false;
        }
        return true;
    }
};
