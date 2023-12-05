/*Problem GFG (Medium)

Minimize the Heights II


Question link: https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1

---------------------------

Logic: Array

---------------------------

Complexity: 

Method 1 : Array

Time Complexity= O(nlogn)

Space Complexity= O(1)

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array
*/

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int ans=arr[n-1]-arr[0];
        int maxi,mini;
        for(int i=1;i<n;i++)
        {
            if(arr[i]-k<0)
            continue;
            maxi=max(arr[i-1]+k,arr[n-1]-k);
            mini=min(arr[i]-k,arr[0]+k);
            ans=min(ans,maxi-mini);
        }
        return ans;
    }
};