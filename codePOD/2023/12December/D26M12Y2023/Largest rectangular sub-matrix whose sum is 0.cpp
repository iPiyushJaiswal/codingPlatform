/*Problem GFG (Hard)

Largest rectangular sub-matrix whose sum is 0


Question link: https://www.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1

---------------------------

Logic: Matrix + Prefix Sum + Hashing

---------------------------

Complexity: 

Method 1 : Matrix + Prefix Sum + Hashing

Time Complexity= O(n*m*m)

Space Complexity= O(n*m)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Matrix + Prefix Sum + Hashing
*/

class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      int n=a.size();
      int m=a[0].size();
      vector<vector<int>>pref(n+1,vector<int>(m+1,0));
      for(int i=1;i<=n;i++)
      {
          for(int j=1;j<=m;j++)
          pref[i][j]=pref[i][j-1]+a[i-1][j-1];
      }
      int larArea=0;
      int sX=0,eX=0,sY=0,eY=0;
      for(int i=1;i<=m;i++)
      {
          for(int j=1;j<=m;j++)
          {
              unordered_map<int,int>mp;
              mp[0]=0;
              int val=0;
              for(int k=1;k<=n;k++)
              {
                  val+=pref[k][j]-pref[k][i-1];
                  if(mp.find(val)!=mp.end())
                  {
                      int area=(j-i+1)*(k-mp[val]);
                      if(larArea<area)
                      {
                          larArea=area;
                          sX=mp[val]+1;
                          eX=k;
                          sY=i;
                          eY=j;
                      }
                  }
                  else
                  mp[val]=k;
              }
          }
      }
      vector<vector<int>>ans;
      for(int i=sX;i<=eX;i++)
      {
          vector<int>temp;
          for(int j=sY;j<=eY;j++)
          temp.push_back(a[i-1][j-1]);
          ans.push_back(temp);
      }
      return ans;
  }
};