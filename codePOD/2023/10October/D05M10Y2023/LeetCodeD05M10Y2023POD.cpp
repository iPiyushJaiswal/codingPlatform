/*Problem LeetCode (Medium)

229. Majority Element II


Question link: https://leetcode.com/problems/majority-element-ii/description/?envType=daily-question&envId=2023-10-05

Logic: 2 value 2 count concept

-------------------------

Complexity: 

Method 1:  2 value 2 count concept

Time Complexity=O(n)

Space Complexity=O(1) 

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 2 value 2 count concept
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int val1=INT_MIN;
        int val2=INT_MIN;
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++)
        {
            if(val1==nums[i])
            {
                count1++;
            }
            else if(val2==nums[i])
            {
                count2++;
            }
            else if(count1==0)
            {
                val1=nums[i];
                count1++;
            }
            else if(count2==0)
            {
                val2=nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==val1)
            count1++;
            else if(nums[i]==val2)
            count2++;
        }
        if(count1>n/3 && count2>n/3)
        return {val1,val2};
        else if(count1>n/3)
        return {val1};
        else if(count2>n/3)
        return {val2};
        return {};


    }
};