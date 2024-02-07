/*Problem GFG (Easy)

Check if all leaves are at same level


Question link:	https://www.geeksforgeeks.org/problems/leaf-at-same-level/1

---------------------------

Logic: BFS

---------------------------

Complexity: 

Method 1 : BFS

Time Complexity= O(n)

Space Complexity= O(n)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: BFS
*/

class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        //Your code here
        queue<Node*>q;
        int flag=0;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            if(flag==1 && n>0)
            return false;
            for(int i=0;i<n;i++)
            {
                Node* temp=q.front();
                q.pop();
                if((temp->left || temp->right) && flag==1)
                return false;
                if(!temp->left && !temp->right && flag==0)
                flag=1;
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
        }
        return true;
    }
};