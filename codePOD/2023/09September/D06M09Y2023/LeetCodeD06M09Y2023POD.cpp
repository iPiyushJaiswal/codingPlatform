/*Problem LeetCode (Medium)

725. Split Linked List in Parts


Question link: https://leetcode.com/problems/split-linked-list-in-parts/description/?envType=daily-question&envId=2023-09-06

Logic: Normal Maths 

Complexity: 

Method 1: Normal Maths 

Time Complexity=O(2n)

Space Complexity=O(1). 

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------
*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int length=0;
        while(temp)
        {
            length++;
            temp=temp->next;
        }
        vector<ListNode*>ans;
        int size=length/k;
        int rem=length%k;
        ListNode* nxt=NULL;
        for(int i=0;i<k;i++)
        {
            ListNode* t=head;
            int x=0;
            if(rem>0)
            {
                x=1;
                rem--;
            }
            for(int j=0;j<size+x-1;j++)
            {
                if(!t)
                break;
                t=t->next;
            }
            if(t)
            {nxt=t->next;
            t->next=NULL;}
            ans.push_back(head);
            head=nxt;
        }
        return ans;
    }
};