/*Problem GFG (Medium)

Replace O's with X's


Question link: https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

Complexity: 

Method 1: DFS

Time Complexity=O(n*m*4)

Space Complexity=O(n*m)

-----------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DFS
*/

class Solution{
public:
    void dfs(int i,int j,int n,int m,int rN[],int cN[],
    vector<vector<char>>&mat,vector<vector<int>>&vis)
    {
        vis[i][j]=0;
        for(int k=0;k<4;k++)
        {
            int r=i+rN[k];
            int c=j+cN[k];
            if(r>=0 && r<n && c>=0 && c<m && mat[r][c]=='O' &&
            vis[r][c]==-1)
            dfs(r,c,n,m,rN,cN,mat,vis);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,-1));
        int rN[]={-1,0,1,0};
        int cN[]={0,1,0,-1};
        for(int i=0;i<m;i++)
        {
            if(mat[0][i]=='O' && vis[0][i]==-1)
            dfs(0,i,n,m,rN,cN,mat,vis);
            if(mat[n-1][i]=='O' && vis[n-1][i]==-1)
            dfs(n-1,i,n,m,rN,cN,mat,vis);
        }
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='O' && vis[i][0]==-1)
            dfs(i,0,n,m,rN,cN,mat,vis);
            if(mat[i][m-1]=='O' && vis[i][m-1]==-1)
            dfs(i,m-1,n,m,rN,cN,mat,vis);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O' && vis[i][j]==-1)
                mat[i][j]='X';
            }
        }
        return mat;
    }
};