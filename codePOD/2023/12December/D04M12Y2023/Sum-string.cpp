/*Problem GFG (Hard)

Sum-string


Question link: https://www.geeksforgeeks.org/problems/sum-string3151/1

---------------------------

Logic: String

---------------------------

Complexity: 

Method 1 : String

Time Complexity= O(n^3)

Space Complexity= O(n) recursive stack

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: String
*/

class Solution{   
public:
    int rec(string s,int st)
    {
        long long int a = 0, b, c, ans = 0, n = s.size(); 
        for(int i = st; i < n; i++){
            a = a * 10 + (s[i] - '0'), b = 0; 
            for(int j = i+1; j < n; j++){
                if(s[j] == '0' and b == 0) break;
                if((n - j) < max(i-st+1, j-i+1)) break;
                b = b * 10 + (s[j] - '0'), c = 0; 
                for(int k = j+1; k < n; k++){
                    if(s[k] == '0' and c == 0) break;
                    c = c * 10 + (s[k] - '0');
                    if(c == (a + b)) {
                        //cout<<a<<" "<<b<<" "<<c<<endl; 
                        ans |= ((k == n-1) or rec(s, i+1));
                        if(ans) return 1;
                    }
                    else if(c > (a + b)) break;
                }
            }
        }
        return ans;
    }
    int isSumString(string S){
        // code here 
        return rec(S,0);
    }
};