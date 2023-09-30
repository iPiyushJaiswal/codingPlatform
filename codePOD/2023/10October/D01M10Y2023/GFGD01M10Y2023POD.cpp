/*Problem GFG (Easy)

Boundary traversal of matrix


Question link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-matrix-1587115620/1

---------------------------

Logic:Iteration

---------------------------

Complexity: 


Method 1: Iteration

Time Complexity=O(n + m)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Iteration
*/

class Solution
{   
    public:
    vector<int> boundaryTraversal(vector<vector<int> > mat, int n, int m) 
    {
        // code here
        int rL=0;
        int rH=n-1;
        int cL=0;
        int cH=m-1;
        vector<int>ans;
        for(int i=cL;i<=cH;i++)
        ans.push_back(mat[rL][i]);
        rL++;
        for(int i=rL;i<=rH;i++)
        ans.push_back(mat[i][cH]);
        cH--;
        if(rL<=rH)
        {
        for(int i=cH;i>=cL;i--)
        ans.push_back(mat[rH][i]);
        rH--;
        }
        if(cL<=cH)
        {
        for(int i=rH;i>=rL;i--)
        ans.push_back(mat[i][cL]);
        cL++;
        }
        return ans;
    }
};