/*Problem LeetCode (Medium)

1026. Maximum Difference Between Node and Ancestor


Question link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/?envType=daily-question&envId=2024-01-11

Solution link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/submissions/1143211052/?envType=daily-question&envId=2024-01-11


Logic : DFS

--------------------------
Complexity: 

Method 1: DFS

Time Complexity=O(n)

Space Complexity=O(n) recursive stack
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DFS
*/

class Solution {
public:
    void dfs(TreeNode* root,int &ans,int maxi,int mini)
    {
        if(!root)
        return;
        ans=max(ans,abs(maxi-root->val));
        ans=max(ans,abs(mini-root->val));
        dfs(root->left,ans,max(maxi,root->val),min(mini,root->val));
        dfs(root->right,ans,max(maxi,root->val),min(mini,root->val));
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        dfs(root,ans,root->val,root->val);
        return ans;
    }
};