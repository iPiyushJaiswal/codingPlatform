/*Problem LeetCode (Easy)

1422. Maximum Score After Splitting a String


Question link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2023-12-22

Solution link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/submissions/1125648182/?envType=daily-question&envId=2023-12-22


Logic : 2 Pointers

--------------------------
Complexity: 

Method 1: 2 Pointers

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
    int maxScore(string s) {
        int n=s.size();
        int count1=0;
        for(int i=0;i<n;i++)
        count1+=s[i]-'0';
        int maxi=0;
        int count0=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
            count0++;
            count1-=s[i]-'0';
            maxi=max(maxi,count0+count1);
        }
        return maxi;
    }
};