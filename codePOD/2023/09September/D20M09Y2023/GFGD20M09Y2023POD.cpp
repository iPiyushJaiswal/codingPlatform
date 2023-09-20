/*Problem GFG (Basic)

Rotate Bits


Question link: https://practice.geeksforgeeks.org/problems/rotate-bits4524/1

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

class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            d=d%16;
            int a=((n<<d)|(n>>(16-d)))&((1<<(16))-1);
            int b=((n>>d)|(n<<(16-d)))&((1<<(16))-1);
            return {a,b};
        }
};