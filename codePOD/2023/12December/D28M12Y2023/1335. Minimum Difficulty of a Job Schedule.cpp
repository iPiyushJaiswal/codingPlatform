/*Problem LeetCode (Hard)

1335. Minimum Difficulty of a Job Schedule


Question link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/description/?envType=daily-question&envId=2023-12-29

Solution link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/submissions/1131470074/?envType=daily-question&envId=2023-12-29


Logic : DP

--------------------------
Complexity: 

Method 1: Recursion

Time Complexity=O(2^n)

Space Complexity=O(n) recursive stack
--------------------------
Method 2: Memoization

Time Complexity=O(n*n*d)

Space Complexity=O(n*d) dp vector + O(n) recursive stack
--------------------------
Method 3: Tabulation

Time Complexity=O(n*n*d)

Space Complexity=O(n*d) dp vector
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution {
public:
    long long rec(int i,int n,int d,vector<int>& jD)
    {
        if(i==n)
        return 0;
        if(d==0)
        return INT_MAX;
        long long maxi=INT_MIN;
        long long ans=INT_MAX;
        for(int j=i;j<=n-d;j++)
        {
            maxi=max(maxi,(long long)jD[j]);
            long long val=maxi+rec(j+1,n,d-1,jD);
            ans=min(ans,val);
        }
        return ans;
    }
    long long rec1(int i,int n,int d,vector<int>& jD,vector<vector<int>>&dp)
    {
        if(i==n)
        return 0;
        if(d==0)
        return INT_MAX;
        if(dp[i][d]!=-1)
        return dp[i][d];
        long long maxi=INT_MIN;
        long long ans=INT_MAX;
        for(int j=i;j<=n-d;j++)
        {
            maxi=max(maxi,(long long)jD[j]);
            long long val=maxi+rec1(j+1,n,d-1,jD,dp);
            ans=min(ans,val);
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jD, int d) {
        int n=jD.size();
        if(n<d)
        return -1;

        // recursion
        // return rec(0,n,d,jD);

        // memoization
        // vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        // return rec1(0,n,d,jD,dp);

        // tabulation
        vector<vector<int>>dp(n+1,vector<int>(d+1,INT_MAX));
        for(int x=0;x<=d;x++)
        dp[n][x]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int k=1;k<=d;k++)
            {
                long long maxi=INT_MIN;
                long long ans=INT_MAX;
                for(int j=i;j<=n-k;j++)
                {
                    maxi=max(maxi,(long long)jD[j]);
                    long long val=maxi+dp[j+1][k-1];
                    ans=min(ans,val);
                }
                dp[i][k]=ans;
            }
        }
        return dp[0][d];

    }
};