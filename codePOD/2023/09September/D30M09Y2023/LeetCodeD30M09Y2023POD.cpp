/*Problem LeetCode (Medium)

456. 132 Pattern


Question link: https://leetcode.com/problems/132-pattern/description/?envType=daily-question&envId=2023-09-30

Logic: Stack

-------------------------

Complexity: 

Method 1:  Stack

Time Complexity=O(n)

Space Complexity=O(n) 

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Stack
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int third=INT_MIN;
        stack<int>st;
        st.push(nums[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<third)
            return true;
            while(!st.empty() && st.top()<nums[i])
            {
                third=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};