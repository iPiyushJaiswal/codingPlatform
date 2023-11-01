/*Problem GFG (Easy)

Frequencies of Limited Range Array Elements


Question link: https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1

---------------------------

Logic: Maths

---------------------------

Complexity: 

Method 1 : Maths

Time Complexity= O(2n).

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Maths
*/

class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int n, int p)
    { 
        // code here
        for(int i=0;i<n;i++)
        {
            arr[i]--;
            int ind=(arr[i])%p;
            if(ind<n)
            arr[ind]+=p;
        }
        for(int i=0;i<n;i++)
        {
            arr[i]/=p;
        }
    }
};