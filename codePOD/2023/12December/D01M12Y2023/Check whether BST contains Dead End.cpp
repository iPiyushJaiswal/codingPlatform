/*Problem GFG (Easy)

Check whether BST contains Dead End


Question link: https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

---------------------------

Logic: Tree

---------------------------

Complexity: 

Method 1 : Tree

Time Complexity= O(n)

Space Complexity= O(n)  recursive stack

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Tree
*/

class Solution{
  public:
  bool rec(Node* root,int mini,int maxi)
  {
      if(!root)
      return false;
      if(maxi-mini==0)
      return true;
      return rec(root->left,mini,root->data-1) || rec(root->right,root->data+1,maxi);
  }
    bool isDeadEnd(Node *root)
    {
        //Your code here
        return rec(root,1,INT_MAX);
    }
};