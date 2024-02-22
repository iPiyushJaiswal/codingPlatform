/*Problem GFG (Easy)

Sum of leaf nodes in BST


Question link:	https://geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1

---------------------------

Logic: Traversal

---------------------------

Complexity: 

Method 1 : Traversal

Time Complexity= O(n)

Space Complexity= O(h) height of BST
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Traversal
*/

class Solution
{
    public:
        int rec(Node* root)
        {
            if(!root)
            return 0;
            if(!root->left && !root->right)
            return root->data;
            int a=rec(root->left);
            int b=rec(root->right);
            return a+b;
        }
        /*You are required to complete below method */
        int sumOfLeafNodes(Node *root ){
             /*Your code here */
             return rec(root);
        }
};