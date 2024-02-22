/*Problem LeetCode (Medium)

1642. Furthest Building You Can Reach


Question link: https://leetcode.com/problems/furthest-building-you-can-reach/description/?envType=daily-question&envId=2024-02-17

Solution link: https://leetcode.com/problems/furthest-building-you-can-reach/submissions/1177646556/?envType=daily-question&envId=2024-02-17


Logic : Greedy

--------------------------
Complexity: 

Method 1: Greedy

Time Complexity=O(nlogn)

Space Complexity=O(n)  
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Greedy
*/

class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int n=h.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        for(;i<n-1;i++)
        {
            int diff=h[i+1]-h[i];
            if(diff>0)
            {
                pq.push(diff);
                if(pq.size()>l)
                {
                    int valD=pq.top();
                    pq.pop();
                    if(b>=valD)
                    b-=valD;
                    else
                    break;
                }
            }
        }
        return i;
    }
};