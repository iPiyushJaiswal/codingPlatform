/*Problem GFG (Easy)

Panagram Checking


Question link:	https://www.geeksforgeeks.org/problems/pangram-checking-1587115620/1

---------------------------

Logic: hash 

---------------------------

Complexity: 

Method 1 : hash 

Time Complexity= O(n)

Space Complexity= O(26)
----------------------------------

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: hash 
*/

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        vector<int>freq(26,0);
        int n=s.size();
        if(n<26)
        return false;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            freq[s[i]-'A']++;
            else if(s[i]>='a' && s[i]<='z')
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]==0)
            return false;
        }
        return true;
    }

};