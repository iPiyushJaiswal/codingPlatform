/*Problem LeetCode (Easy)

1758. Minimum Changes To Make Alternating Binary String


Question link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/

Solution link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/submissions/1127204648/


Logic : Array + Maths

--------------------------
Complexity: 

Method 1: Array + Maths

Time Complexity=O(n)

Space Complexity=O(1)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array + Maths
*/

class Solution {
public:
    int minOperations(string s) {
        int one=0,zero=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(i%2==0 && s[i]=='0')
            zero++;
            else if(i%2==1 && s[i]=='1')
            one++;
        }
        return min(zero+one,abs(n-(zero+one)));
    }
};