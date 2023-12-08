/*Problem LeetCode (Easy)

606. Construct String from Binary Tree


Question link: https://leetcode.com/problems/construct-string-from-binary-tree/description/?envType=daily-question&envId=2023-12-08

Solution link: https://leetcode.com/problems/construct-string-from-binary-tree/submissions/1114843178/?envType=daily-question&envId=2023-12-08


Logic : PreOrder

--------------------------

Complexity: 

Method 1: PreOrder

Time Complexity=O(n)

Space Complexity=O(n) recursive stack
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: PreOrder
*/

class Solution {
public:
    void preorder(TreeNode* root,string& ans)
    {
        if(!root)
        return;
        ans+=to_string(root->val);
        if(!root->left && !root->right)
        return ;
        ans+='(';
        preorder(root->left,ans);
        ans+=')';
        if(root->right)
        {
          ans+='(';
          preorder(root->right,ans);
          ans+=')';
        }
    }
    string tree2str(TreeNode* root) {
        string ans;
        preorder(root,ans);
        return ans;
    }
};