/*Problem LeetCode (Medium)

1685. Sum of Absolute Differences in a Sorted Array


Question link: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/description/?envType=daily-question&envId=2023-11-25

Solution link: https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/submissions/1105926250/?envType=daily-question&envId=2023-11-25


Logic: 2 approaches

--------------------------

Complexity: 

Method 1: (Prefex +sufix)array + Maths

Time Complexity=O(3n)

Space Complexity=O(2n)

--------------------------
Method 2: (Prefex +sufix)2 pointer + Maths

Time Complexity=O(2n)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: (Prefex +sufix)array + Maths
*/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int>pref(n,0);
        vector<int>suf(n,0);
        // pref[0]=nums[0];
        // suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++)
        pref[i]=pref[i-1]+nums[i-1];
        for(int i=n-2;i>=0;i--)
        suf[i]=suf[i+1]+nums[i+1];

        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]=nums[i]*i - pref[i] -nums[i]*(n-i-1) +suf[i]; 
        }
        return ans;
    }
};

/*-----------------------------------------------------------
Method 2: (Prefex +sufix)2 pointer + Maths 
*/

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int right=0;
        for(int i=0;i<n;i++)
        right+=nums[i];
        int left=0;

        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            right-=nums[i];
            ans[i]=nums[i]*i -left -nums[i]*(n-i-1) +right;
            left+=nums[i];
        }
        return ans;
    }
};