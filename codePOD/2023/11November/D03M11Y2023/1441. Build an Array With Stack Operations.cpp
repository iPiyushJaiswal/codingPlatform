/*Problem LeetCode (Medium)

1441. Build an Array With Stack Operations


Question link: https://leetcode.com/problems/build-an-array-with-stack-operations/description/?envType=daily-question&envId=2023-11-03


Logic: Array

--------------------------

Complexity: 

Method : Array

Time Complexity=O(n)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Array
*/

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int size=target.size();
        int i=0;
        int count=1;
        vector<string>ans;
        while(i<size)
        {
            if(target[i]==count)
            {
                ans.push_back("Push");
                i++;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            count++;
        }
        return ans;
    }
};