/*Problem GFG (Medium)

Count all Possible Path


Question link:	https://www.geeksforgeeks.org/problems/castle-run3644/1

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
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    int n=paths.size();
	    for(int i=0;i<n;i++)
	    {
	        int temp=0;
	        for(int j=0;j<n;j++)
	        temp+=paths[i][j];
	        if(temp%2!=0)
	        return 0;
	    }
	    return 1;
	}

};