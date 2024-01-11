/*Problem GFG (Medium)

Remove K Digits


Question link: https://www.geeksforgeeks.org/problems/remove-k-digits/1

---------------------------

Logic: Stack

---------------------------

Complexity: 

Method 1 : Stack

Time Complexity= O(n)

Space Complexity= O(n) 
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Stack
*/

class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack<int>st;
        int n=S.size();
        if(n<=K)
        return "0";
        int count=0;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && (S[i]-'0')<st.top() && count<K)
            {
                count++;
                st.pop();
            }
            st.push(S[i]-'0');
        }
        while(!st.empty() && count<K)
        {
            st.pop();
            count++;
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top()+'0');
            st.pop();
        }
        // cout<<ans;
        int i=ans.size()-1;
        while(i>0)
        {
            if(ans[i]=='0')
            ans.pop_back();
            else
            break;
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};