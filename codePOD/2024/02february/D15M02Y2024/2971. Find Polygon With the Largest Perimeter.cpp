/*Problem LeetCode (Medium)

2971. Find Polygon With the Largest Perimeter


Question link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15

Solution link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/submissions/1176042508/?envType=daily-question&envId=2024-02-15


Logic : Greedy

--------------------------
Complexity: 

Method 1: Greedy

Time Complexity=O(nlogn)

Space Complexity=O(1)  
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Greedy
*/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        
        long long ans=-1;

long long sum=nums[0];
        for(int i=1;i<n;i++){
            cout<<sum<<" ";
            if(sum>nums[i])
                {
                ans=sum+nums[i];
            }
       

            sum+=nums[i];

            }
        return ans;
    }
};