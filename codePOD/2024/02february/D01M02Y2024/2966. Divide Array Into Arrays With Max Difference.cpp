/*Problem LeetCode (Medium)

2966. Divide Array Into Arrays With Max Difference


Question link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/?envType=daily-question&envId=2024-02-01

Solution link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/submissions/1162741757/?envType=daily-question&envId=2024-02-01


Logic : Sorting

--------------------------
Complexity: 

Method 1: Sorting

Time Complexity=O(nlogn)

Space Complexity=O(3) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Sorting
*/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        int n=nums.size();
        if(n%3!=0)
        return ans;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;)
        {
            vector<int>temp;
            if(nums[i+2]-nums[i]>k)
            return {};
            int j=0;
            while(j<3)
            {
                temp.push_back(nums[i]);
                j++;
                i++;
            }   
            ans.push_back(temp);            
        }
        return ans;
    }
};