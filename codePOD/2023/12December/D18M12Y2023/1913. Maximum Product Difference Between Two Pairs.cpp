/*Problem LeetCode (Easy)

1913. Maximum Product Difference Between Two Pairs


Question link: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/?envType=daily-question&envId=2023-12-18

Solution link: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/submissions/1122286658/?envType=daily-question&envId=2023-12-18


Logic : Array

--------------------------

Complexity: 

Method 1: Array

Time Complexity=O(n)

Space Complexity=O(1)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array
*/

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        int maxi1=0,maxi2=0;
        int mini1=INT_MAX,mini2=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(maxi1<nums[i])
            {
                maxi2=maxi1;
                maxi1=nums[i];
            }
            else if(maxi2<nums[i])
            maxi2=nums[i];
            if(mini1>nums[i])
            {
                mini2=mini1;
                mini1=nums[i];
            }
            else if(mini2>nums[i])
            mini2=nums[i];
        }
        return (maxi1*maxi2)-(mini1*mini2);
    }
};