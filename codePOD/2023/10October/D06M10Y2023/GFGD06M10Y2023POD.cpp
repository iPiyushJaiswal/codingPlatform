/*Problem GFG (Medium)

Reverse alternate nodes in Link List


Question link: https://practice.geeksforgeeks.org/problems/given-a-linked-list-reverse-alternate-nodes-and-append-at-the-end/1

---------------------------

Logic: Linked List

---------------------------

Complexity: 


Method 1: Linked List

Time Complexity=O(3n)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Linked List
*/

class Solution
{
    public:
    Node* reverse(Node* temp2)
    {
        Node* prev=NULL;
        Node* curr=temp2;
        Node* nxt;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        if(!odd || !odd->next)
        return;
        Node* head1=odd;
        Node* temp1=head1;
        Node* head2=odd->next;
        Node* temp2=head2;
        while(temp1 && temp1->next)
        {
            temp1->next=temp1->next->next;
            if(temp2->next)
            {temp2->next=temp2->next->next;
            temp2=temp2->next;}
            temp1=temp1->next;
        }
        if(temp2)
        temp2->next=NULL;
        head2=reverse(head2);
        if(!temp1)
        {
            temp1=odd;
            while(temp1->next)
            temp1=temp1->next;
        }
        temp1->next=head2;
    }
};