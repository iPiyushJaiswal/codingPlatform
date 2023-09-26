/*Problem GFG (Easy)

Find the closest pair from two arrays


Question link: https://practice.geeksforgeeks.org/problems/find-the-closest-pair-from-two-arrays4215/1

---------------------------

Logic: 2 Pointers

---------------------------

Complexity: 

Method 1: 2 Pointers

Time Complexity=O(n+m)

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : 2 Pointers
*/

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        int i=0;
        int j=m-1;
        int mini=INT_MAX;
        vector<int>ans(2);
        while(i<n && j>=0)
        {
            int sum=arr[i]+brr[j];
            if(mini>abs(sum-x))
            {
                mini=abs(sum-x);
                ans[0]=arr[i];
                ans[1]=brr[j];
            }
            if(sum<=x)
            i++;
            else
            j--;
        }
        return ans;
    }
};