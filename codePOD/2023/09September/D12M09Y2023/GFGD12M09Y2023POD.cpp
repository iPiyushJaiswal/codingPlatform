/*Problem GFG (Easy)

Perfect Numbers


Question link: https://practice.geeksforgeeks.org/problems/perfect-numbers3207/1

Complexity: 

Method 1: Maths

Time Complexity=O(sqrt(n))

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Recursive + Iterative
*/

class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        if(N==1)
        return 0;
        long long sum=1;
        for(long long i=2;i*i<=N;i++)
        {
            if(N%i==0)
            {
                sum+=i;
                if(N/i!=i)
                sum+=N/i;
            }
        }
        if(sum==N)
        return 1;
        return 0;
    }
};