/*Problem GFG (Medium)

Game of XOR


Question link: https://www.geeksforgeeks.org/problems/game-of-xor1541/1

---------------------------

Logic: Maths + XOR

---------------------------

Complexity: 

Method 1 : Maths + XOR

Time Complexity= O(n)

Space Complexity= O(1)

----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Maths + XOR
*/

class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        // code here
        int ans=0;
        for(int i=0;i<N;i++)
        {
            int val=(i+1)*(N-i);
            if(val%2!=0)
            ans^=A[i];
        }
        return ans;
    }
};