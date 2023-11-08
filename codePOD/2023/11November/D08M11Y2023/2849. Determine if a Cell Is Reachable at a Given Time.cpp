/*Problem LeetCode (Medium)

2849. Determine if a Cell Is Reachable at a Given Time


Question link: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/


Logic: Maths

--------------------------

Complexity: 

Method 1: Maths

Time Complexity=O(1)

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
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int difY=abs(fy-sy);
        int difX=abs(fx-sx);
        int a=min(difY,difX);
        int b;
        if(difY==a)
        b=difX-a;
        else
        b=difY-a;
        int mini=a+b;
        // int maxi=difY+difX;
        if(mini==0 && t==1)
        return false;
        if(mini<=t)
        return true;
        return false;
    }
};