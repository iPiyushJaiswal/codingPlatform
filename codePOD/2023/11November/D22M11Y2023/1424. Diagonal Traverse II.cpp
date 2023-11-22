/*Problem LeetCode (Medium)

1424. Diagonal Traverse II


Question link: https://leetcode.com/problems/diagonal-traverse-ii/solutions/?envType=daily-question&envId=2023-11-22


Logic: 2 approach

--------------------------

Complexity: 

Method 1: map

Time Complexity=O(n*m*logn)

Space Complexity=O(n*m)

--------------------------
Method 2: Matrix vector

Time Complexity=O(n*m)

Space Complexity=O(n*m)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: map
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,vector<int>>mp;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        for(auto it: mp)
        {
            reverse(it.second.begin(),it.second.end());
            for(int i=0;i<it.second.size();i++)
            ans.push_back(it.second[i]);
            cout<<endl;
        }
        return ans;
    }
};

/*-----------------------------------------------------------
Method 2: Matrix vector
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<vector<int>>temp;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                if(temp.size()<=i+j)
                temp.push_back(vector<int>());
                temp[i+j].push_back(nums[i][j]);
            }
        }
        for(int i=0;i<temp.size();i++)
        {
            reverse(temp[i].begin(),temp[i].end());
            for(int j=0;j<temp[i].size();j++)
            ans.push_back(temp[i][j]);
        }
        return ans;
    }
};