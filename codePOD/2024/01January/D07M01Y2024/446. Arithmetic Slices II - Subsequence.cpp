/*Problem LeetCode (Hard)

446. Arithmetic Slices II - Subsequence


Question link: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/?envType=daily-question&envId=2024-01-07

Solution link: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/submissions/1139631527/?envType=daily-question&envId=2024-01-07


Logic : DP

--------------------------
Complexity: 

Method 1: DP

Time Complexity=O(n*n)

Space Complexity=O(n*n) DP
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<unordered_map<long long,int>>dp(n);
        dp[0][0]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                long long diff = (long long)(nums[i]) - (long long)(nums[j]);
                dp[i][diff]++;
                if(dp[j].find(diff)!=dp[j].end())
                {
                    dp[i][diff]+=dp[j][diff];
                    ans+=dp[j][diff];
                }
            }
        }
        return ans;
    }
};