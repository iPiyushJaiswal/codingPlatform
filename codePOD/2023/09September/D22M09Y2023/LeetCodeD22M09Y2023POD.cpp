/*Problem LeetCode (Easy)

392. Is Subsequence


Question link: https://leetcode.com/problems/is-subsequence/description/?envType=daily-question&envId=2023-09-22


Logic: 2 Pointer iteration

-------------------------

Complexity: 

Method 1:  2 Pointer iteration

Time Complexity=O(min(m,n))

Space Complexity=O(1) 

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 2 Pointer iteration
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m=s.size();
        int n=t.size();
        int i=0;
        for(int j=0;j<n && i<m;j++)
        {
            if(s[i]==t[j])
            i++;
        }
        return (i==m);
    }
};