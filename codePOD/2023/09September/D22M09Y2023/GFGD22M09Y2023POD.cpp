/*Problem GFG (Medium)

First and last occurrences of x


Question link: https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1

---------------------------

Logic: Binary Search

---------------------------

Complexity: 

Method 1: Binary Search

Time Complexity=O(2*log(n))

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Binary Search
*/

class Solution
{
    public:
    int binarySearch(int arr[],int n,int x,int dir)
    {
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]==x)
            {
                ans=mid;
                if(dir==0)
                high=mid-1;
                else
                low=mid+1;
            }
            else if(arr[mid]<x)
            low=mid+1;
            else
            high=mid-1;
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int first=binarySearch(arr,n,x,0);
        if(first==-1)
        return {-1,-1};
        int second=binarySearch(arr,n,x,1);
        return {first,second};
    }
};