/*Problem LeetCode (Medium)

1921. Eliminate Maximum Number of Monsters


Question link: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/?envType=daily-question&envId=2023-11-07


Logic: Min Heap : Maths + Counting Sort

--------------------------

Complexity: 

Method 1: Min Heap

Time Complexity=O(nlogn)

Space Complexity=O(n)

--------------------------
Method 2: Maths + Counting Sort

Time Complexity=O(n)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Min Heap
*/

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        priority_queue<double,vector<double>,greater<double>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(1.0*dist[i]/speed[i]*1.0);
        }
        int count=0;
        int initial=0;
        while(!pq.empty())
        {
            if(pq.top()<=initial)
            break;
            initial++;
            pq.pop();
            count++;
        }
        return count;
    }
};

/*-------------------------------------------------------------------------------------
Method 2: Maths + Counting Sort
*/

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        for(int i=0;i<n;i++)
        {
            dist[i]=ceil((double)dist[i]/speed[i]);
            speed[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            if(dist[i]>=n)
            continue;
            speed[dist[i]]++;
        }
        for(int i=1;i<n;i++)
        {
            speed[i]+=speed[i-1];
            if(speed[i]>i)
            return i;
        }
        return n;
    }
};