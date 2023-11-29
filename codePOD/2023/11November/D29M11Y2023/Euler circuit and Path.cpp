/*Problem GFG (Medium)

Euler circuit and Path


Question link: https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1

---------------------------

Logic: Graph Basic

---------------------------

Complexity: 

Method 1 : Graph Basic

Time Complexity= O(V)

Space Complexity= O(1) 

----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Graph Basic
*/

class Solution {
public:
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    int odd=0;
	    for(int i=0;i<V;i++)
	    {
	        if(adj[i].size()%2==1)
	        odd++;
	    }
	    if(odd==0)
	    return 2;
	    else if(odd==2)
	    return 1;
	    return 0;
	}
};