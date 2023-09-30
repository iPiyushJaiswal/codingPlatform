/*Problem GFG (Medium)

Boolean Matrix


Question link: https://practice.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1

---------------------------

Logic: Maths + Array

---------------------------

Complexity: 


Method 1: Maths + Array

Time Complexity=O(n*m*2)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Maths + Array 
*/

class Solution
{   
    public:
    void booleanMatrix(vector<vector<int> > &mat)
    {
        // code here 
        int n=mat.size();
        int m=mat[0].size();
        int row=0;
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]==1)
            row=1;
            for(int j=1;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    mat[i][0]=1;
                    mat[0][j]=1;
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>0;j--)
            {
                if(mat[i][0]==1 || mat[0][j]==1)
                mat[i][j]=1;
            }
            if(row==1)
            mat[i][0]=1;
        }
    }
};