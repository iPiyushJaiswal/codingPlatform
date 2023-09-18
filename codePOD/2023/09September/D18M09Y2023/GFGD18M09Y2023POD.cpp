/*Problem GFG (Basic)

Power of 2


Question link: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1

---------------------------

Logic: Bit Manipulation

---------------------------

Complexity: 

Method 1: Bit Manipulation

Time Complexity=O(1)

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Bit Manipulation
*/

class Solution{
    public:
    bool isPowerofTwo(long long n){
        
        // Your code here    
    if(n<=0)
    return false;
    return ((n&(n-1))==0);
    }
};