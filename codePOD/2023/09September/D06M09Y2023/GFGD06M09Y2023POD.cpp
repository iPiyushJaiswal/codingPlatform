/*Problem GFG (Easy)

Mother Vertex


Question link: https://practice.geeksforgeeks.org/problems/mother-vertex/1

Complexity: 

Method 1: Brute Force (TLE) DFS for all nodes.

Time Complexity=O(V+E)

Space Complexity=O(V) visited vector + O(V) recursive stack.

-----------------------------

Method 2: DFS smartly.

Time Complexity=O(V+E)

Space Complexity=O(V) visited vector

-----------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Brute Force (TLE) DFS for all nodes.
*/


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int i,vector<int>adj[],int &count,vector<int>&vis)
    {
        count++;
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(vis[it]==0)
            dfs(it,adj,count,vis);
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int>vis(V,0);
	    int ans=-1;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	       vis=vector<int>(V,0);
	            int count=0;
	            dfs(i,adj,count,vis);
	           // cout<<count;
	            if(count==V)
	            {
	                ans=i;
	                break;
	            }
	        }
	    }
	    return ans;
	}

};


/*------------------------------

Method 2: DFS smartly.*/

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int i,vector<int>adj[],int &count,vector<int>&vis)
    {
        count++;
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(vis[it]==0)
            dfs(it,adj,count,vis);
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int>vis(V,0);
	    int ans=0;
	    int count=0;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	            dfs(i,adj,count,vis);
	            ans=i;
	        }
	    }
	    vis=vector<int>(V,0);
	    count=0;
	    dfs(ans,adj,count,vis);
	    if(count==V)
	    return ans;
	    return -1;
	}