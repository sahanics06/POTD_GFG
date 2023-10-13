/*
You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of 
the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

Example:

Input:
n = 7               2
                     \
                      81
                    /     \
                 42       87
                   \       \
                    66      90
                   /
                 45
x = 87
Output:
87
Explanation:
87 is present in tree so floor will be 87.
Example 2:

Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 11
Output:
9
Your Task:-
You don't need to read input or print anything. Complete the function floor() which takes the integer n and BST and 
integer x returns the floor value.

Constraint:
1 <= Noda data <= 109
1 <= n <= 105

Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/

//********************************************************************************************************

// Solution

class Solution{

public:
    int ms=INT_MAX;
    int mx=INT_MAX;
    void solve(Node *root, int x, int mn)
    {
        if(root==NULL)
        {
            ms=mn; // If we reach NULL, means the value sent in mn is the floor value i.e value less than target
            return;
        }
        if(mx>=root->data) // IN mx we keep atleast one minimum value from target from the BST
        {
            mx=root->data;
        }
        if(root->data==x)
        {
            ms=root->data;
            return;
        }
        if(x>root->data)
        {
            ms=root->data;
            solve(root->right, x, root->data);   // Here we sent root->data because if we go right means the root value 
                                                 // becomes the floor value for the subtree which will be our answer
        }
        else
            solve(root->left, x, mn);  // here we sent the previus value of mn because that is the minimum till now 
                                       // for the subtree since we might go in right direction in the later subtree
    }
    int floor(Node* root, int x) {
        // Code here
        solve(root, x, 0);
        return x<mx?-1:ms;
    }
};
