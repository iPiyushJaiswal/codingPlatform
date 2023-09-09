/*Problem LeetCode (Medium)

377. Combination Sum IV


Question link: https://leetcode.com/problems/combination-sum-iv/description/?envType=daily-question&envId=2023-09-09

Logic: Array + Maths.   

Complexity: 

Method 1: Recursion .

Time Complexity=exponential O(n^x) n=number of element in array, x=number of element taken to reach target.

Space Complexity=exponential O(x), x=number of element taken to reach target. Recursive stack. 

-----------------------------

Method 2: Memoization .

Time Complexity=O(n*x)

Space Complexity=O(target) dp vector + O(x) Recursive stack

-----------------------------

Method 3: Tabulation .

Time Complexity=O(n*x)

Space Complexity=O(target) dp vector

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------
*/

class Solution {
public:
    int rec(int n,vector<int> &nums,int target)
    {
        if(target==0)
        return 1;
        if(target<0)
        return 0;
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(target>=nums[j])
            count+=rec(n,nums,target-nums[j]);
        }
        return count;
    }
    int rec1(int n,vector<int> &nums,int target,vector<int>&dp)
    {
        if(target==0)
        return 1;
        if(target<0)
        return 0;
        if(dp[target]!=-1)
        return dp[target];
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(target>=nums[j])
            count+=rec1(n,nums,target-nums[j],dp);
        }
        return dp[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        // return rec(n,nums,target);
        // memoization
        // vector<int>dp(target+1,-1);
        // return rec1(n,nums,target,dp);

        // tabulaion
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            long long count=0;
            for(int j=0;j<n;j++)
            {
                if(i>=nums[j])
                count+=dp[i-nums[j]];
            }
            dp[i]=count;
        }
        return dp[target];
    }
};