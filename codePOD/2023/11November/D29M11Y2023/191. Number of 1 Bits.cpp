/*Problem LeetCode (Easy)

191. Number of 1 Bits


Question link: https://leetcode.com/problems/number-of-1-bits/?envType=daily-question&envId=2023-11-29

Solution link: https://leetcode.com/problems/number-of-1-bits/submissions/1108933044/?envType=daily-question&envId=2023-11-29


Logic: 3 approaches

--------------------------

Complexity: 

Method 1: 32 bits

Time Complexity=O(32)

Space Complexity=O(1) 

--------------------------
Method 2: Set bits

Time Complexity=O(logn) 

Space Complexity=O(1) 

--------------------------
Method 3: Complement logic

Time Complexity=O(k) k= number of set bits

Space Complexity=O(1) 

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 32 bits
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        int i=0;
        while(i<32)
        {
            if((n>>i)&1)
            count++;
            i++;
        }
        return count;
    }
};

/*-------------------------------------------
Method 2: Set bits
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0)
        {
            if(n&1)
            count++;
            n=n>>1;
        }
        return count;
    }
};


/*-------------------------------------------
Method 3: Complement logic
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        while(n>0)
        {
            count++;
            n&=(n-1);
        }
        return count;
    }
};