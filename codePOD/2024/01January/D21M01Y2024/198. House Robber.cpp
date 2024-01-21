/*Problem LeetCode (Medium)

198. House Robber


Question link: https://leetcode.com/problems/house-robber/?envType=daily-question&envId=2024-01-21

Solution link: https://leetcode.com/problems/house-robber/submissions/1152331690/?envType=daily-question&envId=2024-01-21


Logic : DP

--------------------------
Complexity: 

Method 1: Recursive

Time Complexity=O(2^n)

Space Complexity=O(n) recursive stack
--------------------------
Method 2: Memoization

Time Complexity=O(n)

Space Complexity=O(n) dp vector + O(n) recursive stack
--------------------------
Method 3: Tabulation

Time Complexity=O(n)

Space Complexity=O(n) dp vector
--------------------------
Method 4: Space Optimization

Time Complexity=O(n)

Space Complexity=O(1) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
public:
int rec(vector<int>& nums,int i,int n)
{
    if(i>=n)
    return 0;
    return max(nums[i]+rec(nums,i+2,n),rec(nums,i+1,n));
}
int rec1(vector<int>& nums,int i,int n,vector<int>&dp)
{
    if(i>=n)
    return 0;
    if(dp[i]!=-1)
    return dp[i];
    return dp[i]=max(nums[i]+rec1(nums,i+2,n,dp),rec1(nums,i+1,n,dp));
}
    int rob(vector<int>& nums) {
        int n=nums.size();

        // recursion
        // return rec(nums,0,n);

        // memoization
        // vector<int>dp(n+1,-1);
        // return rec1(nums,0,n,dp);

        // tabulation
        // vector<int>dp(n+2,0);
        // for(int i=n-1;i>=0;i--)
        // {
        //     dp[i]=max(nums[i]+dp[i+2],dp[i+1]);
        // }
        // return dp[0];

        // space optimization
        int prev1=0,prev2=0,curr;
        for(int i=n-1;i>=0;i--)
        {
            curr=max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};