/*Problem GFG (Easy)

Insert in a Sorted List


Question link: https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1

---------------------------

Logic: Linked List

---------------------------

Complexity: 


Method 1: Linked List

Time Complexity=O(n)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Linked List
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node* newNode=new Node(data);
        Node* temp=head;
        if(!temp || temp->data>data)
        {
            newNode->next=temp;
            head=newNode;
            return head;
        }
        while(temp->next && temp->next->data<data)
        {
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        return head;
    }
};