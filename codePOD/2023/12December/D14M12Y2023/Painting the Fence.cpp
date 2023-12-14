/*Problem GFG (Medium)

Painting the Fence


Question link: https://www.geeksforgeeks.org/problems/painting-the-fence3727/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : DP

Time Complexity= O(n)

Space Complexity= O(1)

----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        long long same=0;
        long long diff=k;
        int mod=1e9 +7;
        for(int i=2;i<=n;i++)
        {
            long long temp=(((same+diff)%mod)*(k-1))%mod;
            same=diff;
            diff=temp;
        }
        return (same+diff)%mod;
    }
};