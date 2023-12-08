/*Problem GFG (Medium)

Transform to prime


Question link: https://www.geeksforgeeks.org/problems/transform-to-prime4635/1

---------------------------

Logic: Prime

---------------------------

Complexity: 

Method 1 : Prime

Time Complexity= O(1e6*1e3)

Space Complexity= O(1)

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Prime
*/

class Solution
{
    public:
    bool isPrime(int temp)
    {
        for(int i=2;i<sqrt(temp)+1;i++)
        {
            if(temp%i==0)
            return false;
        }
        return true;
    }
    int minNumber(int arr[],int N)
    {
        long long sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        int ans=0;
        for(int i=0;i<1000000;i++)
        {
            if(isPrime(sum+i))
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};