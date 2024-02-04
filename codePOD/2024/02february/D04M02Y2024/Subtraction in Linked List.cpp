/*Problem GFG (Hard)

Subtraction in Linked List


Question link:	https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1

---------------------------

Logic: LL 

---------------------------

Complexity: 

Method 1 : LL 

Time Complexity= O(n)

Space Complexity= O(n)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: LL 
*/

class Solution {
public:
    Node* reverse(Node** head1,Node** head2,int& maxi)
    {
        Node* curr1=*head1;
        Node* curr2=*head2;
        Node * prev1=NULL;
        Node* nxt1;
        Node * prev2=NULL;
        Node* nxt2;
        int count1=0,count2=0;
        while(curr1 && curr2)
        {
            if(maxi==0)
            {
                if(curr1->data>curr2->data)
                maxi=1;
                else if(curr1->data<curr2->data)
                maxi=2;
            }
            nxt1=curr1->next;
            curr1->next=prev1;
            prev1=curr1;
            curr1=nxt1;
            nxt2=curr2->next;
            curr2->next=prev2;
            prev2=curr2;
            curr2=nxt2;
            count1++;
            count2++;
            // cout<<prev1->data<<" "<<prev2->data<<" ";
        }
        while(curr1)
        {
            count1++;
            nxt1=curr1->next;
            curr1->next=prev1;
            prev1=curr1;
            curr1=nxt1;
        }
        while(curr2)
        {
            count2++;
            nxt2=curr2->next;
            curr2->next=prev2;
            prev2=curr2;
            curr2=nxt2;
        }
        *head1=prev1;
        *head2=prev2;
        if(count1>count2)
        maxi=1;
        else if(count1<count2)
        maxi=2;
    }
    Node* sub(Node* curr1, Node* curr2) {
    int bor = 0;
    int val = 0;
    Node* temp = NULL;
    
    while (curr1 && curr2) {
        val = curr1->data - curr2->data - bor;
        if (val < 0) {
            val += 10;
            bor = 1;
        } else {
            bor = 0;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
        Node* newNode = new Node(val);
        newNode->next = temp;
        temp = newNode;
    }
    
    while (curr1) {
        val = curr1->data - bor;
        if (val < 0) {
            val += 10;
            bor = 1;
        } else {
            bor = 0;
        }
        curr1 = curr1->next;
        Node* newNode = new Node(val);
        newNode->next = temp;
        temp = newNode;
    }
    
    while (temp && temp->data == 0) {
        Node* del = temp;
        temp = temp->next;
        delete del;
    }
    
    return temp;
}

    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        if(!head1)
        return head2;
        if(!head2)
        return head1;
        while(head1 && head1->data==0)
        head1=head1->next;
        while(head2 && head2->data==0)
        head2=head2->next;
        
        if(!head1 && !head2)
        return new Node(0);
        if(!head1)
        return head2;
        if(!head2)
        return head1;
        
        int maxi=0;
        reverse(&head1,&head2,maxi);
        
        // Node*temp=head1;
        // while(temp)
        // {
        //     cout<<temp->data<<" ";
        //     temp=temp->next;
        // }
        if(maxi==0)
        return new Node(0);
        Node* ans=NULL;
        if(maxi==1)
        ans=sub(head1,head2);
        // cout<<"hi";
        else if(maxi==2)
        ans=sub(head2,head1);
        return ans;
    }
};