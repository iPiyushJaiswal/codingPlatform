/*Problem LeetCode (Medium)

907. Sum of Subarray Minimums


Question link: https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20

Solution link: https://leetcode.com/problems/sum-of-subarray-minimums/submissions/1151944413/?envType=daily-question&envId=2024-01-20


Logic : Monotonic Stack

--------------------------
Complexity: 

Method 1: Monotonic Stack

Time Complexity=O(n)

Space Complexity=O(n) stack
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Monotonic Stack
*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9 +7;
        stack<pair<int,int>>st;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[i]<st.top().first)
            {
                auto it=st.top();
                st.pop();
                if(!st.empty())
                ans=(ans+(1ll*it.first*(it.second-st.top().second)*
                (i-it.second))%mod)%mod;
                else
                ans=(ans+(1ll*it.first*(it.second+1)*(i-it.second))%mod)%mod;
            }
            st.push({arr[i],i});
        }
        while(!st.empty())
            {
                auto it=st.top();
                st.pop();
                if(!st.empty())
                ans=(ans+(1ll*it.first*(it.second-st.top().second)*
                (n-it.second))%mod)%mod;
                else
                ans=(ans+(1ll*it.first*(it.second+1)*(n-it.second))%mod)%mod;
            }
            return ans;
    }
};