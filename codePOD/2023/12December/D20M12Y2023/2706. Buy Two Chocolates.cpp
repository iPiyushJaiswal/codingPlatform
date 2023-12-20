/*Problem LeetCode (Easy)

2706. Buy Two Chocolates


Question link: https://leetcode.com/problems/buy-two-chocolates/description/?envType=daily-question&envId=2023-12-20

Solution link: https://leetcode.com/problems/buy-two-chocolates/submissions/1123984413/?envType=daily-question&envId=2023-12-20


Logic : Array

--------------------------
Complexity: 

Method 1: Array

Time Complexity=O(n)

Space Complexity=O(1)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array
*/

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n=prices.size();
        int mini1=INT_MAX;
        int mini2=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(mini1>prices[i])
            {
                mini2=mini1;
                mini1=prices[i];
            }
            else if(mini2>prices[i])
            mini2=prices[i];
        }
        if(money<mini1+mini2)
        return money;
        return money-mini1-mini2;
    }
};