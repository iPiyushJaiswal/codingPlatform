/*Problem GFG (Medium)

Find duplicate rows in a binary matrix


Question link: https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1

---------------------------

Logic: Hashing

---------------------------

Complexity: 

Method 1 : Hashing

Time Complexity= O(n*m)

Space Complexity= O(n*m) 
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Hashing
*/

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        vector<int>ans;
        unordered_set<string>st;
        for(int i=0;i<M;i++)
        {
            string temp;
            for(int j=0;j<N;j++)
            temp.push_back(matrix[i][j]+'0');
            if(st.find(temp)!=st.end())
            ans.push_back(i);
            st.insert(temp);
        }
        return ans;
    } 
};