/*Problem GFG (Easy)

Shortest path from 1 to n


Question link: https://www.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1

---------------------------

Logic: Maths

---------------------------

Complexity: 

Method 1 : Maths

Time Complexity= O(n)

Space Complexity= O(1) 

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Maths
*/

class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
        int count=0;
        while(n>1)
        {
            if(n%3==0)
            n/=3;
            else
            n--;
            count++;
        }
        return count;
    }
};