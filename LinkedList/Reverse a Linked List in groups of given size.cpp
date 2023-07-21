/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
Example 2:

Input:
LinkedList: 1->2->3->4->5
K = 3
Output: 3 2 1 5 4 
Explanation: 
The first 3 elements are 1,2,3 are reversed 
first and then elements 4,5 are reversed.Hence, 
the resultant linked list is 3->2->1->5->4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function reverse() which should reverse the linked list in group of size k and return the head of the modified linked list.

Expected Time Complexity : O(N)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 105
1 <= k <= N
  */

// Solution using loop. T.C- O(N), Space- O(1).

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        node *cur=head, *prev=NULL, *nxt, *new_head=NULL, *prev_head=NULL;
        while(cur)
        {
            int c=0;
            node *h=cur;// Store head for every outer loop
            while(cur && c<k)
            {
                nxt=cur->next;
                cur->next=prev;
                prev=cur;
                cur=nxt;
                c++;
            }
            if(!new_head)
            {
                new_head=prev;
            }
            if(prev_head) // for first loop we have nothing to link wiht 
            //the tail node since prev_head is NUll for initial loop . 
            //IN second loop we have prev head to add so we link that with prev
                prev_head->next=prev;
            prev_head=h;
            prev=NULL;
        }
        return new_head;
    }
};


// Solution using loop. T.C- O(N), Space- O(N)- for using recursion stack.

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head==NULL ||head->next==NULL)
            return head;
        int c=0;
        node *cur=head, *prev=NULL, *next;
        while(cur&&c<k)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            c++;
        }
        if(next)
            head->next=reverse(next, k);
        return prev;
    }
};
