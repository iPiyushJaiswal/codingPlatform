/*Problem GFG (Easy)

Smallest window containing 0, 1 and 2


Question link: https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1

---------------------------

Logic: String + Sliding Window

---------------------------

Complexity: 

Method 1 : String + Sliding Window

Time Complexity= O(n)

Space Complexity= O(1)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: String + Sliding Window
*/

class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        vector<int>temp(3,INT_MAX);
        int ans=INT_MAX;
        int n=s.size();
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            temp[s[i]-'0']=i;
            maxi=i;
            mini=min(temp[0],min(temp[1],temp[2]));
            if(temp[0]!=INT_MAX && temp[1]!=INT_MAX && 
            temp[2]!=INT_MAX)
            ans=min(ans,maxi-mini+1);
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
    }
};