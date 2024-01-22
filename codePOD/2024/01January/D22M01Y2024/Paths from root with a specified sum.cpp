/*Problem GFG (Medium)

Paths from root with a specified sum


Question link: https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

---------------------------

Logic: Tree Traversal

---------------------------

Complexity: 

Method 1 : Tree Traversal

Time Complexity= O(n)

Space Complexity= O(height) recursive stack + vector .
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Tree Traversal
*/

class Solution
{
    public:
    void rec(Node *root, int sum,vector<vector<int>>&ans,vector<int>&temp)
    {
        if(!root)
        return;
        temp.push_back(root->key);
        sum-=root->key;
        if(sum==0)
        ans.push_back(temp);
        rec(root->left,sum,ans,temp);
        rec(root->right,sum,ans,temp);
        sum+=root->key;
        temp.pop_back();
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        //code here
        vector<vector<int>>ans;
        vector<int>temp;
        rec(root,sum,ans,temp);
        return ans;
    }
};