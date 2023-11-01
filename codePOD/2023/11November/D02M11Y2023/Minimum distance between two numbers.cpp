/*Problem GFG (Easy)

Minimum distance between two numbers


Question link: https://www.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/1

---------------------------

Logic: Array

---------------------------

Complexity: 

Method 1 : Array

Time Complexity= O(n).

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Array
*/

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int ind1=-1;
        int ind2=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(a[i]==x)
            ind1=i;
            else if(a[i]==y)
            ind2=i;
            if(ind1!=-1 && ind2!=-1)
            mini=min(mini,abs(ind1-ind2));
        }
        if(mini==INT_MAX)
        return -1;
        return mini;
    }
};