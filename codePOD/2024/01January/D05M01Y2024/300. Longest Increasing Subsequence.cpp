/*Problem LeetCode (Medium)

300. Longest Increasing Subsequence


Question link: https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=daily-question&envId=2024-01-05

Solution link: https://leetcode.com/problems/longest-increasing-subsequence/submissions/1137704800/?envType=daily-question&envId=2024-01-05


Logic : DP + Binary Search

--------------------------
Complexity: 

Method 1: Recursion

Time Complexity=O(2^n)

Space Complexity=O(n) recursive stack 
--------------------------
Method 2: Memoization

Time Complexity=O(n*n)

Space Complexity=O(n*n) dp vector + O(n) recursive stack 
--------------------------
Method 3: Tabulation

Time Complexity=O(n*n)

Space Complexity=O(n*n) dp vector
--------------------------
Method 4: Space Optimization 1

Time Complexity=O(n*n)

Space Complexity=O(2*n) dp vector
--------------------------
Method 5: Space Optimization 2

Time Complexity=O(nlogn)

Space Complexity=O(1)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP + Binary Search
*/

class Solution {
public:
    int rec(int i,int n,vector<int>& nums,int prev)
    {
        if(i==n)
        return 0;
        int a=0;
        if(prev==-1 || nums[i]>nums[prev])
        a=1+rec(i+1,n,nums,i);
        int b=rec(i+1,n,nums,prev);
        return max(a,b);
    }
    int rec1(int i,int n,vector<int>& nums,int prev,vector<vector<int>>&dp)
    {
        if(i==n)
        return 0;
        if(dp[i][prev+1]!=-1)
        return dp[i][prev+1];
        int a=0;
        if(prev==-1 || nums[i]>nums[prev])
        a=1+rec1(i+1,n,nums,i,dp);
        int b=rec1(i+1,n,nums,prev,dp);
        return dp[i][prev+1]=max(a,b);
    }
    void bs(vector<int>&temp,int val)
    {
        int low=0;
        int high=temp.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(temp[mid]<val)
            low=mid+1;
            else
            high=mid-1;
        }
        if(low==temp.size())
        temp.push_back(val);
        else
        temp[low]=val;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // recursion
        // return rec(0,n,nums,-1);

        // memoization
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return rec1(0,n,nums,-1,dp);

        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=i-1;j>=-1;j--)
        //     {
        //         int a=0;
        //         if(j==-1 || nums[i]>nums[j])
        //         a=1+dp[i+1][i+1];
        //         int b=dp[i+1][j+1];
        //         dp[i][j+1]=max(a,b);
        //     }
        // }
        // return dp[0][0];

        // space optimization
        // vector<int>dp(n+2,0);
        // vector<int>temp(n+2,0);
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=i-1;j>=-1;j--)
        //     {
        //         int a=0;
        //         if(j==-1 || nums[i]>nums[j])
        //         a=1+dp[i+1];
        //         int b=dp[j+1];
        //         temp[j+1]=max(a,b);
        //     }
        //     dp=temp;
        // }
        // return dp[0];

        // space optimize 2
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            bs(temp,nums[i]);
        }
        return temp.size();
    }
};