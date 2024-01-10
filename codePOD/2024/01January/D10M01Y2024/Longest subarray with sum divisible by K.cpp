/*Problem GFG (Medium)

Longest subarray with sum divisible by K


Question link: https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1

---------------------------

Logic: Array + Unordered_Map + Maths

---------------------------

Complexity: 

Method 1 : Array + Unordered_Map + Maths

Time Complexity= O(n)

Space Complexity= O(n) 
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Array + Unordered_Map + Maths
*/

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int sum=0;
	    unordered_map<int,int>mp;
	    mp[0]=-1;
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	        int rem=sum%k;
	        if(rem < 0) rem += k;
	        if(mp.find(rem)!=mp.end())
	        ans=max(ans,(i-mp[rem]));
	        else
	        mp[rem]=i;
	    }
	    return ans;
	}
};