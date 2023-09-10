/*Problem GFG (Easy)

Insert a node in a BST


Question link: https://practice.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1

Complexity: 

Method 1: Recursive

Time Complexity=O(height)

Space Complexity=O(height) recursive stack.

-----------------------------

Method 2: Iterative

Time Complexity=O(height)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Recursive + Iterative
*/

class Solution
{
    public:
    Node* createNode(int data)
    {
        Node* newNode=new Node(data);
        return newNode;
    }
    void dfs(Node* node,int data)
    {
        if(!node)
        return;
        if(node->data==data)
        return ;
        else if(node->data<data)
        {
            if(!node->right)
            {
                node->right=createNode(data);
                return;
            }
            dfs(node->right,data);
        }
        else
        {
            if(!node->left)
            {
                node->left=createNode(data);
                return;
            }
            dfs(node->left,data);
        }
    }
        Node* insert(Node* node, int data) {
            // Your code goes here
            // recursive
            // dfs(node,data);
            // iterative
            Node* temp=node;
            while(temp)
            {
                if(temp->data==data)
                break;
                else if(temp->data<data)
                {
                    if(!temp->right)
                    {
                        temp->right=new Node(data);
                        break;
                    }
                    temp=temp->right;
                }
                else
                {
                    if(!temp->left)
                    {
                        temp->left=new Node(data);
                        break;
                    }
                    temp=temp->left;
                }
            }
            return node;
    }

};