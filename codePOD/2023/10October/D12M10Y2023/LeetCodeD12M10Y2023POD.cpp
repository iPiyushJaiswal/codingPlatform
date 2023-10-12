/*Problem LeetCode (Hard)

1095. Find in Mountain Array


Question link: https://leetcode.com/problems/find-in-mountain-array/?envType=daily-question&envId=2023-10-12


Logic: Binary Search

-------------------------

Complexity: 

Method 1:  Binary Search

Time Complexity=O(3*n*logn)

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
    int findInMountainArray(int target, MountainArray &arr) {
        int n=arr.length();
        int low=0;
        int high=n-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int mVal=arr.get(mid);
            int mNVal=arr.get(mid+1);
            if(mNVal>mVal)
            low=mid+1;
            else
            high=mid-1;
        }
        int pivot=low;
        low=0;
        high=pivot;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int mVal=arr.get(mid);
            if(mVal==target)
            {
                ans=mid;
                break;
            }
            else if(mVal<target)
            low=mid+1;
            else
            high=mid-1;
        }
        if(ans!=-1)
        return ans;
        low=pivot+1;
        high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int mVal=arr.get(mid);
            if(mVal==target)
            {
                ans=mid;
                break;
            }
            else if(mVal>target)
            low=mid+1;
            else
            high=mid-1;
        }
        return ans;
    }
};