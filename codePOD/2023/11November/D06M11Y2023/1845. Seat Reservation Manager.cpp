/*Problem LeetCode (Medium)

1845. Seat Reservation Manager


Question link: https://leetcode.com/problems/seat-reservation-manager/description/


Logic: Min Heap

--------------------------

Complexity: 

Method 1: Min Heap

Time Complexity=O(n)

Space Complexity=O(1)

--------------------------
----------------
CODE IN C++ 
---------------- 
------------------------------------------------------------------------------------------------

Method 1: Min Heap
*/

class SeatManager {
public:
priority_queue<int>pq;
int maxi;
    SeatManager(int n) {
        maxi=n;
        for(int i=1;i<=n;i++)
        pq.push(-1*i);
    }
    
    int reserve() {
        int val=pq.top();
        pq.pop();
        return val*-1;
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber>maxi)
        return ;
        pq.push(-1*seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */