/*Problem GFG (Easy)

Find duplicates in an array


Question link: https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1

---------------------------

Logic: Maths

---------------------------

Complexity: 

Method 1:Maths

Time Complexity=O(2*n)

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Maths
*/

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int ind=arr[i]%n;
            arr[ind]+=n;
        }
        for(int i=0;i<n;i++)
        {
            if((arr[i]/n)>1)
            ans.push_back(i);
        }
        if(ans.size()==0)
        return {-1};
        return ans;
    }
};