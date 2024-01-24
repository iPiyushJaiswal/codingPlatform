/*Problem GFG (Medium)

Check if a given graph is tree or not


Question link: https://www.geeksforgeeks.org/problems/is-it-a-tree/1

---------------------------

Logic: Graph 

---------------------------

Complexity: 

Method 1 : Graph 

Time Complexity= O(n+m)

Space Complexity= O(n) vector + adjancency list.
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Graph 
*/

class Solution {
  public:
    int dfs(int i,vector<int>&vis,vector<int>adjL[],int par)
    {
        vis[i]=1;
        for(auto it:adjL[i])
        {
            if(vis[it]==0)
            {
                if(dfs(it,vis,adjL,i))
                return 1;
            }
            else if(par!=it)
            return 1;
        }
        return 0;
    }
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        vector<int>adjL[n];
        for(int i=0;i<m;i++)
        {
            if(adj[i][0]==adj[i][1])
            return 0;
            adjL[adj[i][0]].push_back(adj[i][1]);
            adjL[adj[i][1]].push_back(adj[i][0]);
        }
        
        vector<int>vis(n,0);
        int x=dfs(0,vis,adjL,-1);
        if(x==1)
        return 0;
        // cout<<"hi";
        for(int i=0;i<n;i++)
        {
            // cout<<i<<" ";
            if(vis[i]==0)
            return 0;
        }
        return 1;
    }
};
