/*Problem LeetCode (Medium)

1481. Least Number of Unique Integers after K Removals


Question link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16

Solution link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/submissions/1176927373/?envType=daily-question&envId=2024-02-16


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
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        mp[arr[i]]++;
        vector<int>inp;
        for(auto it:mp)
        inp.push_back(it.second);
        sort(inp.begin(),inp.end());
        int i=0;
        for(;i<inp.size();i++)
        {
            if(k>=inp[i])
            k-=inp[i];
            else
            break;
        }
        return inp.size()-i;
    }
};