/*Problem GFG (Easy)

Reach a given score


Question link:	https://www.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(3n)

Space Complexity= O(n) dp vector
----------------------------------
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
    // Complete this function
    long long int count(long long int n)
    {
    	// Your code here
    	vector<long long int>dp(n+1,0);
    	dp[0]=1;
    	for(long long int i=3;i<=n;i++)
    	dp[i]+=dp[i-3];
    	for(long long int i=5;i<=n;i++)
    	dp[i]+=dp[i-5];
    	for(long long int i=10;i<=n;i++)
    	dp[i]+=dp[i-10];
    	return dp[n];
    }
};