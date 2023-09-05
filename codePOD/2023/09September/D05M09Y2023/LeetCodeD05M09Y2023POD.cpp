/*Problem LeetCode (Medium)

138. Copy List with Random Pointer


Question link: https://leetcode.com/problems/copy-list-with-random-pointer/description/?envType=daily-question&envId=2023-09-05

Logic: Implementation

Complexity: 

Method 1: Implementation

Time Complexity=O(3*n)

Space Complexity=O(n). 

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
        return head;
        Node* temp=head;
        while(temp)
        {
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp)
        {
            temp->next->random=(temp->random!=NULL)?temp->random->next:NULL;
            temp=temp->next->next;
        }
        temp=head;
         Node* temp1=head->next;
        Node* head1=temp1;
        while(temp)
        {
            temp->next=temp->next->next;
            temp1->next=(temp1->next!=NULL)?temp1->next->next:NULL;
            temp=temp->next;
            temp1=temp1->next;
        }
        return head1;
    }
};