/*Problem GFG (Easy)

Print Matrix in snake Pattern


Question link: https://www.geeksforgeeks.org/problems/print-matrix-in-snake-pattern-1587115621/1

---------------------------

Logic: Concept. Matrix Traversal

---------------------------

Complexity: 

Method  : Matrix Traversal

Time Complexity= O(n*m)

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
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        // code here
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(flag==false)
                ans.push_back(matrix[i][j]);
                else
                ans.push_back(matrix[i][m-j-1]);
            }
            flag=!flag;
        }
        return ans;
    }
};