/*Problem LeetCode (Medium)

1535. Find the Winner of an Array Game


Question link: https://leetcode.com/problems/find-the-winner-of-an-array-game/description/?envType=daily-question&envId=2023-11-05


Logic: (Array Traversal + queue) + (Array Traversal)

--------------------------

Complexity: 

Method 1: Array Traversal + queue

Time Complexity=O(n)

Space Complexity=O(n)

--------------------------
Method 2: Array Traversal

Time Complexity=O(n)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array Traversal + queue
*/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        if(k>=n)
        {
            int maxi=INT_MIN;
            for(int i=0;i<n;i++)
            maxi=max(maxi,arr[i]);
            return maxi;
        }
        int k1=k;
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            q.push(arr[i]);
        }
        int valFirst=q.front();
        q.pop();
        while(k1>0)
        {
            if(q.front()<valFirst)
            {
                int temp=q.front();
                q.pop();
                q.push(temp);
                k1--;
            }
            else
            {
                q.push(valFirst);
                valFirst=q.front();
                q.pop();
                k1=k-1;
            }
        }
        return valFirst;
    }
};

/*--------------------------------------
Method 2: Array Traversal
*/

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=arr[0];
        int wins=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i]<ans)
            wins++;
            else
            {
                ans=arr[i];
                wins=1;
            }
            if(wins==k)
            break;
        }
        return ans;
    }
};