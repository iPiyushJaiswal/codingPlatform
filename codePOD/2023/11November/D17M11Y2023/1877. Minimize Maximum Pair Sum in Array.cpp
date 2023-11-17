/*Problem LeetCode (Medium)

1877. Minimize Maximum Pair Sum in Array


Question link: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/description/?envType=daily-question&envId=2023-11-17


Logic: 2 Pointers

--------------------------

Complexity: 

Method 1: 2 Pointers

Time Complexity=O(nlogn)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 2 Pointers
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MIN;
        int i=0;
        int j=nums.size()-1;
        while(i<j)
        {
            ans=max(ans,nums[i]+nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};