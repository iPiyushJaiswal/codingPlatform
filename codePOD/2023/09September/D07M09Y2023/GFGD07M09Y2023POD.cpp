/*Problem GFG (Medium)

Minimum Multiplications to reach End


Question link: https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1

Complexity: 

Method 1: BFS Graph.

Time Complexity=O(1e5 * N)

Space Complexity=O(N) visited vector + O(1e5 * N) queue in worst case.

-----------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: BFS Graph.
*/

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        int n=arr.size();
        vector<int>dis(1e5,INT_MAX);
        int mod=1e5;
        q.push({start,0});
        dis[start]=0;
        while(!q.empty())
        {
            int node=q.front().first;
            int lvl=q.front().second;
            q.pop();
            if(node==end)
            return lvl;
            for(int i=0;i<n;i++)
            {
                int multi=(node*arr[i])%mod;
                if(dis[multi]>lvl+1)
                {
                    q.push({multi,lvl+1});
                    dis[multi]=lvl+1;
                }
            }
        }
        return -1;
    }
};