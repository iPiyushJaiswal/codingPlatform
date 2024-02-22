/*Problem GFG (Medium)

Flatten BST to sorted list


Question link:	https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1

---------------------------

Logic: Tree

---------------------------

Complexity: 

Method 1 : Tree

Time Complexity= O(n)

Space Complexity= O(n) recursive stack
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Tree
*/

class Solution
{
public:
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    void inorder(Node* root)
    {
        if(!root)
        return ;
        inorder(root->left);
        temp->right=root;
        temp=temp->right;
        temp->left=NULL;
        inorder(root->right);
        
    }
    Node *flattenBST(Node *root)
    {
        // code here
        inorder(root);
        return dummy->right;
    }
};