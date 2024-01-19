/*Problem GFG (Medium)

Top k numbers in a stream


Question link: https://www.geeksforgeeks.org/problems/top-k-numbers3425/1

---------------------------

Logic: Map + set

---------------------------

Complexity: 

Method 1 : Map + set

Time Complexity= O(n*k + nlogk)

Space Complexity= O(n) map.
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Map + set
*/

class Solution {
  public:
  class cmp{
    public:
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
        if(a.first==b.first)
        return a.second<b.second;
        return a.first>b.first;
    }
  };
    vector<vector<int>> kTop(vector<int>& arr, int n, int k) {
        // code here
        set<pair<int,int>,cmp>st;
        unordered_map<int,int>mp;
        vector<vector<int>>ans;
        int count=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            continue;
            int temp=mp[arr[i]];
            mp[arr[i]]++;
            if(!st.empty() && st.find({temp,arr[i]})==st.end())
            {
                int flag=0;
                auto it=prev(st.end());
                if(st.size()>=k)
                {
                    if(it->first<=mp[arr[i]])
                    st.erase(it);
                    else
                    flag=1;
                }
                if(flag==0)
                st.insert({mp[arr[i]],arr[i]});
            }
            else
            {
                st.insert({mp[arr[i]],arr[i]});
                st.erase({temp,arr[i]});
            }
            vector<int>x;
            for(auto it:st)
            x.push_back(it.second);
            ans.push_back(x);
        }
        return ans;
    }
};