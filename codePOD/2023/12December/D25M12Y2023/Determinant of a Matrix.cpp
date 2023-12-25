/*Problem GFG (Medium)

Determinant of a Matrix


Question link: https://www.geeksforgeeks.org/problems/determinant-of-a-matrix-1587115620/1

---------------------------

Logic: Recursion

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(n^3)

Space Complexity= O(n^2)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Recursion
*/

class Solution
{   
    public:
    //Function for finding determinant of matrix.
    vector<vector<int>>newMat(vector<vector<int> > mat,int col, int n)
    {
        vector<vector<int>>sMat;
        for(int j=1;j<n;j++)
        {
            vector<int>temp;
            for(int k=0;k<n;k++)
            {
                if(k!=col)
                temp.push_back(mat[j][k]);
            }
            sMat.push_back(temp);
        }
        return sMat;
    }
    int findDet(vector<vector<int> > mat, int n)
    {
        if(n==2)
        return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
        int ans=0;
        int sign=1;
        for(int i=0;i<n;i++)
        {
            ans+=sign*mat[0][i]*findDet(newMat(mat,i,n),n-1);
            sign*=-1;
        }
        return ans;
    }
    int determinantOfMatrix(vector<vector<int> > mat, int n)
    {
        // code here 
        if(n==1)
        return mat[0][0];
        return findDet(mat,n);
    }
};