/*Problem LeetCode (Hard)

1458. Max Dot Product of Two Subsequences


Question link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/?envType=daily-question&envId=2023-10-08

Logic: Recursion + Memoization + Tabulation + Space Optimization

-------------------------

Complexity: 

Method 1:  Recursion

Time Complexity=O(exponential)=O(2^n)

Space Complexity=O(n) recursive stack

--------------------------
Method 2:  DP Memoization

Time Complexity=O(n*n)

Space Complexity=O(n*n) dp vector +  O(n) recursive stack

--------------------------
Method 3:  DP Tabulation

Time Complexity=O(n*n)

Space Complexity=O(n*n) dp vector

--------------------------
Method 4:  DP Space Optimization

Time Complexity=O(n*n)

Space Complexity=O(2n) dp,temp vector

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Recursion + Memoization + Tabulation + Space Optimization
*/

class Solution {
public:
int rec(int i,int j,int n,int m,vector<int>& nums1, vector<int>& nums2)
{
    if(i==n || j==m)
    return 0;
    int take=nums1[i]*nums2[j] + rec(i+1,j+1,n,m,nums1,nums2);
    int notTake=max(rec(i+1,j,n,m,nums1,nums2),rec(i,j+1,n,m,nums1,nums2));
    return max(take,notTake);
}
int rec1(int i,int j,int n,int m,vector<int>& nums1, vector<int>& nums2,
vector<vector<int>>&dp)
{
    if(i==n || j==m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int take=nums1[i]*nums2[j] + rec1(i+1,j+1,n,m,nums1,nums2,dp);
    int notTake=max(rec1(i+1,j,n,m,nums1,nums2,dp),
    rec1(i,j+1,n,m,nums1,nums2,dp));
    return dp[i][j]=max(take,notTake);
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        // recursion
        // int ans=rec(0,0,n,m,nums1,nums2);

        // memoization
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // int ans=rec1(0,0,n,m,nums1,nums2,dp);

        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=m-1;j>=0;j--)
        //     {
        //         int take=nums1[i]*nums2[j] + dp[i+1][j+1];
        //         int notTake=max(dp[i+1][j],dp[i][j+1]);
        //         dp[i][j]=max(take,notTake);
        //     }
        // }
        // int ans=dp[0][0];

        // space optimization
        vector<int>dp(m+1,0);
        vector<int>temp(m+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                int take=nums1[i]*nums2[j] + dp[j+1];
                int notTake=max(dp[j],temp[j+1]);
                temp[j]=max(take,notTake);
            }
            dp=temp;
        }
        int ans=dp[0];
        if(ans==0)
        {
            int a=INT_MIN,b=INT_MAX,c=INT_MIN,d=INT_MAX;
            for(int i=0;i<n;i++)
            {
                a=max(a,nums1[i]);
                b=min(b,nums1[i]);
            }
            for(int i=0;i<m;i++)
            {
                c=max(c,nums2[i]);
                d=min(d,nums2[i]);
            }
            return max(a*d,b*c);
        }
        return ans;
    }
};