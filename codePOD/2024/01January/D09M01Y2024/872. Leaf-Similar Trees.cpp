/*Problem LeetCode (Easy)

872. Leaf-Similar Trees


Question link: https://leetcode.com/problems/leaf-similar-trees/?envType=daily-question&envId=2024-01-09

Solution link: https://leetcode.com/problems/leaf-similar-trees/submissions/?envType=daily-question&envId=2024-01-09


Logic : DFS

--------------------------
Complexity: 

Method 1: DFS

Time Complexity=O(n + m)

Space Complexity=O(n + m) DFS vector
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DFS
*/

class Solution {
public:
    void dfs(TreeNode* root,vector<int>&leaf)
    {
        if(!root)
        return ;
        if(!root->left && !root->right)
        {
            leaf.push_back(root->val);
            return;
        }
        dfs(root->left,leaf);
        dfs(root->right,leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2)
        return false;
        vector<int>leaf1;
        dfs(root1,leaf1);
        vector<int>leaf2;
        dfs(root2,leaf2);
        int n=leaf1.size()-1;
        int m=leaf2.size()-1;
        if(n!=m)
        return false;
        while(n>=0 && m>=0)
        {
            if(leaf1[n]!=leaf2[m])
            return false;
            n--;
            m--;
        }
        return true;
    }
};