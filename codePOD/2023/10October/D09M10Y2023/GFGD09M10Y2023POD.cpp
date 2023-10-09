/*Problem GFG (Easy)

Height of Binary Tree


Question link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

---------------------------

Logic: Linked List

---------------------------

Complexity: 


Method 1: Linked List

Time Complexity=O(n)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Linked List
*/

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(!node)
        return 0;
        return 1 + max(height(node->left),height(node->right));
    }
};