/*Problem GFG (Easy)

Move all zeroes to end of array


Question link: https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

---------------------------

Logic: Array 2 Pointers

---------------------------

Complexity: 

Method 1 : Array 2 Pointers

Time Complexity= O(n).

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Array 2 Pointers
*/

class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int i=0;
	    int j=0;
	    while(j<n)
	    {
	        if(arr[j]!=0)
	        {
	            swap(arr[i],arr[j]);
	            i++;
	        }
	        j++;
	    }
	}
};