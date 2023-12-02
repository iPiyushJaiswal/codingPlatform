/*Problem GFG (Easy)

Inorder Traversal and BST


Question link: https://www.geeksforgeeks.org/problems/inorder-traversal-and-bst5855/1

---------------------------

Logic: Array Traversal (Inorder of BST  must be in increasing order because inorder traverse left->root->right)

---------------------------

Complexity: 

Method 1 : Array Traversal

Time Complexity= O(n)

Space Complexity= O(1) 

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array Traversal
*/

class Solution{
    public:
    int isRepresentingBST(int arr[], int N)
    {
        // code here
        for(int i=1;i<N;i++)
        {
            if(arr[i]<arr[i-1])
            return false;
        }
        return true;
    }
};