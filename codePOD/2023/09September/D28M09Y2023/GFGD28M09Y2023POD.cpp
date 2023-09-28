/*Problem GFG (Easy)

Wave Array


Question link: https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1

---------------------------

Logic: Iteration

---------------------------

Complexity: 

Method 1: Iteration

Time Complexity=O(n)

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Iteration
*/

class Solution{
    public:
    void convertToWave(int n, vector<int>& arr){
        // Your code here
        for(int i=1;i<n;)
        {
            swap(arr[i-1],arr[i]);
            i+=2;
        }
    }
};