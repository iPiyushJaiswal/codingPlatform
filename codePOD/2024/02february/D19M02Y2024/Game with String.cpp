/*Problem GFG (Medium)

Game with String


Question link:	https://www.geeksforgeeks.org/problems/game-with-string4100/1

---------------------------

Logic: Heap

---------------------------

Complexity: 

Method 1 : Heap

Time Complexity= O(n + 26log26)

Space Complexity= O(26) priority_queue
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Heap
*/

//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)
        freq[s[i]-'a']++;
        priority_queue<int>pq;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            pq.push(freq[i]);
        }
        for(int i=0;i<k;i++)
        {
            int val=pq.top();
            pq.pop();
            val--;
            if(val>0)
            pq.push(val);
        }
        long long ans=0;
        while(!pq.empty())
        {
            int val=pq.top();
            pq.pop();
            ans+=val*val;
        }
        return ans;
    }
};