/*
Given a binary tree and the task is to find the spiral order traversal of the tree.

Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels 
we print the node's value from left to right. 

For below tree, function should return 1, 2, 3, 4, 5, 6, 7.

Example 1:

Input:
      1
    /   \
   3     2
Output:1 3 2

Example 2:

Input:
           10
         /     \
        20     30
      /    \
    40     60
Output: 10 20 30 60 40 
Your Task:
The task is to complete the function findSpiral() which takes root node as input parameter and returns the elements in spiral form of level order traversal as a list. 
The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 105
0 <= Data of a node <= 105
*/

// Solution

vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int>ans;
    int t=1;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        vector<int>tmp;
        while(n)
        {
            Node *x=q.front();
            tmp.push_back(x->data);
            n--;
            if(x->left)
            {
                q.push(x->left);
            }
            if(x->right)
            {
                q.push(x->right);
            }
            q.pop();
        }
        if(t)
        {
            reverse(tmp.begin(), tmp.end());
        }
        ans.insert(ans.end(), tmp.begin(), tmp.end());
        t=t^1;
    }
    return ans;
}
