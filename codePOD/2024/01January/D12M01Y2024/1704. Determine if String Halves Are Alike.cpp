/*Problem LeetCode (Easy)

1704. Determine if String Halves Are Alike


Question link: https://leetcode.com/problems/determine-if-string-halves-are-alike/

Solution link: https://leetcode.com/problems/determine-if-string-halves-are-alike/submissions/1143913499/


Logic : String

--------------------------
Complexity: 

Method 1: String

Time Complexity=O(n)

Space Complexity=O(1) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: String
*/

class Solution {
public:
int isVowel(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
    ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
    return 1;
    return 0;
}
    bool halvesAreAlike(string s) {
        int n=s.size();
        if(n%2!=0)
        return false;
        int i=0;
        int j=n-1;
        int count1=0;
        int count2=0;
        while(i<j)
        {
            count1+=isVowel(s[i]);
            count2+=isVowel(s[j]);
            i++;
            j--;
        }
        return (count1==count2);
    }
};