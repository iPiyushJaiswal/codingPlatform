/*Problem LeetCode (Medium)

2265. Count Nodes Equal to Average of Subtree


Question link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/?submissionId=1089613893


Logic: BT iteration PostOrder

--------------------------

Complexity: 

Method : BT iteration PostOrder

Time Complexity=O(n)

Space Complexity=O(n) recursive stack.

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : BT iteration PostOrder
*/

class Solution {
public:
    pair<int,int> rec(TreeNode* root,int &count)
    {
        if(!root)
        return {0,0};
        pair<int,int> a=rec(root->left,count);
        pair<int,int> b=rec(root->right,count);
        int sum=root->val;
        int n=1;
        sum+=a.first + b.first;
        n+=a.second + b.second;    
        if(root->val==(sum/n))
        count++;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        rec(root,count);
        return count;
    }
};