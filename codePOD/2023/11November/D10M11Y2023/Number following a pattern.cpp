/*Problem GFG (Medium)

Number following a pattern


Question link: https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1

---------------------------

Logic: Concept. Maths

---------------------------

Complexity: 

Method  : Maths

Time Complexity= O(n)

Space Complexity=O(1)

-----------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method : Maths
*/

class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans;
        int n=S.size();
        for(int i=0;i<=n;i++)
        ans.push_back(i+1+'0');
        for(int i=0;i<n;i++)
        {
            if(S[i]=='I')
            continue;
            int count=1;
            int k=i;
            while(i<n && S[i]=='D')
            {
                count++;
                i++;
            }
            reverse(ans.begin()+k,ans.begin()+k+count);
        }
        return ans;
    }
};