/*Problem GFG (Medium)

Transitive closure of a Graph


Question link: https://practice.geeksforgeeks.org/problems/transitive-closure-of-a-graph0930/1

---------------------------

Logic: DFS

---------------------------

Complexity: 


Method 1 : DFS

Time Complexity=O(n^3)

Space Complexity=O(n) visited vector + O(n) recursive stack. 

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1 : DFS
*/


class Solution{
public:
    void dfs(vector<vector<int>>&ans,int i,vector<int>&vis,int n)
    {
        vis[i]=1;
        for(int j=0;j<n;j++)
        {
            if(i!=j && vis[j]==0 && ans[i][j]==1)
            dfs(ans,j,vis,n);
        }
    }
    vector<vector<int>> transitiveClosure(int n, vector<vector<int>> graph)
    {
        // code here
        vector<vector<int>>ans=graph;
        for(int i=0;i<n;i++)
        {
            vector<int>vis(n,0);
            dfs(ans,i,vis,n);
            for(int j=0;j<n;j++)
            {
                if(vis[j]==1)
                ans[i][j]=1;
            }
        }
        return ans;
    }
};