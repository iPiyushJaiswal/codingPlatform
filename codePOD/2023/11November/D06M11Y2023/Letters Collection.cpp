/*Problem GFG (Easy)

Letters Collection


Question link: https://www.geeksforgeeks.org/problems/c-letters-collection4552/1

---------------------------

Logic: Concept. Logic Array Traversal

---------------------------

Complexity: 

Method  : Concept. Logic Array Traversal

Time Complexity= O(q*16)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Concept. Logic Array Traversal
*/

class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
        vector<int>ans;
        for(int i=0;i<q;i++)
        {
            int rS=queries[i][1]-queries[i][0];
            int rE=queries[i][1]+queries[i][0];
            int cS=queries[i][2]-queries[i][0];
            int cE=queries[i][2]+queries[i][0];
            int count=0;
            for(int j=rS;j<=rE;j++)
            {
                if(cS>=0 && j>=0 && j<n)
                count+=mat[j][cS];
                if(cE<m && j>=0 && j<n)
                count+=mat[j][cE];
            }
            for(int j=cS+1;j<=cE-1;j++)
            {
                if(rS>=0 && j>=0 && j<m)
                count+=mat[rS][j];
                if(rE<n && j>=0 && j<m)
                count+=mat[rE][j];
            }
            ans.push_back(count);
        }
        return ans;
    }
};