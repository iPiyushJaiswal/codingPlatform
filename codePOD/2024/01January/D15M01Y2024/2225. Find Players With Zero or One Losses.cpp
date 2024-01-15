/*Problem LeetCode (Medium)

2225. Find Players With Zero or One Losses


Question link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15

Solution link: https://leetcode.com/problems/find-players-with-zero-or-one-losses/submissions/1146565443/?envType=daily-question&envId=2024-01-15


Logic : Hashing

--------------------------
Complexity: 

Method 1: Hashing

Time Complexity=O(nlogn)

Space Complexity=O(nlogn) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Hashing
*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        int n=m.size();
        vector<vector<int>>ans(2);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int a=m[i][0];
            int b=m[i][1];
            mp[b]++;
            if(mp.find(a)==mp.end())
            mp[a]=0;            
        }
        for(auto it:mp)
        {
            if(it.second==0)
            ans[0].push_back(it.first);
            else if(it.second==1)
            ans[1].push_back(it.first);
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};