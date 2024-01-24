/*Problem LeetCode (Medium)

1457. Pseudo-Palindromic Paths in a Binary Tree


Question link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24

Solution link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/submissions/1155340929/?envType=daily-question&envId=2024-01-24


Logic : Tree Traversal

--------------------------
Complexity: 

Method 1: Tree Traversal

Time Complexity=O(n)

Space Complexity=O(height) recursive stack 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Tree Traversal
*/

class Solution {
public:
    bool isSafe(vector<int>&temp)
    {
        int sum=0;
        for(int i=1;i<10;i++)
        {
            if(sum%2!=0 && temp[i]%2!=0)
            return false;
            sum+=temp[i];
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    int rec(TreeNode* root,vector<int>&temp)
    {
        if(!root)
        return 1;
        int a=0,b=0,flag=-1;
        temp[root->val]++;
        if(root->left)
        a=rec(root->left,temp);
        if(root->right)
        b=rec(root->right,temp);
        if(!root->left && !root->right)
        {
            if(isSafe(temp))
            flag= 1;
            else
            flag= 0;
        }
        temp[root->val]--;
        if(flag!=-1)
        return flag;
        return a+b;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>temp(10,0);
        return rec(root,temp);
    }
};