/*Problem GFG (Hard)

Number of distinct subsequences


Question link: https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1

---------------------------

Logic:DP

---------------------------

Complexity: 


Method 1: DP

Time Complexity=O(n)

Space Complexity=O(n)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP
*/

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int mod=1e9+7;
	    int n=s.size();
	    vector<int>dp(n+2,0);
	    vector<int>pos(26,-1);
	    dp[0]=1;
	    for(int i=0;i<n;i++)
	    {
	        dp[i+1]=(dp[i]*2)%mod;
	        if(pos[s[i]-'a']!=-1)
	        dp[i+1]-=dp[pos[s[i]-'a']];
	        if(dp[i+1]<0)
	        dp[i+1]+=mod;
	        pos[s[i]-'a']=i;
	    }
	    return dp[n]%mod;
	}
};