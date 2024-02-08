/*Problem LeetCode (Medium)

279. Perfect Squares


Question link: https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08

Solution link: https://leetcode.com/problems/perfect-squares/submissions/1169408867/?envType=daily-question&envId=2024-02-08


Logic : DP

--------------------------
Complexity: 

Method 1: DP

Time Complexity=O(n*sqrt(n))

Space Complexity=O(n) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                dp[i]=min(1+dp[i-j*j],dp[i]);
            }
        }
        return dp[n];
    }
};