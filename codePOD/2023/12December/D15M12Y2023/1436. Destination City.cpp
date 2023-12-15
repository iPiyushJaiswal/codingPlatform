/*Problem LeetCode (Easy)

1436. Destination City


Question link: https://leetcode.com/problems/destination-city/

Solution link: https://leetcode.com/problems/destination-city/submissions/1120189255/


Logic : Set

--------------------------

Complexity: 

Method 1: Set

Time Complexity=O(n)

Space Complexity=O(n)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Set
*/

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n=paths.size();
        set<string>st;
        for(int i=0;i<n;i++)
        st.insert(paths[i][0]);
        for(int i=0;i<n;i++)
        {
            if(st.find(paths[i][1])==st.end())
            return paths[i][1];
        }
        return "";
    }
};