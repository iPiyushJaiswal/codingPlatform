/*Problem LeetCode (Easy)

1160. Find Words That Can Be Formed by Characters


Question link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?envType=daily-question&envId=2023-12-02

Solution link: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/submissions/1110586303/?envType=daily-question&envId=2023-12-02


Logic: String Hashing

--------------------------

Complexity: 

Method 1: String Hashing

Time Complexity=O(n*m) because of each vector of string can be of maximum size (m) which we traverse

Space Complexity=O(m) Unordered_map
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: String Hashing
*/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp;
        int n=words.size();
        int m=chars.size();
        for(int i=0;i<m;i++)
        {
            mp[chars[i]]++;
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(words[i].size()>m)
            continue;
            int j=0;
            int flag=0;
            for(;j<words[i].size();j++)
            {
                if(mp[words[i][j]]>0)
                {
                    mp[words[i][j]]--;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
            for(int k=0;k<j;k++)
            mp[words[i][k]]++;
            if(flag==0)
            ans+=words[i].size();
        }
        return ans;
    }
};