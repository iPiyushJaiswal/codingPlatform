/*Problem LeetCode (Easy)

645. Set Mismatch


Question link: https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22

Solution link: https://leetcode.com/problems/set-mismatch/submissions/1153435220/?envType=daily-question&envId=2024-01-22


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
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int xorV=0;
        for(int i=0;i<nums.size();i++)
        {
            xorV^=(i+1);
            xorV^=nums[i];
        }
        int sBit=xorV&(~(xorV-1));
        int buck1=0,buck2=0;
        for(int i=0;i<n;i++)
        {
            if((sBit&(i+1))==0)
            buck2^=(i+1);
            else
            buck1^=(i+1);
            if((sBit&nums[i])==0)
            buck2^=nums[i];
            else
            buck1^=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(buck1==nums[i])
            return {buck1,buck2};
            else if(buck2==nums[i])
            return {buck2,buck1};
        }
        return {-1,-1};
    }
};