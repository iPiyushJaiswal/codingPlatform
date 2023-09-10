/*Problem LeetCode (Hard)

1359. Count All Valid Pickup and Delivery Options


Question link: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/description/?envType=daily-question&envId=2023-09-10

Logic: DP + maths + permutation.

Complexity: 

Method 1: DP + maths + permutation.

Time Complexity=O(n)

Space Complexity=O(1)

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------
*/

class Solution {
public:
    int countOrders(int n) {
        int mod=1e9+7;
        int ans=1;
        int prev=1;
        for(int i=2;i<=n;i++)
        {
            int val=(2*i -1)%mod;
            int count=((val)*(val+1)/2)%mod;
            ans=(1ll*(prev%mod)*(count%mod))%mod;
            prev=ans;
        }
        return ans;
    }
};