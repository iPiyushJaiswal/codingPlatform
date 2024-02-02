/*Problem GFG (Medium)

Implement Atoi


Question link:	https://www.geeksforgeeks.org/problems/implement-atoi/1

---------------------------

Logic: String 

---------------------------

Complexity: 

Method 1 : String 

Time Complexity= O(n)

Space Complexity= O(1)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: String 
*/

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int val=0;
        int sign=1;
        int n=s.size();
        int i=0;
        if(s[i]=='-')
        {
            i++;
            sign=-1;
        }
        else if(s[i]=='+')
        {
            i++;
            sign=1;
        }
        while(i<n)
        {
            if(s[i]>='0' && s[i]<='9')
            val=val*10 + s[i]-'0';
            else
            return -1;
            i++;
        }
        return sign*val;
    }
};