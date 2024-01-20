/*Problem GFG (Hard)

Distribute candies in a binary tree


Question link: https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1

---------------------------

Logic: Tree Traversal

---------------------------

Complexity: 

Method 1 : Tree Traversal

Time Complexity= O(n)

Space Complexity= O(height) recursive stack.
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
    int rec(Node* root,int& steps)
    {
        if(!root)
        return 0;
        int a=rec(root->left,steps);
        int b=rec(root->right,steps);
        steps=abs(a)+abs(b)+abs(steps);
        int val=a+b+root->key-1;
        return val;
    }
    int distributeCandy(Node* root)
    {
        //code here
        int steps=0;
        int a=rec(root,steps);
        // if(val!=0)
        // return a+val;
        return steps;
    }
};