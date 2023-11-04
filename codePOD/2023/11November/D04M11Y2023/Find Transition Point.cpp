/*Problem GFG (Easy)

Find Transition Point


Question link: https://www.geeksforgeeks.org/problems/find-transition-point-1587115620/1

---------------------------

Logic: Binary Search

---------------------------

Complexity: 

Method 1 : Binary Search

Time Complexity= O(logn).

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Binary Search
*/

class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        // code here
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==1)
            high=mid-1;
            else
            low=mid+1;
        }
        if(low==n)
        return -1;
        return low;
    }
};