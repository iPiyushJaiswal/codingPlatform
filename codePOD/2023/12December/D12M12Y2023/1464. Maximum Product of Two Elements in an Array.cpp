/*Problem LeetCode (Easy)

1464. Maximum Product of Two Elements in an Array


Question link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/?envType=daily-question&envId=2023-12-12

Solution link: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/submissions/1118105428/?envType=daily-question&envId=2023-12-12


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
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi1=0;
        int maxi2=0;
        for(int i=0;i<n;i++)
        {
            if(maxi1<nums[i])
            {
                maxi2=maxi1;
                maxi1=nums[i];
            }
            else if(maxi2<nums[i])
            maxi2=nums[i];
        }
        return (maxi1-1)*(maxi2-1);
    }
};