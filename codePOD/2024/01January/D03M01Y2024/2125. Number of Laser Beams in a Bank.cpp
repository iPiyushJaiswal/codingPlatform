/*Problem LeetCode (Medium)

2125. Number of Laser Beams in a Bank


Question link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2024-01-03

Solution link: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/submissions/1135296594/?envType=daily-question&envId=2024-01-03


Logic : Matrix + Maths

--------------------------
Complexity: 

Method 1: Matrix + Maths

Time Complexity=O(n*m)

Space Complexity=O(1) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Matrix + Maths
*/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int m=bank[0].size();
        int ans=0;
        int countPrev=0;
        int countCurr=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(bank[i][j]=='1')
                countCurr++;
            }
                if(countCurr!=0)
                {
                    ans+=countPrev*countCurr;
                    countPrev=(countCurr==0)?countPrev:countCurr;
                    countCurr=0;
                }
        }
        return ans;
    }
};