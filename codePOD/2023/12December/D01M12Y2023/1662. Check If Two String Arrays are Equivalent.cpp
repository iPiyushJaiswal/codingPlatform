/*Problem LeetCode (Easy)

1662. Check If Two String Arrays are Equivalent


Question link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

Solution link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/submissions/1110122969/


Logic: String

--------------------------

Complexity: 

Method 1: String

Time Complexity=O(n+m)

Space Complexity=O(n) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: String
*/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        string a;
        for(int i=0;i<n;i++)
        a+=word1[i];

        int k=0;
        int x=a.size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<word2[i].size();j++)
            {
                if(k<x && word2[i][j]!=a[k])
                return false;
                k++;
            }
        }
        if(k!=x)
        return false;
        return true;
    }
};