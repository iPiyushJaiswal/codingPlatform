/*Problem LeetCode (Medium)

1631. Path With Minimum Effort


Question link: https://leetcode.com/problems/path-with-minimum-effort/description/?envType=daily-question&envId=2023-09-16


Logic: Queue although complexity look smaller but the amortized way PQ give result faster.

Complexity: 

Method 1: Brute force Using Queue visit all nodes multiple times. 

Time Complexity=O(4*n*m),

Space Complexity=O(n*m)

--------------------------

Method 2: Priority_Queue optimized.

Time Complexity=O(4*n*m*log(n*m)),

Space Complexity=O(n*m)

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Brute force Using Queue visit all nodes multiple times.
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        int rN[]={-1,0,1,0};
        int cN[]={0,1,0,-1};
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        int ans=INT_MAX;
        dis[0][0]=0;
        while(!q.empty())
        {
            int val=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            if(row==n-1 && col==m-1)
            ans=min(ans,val);
            for(int i=0;i<4;i++)
            {
                int rV=row+rN[i];
                int cV=col+cN[i];
                if(rV>=0 && rV<n && cV>=0 && cV<m)
                {
                   int effort=max(val,abs(heights[rV][cV]-heights[row][col]));
                   if(effort<dis[rV][cV])
                   {
                       dis[rV][cV]=effort;
                       q.push({effort,{rV,cV}});
                   }
                }
            }
        }
        return ans;
    }
};

/*
--------------------------------------------------

Method 2: Priority_Queue optimized.
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int rN[]={-1,0,1,0};
        int cN[]={0,1,0,-1};
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        while(!pq.empty())
        {
            int val=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 && col==m-1)
            return val;
            for(int i=0;i<4;i++)
            {
                int rV=row+rN[i];
                int cV=col+cN[i];
                if(rV>=0 && rV<n && cV>=0 && cV<m)
                {
                   int effort=max(val,abs(heights[rV][cV]-heights[row][col]));
                   if(effort<dis[rV][cV])
                   {
                       dis[rV][cV]=effort;
                       pq.push({effort,{rV,cV}});
                   }
                }
            }
        }
        return -1;
    }
};