/*Problem LeetCode (Medium)

316. Remove Duplicate Letters


Question link: https://leetcode.com/problems/remove-duplicate-letters/description/?envType=daily-question&envId=2023-09-26

Logic: Stack + freq

-------------------------

Complexity: 

Method 1:  Stack + freq

Time Complexity=O(2n)

Space Complexity=O(26) 

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Stack + freq
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int>ind(26,0);
        vector<bool>vis(26,false);
        for(int i=0;i<n;i++)
        ind[s[i]-'a']=i;
        stack<char>st;
        string ans;
        for(int i=0;i<n;i++)
        {
            if(vis[s[i]-'a']==true)
            continue;
            while(!st.empty() && st.top()>s[i] && ind[st.top()-'a']>i)
            {
                vis[st.top()-'a']=false;
                st.pop();
            }
                st.push(s[i]);
                vis[s[i]-'a']=true;
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};