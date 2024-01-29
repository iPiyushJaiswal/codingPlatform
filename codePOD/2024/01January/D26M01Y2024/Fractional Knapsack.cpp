/*Problem GFG (Medium)

Fractional Knapsack


Question link: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

---------------------------

Logic: Greedy 

---------------------------

Complexity: 

Method 1 : Greedy 

Time Complexity= O(nlogn)

Space Complexity= O(1)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Greedy 
*/

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool comp(Item &m1,Item &m2)
    {
        return (double)m1.value/m1.weight>(double)m2.value/m2.weight;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comp);
        double ans=0;
        for(int i=0;i<n;i++)
        {
            if(W>=arr[i].weight)
            {
                W-=arr[i].weight;
                ans+=arr[i].value;
            }
            else
            {
                ans+=(double)arr[i].value*W/arr[i].weight;
               break;
            }
        }
        return ans;
    }
        
};
