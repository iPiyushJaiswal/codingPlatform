/*Problem LeetCode (Easy)

1287. Element Appearing More Than 25% In Sorted Array


Question link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/?envType=daily-question&envId=2023-12-11

Solution link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/submissions/1117443880/?envType=daily-question&envId=2023-12-11


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
    int findSpecialInteger(vector<int>& arr) {
        int count=0;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            if(arr[i]!=arr[i-1])
            count=0;
            count++;
            if(count>n/4)
            return arr[i];
        }
        return arr[0];
    }
};