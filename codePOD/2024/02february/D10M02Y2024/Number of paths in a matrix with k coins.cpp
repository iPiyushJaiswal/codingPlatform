/*Problem GFG (Medium)

Number of paths in a matrix with k coins


Question link:	https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^(n+m))

Space Complexity= O(n+m) recursive stack
----------------------------------
Method 2 : Memoization

Time Complexity= O(n*m*k)

Space Complexity= O(n*m*k) dp vector O(n+m) recursive stack.
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
public:
    long long rec(int n, int k, vector<vector<int>> &arr,int i,int j)
    {
        if(i==n-1 && j==n-1)
        {
            if(k==arr[i][j])
            return 1;
            return 0;
        }
        if(i>=n || j>=n || k<0)
        return 0;
        long long a=rec(n,k-arr[i][j],arr,i+1,j);
        long long b=rec(n,k-arr[i][j],arr,i,j+1);
        return a+b;
    }
    long long rec1(int n, int k, vector<vector<int>> &arr,int i,int j,
    vector<vector<vector<int>>>&dp)
    {
        if(i==n-1 && j==n-1)
        {
            if(k==arr[i][j])
            return 1;
            return 0;
        }
        if(i>=n || j>=n || k<0)
        return 0;
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        long long a=rec1(n,k-arr[i][j],arr,i+1,j,dp);
        long long b=rec1(n,k-arr[i][j],arr,i,j+1,dp);
        return dp[i][j][k]=a+b;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        
        // Code Here
        
        // recursion
        // return rec(n,k,arr,0,0);
        
        // memoizaton
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return rec1(n,k,arr,0,0,dp);
    }
};