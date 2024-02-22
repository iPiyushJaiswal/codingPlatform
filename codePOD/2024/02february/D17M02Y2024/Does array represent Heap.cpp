/*Problem GFG (Easy)

Does array represent Heap


Question link:	https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

---------------------------

Logic: Array

---------------------------

Complexity: 

Method 1 : Array

Time Complexity= O(n)

Space Complexity= O(1) 
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array
*/


class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i=0;i<n;i++)
        {
            int l=0;
            if(i*2 +1 <n)
            l=arr[i*2 +1];
            int r=0;
            if(i*2 +2 <n)
            r=arr[i*2 +2];
            if(arr[i]<l || arr[i]<r)
            return false;
        }
        return true;
    }
};