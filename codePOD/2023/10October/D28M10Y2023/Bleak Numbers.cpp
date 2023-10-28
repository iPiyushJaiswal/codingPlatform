/*Problem GFG (Medium)

Bleak Numbers


Question link: https://practice.geeksforgeeks.org/problems/bleak-numbers1552/1

---------------------------

Logic: Maths

---------------------------

Complexity: 

Method 1 : Maths

Time Complexity= O(32*logn).

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Maths
*/

class Solution
{
public:
    int countBit(int i)
    {
        int count=0;
        while(i>0)
        {
            if(i%2!=0)
            count++;
            i/=2;
        }
        return count;
    }
	int is_bleak(int n)
	{
	    // Code here.
	    int j=max(1,n-32);
	    for(int i=j;i<n;i++)
	    {
	        if((i+countBit(i))==n)
	        return 0;
	    }
	    return 1;
	}
};