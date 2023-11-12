/*Problem LeetCode (Hard)

815. Bus Routes


Question link: https://leetcode.com/problems/bus-routes/description/?envType=daily-question&envId=2023-11-12


Logic: BFS

--------------------------

Complexity: 

Method 1: BFS

Time Complexity=O(N*M)

Space Complexity=O(N*M)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: BFS
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int,set<int>>adj;
        int buses=routes.size();
        for(int i=0;i<buses;i++)
        {
            for(int j=0;j<routes[i].size();j++)
            adj[routes[i][j]].insert(i);
        }
        set<int>busVis,routeVis;
        queue<pair<int,int>>q;
        q.push({source,0});
        routeVis.insert(source);
        while(!q.empty())
        {
            int r=q.front().first;
            int b=q.front().second;
            q.pop();
            if(r==target)
            return b;
            for(auto it:adj[r])
            {
                if(busVis.find(it)==busVis.end())
                {
                    for(auto itr:routes[it])
                    {
                        if(routeVis.find(itr)==routeVis.end())
                        {
                            q.push({itr,b+1});
                            routeVis.insert(itr);
                        }
                    }
                    busVis.insert(it);
                }
            }
        }
        return -1;
    }
};