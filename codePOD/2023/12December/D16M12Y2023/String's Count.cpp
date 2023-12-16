/*Problem GFG (Easy)

String's Count


Question link: https://www.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints1135/1

---------------------------

Logic: 6 cases

---------------------------

Complexity: 

Method 1 : 6 cases

Time Complexity= O(1)

Space Complexity= O(1)

----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 6 cases
*/

long long int countStr(long long int n){
    //complete the function here
    return 1 + n + n + (n*(n-1))/2 + (n*(n-1)*(n-2))/2 + n*(n-1);
}