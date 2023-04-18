/*
Given a binary tree and a target, find the number of node in the minimum sub-tree with the given sum equal to the target which is also a binary search tree.

Example 1:

Input:
           13
         /    \
       5       23
      / \      / \
     N   17   N   N
         /
        16
Target: 38
Output: 3
Explanation: 5,17,16 is the smallest subtree
with length 3.
 

Example 2:

Input:
             7
           /   \
          N    23
             /   \
            10    23
           /  \   / \
          N   17 N   N
Target: 73
Output: -1
Explanation: No subtree is bst for the given target.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minSubtreeSumBST() which takes the tree root and target as input parameters which is a binary Tree and returns the length of the minimum subtree having a sum equal to the target but which is a binary search tree.

Expected Time Complexity: O(N), where N is no. of nodes
Expected Space Complexity: O(h), where h is the height of the tree

Constraints:
1 <= N <= 10^5

*/

class Solution {
public:
    vector<int> help(Node *root, int target, int &ans)
    {
        if(!root)   return {1, 0, 0, INT_MAX, INT_MIN};
        vector<int>l=help(root->left, target, ans);
        vector<int>r=help(root->right, target, ans);
        if(root->data<=l[4] || root->data>=r[3])    return {0, 0, 0, 0, 0};
        int sum=root->data+l[2]+r[2];
        int n=1+l[1]+r[1];
        if(l[0]==1 && r[0]==1 && sum==target)
        {
            ans=min(ans,n);
        }
        return {l[0]&r[0], n, sum, min(l[3], root->data), max(r[4], root->data)};
    }
    int minSubtreeSumBST(int target, Node *root) {
        // code here
        int ans=INT_MAX;
        vector<int> tmp=help(root, target, ans);
        if(tmp[0]==1 && tmp[2]==target)
        {
            ans=min(ans, tmp[1]);
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};
