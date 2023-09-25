/*Problem LeetCode (Medium)

389. Find the Difference


Question link: https://leetcode.com/problems/find-the-difference/description/?envType=daily-question&envId=2023-09-25

Logic: XOR

-------------------------

Complexity: 

Method 1:  Brute force (frequency vector)

Time Complexity=O(n+m)

Space Complexity=O(26) 

--------------------------

Method 2:  Optimized (XOR)

Time Complexity=O(n)

Space Complexity=O(1) 

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: XOR
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        // brute force
        // vector<int>freq(26,0);
        // int m=s.size();
        // int n=t.size();
        // for(int i=0;i<m;i++)
        // freq[s[i]-'a']++;
        // for(int i=0;i<n;i++)
        // {
        //     freq[t[i]-'a']--;
        //     if(freq[t[i]-'a']<0)
        //     return t[i];
        // }
        // return ' ';
        
        // optimized
        int xorV=0;
        int m=s.size();
        int n=t.size();
        int i;
        for(i=0;i<m;i++)
        {
            xorV^=(s[i]-'a');
            xorV^=(t[i]-'a');
        }
        xorV^=(t[i]-'a');
        return 'a'+ xorV;
    }
};