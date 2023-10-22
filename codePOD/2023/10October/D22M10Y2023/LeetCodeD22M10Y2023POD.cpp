/*Problem LeetCode (Hard)

1793. Maximum Score of a Good Subarray


Question link: https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/?envType=daily-question&envId=2023-10-22


Logic: C2 pointer

-------------------------

Complexity: 

Method 1:  2 pointer

Time Complexity=O(n)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 2 pointer
*/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k;
        int j=k;
        int n=nums.size();
        int ans=nums[k];
        int mini=nums[k];
        while(i>0 || j<n-1)
        {
            if(i==0)
            j++;
            else if(j==n-1)
            i--;
            else if(nums[i-1]<nums[j+1])
            j++;
            else
            i--;
            mini=min(mini,min(nums[i],nums[j]));
            ans=max(ans,mini*(j-i+1));
        }
        return ans;
    }
};