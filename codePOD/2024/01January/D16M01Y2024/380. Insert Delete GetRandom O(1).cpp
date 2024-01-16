/*Problem LeetCode (Medium)

380. Insert Delete GetRandom O(1)


Question link: https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16

Solution link: https://leetcode.com/problems/insert-delete-getrandom-o1/submissions/1147595806/?envType=daily-question&envId=2024-01-16


Logic : Hashing

--------------------------
Complexity: 

Method 1: Hashing

Time Complexity=O(1)

Space Complexity=O(n) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Hashing
*/

class RandomizedSet {
public:
vector<int>vec;
unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())
        return false;
        vec.push_back(val);
        mp[val]=vec.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())
        return false; 
        int j=vec.size()-1;
        int i=mp[val];
        mp[vec[j]]=i;
        mp.erase(vec[i]);
        vec[i]=vec[j];
        vec.pop_back();
        return true;
    }
    
    int getRandom() {
        int n=vec.size();
        return vec[rand()%n];
    }
};
