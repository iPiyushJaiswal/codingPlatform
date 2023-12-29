/*Problem GFG (Easy)

Winner of an election


Question link: https://www.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1

---------------------------

Logic: unordered_map

---------------------------

Complexity: 

Method 1 : unordered_map

Time Complexity= O(n)

Space Complexity= O(n)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: unordered_map
*/

class Solution{
  public:
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int>mp;
        int maxi=0;
        string ans;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
            if(mp[arr[i]]>maxi)
            {
                maxi=mp[arr[i]];
                ans=arr[i];
            }
            else if(mp[arr[i]]==maxi && arr[i]<ans)
            ans=arr[i];
        }
        return {ans,to_string(maxi)};
    }
};