/*Problem GFG (Easy)

Reach the Nth point


Question link: https://www.geeksforgeeks.org/problems/reach-the-nth-point5433/1

---------------------------

Logic: DP

---------------------------

Complexity: 

Method 1 : DP

Time Complexity= O(n)

Space Complexity= O(1)

----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: DP
*/

class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    int mod=1e9 +7;
		    int n1=1;
		    if(n==1)
		    return n1;
		    int n2=2;
		    if(n==2)
		    return n2;
		    for(int i=3;i<=n;i++)
		    {
		        int curr=(n1+n2)%mod;
		        n1=n2;
		        n2=curr;
		    }
		    return n2;
		    
		}
};