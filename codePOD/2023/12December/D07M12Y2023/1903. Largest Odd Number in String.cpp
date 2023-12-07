/*Problem LeetCode (Easy)

1903. Largest Odd Number in String


Question link: https://leetcode.com/problems/largest-odd-number-in-string/description/?envType=daily-question&envId=2023-12-07

Solution link: https://leetcode.com/problems/largest-odd-number-in-string/submissions/1114053461/?envType=daily-question&envId=2023-12-07


Logic : Array + Maths

--------------------------

Complexity: 

Method 1: Array + Maths

Time Complexity=O(n)

Space Complexity=O(1)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array + Maths
*/

class Solution {
public:
    string largestOddNumber(string num) {
      int n=num.size();
      string ans;
      for(int i=n-1;i>=0;i--)
      {
        int dig=num[i]-'0';
        if(dig%2!=0)
        {
          ans=num.substr(0,i+1);
          return ans;
        }
      }
      return ans;
    }
};