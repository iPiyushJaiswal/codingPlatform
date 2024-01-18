/*Problem GFG (Medium)

Water the plants


Question link: https://www.geeksforgeeks.org/problems/water-the-plants--170646/1

---------------------------

Logic: sorting + greedy

---------------------------

Complexity: 

Method 1 : sorting + greedy

Time Complexity= O(nlogn)

Space Complexity= O(n) vector.
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: sorting + greedy
*/

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++)
        {
            if(gallery[i]==-1)
            continue;
            int a=max(0,i-gallery[i]);
            int b=min(n-1,i+gallery[i]);
            temp.push_back({a,b});
        }
        sort(temp.begin(),temp.end());
        int i=0;
        int ans=0;
        int maxi=0;
        int prevM=0;
        int x=temp.size();
        while(maxi<n)
        {
            // ans++;
            while(i<x && temp[i].first<=maxi)
            {
                prevM=max(prevM,temp[i].second);
                i++;
            }
            if(maxi<=prevM)
            {
                maxi=prevM+1;
                ans++;
            }
            else
            {
                return -1;
            }
        }
        // if(ans==0)
        // return -1;
        return ans;
    }
};
