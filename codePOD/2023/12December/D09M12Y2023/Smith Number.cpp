/*Problem GFG (Medium)

Smith Number


Question link: https://www.geeksforgeeks.org/problems/smith-number4132/1

---------------------------

Logic: Prime + Sieve

---------------------------

Complexity: 

Method 1 : Prime + Sieve

Time Complexity= O(nlogn)

Space Complexity= O(n)

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Prime + Sieve
*/

class Solution {
  public:
    int sumDig(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum+=n%10;
            n/=10;
        }
      return sum;
    }
    int fact(int n)
    {
        vector<int>sie(n+1,0);
        sie[0]=1;
        sie[1]=1;
        for(int i=2;i*i<=n;i++)
        {
            if(sie[i]==0)
            {
                for(int j=i*i;j<=n;j+=i)
                sie[j]=1;
            }
        }
        if(sie[n]==0)
        return -1;
        int sum=0;
        for(int i=2;i<=n;i++)
        {
            if(n%i==0 && sie[i]==0)
            {
                int s=sumDig(i);
                while(n%i==0)
                {
                    sum+=s;
                    n/=i;
                }
            }
        }
        return sum;
    }
    int smithNum(int n) {
        // code here
        return (sumDig(n)==fact(n));
    }
};