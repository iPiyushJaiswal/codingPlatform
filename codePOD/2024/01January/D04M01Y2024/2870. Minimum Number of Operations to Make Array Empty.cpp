/*Problem LeetCode (Medium)

2870. Minimum Number of Operations to Make Array Empty


Question link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/

Solution link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/submissions/1136530712/


Logic : Maths

--------------------------
Complexity: 

Method 1: Maths

Time Complexity=O(n)

Space Complexity=O(n) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Maths
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        mp[nums[i]]++;
        int ans=0;
        for(auto it:mp)
        {
            if(it.second==1)
            return -1;
            if(it.second%3==1)
            {
                ans+=(it.second/3)-1 +2;
            }
            else if(it.second%3==0)
            ans+=(it.second/3);
            else
            ans+=(it.second/3)+1;
        }
        return ans;
    }
};