/*Problem LeetCode (Medium)

451. Sort Characters By Frequency


Question link: https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07

Solution link: https://leetcode.com/problems/sort-characters-by-frequency/submissions/1168377886/?envType=daily-question&envId=2024-02-07


Logic : Hashing

--------------------------
Complexity: 

Method 1: Hashing

Time Complexity=O(nlogn)

Space Complexity=O(n) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Hashing
*/

class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        vector<int>freq(62,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]>='a' && s[i]<='z')
            freq[s[i]-'a']++;
            else if(s[i]>='A' && s[i]<='Z')
            freq[26+s[i]-'A']++;
            else if(s[i]>='0' && s[i]<='9')
            freq[52+s[i]-'0']++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<62;i++)
        {
            if(i<26 && freq[i]>0)
            pq.push({freq[i],i + 'a'});
            else if(i>=26 && i<52 && freq[i]>0)
             pq.push({freq[i],i-26+'A'});
            else if(i>=52 && freq[i]>0)
             pq.push({freq[i],i-52+'0'});
        }
        string ans;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int i=0;
            while(i<it.first)
            {
                ans+=it.second;
                i++;
            }            
        }
        return ans;
    }
};