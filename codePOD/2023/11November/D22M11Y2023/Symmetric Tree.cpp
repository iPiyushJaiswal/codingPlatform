/*Problem GFG (Easy)

Symmetric Tree


Question link: https://www.geeksforgeeks.org/problems/symmetric-tree/1

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

class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool check(Node* left1,Node* right1)
    {
        if(!left1 && !right1)
        return true;
        if(!left1 || !right1)
        return false;
        return (left1->data==right1->data) && 
        check(left1->left,right1->right) && 
        check(left1->right,right1->left);
    }
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(!root)
	    return true;
	    Node* left1=root->left;
	    Node* right1=root->right;
	    return check(left1,right1);
    }
};