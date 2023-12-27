/*Problem LeetCode (Medium)

1578. Minimum Time to Make Rope Colorful


Question link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/?envType=daily-question&envId=2023-12-27

Solution link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/submissions/1129391040/?envType=daily-question&envId=2023-12-27


Logic : Array

--------------------------
Complexity: 

Method 1: Array

Time Complexity=O(n)

Space Complexity=O(1)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Array
*/

class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n=time.size();
        int count=0,ans=0,maxi=0;
        for(int i=1;i<n;i++)
        {
            if(colors[i]==colors[i-1])
            {
                count+=time[i-1];
                maxi=max(maxi,time[i-1]);
            }
            while(i<n && colors[i]==colors[i-1])
            {
                count+=time[i];
                maxi=max(maxi,time[i]);
                i++;
            }
            ans+=count-maxi;
            count=0;
            maxi=0;
        }
        return ans;
    }
};