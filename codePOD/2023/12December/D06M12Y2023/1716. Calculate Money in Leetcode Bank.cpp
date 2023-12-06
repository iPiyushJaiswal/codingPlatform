/*Problem LeetCode (Easy)

1716. Calculate Money in Leetcode Bank


Question link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2023-12-06

Solution link: https://leetcode.com/problems/calculate-money-in-leetcode-bank/submissions/1113356040/?envType=daily-question&envId=2023-12-06


Logic : Array + Maths

--------------------------

Complexity: 

Method 1: Array

Time Complexity=O(n/7+n%7)

Space Complexity=O(1)
--------------------------
Method 1: Maths

Time Complexity=O(1)

Space Complexity=O(1)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array
*/

class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int val=(7*4);
        int low=1;
        while(n>0)
        {
            while(n/7>0)
            {
                ans+=val;
                val+=7;
                n-=7;
                low++;
            }
            if(n!=0)
            {
                ans+=low;
                low++;
                n--;
            }
        }
        return ans;
    }
};

/*-------------------------------------------------------------------------
Method 2: Maths
*/

class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int x=n/7;
        int val1=(x*(56+(x-1)*7))/2;
        int rem=n%7;
        int val2=(rem*(2*(x+1) + (rem-1)))/2;
        return val1+val2;
    }
};