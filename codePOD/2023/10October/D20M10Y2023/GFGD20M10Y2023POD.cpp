/*Problem GFG (Easy)

Form a number divisible by 3 using array digits


Question link: https://practice.geeksforgeeks.org/problems/form-a-number-divisible-by-3-using-array-digits0717/1

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


class Solution {
  public:
    int isPossible(int N, int arr[]) {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        {
            sum=(sum + arr[i]%3)%3;
        }
        return (sum==0);
    }
};