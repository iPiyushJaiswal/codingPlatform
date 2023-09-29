/*Problem LeetCode (Easy)

896. Monotonic Array


Question link: https://leetcode.com/problems/monotonic-array/description/?envType=daily-question&envId=2023-09-29

Logic: Iteration

-------------------------

Complexity: 

Method 1:  Iteration

Time Complexity=O(2n)

Space Complexity=O(1) 

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Iteration
*/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return true;
        int flag=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            {
                flag=0;
                break;
            }
            flag=1;
        }
        if(flag==1)
        return true;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
             {
                flag=0;
                break;
            }
            flag=1;
        }
        return (flag==1);
    }
};