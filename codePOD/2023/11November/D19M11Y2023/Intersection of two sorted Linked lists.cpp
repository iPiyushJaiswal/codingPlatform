/*Problem GFG (Easy)

Intersection of two sorted Linked lists


Question link: https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

---------------------------

Logic: 2 pointers

---------------------------

Complexity: 

Method 1 : 2 pointers

Time Complexity= O(min(n,m))

Space Complexity= O(min(n,m))

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 2 pointers
*/

class Solution
{
    public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        // code goes here.
        Node* dummy=new Node(-1);
        Node* temp1=head1;
        Node* temp2=head2;
        Node*temp=dummy;
        while(temp1 && temp2)
        {
            if(temp1->data==temp2->data)
            {
                temp->next=new Node(temp1->data);
                temp=temp->next;
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1->data<temp2->data)
            temp1=temp1->next;
            else
            temp2=temp2->next;
        }
        return dummy->next;
    }
};