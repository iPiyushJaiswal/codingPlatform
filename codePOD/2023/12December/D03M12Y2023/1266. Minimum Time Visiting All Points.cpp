/*Problem LeetCode (Easy)

1266. Minimum Time Visiting All Points


Question link: https://leetcode.com/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2023-12-03

Solution link: https://leetcode.com/problems/minimum-time-visiting-all-points/submissions/1111357560/?envType=daily-question&envId=2023-12-03


Logic: Maths

--------------------------

Complexity: 

Method 1: Maths

Time Complexity=O(n)

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
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        for(int i=1;i<n;i++)
        {
            int x=abs(points[i][0]-points[i-1][0]);
            int y=abs(points[i][1]-points[i-1][1]);
            ans+=max(x,y);
        }
        return ans;
    }
};