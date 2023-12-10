/*Problem GFG (Medium)

Subarray with 0 sum


Question link: https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

---------------------------

Logic: Subarray

---------------------------

Complexity: 

Method 1 : Subarray

Time Complexity= O(n)

Space Complexity= O(n)

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Subarray
*/

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int>st;
        st.insert(0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(st.find(sum)!=st.end())
            return true;
            st.insert(sum);
        }
        return false;
    }
};