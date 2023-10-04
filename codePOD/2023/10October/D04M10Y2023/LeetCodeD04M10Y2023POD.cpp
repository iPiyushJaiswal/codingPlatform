/*Problem LeetCode (Easy)

706. Design HashMap


Question link: https://leetcode.com/problems/design-hashmap/description/

Logic: Maths

-------------------------

Complexity: 

Method 1:  Maths

Time Complexity=O(1)

Space Complexity=O(n) 

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Maths
*/

class MyHashMap {
public:
    vector<int>mp;
    MyHashMap() {
        mp=vector<int>(1e6+1,-1);
    }
    
    void put(int key, int value) {
        mp[key]=value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
         mp[key]=-1;
    }
};