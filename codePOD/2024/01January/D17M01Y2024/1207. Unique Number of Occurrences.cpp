/*Problem LeetCode (Easy)

1207. Unique Number of Occurrences


Question link: https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=daily-question&envId=2024-01-17

Solution link: https://leetcode.com/problems/unique-number-of-occurrences/submissions/1148444855/?envType=daily-question&envId=2024-01-17


Logic : Hashing

--------------------------
Complexity: 

Method 1: Hashing

Time Complexity=O(n)

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
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_set<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++)
        mp[arr[i]]++;
        for(auto it:mp)
        {
            if(st.find(it.second)!=st.end())
            return false;
            st.insert(it.second);
        }
        return true;
    }
};