/*Problem GFG (Easy)

Sum of upper and lower triangles


Question link: https://www.geeksforgeeks.org/problems/sum-of-upper-and-lower-triangles-1587115621/1

---------------------------

Logic: Concept. Matrix Traversal

---------------------------

Complexity: 

Method  : Matrix Traversal

Time Complexity= O(n*n)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Matrix Traversal
*/

class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        vector<int>ans(2,0);
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                {
                    ans[0]+=matrix[i][j];
                    ans[1]+=matrix[i][j];
                }
                else
                {
                    ans[0]+=matrix[i][j];
                    ans[1]+=matrix[j][i];
                }
            }
        }
        return ans;
    }
};