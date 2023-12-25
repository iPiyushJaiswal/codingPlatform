/*Problem LeetCode (Medium)

91. Decode Ways


Question link: https://leetcode.com/problems/decode-ways/?envType=daily-question&envId=2023-12-25

Solution link: https://leetcode.com/problems/decode-ways/submissions/1127965827/?envType=daily-question&envId=2023-12-25


Logic : DP

--------------------------
Complexity: 

Method 1: Recursion

Time Complexity=O(2^n)

Space Complexity=O(n)
--------------------------
Method 2: Memoization

Time Complexity=O(n)

Space Complexity=O(n) dp vector + O(n) recursive stack
--------------------------
Method 3: Tabulation

Time Complexity=O(n)

Space Complexity=O(n) dp vector
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution {
public:
    int rec(int i,int n,string s)
    {
        if(i==n)
        return 1;
        int ans=0;
        string temp;
        for(int j=i;j<n;j++)
        {
            temp+=s[j];
            // cout<<temp<<" ";
            int val=stoi(temp);
            if(val>=1 && val<=26)
            ans+=rec(j+1,n,s);
            else 
            break;
        }
        return ans;
    }
    int rec1(int i,int n,string s,vector<int>&dp)
    {
        if(i==n)
        return 1;
        if(dp[i]!=-1)
        return dp[i];
        int ans=0;
        string temp;
        for(int j=i;j<n;j++)
        {
            temp+=s[j];
            // cout<<temp<<" ";
            int val=stoi(temp);
            if(val>=1 && val<=26)
            ans+=rec1(j+1,n,s,dp);
            else 
            break;
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n=s.size();
        // recursion t.c=O(2^n) S.c=O(n)
        // return rec(0,n,s);

        // memoization t.c=O(n) S.c=O(n)+O(n)
        // vector<int>dp(n+1,-1);
        // return rec1(0,n,s,dp);

        // tabulation t.c=O(n) S.c=O(n)
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            int ans=0;
            string temp;
            for(int j=i;j<n;j++)
            {
                temp+=s[j];
                int val=stoi(temp);
                if(val>=1 && val<=26)
                ans+=dp[j+1];
                else 
                break;
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};