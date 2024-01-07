/*Problem GFG (Medium)

Merge 2 sorted linked list in reverse order


Question link: https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1

---------------------------

Logic: Linked List

---------------------------

Complexity: 

Method 1 : Linked List

Time Complexity= O(N + M)

Space Complexity= O(1) 
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Linked List
*/

class Solution
{
    public:
    struct Node* reverse(Node* head)
    {
        Node* prev=NULL;
        Node* curr=head;
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
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        Node* dummy=new Node;
        dummy->data=-1;
        dummy->next=NULL;
        
        Node* temp=dummy;
        
        while(node1 && node2)
        {
            if(node1->data<=node2->data)
            {
                temp->next=node1;
                node1=node1->next;
            }
            else
            {
                temp->next=node2;
                node2=node2->next;
            }
            temp=temp->next;
        }
        
        if(node1)
        temp->next=node1;
        
        if(node2)
        temp->next=node2;
        
        return reverse(dummy->next);
    }  
};