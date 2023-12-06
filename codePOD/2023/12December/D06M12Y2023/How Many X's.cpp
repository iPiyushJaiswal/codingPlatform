/*Problem GFG (Medium)

How Many X's?


Question link: https://www.geeksforgeeks.org/problems/how-many-xs4514/1

---------------------------

Logic: Array

---------------------------

Complexity: 

Method 1 : Array

Time Complexity= O(nlogn)

Space Complexity= O(1)

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array
*/

class Solution {
  public:
    int findVal(int i,int x)
    {
        int cal=0;
        while(i>0)
        {
            if(i%10==x)
            cal++;
            i/=10;
        }
        return cal;
    }
    int countX(int L, int R, int X) {
        // code here
        int ans=0;
        for(int i=L+1;i<R;i++)
        {
            ans+=findVal(i,X);
        }
        return ans;
    }
};