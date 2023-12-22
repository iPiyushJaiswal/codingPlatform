/*Problem GFG (Easy)

Count More than n/k Occurences


Question link: https://www.geeksforgeeks.org/problems/count-element-occurences/1

---------------------------

Logic: unordered_map

---------------------------

Complexity: 

Method 1 : unordered_map

Time Complexity= O(n)

Space Complexity= O(n)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: unordered_map
*/

class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        // Your code here
        unordered_map<int,int>mp;
        int count=0;
        int tar=n/k;
        for(int i=0;i<n;i++)
        mp[arr[i]]++;
        for(auto it:mp)
        {
            if(it.second>tar)
            count++;
        }
        return count;
    }
};