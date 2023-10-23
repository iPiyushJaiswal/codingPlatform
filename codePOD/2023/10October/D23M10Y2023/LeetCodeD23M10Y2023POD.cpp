/*Problem LeetCode (Easy)

342. Power of Four


Question link: https://leetcode.com/problems/power-of-four/description/


Logic: Iterative + Recursive + Bit manipulation

-------------------------

Complexity: 

Method 1:  Iterative

Time Complexity=O(logn)

Space Complexity=O(1)

--------------------------
Method 2:  Recursive

Time Complexity=O(logn)

Space Complexity=O(logn) recursive stack.

--------------------------
Method 3:  Bit manipulation

Time Complexity=O(1)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Iterative + Recursive + Bit manipulation
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        // recursive
        // if(n==0)
        // return false;
        // if(n==1)
        // return true;
        // if(n%4!=0)
        // return false;
        // return isPowerOfFour(n/4);

        // iterative
        // if(n==0)
        // return false;
        // while(n%4==0)
        // {
        //     n/=4;
        // }
        // return (n==1);

        // bit manipulation method 1
        // return (n>0) && ((n&(~(n-1)))==n) && (((n-1)%3)==0);

        // bit manipulation method 2
        return (n>0) && ((n&(n-1))==0) && ((n%3)==1);
    }
};