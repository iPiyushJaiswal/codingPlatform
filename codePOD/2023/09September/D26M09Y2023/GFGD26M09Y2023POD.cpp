/*Problem GFG (Medium)

Find All Four Sum Numbers


Question link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

---------------------------

Logic: Sorting + 4SUM

---------------------------

Complexity: 

Method 1:Sorting + 4SUM

Time Complexity=O(n^3)

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Sorting + 4SUM
*/

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(i!=0 && arr[i]==arr[i-1])
            continue;
            int sum=k-arr[i];
            for(int j=i+1;j<n;j++)
            {
                if(j!=i+1 && arr[j]==arr[j-1])
                continue;
                int sum1=sum-arr[j];
                int low=j+1;
                int high=n-1;
                while(low<high)
                {
                    int sum2=arr[low]+arr[high];
                    if(sum1==sum2)
                    {
                        ans.push_back({arr[i],arr[j],arr[low],arr[high]});
                        low++;
                        high--;
                        while(low<high && arr[high]==arr[high+1])
                        high--;
                        while(low<high && arr[low]==arr[low-1])
                        low++;
                    }
                    else if(sum2<sum1)
                    low++;
                    else
                    high--;
                }
            }
        }
        return ans;
    }
};