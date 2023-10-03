/*Problem GFG (Medium)

Column name from a given column number


Question link: https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1

---------------------------

Logic: Maths

---------------------------

Complexity: 


Method 1: Maths

Time Complexity=O(logn)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Maths
*/

class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans;
        while(n>0)
        {
            n=n-1;
            int val=(n)%26;
            ans.push_back(val+'A');
            n/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};