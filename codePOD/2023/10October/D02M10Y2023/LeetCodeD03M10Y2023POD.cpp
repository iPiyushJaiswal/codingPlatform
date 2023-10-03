/*Problem LeetCode (Easy)

1512. Number of Good Pairs


Question link: https://leetcode.com/problems/number-of-good-pairs/description/?envType=daily-question&envId=2023-10-03

Logic: Maths

-------------------------

Complexity: 

Method 1:  Maths

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
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[nums[i]]++;

        int ans=0;
        for(auto it:mp)
        {
            ans+=(it.second*(it.second-1)/2);
        }
        return ans;
    }
};