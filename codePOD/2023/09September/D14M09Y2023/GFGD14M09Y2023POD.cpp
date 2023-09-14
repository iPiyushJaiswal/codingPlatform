/*Problem GFG (Medium)

Perfect Sum Problem


Question link: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

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
	int mod=1e9+7;
	int rec(int i,int arr[], int n, int sum)
	{
	    if(i==n)
	    {
	        if(sum==0)
	        return 1;
	        return 0;
	    }
	    int take=0;
	    if(arr[i]<=sum)
	    take=rec(i+1,arr,n,sum-arr[i]);
	    int notTake=rec(i+1,arr,n,sum);
	    return (take+notTake)%mod;
	}
	int rec1(int i,int arr[], int n, int sum,
	vector<vector<int>>&dp)
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
	    take=rec1(i+1,arr,n,sum-arr[i],dp);
	    int notTake=rec1(i+1,arr,n,sum,dp);
	    return dp[i][sum]=(take+notTake)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // return rec(0,arr,n,sum);
        
        // memoization
        // vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        // return rec1(0,arr,n,sum,dp);
        
        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        // dp[n][0]=1;
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=0;j<=sum;j++)
        //     {
        //         int take=0;
        // 	    if(arr[i]<=j)
        // 	    take=dp[i+1][j-arr[i]];
        // 	    int notTake=dp[i+1][j];
        // 	    dp[i][j]=(take+notTake)%mod;
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
        	    temp[j]=(take+notTake)%mod;
            }
            dp=temp;
        }
        return dp[sum];
	}
};