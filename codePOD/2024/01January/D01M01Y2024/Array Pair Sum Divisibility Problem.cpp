/*Problem GFG (Medium)

Array Pair Sum Divisibility Problem


Question link: https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

---------------------------

Logic: HashMap

---------------------------

Complexity: 

Method 1 : HashMap

Time Complexity= O(n)

Space Complexity= O(n) Unordered_map
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: HashMap
*/

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();
        if(n%2!=0)
        return false;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[nums[i]%k]++;
        for(auto it:mp)
        {
            int val=k-it.first;
            if(it.first==0)
            continue;
            if(mp[val]!=mp[it.first])
            return false;
        }
        return true;
    }