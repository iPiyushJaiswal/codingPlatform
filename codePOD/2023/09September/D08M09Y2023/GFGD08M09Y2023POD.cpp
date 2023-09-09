/*Problem GFG (Easy)

Binary Tree to BST


Question link: https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1

Complexity: 

Method 1: Tree Traversal ->store value in vector ->sort vector ->inOrder Traversal.

Time Complexity=O(NlogN)

Space Complexity=O(N) value vector.

-----------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Tree Traversal ->store value in vector ->sort vector ->inOrder Traversal.
*/

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void treeTrav(Node* root,vector<int>&bt)
    {
        if(!root)
        return ;
        bt.push_back(root->data);
        treeTrav(root->left,bt);
        treeTrav(root->right,bt);
    }
    void inOrder(Node* root,vector<int>&bt,int &i)
    {
        if(!root)
        return ;
        inOrder(root->left,bt,i);
        root->data=bt[i];
        i++;
        inOrder(root->right,bt,i);
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int>bt;
        treeTrav(root,bt);
        sort(bt.begin(),bt.end());
        int i=0;
        inOrder(root,bt,i);
        return root;
    }
};