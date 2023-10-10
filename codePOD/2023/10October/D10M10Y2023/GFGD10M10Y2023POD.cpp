/*Problem GFG (Hars)

Nodes at given distance in binary tree


Question link: https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1

---------------------------

Logic: Tree

---------------------------

Complexity: 


Method 1: Tree

Time Complexity=O(n)

Space Complexity=O(n)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Tree
*/

class Solution
{
private:

public:
Node* findTarget(Node* root, int target)
{
    if(!root)
    return root;
    if(root->data==target)
    return root;
    Node* l=findTarget(root->left,target);
    Node* r=findTarget(root->right,target);
    if(!l)
    return r;
    return l;
}
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int>ans;
        if(!root)
        return ans;
        queue<Node*>q1;
        q1.push(root);
        map<Node*,Node*>mp1;
        while(!q1.empty())
        {
            Node* t=q1.front();
            q1.pop();
            if(t->left)
            {
                mp1[t->left]=t;
                q1.push(t->left);
            }
            if(t->right)
            {
                mp1[t->right]=t;
                q1.push(t->right);
            }
        }
        Node* tar=findTarget(root,target);
        queue<pair<Node*,int>>q2;
        map<Node*,int>mp2;
        q2.push({tar,0});
        while(!q2.empty())
        {
            int size=q2.size();
            int dis;
            for(int i=0;i<size;i++)
            {
                Node *t=q2.front().first;
                dis=q2.front().second;
                q2.pop();
                mp2[t]++;
                if(t->left && !mp2[t->left])
                q2.push({t->left,dis+1});
                if(t->right && !mp2[t->right])
                q2.push({t->right,dis+1});
                if(mp1[t] && !mp2[mp1[t]])
                q2.push({mp1[t],dis+1});
            }
            if(dis+1==k)
            break;
        }
        while(!q2.empty())
        {
            Node* t=q2.front().first;
            q2.pop();
            ans.push_back(t->data);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};