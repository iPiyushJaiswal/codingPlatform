/*Problem GFG (Easy)

Sum of all divisors from 1 to n


Question link: https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1

---------------------------

Logic: Maths

---------------------------

Complexity: 


Method 1 : Maths

Time Complexity= O(n)

Space Complexity=O(1)  

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1 : Maths
*/

class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        long long ans=0;
        for(int i=1;i<=N;i++)
        ans+=i*(N/i);
        return ans;
    }
};