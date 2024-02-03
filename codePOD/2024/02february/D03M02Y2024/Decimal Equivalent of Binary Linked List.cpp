/*Problem GFG (Easy)

Decimal Equivalent of Binary Linked List


Question link:	https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1

---------------------------

Logic: LL 

---------------------------

Complexity: 

Method 1 : LL 

Time Complexity= O(n)

Space Complexity= O(1)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: LL 
*/

class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           // Your Code Here
           int mod=1e9+7;
           long long unsigned int ans=0;
           while(head)
           {
               ans=(ans*2 + head->data)%mod;
               head=head->next;
           }
           return ans;
        }
};