/*Problem LeetCode (Medium)

1043. Partition Array for Maximum Sum


Question link: https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03

Solution link: https://leetcode.com/problems/partition-array-for-maximum-sum/submissions/1164535356/?envType=daily-question&envId=2024-02-03


Logic : DP + Sliding Window

--------------------------
Complexity: 

Method 1: Recursion

Time Complexity=O(k^n)

Space Complexity=O(n) 
--------------------------
Method 2: Memoization

Time Complexity=O(n*k)

Space Complexity=O(n) + O(n) recursive stack.
--------------------------
Method 3: Tabulation

Time Complexity=O(n*k)

Space Complexity=O(n) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP + Sliding Window
*/

class Solution {
public:
    int rec(int i,int n,vector<int>& arr,int k)
    {
        if(i==n)
        return 0;
        int maxi=0;
        int ans=0;
        for(int j=0;j<k;j++)
        {
            if(i+j<n)
            {
                maxi=max(maxi,arr[i+j]);
                int val=maxi*(j+1) + rec(i+j+1,n,arr,k);
                ans=max(ans,val);
            }
            else
            break;
        }
        return ans;
    }
    int rec1(int i,int n,vector<int>& arr,int k,vector<int>&dp)
    {
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int maxi=0;
        int ans=0;
        for(int j=0;j<k;j++)
        {
            if(i+j<n)
            {
                maxi=max(maxi,arr[i+j]);
                int val=maxi*(j+1) + rec1(i+j+1,n,arr,k,dp);
                ans=max(ans,val);
            }
            else
            break;
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        // recursion
        // return rec(0,n,arr,k);

        // memoization
        // vector<int>dp(n+1,-1);
        // return rec1(0,n,arr,k,dp);

        // tabulation
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int maxi=0;
            int ans=0;
            for(int j=0;j<k;j++)
            {
                if(i+j<n)
                {
                    maxi=max(maxi,arr[i+j]);
                    int val=maxi*(j+1) + dp[i+j+1];
                    ans=max(ans,val);
                }
                else
                break;
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};