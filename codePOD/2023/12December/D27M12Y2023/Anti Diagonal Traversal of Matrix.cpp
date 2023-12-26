/*Problem GFG (Medium)

Anti Diagonal Traversal of Matrix


Question link: https://www.geeksforgeeks.org/problems/print-diagonally1623/1

---------------------------

Logic: Matrix

---------------------------

Complexity: 

Method 1 : Matrix

Time Complexity= O(n*n)

Space Complexity= O(1)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Matrix
*/

class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> mat) 
    {
        // Code here
        int n=mat.size();

        vector<int>ans;
        for(int i=0;i<=2*(n-1);i++)
        {
            int k=min(i,n-1);
            int j=i-k;
            while(k>=0 && j<n)
            {
                ans.push_back(mat[j][k]);
                k--;
                j++;
            }
        }
        return ans;
    }
};