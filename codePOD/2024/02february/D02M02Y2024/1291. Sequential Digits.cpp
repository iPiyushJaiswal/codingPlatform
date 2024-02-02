/*Problem LeetCode (Medium)

1291. Sequential Digits


Question link: https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02

Solution link: https://leetcode.com/problems/sequential-digits/submissions/1163615604/?envType=daily-question&envId=2024-02-02


Logic : Sliding Window

--------------------------
Complexity: 

Method 1: Sliding Window

Time Complexity=O(9)

Space Complexity=O(1) 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Sliding Window
*/

class Solution {
public:
    int fDigit(int val)
    {
        int count=0;
        while(val>0)
        {
            count++;
            val/=10;
        }
        return count;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        int lDigit=fDigit(low);
        int hDigit=fDigit(high);
        for(int i=lDigit;i<=hDigit;i++)
        {
            int b=1;
            while(b+i<=10)
            {
                int val=0;
                int a=b;
                while(a<b+i)
                {
                    val=val*10+ a;
                    a++;
                }
                cout<<val<<" ";
                b++;
                if(val>=low && val<=high)
                ans.push_back(val);
            }
        }
        return ans;
    }
};