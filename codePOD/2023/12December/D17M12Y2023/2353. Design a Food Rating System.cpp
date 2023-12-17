/*Problem LeetCode (Medium)

2353. Design a Food Rating System


Question link: https://leetcode.com/problems/design-a-food-rating-system/description/?envType=daily-question&envId=2023-12-17

Solution link: https://leetcode.com/problems/design-a-food-rating-system/submissions/1121614285/?envType=daily-question&envId=2023-12-17


Logic : Map + Set

--------------------------

Complexity: 

Method 1: Map + Set

Time Complexity=O(nlogn)

Space Complexity=O(n)
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Map + Set
*/

class FoodRatings {
public:
// food,cusiene
unordered_map<string,string>foodCu;
// food,rating
unordered_map<string,int>foodRa;
// all map {cusiene,{rat,food}}
unordered_map<string,set<pair<int,string>>>mp;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++)
        {
            foodCu[foods[i]]=cuisines[i];
            foodRa[foods[i]]=ratings[i];
            mp[cuisines[i]].insert({-1*ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string fCus=foodCu[food];
        int rat=foodRa[food];
        foodRa[food]=newRating;
        auto it=mp[fCus].find({-1*rat,food});
        mp[fCus].erase(it);
        mp[fCus].insert({-1*newRating,food});
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].begin()->second;
    }
};
