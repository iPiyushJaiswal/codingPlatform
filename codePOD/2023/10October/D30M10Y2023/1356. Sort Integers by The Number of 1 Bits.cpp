/*Problem LeetCode (Easy)

1356. Sort Integers by The Number of 1 Bits


Question link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/?envType=daily-question&envId=2023-10-30


Logic: sorting + Map

-------------------------

Complexity: 

Method 1:  sorting + Map

Time Complexity=O(n*32) + O(nlogn)

Space Complexity=O(n) Map

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : sorting + Map
*/

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int val=arr[i];
            int count=0;
            while(val>0)
            {
                if(val%2!=0)
                count++;
                val/=2;
            }
            mp[count].push_back(arr[i]);
        }
        vector<int>ans;
        for(auto it:mp)
        {
            for(int i=0;i<it.second.size();i++)
            {
                ans.push_back(it.second[i]);
            }
        }
        return ans;
    }
};