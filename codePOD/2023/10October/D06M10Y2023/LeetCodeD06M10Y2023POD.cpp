/*Problem LeetCode (Medium)

343. Integer Break


Question link: https://leetcode.com/problems/integer-break/description/?envType=daily-question&envId=2023-10-06

Logic: recursion + dp + maths

-------------------------

Complexity: 

Method 1:  recursion

Time Complexity=O(exponential)

Space Complexity=O(n) recursive stack

--------------------------
Method 2:  DP Tabulation

Time Complexity=O(n*n)

Space Complexity=O(n) dp vector

--------------------------
Method 3:  Maths

Time Complexity=O(1)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : recursion + dp + maths
*/

class Solution {
public:
    int rec(int i)
    {
        if(i<=1)
        return 1;
        int ans=0;
        for(int j=1;j<i;j++)
        {
            int a=j*max(i-j,rec(i-j));
            ans=max(ans,a);
        }
        return ans;
    }
    int integerBreak(int n) {
        // return rec(n);

        // tabulation
        // vector<int>dp(n+1,-1);
        // dp[0]=dp[1]=1;
        // for(int i=2;i<=n;i++)
        // {
        //     int ans=0;
        //     for(int j=1;j<i;j++)
        //     {
        //         int a=j*max(i-j,dp[i-j]);
        //         ans=max(ans,a);
        //     }
        //     dp[i]=ans;
        // }
        // return dp[n];

        // maths
        if(n<=3)
        return n-1;
        int count2=n%3;
        int count3=n/3;
        if(count2==2)
        count2--;
        else if(count2==1)
        {
            count2++;
            count3--;
        }
        return pow(3,count3)*pow(2,count2);
    }
};