/*Problem LeetCode (Easy)

268. Missing Number


Question link: https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20

Solution link: https://leetcode.com/problems/missing-number/submissions/1180493878/?envType=daily-question&envId=2024-02-20


Logic : Bit Manipulation

--------------------------
Complexity: 

Method 1: Bit Manipulation

Time Complexity=O(n)

Space Complexity=O(1)  
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Bit Manipulation
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xorV=0;
        for(int i=0;i<n;i++)
        {
            xorV^=nums[i];
            xorV^=i;
        }
        return xorV^=n;
    }
};