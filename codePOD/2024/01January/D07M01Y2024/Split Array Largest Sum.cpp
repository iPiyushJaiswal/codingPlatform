/*Problem GFG (Hard)

Split Array Largest Sum


Question link: https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1

---------------------------

Logic: Binary Search

---------------------------

Complexity: 

Method 1 : Binary Search

Time Complexity= O(N*log(sum(arr)))

Space Complexity= O(1) Sieve Vector
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Binary Search
*/

class Solution {
  public:
  int isSafe(int mid,int arr[],int n)
  {
      int count=0;
      int sum=0;
      for(int i=0;i<n;i++)
      {
          sum+=arr[i];
          if(mid<arr[i])
          return INT_MAX;
          if(sum>mid)
          {
              count++;
              sum=arr[i];
          }
      }
      return count;
  }
    int splitArray(int arr[] ,int n, int k) {
        // code here
        int high=0;
        for(int i=0;i<n;i++)
        high+=arr[i];
        int low=0;
        int ans=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isSafe(mid,arr,n)<k)
            {
                ans=mid;
                high=mid-1;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};