/*Problem LeetCode (Easy)

1897. Redistribute Characters to Make All Strings Equal


Question link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/?envType=daily-question&envId=2023-12-30

Solution link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/submissions/1131916209/?envType=daily-question&envId=2023-12-30


Logic : frequency vector

--------------------------
Complexity: 

Method 1: frequency vector

Time Complexity=O(n*d) n=number of string , d= size of string

Space Complexity=O(26) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : frequency vector
*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
            freq[words[i][j]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]%n!=0)
            return false;
        }
        return true;
    }
};