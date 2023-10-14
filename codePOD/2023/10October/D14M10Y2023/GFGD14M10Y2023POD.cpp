/*Problem GFG (Easy)

Find Common Nodes in two BSTs


Question link: https://practice.geeksforgeeks.org/problems/print-common-nodes-in-bst/1

---------------------------

Logic: BST traversal

---------------------------

Complexity: 


Method 1 : Inorder traversal

Time Complexity=O(n+m)

Space Complexity=O(n+m)

-----------------------------
Method 2 : Stack + Inorder Method

Time Complexity=O(n+m)

Space Complexity=O(height of root1 + height of root2)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1 : Inorder traversal
*/


class Solution
{
    public:
    //Function to find the nodes that are common in both BST.
    void inorder(Node* root1, vector<int>&r1)
    {
        if(!root1)
        return;
        inorder(root1->left,r1);
        r1.push_back(root1->data);
        inorder(root1->right,r1);
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int>r1;
     inorder(root1,r1);
     vector<int>r2;
     inorder(root2,r2);
     int n=r1.size();
     int m=r2.size();
     int i=0;
     int j=0;
     vector<int>ans;
     while(i<n && j<m)
     {
         if(r1[i]==r2[j])
         {
             ans.push_back(r1[i]);
             i++;
             j++;
         }
         else if(r1[i]<r2[j])
         i++;
         else
         j++;
     }
     return ans;
    }
};

/*-------------------------------------------------------
Method 2 : Stack + Inorder Method
*/


class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
    stack<Node*>s1,s2;
    vector<int>ans;
    while(true)
    {
        while(root1)
        {
            s1.push(root1);
            root1=root1->left; 
        }
        while(root2)
        {
            s2.push(root2);
            root2=root2->left;
        }
        if(!s1.empty() && !s2.empty())
        {
            root1=s1.top();
            root2=s2.top();
            if(root1->data<root2->data)
            {
                s1.pop();
                root1=root1->right;
                root2=NULL;
            }
            else if(root1->data>root2->data)
            {
                s2.pop();
                root2=root2->right;
                root1=NULL;
            }
            else
            {
                ans.push_back(root1->data);
                s1.pop();
                root1=root1->right;
                s2.pop();
                root2=root2->right;
            }
        }
        else
        break;
    }
    return ans;
    }
};

