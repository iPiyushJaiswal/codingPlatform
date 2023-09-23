/*Problem LeetCode (Medium)

1048. Longest String Chain


Question link: https://leetcode.com/problems/longest-string-chain/description/?envType=daily-question&envId=2023-09-23


Logic: DP

-------------------------

Complexity: 

Method 1:  DP

Time Complexity=O(n*n*l) l=length of longest string.

Space Complexity=O(n) 

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
public:
bool comp(string x,string y)
{
    int x1=x.size();
    int y1=y.size();
    if(x1!=y1+1)
    return false;
    int i=0;
    int j=0;
    while(i<x1)
    {
        if(x[i]==y[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if(i<x1 || j<y1)
    return false;
    return true;
}
static bool comparator(string &a,string &b)
{
    return (a.size()<b.size());
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        if(n==1)
        return n;
        sort(words.begin(),words.end(),comparator);
        vector<int>dp(n,1);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(comp(words[i],words[j]) && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};