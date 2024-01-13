/*Problem LeetCode (Easy)

1347. Minimum Number of Steps to Make Two Strings Anagram


Question link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13

Solution link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/submissions/1144753405/?envType=daily-question&envId=2024-01-13


Logic : String

--------------------------
Complexity: 

Method 1: String

Time Complexity=O(n)

Space Complexity=O(26) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: String
*/

class Solution {
public:
    int minSteps(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m)
        return -1;
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        freq[s[i]-'a']++;
        for(int i=0;i<m;i++)
        freq[t[i]-'a']--;
        int ans=0;
        for(int i=0;i<26;i++)
        ans+=abs(freq[i]);
        return ans/2;
    }
};