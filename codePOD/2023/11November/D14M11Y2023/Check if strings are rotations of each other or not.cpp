/*Problem GFG (Easy)

Check if strings are rotations of each other or not


Question link: https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

---------------------------

Logic: Maths

---------------------------

Complexity: 

Method 1 : Maths

Time Complexity= O(2*n1)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Maths
*/

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int n1=s1.size();
        int n2=s2.size();
        int i=0;
        int j=0;
        int flag=0;
        while(j<n2 && flag<2)
        {
            if(i==n1)
            flag++;
            i=i%n1;
            if(s1[i]==s2[j])
            {
                j++;
            }
            i++;
        }
        return (j==n2);
    }
};