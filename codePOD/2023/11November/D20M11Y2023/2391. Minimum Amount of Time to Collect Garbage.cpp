/*Problem LeetCode (Medium)

2391. Minimum Amount of Time to Collect Garbage


Question link: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/description/?envType=daily-question&envId=2023-11-20


Logic: 2 approach

--------------------------

Complexity: 

Method 1: 2 Iteration one in garbage and one in travel

Time Complexity=O(2*n)

Space Complexity=O(1)

--------------------------
Method 2: Single iteration

Time Complexity=O(n)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 2 Iteration one in garbage and one in travel
*/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int flagP=0;
        int flagG=0;
        int flagM=0;
        int n=garbage.size();
        int ans=0;
        int sum=0;
        int x=travel.size()-1;
        for(int i=0;i<=x;i++)
        sum+=travel[i];
        for(int i=n-1;i>=0;i--)
        {
            int m=garbage[i].size();
            for(int j=0;j<m;j++)
            {
                if(garbage[i][j]=='G')
                {
                    if(flagG==0)
                    {
                        ans+=sum;
                        flagG=1;
                    }
                    ans+=1;
                }
                else if(garbage[i][j]=='M')
                {
                    if(flagM==0)
                    {
                        ans+=sum;
                        flagM=1;
                    }
                    ans+=1;
                }
                else
                {
                    if(flagP==0)
                    {
                        ans+=sum;
                        flagP=1;
                    }
                    ans+=1;
                }
            }
            if(x>=0)
            sum-=travel[x];
            x--;
        }
        return ans;
    }
};

/*----------------------------------------------------------
Method 2: Single iteration
*/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int flagP=0;
        int flagG=0;
        int flagM=0;
        int n=garbage.size();
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            int m=garbage[i].size();
            for(int j=0;j<m;j++)
            {
                if(garbage[i][j]=='G')
                {
                    if(flagG==0)
                    flagG=1;
                    ans+=1;
                }
                else if(garbage[i][j]=='M')
                {
                    if(flagM==0)
                    flagM=1;
                    ans+=1;
                }
                else
                {
                    if(flagP==0)
                    flagP=1;
                    ans+=1;
                }
            }
            if(i>0){
            if(flagG==1)
            ans+=travel[i-1];
            if(flagP==1)
            ans+=travel[i-1];
            if(flagM==1)
            ans+=travel[i-1];
            }
        }
        return ans;
    }
};