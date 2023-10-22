/*Problem GFG (Medium)

Maximum sum increasing subsequence


Question link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

---------------------------

Logic: Combination + Maths

---------------------------

Complexity: 


Method 1 : Recursion

Time Complexity= O(2^n)

Space Complexity=O(n) recursive space  

-----------------------------
Method 2 : Memoization

Time Complexity= O(n*n)

Space Complexity=O(n*n) dp vector+ O(n) recursive space  

-----------------------------
Method 3 : Tabulation

Time Complexity= O(n*n)

Space Complexity=O(n*n) dp vector   

-----------------------------
Method 4 : Space Optimization

Time Complexity= O(n*n)

Space Complexity=O(2n) dp vector 

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1 : Combination + Maths
*/

class Solution{
	public:
	int ans=0;
	int rec(int arr[],int n,int i,int prev)
	{
	    if(i==n)
	    return 0;
	    int take=0;
	    if(prev==-1 || arr[prev]<arr[i])
	    take=arr[i]+rec(arr,n,i+1,i);
	    int notTake=rec(arr,n,i+1,prev);
	    ans=max(ans,max(take,notTake));
	    return max(take,notTake);
	}
	int rec1(int arr[],int n,int i,int prev,vector<vector<int>>&dp)
	{
	    if(i==n)
	    return 0;
	    if(dp[i][prev+1]!=-1)
	    return dp[i][prev+1];
	    int take=0;
	    if(prev==-1 || arr[prev]<arr[i])
	    take=arr[i]+rec1(arr,n,i+1,i,dp);
	    int notTake=rec1(arr,n,i+1,prev,dp);
	    ans=max(ans,max(take,notTake));
	    return dp[i][prev+1]=max(take,notTake);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    // recursion
	   // rec(arr,n,0,-1);
	   // return ans;
	   
	    //memoization
	   // vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
    //     rec1(arr,n,0,-1,dp);
	   // return ans;
	   
	   //tabulation
	   //vector<vector<int>>dp(n+2,vector<int>(n+2,0));
	   //for(int i=n-1;i>=0;i--)
	   //{
	   //    for(int j=i-1;j>=-1;j--)
	   //    {
	   //        int take=0;
    //     	    if(j==-1 || arr[j]<arr[i])
    //     	    take=arr[i]+dp[i+1][i+1];
    //     	    int notTake=dp[i+1][j+1];
    //     	    ans=max(ans,max(take,notTake));
    //     	    dp[i][j+1]=max(take,notTake);
	   //    }
	   //}
	   //return ans;
	   
	   //space optimization
	    vector<int>dp(n+2,0);
	    vector<int>temp(n+2,0);
	   for(int i=n-1;i>=0;i--)
	   {
	       for(int j=i-1;j>=-1;j--)
	       {
	           int take=0;
        	    if(j==-1 || arr[j]<arr[i])
        	    take=arr[i]+dp[i+1];
        	    int notTake=dp[j+1];
        	   // ans=max(ans,max(take,notTake));
        	    temp[j+1]=max(take,notTake);
	       }
	       dp=temp;
	   }
	   for(int i=0;i<n;i++)
	   {
	       ans=max(ans,dp[i]);
	   }
	   return ans;
	}  
};