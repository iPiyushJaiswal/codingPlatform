/*Problem LeetCode (Medium)

1647. Minimum Deletions to Make Character Frequencies Unique


Question link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/

Logic: MAP + Common sense.

Complexity: 

Method 1: frequency vector + set.

Time Complexity=O(n) 

Space Complexity=O(26)

--------------------------

Method 2: frequency vector

Time Complexity=O(n), for sorting it's not (nlogn). only 26 character so (26log26)==> O(1).

Space Complexity=O(26)

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: frequency vector + set.
*/
class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        freq[s[i]-'a']++;
        set<int>st;
        int count=0;
        for(int i=0;i<26;i++)
        {
            while(!st.empty() && freq[i]>0 && st.find(freq[i])!=st.end())
            {
                count++;
                freq[i]--;
            }
            if(freq[i]>0)
            st.insert(freq[i]);
        }
        return count;
    }
};

/*
--------------------------------------------------
Method 2: frequency vector 
*/

class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        freq[s[i]-'a']++;
        sort(freq.rbegin(),freq.rend());
        int count=0;
        int mini=freq[0];
        for(int i=0;i<26;i++)
        {
            if(freq[i]>mini)
            {
                if(mini>0)
                count+=freq[i]-mini;
                else
                count+=freq[i];
            }
            mini=min(mini-1,freq[i]-1);
        }
        return count;
    }
};
