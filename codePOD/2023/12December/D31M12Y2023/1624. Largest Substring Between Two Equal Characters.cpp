/*Problem LeetCode (Easy)

1624. Largest Substring Between Two Equal Characters


Question link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/?envType=daily-question&envId=2023-12-31

Solution link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/submissions/1132877234/?envType=daily-question&envId=2023-12-31


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

Method : frequency vector
*/

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>mp(26,-1);
        int n=s.size();
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]-'a']==-1)
            mp[s[i]-'a']=i;
        }
        for(int i=n-1;i>=0;i--)
        maxi=max(maxi,i-mp[s[i]-'a']-1);
        return maxi;
    }
};