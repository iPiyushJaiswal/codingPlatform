/*Problem GFG (Medium)

Sequence of Sequence


Question link: https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : Recursion

Time Complexity= O(2^n)

Space Complexity= O(n) recursive stack
----------------------------------
Method 2 : Memoization

Time Complexity= O(n*m)

Space Complexity= O(n*m) dp vector + O(n) recursive stack
----------------------------------
Method 3 : Tabulation

Time Complexity= O(n*m)

Space Complexity= O(n*m) dp vector
----------------------------------
Method 4 : Space Optimization

Time Complexity= O(n*m)

Space Complexity= O(2*m) dp vector
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution{
public:
    int rec(int m,int n)
    {
        if(m<n)
        return 0;
        if(n==0)
        return 1;
        int a=0,b=0;
        a=rec(m/2,n-1);
        b=rec(m-1,n);
        return a+b;
    }
    int rec1(int m,int n,vector<vector<int>>&dp)
    {
        if(m<n)
        return 0;
        if(n==0)
        return 1;
        if(dp[m][n]!=-1)
        return dp[m][n];
        int a=0,b=0;
        a=rec1(m/2,n-1,dp);
        b=rec1(m-1,n,dp);
        return dp[m][n]=a+b;
    }
    int numberSequence(int m, int n){
        // code here
        // return rec(m,n);
        
        // memoization
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return rec1(m,n,dp);
        
        // tabulation
        //   vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //     for(int i=0;i<=m;i++)
        //     dp[0][i]=1;
        //       for(int i=1;i<=n;i++)
        //       {
        //           for(int j=1;j<=m;j++)
        //           {
        //               int a=0,b=0;
        //                 a=dp[i-1][j/2];
        //                 b=dp[i][j-1];
        //                 dp[i][j]=a+b;
        //           }
        //       }
        //       return dp[n][m];
        
        // space optmization
            vector<int>dp(m+1,1);
            vector<int>temp(m+1,0);

              for(int i=1;i<=n;i++)
              {
                  for(int j=1;j<=m;j++)
                  {
                      int a=0,b=0;
                        a=dp[j/2];
                        b=temp[j-1];
                        temp[j]=a+b;
                  }
                  dp=temp;
              }
              return dp[m];
    }
};