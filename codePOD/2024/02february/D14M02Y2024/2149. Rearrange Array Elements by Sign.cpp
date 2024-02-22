/*Problem LeetCode (Medium)

2149. Rearrange Array Elements by Sign


Question link: https://leetcode.com/problems/rearrange-array-elements-by-sign/?envType=daily-question&envId=2024-02-14

Solution link: https://leetcode.com/problems/rearrange-array-elements-by-sign/submissions/1174659511/?envType=daily-question&envId=2024-02-14


Logic : Array

--------------------------
Complexity: 

Method 1: Array

Time Complexity=O(x)

Space Complexity=O(x)  
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int x=nums.size();
        vector<int>ans(x,0);
        int p=0,n=1;
        for(int i=0;i<x;i++)
            {
            if(nums[i]<0)
                {
                ans[n]=nums[i];
                n+=2;
            }
            else
                {
                ans[p]=nums[i];
                p+=2;
            }
        }
        return ans;
    }
};