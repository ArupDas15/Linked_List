// Time Complexity: O(mlogn) where 'm' is the total calls made to reserve()
// Space Complexity: O(n)
class SeatManager {
public:
    int s;
    set<int>seats;
    SeatManager(int n) {
        // initialising the counter to the lowest seat number
        s = 1;
    }
    
    int reserve() {
        if(seats.empty()==false) {
            int seatno=*seats.begin();
            // removing the lowest seat number
            seats.erase(seats.begin());
            return seatno;
        }
        // if no seat has been unreserved till now then return the lowest seat number
        int seatno = s;
        s++;
        return seatno;
    }
    
    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */