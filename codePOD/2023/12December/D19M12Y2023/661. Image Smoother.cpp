/*Problem LeetCode (Easy)

661. Image Smoother


Question link: https://leetcode.com/problems/image-smoother/description/?envType=daily-question&envId=2023-12-19

Solution link: https://leetcode.com/problems/image-smoother/submissions/1123150957/?envType=daily-question&envId=2023-12-19


Logic : Array + Maths

--------------------------

Complexity: 

Method 1: Brute Force

Time Complexity=O(n*m)

Space Complexity=O(n*m)
--------------------------
Method 2: Optimized (Nice approach)

Time Complexity=O(n*m)

Space Complexity=O(1)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Brute Force
*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        int r[]={-1,-1,-1,0,1,1,1,0};
        int c[]={-1,0,1,1,1,0,-1,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum=img[i][j];
                int count=1;
                for(int k=0;k<8;k++)
                {
                    int rV=i+r[k];
                    int cV=j+c[k];
                    if(rV>=0 && rV<n && cV>=0 && cV<m)
                    {
                        count++;
                        sum+=img[rV][cV];
                    }
                }
                ans[i][j]=sum/count;
            }
        }
        return ans;
    }
};

/*----------------------------------------
Method 2: Optimized
*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        int r[]={-1,-1,-1,0,1,1,1,0};
        int c[]={-1,0,1,1,1,0,-1,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum=img[i][j]%256;
                int count=1;
                for(int k=0;k<8;k++)
                {
                    int rV=i+r[k];
                    int cV=j+c[k];
                    if(rV>=0 && rV<n && cV>=0 && cV<m)
                    {
                        count++;
                        sum+=img[rV][cV]%256;
                    }
                }
                img[i][j]+=(sum/count)*256;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            img[i][j]/=256;
        }
        return img;
    }
};