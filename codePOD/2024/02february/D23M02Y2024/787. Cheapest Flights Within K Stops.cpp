/*Problem LeetCode (Medium)

787. Cheapest Flights Within K Stops


Question link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=daily-question&envId=2024-02-23

Solution link: https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/1183902721/?envType=daily-question&envId=2024-02-23


Logic : Array

--------------------------
Complexity: 

Method 1: Recursion

Time Complexity=O(V*E)

Space Complexity=O(V*E)adj List +  O(k) recursive stack
--------------------------
Method 2: DFS

Time Complexity=O(V*k)

Space Complexity=O(V*E)adj List + O(V*k) dp.
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DFS + DP
*/

class Solution {
public:
    int rec(vector<vector<pair<int,int>>>&adj, int i,int dst,int k)
    {
        if(i==dst)
        return 0;
        if(k<0)
        return INT_MAX;
        int ans=INT_MAX;
        for(auto it:adj[i])
        {
            int val=rec(adj,it.first,dst,k-1);
            if(val!=INT_MAX)
            ans=min(ans,val+it.second);
        }
        return ans;
    }
    int rec1(vector<vector<pair<int,int>>>&adj, int i,int dst,int k,
    vector<vector<int>>&dp)
    {
        if(i==dst)
        return 0;
        if(k<0)
        return INT_MAX;
        if(dp[i][k]!=-1)
        return dp[i][k];
        int ans=INT_MAX;
        for(auto it:adj[i])
        {
            int val=rec1(adj,it.first,dst,k-1,dp);
            if(val!=INT_MAX)
            ans=min(ans,val+it.second);
        }
        return dp[i][k]=ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        int m=f.size();
        for(int i=0;i<m;i++)
        adj[f[i][0]].push_back({f[i][1],f[i][2]});

        // recursion
        // int ans=rec(adj,src,dst,k);

        // memoization
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        int ans=rec1(adj,src,dst,k,dp);
        return (ans==INT_MAX)?-1:ans;
    }
};