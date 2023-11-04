/*Problem LeetCode (Medium)

1503. Last Moment Before All Ants Fall Out of a Plank


Question link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/description/?envType=daily-question&envId=2023-11-04


Logic: Array Traversal

--------------------------

Complexity: 

Method : Array Traversal

Time Complexity=O(x1 + x2)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Array Traversal
*/

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int x1=left.size();
        int x2=right.size();
        int mini=INT_MAX;
        for(int i=0;i<x2;i++)
        {
            mini=min(mini,right[i]);
        }
        int maxi=INT_MIN;
        for(int i=0;i<x1;i++)
        {
            maxi=max(maxi,left[i]);
        }
        int ans=0;
        if(mini!=INT_MAX)
        ans=max(ans,abs(n-mini));
        if(maxi!=INT_MIN)
        ans=max(ans,maxi);
        return ans;
    }
};