/*Problem LeetCode (Medium)

2038. Remove Colored Pieces if Both Neighbors are the Same Color


Question link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/

Logic: Maths

-------------------------

Complexity: 

Method 1:  Maths

Time Complexity=O(2n)

Space Complexity=O(1) 

--------------------------
Method 2:  Maths optimized single iteration

Time Complexity=O(n)

Space Complexity=O(1) 

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Maths
*/

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int aSet=0;
        int bSet=0;
        for(int i=0;i<n;i++)
        {
            int count=0;
            while(i<n && colors[i]=='A')
            {
                count++;
                i++;
            }
            if(count>=3)
            aSet+=count-3 + 1;
        }
        for(int i=0;i<n;i++)
        {
            int count=0;
            while(i<n && colors[i]=='B')
            {
                count++;
                i++;
            }
            if(count>=3)
            bSet+=count-3 + 1;
        }
        return (aSet>bSet);
    }
};

/*
Method 2: Maths optimized single iteration
*/

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        int aSet=0;
        int bSet=0;
        int i=0;
        while(i<n)
        {
            int countA=0;
            while(i<n && colors[i]=='A')
            {
                countA++;
                i++;
            }
            if(countA>=3)
            aSet+=countA-3 + 1;
            int countB=0;
            while(i<n && colors[i]=='B')
            {
                countB++;
                i++;
            }
            if(countB>=3)
            bSet+=countB-3 + 1;
        }
        return (aSet>bSet);
    }
};