/*Problem GFG (Easy)

Reverse a Doubly Linked List


Question link: https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

---------------------------

Logic: Reverse Doubly linked list

---------------------------

Complexity: 

Method 1 : 3 pointers

Time Complexity= O(n)

Space Complexity=O(1) 

-----------------------------
Method 2 : 2 pointers

Time Complexity= O(n)

Space Complexity= O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 3 pointers
*/

class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node* prev=NULL;
        Node* curr=head;
        Node* nxt;
        while(curr)
        {
            nxt=curr->next;
            curr->prev=nxt;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
};


/*-----------------------------------------------------------------------
Method 2 : 2 pointers
*/

class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        Node* temp;
        while(head)
        {
            temp=head->next;
            head->next=head->prev;
            head->prev=temp;
            if(!temp)
            break;
            head=head->prev;
        }
        return head;
    }
};