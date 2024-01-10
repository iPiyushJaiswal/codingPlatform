/*Problem LeetCode (Medium)

2385. Amount of Time for Binary Tree to Be Infected


Question link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/?envType=daily-question&envId=2024-01-10

Solution link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/submissions/1142109350/?envType=daily-question&envId=2024-01-10


Logic : BFS

--------------------------
Complexity: 

Method 1: BFS

Time Complexity=O(height)

Space Complexity=O(2*n) unordered_map
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: BFS
*/

class Solution {
public:
    void findPar(unordered_map<TreeNode*,TreeNode*>&par,TreeNode* root,
    TreeNode** str,int start)
    {
        if(!root)
        return ;
        if(root->val==start)
        *str=root;
        if(root->left)
        par[root->left]=root;
        if(root->right)
        par[root->right]=root;
        findPar(par,root->left,str,start);
        findPar(par,root->right,str,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* str;
        unordered_map<TreeNode*,TreeNode*>par;
        par[root]=root;
        unordered_map<TreeNode*,int>vis;
        findPar(par,root,&str,start);
        cout<<str->val<<" ";
        queue<TreeNode*>q;
        q.push(str);
        vis[str]++;
        int ans=-1;
        while(!q.empty())
        {
            int size=q.size();
            ans++;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && vis[temp->left]==0)
                {
                    q.push(temp->left);
                    vis[temp->left]++;
                }
                if(temp->right && vis[temp->right]==0)
                {
                    q.push(temp->right);
                    vis[temp->right]++;    
                }
                if(vis.find(par[temp])==vis.end())
                {
                    q.push(par[temp]);
                    vis[par[temp]]++;    
                }
            }
        }
        return ans;
    }
};