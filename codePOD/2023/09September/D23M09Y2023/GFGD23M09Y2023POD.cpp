/*Problem GFG (Easy)

Equilibrium Point


Question link: https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1

---------------------------

Logic: Prefix-Suffix Sum

---------------------------

Complexity: 

Method 1: Prefix-Suffix Sum

Time Complexity=O(2*n)

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Prefix-Suffix Sum
*/

class Solution{
    public:
    int equilibriumPoint(long long a[], int n) {
        // Your code here
    long long sum1=0;
    long long sum2=0;
    for(int i=n-1;i>=0;i--)
    sum2+=a[i];
    for(int i=0;i<n;i++)
    {
        sum2-=a[i];
        if(sum1==sum2)
        return i+1;
        sum1+=a[i];
    }
    return -1;
    }
};