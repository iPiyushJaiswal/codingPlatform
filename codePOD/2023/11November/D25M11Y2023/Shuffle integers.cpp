/*Problem GFG (Medium)

Shuffle integers


Question link: https://www.geeksforgeeks.org/problems/shuffle-integers2401/1

---------------------------

Logic: put 2 elements in same index.

---------------------------

Complexity: 

Method 1 : put 2 elements in same index.

Time Complexity= O(2n)

Space Complexity= O(1)

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: put 2 elements in same index.
*/

class Solution{
public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    n--;
	    int i=n/2;
	    int j=n;
	    while(i>=0)
	    {
	        arr[i]=arr[i]*1001 +arr[j];
	        i--;
	        j--;
	    }
	    i=n/2;
	    j=n;
	    while(j>=0)
	    {
	        arr[j]=arr[i]%1001;
	        arr[j-1]=arr[i]/1001;
	        j-=2;
	        i--;
	    }
	}
};