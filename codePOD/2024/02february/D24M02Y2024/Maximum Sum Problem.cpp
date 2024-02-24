/*Problem GFG (Easy)

Maximum Sum Problem


Question link:	https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(3^n)

Space Complexity= O(n) recursive stack
----------------------------------
Method 2 : Memoization

Time Complexity= O(n)

Space Complexity= O(n) dp vector + O(n) recursive stack
----------------------------------
Method 3 : Tabulation

Time Complexity= O(n)

Space Complexity= O(n) dp vector
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution
{
    public:
    int rec(int n)
    {
        if(n==0)
        return 0;
        int maxi=n;
        int a=rec(n/2);
        int b=rec(n/3);
        int c=rec(n/4);
        if(a+b+c<n)
        return n;
        return a+b+c;
    }
    int rec1(int n,vector<int>&dp)
    {
        if(n==0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];
        int maxi=n;
        int a=rec1(n/2,dp);
        int b=rec1(n/3,dp);
        int c=rec1(n/4,dp);
        if(a+b+c<n)
        return dp[n]=n;
        return dp[n]=a+b+c;
    }
        int maxSum(int n)
        {
            //code here.
            
            // recursion
            // return rec(n);
            
            //memoization
            // vector<int>dp(n+1,-1);
            // return rec1(n,dp);
            
            // tabulation
            vector<int>dp(n+1,0);
            for(int i=1;i<=n;i++)
            {
                int maxi=i;
                int a=dp[i/2];
                int b=dp[i/3];
                int c=dp[i/4];
                if(a+b+c<i)
                dp[i]=i;
                else
                dp[i]=a+b+c;
            }
            return dp[n];
        }
};