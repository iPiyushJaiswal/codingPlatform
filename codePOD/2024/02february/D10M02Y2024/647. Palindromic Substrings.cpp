/*Problem LeetCode (Medium)

647. Palindromic Substrings


Question link: https://leetcode.com/problems/palindromic-substrings/?envType=daily-question&envId=2024-02-10

Solution link: https://leetcode.com/problems/palindromic-substrings/submissions/1171384956/?envType=daily-question&envId=2024-02-10


Logic : LIS

--------------------------
Complexity: 

Method 1: Iterative

Time Complexity=O(n^3)

Space Complexity=O(1) 
--------------------------
Method 2: Memoization

Time Complexity=O(n*n)

Space Complexity=O(n*n) dp vector
--------------------------
Method 3: Tabulation

Time Complexity=O(n*n)

Space Complexity=O(n*n) dp vectorvector
--------------------------
Method 4: Space Optimization

Time Complexity=O(n*n)

Space Complexity=O(2n) dp vector
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
public:
    int isPali(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            return 0;
            i++;
            j--;
        }
        return 1;
    }
    int rec(string s)
    {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            count+=isPali(s,i,j);
        }
        return count;
    }
    int isPaliDP(string s,int i,int j,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1)
        return dp[i][j];
        while(i<j)
        {
            if(s[i]!=s[j])
            return dp[i][j]=0;
            i++;
            j--;
        }
        return dp[i][j]=1;
    }
    int memo(string s)
    {
        int n=s.size();
        int count=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            count+=isPaliDP(s,i,j,dp);
        }
        return count;
    }
    int countSubstrings(string s) {
        int n=s.size();
        // recurion
        // return rec(s);

        // memoization
        // return memo(s);

        // tabulation
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // int count=0;
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         if(i==j)
        //         dp[i][j]=1;
        //         else if(i+1==j)
        //         dp[i][j]=(s[i]==s[j])?1:0;
        //         else
        //         dp[i][j]=(s[i]==s[j])?dp[i+1][j-1]:0;
        //         count+=dp[i][j];
        //     }
        // }
        // return count;

        // space otimization
        vector<int>dp(n+1,0);
        vector<int>temp(n+1,0);
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                temp[j]=1;
                else if(i+1==j)
                temp[j]=(s[i]==s[j])?1:0;
                else
                temp[j]=(s[i]==s[j])?dp[j-1]:0;
                count+=temp[j];
            }
            dp=temp;
        }
        return count;
    }
};