/*Problem GFG (Medium)

Number of paths


Question link: https://practice.geeksforgeeks.org/problems/number-of-paths0926/1

---------------------------

Logic: Combination + Maths

---------------------------

Complexity: 


Method 1 : Combination + Maths

Time Complexity= O(nlogn)

Space Complexity=O(1)  

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1 : Combination + Maths
*/

class Solution
{
    public:

    long long modInverse(long long a, long long m) {
        long long m0 = m;
        long long x0 = 0, x1 = 1;

        while (a > 1) {
            long long q = a / m;
            long long t = m;
            m = a % m, a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }

        if (x1 < 0) {
            x1 += m0;
        }

        return x1;
    }
    long long  numberOfPaths(int m, int n)
    {
        // Code Here
        int mod=1e9+7;
        long long x=m+n-2;
        long long y=min(m,n)-1;
        long long ans=1;
        for(long long i=1;i<=y;i++)
        {
            // ans=(((ans%mod)*(x-i+1)%mod)/(i%mod))%mod;
            ans=(ans*(x-i+1))%mod;
            ans=(ans*(modInverse(i,mod)))%mod;
        }
        return ans;
    }
};