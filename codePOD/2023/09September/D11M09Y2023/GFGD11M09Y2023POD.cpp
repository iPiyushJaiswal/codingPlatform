/*Problem GFG (Easy)

Lucky Numbers


Question link: https://practice.geeksforgeeks.org/problems/lucky-numbers2911/1

Complexity: 

Method 1: Recursive

Time Complexity=O(sqrt(n))

Space Complexity=O(sqrt(n)) recursive stack.

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Recursive + Iterative
*/

class Solution{
public:
    int counter=2;
    bool isLucky(int n) {
        // code here
        if(n<counter)
        return true;
        if(n%counter==0)
        return false;
        // current position - number of removed by counter.
        n=n - n/counter;
        counter++;
        return isLucky(n);
    }
};