/*Problem GFG (Hard)

Candy


Question link: https://www.geeksforgeeks.org/problems/candy/1

---------------------------

Logic: Peek valley concept.

---------------------------

Complexity: 

Method 1 : Prefix Suffix vector

Time Complexity= O(n)

Space Complexity= O(2n)

----------------------------------
Method 2 : Peek valley concept. 

Time Complexity= O(n)

Space Complexity= O(1)

----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Prefix Suffix vector
*/

class Solution {
  public:
    int minCandy(int N, vector<int> &r) {
        // code here
        int ans=0;
        vector<int>pref(N,1);
        vector<int>suf(N,1);
        for(int i=1;i<N;i++)
        {
            if(r[i]>r[i-1])
            pref[i]=pref[i-1]+1;
        }
        for(int i=N-2;i>=0;i--)
        {
            if(r[i]>r[i+1])
            suf[i]=suf[i+1]+1;
        }
        for(int i=0;i<N;i++)
        ans+=max(pref[i],suf[i]);
        return ans;
    }
};

/------------------------------------
Method 2: Peek valley concept.
*/

class Solution {
  public:
    int minCandy(int N, vector<int> &r) {
        // code here
        int ans=N;
        int i=1;
        while(i<N)
        {
            int peek=0;
            while(i<N && r[i]>r[i-1])
            {
                peek++;
                ans+=peek;
                i++;
            }
            int valley=0;
            while(i<N && r[i]<r[i-1])
            {
                valley++;
                ans+=valley;
                i++;
            }
            ans-=min(peek,valley);
            if(r[i]==r[i-1])
            i++;
        }
        return ans;
    }
};