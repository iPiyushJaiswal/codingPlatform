/*Problem LeetCode (Hard)

1269. Number of Ways to Stay in the Same Place After Some Steps


Question link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/?envType=daily-question&envId=2023-10-15


Logic: DP

-------------------------

Complexity: 

Method 1:  Recursive

Time Complexity=O(3^n)

Space Complexity=O(n) recursive stack

--------------------------
Method 2:  Memoization

Time Complexity=O(n*range)

Space Complexity=O(n*range) dp vector + O(range) recursive stack

--------------------------
Method 3:  Tabulation

Time Complexity=O(n*range)

Space Complexity=O(n*range) dp vector

--------------------------
Method 4:  Space Optimization

Time Complexity=O(n*range)

Space Complexity=O(2*range) dp vector

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution {
public:
int mod=1e9 +7;
    int rec(int steps,int n,int i)
    {
        if(steps==0 && i==0)
        return 1;
        if(steps<0)
        return 0;
        int a=0,b=0,c=0;
        // right
        if(i+1<n)
        a=rec(steps-1,n,i+1);
        // left
        if(i-1>=0)
        b=rec(steps-1,n,i-1);
        // stay
        c=rec(steps-1,n,i);
        return (a%mod + b%mod + c%mod)%mod;
    }
    int rec1(int steps,int n,int i,vector<vector<long long>>&dp)
    {
        if(steps==0 && i==0)
        return 1;
        if(steps<0)
        return 0;
        if(dp[steps][i]!=-1)
        return dp[steps][i];
        long long a=0,b=0,c=0;
        // right
        if(i+1<n)
        a=rec1(steps-1,n,i+1,dp)%mod;
        // left
        if(i-1>=0)
        b=rec1(steps-1,n,i-1,dp)%mod;
        // stay
        c=rec1(steps-1,n,i,dp)%mod;
        return dp[steps][i]=(a+b+c)%mod;
    }
    int numWays(int steps, int arrLen) {
        // return rec(steps,arrLen,0);

        // memoization
        // int range=min(arrLen,steps);
        // vector<vector<long long>>dp(steps+1,vector<long long>(range+1,-1));
        // return rec1(steps,range,0,dp);

        // tabulation
        // int range=min(arrLen,steps);
        // vector<vector<long long>>dp(steps+1,vector<long long>(range+1,0));
        // dp[0][0]=1;
        // int n=range;
        // for(int i=1;i<=steps;i++)
        // {
        //     for(int j=range-1;j>=0;j--)
        //     {
        //         long long a=0,b=0,c=0;
        //         // right
        //         if(j+1<n)
        //         a=dp[i-1][j+1]%mod;
        //         // left
        //         if(j-1>=0)
        //         b=dp[i-1][j-1]%mod;
        //         // stay
        //         c=dp[i-1][j]%mod;
        //         dp[i][j]=(a+b+c)%mod;
        //     }
        // }
        // return dp[steps][0];

        // space optimization
        int range=min(arrLen,steps);
        vector<long long>dp(range+1,0);
        vector<long long>temp(range+1,0);
        dp[0]=1;
        int n=range;
        for(int i=1;i<=steps;i++)
        {
            for(int j=range-1;j>=0;j--)
            {
                long long a=0,b=0,c=0;
                // right
                if(j+1<n)
                a=dp[j+1]%mod;
                // left
                if(j-1>=0)
                b=dp[j-1]%mod;
                // stay
                c=dp[j]%mod;
                temp[j]=(a+b+c)%mod;
            }
            dp=temp;
        }
        return dp[0];
    }
};