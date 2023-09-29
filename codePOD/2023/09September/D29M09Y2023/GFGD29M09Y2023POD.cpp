/*Problem GFG (Medium)

Number Of Enclaves


Question link: https://practice.geeksforgeeks.org/problems/number-of-enclaves/1

---------------------------

Logic: Iteration

---------------------------

Complexity: 

Method 1: DFS

Time Complexity=O(n*m*4)

Space Complexity=O(m*n) visited vector + O(m*n) recursive stack.

-----------------------------
Method 1: BFS

Time Complexity=O(n*m*4)

Space Complexity=O(m*n) visited vector .

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DFS 
*/

class Solution {
  public:
  void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,
  int x,int y,int rN[],int cN[],int m,int n)
  {
      vis[x][y]=1;
      for(int i=0;i<4;i++)
      {
          int r=x+rN[i];
          int c=y+cN[i];
          if(r>=0 && r<m && c>=0 && c<n && vis[r][c]==0 
          && grid[r][c]==1)
          dfs(grid,vis,r,c,rN,cN,m,n);
      }
  }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int rN[]={-1,0,1,0};
        int cN[]={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            if(vis[0][i]==0 && grid[0][i]==1)
            dfs(grid,vis,0,i,rN,cN,m,n);
            if(vis[m-1][i]==0 && grid[m-1][i]==1)
            dfs(grid,vis,m-1,i,rN,cN,m,n);
        }
        for(int i=0;i<m;i++)
        {
            if(vis[i][0]==0 && grid[i][0]==1)
            dfs(grid,vis,i,0,rN,cN,m,n);
            if(vis[i][n-1]==0 && grid[i][n-1]==1)
            dfs(grid,vis,i,n-1,rN,cN,m,n);
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1)
                ans++;
            }
        }
        return ans;
    }
};

/*----------------------------------------------------------
Method 2: BFS */

// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 && !vis[i][0])
            {
                q.push({i,0});
                vis[i][0]=1;
            }
            if(grid[i][m-1]==1 && !vis[i][m-1])
            {
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 && !vis[0][i])
            {
                q.push({0,i});
                vis[0][i]=1;
            }
            if(grid[n-1][i]==1 && !vis[n-1][i])
            {
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        int rV[]={-1,1,0,0};
        int cV[]={0,0,-1,1};
        int rN,cN;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                rN=r+rV[i];
                cN=c+cV[i];
                if(rN>=0 && rN<n && cN>=0 && cN<m && !vis[rN][cN] && grid[rN][cN]==1)
                {
                    vis[rN][cN]=1;
                    q.push({rN,cN});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                ans++;
            }
        }
        return ans;
    }
};
