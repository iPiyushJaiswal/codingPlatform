/*Problem LeetCode (Easy)

867. Transpose Matrix


Question link: https://leetcode.com/problems/transpose-matrix/description/?envType=daily-question&envId=2023-12-10

Solution link: https://leetcode.com/problems/transpose-matrix/submissions/1116260301/?envType=daily-question&envId=2023-12-10


Logic : Matrix

--------------------------

Complexity: 

Method 1: Matrix

Time Complexity=O(n*m)

Space Complexity=O(n*m)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Matrix
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>ans(m);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                ans[i].push_back(matrix[j][i]);
        return ans;
    }
};