/*Problem LeetCode (Easy)

844. Backspace String Compare


Question link: https://leetcode.com/problems/backspace-string-compare/description/?envType=daily-question&envId=2023-10-19


Logic: String

-------------------------

Complexity: 

Method 1:  Better

Time Complexity=O(n+m)

Space Complexity=O(n+m) string

--------------------------
Method 2:  Optimized

Time Complexity=O(n+m)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Better
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="",t1="";
        int n=s.size();
        int m=t.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='#')
            {
                if(s1.size()>0)
                s1.pop_back();
            }
            else
            s1.push_back(s[i]);            
        }
        for(int i=0;i<m;i++)
        {
            if(t[i]=='#')
            {
                if(t1.size()>0)
                t1.pop_back();
            }
            else
            t1.push_back(t[i]);            
        }
        return (s1==t1);
    }
};

/* ---------------------------------------------
Method 2: Optimized
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1;
        int j=t.size()-1;
        
        while(true)
        {
            int steps=0;
            while(i>=0 &&  (steps>0 || s[i]=='#'))
            {
                steps+=s[i]=='#'?1:-1;
                i--;
            }
            steps=0;
            while(j>=0 &&  (steps>0 || t[j]=='#'))
            {
                steps+=t[j]=='#'?1:-1;
                j--;
            }
            if(i>=0 && j>=0 && s[i]==t[j])
            {
                i--;
                j--;
            }
            else
            break;
        }
        return (i<0 && j<0);
    }
};