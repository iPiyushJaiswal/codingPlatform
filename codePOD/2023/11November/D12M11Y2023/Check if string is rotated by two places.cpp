/*Problem GFG (Easy)

Check if string is rotated by two places


Question link: https://www.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1

---------------------------

Logic: Array Traversal

---------------------------

Complexity: 

Method  : Array Traversal

Time Complexity= O(n)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Array Traversal
*/

class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        int n1=str1.size();
        int n2=str2.size();
        if(n1!=n2)
        return false;
        int ans1=true,ans2=true;
        for(int i=0;i<n2;i++)
        {
            if(str1[(i+2)%n1]!=str2[i] && ans1!=false)
            ans1=false;
            if(str1[(n1+i-2)%n1]!=str2[i] && ans2!=false)
            ans2=false;
            if(!ans1 && !ans2)
            return false;
        }
        return true;
    }
};