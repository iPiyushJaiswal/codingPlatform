/*Problem GFG (Medium)

Level of Nodes


Question link: https://practice.geeksforgeeks.org/problems/level-of-nodes-1587115620/1

---------------------------

Logic: BFS

---------------------------

Complexity: 


Method 1 : BFS

Time Complexity= O(V)

Space Complexity=O(V) Visited vector + O(V) queue  

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1 : BFS
*/


class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    if(X<0 || X>=V)
	    return -1;
	    queue<int>q;
	    vector<int>vis(V,0);
	    q.push(0);
	    vis[0]=1;
	    int ans=-1;
	    while(!q.empty())
	    {
	        int size=q.size();
	        ans++;
	        for(int i=0;i<size;i++)
	        {
	            int node=q.front();
	            q.pop();
	            for(auto it:adj[node])
	            {
	                if(it==X)
	                return ans+1;
	                if(vis[it]==0)
	                {
	                    q.push(it);
	                    vis[it]=1;
	                }
	            }
	        }
	    }
	    return -1;
	}
};