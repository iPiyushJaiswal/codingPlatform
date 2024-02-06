/*Problem LeetCode (Medium)

49. Group Anagrams


Question link: https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06

Solution link: https://leetcode.com/problems/group-anagrams/submissions/1167459116/?envType=daily-question&envId=2024-02-06


Logic : Hashing

--------------------------
Complexity: 

Method 1: Hashing

Time Complexity=O(nlogn)

Space Complexity=O(n) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Hashing
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        unordered_map<string,vector<string>>mp;
        int n=str.size();
        for(int i=0;i<n;i++)
        {
            string s=str[i];
            sort(s.begin(),s.end());
           mp[s].push_back(str[i]); 
        }
        vector<vector<string>>ans;
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};