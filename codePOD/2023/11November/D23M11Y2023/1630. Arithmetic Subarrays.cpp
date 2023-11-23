/*Problem LeetCode (Medium)

1630. Arithmetic Subarrays


Question link: https://leetcode.com/problems/arithmetic-subarrays/description/?envType=daily-question&envId=2023-11-23


Logic: 2 approach

--------------------------

Complexity: 

Method 1: sorting

Time Complexity=O(n*m*logn)

Space Complexity=O(n*m)

--------------------------
Method 2: Set

Time Complexity=O(n*m)

Space Complexity=O(n*m)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: sorting
*/

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        int n=l.size();
        int m=nums.size();
        int i=0;
        while(i<n)
        {
            int low=l[i];
            int high=r[i];
            priority_queue<int,vector<int>,greater<int>>pq;
            while(low<=high && low<m)
            {
                pq.push(nums[low]);
                low++;
            }
            int prev=INT_MIN;
            int diff=INT_MIN;
            bool flag=1;
            while(!pq.empty())
            {
                if(prev==INT_MIN)
                {
                    prev=pq.top();
                    pq.pop();
                    continue;
                }
                if(diff==INT_MIN)
                {
                    diff=pq.top()-prev;
                    prev=pq.top();
                    pq.pop();
                    continue;
                }
                if(diff!=(pq.top()-prev))
                {
                    flag=0;
                    break;
                }
                else
                {
                    diff=pq.top()-prev;
                    prev=pq.top();
                    pq.pop();
                }
            }
            ans.push_back(flag);
            i++;
        }    
        return ans;    
    }
};

/*-----------------------------------------------------------
Method 2: Set
*/

class Solution {
public:
void findMin(vector<int>&nums,int low,int high,int &mini,int &maxi)
{
    int x=nums.size();
    while(low<=high && low<x)
    {
        mini=min(mini,nums[low]);
        maxi=max(maxi,nums[low]);
        low++;
    }
}
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n=l.size();
        int m=nums.size();
        vector<bool>ans;

        for(int i=0;i<n;i++)
        {
            int low=l[i];
            int high=r[i];
            int mini=INT_MAX,maxi=INT_MIN;
            findMin(nums,low,high,mini,maxi);
            if((maxi-mini)%(high-low)!=0)
            {
                ans.push_back(false);
                continue;
            }
            int d=(maxi-mini)/(high-low);
            int count=high-low;
            int nxt=mini;
            unordered_set<int>st;
            while(low<=high && low<m)
            {
                st.insert(nums[low]);
                low++;
            }
            bool flag=1;
            while(count>0)
            {
                nxt+=d;
                if(st.find(nxt)==st.end())
                    {
                        flag=0;
                        break;
                    }
                    count--;
            }
            ans.push_back(flag);
        }
        return ans;
    }
};