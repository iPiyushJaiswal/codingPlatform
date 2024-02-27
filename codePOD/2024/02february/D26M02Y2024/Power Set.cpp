/*Problem GFG (Medium)

Power Set


Question link:	https://www.geeksforgeeks.org/problems/power-set4302/1

---------------------------

Logic: Backtracking

---------------------------

Complexity: 

Method 1 : Iterative

Time Complexity= O(n*2^n)

Space Complexity= O(n) temp string
----------------------------------
Method 2 : Recursion

Time Complexity= O(2^n)

Space Complexity= O(n) recursive stack
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Iterative
*/


class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n=s.size();
		    vector<string>ans;
		    for(int i=1;i<(1<<n);i++)
		    {
		        string temp;
		        for(int j=0;j<n;j++)
		        {
		            if(i&(1<<j))
		            temp+=s[j];
		        }
		        ans.push_back(temp);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

/*-----------------------------------------------------------------------------------------------
Method 2: Recursive */

class Solution{
	public:
	void rec(string s,int i,int n,vector<string>&ans,string& str)
	{
	    if(i==n)
	    {
	        if(str.size()>0)
	        ans.push_back(str);
	        return;
	    }
	    str.push_back(s[i]);
	    rec(s,i+1,n,ans,str);
	    str.pop_back();
	    rec(s,i+1,n,ans,str);
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n=s.size();
		    vector<string>ans;
		    string str;
		    rec(s,0,n,ans,str);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};