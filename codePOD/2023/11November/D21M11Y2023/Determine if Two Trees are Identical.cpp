/*Problem GFG (Easy)

Determine if Two Trees are Identical


Question link: https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

---------------------------

Logic: tree traversal

---------------------------

Complexity: 

Method 1 : tree traversal

Time Complexity= O(n))

Space Complexity= O(h) recursive stack

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: tree traversal
*/

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        if(!r1 && !r2)
        return true;
        if(!r1 || !r2)
        return false;
        return (r1->data==r2->data) && 
        isIdentical(r1->left,r2->left) && 
        isIdentical(r1->right,r2->right) ;
    }
};