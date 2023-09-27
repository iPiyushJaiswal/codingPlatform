/*Problem LeetCode (Medium)

880. Decoded String at Index


Question link: https://leetcode.com/problems/decoded-string-at-index/description/?envType=daily-question&envId=2023-09-27

Logic: Maths

-------------------------

Complexity: 

Method 1:  Maths

Time Complexity=O(2n)

Space Complexity=O(1) 

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Maths
*/

class Solution {
public:
    bool isDigit(char ch)
    {
        if(ch>='0' && ch<='9')
        return true;
        return false;
    }
    string decodeAtIndex(string s, int k) {
        int n=s.size();
        long long ind=0;
        for(int i=0;i<n;i++)
        ind=(isDigit(s[i]))?ind*(s[i]-'0'):ind+1;
        string ans;
        // cout<<ind;
        for(int i=n-1;i>=0;i--)
        {
            k=k%ind;
            if(k==0 && !isDigit(s[i]))
            {
                ans.push_back(s[i]);
                return ans;
            }
            if(!isDigit(s[i]))
            ind--;
            else
            ind=ind/(s[i]-'0');
        }
        return ans;
    }
};