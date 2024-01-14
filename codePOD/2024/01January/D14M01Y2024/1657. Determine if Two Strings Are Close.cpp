/*Problem LeetCode (Medium)

1657. Determine if Two Strings Are Close


Question link: https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14

Solution link: https://leetcode.com/problems/determine-if-two-strings-are-close/submissions/1145730654/?envType=daily-question&envId=2024-01-14


Logic : String

--------------------------
Complexity: 

Method 1: String

Time Complexity=O(n)

Space Complexity=O(n) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: String
*/

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<int,int>mp;
        int n=word1.size();
        int m=word2.size();
        if(n!=m)
        return false;
        vector<int>temp1(26,0);
        vector<int>temp2(26,0);
        for(int i=0;i<n;i++)
        temp1[word1[i]-'a']++;
        for(int i=0;i<26;i++)
        {
            if(temp1[i]!=0)
            mp[temp1[i]]++;
        }
        for(int i=0;i<m;i++)
        {
            if(temp1[word2[i]-'a']==0)
            return false;
            temp2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(temp2[i]!=0)
            {
                mp[temp2[i]]--;
                if(mp[temp2[i]]<0)
                return false;
            }
        }
        return true;
    }
};