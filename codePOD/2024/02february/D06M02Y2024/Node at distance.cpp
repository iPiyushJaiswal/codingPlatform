/*Problem GFG (Medium)

Node at distance


Question link:	https://www.geeksforgeeks.org/problems/node-at-distance/1

---------------------------

Logic: Tree.

---------------------------

Complexity: 

Method 1 : Tree 

Time Complexity= O(n)

Space Complexity= O(height of tree) vector + O(height of tree) recursive stack.
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Tree 
*/

class Solution
{
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    void rec(Node* root,int k,int mHeight,int& ans,
    vector<pair<Node*,int>>&path)
    {
        if(!root)
        return;
        if(!root->left && !root->right && (k==0 || (mHeight-k>=0 && 
        path[mHeight-k].second==0)))
        {
            ans++;
            if(k!=0)
            path[mHeight-k].second=1;
            return;
        }
        path.push_back({root,0});
        rec(root->left,k,mHeight+1,ans,path);
        rec(root->right,k,mHeight+1,ans,path);
        path.pop_back();
    }
    int printKDistantfromLeaf(Node* root, int k)
    {
    	//Add your code here. 
    	int ans=0;
    	vector<pair<Node*,int>>path;
    	rec(root,k,0,ans,path);
    	return ans;
    }
};