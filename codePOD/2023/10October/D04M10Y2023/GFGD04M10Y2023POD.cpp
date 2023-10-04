/*Problem GFG (Medium)

Roman Number to Integer


Question link: https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1

---------------------------

Logic: Maths

---------------------------

Complexity: 


Method 1: Maths

Time Complexity=O(n)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Maths
*/

class Solution {
  public:
  int rTD(char ch)
  {
     if(ch=='I')
     return 1;
     else if(ch=='V')
     return 5;
     else if(ch=='X')
     return 10;
     else if(ch=='L')
     return 50;
     else if(ch=='C')
     return 100;
     else if(ch=='D')
     return 500;
     else if(ch=='M')
     return 1000;
     return -1;
  }
    int romanToDecimal(string &str) {
        // code here
        int n=str.size();
        int ans=0;
        int prev=0;
        for(int i=n-1;i>=0;i--)
        {
           int val=rTD(str[i]);
           if(prev>val)
           ans-=val;
           else
           ans+=val;
           prev=val;
        }
        return ans;
    }
};