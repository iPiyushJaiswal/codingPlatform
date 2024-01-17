/*Problem GFG (Medium)

All Unique Permutations of an array


Question link: https://www.geeksforgeeks.org/problems/all-unique-permutations-of-an-array/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : visited and temp vector.

Time Complexity= O(n*n!)

Space Complexity= O(n*n!) for set and ans vector + O(2n) visited and temp vector.
----------------------------------
Method 2 : Memoization

Time Complexity= O(n*n!)

Space Complexity= O(n*n!) for set and ans vector
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: visited and temp vector.
*/

class Solution {
  public:
    void rec(vector<int> &arr ,int n,int i,set<vector<int>>&st,
    vector<int>&vis,vector<int>&temp)
    {
        if(i==n)
        {
            st.insert(temp);
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(vis[j]!=1)
            {
                vis[j]=1;
                temp.push_back(arr[j]);
                rec(arr,n,i+1,st,vis,temp);
                temp.pop_back();
                vis[j]=0;
            }
        }
        
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        set<vector<int>>st;
        vector<vector<int>>ans;
        vector<int>vis(n,0);
        vector<int>temp;
        rec(arr,n,0,st,vis,temp);
        for(auto it:st)
        ans.push_back(it);
        return ans;
    }
};

/*-----------------------------------------------
Method 2: Swap Funcion
*/

class Solution {
  public:
void rec(int i,int n,vector<int> &arr,set<vector<int>>&st)
{
	if(i==n)
	{
		st.insert(arr);
		return;
	}
	for(int j=i;j<n;j++)
	{
		if(j>i && (arr[i]==arr[j] || arr[j-1]==arr[j]))
		continue;
		swap(arr[i],arr[j]);
		rec(i+1,n,arr,st);
		swap(arr[i],arr[j]);
	}
}
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // code here
        sort(arr.begin(),arr.end());
	set<vector<int>>st;
	vector<vector<int>>ans;
	rec(0,n,arr,st);
	for(auto it:st)
	ans.push_back(it);
	return ans;
    }
};
