/*Problem LeetCode (Easy)

119. Pascal's Triangle II


Question link: https://leetcode.com/problems/pascals-triangle-ii/description/?envType=daily-question&envId=2023-10-16


Logic: DP

-------------------------

Complexity: 

Method 1:  Brute Force

Time Complexity=O(n*n)

Space Complexity=O(2n) dp vector

--------------------------
Method 2:  Better

Time Complexity=O(n*n)

Space Complexity=O(n) dp vector

--------------------------
Method 3:  Optimized

Time Complexity=O(n)

Space Complexity=O(n) dp vector

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // bruteforce
        // if(rowIndex==0)
        // return {1};
        // vector<int>dp(2,1);
        // for(int i=2;i<=rowIndex;i++)
        // {
        //     vector<int>temp(i+1);
        //     temp[0]=1;
        //     temp[i]=1;
        //     for(int j=1;j<i;j++)
        //     temp[j]=dp[j-1]+dp[j];
        //     dp.resize(i+1);
        //     dp=temp;
        // }
        // return dp;

        // better
        // vector<int>dp(rowIndex+1,1);
        // for(int i=0;i<=rowIndex;i++)
        // {
        //     for(int j=i-1;j>0;j--)
        //     dp[j]=dp[j]+dp[j-1];
        // }
        // return dp;
        
        // optimized
        vector<int>dp(rowIndex+1,1);
        for(int i=1;i<=rowIndex/2;i++)
        {
            dp[i]=1ll*dp[i-1]*(rowIndex-i+1)/i;
            dp[rowIndex-i]=dp[i];            
        }
        return dp;
    }
};