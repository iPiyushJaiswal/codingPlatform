/*Problem GFG (Easy)

Max Sum Subarray of size K


Question link: https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

---------------------------

Logic: Sliding Window

---------------------------

Complexity: 

Method 1 : Sliding Window

Time Complexity= O(n)

Space Complexity= O(1)

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Sliding Window
*/

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long ans=0;
        long sum=0;
        int i=0;
        int j=0;
        while(j<K)
        {
            sum+=Arr[j];
            j++;
        }
        ans=max(ans,sum);
        while(j<N)
        {
            sum+=Arr[j]-Arr[i];
            j++;
            i++;
            ans=max(ans,sum);
        }
        return ans;
    }
};