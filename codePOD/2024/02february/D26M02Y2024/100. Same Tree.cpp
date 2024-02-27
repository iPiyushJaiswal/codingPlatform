/*Problem LeetCode (Easy)

100. Same Tree


Question link: https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26

Solution link: https://leetcode.com/problems/same-tree/submissions/1186723479/?envType=daily-question&envId=2024-02-26


Logic : Tree

--------------------------
Complexity: 

Method 1: Traversal

Time Complexity=O(n)

Space Complexity=O(h) height of tree recursive stack
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Traversal
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
        return true;
        if((!p && q)||(p && !q))
        return false;
        return (p->val==q->val)&&isSameTree(p->left,q->left)&&
        isSameTree(p->right,q->right);
    }
};