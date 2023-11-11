/*Problem GFG (Medium)

Isomorphic Strings


Question link: https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

---------------------------

Logic: Map

---------------------------

Complexity: 

Method  : map

Time Complexity= O(n)

Space Complexity=O(26)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Map
*/

class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        int n1=str1.size();
        int n2=str2.size();
        if(n1!=n2)
        return false;
        unordered_map<char,char>mp;
        unordered_map<char,int>vis;
        for(int i=0;i<n1;i++)
        {
            if(mp.find(str1[i])==mp.end())
            {
                if(vis[str2[i]]==1)
                return false;
                mp.insert({str1[i],str2[i]});
                vis[str2[i]]++;
            }
            else
            {
                if(mp[str1[i]]!=str2[i])
                return false;
            }
        }
        return true;
    }
};