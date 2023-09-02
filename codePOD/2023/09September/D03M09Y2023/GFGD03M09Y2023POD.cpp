/*Problem GFG (Easy)

Check if Tree is Isomorphic


Question link: https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1

Complexity: 

Method 1: Tree Traversal

Time Complexity=O(min(h1,h2)*2)

Space Complexity=O(min(h1,h2))

-----------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Tree Traversal
*/

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
    //add code here.
    if(!root1 && !root2)
    return true;
    if((!root1 && root2)||(root1 && !root2)||
    (root1->data!=root2->data))
    return false;
    return ((isIsomorphic(root1->left,root2->right)&&
    isIsomorphic(root1->right,root2->left))||
    (isIsomorphic(root1->left,root2->left)&&
    isIsomorphic(root1->right,root2->right)));
    }
};