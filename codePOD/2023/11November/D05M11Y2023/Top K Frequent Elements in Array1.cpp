/*Problem GFG (Easy)

Top K Frequent Elements in Array - |


Question link: https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1

---------------------------

Logic: priority_queue + unordered_map

---------------------------

Complexity: 

Method 1 : priority_queue + unordered_map

Time Complexity= O(nlogn).

Space Complexity=O(n)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: priority_queue + unordered_map
*/

class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto it:mp)
        pq.push({it.second,it.first});
        vector<int>ans;
        while(k>0 && !pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};