/*Problem LeetCode (Easy)

997. Find the Town Judge


Question link: https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22

Solution link: https://leetcode.com/problems/find-the-town-judge/submissions/1182570749/?envType=daily-question&envId=2024-02-22


Logic : Array

--------------------------
Complexity: 

Method 1: Array

Time Complexity=O(m + n)

Space Complexity=O(n)  
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>deg(n+1,0);
        int ans=-1;
        int m=trust.size();
        for(int i=0;i<m;i++)
        {
            deg[trust[i][0]]--;
            deg[trust[i][1]]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(deg[i]==n-1)
            ans=i;
        }
        return ans;
    }
};