/*Problem LeetCode (Easy)

141. Linked List Cycle


Question link: https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2023-09-04

Logic: slow fast pointer. One pass

Complexity: 

Method 1: slow fast pointer. One pass

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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        return false;
        ListNode* slow=head;
        ListNode* fast=head;
        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast && fast!=NULL && fast->next!=NULL);
        if(fast==NULL || fast->next==NULL)
        return false;
        return true;
    }
};