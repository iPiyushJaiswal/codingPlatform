/*Problem LeetCode (Easy)

905. Sort Array By Parity


Question link: https://leetcode.com/problems/sort-array-by-parity/description/?envType=daily-question&envId=2023-09-28

Logic: Iteration

-------------------------

Complexity: 

Method 1:  Iteration

Time Complexity=O(n)

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
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int even=0;
        while(i<n)
        {
            if(nums[i]%2==0)
            {
                swap(nums[i],nums[even]);
                even++;
            }
            i++;
        }
        return nums;
    }
};