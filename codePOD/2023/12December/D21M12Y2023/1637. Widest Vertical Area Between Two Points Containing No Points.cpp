/*Problem LeetCode (Medium)

1637. Widest Vertical Area Between Two Points Containing No Points


Question link: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=daily-question&envId=2023-12-21

Solution link: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/submissions/1124753879/?envType=daily-question&envId=2023-12-21


Logic : Sorting

--------------------------
Complexity: 

Method 1: Sorting

Time Complexity=O(nlogn)

Space Complexity=O(1)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Sorting
*/

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int maxi=0;
        int n=points.size();
        for(int i=1;i<n;i++)
        maxi=max(maxi,points[i][0]-points[i-1][0]);
        return maxi;
    }
};