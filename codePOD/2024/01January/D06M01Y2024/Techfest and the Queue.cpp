/*Problem GFG (Medium)

Techfest and the Queue


Question link: https://www.geeksforgeeks.org/problems/techfest-and-the-queue1044/1

---------------------------

Logic: Sieve of Eratosthenes

---------------------------

Complexity: 

Method 1 : Sieve of Eratosthenes

Time Complexity= O(blogb)

Space Complexity= O(b) Sieve Vector
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Sieve of Eratosthenes
*/

class Solution {
public:
    void sieve(vector<int>&sie)
    {
        int n=sie.size();
        for(int i=0;i<n;i++)
        sie[i]=i;
        for(int i=2;i*i<n;i++)
        {
            if(sie[i]==i)
            {
                for(int j=i;j*i<n;j++)
                {
                    sie[i*j]=i;
                }
            }
        }
    }
	int sumOfPowers(int a, int b){
	    // Code here
	    vector<int>sie(b+1);
	    sieve(sie);
	    int ans=0;
	    int x=a;
	    while(x<=b)
	    {
	        int val=x;
	        while(val!=1)
	        {
	            int d=sie[val];
	            ans++;
	            val/=d;
	        }
	        x++;
	    }
	    return ans;
	}
};