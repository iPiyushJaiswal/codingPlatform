/*Problem LeetCode (Easy)

543. Diameter of Binary Tree


Question link: https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-27

Solution link: https://leetcode.com/problems/diameter-of-binary-tree/submissions/1187362000/?envType=daily-question&envId=2024-02-27


Logic : Tree

--------------------------
Complexity: 

Method 1: Tree

Time Complexity=O(n)

Space Complexity=O(h)height of tree recursive stack
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Tree
*/

class Solution {
public:
    int rec(TreeNode* root,int& ans)
    {
        if(!root)
        return 0;

        int l=rec(root->left,ans);
        int r=rec(root->right,ans);
        ans=max(ans,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN;
        rec(root,ans);
        return ans;
    }
};