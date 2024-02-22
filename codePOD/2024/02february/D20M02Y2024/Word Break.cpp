/*Problem GFG (Medium)

Word Break


Question link:	https://www.geeksforgeeks.org/problems/word-break1352/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^n)

Space Complexity=O(B.size) unordered_set + O(n) recursive stack
----------------------------------
Method 2 : Memoization

Time Complexity= O(n^3)

Space Complexity=O(B.size) unordered_set
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution
{
public:
    bool rec(string &A,int i,int n,unordered_set<string>&st)
    {
        if(i==n)
        return true;
        bool x=false;
        string temp;
        for(int j=i;j<n;j++)
        {
            temp+=A[j];
            if(st.find(temp)!=st.end())
            x|=rec(A,j+1,n,st);
        }
        return x;
    }
    bool rec1(string &A,int i,int n,unordered_set<string>&st,
    vector<int>&dp)
    {
        if(i==n)
        return true;
        if(dp[i]!=-1)
        return dp[i];
        bool x=false;
        string temp;
        for(int j=i;j<n;j++)
        {
            temp+=A[j];
            if(st.find(temp)!=st.end())
            x|=rec1(A,j+1,n,st,dp);
        }
        return dp[i]=x;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n=A.size();
        unordered_set<string>st;
        for(int i=0;i<B.size();i++)
        st.insert(B[i]);
        
        // recursion
        // return rec(A,0,n,st);
        
        // memoization
        vector<int>dp(n+1,-1);
        return rec1(A,0,n,st,dp);
    }
};