/*Problem LeetCode (Medium)

779. K-th Symbol in Grammar


Question link: https://leetcode.com/problems/k-th-symbol-in-grammar/description/


Logic: Recursion

-------------------------

Complexity: 

Method 1:  Recursion

Time Complexity=O(n)

Space Complexity=O(n) recursive stack.

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Recursion
*/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1)
        return 0;
        if(k%2==0)
        return (kthGrammar(n-1,k/2)==0)?1:0;
        else
        return (kthGrammar(n-1,(k+1)/2)==0)?0:1;
    }
};