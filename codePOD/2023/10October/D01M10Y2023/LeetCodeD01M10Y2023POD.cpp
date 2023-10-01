/*Problem LeetCode (Easy)

557. Reverse Words in a String III


Question link: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/?envType=daily-question&envId=2023-10-01

Logic: 2 Pointers

-------------------------

Complexity: 

Method 1:  2 Pointers

Time Complexity=O(2n)

Space Complexity=O(1) 

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 2 Pointers
*/

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=-1;
        for(int j=0;j<=n;j++)
        {
            if(j==n || s[j]==' ')
            {
                int k=j-1;
                i++;
                while(i<k)
                {
                    swap(s[i],s[k]);
                    i++;
                    k--;
                }
                i=j;
            }
        }
        return s;
    }
};