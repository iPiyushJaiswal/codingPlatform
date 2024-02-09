/*Problem LeetCode (Medium)

368. Largest Divisible Subset


Question link: https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2024-02-09

Solution link: https://leetcode.com/problems/largest-divisible-subset/submissions/1170349722/?envType=daily-question&envId=2024-02-09


Logic : LIS

--------------------------
Complexity: 

Method 1: Recursion

Time Complexity=O(2^n)

Space Complexity=O(n) recursive stack
--------------------------
Method 2: Longest Increasing SubSequence Variation

Time Complexity=O(n*n)

Space Complexity=O(n) dp vector
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Recursion
*/

class Solution {
public:
    void rec(vector<int>& nums,int i,int n,vector<int>&ans,vector<int>&temp)
    {
        if(i==n)
        {
            if(ans.size()<temp.size())
            ans=temp;
            return;
        }
        if(temp.size()==0 || nums[i]%temp[temp.size()-1]==0 || 
        temp[temp.size()-1]%nums[i]==0)
        {
            temp.push_back(nums[i]);
            rec(nums,i+1,n,ans,temp);
            temp.pop_back();
        }
        // else
        rec(nums,i+1,n,ans,temp);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<int>temp;
        int n=nums.size();
        rec(nums,0,n,ans,temp);
        return ans;
    }
};


/*---------------------------------------------------------------------------------------
Method 2: Longest Increasing SubSequence Variation
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        vector<int>dp(n+1,1);
        vector<int>bT(n);
        int maxi=0;
        int mInd=0;
        for(int i=0;i<n;i++)
        bT[i]=i;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if((nums[i]%nums[j]==0 || nums[j]%nums[i]==0) && dp[i]<1+dp[j])
                {
                    dp[i]=1+dp[j];
                    bT[i]=j;
                }
            }
            if(maxi<dp[i])
            {
                maxi=dp[i];
                mInd=i;
            }
        }
        while(mInd!=bT[mInd])
        {
            ans.push_back(nums[mInd]);
            mInd=bT[mInd];                    
        }
        ans.push_back(nums[mInd]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};