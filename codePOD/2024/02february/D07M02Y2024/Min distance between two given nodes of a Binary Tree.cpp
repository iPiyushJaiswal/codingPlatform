/*Problem GFG (Medium)

Min distance between two given nodes of a Binary Tree


Question link:	https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

---------------------------

Logic: Tree.

---------------------------

Complexity: 

Method 1 : Brute Force 

Time Complexity= O(n)

Space Complexity= O(n)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Brute Force 
*/

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    void findNode(Node* root,unordered_map<Node*,Node*>&cP,Node** start,
    Node** target,int a,int b)
    {
        if(!root)
        return;
        if(root->data==a)
        *start=root;
        if(root->data==b)
        *target=root;
        if(root->left)
        {
            cP[root->left]=root;
            findNode(root->left,cP,start,target,a,b);
        }
        if(root->right)
        {
            cP[root->right]=root;
             findNode(root->right,cP,start,target,a,b);
        }
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        unordered_map<Node*,Node*>cP;
        Node* start=NULL;
        Node* target=NULL;
        findNode(root,cP,&start,&target,a,b);
        if(start==target)
        return 0;
        queue<Node*>q;
        unordered_map<Node*,int>mp;
        int count=0;
        q.push(start);
        mp[start]=1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node* temp=q.front();
                q.pop();
                if(temp==target)
                return count;
                if(temp->left && mp.find(temp->left)==mp.end())
                {
                    q.push(temp->left);
                    mp[temp->left]++;
                }
                if(temp->right && mp.find(temp->right)==mp.end())
                {
                    q.push(temp->right);
                    mp[temp->right]++;
                }
                if(cP.find(temp)!=cP.end() && mp.find(cP[temp])==mp.end())
                {
                    q.push(cP[temp]);
                    mp[cP[temp]]++;
                }
            }
            count++;
        }
        return -1;
    }
};