/*Problem GFG (Medium)

Number of subarrays with maximum values in given range


Question link: https://www.geeksforgeeks.org/problems/number-of-subarrays-with-maximum-values-in-given-range5949/1

---------------------------

Logic: Sliding Window

---------------------------

Complexity: 

Method 1 : Sliding Window

Time Complexity= O(n)

Space Complexity= O(1)

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Sliding Window
*/

class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        int i=0;
        int j=0;
        long count=0;
        long temp=0;
        while(j<n)
        {
            if(a[j]>R)
            {
                temp=0;
                i=j+1;
            }
            else if(a[j]>=L && a[j]<=R)
            temp=j-i+1;
            count+=temp;
            j++;
        }
        return count;
    }
};