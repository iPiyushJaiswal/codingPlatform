/*Problem LeetCode (Medium)

935. Knight Dialer


Question link: https://leetcode.com/problems/knight-dialer/?envType=daily-question&envId=2023-11-27

Solution link: https://leetcode.com/problems/knight-dialer/submissions/?envType=daily-question&envId=2023-11-27


Logic: 2 approaches

--------------------------

Complexity: 

Method 1: Recursion

Time Complexity=O(10^(8*n))

Space Complexity=O(n) recursive stack

--------------------------
Method 2: Memoization

Time Complexity=O(10*n)

Space Complexity=O(20*n)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: notUpdate input matrix + dp vector + sorting
*/

class Solution {
public:
int mod=1e9 +7;
    int rec(vector<vector<int>>&mat,int rN[],int cN[],int i,int j,int n,int x,int y)
    {
        if(n==1)
        return 1;
        int count=0;
        for(int k=0;k<8;k++)
        {
            int r=i+rN[k];
            int c=j+cN[k];
            if(r>=0 && r<=x && c>=0 && c<=y && mat[r][c]!=-1)
            count=(count%mod +  rec(mat,rN,cN,r,c,n-1,x,y)%mod)%mod;
        }
        return count;
    }
    int rec1(vector<vector<int>>&mat,int rN[],int cN[],int i,int j,int n,int x,int y,vector<vector<vector<int>>>&dp)
    {
        if(n==1)
        return 1;
        if(dp[i][j][n]!=-1)
        return dp[i][j][n];
        int count=0;
        for(int k=0;k<8;k++)
        {
            int r=i+rN[k];
            int c=j+cN[k];
            if(r>=0 && r<=x && c>=0 && c<=y && mat[r][c]!=-1)
            count=(count%mod +  rec1(mat,rN,cN,r,c,n-1,x,y,dp)%mod)%mod;
        }
        return dp[i][j][n]=count;
    }
    int knightDialer(int n) {
        int rN[]={-2,-2,-1,1,2,2,1,-1};
        int cN[]={-1,1,2,2,1,-1,-2,-2};
        vector<vector<int>>mat={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        int ans=0;
        // for(int i=0;i<4;i++)
        // {
        //     for(int j=0;j<3;j++)
        //     {
        //         if(mat[i][j]!=-1)
        //         {
        //             cout<<mat[i][j]<<" ";
        //             ans=(ans + rec(mat,rN,cN,i,j,n,3,2))%mod;
        //         }
        //     }
        // }
        // memoization
        vector<vector<vector<int>>>dp(5,vector<vector<int>>(4,vector<int>(n+1,-1)));
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(mat[i][j]!=-1)
                {
                    cout<<mat[i][j]<<" ";
                    ans=(ans + rec1(mat,rN,cN,i,j,n,3,2,dp))%mod;
                }
            }
        }
        return ans;
    }
};