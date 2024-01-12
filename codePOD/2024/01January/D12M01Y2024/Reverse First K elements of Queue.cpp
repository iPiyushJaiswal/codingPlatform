/*Problem GFG (Easy)

Reverse First K elements of Queue


Question link: https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

---------------------------

Logic: Queue

---------------------------

Complexity: 

Method 1 : Iteration Queue

Time Complexity= O(n)

Space Complexity= O(k) 
----------------------------------
Method 2 : Recursive Queue

Time Complexity= O(n)

Space Complexity= O(k) 
----------------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Iteration Queue
*/

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        int size=q.size();
        vector<int>temp;
        int i=0;
        for(;i<k;i++)
        {
            temp.push_back(q.front());
            q.pop();
        }
        for(int j=temp.size()-1;j>=0;j--)
        q.push(temp[j]);
        for(;i<size;i++)
        {
            q.push(q.front());
            q.pop();
        }
        return q;
    }
};

/*-------------------------------------------------------
Method 2: Recursive Queue
*/

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    void rec(queue<int> &q, int k)
    {
        if(k==0 || q.empty())
        return;
        int temp=q.front();
        q.pop();
        rec(q,k-1);
        q.push(temp);
    }
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        int n=q.size()-k;
        rec(q,k);
        while(n>0)
        {
            q.push(q.front());
            q.pop();
            n--;
        }
        return q;
    }
};