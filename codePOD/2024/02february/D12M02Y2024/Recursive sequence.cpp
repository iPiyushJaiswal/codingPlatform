/*Problem GFG (Easy)

Recursive sequence


Question link:	https://www.geeksforgeeks.org/problems/recursive-sequence1611/1

---------------------------

Logic: Array

---------------------------

Complexity: 

Method 1 : Recursive

Time Complexity= O(n*n)

Space Complexity= O(n) recursive stack.
----------------------------------
Method 2 : Iterative

Time Complexity= O(n*n)

Space Complexity= O(1)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Recursive
*/

class Solution{
public:
    int mod=1e9 +7;
    long long rec(int n,int val)
    {
        if(n==1)
        return 1;
        long long ans=1;
        for(int i=0;i<n;i++)
        ans=(ans*val--)%mod;
        return (ans + rec(n-1,val))%mod;
    }
    long long sequence(int n){
        // code here
        return rec(n,(n*(n+1))/2);
    }
};


/* ------------------------------------
Method 2: Iterative
*/

class Solution{
public:
    long long sequence(int n){
        // code here
        long long val=1;
        long long ans=0;
        int mod=1e9 +7;
        for(int i=0;i<n;i++)
        {
            long long temp=1;
            for(int j=0;j<=i;j++)
            {
                temp=(temp*val)%mod;
                val++;
            }
            ans=(ans+temp)%mod;
        }
        return ans;
    }
};