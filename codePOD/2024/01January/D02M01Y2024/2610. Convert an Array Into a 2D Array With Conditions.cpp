/*Problem LeetCode (Medium)

2610. Convert an Array Into a 2D Array With Conditions


Question link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02

Solution link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/submissions/1134307458/?envType=daily-question&envId=2024-01-02


Logic : unordered_map

--------------------------
Complexity: 

Method 1: unordered_map

Time Complexity=O(n)

Space Complexity=O(n) 
--------------------------
Method 2: frequency array (This work if nums[i]<=size of array)

Time Complexity=O(n)

Space Complexity=O(n) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: unordered_map
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            maxi=max(maxi,mp[nums[i]]);
        }
        vector<vector<int>>ans(maxi);
        for(auto it:mp)
        {
            for(int i=0;i<it.second;i++)
            ans[i].push_back(it.first);
        }
        return ans;
    }
};

/*------------------------------------------------------------------------------------------------
Method 2: frequency array
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n+1);
        vector<vector<int>>ans;
        for(auto i:nums)
        {
            if(freq[i]>=ans.size())
            ans.push_back({});
            ans[freq[i]].push_back(i);
            freq[i]++;
        }
     return ans; 
    }
};