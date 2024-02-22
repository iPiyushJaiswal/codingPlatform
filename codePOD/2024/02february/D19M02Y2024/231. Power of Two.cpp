/*Problem LeetCode (Easy)

231. Power of Two


Question link: https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2024-02-19

Solution link: https://leetcode.com/problems/power-of-two/submissions/1179789901/?envType=daily-question&envId=2024-02-19


Logic : Bit Manipulation

--------------------------
Complexity: 

Method 1: Bit Manipulation

Time Complexity=O(1)

Space Complexity=O(1)  
--------------------------
Method 2: Bit Manipulation

Time Complexity=O(logn)

Space Complexity=O(1)  
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Bit Manipulation
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        return false;
        // return (n&(~(n-1)))==n;
        return (n&((n-1)))==0;
    }
};


/* ----------------------------------------------------------------------------------------------
Method 2: Bit Manipulation */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
        return false;
        while(n!=0)
        {
            if(n!=1 && n%2!=0)
            return false;
            n/=2;
        }
        return true;
    }
};