/*Problem GFG (Medium)

Largest Sum Subarray of Size at least K


Question link: https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1

---------------------------

Logic: DP + Sliding Window

---------------------------

Complexity: 

Method 1 : DP + Sliding Window

Time Complexity= O(n)

Space Complexity= O(n) DP vector
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP + Sliding Window
*/

class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<long long int>dp(n);
        dp[n-1]=max(0ll,a[n-1]);
        for(long long int i=n-2;i>=0;i--)
        dp[i]=max(0ll,dp[i+1]+a[i]);
        
        long long int i=0;
        long long int sum=0;
        long long int ans=INT_MIN;
        while(i<k)
        {
            sum+=a[i];
            i++;
        }
        while(i<n)
        {
            ans=max(ans,sum+dp[i]);
            sum+=a[i]-a[i-k];
            i++;
        }
        ans=max(ans,sum);
        return ans;
    }
};