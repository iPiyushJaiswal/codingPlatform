/*Problem GFG (Easy)

Rightmost different bit


Question link: https://www.geeksforgeeks.org/problems/rightmost-different-bit-1587115621/1

---------------------------

Logic: Bit

---------------------------

Complexity: 

Method 1 : Bit 

Time Complexity= O(32)

Space Complexity= O(1)

----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Bit
*/

class Solution
{
    public:
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code 
        int i=0;
        while(i<32)
        {
            if(((m>>i)&1)!=((n>>i)&1))
            return i+1;
            i++;
        }
        return -1;
    }
};