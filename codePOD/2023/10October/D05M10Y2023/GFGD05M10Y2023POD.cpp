/*Problem GFG (Medium)

Count number of substrings


Question link: https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1

---------------------------

Logic: 2 pointer

---------------------------

Complexity: 


Method 1: 2 pointer

Time Complexity=O(2n)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : 2 pointer
*/

class Solution
{
  public:
  long long int findK(string s,int k)
  {
      int n=s.size();
      long long int ans=0;
      int dist=0;
      vector<int>freq(26,0);
      int j=0;
      int i=0;
      while(i<n)
      {
          freq[s[i]-'a']++;
          if(freq[s[i]-'a']==1)
          dist++;
          while(dist>k)
          {
              freq[s[j]-'a']--;
              if(freq[s[j]-'a']==0)
              dist--;
              j++;
          }
          ans+=i-j+1;
          i++;
      }
      return ans;
  }
    long long int substrCount (string s, int k) {
    	//code here.
    	return findK(s,k)-findK(s,k-1);
    }
};