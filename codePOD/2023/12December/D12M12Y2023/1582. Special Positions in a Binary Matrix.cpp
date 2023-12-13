/*Problem LeetCode (Easy)

1582. Special Positions in a Binary Matrix


Question link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2023-12-13

Solution link: https://leetcode.com/problems/special-positions-in-a-binary-matrix/submissions/1118526039/?envType=daily-question&envId=2023-12-13


Logic : Matrix

--------------------------

Complexity: 

Method 1: Matrix

Time Complexity=O(n*m)

Space Complexity=O(n+m)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Matrix
*/

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>r(n,0);
        vector<int>c(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                r[i]+=mat[i][j];
                c[j]+=mat[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(r[i]==1)
            {
                for(int j=0;j<m;j++)
                {
                    if(mat[i][j]==1 && c[j]==1)
                    ans++;
                }
            }
        }
        return ans;
    }
};