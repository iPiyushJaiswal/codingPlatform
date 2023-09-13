/*Problem LeetCode (Hard)

135. Candy


Question link: https://leetcode.com/problems/candy/description/?envType=daily-question&envId=2023-09-13

Logic: 

Complexity: 

Method 1: Prefix and Suffix vector concept.

Time Complexity=O(n) 

Space Complexity=O(2n)

--------------------------

Method 2: Peak Valley concept (New Learning) Optimized

Time Complexity=O(n),

Space Complexity=O(1)

--------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Prefix and Suffix vector concept.
*/

class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[i-1])
            left[i]=left[i-1]+1;
        }
        for(int j=n-2;j>=0;j--)
        {
            if(arr[j]>arr[j+1])
            right[j]=right[j+1]+1;
        }
        int count=0;
        for(int i=0;i<n;i++)
        count+=max(left[i],right[i]);
        return count;
    }
};

/*
--------------------------------------------------

Method 2: Peak Valley concept
*/

class Solution {
public:
    int candy(vector<int>& arr) {
        int n=arr.size();
        int count=n;
        int i=1;
        while(i<n)
        {
            if(arr[i]==arr[i-1])
            {
                i++;
                continue;
            }
            int peak=0;
            while(i<n && arr[i]>arr[i-1])
            {
                peak++;
                count+=peak;
                i++;
            }
            
            int valley=0;
            while(i<n && arr[i]<arr[i-1])
            {
                valley++;
                count+=valley;
                i++;
            }
            count-=min(peak,valley);
        }
        return count;
    }
};