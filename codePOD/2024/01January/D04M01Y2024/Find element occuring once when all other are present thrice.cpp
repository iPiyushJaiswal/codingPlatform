/*Problem GFG (Medium)

Find element occuring once when all other are present thrice


Question link: https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1

---------------------------

Logic: Bit Manipulation

---------------------------

Complexity: 

Method 1 : Bit Manipulation

Time Complexity= O(n)

Space Complexity= O(1)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Bit Manipulation
*/

class Solution {
  public:
    int singleElement(int arr[] ,int n) {
        // code here
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(((arr[j]>>i)&1)==1)
                count++;
            }
            if(count%3!=0)
            ans+=(1<<i);
        }
        return ans;
    }
};