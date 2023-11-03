/*Problem GFG (Medium)

Pythagorean Triplet


Question link: https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1

---------------------------

Logic: Array

---------------------------

Complexity: 

Method 1 : 2 pointer

Time Complexity= O(n*n).

Space Complexity=O(1)

-----------------------------
Method 2 : Maths + unordered_map

Time Complexity= O(n + maxi*maxi).

Space Complexity=O(maxi)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 2 pointer
*/

class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    sort(arr,arr+n);
	    for(int i=n-1;i>=2;i--)
	    {
	        int j=0,k=i-1;
	        int c=pow(arr[i],2);
	        while(j<k)
	        {
	            int a=pow(arr[j],2);
	            int b=pow(arr[k],2);
	            if((a+b)==c)
	            return true;
	            else if((a+b)<c)
	            j++;
	            else
	            k--;
	        }
	    }
	    return false;
	}
};

/*--------------------------------------------------------
Method 2: Maths + unordered_map
*/

class Solution{
public:
	// Function to check if the
	// Pythagorean triplet exists or not
	bool checkTriplet(int arr[], int n) {
	    // code here
	    int maxi=0;
	    for(int i=0;i<n;i++)
	    maxi=max(maxi,arr[i]);
	    unordered_map<int,int>mp;
	    for(int i=0;i<n;i++)
	    mp[arr[i]]++;
	    for(int i=1;i<=maxi;i++)
	    {
	        if(mp.find(i)==mp.end())
	        continue;
	        for(int j=1;j<=maxi;j++)
	        {
	            if(mp.find(j)==mp.end() || i==j)
	            continue;
	            int a=i*i + j*j;
	            int val=sqrt(a);
	            if((val*val)==a && mp.find(val)!=mp.end())
	            return true;
	        }
	    }
	    return false;
	}
};





