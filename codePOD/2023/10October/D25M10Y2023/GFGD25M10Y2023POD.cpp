/*Problem GFG (Medium)

Knapsack with Duplicate Items


Question link: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

---------------------------

Logic: DP

---------------------------

Complexity: DP


Method 1 : Recursion

Time Complexity= O(2^n) exponential.

Space Complexity=O(w) recursive space  

-----------------------------
Method 2 : Memoization

Time Complexity= O(n*w)

Space Complexity=O(n*w) dp vector+ O(w) recursive space  

-----------------------------
Method 3 : Tabulation

Time Complexity= O(n*w)

Space Complexity=O(n*w) dp vector   

-----------------------------
Method 4 : Space Optimization

Time Complexity= O(n*w)

Space Complexity=O(2*w) dp vector   

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution{
public:
    int rec(int N, int W, int val[], int wt[],int i)
    {
        if(i==N || W==0)
        return 0;
        // int maxi=INT_MIN;
        int take=0;
        if(W>=wt[i])
        take=val[i] + rec(N,W-wt[i],val,wt,i);
        int notTake=rec(N,W,val,wt,i+1);
        return max(take,notTake);
    }
    int rec1(int N, int W, int val[], int wt[],int i,
    vector<vector<int>>&dp)
    {
        if(i==N || W==0)
        return 0;
        if(dp[i][W]!=-1)
        return dp[i][W];
        int take=0;
        if(W>=wt[i])
        take=val[i] + rec1(N,W-wt[i],val,wt,i,dp);
        int notTake=rec1(N,W,val,wt,i+1,dp);
        return dp[i][W]=max(take,notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        // recursion
        // return rec(N,W,val,wt,0);
        
        // memoization
        // vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        // return rec1(N,W,val,wt,0,dp);
        
        // tabulation
        // vector<vector<int>>dp(N+1,vector<int>(W+1,0));
        // for(int i=N-1;i>=0;i--)
        // {
        //     for(int j=0;j<=W;j++)
        //     {
        //         int take=0;
        //         if(j>=wt[i])
        //         take=val[i] + dp[i][j-wt[i]];
        //         int notTake=dp[i+1][j];
        //         dp[i][j]=max(take,notTake);
        //     }
        // }
        // return dp[0][W];
        
        // space optimization
        vector<int>dp(W+1,0);
        vector<int>temp(W+1,0);
        for(int i=N-1;i>=0;i--)
        {
            for(int j=0;j<=W;j++)
            {
                int take=0;
                if(j>=wt[i])
                take=val[i] + temp[j-wt[i]];
                int notTake=dp[j];
                temp[j]=max(take,notTake);
            }
            dp=temp;
        }
        return dp[W];
    }
};