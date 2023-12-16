/*Problem LeetCode (Easy)

242. Valid Anagram


Question link: https://leetcode.com/problems/valid-anagram/?envType=daily-question&envId=2023-12-16

Solution link: https://leetcode.com/problems/valid-anagram/submissions/1120827554/?envType=daily-question&envId=2023-12-16


Logic : frequency vector

--------------------------

Complexity: 

Method 1: frequency vector

Time Complexity=O(n)

Space Complexity=O(26)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: frequency vector
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>mp(26,0);
        int n=s.size();
        int m=t.size();
        for(int i=0;i<n;i++)
        mp[s[i]-'a']++;
        for(int j=0;j<m;j++)
        mp[t[j]-'a']--;
        for(int i=0;i<26;i++)
        {
            if(mp[i]!=0)
            return false;
        }
        return true;
    }
};