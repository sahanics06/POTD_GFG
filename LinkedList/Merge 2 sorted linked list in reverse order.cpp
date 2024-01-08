/*
Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way 
that the resulting list is in non-increasing order.

Example 1:

Input:
N = 2, M = 2
list1 = 1->3
list2 = 2->4
Output:
4->3->2->1
Explanation:
After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.
Example 2:

Input:
N = 4, M = 3
list1 = 5->10->15->40 
list2 = 2->3->20
Output:
40->20->15->10->5->3->2
Explanation:
After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.
Your Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns 
the pointer to the merged linked list.

Expected Time Complexity : O(N+M)
Expected Auxiliary Space : O(1)

Constraints:
0 <= N, M <= 104

*/

// Solution 

class Solution
{
    public:
    
    Node *reverse(Node *head)
    {
        Node *prev=NULL, *cur=head;
        while(cur)
        {
            Node *tmp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=tmp;
        }
        return prev;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        if(node1==NULL)
            return reverse(node2);
        if(node2==NULL)
            return reverse(node1);
        Node *head1 = reverse(node1);
        Node *head2 = reverse(node2);
        Node *tmp = new Node();
        Node *cur = tmp;
        while(head1 && head2)
        {
            if(head1->data > head2->data)
            {
                cur->next=head1;
                cur=head1;
                head1=head1->next;
            }
            else
            {
                cur->next=head2;
                cur=head2;
                head2=head2->next;
            }
        }
        if(head1)
        {
            cur->next=head1;
        }
        if(head2)
        {
            cur->next=head2;
        }
        return tmp->next;
    }  
};
