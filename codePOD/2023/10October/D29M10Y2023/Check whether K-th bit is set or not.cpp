/*Problem GFG (Easy)

Check whether K-th bit is set or not


Question link: https://practice.geeksforgeeks.org/problems/check-whether-k-th-bit-is-set-or-not-1587115620/1

---------------------------

Logic: Bit Manipulation

---------------------------

Complexity: 

Method 1 : Bit Manipulation

Time Complexity= O(1).

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Bit Manipulation
*/

class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Your code here
        return (n>>k)&1;
    }
};