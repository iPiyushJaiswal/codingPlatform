/*Problem GFG (Medium)

Check if a string is repetition of its substring of k-length


Question link: https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1

---------------------------

Logic: String + sliding window

---------------------------

Complexity: 

Method 1 : String + sliding window

Time Complexity= O(n)

Space Complexity= O(k)
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: String + sliding window
*/

class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    // Your Code Here
	    if(n%k!=0)
	    return 0;
	    string s1;
	    string s2;
	    int count=0;
	    int i=0;
	   while(i<k)
	   {
	       s1+=s[i];
	       i++;
	   }
	   while(i<n)
	   {
	       int j=0;
	       string temp;
	        while(j<k)
	        {
	            temp+=s[i+j];
	            j++;
	        }
	        if(s2.size()==0 && s1==temp)
	        s2=temp;
	        else if(count==0 && s1!=temp)
	        {
	            count++;
	            s2=temp;
	        }
	        else if(temp!=s1 && temp!=s2)
	        return 0;
	        i+=j;
	    }
	    return 1;
	}
};