/*Problem LeetCode (Medium)

1759. Count Number of Homogenous Substrings


Question link: https://leetcode.com/problems/count-number-of-homogenous-substrings/description/?envType=daily-question&envId=2023-11-09


Logic: 2 Pointers

--------------------------

Complexity: 

Method 1: 2 Pointers

Time Complexity=O(2n)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 2 Pointers
*/

class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        int mod=1e9 +7;
        while(j<n)
        {
            while(s[i]==s[j])
            {
                j++;
            }
            if(j==n || s[i]!=s[j])
            {
                int x=j-i;
                ans=(ans%mod +((1ll*x*(x+1))/2)%mod)%mod;
                i=j;
            }
        }
        return ans%mod;
    }
};