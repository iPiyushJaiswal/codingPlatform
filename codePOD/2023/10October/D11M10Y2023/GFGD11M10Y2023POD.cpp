/*Problem GFG (Easy)

Check for Balanced Tree


Question link: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

---------------------------

Logic: Tree

---------------------------

Complexity: 


Method 1: Tree

Time Complexity=O(n)

Space Complexity=O(height of tree) recursive stack

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Tree
*/

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int dfs(Node* root)
    {
        if(!root)
        return 0;
        int a=dfs(root->left);
        int b=dfs(root->right);
        if(a==INT_MIN || b==INT_MIN || abs(a-b)>1)
        return INT_MIN;
        return 1 + max(a,b);
    }
    bool isBalanced(Node *root)
    {
        //  Your Code here
        int val=dfs(root);
        if(val==INT_MIN)
        return false;
        return true;
    }
};