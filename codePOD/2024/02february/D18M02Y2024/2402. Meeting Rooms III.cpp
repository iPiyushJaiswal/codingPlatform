/*Problem LeetCode (Hard)

2402. Meeting Rooms III


Question link: https://leetcode.com/problems/meeting-rooms-iii/description/?envType=daily-question&envId=2024-02-18

Solution link: https://leetcode.com/problems/meeting-rooms-iii/submissions/1178637121/?envType=daily-question&envId=2024-02-18


Logic : Heap

--------------------------
Complexity: 

Method 1: Heap

Time Complexity=O(nlogn)

Space Complexity=O(1)  
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Heap
*/

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        sort(m.begin(),m.end());
        int r=m.size();
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        priority_queue<int,vector<int>,greater<int>>eq;
        vector<int>count(n,0);
        for(int i=0;i<n;i++)
        eq.push(i);
        for(int i=0;i<r;i++)
        {
            while(!pq.empty() && pq.top().first<m[i][0])
            {
                eq.push(pq.top().second);
                pq.pop();
            }
            if(pq.empty() || (pq.top().first>m[i][0] && pq.size()<n))
            {
                pq.push({m[i][1],eq.top()});
                count[eq.top()]++;
                eq.pop();
            }
            else
            {
                auto it=pq.top();
                pq.pop();
                long long start=max(it.first,(long long)m[i][0]);
                long long diff=m[i][1]-m[i][0];
                eq.push(it.second);
                pq.push({start+diff,eq.top()});
                count[eq.top()]++;
                eq.pop();
            }
        }
        long long ans=-1;
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(maxi<count[i])
            {
                ans=i;
                maxi=count[i];
            }
        }
        return ans;
    }
};