/*Problem GFG (Medium)

Count digit groupings of a number


Question link: https://www.geeksforgeeks.org/problems/count-digit-groupings-of-a-number1520/1

---------------------------

Logic: DP 

---------------------------

Complexity: 

Method 1 : Recursion 

Time Complexity= O(n^n)

Space Complexity= O(n) recursive stack.
----------------------------------
Method 2 : Memoization 

Time Complexity= O(n^3)

Space Complexity= O(n^2)dp vector + O(n) recursive stack.
----------------------------------
Method 3 : Tabulation 

Time Complexity= O(n^3)

Space Complexity= O(n^2)dp vector.
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP 
*/

class Solution{
	public:
	int rec(int prev,int i,int n,string str)
	{
	    if(i==n)
	    return 1;
	    int ans=0;
	    int sum=0;
	    for(int j=i;j<n;j++)
	    {
	        sum+=str[j]-'0';
	        if(prev<=sum)
	        ans+=rec(sum,j+1,n,str);
	    }
	    return ans;
	}
	int rec1(int prev,int i,int n,string str,vector<vector<int>>&dp)
	{
	    if(i==n)
	    return 1;
	    if(dp[prev][i]!=-1)
	    return dp[prev][i];
	    int ans=0;
	    int sum=0;
	    for(int j=i;j<n;j++)
	    {
	        sum+=str[j]-'0';
	        if(prev<=sum)
	        ans+=rec1(sum,j+1,n,str,dp);
	    }
	    return dp[prev][i]=ans;
	}
	int TotalCount(string str){
	    // Code here
	    int n=str.size();
	    
	   // recursion
	   // return rec(0,0,n,str);
	   
	   //memoization
	   //vector<vector<int>>dp(1000,vector<int>(n+1,-1));
	   //return rec1(0,0,n,str,dp);
	   
	   //tabulation
	   int digitSum=0;
	   for(int i=0;i<n;i++)
	   digitSum+=str[i]-'0';
	   vector<vector<int>>dp(digitSum+1,vector<int>(n+1,0));
	   for(int i=digitSum;i>=0;i--)
	   {
	       dp[i][n]=1;
	       for(int k=n-1;k>=0;k--)
	       {
	            int ans=0;
        	    int sum=0;
        	    for(int j=k;j<n;j++)
        	    {
        	        sum+=str[j]-'0';
        	        if(i<=sum)
        	        ans+=dp[sum][j+1];
        	    }
        	    dp[i][k]=ans;
	       }
	   }
	   return dp[0][0];
	   
	}
};