/*Problem LeetCode (Hard)

2147. Number of Ways to Divide a Long Corridor


Question link: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/

Solution link: https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/submissions/1107955410/


Logic: 1 approaches

--------------------------

Complexity: 

Method 1: Greedy

Time Complexity=O(2*n)

Space Complexity=O(1) 

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Greedy
*/

class Solution {
public:
    int numberOfWays(string c) {
        int n=c.size();
        int s=0;
        int mod=1e9 +7;
        for(int i=0;i<n;i++)
        {
            if(c[i]=='S')
            s++;
        }
        if(s==0 || s%2!=0)
        return 0;
        long long count=1;
        int p=1;
        int seat=0;
        for(int i=0;i<n;i++)
        {
            if(c[i]=='P'){
            if(seat!=0 && seat%2==0 && seat!=s)
            p++;
            }
            else
            {
                count=(count%mod * p%mod)%mod;
                p=1;
                seat++;
            }
        }
        return (count%mod * p%mod)%mod;
    }
};