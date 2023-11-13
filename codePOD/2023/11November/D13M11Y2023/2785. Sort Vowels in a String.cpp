/*Problem LeetCode (Medium)

2785. Sort Vowels in a String


Question link: https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2023-11-13


Logic: Map

--------------------------

Complexity: 

Method 1: Map

Time Complexity=O(2n)

Space Complexity=O(10log10)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Map
*/

class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        return true;
        return false;
    } 
    string sortVowels(string s) {
        map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i]))
            mp[s[i]]++;
        }
        int count=0;
        char ch;
        for(int i=0;i<n;i++)
        {
            if(isVowel(s[i]))
            {
                if(count==0)
                {
                    auto it= mp.begin();
                    ch=it->first;
                    count=it->second;
                    mp.erase(it);
                }
                s[i]=ch;
                count--;
            }
        }
        return s;
    }
};