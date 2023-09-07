/*Problem LeetCode (Medium)

92. Reverse Linked List II


Question link: https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=daily-question&envId=2023-09-07

Logic: Linked List Traversal   

Complexity: 

Method 1: Linked List Traversal + Common sense. 

Time Complexity=O(n)

Space Complexity=O(1). 

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode*prev=dummy,*curr,*nxt;
        for(int i=0;i<left-1;i++)
        {
            prev=prev->next;
        }
        curr=prev->next;
        ListNode* head1=curr;
        ListNode* prev1=NULL;
        for(int i=0;i<=right-left;i++)
        {
            nxt=curr->next;
            curr->next=prev1;
            prev1=curr;
            curr=nxt;
        }
        prev->next=prev1;
        head1->next=curr;
        return dummy->next;
    }
};