/*Problem LeetCode (Medium)

1658. Minimum Operations to Reduce X to Zero


Question link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/description/


Logic: Sliding window

-------------------------

Complexity: 

Method 1: Sliding window 

Time Complexity=O(n)

Space Complexity=O(1) 

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Sliding window
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int l=n-1;
        int sum=0;
        while(l>=0 && sum<x)
        {
            sum+=nums[l];
            l--;
        }
        l++;
        if(sum<x)
        return -1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            while(sum>x && l<n)
            {
                sum-=nums[l];
                l++;
            }
            if(sum==x)
            ans=min(ans,i+n-l);
            sum+=nums[i];
            if(sum>x && l==n)
            break;
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
    }
};