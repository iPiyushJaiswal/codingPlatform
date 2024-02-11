/*Problem LeetCode (Medium)

1463. Cherry Pickup II


Question link: https://leetcode.com/problems/cherry-pickup-ii/description/?envType=daily-question&envId=2024-02-11

Solution link: https://leetcode.com/problems/cherry-pickup-ii/submissions/1172022112/?envType=daily-question&envId=2024-02-11


Logic : LIS

--------------------------
Complexity: 

Method 1: Recursive

Time Complexity=O(n * 3^m * 3^m)

Space Complexity=O(n) recursive stack. 
--------------------------
Method 2: Memoization

Time Complexity=O(n*m*m*3*3)

Space Complexity=O(n*m*m) dp vector + O(n) recursive stack
--------------------------
Method 3: Tabulation

Time Complexity=O(n*m*m*3*3)

Space Complexity=O(n*m*m) dp vector
--------------------------
Method 4: Space Optimization

Time Complexity=O(n*m*m*3*3)

Space Complexity=O(2*m*m) dp vector
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution {
public:
    int rec(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid)
    {
        if(i==n || j1<0 || j1>=m || j2<0 || j2>=m)
        return 0;
        int maxi=0;
        for(int c1=-1;c1<=1;c1++)
        {
            int val1=0;
            for(int c2=-1;c2<=1;c2++)
            {
                if(j1+c1==j2+c2)
                continue;
                val1=max(val1,rec(i+1,j1+c1,j2+c2,n,m,grid));
            }
            maxi=max(maxi,grid[i][j1]+grid[i][j2]+val1);
        }
        return maxi;
    }
    int rec1(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid,
    vector<vector<vector<int>>>&dp)
    {
        if(i==n || j1<0 || j1>=m || j2<0 || j2>=m)
        return 0;
        if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];
        int maxi=0;
        for(int c1=-1;c1<=1;c1++)
        {
            int val1=0;
            for(int c2=-1;c2<=1;c2++)
            {
                if(j1+c1==j2+c2)
                continue;
                val1=max(val1,rec1(i+1,j1+c1,j2+c2,n,m,grid,dp));
            }
            maxi=max(maxi,grid[i][j1]+grid[i][j2]+val1);
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        // recusion
        // return rec(0,0,m-1,n,m,grid);

        // memoization
        // vector<vector<vector<int>>>dp(n+1,
        // vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        // return rec1(0,0,m-1,n,m,grid,dp);

        // tabulation
        // vector<vector<vector<int>>>dp(n+1,
        // vector<vector<int>>(m+1,vector<int>(m+1,0)));
        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j1=0;j1<m;j1++)
        //     {
        //         for(int j2=m-1;j2>=0;j2--)
        //         {
        //             int maxi=0;
        //             for(int c1=-1;c1<=1;c1++)
        //             {
        //                 int val1=0;
        //                 for(int c2=-1;c2<=1;c2++)
        //                 {
        //                     if(j1+c1==j2+c2)
        //                     continue;
        //                     if(j1+c1>=0 && j1+c1<m && j2+c2>=0 && j2+c2<m)
        //                     val1=max(val1,dp[i+1][j1+c1][j2+c2]);
        //                 }
        //                 maxi=max(maxi,grid[i][j1]+grid[i][j2]+val1);
        //             }
        //             dp[i][j1][j2]=maxi;
        //         }
        //     }
        // }
        // return dp[0][0][m-1];

        // space optimization
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        vector<vector<int>>temp(m+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=m-1;j2>=0;j2--)
                {
                    int maxi=0;
                    for(int c1=-1;c1<=1;c1++)
                    {
                        int val1=0;
                        for(int c2=-1;c2<=1;c2++)
                        {
                            if(j1+c1==j2+c2)
                            continue;
                            if(j1+c1>=0 && j1+c1<m && j2+c2>=0 && j2+c2<m)
                            val1=max(val1,dp[j1+c1][j2+c2]);
                        }
                        maxi=max(maxi,grid[i][j1]+grid[i][j2]+val1);
                    }
                    temp[j1][j2]=maxi;
                }
            }
            dp=temp;
        }
        return dp[0][m-1];
    }
};
