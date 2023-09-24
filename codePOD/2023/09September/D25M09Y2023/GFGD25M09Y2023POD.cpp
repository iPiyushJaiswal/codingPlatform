/*Problem GFG (Medium)

Maximum Sum Combination


Question link: https://practice.geeksforgeeks.org/problems/maximum-sum-combination/1

---------------------------

Logic: Sorting + Priority_queue

---------------------------

Complexity: 

Method 1:Sorting + Priority_queue

Time Complexity=O(nlogn)

Space Complexity=O(n).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Sorting + Priority_queue
*/

class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int,int>>st;
        vector<int>ans;
        pq.push({A[n-1]+B[n-1],{n-1,n-1}});
        st.insert({n-1,n-1});
        while(!pq.empty() && k>0)
        {
            int val=pq.top().first;
            int aInd=pq.top().second.first;
            int bInd=pq.top().second.second;
            pq.pop();
            ans.push_back(val);
            k--;
            if(aInd-1>=0 && st.find({aInd-1,bInd})==st.end())
            {
                pq.push({A[aInd-1]+B[bInd],{aInd-1,bInd}});
                st.insert({aInd-1,bInd});
            }
            if(bInd-1>=0 && st.find({aInd,bInd-1})==st.end())
            {
                pq.push({A[aInd]+B[bInd-1],{aInd,bInd-1}});
                st.insert({aInd,bInd-1});
            }
        }
        return ans;
    }
};