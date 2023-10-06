/*Problem GFG (Easy)

Pairwise swap elements of a linked list


Question link: https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1

---------------------------

Logic: Linked List reverse group of k logic

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

class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        Node* temp=head;
        for(int i=0;i<2;i++)
        {
            if(!temp)
            return head;
            temp=temp->next;
        }
        Node*prev=NULL;
        Node* curr=head;
        Node* nxt;
        int i=0;
        while(i<2)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            i++;
        }
        head->next=pairWiseSwap(nxt);
        return prev;
    }
};