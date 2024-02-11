/*Problem GFG (Easy)

Recamans sequence


Question link:	https://www.geeksforgeeks.org/problems/recamans-sequence4856/1

---------------------------

Logic: Array

---------------------------

Complexity: 

Method 1 : Array

Time Complexity= O(n)

Space Complexity= O(n) set
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array
*/

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        unordered_set<int>st;
        vector<int>ans(n);
        ans[0]=0;
        for(int i=1;i<n;i++)
        {
            int val1=ans[i-1]-i;
            if(val1>0 && st.find(val1)==st.end())
            {
                ans[i]=val1;
                st.insert(val1);
            }
            else
            {
                ans[i]=ans[i-1]+i;
                st.insert(ans[i-1]+i);
            }
        }
        return ans;
    }
};