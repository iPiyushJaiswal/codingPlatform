/*Problem LeetCode (Hard)

2251. Number of Flowers in Full Bloom


Question link: https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/?envType=daily-question&envId=2023-10-11


Logic: Sweep Line Algo 

-------------------------

Complexity: 

Method 1:  Sweep Line Algo 

Time Complexity=O(nlogn + mlogm)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Sweep Line Algo 
*/

class Solution {
public:
int bs(vector<int>temp,int val)
{
    int low=0;
    int high=temp.size()-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(temp[mid]==val)
        return temp[mid];
        else if(temp[mid]<val)
        low=mid+1;
        else
        high=mid-1;
    }
    return (high>=0)?temp[high]:high;
}
    vector<int> fullBloomFlowers(vector<vector<int>>& flo, vector<int>& people) {
        int n=flo.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[flo[i][0]]++;
            mp[flo[i][1]+1]--;
        }
        vector<int>temp;
        int total=0;
        for(auto it:mp)
        {
            total+=it.second;
            mp[it.first]=total;
            temp.push_back(it.first);
        }
        vector<int>ans;
        int m=people.size();
        for(int i=0;i<m;i++)
        {
            // int day=bs(temp,people[i]);
            auto it = upper_bound(temp.begin(), temp.end(), people[i]);
            int day = distance(temp.begin(), it);
            if(day==0)
            ans.push_back(0);
            else
            ans.push_back(mp[temp[day-1]]);
        }
        return ans;
    }
};