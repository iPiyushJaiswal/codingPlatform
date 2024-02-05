/*Problem GFG (Easy)

Sorted insert for circular linked list


Question link:	https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

---------------------------

Logic: Circular Linked List.

---------------------------

Complexity: 

Method 1 : CLL 

Time Complexity= O(n)

Space Complexity= O(1)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: CLL 
*/

class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       Node* newNode=new Node(data);
       if(!head)
       {
           newNode->next=newNode;
           head=newNode;
           return head;
       }
       if(head->data>data)
       {
           newNode->next=head;
           Node* curr=head;
           while(curr->next!=head)
           {
               curr=curr->next;
           }
           curr->next=newNode;
           head=newNode;
           return head;
       }
        Node* curr = head;
        while (curr->next != head && curr->next->data < data) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        return head;
    }
};