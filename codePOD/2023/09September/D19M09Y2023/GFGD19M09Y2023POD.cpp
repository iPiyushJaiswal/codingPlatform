/*Problem GFG (Easy)

Find first set bit


Question link: https://practice.geeksforgeeks.org/problems/find-first-set-bit-1587115620/1

---------------------------

Logic: Bit Manipulation

---------------------------

Complexity: 

Method 1: Bit Manipulation

Time Complexity=O(32)

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Bit Manipulation
*/

class Solution
{
    public:
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        int i=0;
        while(i<32)
        {
            if(((n>>i)&1))
            return i+1;
            i++;
        }
        return 0;
    }
};