/*Problem LeetCode (Easy)

118. Pascal's Triangle


Question link: https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2023-09-08

Logic: Array + Maths.   

Complexity: 

Method 1: Maths.

Time Complexity=O(n*n)

Space Complexity=O(1). 

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for(int i=0;i<numRows;i++)
        {
            ans[i].resize(i+1);
            ans[i][0]=ans[i][i]=1;
            for(int j=1;j<i;j++)
            {
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
            }
        }
        return ans;
    }
};