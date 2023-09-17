/*Problem GFG (Basic)

Print first n Fibonacci Numbers


Question link: https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1: DP

Time Complexity=O(n)

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution
{
    public:
    vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long>ans;
        ans.push_back(1);
        if(n==1)
        return ans;
        ans.push_back(1);
        if(n==2)
        return ans;
        for(int i=2;i<n;i++)
        {
            long long curr=ans[i-1]+ans[i-2];
            ans.push_back(curr);
        }
        return ans;
    }
};