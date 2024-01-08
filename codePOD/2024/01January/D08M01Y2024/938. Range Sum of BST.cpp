/*Problem LeetCode (Easy)

938. Range Sum of BST


Question link: https://leetcode.com/problems/range-sum-of-bst/description/?envType=daily-question&envId=2024-01-08

Solution link: https://leetcode.com/problems/range-sum-of-bst/submissions/1140322798/?envType=daily-question&envId=2024-01-08


Logic : Inorder

--------------------------
Complexity: 

Method 1: Inorder

Time Complexity=O(n)

Space Complexity=O(n) recursive stack
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Inorder
*/

class Solution {
public:
int rec(TreeNode* root, int low, int high)
{
    if(!root)
    return 0;
    int a=0;
    a+=rec(root->left,low,high);
    if(low<=root->val && root->val<=high)
    a+=root->val;
    a+=rec(root->right,low,high);
    return a;
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        return rec(root,low,high);
    }
};