/*Problem LeetCode (Easy)

94. Binary Tree Inorder Traversal


Question link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/?envType=daily-question&envId=2023-12-09

Solution link: https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/1115488533/?envType=daily-question&envId=2023-12-09


Logic : Inorder

--------------------------

Complexity: 

Method 1: Recursive

Time Complexity=O(n)

Space Complexity=O(height) recursive stack
--------------------------
Method 2: Inorder Stack

Time Complexity=O(n)

Space Complexity=O(height) stack
--------------------------
Method 3: Moriss

Time Complexity=O(n)

Space Complexity=O(1) recursive stack
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Recursive
*/

class Solution {
public:
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(!root)
        return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        return ans;
    }
};

/*-------------------------------------------------------------
Method 2: Iterative Stack
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        while(true)
        {
            if(root)
            {
                st.push(root);
                root=root->left;
            }
            else
            {
                if(st.empty())
                break;
                root=st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};

/*-------------------------------------------------------------
Method 3: Moriss
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        while(root)
        {
            if(!root->left)
            {
                ans.push_back(root->val);
                root=root->right;
            }
            else
            {
                TreeNode* temp=root->left;
                while(temp->right && temp->right!=root)
                temp=temp->right;
                if(temp->right==NULL)
                {
                    temp->right=root;
                    root=root->left;
                }
                else
                {
                    temp->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return ans;
    }
};