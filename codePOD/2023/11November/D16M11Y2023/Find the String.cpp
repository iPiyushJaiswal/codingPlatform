/*Problem GFG (Hard)

Find the String


Question link: https://www.geeksforgeeks.org/problems/find-the-string/1

---------------------------

Logic: SET

---------------------------

Complexity: 

Method 1 : SET

Time Complexity= O(n+k)

Space Complexity=O(k)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : SET
*/

class Solution
{
public:
    string findString(int n, int k) {
        // code here
        string ans="";

       unordered_set<string>st;

       for(int i=0;i<n;i++)ans+='0';

       st.insert(ans);

       string temp;

       for(int i=k-1;i>=0;i--){

           temp=ans.substr(ans.size()-n+1,n-1);

           temp+=to_string(i);

           if(st.find(temp)==st.end()){

               ans+=to_string(i);

               i=k;

               st.insert(temp);

           }

       }

       return ans;
    }
};