/*Problem LeetCode (Medium)

201. Bitwise AND of Numbers Range


Question link: https://leetcode.com/problems/bitwise-and-of-numbers-range/description/?envType=daily-question&envId=2024-02-21

Solution link: https://leetcode.com/problems/bitwise-and-of-numbers-range/submissions/1181720164/?envType=daily-question&envId=2024-02-21


Logic : Bit Manipulation

--------------------------
Complexity: 

Method 1: Bit Manipulation

Time Complexity=O(1)

Space Complexity=O(1)  
--------------------------
Method 2: Bit Manipulation

Time Complexity=O(32)

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
    int rangeBitwiseAnd(int left, int right) {
        int count=0;
        while(left!=right)
        {
            left>>=1;
            right>>=1;
            count++;
        }
        return left<<count;
    }
};

/*----------------------------------------------------------------------------------------------
Method 2: Bit Manipulation */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right)
        return left;
        int i=31;
        int ans=0;
        while(i>=0)
        {
            int val1=(left>>i)&1;
            int val2=(right>>i)&1;
            if(val1==val2)
            ans+=(val1<<i);
            else
            break;
            i--;
        }
        return ans;
    }
};