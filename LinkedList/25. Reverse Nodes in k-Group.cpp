/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, 
should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
  */

// Solution using a dummy node. T.C- O(N)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *dum=new ListNode(0);
        dum->next=head;
        ListNode *cur=dum, *prev=dum, *nex=dum;
        int c=0;
        cur=cur->next;
        while(cur)
        {
            c++;
            cur=cur->next;
        }
        while(c>=k)
        {
            cur=prev->next;
            nex=cur->next;
            for(int i=1; i<k; i++)
            {
                cur->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=cur->next;
            }
            prev=cur;
            c-=k;
        }
        return dum->next;
    }
};
