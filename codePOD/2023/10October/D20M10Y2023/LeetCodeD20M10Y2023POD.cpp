/*Problem LeetCode (Medium)

341. Flatten Nested List Iterator


Question link: https://leetcode.com/problems/flatten-nested-list-iterator/


Logic: Class Iterator

-------------------------

Complexity: 

Method 1:  BruteForce

Time Complexity=O(n)

Space Complexity=O(n)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: BruteForce
*/

class NestedIterator {
public:
    vector<int>ans;
    int idx;
    void flatList(vector<NestedInteger> &x)
    {
        for(auto it:x)
        {
            if(it.isInteger())
            ans.push_back(it.getInteger());
            else
            flatList(it.getList());
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        idx=0;
        flatList(nestedList);
    }
    
    int next() {
        int val=ans[idx];
        idx++;
        return val;
    }
    
    bool hasNext() {
        return (idx<ans.size());
    }
};
