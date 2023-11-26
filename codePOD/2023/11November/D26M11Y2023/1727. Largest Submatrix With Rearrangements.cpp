/*Problem LeetCode (Medium)

1727. Largest Submatrix With Rearrangements


Question link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/description/?envType=daily-question&envId=2023-11-26

Solution link: https://leetcode.com/problems/largest-submatrix-with-rearrangements/submissions/1106554677/?envType=daily-question&envId=2023-11-26


Logic: 2 approaches

--------------------------

Complexity: 

Method 1: notUpdate input matrix + dp vector + sorting

Time Complexity=O(n*logm + n*m )

Space Complexity=O(2m)

--------------------------
Method 2: Update input matrix + sorting

Time Complexity=O(n*logm + n*m )

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: notUpdate input matrix + dp vector + sorting
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<int>dp(m,0);
        for(int i=0;i<n;i++)
        {
            vector<int>temp=dp;
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                temp[j]=0;
                else
                temp[j]++;
            }
            dp=temp;
            sort(temp.begin(),temp.end());
            for(int j=0;j<m;j++)
            {
                maxi=max(maxi,temp[j]*(m-j));
            }
        }
        return maxi;
    }
};

/*-----------------------------------------------------------
Method 2: Update input matrix + sorting
*/

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                matrix[i][j]=0;
                else
                matrix[i][j]+=matrix[i-1][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            sort(matrix[i].begin(),matrix[i].end());
            for(int j=0;j<m;j++)
            {
                maxi=max(maxi,matrix[i][j]*(m-j));
            }
        }
        return maxi;
    }
};