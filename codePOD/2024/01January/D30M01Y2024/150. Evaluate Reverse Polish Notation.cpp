/*Problem LeetCode (Medium)

150. Evaluate Reverse Polish Notation


Question link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30

Solution link: https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/1160775990/?envType=daily-question&envId=2024-01-30


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
    int evalRPN(vector<string>& t) {
        stack<int>st;
        int n=t.size();
        for(int i=0;i<n;i++)
        {
            int neg=1;
            int val=0;
            int sign=0;
            int x=t[i].size();
            for(int j=0;j<x;j++)
            {
                if((t[i][j]=='-' || t[i][j]=='+' || t[i][j]=='*' || t[i][j]=='/')
                && j+1==x)
                sign=1;
                else if(t[i][j]=='-')
                neg=-1;
                else if(t[i][j]=='+')
                neg=1;
                else
                val=val*10 + t[i][j]-'0';
            }
            if(sign==1)
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int temp=0;
                if(t[i][0]=='-')
                temp=b-a;
                else if(t[i][0]=='+')
                temp=b+a;
                else if(t[i][0]=='*')
                temp=b*a;
                else
                temp=b/a;
                st.push(temp);
            }
            else
            st.push(neg*val);
        }
        return st.top();
    }
};