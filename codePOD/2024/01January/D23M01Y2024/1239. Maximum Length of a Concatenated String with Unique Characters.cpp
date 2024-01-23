/*Problem LeetCode (Medium)

1239. Maximum Length of a Concatenated String with Unique Characters


Question link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23

Solution link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/submissions/1154213271/?envType=daily-question&envId=2024-01-23


Logic : Backtracking

--------------------------
Complexity: 

Method 1: Backtracking

Time Complexity=O(2^n)

Space Complexity=O(n) recursive stack + O(n*26) unordered_set
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Backtracking
*/

class Solution {
public:
    bool isSafe(string temp,string arrT)
    {
        unordered_set<char>st;
        int n=temp.size();
        int m=arrT.size();
        for(int i=0;i<n;i++)
        st.insert(temp[i]);
        for(int i=0;i<m;i++)
        {
            if(st.find(arrT[i])!=st.end())
            return false;
            st.insert(arrT[i]);
        }
        return true;
    }
    int rec(vector<string>& arr,int i,int n,string temp)
    {
        if(i==n)
        return temp.size();
        int a=0;
        if(isSafe(temp,arr[i]))
        a=rec(arr,i+1,n,temp+arr[i]);
        int b=rec(arr,i+1,n,temp);
        return max(a,b);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string temp;
        return rec(arr,0,n,"");
    }
};