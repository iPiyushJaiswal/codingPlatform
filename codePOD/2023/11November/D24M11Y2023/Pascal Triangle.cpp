/*Problem GFG (Easy)

Pascal Triangle


Question link: https://www.geeksforgeeks.org/problems/pascal-triangle0652/1

---------------------------

Logic: Pascal triangle

---------------------------

Complexity: 

Method 1 : Pascal triangle

Time Complexity= O(n*n))

Space Complexity= O(n)

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Pascal triangle
*/

class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        vector<long long>temp1;
        vector<long long>temp2;
        int mod=1e9 +7;
        for(int i=0;i<n;i++)
        {
            temp2.resize(i+1);
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                temp2[j]=1;
                else
                {
                    temp2[j]=(temp1[j]+temp1[j-1])%mod;
                }
            }
            temp1.resize(i+1);
            temp1=temp2;
        }
        return temp2;
    }
};