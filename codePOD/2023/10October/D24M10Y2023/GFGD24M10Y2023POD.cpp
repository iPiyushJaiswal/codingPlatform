/*Problem GFG (Hard)

Palindromic Partitioning


Question link: https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1

---------------------------

Logic: DP

---------------------------

Complexity: DP


Method 1 : Recursion

Time Complexity= O(n^n) exponential.

Space Complexity=O(n) recursive space  

-----------------------------
Method 2 : Memoization

Time Complexity= O(n*n)

Space Complexity=O(n) dp vector+ O(n) recursive space  

-----------------------------
Method 3 : Tabulation

Time Complexity= O(n*n)

Space Complexity=O(n) dp vector   

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1 : DP
*/

class Solution{
public:
    bool isPali(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            return false;
            i++;
            j--;
        }
        return true;
    }
    int rec(string s,int i,int n)
    {
        if(i==n)
        return 0;
        int mini=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(isPali(s,i,j))
            {
                int step=1+rec(s,j+1,n);
                mini=min(mini,step);
            }
        }
        return mini;
    }
    int rec1(string s,int i,int n,vector<int>&dp)
    {
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int mini=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(isPali(s,i,j))
            {
                int step=1+rec1(s,j+1,n,dp);
                mini=min(mini,step);
            }
        }
        return dp[i]=mini;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        // recursion
        // return rec(str,0,n)-1;
        
        // memoization
        // vector<int>dp(n+1,-1);
        // return rec1(str,0,n,dp)-1;
        
        // tabulation
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            int mini=INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(isPali(str,i,j))
                {
                    int step=1+dp[j+1];
                    mini=min(mini,step);
                }
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};