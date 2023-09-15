/*Problem GFG (Medium)

Partition Equal Subset Sum


Question link: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

Logic: DP

Complexity: 

Method 1: Recursion

Time Complexity=O(2^n)

Space Complexity=O(n) recursive stack.

-------------------------

Method 2: Memoization

Time Complexity=O(n*sum)

Space Complexity=O(n*sum)dp vector + O(n) recursive stack.

-------------------------

Method 3: Tabulation

Time Complexity=O(n*sum)

Space Complexity=O(n*sum)dp vector.

-------------------------

Method 4: Space optimization

Time Complexity=O(n*sum)

Space Complexity=O(2*sum)dp vector.

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution{
public:
    int rec(int i,int n,int sum,int arr[])
    {
        if(i==n)
        {
            if(sum==0)
            return 1;
            return 0;
        }
        int take=0;
        if(arr[i]<=sum)
        take=rec(i+1,n,sum-arr[i],arr);
        int notTake=rec(i+1,n,sum,arr);
        return take | notTake;
    }
    int rec1(int i,int n,int sum,int arr[],vector<vector<int>>&dp)
    {
        if(i==n)
        {
            if(sum==0)
            return 1;
            return 0;
        }
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        int take=0;
        if(arr[i]<=sum)
        take=rec1(i+1,n,sum-arr[i],arr,dp);
        int notTake=rec1(i+1,n,sum,arr,dp);
        return dp[i][sum]=take | notTake;
    }
    int equalPartition(int n, int arr[])
    {
        // code here
        int total=0;
        for(int i=0;i<n;i++)
        total+=arr[i];
        if(total%2!=0)
        return 0;
        int sum=total/2;
        
        // recursion
        // return rec(0,n,sum,arr);
        
        // memoization
        // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        // return rec1(0,n,sum,arr,dp);
        
        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        // dp[n][0]=1;
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=0;j<=sum;j++)
        //     {
        //         int take=0;
        //         if(arr[i]<=j)
        //         take=dp[i+1][j-arr[i]];
        //         int notTake=dp[i+1][j];
        //         dp[i][j]=take | notTake;
        //     }
        // }
        // return dp[0][sum];
        
        // space optimization
        vector<int>dp(sum+1,0);
        vector<int>temp(sum+1,0);
        dp[0]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=sum;j++)
            {
                int take=0;
                if(arr[i]<=j)
                take=dp[j-arr[i]];
                int notTake=dp[j];
                temp[j]=take | notTake;
            }
            dp=temp;
        }
        return dp[sum];
    }
};