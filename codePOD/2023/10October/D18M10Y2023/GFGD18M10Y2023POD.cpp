/*Problem GFG (Medium)

Eventual Safe States


Question link: https://practice.geeksforgeeks.org/problems/eventual-safe-states/1

---------------------------

Logic: TopoSort

---------------------------

Complexity: 


Method 1 : TopoSort

Time Complexity= O(V+E)+O(N*logN),Extra O(N*logN) for sorting the safeNodes array, where N is the number of safe nodes.

Space Complexity=O(V) vector  

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1 : TopoSort
*/


class Solution {
  public:
//   all the node which are part of cycle or leading to cycle are unsafe.
    
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
       vector<int>rAdj[V];
       vector<int>inDeg(V,0);
       for(int i=0;i<V;i++)
       {
           for(auto it:adj[i])
           {
               rAdj[it].push_back(i);
               inDeg[i]++;
           }
       }
       queue<int>q;
       for(int i=0;i<V;i++)
       {
           if(inDeg[i]==0)
           q.push(i);
       }
       vector<int>ans;
       while(!q.empty())
       {
           int node=q.front();
           q.pop();
           ans.push_back(node);
           for(auto it:rAdj[node])
           {
               inDeg[it]--;
               if(inDeg[it]==0)
               q.push(it);
           }
       }
      sort(ans.begin(),ans.end());
       return ans;
    }
};