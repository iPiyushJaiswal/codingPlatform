/*Problem LeetCode (Medium)

501. Find Mode in Binary Search Tree


Question link: https://leetcode.com/problems/find-mode-in-binary-search-tree/?envType=daily-question&envId=2023-11-01


Logic:BST

-------------------------

Complexity: 

Method 1:  BST

Time Complexity=O(n)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : BST
*/

class Solution {
public:
    vector<int>ans;
    int prev=INT_MAX;
    int maxi=0,count=0;
    void inorder(TreeNode* root)
    {
        if(!root)
        return;
        inorder(root->left);
        if(root->val==prev)
        count++;
        else
        {
            prev=root->val;
            count=1;
        }
        if(maxi<count)
        {
            ans.clear();
            ans.push_back(root->val);  
            maxi=count;
        }
        else if(maxi==count)
        ans.push_back(root->val);
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};