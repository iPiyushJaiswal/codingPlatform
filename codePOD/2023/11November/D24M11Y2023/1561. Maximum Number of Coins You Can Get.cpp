/*Problem LeetCode (Medium)

1561. Maximum Number of Coins You Can Get


Question link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/description/?envType=daily-question&envId=2023-11-24

Solution link: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/submissions/1105165676/


Logic: 3 approaches

--------------------------

Complexity: 

Method 1: Min heap priority_queue (BruteForce)

Time Complexity=O(nlogn)

Space Complexity=O(n)

--------------------------
Method 2: Sorting

Time Complexity=O(nlogn)

Space Complexity=O(1)

--------------------------
Method 3: Hash Optimized

Time Complexity=O(max(n,maxi))

Space Complexity=O(maxi)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Min heap priority_queue (BruteForce)
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        int count=(2*n)/3;
        // cout<<count;
        for(int i=0;i<n;i++)
        {
            // if(pq.size()>=count)
            // pq.pop();
            pq.push(piles[i]);
        }
        int ans=0;
        while(!pq.empty())
        {
            if(pq.size()>count)
            {
                pq.pop();
                continue;
            }
            cout<<pq.top()<<" ";
            ans+=pq.top();
            pq.pop();
            pq.pop();
        }
        return ans;
    }
};

/*-----------------------------------------------------------
Method 2: Sorting 
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        sort(piles.begin(),piles.end());
        int ans=0;
        int count=n/3;
        for(int i=n-2;i>=count;i-=2)
        ans+=piles[i];
        return ans;
    }
};

/*-----------------------------------------------------------
Method 3: Hash Optimized
*/

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        maxi=max(maxi,piles[i]);
        vector<int>hash(maxi+2,0);

        for(int i=0;i<n;i++)
        hash[piles[i]]++;

        int count=n/3;

        int i=1;
        int ans=0;
        int taken=1;
        for(;i<maxi+2;i++)
        {
            int mini=min(hash[i],count);
            count-=mini;
            hash[i]-=mini;
            if(count==0)
            {
                while(hash[i]>0)
                {
                    ans+=taken*i;
                    taken=taken^1;
                    hash[i]--;
                }
            }
        }
        return ans;
    }
};