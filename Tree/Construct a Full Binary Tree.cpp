/*
Given two arrays that represent Preorder traversals of a Full binary tree preOrder[] and its mirror tree preOrderMirror[], your task is to complete the function constructBinaryTree(), that constructs the full binary tree using these two Preorder traversals.

Note: It is not possible to construct a general binary tree using these two traversal. But it is possible to create a full binary tree using the above traversals without any ambiguity.

Example 1:

Input :
preOrder[] = {0,1,2}
preOrderMirror[] = {0,2,1} 

Output :
                0
              /   \
             1     2
Explanation :
Tree in the output and it's mirror tree matches the preOrder and preOrderMirror.
Example 2:

Input :  
preOrder[] = {1,2,4,5,3,6,7}
preOrderMirror[] = {1,3,7,6,2,5,4}

Output :          
                 1
               /    \
              2      3
            /   \   /  \
           4     5 6    7
Explanation :
Tree in the output and it's mirror tree matches the preOrder and preOrderMirror.
Your Task:

You don't need to read, input, or print anything. Your task is to complete the function constructBTree, The function takes three arguments as input, first the array that represent Preorder traversals of a Full binary tree preOrder[], second the array that represents the preorder traversal of its mirror tree preOrderMirror[] and last the size of both the array,and returns root of the full binary tree.

Expected Time Complexity: O(N^2)
Expected Auxiliary Space: O(N), where N indicates number of nodes.

Constraints:
1 <= Number of Nodes <= 103
*/

// Solution --- We start from first element in Pre array and find the element in the PreMirror array. In PreMirror when we find the element from Pre array, we see that
//              elements to the right are left part of the element in the tree and the elements to left are the right part of the tree.

class Solution{
  public:
    Node* solve(int& index, int start, int end, int pre[], int preMirror[], int size)
    {
        if(index>=size || start>end)
        {
            return NULL;
        }
        if(index==size-1 || start==end)
        {
            Node* tmp=new Node(pre[index]);
            index++;
            return tmp;
        }
        Node *tmp=new Node(pre[index]);
        index++;
        for(int i=start; i<=end; i++)
        {
            if(preMirror[i]==pre[index])
            {
                tmp->left=solve(index, i, end, pre, preMirror, size);
                tmp->right=solve(index, start+1, i-1, pre, preMirror, size);
                break;
            }
        }
        return tmp;
    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        int index=0;
        return solve(index, 0, size-1, pre, preMirror, size);
    }
};
