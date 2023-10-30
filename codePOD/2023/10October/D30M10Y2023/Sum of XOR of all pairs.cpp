/*Problem GFG (Medium)

Sum of XOR of all pairs


Question link: https://practice.geeksforgeeks.org/problems/sum-of-xor-of-all-pairs0723/1

---------------------------

Logic: Bit Manipulation

---------------------------

Complexity: 

Method 1 : Bit Manipulation

Time Complexity= O(n*32).

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Bit Manipulation
*/

class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	long long int ans=0;
    	for(int i=0;i<32;i++)
    	{
    	    long long int countSet=0;
    	    for(int j=0;j<n;j++)
    	    {
    	        int bitV=((arr[j]>>i)&1);
    	        if(bitV==1)
    	        countSet++;
    	    }
    	    ans+=(1<<i)*countSet*(n-countSet);
    	}
    	return ans;
    }
};