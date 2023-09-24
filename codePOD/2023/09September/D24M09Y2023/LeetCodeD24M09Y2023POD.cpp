/*Problem LeetCode (Medium)

799. Champagne Tower


Question link: https://leetcode.com/problems/champagne-tower/description/


Logic: DP + Pascel triangle

-------------------------

Complexity: 

Method 1:  DP + Pascel triangle

Time Complexity=O(query_row*query_glass)

Space Complexity=O(query_row) 

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP + Pascel triangle
*/

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>dp(1);
        dp[0]=poured;
        for(int i=1;i<=query_row;i++)
        {
            vector<double>curr(i+1);
            for(int j=0;j<=i;j++)
            {
                double a=0, b=0;
                if(j-1>=0)
                {
                    a=(dp[j-1]-1)/2;
                // cout<<a<<" "<<j-1<<endl;    
                }
                if(i>j)
                {b=(dp[j]-1)/2;
                //  cout<<b<<" "<<j<<endl;   
                }
                a=(a<0)?0:a ;
                b= (b<0)?0:b;
                curr[j]=a+b;
                // cout<<curr[j]<<" ";
            }
            cout<<endl;
            dp.resize(i+1);
            dp=curr;
        }
        if(dp[query_glass]>=1)
        return 1;
        return dp[query_glass];
    }
};