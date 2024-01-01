/*Problem LeetCode (Easy)

455. Assign Cookies


Question link: https://leetcode.com/problems/assign-cookies/

Solution link: https://leetcode.com/problems/assign-cookies/submissions/1133535535/


Logic : Sorting + 2 Pointers

--------------------------
Complexity: 

Method 1: Sorting + 2 Pointers

Time Complexity=O(ilogi + jlogj)

Space Complexity=O(1) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Sorting + 2 Pointers
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=g.size()-1;
        int j=s.size()-1;
        int count=0;
        while(i>=0 && j>=0)
        {
            if(g[i]<=s[j])
            {
                count++;
                i--;
                j--;
            }
            else
            i--;
        }
        return count;
    }
};