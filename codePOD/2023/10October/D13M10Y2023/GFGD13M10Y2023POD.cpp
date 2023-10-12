/*Problem GFG (Medium)

Floor in BST


Question link: https://practice.geeksforgeeks.org/problems/floor-in-bst/1

---------------------------

Logic: BST traversal

---------------------------

Complexity: 


Method 1: BST traversal

Time Complexity=O(height of tree)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : BST traversal
*/

class Solution{

public:
    int floor(Node* root, int x) {
        // Code here
        int ans=-1;
        Node* temp=root;
        while(temp)
        {
            if(temp->data==x)
            return x;
            else if(temp->data<x)
            {
                ans=temp->data;
                temp=temp->right;
            }
            else
            temp=temp->left;
        }
        return ans;
    }
};