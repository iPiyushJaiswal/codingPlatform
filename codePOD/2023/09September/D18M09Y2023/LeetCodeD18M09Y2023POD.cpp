/*Problem LeetCode (Easy)

1337. The K Weakest Rows in a Matrix


Question link: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/?envType=daily-question&envId=2023-09-18


Logic: Priority_Queue + Binary Search

-------------------------

Complexity: 

Method 1: Priority_Queue + Binary Search

Time Complexity=O(m*log(n))BS+ O(m*log(k))PQ

Space Complexity=O(k) Priority_Queue

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Priority_Queue + Binary Search
*/

class Solution {
public:
int bS(vector<vector<int>>& mat,int low,int high,int i)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(mat[i][mid]>=1)
        low=mid+1;
        else
        high=mid-1;
    }
    return low;
}
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<m;i++)
        {
            int val=bS(mat,0,n-1,i);
            if(pq.size()<k)
            pq.push({val,i});
            else if(pq.top().first>val)
            {
                pq.pop();
                pq.push({val,i});
            }
        }
        vector<int>ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};