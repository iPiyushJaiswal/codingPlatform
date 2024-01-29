/*Problem LeetCode (Easy)

232. Implement Queue using Stacks


Question link: https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29

Solution link: https://leetcode.com/problems/implement-queue-using-stacks/submissions/1159828712/?envType=daily-question&envId=2024-01-29


Logic : Stacks

--------------------------
Complexity: 

Method 1: 2 Stacks

Time Complexity=O(n)

Space Complexity=O(2*n) stack. 
--------------------------
Method 2: 1 Stack

Time Complexity=O(n)

Space Complexity=O(n) stack + O(n) recursive stack 
--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: 2 Stacks
*/

class MyQueue {
public:
stack<int>st1,st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st1.size()==0 && st2.size()==0)
        return -1;
        if(st2.size()==0)
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int val=st2.top();
        st2.pop();
        return val;
    }
    
    int peek() {
        if(st1.size()==0 && st2.size()==0)
        return -1;
        if(st2.size()==0)
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return (st1.size()==0 && st2.size()==0);
    }
};

/*--------------------------------------
Method 2: 1 stack
*/

class MyQueue {
public:
    stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(empty())
        {
            st.push(x);
            return;
        }
        int val=st.top();
        st.pop();
        push(x);
        st.push(val);
    }
    
    int pop() {
        if(empty())
        return -1;
        int val=st.top();
        st.pop();
        return val;
    }
    
    int peek() {
        if(empty())
        return -1;
        return st.top();
    }
    
    bool empty() {
        return (st.size()==0);
    }
};
