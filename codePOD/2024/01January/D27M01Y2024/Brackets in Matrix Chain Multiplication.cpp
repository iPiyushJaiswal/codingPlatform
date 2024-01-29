/*Problem GFG (Hard)

Brackets in Matrix Chain Multiplication


Question link: https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

---------------------------

Logic: DP 

---------------------------

Complexity: 

Method 1 : DP 

Time Complexity= O(n^3)

Space Complexity= O(n^2) dp vector 
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP 
*/

class Solution{
public:
    pair<string,int> rec(int low,int p[],int high,vector<vector<pair<string,int>>>&dp)
    {
        if(low==high)
        {
            string s="";
            s=(low-1) +'A';
            return {s,0};
        }
        if(dp[low][high].second!=-1)
        return dp[low][high];
        int mini=INT_MAX;
        string str;
        for(int k=low;k<high;k++)
        {
            auto a=rec(low,p,k,dp);
            auto b=rec(k+1,p,high,dp);
            int val=a.second + b.second + p[low-1]*p[k]*p[high];
            string s="("+ a.first + b.first + ")";
            if(val<mini)
            {
                mini=val;
                str=s;
            }
        }
        return dp[low][high]={str,mini};
    }
    string matrixChainOrder(int p[], int n){
        // code here
        vector<vector<pair<string,int>>>dp(n+1,
        vector<pair<string,int>>(n+1,{"",-1}));
        auto str=rec(1,p,n-1,dp);
        return str.first;
    }
};