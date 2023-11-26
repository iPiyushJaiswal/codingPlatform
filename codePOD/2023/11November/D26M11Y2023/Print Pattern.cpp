/*Problem GFG (Easy)

Print Pattern


Question link: https://www.geeksforgeeks.org/problems/print-pattern3549/1

---------------------------

Logic: Recursion

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(n/5)

Space Complexity= O(n/5) recursive stack

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Recursion
*/

class Solution{
public:
void rec(int i,int N,vector<int>&ans)
{
    if(i<=0)
    {
        ans.push_back(i);
        return;
    }
    ans.push_back(i);
    rec(i-5,N,ans);
    ans.push_back(i);
}
    vector<int> pattern(int N){
        // code here
        vector<int>ans;
        rec(N,N,ans);
        return ans;
    }
};