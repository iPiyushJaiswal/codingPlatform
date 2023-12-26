/*Problem LeetCode (Medium)

1155. Number of Dice Rolls With Target Sum


Question link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/?envType=daily-question&envId=2023-12-26

Solution link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/solutions/4459231/c-4-methods-dp-solution-recursion-memoization-tabulation-space-optimization/


Logic : DP

--------------------------
Complexity: 

Method 1: Recursion

Time Complexity=O(k^n)

Space Complexity=O(n)
--------------------------
Method 2: Memoization

Time Complexity=O(n*taregt*k)

Space Complexity=O(n*target) dp vector + O(n) recursive stack
--------------------------
Method 3: Tabulation

Time Complexity=O(n*taregt*k)

Space Complexity=O(n*target) dp vector
--------------------------
Method 4: Space optimization

Time Complexity=O(n*taregt*k)

Space Complexity=O(2*target) dp vector
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
int rec(int i,int n,int k,int target)
{
    if(i==n)
    {
        if(target==0)
        return 1;
        return 0;
    }
    int ans=0;
    for(int j=1;j<=k;j++)
    {
        if(target>=j)
        ans=(ans%mod + rec(i+1,n,k,target-j)%mod)%mod;
        else 
        break;
    }
    return ans;
}
int rec1(int i,int n,int k,int target,vector<vector<int>>&dp)
{
    if(i==n)
    {
        if(target==0)
        return 1;
        return 0;
    }
    if(dp[i][target]!=-1)
    return dp[i][target];
    int ans=0;
    for(int j=1;j<=k;j++)
    {
        if(target>=j)
        ans=(ans%mod + rec1(i+1,n,k,target-j,dp)%mod)%mod;
        else 
        break;
    }
    return dp[i][target]=ans;
}
    int numRollsToTarget(int n, int k, int target) {
        if(n*k<target)
        return 0;
        // recursion
        // return rec(0,n,k,target);

        // memoization
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return rec1(0,n,k,target,dp);

        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        // dp[n][0]=1;
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int a=target;a>=1;a--)
        //     {
        //         int ans=0;
        //         for(int j=1;j<=k;j++)
        //         {
        //             if(a>=j)
        //             ans=(ans%mod + dp[i+1][a-j]%mod)%mod;
        //             else 
        //             break;
        //         }
        //         dp[i][a]=ans;
        //     }
        // }
        // return dp[0][target];

        // space optimization
        vector<int>dp(target+1,0);
        vector<int>temp(target+1,0);
        dp[0]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int a=target;a>=1;a--)
            {
                int ans=0;
                for(int j=1;j<=k;j++)
                {
                    if(a>=j)
                    ans=(ans%mod + dp[a-j]%mod)%mod;
                    else 
                    break;
                }
                temp[a]=ans;
            }
            dp=temp;
        }
        return dp[target];
    }
};