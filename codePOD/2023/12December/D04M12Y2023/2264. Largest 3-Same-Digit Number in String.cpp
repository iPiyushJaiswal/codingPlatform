/*Problem LeetCode (Easy)

2264. Largest 3-Same-Digit Number in String


Question link: https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/?envType=daily-question&envId=2023-12-04

Solution link: https://leetcode.com/problems/largest-3-same-digit-number-in-string/submissions/1111973481/?envType=daily-question&envId=2023-12-04


Logic: Array

--------------------------

Complexity: 

Method 1: Array

Time Complexity=O(n)

Space Complexity=O(1)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array
*/

class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int ans=-1;
        int val=INT_MIN;
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(num[i]==num[i-1])
            {
                val=num[i]-'0';
                count++;
            }
            else
            count=1;
            if(count>=3)
            ans=max(ans,val);
        }
        if(ans==-1)
        return "";
        string res;
        res.push_back(ans+'0');
        res.push_back(ans+'0');
        res.push_back(ans+'0');
        return res;
    }
};