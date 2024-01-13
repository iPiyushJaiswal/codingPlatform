/*Problem GFG (Medium)

Insertion Sort for Singly Linked List


Question link: https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1

---------------------------

Logic: Sorting

---------------------------

Complexity: 

Method 1 : Sorting

Time Complexity= O(n*n)

Space Complexity= O(1) 
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Sorting
*/

class Solution
{
    public:
    Node* reverse(Node* dummy)
    {
        Node* curr=dummy;
        Node* prev=NULL;
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
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        Node* temp1=head_ref;
        Node* dummy=new Node(INT_MIN);
        Node* temp2;
        Node* nxt;
        while(temp1)
        {
            temp2=dummy;
            nxt=temp1->next;
            while(temp2->next && temp2->next->data>temp1->data)
            temp2=temp2->next;
            temp1->next=temp2->next;
            temp2->next=temp1;
            temp1=nxt;
        }
        return reverse(dummy->next);
    }
    
};