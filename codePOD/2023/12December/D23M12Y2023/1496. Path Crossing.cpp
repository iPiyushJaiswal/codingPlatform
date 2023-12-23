/*Problem LeetCode (Easy)

1496. Path Crossing


Question link: https://leetcode.com/problems/path-crossing/description/?envType=daily-question&envId=2023-12-23

Solution link: https://leetcode.com/problems/path-crossing/submissions/?envType=daily-question&envId=2023-12-23


Logic : Unordered_Set

--------------------------
Complexity: 

Method 1: Unordered_Set

Time Complexity=O(n)

Space Complexity=O(n)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Unordered_Set
*/

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string>st;
        int n=path.size();
        int x=0,y=0;
        st.insert(to_string(x)+","+to_string(y));
        for(int i=0;i<n;i++)
        {
            if(path[i]=='N')
            y++;
            else if(path[i]=='S')
            y--;
            else if(path[i]=='E')
            x++;
            else
            x--;
            if(st.find(to_string(x)+","+to_string(y))!=st.end())
            return true;
            st.insert(to_string(x)+","+to_string(y));
        }
        return false;
    }
};