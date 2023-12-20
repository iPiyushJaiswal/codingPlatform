/*Problem GFG (Medium)

Modified Game of Nim


Question link: https://www.geeksforgeeks.org/problems/variation-in-nim-game4317/1

---------------------------

Logic: Array Xor

---------------------------

Complexity: 

Method 1 : Array Xor 

Time Complexity= O(n)

Space Complexity= O(1)

----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array Xor
*/

class Solution{
public:
    int findWinner(int n, int A[]){
        // code here
        int xorV=0;
        for(int i=0;i<n;i++)
        xorV^=A[i];
        if(xorV==0 || n%2==0)
        return 1;
        return 2;
    }
};