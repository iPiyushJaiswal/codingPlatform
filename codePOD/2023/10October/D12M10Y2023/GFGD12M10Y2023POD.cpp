/*Problem GFG (Medium)

Duplicate subtree in Binary Tree


Question link: https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

---------------------------

Logic: Tree serializable

---------------------------

Complexity: 


Method 1: Tree serializable

Time Complexity=O(n)

Space Complexity=O(n*n) n string of size n

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Tree serializable
*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    unordered_set<string>st;
    
    string rec(Node* root)
    {
        if(!root)
        return "$";
        string l=rec(root->left);
        string r=rec(root->right);
        if(l=="x" || r=="x")
        return "x";
        string temp=l+r+root->data;
        if(!root->left && !root->right)
        return temp;
        if(st.find(temp)!=st.end())
        return "x";
        st.insert(temp);
        return temp;
    }
    int dupSub(Node *root) {
         // code here
         string ans=rec(root);
         if(ans=="x")
         return 1;
         return 0;
    }
};