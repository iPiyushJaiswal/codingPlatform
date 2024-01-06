/*Problem LeetCode (Hard)

1235. Maximum Profit in Job Scheduling


Question link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/?envType=daily-question&envId=2024-01-06

Solution link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/submissions/1138192515/?envType=daily-question&envId=2024-01-06


Logic : DP + Linear Search + Binary Search

--------------------------
Complexity: 

Method 1: Recursion

Time Complexity=O(2^n)

Space Complexity=O(n) recursive stack 
--------------------------
Method 2: Memoization

Time Complexity=O(n*n)

Space Complexity=O(n*n) dp vector + O(n) recursive stack 
--------------------------
Method 3: Tabulation

Time Complexity=O(n*n)

Space Complexity=O(n*n) dp vector
--------------------------
Method 4: Space Optimization 1

Time Complexity=O(n*n)

Space Complexity=O(2*n) dp vector
--------------------------
Method 5: Space Optimization 2 Binary Search

Time Complexity=O(nlogn)

Space Complexity=O(n)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP + Linear Search
*/

class Solution {
public:
    int rec(int i,int n,vector<pair<int,pair<int,int>>>&inp,int prev)
    {
        if(i>=n)
        return 0;
        int a=0;
        if(prev==-1 || inp[i].second.first>=inp[prev].first)
        {
            a=inp[i].second.second + rec(i+1,n,inp,i);
        }
        int b=rec(i+1,n,inp,prev);
        return max(a,b);
    }
    int rec1(int i,int n,vector<pair<int,pair<int,int>>>&inp,int prev,
    vector<vector<int>>&dp)
    {
        if(i==n)
        return 0;
        int a=0;
        if(dp[i][prev+1]!=-1)
        return dp[i][prev+1];
        if(prev==-1 || inp[i].second.first>=inp[prev].first)
        {
            a=inp[i].second.second + rec1(i+1,n,inp,i,dp);
        }
        int b=rec1(i+1,n,inp,prev,dp);
        return dp[i][prev+1]=max(a,b);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<int,pair<int,int>>>inp;
        int n=startTime.size();
        for(int i=0;i<n;i++)
        inp.push_back({endTime[i],{startTime[i],profit[i]}});
        sort(inp.begin(),inp.end());

        // recursion
        // return rec(0,n,inp,-1);

        // memoization
        // vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        // return rec1(0,n,inp,-1,dp);

        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int prev=i-1;prev>=-1;prev--)
        //     {
        //         int a=0;
        //         if(prev==-1 || inp[i].second.first>=inp[prev].first)
        //         a=inp[i].second.second +dp[i+1][i+1];
        //         int b=dp[i+1][prev+1];
        //         dp[i][prev+1]=max(a,b);
        //     }
        // }
        // return dp[0][0];

        // space optimization
        vector<int>dp(n+2,0);
        vector<int>temp(n+2,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int a=0;
                if(prev==-1 || inp[i].second.first>=inp[prev].first)
                a=inp[i].second.second +dp[i+1];
                int b=dp[prev+1];
                temp[prev+1]=max(a,b);
            }
            dp=temp;
        }
        return dp[0];
    }
};

/* -----------------------------------------------------------------
 Method 5: Space Optimization 2
*/

class Solution {
public:
    int bs(vector<vector<int>>&inp,int ind)
    {
        int low=ind+1;
        int high=inp.size()-1;
        int ans=inp.size();
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(inp[ind][1]<=inp[mid][0])
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        } 
        return ans;       
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>inp;
        for(int i=0;i<n;i++)
        inp.push_back({startTime[i],endTime[i],profit[i]});
        sort(inp.begin(),inp.end());
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int nxt=bs(inp,i);
            dp[i]=max(dp[i+1],dp[nxt]+inp[i][2]);
        }
        return dp[0];
    }
};