/*Problem LeetCode (Easy)

2108. Find First Palindromic String in the Array


Question link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13

Solution link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/submissions/1173764612/?envType=daily-question&envId=2024-02-13


Logic : 2 Pointer

--------------------------
Complexity: 

Method 1: 2 Pointer

Time Complexity=O(n*sizeOfWord)

Space Complexity=O(1)  
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 2 Pointer
*/

class Solution {
public:
bool isPali(string temp)
{
    int j=temp.size()-1;
    int i=0;
    while(i<j)
    {
        if(temp[i]!=temp[j])
        return false;
        i++;
        j--;
    }
    return true;
}
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            if(isPali(words[i]))
            return words[i];
        }
        return "";
    }
};