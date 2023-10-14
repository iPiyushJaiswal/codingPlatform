/*Problem GFG (Easy)

Normal BST to Balanced BST


Question link: https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1

---------------------------

Logic: Inorder traversal + Binary Search Logic

---------------------------

Complexity: 


Method 1 : Inorder traversal + Binary Search Logic

Time Complexity=O(n)

Space Complexity=O(n) inorder vector + O(n) recursive stack. 

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1 : Inorder traversal + Binary Search Logic
*/


class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    void inorder(Node* root,vector<Node*>&arr)
    {
        if(!root)
        return;
        inorder(root->left,arr);
        arr.push_back(root);
        inorder(root->right,arr);
    }
    Node* bs(int low,int high,vector<Node*>&arr)
    {
        if(low>high)
        return NULL;
        int mid=(high+low)/2;
        arr[mid]->left=bs(low,mid-1,arr);
        arr[mid]->right=bs(mid+1,high,arr);
        return arr[mid];
    }
    Node* buildBalancedTree(Node* root)
    {
    	// Code here
    	vector<Node*>arr;
    	inorder(root,arr);
    	int n=arr.size();
    	return bs(0,n-1,arr);
    }
};