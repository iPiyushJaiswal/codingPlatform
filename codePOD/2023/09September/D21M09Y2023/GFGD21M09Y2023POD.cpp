/*Problem GFG (Medium)

Stickler Thief


Question link: https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1: Recursion

Time Complexity=O(2^n)

Space Complexity=O(n).

-----------------------------

Method 2: Memoization

Time Complexity=O(n)

Space Complexity=O(n)dp vector + O(n) recursive stack.

-----------------------------

Method 3: Tabulation

Time Complexity=O(n)

Space Complexity=O(n)dp vector

-----------------------------

Method 4: Space optimization

Time Complexity=O(n)

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int rec(int i,int arr[],int n)
    {
        if(i>=n)
        return 0;
        return max(arr[i] + rec(i+2,arr,n),rec(i+1,arr,n));
    }
    int rec1(int i,int arr[],int n,vector<long long>&dp)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        return dp[i]=max(arr[i] + rec1(i+2,arr,n,dp),
        rec1(i+1,arr,n,dp));
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // return rec(0,arr,n);
        
        // memoization
        // vector<long long>dp(n+2,-1);
        // return rec1(0,arr,n,dp);
        
        // tabulation
        // vector<int>dp(n+2,0);
        // for(int i=n-1;i>=0;i--)
        // {
        //     dp[i]=max(arr[i] + dp[i+2],dp[i+1]);
        // }
        // return dp[0];
        
        // space optimization
        int prev1=0,prev2=0,curr=0;
        for(int i=n-1;i>=0;i--)
        {
            curr=max(arr[i] + prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};