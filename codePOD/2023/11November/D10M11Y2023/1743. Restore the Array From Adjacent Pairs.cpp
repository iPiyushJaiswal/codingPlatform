/*Problem LeetCode (Medium)

1743. Restore the Array From Adjacent Pairs


Question link: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/


Logic: DFS

--------------------------

Complexity: 

Method 1: DFS

Time Complexity=O(3n)

Space Complexity=O(3n)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DFS
*/

class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,
    vector<int>& ans, int root, unordered_map<int, int>& mp) {
        mp[root] = 0;
        ans.push_back(root);
        for (auto it : adj[root]) {
            if (mp[it] != 0)
                dfs(adj, ans, it, mp);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size();
        unordered_map<int,vector<int>>adj;
        unordered_map<int, int> mp;
        int root = -1;
        for (int i = 0; i < n; i++) {
            adj[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            adj[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
            mp[adjacentPairs[i][0]]++;
            mp[adjacentPairs[i][1]]++;
        }

        for (auto it : mp) {
            if (it.second == 1)
                root = it.first;
        }
        vector<int> ans;
        // if (root != -1)
        dfs(adj, ans, root, mp);
        return ans;
    }
};
