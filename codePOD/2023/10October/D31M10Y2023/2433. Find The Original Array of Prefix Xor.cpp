/*Problem LeetCode (Medium)

2433. Find The Original Array of Prefix Xor


Question link: https://leetcode.com/problems/find-the-original-array-of-prefix-xor/description/?envType=daily-question&envId=2023-10-31


Logic: Bit Manipulation

-------------------------

Complexity: 

Method 1:  Bit Manipulation

Time Complexity=O(n)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Bit Manipulation
*/

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>ans;
        int n=pref.size();
        int xorV=0;
        for(int i=0;i<n;i++)
        {
            xorV^=pref[i];
            ans.push_back(xorV);
            xorV=pref[i];
        }
        return ans;
    }
};