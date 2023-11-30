/*Problem LeetCode (Hard)

1611. Minimum One Bit Operations to Make Integers Zero


Question link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/

Solution link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/solutions/4347233/c-tricky-question-but-easy/


Logic: 1 approaches (Set theroy + Bit Manipulation)(A-B+C)

--------------------------

Complexity: 

Method 1: (Set theroy + Bit Manipulation)

Time Complexity=O(32)

Space Complexity=O(1) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: (Set theroy + Bit Manipulation)
*/

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int i=31;
        int count=0;
        bool flag=false;
        while(i>=0)
        {
            if((n>>i)&1)
            {
                if(flag==false)
                count+=(1<<(i+1))-1;
                else
                count-=(1<<(i+1))-1;
                flag=!flag;
            }
            i--;
        }
        return count;
    }
};