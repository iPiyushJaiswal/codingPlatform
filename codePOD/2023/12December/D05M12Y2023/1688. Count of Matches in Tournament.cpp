/*Problem LeetCode (Easy)

1688. Count of Matches in Tournament


Question link: https://leetcode.com/problems/count-of-matches-in-tournament/description/?envType=daily-question&envId=2023-12-05

Solution link: https://leetcode.com/problems/count-of-matches-in-tournament/submissions/1112618582/?envType=daily-question&envId=2023-12-05


Logic: Array

--------------------------

Complexity: 

Method 1: Array

Time Complexity=O(logn)

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
    int numberOfMatches(int n) {
        int ans=0;
        while(n>1)
        {
            ans+=n/2;
            if(n%2!=0)
            n++;
            n/=2;
        }
        return ans;
    }
};