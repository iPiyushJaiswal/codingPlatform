/*Problem GFG (Hard)

AVL Tree Insertion


Question link: https://www.geeksforgeeks.org/problems/avl-tree-insertion/1

---------------------------

Logic: AVL Insertion

---------------------------

Complexity: 

Method 1 : AVL Insertion

Time Complexity= O(nlogn))

Space Complexity= O(logn)

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: AVL Insertion
*/

class Solution{
  public:
    /*You are required to complete this method */
    int findHeight(Node* node)
    {
        if(!node)
        return 0;
        return node->height;
    }
    Node* rightRotate(Node* node)
    {
        Node* temp=node->left;
        node->left=temp->right;
        temp->right=node;
        node->height=1+max(findHeight(node->left),findHeight(node->right));
        temp->height=1+max(findHeight(temp->left),findHeight(temp->right));
        return temp;
    }
    Node* leftRotate(Node* node)
    {
        Node* temp=node->right;
        node->right=temp->left;
        temp->left=node;
        node->height=1+max(findHeight(node->left),findHeight(node->right));
        temp->height=1+max(findHeight(temp->left),findHeight(temp->right));
        return temp;
    }
    Node* insertToAVL(Node* node, int data)
    {
        //Your code here
        if(node==NULL)
        return new Node(data);
        if(node->data<data)
        node->right=insertToAVL(node->right,data);
        else if(node->data>data)
        node->left=insertToAVL(node->left,data);
        else
        return node;
        
        int l=findHeight(node->left);
        int r=findHeight(node->right);
        node->height=1+ max(l,r);
        
        int diff=l-r;
        if(diff>1)
        {
            int a=findHeight(node->left->left);
            int b=findHeight(node->left->right);
            if(a-b>0)
            return rightRotate(node);
            else if(a-b<0)
            {
                node->left=leftRotate(node->left);
                return rightRotate(node);
            }
        }
        else if(diff<-1)
        {
            int a=findHeight(node->right->left);
            int b=findHeight(node->right->right);
            if(a-b>0)
            {
                node->right=rightRotate(node->right);
                return leftRotate(node);
            }
            else if(a-b<0)
            return leftRotate(node);
        }
        return node;
    }
};