/*Problem GFG (Medium)

Binary Tree to CDLL


Question link: https://www.geeksforgeeks.org/problems/binary-tree-to-cdll/1

---------------------------

Logic: Inorder linked list

---------------------------

Complexity: 

Method 1 : Brute Force

Time Complexity= O(n)

Space Complexity=O(n)Inorder vector + O(h) recursive stack 

-----------------------------
Method 2 : Optimized

Time Complexity= O(n)

Space Complexity= O(h) recursive stack

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Brute Force
*/

class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    void inorder(Node* root,vector<Node*>&in)
    {
        if(!root)
        return;
        inorder(root->left,in);
        in.push_back(root);
        inorder(root->right,in);
    }
    Node *bTreeToCList(Node *root)
    {
    //add code here.
    vector<Node*>in;
    inorder(root,in);
    Node* head=in[0];
    Node* temp=head;
    int n=in.size();
    for(int i=1;i<n;i++)
    {
        temp->right=in[i];
        in[i]->left=temp;
        temp=temp->right;
    }
    in[n-1]->right=head;
    head->left=in[n-1];
    return head;
    }
};

/*-----------------------------------------------------------------------
Method 2 : Optimized
*/

class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node* head=NULL;
    Node* tail=NULL;
    void inorder(Node* root)
    {
        if(!root)
        return ;
        inorder(root->left);
        if(head==NULL)
        {
            head=root;
            tail=root;
        }
        else
        {
            tail->right=root;
            root->left=tail;
            tail=tail->right;
        }
        inorder(root->right);
    }
    Node *bTreeToCList(Node *root)
    {
    //add code here.
    if(!root)
    return NULL;
    inorder(root);
    head->left=tail;
    tail->right=head;
    return head;
    }
};