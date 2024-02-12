/*Problem LeetCode (Easy)

169. Majority Element


Question link: https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12

Solution link: https://leetcode.com/problems/majority-element/submissions/1172817572/?envType=daily-question&envId=2024-02-12


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
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int val=-1e9+7;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                val=nums[i];
                count++;
            }
            else if(val==nums[i])
            count++;
            else
            count--;
        }
        if(val==-1e9+7)
        return -1;
        return val;
    }
};