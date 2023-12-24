/*Problem GFG (Medium)

Buy Maximum Stocks if i stocks can be bought on i-th day


Question link: https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1

---------------------------

Logic: Array + Sorting + Greedy

---------------------------

Complexity: 

Method 1 : Array + Sorting + Greedy

Time Complexity= O(nlogn)

Space Complexity= O(n)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Array + Sorting + Greedy
*/

lass Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        arr.push_back({price[i],i+1});
        sort(arr.begin(),arr.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i].first<=k)
            {
                int val=k/arr[i].first;
                count+=min(arr[i].second,val);
                k-=arr[i].first*min(arr[i].second,val);
            }
        }
        return count;
    }
};