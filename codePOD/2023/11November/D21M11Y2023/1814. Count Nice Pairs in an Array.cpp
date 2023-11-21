/*Problem LeetCode (Medium)

1814. Count Nice Pairs in an Array


Question link: https://leetcode.com/problems/count-nice-pairs-in-an-array/description/?envType=daily-question&envId=2023-11-21


Logic: 1 approach

--------------------------

Complexity: 

Method 1: unordered_map + sum find in array

Time Complexity=O(n*9)

Space Complexity=O(n)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: unordered_map + sum find in array
*/

class Solution {
public:
int rev(int x)
{
    int val=0;
    while(x>0)
    {
        val=val*10 + x%10;
        x/=10;
    }
    return val;
}
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int mod=1e9 +7;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int r=rev(nums[i]);
            int f=nums[i]-r;
            if(mp.find(f)!=mp.end())
            ans=(ans+mp[f])%mod;
            mp[f]=(mp[f]+1)%mod;
        }
        return ans;
    }
};