/*Problem LeetCode (Easy)

387. First Unique Character in a String


Question link: https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05

Solution link: https://leetcode.com/problems/first-unique-character-in-a-string/submissions/1166349115/?envType=daily-question&envId=2024-02-05


Logic : Hashing

--------------------------
Complexity: 

Method 1: Hashing

Time Complexity=O(n)

Space Complexity=O(26) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Hashing
*/

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26,-1);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(freq[s[i]-'a']!=-1)
            freq[s[i]-'a']=-2;
            else
            freq[s[i]-'a']=i;
        }
        int mini=n;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>=0)
            mini=min(mini,freq[i]);
        }
        if(mini==n)
        return -1;
        return mini;
        
    }
};