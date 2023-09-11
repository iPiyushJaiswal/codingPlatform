/*Problem LeetCode (Medium)

1282. Group the People Given the Group Size They Belong To


Question link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/description/?envType=daily-question&envId=2023-09-11

Logic: MAP + Common sense.

Complexity: 

Method 1: MAP + Common sense.

Time Complexity=O(n) *(if map *logn if unordered_map *n worst case ) in Unordered_map amortized O(1)=> 
total=> O(n)

Space Complexity=O(n)

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int,vector<int>>mp;
        int n=groupSizes.size();
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            mp[groupSizes[i]].push_back(i);
            if(mp[groupSizes[i]].size()>=groupSizes[i])
            {
                ans.push_back(mp[groupSizes[i]]);
                mp.erase(groupSizes[i]);
            }
        }
        
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};