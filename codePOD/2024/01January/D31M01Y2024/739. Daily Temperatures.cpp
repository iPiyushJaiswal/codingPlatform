/*Problem LeetCode (Medium)

739. Daily Temperatures


Question link: https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31

Solution link: https://leetcode.com/problems/daily-temperatures/submissions/1161632380/?envType=daily-question&envId=2024-01-31


Logic : Stack

--------------------------
Complexity: 

Method 1: Stack

Time Complexity=O(n)

Space Complexity=O(n) stack. 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Stack
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && t[i]>=t[st.top()])
            st.pop();
            if(st.empty())
            ans[i]=0;
            else
            ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;
    }
};