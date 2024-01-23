/*Problem GFG (Medium)

Course Schedule


Question link: https://www.geeksforgeeks.org/problems/course-schedule/1

---------------------------

Logic: Graph + inDegree

---------------------------

Complexity: 

Method 1 : Graph + inDegree

Time Complexity= O(n+m)

Space Complexity= O(n+m) vector + queue + adjancency list.
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Graph + inDegree
*/

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> p) 
    {
        //code here
        vector<int>adj[n];
        for(int i=0;i<m;i++)
        {
            if(p[i][1]==p[i][0])
            return {};
            adj[p[i][1]].push_back(p[i][0]);
        }
        vector<int>inDeg(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            inDeg[it]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inDeg[i]==0)
            q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int temp=q.front();
                q.pop();
                ans.push_back(temp);
                for(auto it:adj[temp])
                {
                    inDeg[it]--;
                    if(inDeg[it]==0)
                    q.push(it);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(inDeg[i]>0)
            return {};
        }
        return ans;
    }
};