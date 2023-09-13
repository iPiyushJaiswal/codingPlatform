/*Problem GFG (Easy)

Largest number possible


Question link: https://practice.geeksforgeeks.org/problems/largest-number-possible5028/1

Complexity: 

Method 1: Maths

Time Complexity=O(n)

Space Complexity=O(1).

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Maths
*/

class Solution{
public:
    int findL(int S)
    {
        if(S>=9)
        return 9;
        return S;
    }
    string findLargest(int N, int S){
        // code here
        string ans;
        if((N>1 && S==0) || N*9<S)
        return "-1";
        for(int i=0;i<N;i++)
        {
            int val=findL(S);
            S-=val;
            ans.push_back('0'+val);
        }
        return ans;
    }
};