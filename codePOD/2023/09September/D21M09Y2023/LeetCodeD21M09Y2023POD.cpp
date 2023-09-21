/*Problem LeetCode (HARD)

4. Median of Two Sorted Arrays


Question link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=daily-question&envId=2023-09-21


Logic: Binary Search cut logic

-------------------------

Complexity: 

Method 1:  Binary Search

Time Complexity=O(log(min(n1,n2)))

Space Complexity=O(1) 

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Binary Search
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2)
        return findMedianSortedArrays(nums2,nums1);
        int low=0;
        int high=n1;
        int left=(n1+n2+1)/2;
        while(low<=high)
        {
            int mid1=(low+high)>>1;
            int mid2=left-mid1;
            int lCut1=(mid1-1)>=0?nums1[mid1-1]:INT_MIN;
            int lCut2=(mid2-1)>=0?nums2[mid2-1]:INT_MIN;

            int rCut1=(mid1)<n1?nums1[mid1]:INT_MAX;
            int rCut2=mid2<n2?nums2[mid2]:INT_MAX;

            if(lCut1<=rCut2 && lCut2<=rCut1)
            {
                if((n1+n2)%2==0)
                return (double)(max(lCut1,lCut2)+min(rCut1,rCut2))/2.0;
                else
                return max(lCut1,lCut2);
            }
            else if(lCut1>rCut2)
            high=mid1-1;
            else
            low=mid1+1;
        }
        return -1;
    }
};