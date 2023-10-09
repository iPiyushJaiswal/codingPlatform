/*Problem LeetCode (Hard)

34. Find First and Last Position of Element in Sorted Array


Question link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/?envType=daily-question&envId=2023-10-09


Logic: Binary Search

-------------------------

Complexity: 

Method 1:  Binary Search

Time Complexity=O(2logn)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Binary Search
*/

class Solution {
public:
    int binarySearch(int low,int high,vector<int>& nums, int target,int dir)
    {
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                if(dir==0)
                high=mid-1;
                else
                low=mid+1;
            }
            else if(nums[mid]<target)
            low=mid+1;
            else
            high=mid-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=binarySearch(0,n-1,nums,target,0);
        if(low==-1)
        return {-1,-1};
        int high=binarySearch(0,n-1,nums,target,1);
        return {low,high};
    }
};