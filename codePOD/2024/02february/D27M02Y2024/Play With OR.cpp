/*Problem GFG (Easy)






Question link:	https://www.geeksforgeeks.org/problems/play-with-or5515/1

---------------------------

Logic: OR

---------------------------

Complexity: 

Method 1 : OR

Time Complexity= O(n)

Space Complexity= O(1) 
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: OR
*/

int* game_with_number(int arr[], int n)
{
    
    // Complete the function
    for(int i=0;i<n-1;i++)
    arr[i]|=arr[i+1];
    return arr;
    
}