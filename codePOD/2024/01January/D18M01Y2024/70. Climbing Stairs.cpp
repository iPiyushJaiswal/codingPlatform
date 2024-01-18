/*Problem LeetCode (Easy)

70. Climbing Stairs


Question link: https://leetcode.com/problems/climbing-stairs/?envType=daily-question&envId=2024-01-18

Solution link: https://leetcode.com/problems/climbing-stairs/submissions/1149663257/?envType=daily-question&envId=2024-01-18


Logic : DP

--------------------------
Complexity: 

Method 1: DP

Time Complexity=O(n)

Space Complexity=O(1) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
        return n;
        int prev1=1;
        int prev2=2;
        int curr=0;
        for(int i=3;i<=n;i++)
        {
            curr=prev2+prev1;
            prev1=prev2;
            prev2=curr;
        } 
        return curr;
    }
};