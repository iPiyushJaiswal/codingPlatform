/*Problem LeetCode (Medium)

823. Binary Trees With Factors


Question link: https://leetcode.com/problems/binary-trees-with-factors/description/?envType=daily-question&envId=2023-10-26


Logic: DP + sorting

-------------------------

Complexity: 

Method 1:  DP + sorting

Time Complexity=O(nlogn) + O(n*n)

Space Complexity=O(n) unordered_map

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : DP + sorting
*/

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        int mod=1e9 +7;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]=1;
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0)
                mp[arr[i]]=(mp[arr[i]]+ 1ll*mp[arr[i]/arr[j]]*mp[arr[j]])%mod;
            }    
            ans=(ans+mp[arr[i]])%mod;
        }
        return ans;
    }
};