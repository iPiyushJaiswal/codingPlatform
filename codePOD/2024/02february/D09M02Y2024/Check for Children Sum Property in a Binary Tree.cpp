/*Problem GFG (Medium)

Check for Children Sum Property in a Binary Tree


Question link:	https://www.geeksforgeeks.org/problems/children-sum-parent/1

---------------------------

Logic: BFS + DFS

---------------------------

Complexity: 

Method 1 : BFS

Time Complexity= O(n)

Space Complexity= O(n)
----------------------------------
Method 2 : DFS

Time Complexity= O(n)

Space Complexity= O(height of tree) Recursive stack
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: BFS
*/

class Solution{
    public:
    int isSumProperty(Node *root)
    {
     // Add your code here
     queue<Node*>q;
     q.push(root);
     while(!q.empty())
     {
         int size=q.size();
         for(int i=0;i<size;i++)
         {
             Node* temp=q.front();
             q.pop();
             int a=0;
             int b=0;
             if(temp->left)
             {
                 a=temp->left->data;
                 q.push(temp->left);
             }
             if(temp->right)
             {
                 b=temp->right->data;
                 q.push(temp->right);
             }
             if(a==0 && b==0)
             continue;
             if((a+b)!=temp->data)
             return false;
         }
     }
     return true;
    }
};


/* --------------------------------------------
Method 2: DFS
*/

class Solution{
    public:
    bool rec(Node* root)
    {
        if(!root)
        return true;
        if(!root->left && !root->right)
        return true;
        int a=0;
        int b=0;
        if(root->left)
        a=root->left->data;
        if(root->right)
        b=root->right->data;
        if(root->data!=(a+b))
        return false;
        return rec(root->left) && rec(root->right);
    }
    int isSumProperty(Node *root)
    {
     // Add your code here
     return rec(root);
    }