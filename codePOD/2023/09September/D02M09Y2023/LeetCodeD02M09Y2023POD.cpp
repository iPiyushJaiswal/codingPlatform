/*Problem LeetCode (Medium)

2707. Extra Characters in a String


Question link: https://leetcode.com/problems/extra-characters-in-a-string/description/?envType=daily-question&envId=2023-09-02

Logic: Fractional DP

Complexity: 

Method 1: Recurssion

Time Complexity=O(Exponential)

Space Complexity=O(n). 

--------------------------

Method 2: Memoization

Time Complexity=O(n*n)

Space Complexity=O(n). vector used as DP. + O(n) recursive stack.

--------------------------
Method 3: Tabulation

Time Complexity=O(n*n)

Space Complexity=O(n). vector used as DP.

 
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------
*/
class Solution {
public:
    int rec(string s,set<string>st,int i,int n)
    {
        if(i>=n)
        return 0;
        string temp;
        int mini=INT_MAX;
        for(int j=i;j<n;j++)
        {
            temp.push_back(s[j]);
            int val=0;
            if(st.find(temp)==st.end())
            val=temp.size();
            val+=rec(s,st,j+1,n);
            mini=min(mini,val);
        }
        return mini;
    }
    int rec1(string s,set<string>st,int i,int n,vector<int>&dp)
    {
        if(i>=n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        string temp;
        int mini=INT_MAX;
        for(int j=i;j<n;j++)
        {
            temp.push_back(s[j]);
            int val=0;
            if(st.find(temp)==st.end())
            val=temp.size();
            val+=rec1(s,st,j+1,n,dp);
            mini=min(mini,val);
        }
        return dp[i]=mini;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string>st;
        for(auto it:dictionary)
        st.insert(it);
        int n =s.size();
        // return rec(s,st,0,n);
        // vector<int>dp(n+1,-1);
        // return rec1(s,st,0,n,dp);

        // tabulation
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            string temp;
            int mini=INT_MAX;
            for(int j=i;j<n;j++)
            {
                temp.push_back(s[j]);
                int val=0;
                if(st.find(temp)==st.end())
                val=temp.size();
                val+=dp[j+1];
                mini=min(mini,val);
            }
            dp[i]=mini;
        }
        return dp[0];
    }
};