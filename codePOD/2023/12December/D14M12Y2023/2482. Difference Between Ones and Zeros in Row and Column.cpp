/*Problem LeetCode (Medium)

2482. Difference Between Ones and Zeros in Row and Column


Question link: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/?envType=daily-question&envId=2023-12-14

Solution link: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/submissions/1119313368/?envType=daily-question&envId=2023-12-14


Logic : Matrix

--------------------------

Complexity: 

Method 1: Better

Time Complexity=O(n*m)

Space Complexity=O(n*m)
--------------------------
Method 2: Optimized

Time Complexity=O(n*m)

Space Complexity=O(n+m)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Better
*/

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        int row=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                row+=grid[i][j];
                else
                ans[i][0]+=grid[i][j];
                ans[0][j]+=grid[i][j];
            }
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==0)
                ans[i][j]=2*row + 2*ans[0][j] -m -n;
                else
                ans[i][j]=2*ans[i][0] + 2*ans[0][j] -m -n;
            }
        }
        return ans;
    }
};

/*--------------------------------------------------------
Method 2: Optimized
*/

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        }
        for(int i=m-1;i>=0;i--)
            for(int j=n-1;j>=0;j--)
                grid[i][j]=2*row[i] + 2*col[j] -m -n;

        return grid;
    }
};