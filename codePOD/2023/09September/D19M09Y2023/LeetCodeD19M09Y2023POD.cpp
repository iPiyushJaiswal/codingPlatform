/*Problem LeetCode (Medium)

287. Find the Duplicate Number


Question link: https://leetcode.com/problems/find-the-duplicate-number/description/


Logic: Slow Fast Pointer LinkedList Cycle

-------------------------

Complexity: 

Method 1: Slow Fast Pointer LinkedList Cycle 

Time Complexity=O(n)

Space Complexity=O(1) 

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Slow Fast Pointer LinkedList Cycle
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=0;
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};