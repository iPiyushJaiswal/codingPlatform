/*Problem GFG (Easy)

Minimum Operations


Question link: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

---------------------------

Logic: Maths

---------------------------

Complexity: 

Method 1 : Maths

Time Complexity= O(logn) .

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
    int minOperation(int n)
    {
        //code here.
        int val=n;
        int count=0;
        while(val>0)
        {
            if(val%2==0)
            val/=2;
            else
            val--;
            count++;
        }
        return count;
    }
};