/*Problem GFG (Easy)

Kth largest element in BST


Question link: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

Complexity: 

Method 1: modified reverse INorder.

Time Complexity=O(min(k,n))

Space Complexity=O(height) recursive stack.

-----------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: modified reverse INorder.
*/

class Solution
{
    public:
    int dfs(Node* root,int& k)
    {
        if(!root)
        return -1;
        int a=dfs(root->right,k);
        k--;
        if(k==0)
        return root->data;
        int b=dfs(root->left,k);
        return max(a,b);
    }
    int kthLargest(Node *root, int K)
    {
        //Your code here
        return dfs(root,K);
    }
};