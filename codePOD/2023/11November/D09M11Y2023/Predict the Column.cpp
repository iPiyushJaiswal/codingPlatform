/*Problem GFG (Easy)

Predict the Column


Question link: https://www.geeksforgeeks.org/problems/predict-the-column/1

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

class Solution{
    public:
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        // Your code here
        int maxColumn=-1;
        int maxCount=0;
        for(int i=0;i<N;i++)
        {
            int count=0;
            for(int j=0;j<N;j++)
            {
                if(arr[j][i]==0)
                count++;
            }
            if(maxCount<count)
            {
                maxCount=count;
                maxColumn=i;
            }
        }
        return maxColumn;
    }
};