/*Problem GFG (Medium)

Buy and Sell a Share at most twice


Question link:	https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^n)

Space Complexity= O(n) recursive stack
----------------------------------
Method 2 : Memoization

Time Complexity= O(n*2*2)

Space Complexity= O(n*2*2) dp vector + O(n) recursive stack
----------------------------------
Method 3 : Tabulation

Time Complexity= O(n*2*2)

Space Complexity= O(n*2*2) dp vector
----------------------------------
Method 4 : Space Optimization

Time Complexity= O(n*2*2)

Space Complexity= O(2*2*2) dp vector
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
        //User function Template for C++
        int rec(int i,int n,vector<int>&price,int buy,int lim)
        {
            if(i==n || lim==0)
            return 0;
            if(buy==0)
            return max(-price[i]+rec(i+1,n,price,1,lim),
            rec(i+1,n,price,0,lim));
            else
            return max(price[i]+rec(i+1,n,price,0,lim-1),
            rec(i+1,n,price,1,lim));
        }
        int rec1(int i,int n,vector<int>&price,int buy,int lim,
        vector<vector<vector<int>>>&dp)
        {
            if(i==n || lim==0)
            return 0;
            if(dp[i][buy][lim]!=-1)
            return dp[i][buy][lim];
            if(buy==0)
            return dp[i][buy][lim]=max(-price[i]+rec1(i+1,n,price,1,lim,dp),
            rec1(i+1,n,price,0,lim,dp));
            else
            return dp[i][buy][lim]=max(price[i]+rec1(i+1,n,price,0,lim-1,dp),
            rec1(i+1,n,price,1,lim,dp));
        }
        int maxProfit(vector<int>&price){
            //Write your code here..
            int n=price.size();
            
            // recursion
            // return rec(0,n,price,0,2);
            
            // memoization
            // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,
            // vector<int>(3,-1)));
            // return rec1(0,n,price,0,2,dp);
            
            // tabulation
            // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,
            // vector<int>(3,0)));
            // for(int i=n-1;i>=0;i--)
            // {
            //     for(int buy=1;buy>=0;buy--)
            //     {
            //         for(int lim=1;lim<=2;lim++)
            //         {
            //             if(buy==0)
            //             dp[i][buy][lim]=max(-price[i]+dp[i+1][1][lim],
            //             dp[i+1][0][lim]);
            //             else
            //             dp[i][buy][lim]=max(price[i]+dp[i+1][0][lim-1],
            //             dp[i+1][1][lim]);
            //         }
            //     }
            // }
            // return dp[0][0][2];
            
            // space optimization
            vector<vector<int>>dp(2,vector<int>(3,0));
            vector<vector<int>>temp(2,vector<int>(3,0));
            for(int i=n-1;i>=0;i--)
            {
                for(int buy=1;buy>=0;buy--)
                {
                    for(int lim=1;lim<=2;lim++)
                    {
                        if(buy==0)
                        temp[buy][lim]=max(-price[i]+dp[1][lim],
                        dp[0][lim]);
                        else
                        temp[buy][lim]=max(price[i]+dp[0][lim-1],
                        dp[1][lim]);
                    }
                }
                dp=temp;
            }
            return dp[0][2];
        }
};